// Auto-generated structure: Weapon
// Source: Weapon.txt
// Fields count: 18
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct Weapon
{
    char TimeToReload;
    char field_3;
    int SMG;
    int field_8;
    int field_C;
    __int16 short;
    char field_12;
    char field_13;
    WeaponType TypeWeapon;
    char field_20;
    char field_21;
    char field_22;
    char field_23;
    int SoundWeapon;
    char field_2C;
    char field_2D;
    char field_2E;
    char field_2F;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(Weapon) == EXPECTED_SIZE, "Size mismatch for Weapon");
