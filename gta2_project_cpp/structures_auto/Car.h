// Auto-generated structure: Car
// Source: Car.txt
// Fields count: 41
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct Car
{
    CAR_LIGHTS_AND_DOORS_BITSTATE carLights;
    int field_68;
    int ID;
    __int16 Damage;
    __int16 field_76;
    __int16 PhysicsBitmask;
    char field_7A;
    char field_7B;
    SearchType SearchType;
    char field_80;
    char field_81;
    char field_82;
    char field_83;
    CarModel CarType;
    int Mask;
    char FireState;
    char field_8D;
    char AlarmTime;
    char field_8F;
    DamageType DamageType;
    char DamageShotTimer;
    char PlayerId;
    char field_96;
    char field_97;
    int locksDoor;
    CAR_ENGINE_STATE engineState;
    TRAFFIC_CAR_TYPE trafficCarType;
    char sirenState;
    char sirenPhase;
    char field_A6;
    char horn;
    char field_A8;
    char FireTimer;
    char field_AA;
    char field_AB;
    int field_AC;
    int field_B0;
    char field_B8;
    char field_B9;
    char field_BA;
    char field_0;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(Car) == EXPECTED_SIZE, "Size mismatch for Car");
