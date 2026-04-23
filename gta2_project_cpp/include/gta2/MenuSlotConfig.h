#pragma once

#include <cstdint>

/**
 * @brief Структура конфигурации слота меню (ранее S139)
 * 
 * Размер: 8 байт (0x08)
 * Адрес в оригинале: Используется внутри структуры Menu
 * 
 * Назначение: Хранит расширенную конфигурацию слота игрока,
 * включая настройки управления и состояние готовности.
 */
#pragma pack(push, 1)
struct MenuSlotConfig {
    // Смещение 0x00
    uint8_t slotId;           // ID слота (0-7)
    
    // Смещение 0x01
    uint8_t inputDevice;      // Устройство ввода: 0 - KB, 1 - Gamepad, 2 - Network
    
    // Смещение 0x02
    uint8_t teamId;           // ID команды (для мультиплеера)
    
    // Смещение 0x03
    uint8_t carClass;         // Предпочитаемый класс автомобиля
    
    // Смещение 0x04
    uint32_t flags;           // Флаги состояния (битовая маска)
    
    // Смещение 0x08 (конец, но размер может быть выровнен в массивах)

    // Статический размер структуры
    static constexpr size_t Size = 0x08;

    /**
     * @brief Конструктор
     * Адрес: 0x00452D10 (предположительно, рядом с S138)
     */
    MenuSlotConfig();

    /**
     * @brief Деструктор
     * Адрес: 0x00452D20
     */
    ~MenuSlotConfig();

    /**
     * @brief Инициализация значениями по умолчанию
     * Адрес: 0x00452D30
     */
    void Init();

    /**
     * @brief Установка устройства ввода
     * @param device Тип устройства
     */
    void SetInputDevice(uint8_t device);

    /**
     * @brief Проверка флага активности
     * @return true если слот активен
     */
    bool IsActive() const;

    /**
     * @brief Сброс конфигурации
     */
    void Reset();
};
#pragma pack(pop)

// Проверка размера структуры
static_assert(sizeof(MenuSlotConfig) == 0x08, "MenuSlotConfig size must be 8 bytes");
