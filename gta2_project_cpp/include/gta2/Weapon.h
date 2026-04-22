/**
 * @file Weapon.h
 * @brief Структура оружия и связанные типы
 * 
 * Адрес структуры в дампе: line 4935 в gta2.exe.h
 * Размер: 0x30 (48 байт)
 * Основано на: gta2.exe/ida_pro/gta2.exe.h, gta2.exe.map
 */

#pragma once

#include <cstdint>

// Forward declarations
struct Ped;
struct Car;

enum class WeaponType : int32_t {
    WEAPON_UNARMED = 0,
    WEAPON_PISTOL = 1,
    WEAPON_SHOTGUN = 2,
    WEAPON_UZI = 3,
    WEAPON_ROCKET_LAUNCHER = 4,
    WEAPON_FLAMETHROWER = 5,
    WEAPON_GRENADE = 6,
    WEAPON_MOLOTOV = 7,
    WEAPON_REMOTE_CONTROLLED_BOMB = 8,
    WEAPON_ROOF_GUN = 9,
    WEAPON_TANK_TURRET = 10,
    WEAPON_WATER_CANNON = 11,
    WEAPON_ELECTROFINGERS = 12
};

#pragma pack(push, 1)

struct Weapon
{
    uint16_t Ammo;            // 0x0000 - Количество патронов
    char TimeToReload;        // 0x0002 - Время до перезарядки
    char field_3;             // 0x0003
    int SMG;                  // 0x0004 - SMG related
    int field_8;              // 0x0008
    int field_C;              // 0x000C
    int16_t short_field;      // 0x0010
    char field_12;            // 0x0012
    char field_13;            // 0x0013
    Car* pCar;                // 0x0014 - Автомобиль (для оружия транспорта)
    Weapon* NextWeapon;       // 0x0018 - Следующее оружие в списке
    WeaponType TypeWeapon;    // 0x001C - Тип оружия
    char field_20;            // 0x0020
    char field_21;            // 0x0021
    char field_22;            // 0x0022
    char field_23;            // 0x0023
    Ped* pPed;                // 0x0024 - Владелец оружия (пешеход)
    int SoundWeapon;          // 0x0028 - Звук оружия
    char field_2C;            // 0x002C
    char field_2D;            // 0x002D
    char field_2E;            // 0x002E
    char field_2F;            // 0x002F
};

#pragma pack(pop)


// ============================================================================
// ФУНКЦИИ WEAPON (адреса из gta2.exe.map)
// ============================================================================


#ifdef __cplusplus
extern "C" {
#endif
// Адрес: 0x0041D550 - Weapon__UseAmmo
void Weapon__UseAmmo(Weapon* weapon, int amount);

// Адрес: 0x0042B1E0 - Weapon__sub_41C1E0
void Weapon__sub_41C1E0(Weapon* weapon);

// Адрес: 0x00432860 - Weapon__sub_432860
void Weapon__sub_432860(Weapon* weapon);

// Адрес: 0x00432810 - Weapon__SetWeapon
void Weapon__SetWeapon(Weapon* weapon, WeaponType type);

// Адрес: 0x004828C0 - Weapon__sub_4828C0
void Weapon__sub_4828C0(Weapon* weapon);

// Адрес: 0x004A4F80 - Weapon__GetArmo
int Weapon__GetArmo(Weapon* weapon);

// Адрес: 0x004A4F90 - Weapon__GiveWeaponInfiniti
void Weapon__GiveWeaponInfiniti(Weapon* weapon);

// Адрес: 0x004A4FA0 - Weapon__NotInfiniti
void Weapon__NotInfiniti(Weapon* weapon);

// Адрес: 0x004A4FB0 - Weapon__GetDisplayAmmo
int Weapon__GetDisplayAmmo(Weapon* weapon);

// Адрес: 0x004A4FE0 - Weapon__GetAmmo
int Weapon__GetAmmo(Weapon* weapon);

// Адрес: 0x004CC800 - Weapon__Weapon (constructor)
void Weapon__Weapon(Weapon* weapon);

// Адрес: 0x004CC810 - Weapon__InitializeWeapon
void Weapon__InitializeWeapon(Weapon* weapon, WeaponType type, int ammo);

// Адрес: 0x004CC860 - Weapon__SetAmmo
void Weapon__SetAmmo(Weapon* weapon, int ammo);

// Адрес: 0x004CC880 - Weapon__sub_4CC880
void Weapon__sub_4CC880(Weapon* weapon);

// Адрес: 0x004CC8C0 - Weapon__IsCarWeapon
bool Weapon__IsCarWeapon(Weapon* weapon);

// Адрес: 0x004CC950 - Weapon__sub_4CC950
void Weapon__sub_4CC950(Weapon* weapon);

// Адрес: 0x004CCA00 - Weapon__SetTypeWeapon_0
void Weapon__SetTypeWeapon_0(Weapon* weapon, WeaponType type);

// Адрес: 0x004CCA10 - Weapon__SetPed
void Weapon__SetPed(Weapon* weapon, Ped* ped);

// Адрес: 0x004CCA20 - Weapon__SetCar
void Weapon__SetCar(Weapon* weapon, Car* car);

// Адрес: 0x004CCA30 - Weapon__Decrement10Ammo
void Weapon__Decrement10Ammo(Weapon* weapon);

// Адрес: 0x004CCA60 - Weapon__Decrement1Ammo
void Weapon__Decrement1Ammo(Weapon* weapon);

// Адрес: 0x004CCA80 - Weapon__Set_4CCA80
void Weapon__Set_4CCA80(Weapon* weapon, int value);

// Адрес: 0x004CCB10 - Weapon__Weapon_dec
void Weapon__Weapon_dec(Weapon* weapon);

// Адрес: 0x004CCB40 - Weapon__sub_4CCB40
void Weapon__sub_4CCB40(Weapon* weapon);

// Адрес: 0x004CCB70 - Weapon__sub_4CCB70
void Weapon__sub_4CCB70(Weapon* weapon);

// Адрес: 0x004CD000 - Weapon__TimeToReload
bool Weapon__TimeToReload(Weapon* weapon);

// Адрес: 0x004CD020 - Weapon__sub_4CD020
void Weapon__sub_4CD020(Weapon* weapon);

// Адрес: 0x004CD400 - Weapon__sub_4CD400
void Weapon__sub_4CD400(Weapon* weapon);

// Адрес: 0x004CD460 - Weapon__sub_4CD460
void Weapon__sub_4CD460(Weapon* weapon);

// Адрес: 0x004CD5F0 - Weapon__sub_4CD5F0
void Weapon__sub_4CD5F0(Weapon* weapon);

// Адрес: 0x004CDA90 - Weapon__sub_4CDA90
void Weapon__sub_4CDA90(Weapon* weapon);

// Адрес: 0x004CDC20 - Weapon__sub_4CDC20
void Weapon__sub_4CDC20(Weapon* weapon);

// Адрес: 0x004CDDA0 - Weapon__sub_4CDDA0
void Weapon__sub_4CDDA0(Weapon* weapon);

// Адрес: 0x004CE070 - Weapon__sub_4CE070
void Weapon__sub_4CE070(Weapon* weapon);

// Адрес: 0x004CE270 - Weapon__sub_4CE270
void Weapon__sub_4CE270(Weapon* weapon);

// Адрес: 0x004CE4B0 - Weapon__sub_4CE4B0
void Weapon__sub_4CE4B0(Weapon* weapon);

// Адрес: 0x004CE6D0 - Weapon__sub_4CE6D0
void Weapon__sub_4CE6D0(Weapon* weapon);

// Адрес: 0x004CE970 - Weapon__sub_4CE970
void Weapon__sub_4CE970(Weapon* weapon);

// Адрес: 0x004CF380 - Weapon__sub_4CF380
void Weapon__sub_4CF380(Weapon* weapon);

// Адрес: 0x004CFA30 - Weapon__sub_4CFA30
void Weapon__sub_4CFA30(Weapon* weapon);

// Адрес: 0x004CFBE0 - Weapon__sub_4CFBE0
void Weapon__sub_4CFBE0(Weapon* weapon);

// Адрес: 0x004CFD80 - Weapon__sub_4CFD80
void Weapon__sub_4CFD80(Weapon* weapon);

// Адрес: 0x004CFEC0 - Weapon__sub_4CFEC0
void Weapon__sub_4CFEC0(Weapon* weapon);

// Адрес: 0x004D0080 - Weapon__sub_4D0080
void Weapon__sub_4D0080(Weapon* weapon);

// Адрес: 0x004D0230 - Weapon__sub_4D0230
void Weapon__sub_4D0230(Weapon* weapon);

#ifdef __cplusplus
}
#endif

#endif // WEAPON_H
