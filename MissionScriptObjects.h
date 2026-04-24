#pragma once

#include <cstdint>

// Forward declaration
struct MissionScriptObject; // S28

/**
 * @brief Структура управления объектами скриптов миссий (S27).
 * 
 * Глобальный экземпляр расположен по адресу 0x006644C0.
 * Размер: 0x8EC байт.
 * Содержит пул объектов (предположительно 8 элементов S28) и управляет их жизненным циклом.
 */
struct MissionScriptObjects
{
    // Данные заполняются на основе анализа размера 0x8EC и поведения методов
    // Предположительная структура поля в начале (нужно уточнять по листингу конструктора)
    uint8_t padding[0x8EC]; 

    // --- Методы ---

    /**
     * @brief Конструктор
     * Адрес: 0x00481310
     * Инициализирует структуру, вероятно, обнуляет память и настраивает связный список пула.
     */
    void Constructor();

    /**
     * @brief Внутренний деструктор
     * Адрес: 0x00481303
     * Очищает содержимое объектов, но не освобождает память самой структуры.
     */
    void Destructor_Internal();

    /**
     * @brief Метод обработки/обновления
     * Адрес: 0x00481380
     * Основной цикл обновления состояния объектов миссии.
     */
    void Update();

    /**
     * @brief Вспомогательный метод обхода
     * Адрес: 0x0047F4D0
     * Проходит по элементам и вызывает функцию обработки (sub_476E10).
     */
    void ProcessElements();

    /**
     * @brief Оператор удаления (внешний деструктор)
     * Адрес: 0x00481C2E
     * Вызывает внутренний деструктор и освобождает память (free).
     */
    void operator delete(void* ptr);
};

// Глобальный указатель на экземпляр
extern MissionScriptObjects* g_MissionScriptObjects; // 0x006644C0

// Объявления функций-оберток для вызова из ассемблерного кода
void __cdecl MissionScriptObjects_Construct(MissionScriptObjects* _this);
void __cdecl MissionScriptObjects_Destruct(MissionScriptObjects* _this);
void __cdecl MissionScriptObjects_Update(MissionScriptObjects* _this);
void __cdecl MissionScriptObjects_ProcessElements(MissionScriptObjects* _this);
void __cdecl MissionScriptObjects_Delete(MissionScriptObjects* _this);
