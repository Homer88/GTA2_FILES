#pragma once

/**
 * @file PlayerSlotConfig.h
 * @brief Конфигурация слота игрока в меню
 * 
 * Оригинальное имя: S138
 * Размер: 4 байта
 * Используется: массив из 8 элементов в структуре Menu
 * 
 * Предназначение: Хранит состояние и настройки слота игрока:
 * - field_0: Активность слота (0 = неактивен, 1 = активен)
 * - field_1: Тип контроллера (0 = клавиатура, 1 = геймпад)
 * - field_2: Номер игрока / ID
 * - field_3: Зарезервировано / флаги состояния
 */

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// Прямое объявление для использования в C
struct PlayerSlotConfig_t;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "gta2_forward.h"

/**
 * @class PlayerSlotConfig
 * @brief Конфигурация слота игрока в меню
 * 
 * Адрес конструктора: 0x00452CE0
 * Адрес деструктора: 0x00452CF0
 * Адрес метода инициализации: 0x00452D00
 */
#pragma pack(push, 1)
struct PlayerSlotConfig
{
    /**
     * @brief Активность слота
     * 0 = слот неактивен
     * 1 = слот активен (игрок присутствует)
     */
    uint8_t IsActive;           // +0x00 (field_0)
    
    /**
     * @brief Тип устройства ввода
     * 0 = клавиатура/мышь
     * 1 = геймпад/джойстик
     * Другие значения = специальные контроллеры
     */
    uint8_t ControllerType;     // +0x01 (field_1)
    
    /**
     * @brief Идентификатор игрока
     * Номер игрока в системе (0-7 для 8 слотов)
     * Или ссылка на индекс в массиве Players
     */
    uint8_t PlayerID;           // +0x02 (field_2)
    
    /**
     * @brief Флаги состояния / зарезервировано
     * Битовые флаги:
     * - Bit 0: Готов к игре
     * - Bit 1: Выбрал персонажа
     * - Bit 2: Выбрал машину
     * - Bit 3-7: Зарезервировано
     */
    uint8_t StateFlags;         // +0x03 (field_3)
    
    // Статический размер: 4 байта
    static_assert(sizeof(PlayerSlotConfig) == 4, "PlayerSlotConfig must be 4 bytes");
    
    /**
     * @brief Конструктор
     * Адрес: 0x00452CE0
     * Инициализирует все поля в 0
     */
    PlayerSlotConfig();
    
    /**
     * @brief Деструктор
     * Адрес: 0x00452CF0
     * Очищает ресурсы (если есть)
     */
    ~PlayerSlotConfig();
    
    /**
     * @brief Инициализация слота
     * Адрес: 0x00452D00
     * @param isActive Активность слота
     * @param controllerType Тип контроллера
     * @param playerID ID игрока
     * @param stateFlags Флаги состояния
     */
    void Initialize(uint8_t isActive, uint8_t controllerType, 
                    uint8_t playerID, uint8_t stateFlags);
    
    /**
     * @brief Проверка активности слота
     * @return true если слот активен
     */
    bool IsActiveSlot() const { return IsActive != 0; }
    
    /**
     * @brief Установка активности
     * @param active Новое состояние активности
     */
    void SetActive(bool active) { IsActive = active ? 1 : 0; }
    
    /**
     * @brief Установка типа контроллера
     * @param type Тип устройства (0=клавиатура, 1=геймпад)
     */
    void SetControllerType(uint8_t type) { ControllerType = type; }
    
    /**
     * @brief Установка ID игрока
     * @param id Идентификатор игрока
     */
    void SetPlayerID(uint8_t id) { PlayerID = id; }
    
    /**
     * @brief Установка флага состояния
     * @param flag Бит флага для установки
     * @param value Значение флага (true/false)
     */
    void SetStateFlag(uint8_t flag, bool value);
    
    /**
     * @brief Проверка флага состояния
     * @param flag Бит флага для проверки
     * @return true если флаг установлен
     */
    bool HasStateFlag(uint8_t flag) const;
    
    /**
     * @brief Сброс всех настроек слота
     */
    void Reset();
};

#pragma pack(pop)

#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif

// C-версия структуры
typedef struct PlayerSlotConfig_t
{
    uint8_t IsActive;           ///< Активность слота
    uint8_t ControllerType;     ///< Тип контроллера
    uint8_t PlayerID;           ///< ID игрока
    uint8_t StateFlags;         ///< Флаги состояния
} PlayerSlotConfig_t;

// Утверждение размера для C версии
// sizeof(PlayerSlotConfig_t) должно быть равно 4

#ifdef __cplusplus
}
#endif

// Функции для работы с PlayerSlotConfig в C стиле
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Инициализация структуры PlayerSlotConfig
 * @param config Указатель на структуру
 * @param isActive Активность
 * @param controllerType Тип контроллера
 * @param playerID ID игрока
 * @param stateFlags Флаги состояния
 */
void PlayerSlotConfig_Init(PlayerSlotConfig_t* config, 
                           uint8_t isActive, 
                           uint8_t controllerType,
                           uint8_t playerID, 
                           uint8_t stateFlags);

/**
 * @brief Сброс структуры PlayerSlotConfig
 * @param config Указатель на структуру
 */
void PlayerSlotConfig_Reset(PlayerSlotConfig_t* config);

/**
 * @brief Проверка активности слота
 * @param config Указатель на структуру
 * @return 1 если активен, 0 иначе
 */
int PlayerSlotConfig_IsActive(const PlayerSlotConfig_t* config);

/**
 * @brief Установка флага состояния
 * @param config Указатель на структуру
 * @param flag Бит флага
 * @param value Значение (0 или 1)
 */
void PlayerSlotConfig_SetFlag(PlayerSlotConfig_t* config, 
                              uint8_t flag, 
                              int value);

/**
 * @brief Проверка флага состояния
 * @param config Указатель на структуру
 * @param flag Бит флага
 * @return 1 если установлен, 0 иначе
 */
int PlayerSlotConfig_HasFlag(const PlayerSlotConfig_t* config, 
                             uint8_t flag);

#ifdef __cplusplus
}
#endif
