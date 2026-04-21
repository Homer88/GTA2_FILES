/**
 * @file weapon.cpp
 * @brief C++ wrapper-функции для оружия в GTA2
 * 
 * Использует структуры вместо классов.
 * Пространство имен: GTA2::Weapons
 * Старые имена функций (IDA Pro): sub_XXXXXX
 */

#include "entities/weapon.h"
#include <cstring>

extern "C" {
    // Подключаем C реализации
    #include "weapons/weapon.c"
}

namespace GTA2 {
namespace Weapons {

/* ==========================================================================
 * Wrapper-функции инициализации и базовой логики
 * ========================================================================== */

/**
 * @brief Инициализация оружия (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @param type Тип оружия
 * 
 * old_name: sub_004A1230
 */
void Init(Weapon* weapon, WeaponType type) {
    Weapon_Init(weapon, type);
}

/**
 * @brief Обновление оружия (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @param ped_owner Владелец
 * @param delta_time Дельта времени
 * 
 * old_name: sub_004A1280
 */
void Update(Weapon* weapon, Ped* ped_owner, float delta_time) {
    Weapon_Update(weapon, ped_owner, delta_time);
}

/**
 * @brief Выстрел из оружия (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @param target Цель
 * @return Результат выстрела
 * 
 * old_name: sub_004A1350
 */
int Fire(Weapon* weapon, Vector3* target) {
    return Weapon_Fire(weapon, target);
}

/**
 * @brief Перезарядка (C++ wrapper)
 * @param weapon Указатель на Weapon
 * 
 * old_name: sub_004A13E0
 */
void Reload(Weapon* weapon) {
    Weapon_Reload(weapon);
}

/**
 * @brief Добавление патронов (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @param amount Количество
 * 
 * old_name: sub_004A1450
 */
void AddAmmo(Weapon* weapon, int amount) {
    Weapon_AddAmmo(weapon, amount);
}

/* ==========================================================================
 * Wrapper-функции получения характеристик
 * ========================================================================== */

/**
 * @brief Получить урон (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @return Урон
 * 
 * old_name: sub_004A14C0
 */
float GetDamage(const Weapon* weapon) {
    return Weapon_GetDamage(weapon);
}

/**
 * @brief Получить дальность (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @return Дальность
 * 
 * old_name: sub_004A1510
 */
float GetRange(const Weapon* weapon) {
    return Weapon_GetRange(weapon);
}

/**
 * @brief Получить точность (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @return Точность
 * 
 * old_name: sub_004A1560
 */
float GetAccuracy(const Weapon* weapon) {
    return Weapon_GetAccuracy(weapon);
}

/**
 * @brief Получить статистику (C++ wrapper)
 * @param type Тип оружия
 * @return Статистика
 * 
 * old_name: sub_004A15B0
 */
const WeaponStats* GetStats(WeaponType type) {
    return Weapon_GetStats(type);
}

/* ==========================================================================
 * Wrapper-функции проверки условий
 * ========================================================================== */

/**
 * @brief Проверка возможности выстрела (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @return Можно ли стрелять
 * 
 * old_name: sub_004A1680
 */
int CanFire(const Weapon* weapon) {
    return Weapon_CanFire(weapon);
}

/**
 * @brief Проверка необходимости перезарядки (C++ wrapper)
 * @param weapon Указатель на Weapon
 * @return Нужна ли перезарядка
 * 
 * old_name: sub_004A16D0
 */
int NeedsReload(const Weapon* weapon) {
    return Weapon_NeedsReload(weapon);
}

/**
 * @brief Сброс оружия (C++ wrapper)
 * @param weapon Указатель на Weapon
 * 
 * old_name: sub_004A1720
 */
void Reset(Weapon* weapon) {
    Weapon_Reset(weapon);
}

/* ==========================================================================
 * Вспомогательные wrapper-функции
 * ========================================================================== */

/**
 * @brief Получить название типа (C++ wrapper)
 * @param type Тип оружия
 * @return Название
 * 
 * old_name: sub_004A1780
 */
const char* GetTypeName(WeaponType type) {
    return Weapon_GetTypeName(type);
}

/**
 * @brief Клонирование оружия (C++ wrapper)
 * @param dest Куда копировать
 * @param src Откуда копировать
 * 
 * old_name: sub_004A1800
 */
void Copy(Weapon* dest, const Weapon* src) {
    Weapon_Copy(dest, src);
}

} // namespace Weapons
} // namespace GTA2
