/**
 * @file weapon.c
 * @brief Реализация функций оружия для GTA2
 * 
 * Старые имена функций (IDA Pro): sub_XXXXXX
 * Структуры: Weapon, WeaponStats
 */

#include "entities/weapon.h"
#include <string.h>

/* ==========================================================================
 * Функции инициализации и базовой логики
 * ========================================================================== */

/**
 * @brief Инициализация структуры оружия
 * @param weapon Указатель на структуру Weapon
 * @param type Тип оружия
 * 
 * old_name: sub_004A1230
 */
void Weapon_Init(Weapon* weapon, WeaponType type) {
    // old_var: pWeapon
    // old_var: iType
    if (!weapon) return;
    
    weapon->type = type;
    weapon->ammo_count = 0;
    weapon->state = WEAPON_STATE_IDLE;
    weapon->timer = 0;
    weapon->flags = 0;
}

/**
 * @brief Обновление состояния оружия (стрельба, перезарядка)
 * @param weapon Указатель на структуру Weapon
 * @param ped_owner Владелец оружия (Ped)
 * @param delta_time Время с последнего кадра
 * 
 * old_name: sub_004A1280
 */
void Weapon_Update(Weapon* weapon, Ped* ped_owner, float delta_time) {
    // old_var: pWeapon
    // old_var: pPed
    // old_var: fDeltaTime
    if (!weapon || !ped_owner) return;
    
    switch (weapon->state) {
        case WEAPON_STATE_FIRING:
            weapon->timer -= delta_time;
            if (weapon->timer <= 0.0f) {
                weapon->state = WEAPON_STATE_IDLE;
            }
            break;
            
        case WEAPON_STATE_RELOADING:
            weapon->timer -= delta_time;
            if (weapon->timer <= 0.0f) {
                weapon->state = WEAPON_STATE_IDLE;
                weapon->ammo_count = weapon->max_ammo;
            }
            break;
            
        default:
            break;
    }
}

/**
 * @brief Попытка выстрела из оружия
 * @param weapon Указатель на структуру Weapon
 * @param target Целевая точка
 * @return 1 если выстрел успешен, 0 иначе
 * 
 * old_name: sub_004A1350
 */
int Weapon_Fire(Weapon* weapon, Vector3* target) {
    // old_var: pWeapon
    // old_var: pTarget
    if (!weapon || !target) return 0;
    
    if (weapon->ammo_count <= 0) {
        return 0; // Нет патронов
    }
    
    if (weapon->state != WEAPON_STATE_IDLE) {
        return 0; // Оружие не готово
    }
    
    weapon->ammo_count--;
    weapon->state = WEAPON_STATE_FIRING;
    weapon->timer = weapon->fire_delay;
    
    // old_var: bSuccess
    return 1;
}

/**
 * @brief Перезарядка оружия
 * @param weapon Указатель на структуру Weapon
 * 
 * old_name: sub_004A13E0
 */
void Weapon_Reload(Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return;
    
    if (weapon->state != WEAPON_STATE_IDLE) {
        return; // Нельзя прервать текущее действие
    }
    
    if (weapon->ammo_count >= weapon->max_ammo) {
        return; // Полностью заряжено
    }
    
    weapon->state = WEAPON_STATE_RELOADING;
    weapon->timer = weapon->reload_time;
}

/**
 * @brief Добавление патронов к оружию
 * @param weapon Указатель на структуру Weapon
 * @param amount Количество патронов
 * 
 * old_name: sub_004A1450
 */
void Weapon_AddAmmo(Weapon* weapon, int amount) {
    // old_var: pWeapon
    // old_var: iAmount
    if (!weapon) return;
    
    weapon->ammo_count += amount;
    if (weapon->ammo_count > weapon->max_ammo) {
        weapon->ammo_count = weapon->max_ammo;
    }
}

/* ==========================================================================
 * Функции получения характеристик оружия
 * ========================================================================== */

/**
 * @brief Получить урон оружия
 * @param weapon Указатель на структуру Weapon
 * @return Значение урона
 * 
 * old_name: sub_004A14C0
 */
float Weapon_GetDamage(const Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return 0.0f;
    
    const WeaponStats* stats = Weapon_GetStats(weapon->type);
    if (!stats) return 0.0f;
    
    return stats->base_damage;
}

/**
 * @brief Получить дальность оружия
 * @param weapon Указатель на структуру Weapon
 * @return Значение дальности
 * 
 * old_name: sub_004A1510
 */
float Weapon_GetRange(const Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return 0.0f;
    
    const WeaponStats* stats = Weapon_GetStats(weapon->type);
    if (!stats) return 0.0f;
    
    return stats->range;
}

/**
 * @brief Получить точность оружия
 * @param weapon Указатель на структуру Weapon
 * @return Значение точности (0.0 - 1.0)
 * 
 * old_name: sub_004A1560
 */
float Weapon_GetAccuracy(const Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return 0.0f;
    
    const WeaponStats* stats = Weapon_GetStats(weapon->type);
    if (!stats) return 0.0f;
    
    return stats->accuracy;
}

/**
 * @brief Получить статистику по типу оружия
 * @param type Тип оружия
 * @return Указатель на константную статистику
 * 
 * old_name: sub_004A15B0
 */
const WeaponStats* Weapon_GetStats(WeaponType type) {
    // old_var: iType
    // Статическая таблица характеристик оружия
    static const WeaponStats weapon_stats_table[WEAPON_TYPE_COUNT] = {
        // FISTS
        {1.0f, 2.0f, 1.0f, 0.0f, 0, 0},
        // BAT
        {5.0f, 3.0f, 0.8f, 0.0f, 0, 0},
        // PISTOL
        {15.0f, 50.0f, 0.7f, 0.3f, 12, 0.1f},
        // UZI
        {8.0f, 30.0f, 0.5f, 0.5f, 30, 0.05f},
        // SHOTGUN
        {25.0f, 20.0f, 0.6f, 0.8f, 8, 0.2f},
        // AK47
        {12.0f, 80.0f, 0.65f, 0.4f, 30, 0.08f},
        // FLAMETHROWER
        {3.0f, 15.0f, 0.4f, 1.0f, 100, 0.0f},
        // ROCKETLAUNCHER
        {100.0f, 100.0f, 0.8f, 0.0f, 1, 0.5f}
    };
    
    if (type < 0 || type >= WEAPON_TYPE_COUNT) {
        return &weapon_stats_table[0]; // Возвращаем кулаки по умолчанию
    }
    
    return &weapon_stats_table[type];
}

/* ==========================================================================
 * Функции проверки условий
 * ========================================================================== */

/**
 * @brief Проверка возможности выстрела
 * @param weapon Указатель на структуру Weapon
 * @return 1 если можно выстрелить, 0 иначе
 * 
 * old_name: sub_004A1680
 */
int Weapon_CanFire(const Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return 0;
    
    return (weapon->state == WEAPON_STATE_IDLE && weapon->ammo_count > 0);
}

/**
 * @brief Проверка необходимости перезарядки
 * @param weapon Указатель на структуру Weapon
 * @return 1 если нужна перезарядка, 0 иначе
 * 
 * old_name: sub_004A16D0
 */
int Weapon_NeedsReload(const Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return 0;
    
    return (weapon->ammo_count < weapon->max_ammo && weapon->ammo_count > 0);
}

/**
 * @brief Сброс состояния оружия
 * @param weapon Указатель на структуру Weapon
 * 
 * old_name: sub_004A1720
 */
void Weapon_Reset(Weapon* weapon) {
    // old_var: pWeapon
    if (!weapon) return;
    
    weapon->state = WEAPON_STATE_IDLE;
    weapon->timer = 0;
    weapon->ammo_count = weapon->max_ammo;
    weapon->flags = 0;
}

/* ==========================================================================
 * Вспомогательные функции
 * ========================================================================== */

/**
 * @brief Получить название типа оружия
 * @param type Тип оружия
 * @return Строковое представление
 * 
 * old_name: sub_004A1780
 */
const char* Weapon_GetTypeName(WeaponType type) {
    // old_var: iType
    switch (type) {
        case WEAPON_TYPE_FISTS: return "Fists";
        case WEAPON_TYPE_BAT: return "Baseball Bat";
        case WEAPON_TYPE_PISTOL: return "Pistol";
        case WEAPON_TYPE_UZI: return "Uzi";
        case WEAPON_TYPE_SHOTGUN: return "Shotgun";
        case WEAPON_TYPE_AK47: return "AK-47";
        case WEAPON_TYPE_FLAMETHROWER: return "Flamethrower";
        case WEAPON_TYPE_ROCKETLAUNCHER: return "Rocket Launcher";
        default: return "Unknown";
    }
}

/**
 * @brief Клонирование оружия
 * @param dest Целевая структура
 * @param src Исходная структура
 * 
 * old_name: sub_004A1800
 */
void Weapon_Copy(Weapon* dest, const Weapon* src) {
    // old_var: pDest
    // old_var: pSrc
    if (!dest || !src) return;
    
    memcpy(dest, src, sizeof(Weapon));
}
