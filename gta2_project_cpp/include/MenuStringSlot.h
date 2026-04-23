#pragma once

#include <cstdint>
#include <cstring>
#include <string>

namespace gta2 {

/**
 * @brief Структура S140 (переименована в MenuStringSlot)
 * 
 * Предположительное назначение: Строковый элемент меню или локализованная строка конфигурации.
 * Содержит флаги, идентификатор выбора и широкую строку (Unicode).
 * 
 * Исходный размер: 108 байт
 */
struct MenuStringSlot {
    uint8_t  fild;          // 0x00 - Флаг состояния или типа
    uint8_t  field_1;       // 0x01 - Дополнительный флаг
    uint16_t field_2;       // 0x02 - Параметр (возможно, ID или смещение)
    uint16_t field_4;       // 0x04 - Параметр (возможно, цвет или стиль)
    uint16_t Select;        // 0x06 - Индекс выбора или активный статус
    wchar_t  str[50];       // 0x08 - Текстовое содержимое (Unicode, макс 49 симв + \0)

    // Статическая константа размера строки
    static constexpr size_t MAX_STRING_LENGTH = 50;

    // Конструктор по умолчанию (инициализация нулями)
    MenuStringSlot() 
        : fild(0)
        , field_1(0)
        , field_2(0)
        , field_4(0)
        , Select(0) 
    {
        std::memset(str, 0, sizeof(str));
    }

    // Конструктор с параметрами
    MenuStringSlot(uint8_t flags, uint16_t id, const wchar_t* text)
        : fild(flags)
        , field_1(0)
        , field_2(id)
        , field_4(0)
        , Select(0)
    {
        std::memset(str, 0, sizeof(str));
        if (text) {
            std::wcsncpy(str, text, MAX_STRING_LENGTH - 1);
            str[MAX_STRING_LENGTH - 1] = L'\0';
        }
    }

    // Геттеры
    uint8_t getFlags() const { return fild; }
    uint16_t getId() const { return field_2; }
    uint16_t getSelectIndex() const { return Select; }
    
    std::wstring getText() const {
        return std::wstring(str);
    }

    // Сеттеры
    void setFlags(uint8_t flags) { fild = flags; }
    void setId(uint16_t id) { field_2 = id; }
    void setSelectIndex(uint16_t index) { Select = index; }
    
    void setText(const wchar_t* text) {
        if (text) {
            std::wcsncpy(str, text, MAX_STRING_LENGTH - 1);
            str[MAX_STRING_LENGTH - 1] = L'\0';
        } else {
            std::memset(str, 0, sizeof(str));
        }
    }

    // Проверка размера структуры (для отладки)
    static constexpr size_t expectedSize() {
        return 108;
    }
};

// Проверка размера на этапе компиляции (если включена поддержка C++11 static_assert)
// static_assert(sizeof(MenuStringSlot) == 108, "Size of MenuStringSlot must be 108 bytes");

} // namespace gta2
