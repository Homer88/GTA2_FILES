// Auto-generated structure: Player
// Source: Player.txt
// Fields count: 144
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct Player
{
    KeyPlayer Rotate;
    FW FW;
    __int16 Sw;
    __int16 TypeWeapon;
    __int16 SelectWeaponNext;
    char field_1E;
    char field_1F;
    int ID;
    __int16 MoneyValue;
    char field_2F;
    int field_3C;
    DEATH_REASON DeathReason;
    int Sound;
    int field_50;
    int field_54;
    int field_58;
    int field_60;
    int field_64;
    int MultiPlayerMode;
    int field_6C;
    byte Up;
    byte Down;
    byte Left;
    byte Right;
    byte prevWeapon;
    byte nextWeapon;
    byte debugKey1;
    byte debugKey2;
    bool Forward;
    bool Backward;
    bool RotateLeft;
    bool RotateRight;
    bool Attack;
    bool Enter;
    bool Jump;
    bool NextWeaponZ;
    bool PrevWeaponX;
    bool keySpecial;
    bool keySpecial2;
    char field_83;
    int field_84;
    int field_88;
    char AttackIsChanged;
    char field_8D;
    byte PlayerNext;
    char field_8F;
    char field_94;
    char field_95;
    char field_96;
    char field_97;
    int State;
    int field_A0;
    char field_A7;
    char field_A8;
    char field_A9;
    char field_AC;
    char field_D3;
    char field_DB;
    char field_EA;
    char field_F7;
    char field_102;
    char field_115;
    char field_116;
    char field_117;
    int field_118;
    int field_11C;
    int field_120;
    char field_124;
    char field_125;
    char field_126;
    char field_127;
    int field_128;
    int field_12C;
    int field_130;
    char field_154;
    char field_193;
    char field_1A6;
    char field_1C7;
    char field_1D1;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int Camer_X_View;
    int Camer_Y_View;
    int Camer_Z_View;
    char field_1F3;
    char field_1FA;
    char field_202;
    char field_20C;
    char field_229;
    char field_24D;
    char field_259;
    char field_26B;
    char field_28C;
    char field_298;
    char field_29E;
    char field_29F;
    int AuxGameCameraX;
    int AuxGameCameraY;
    int AuxGameCameraZ;
    char field_2D0;
    char field_343;
    char field_3E4;
    char field_41A;
    char field_449;
    char field_469;
    char field_46A;
    char field_46B;
    char field_46C;
    char field_46D;
    char field_46E;
    char field_46F;
    char field_470;
    char field_471;
    char field_472;
    char field_473;
    char field_474;
    char field_475;
    char field_476;
    char field_477;
    char field_478;
    char field_479;
    char field_47A;
    char field_47B;
    char field_47C;
    char field_47D;
    char field_47E;
    char field_47F;
    char field_480;
    char field_48A;
    char field_640;
    int field_644;
    int field_678;
    int field_67C;
    __int16 field_682;
    char field_6C0;
    char field_6D9;
    char field_6E5;
    char field_6EC;
    __int16 SelectWeapon;
    bool quit1;
    char field_78B;
    char Network;
    char field_79E;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(Player) == EXPECTED_SIZE, "Size mismatch for Player");
