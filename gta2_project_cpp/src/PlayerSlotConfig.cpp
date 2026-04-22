/**
 * @file PlayerSlotConfig.cpp
 * @brief Реализация конфигурации слота игрока в меню
 * 
 * Оригинальное имя структуры: S138
 * Адреса функций из gta2.exe.map:
 * - Конструктор: 0x00452CE0 (S138__S138)
 * - Деструктор: 0x00452CF0 (S138__S138_DEC)
 * - Метод инициализации: 0x00452D00 (S138__sub_452D00)
 */

#include "gta2/PlayerSlotConfig.h"
#include <cstring>

#ifdef __cplusplus

// ============================================================================
// PlayerSlotConfig - реализация методов C++
// ============================================================================

/**
 * @brief Конструктор
 * Адрес: 0x00452CE0
 */
PlayerSlotConfig::PlayerSlotConfig()
    : IsActive(0)
    , ControllerType(0)
    , PlayerID(0)
    , StateFlags(0)
{
    // Инициализация всех полей в 0
    // Соответствует оригинальной функции S138__S138
}

/**
 * @brief Деструктор
 * Адрес: 0x00452CF0
 */
PlayerSlotConfig::~PlayerSlotConfig()
{
    // В оригинале деструктор пустой (S138__S138_DEC)
    // Никаких ресурсов не освобождается
}

/**
 * @brief Инициализация слота
 * Адрес: 0x00452D00
 */
void PlayerSlotConfig::Initialize(uint8_t isActive, 
                                   uint8_t controllerType,
                                   uint8_t playerID, 
                                   uint8_t stateFlags)
{
    IsActive = isActive;
    ControllerType = controllerType;
    PlayerID = playerID;
    StateFlags = stateFlags;
}

/**
 * @brief Установка флага состояния
 */
void PlayerSlotConfig::SetStateFlag(uint8_t flag, bool value)
{
    if (flag < 8) // Проверка на допустимый диапазон битов
    {
        if (value)
        {
            StateFlags |= (1 << flag);
        }
        else
        {
            StateFlags &= ~(1 << flag);
        }
    }
}

/**
 * @brief Проверка флага состояния
 */
bool PlayerSlotConfig::HasStateFlag(uint8_t flag) const
{
    if (flag < 8)
    {
        return (StateFlags & (1 << flag)) != 0;
    }
    return false;
}

/**
 * @brief Сброс всех настроек слота
 */
void PlayerSlotConfig::Reset()
{
    IsActive = 0;
    ControllerType = 0;
    PlayerID = 0;
    StateFlags = 0;
}

#endif // __cplusplus

// ============================================================================
// C-версия функций для работы с PlayerSlotConfig_t
// ============================================================================

extern "C" {

/**
 * @brief Инициализация структуры PlayerSlotConfig
 */
void PlayerSlotConfig_Init(PlayerSlotConfig_t* config,
                           uint8_t isActive,
                           uint8_t controllerType,
                           uint8_t playerID,
                           uint8_t stateFlags)
{
    if (config)
    {
        config->IsActive = isActive;
        config->ControllerType = controllerType;
        config->PlayerID = playerID;
        config->StateFlags = stateFlags;
    }
}

/**
 * @brief Сброс структуры PlayerSlotConfig
 */
void PlayerSlotConfig_Reset(PlayerSlotConfig_t* config)
{
    if (config)
    {
        config->IsActive = 0;
        config->ControllerType = 0;
        config->PlayerID = 0;
        config->StateFlags = 0;
    }
}

/**
 * @brief Проверка активности слота
 */
int PlayerSlotConfig_IsActive(const PlayerSlotConfig_t* config)
{
    if (config)
    {
        return config->IsActive != 0 ? 1 : 0;
    }
    return 0;
}

/**
 * @brief Установка флага состояния
 */
void PlayerSlotConfig_SetFlag(PlayerSlotConfig_t* config,
                              uint8_t flag,
                              int value)
{
    if (config && flag < 8)
    {
        if (value)
        {
            config->StateFlags |= (1 << flag);
        }
        else
        {
            config->StateFlags &= ~(1 << flag);
        }
    }
}

/**
 * @brief Проверка флага состояния
 */
int PlayerSlotConfig_HasFlag(const PlayerSlotConfig_t* config,
                             uint8_t flag)
{
    if (config && flag < 8)
    {
        return (config->StateFlags & (1 << flag)) != 0 ? 1 : 0;
    }
    return 0;
}

} // extern "C"
