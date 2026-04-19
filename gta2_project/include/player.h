#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "enums.h"
#include "forward_declarations.h"

struct Player {
    struct Player *CurrentPlayer;
    struct Player *Player;
    undefined2 Left; // Влево вправа поворот (48_влево 1392 вправо)
    undefined2 field3_0xa;
    undefined4 Forw; // Вперед 16384 назад 4294950912
    struct S46 *s46;
    short SW;
    short TypeWeapon;
    ushort field8_0x18;
    ushort Arrmo; // текущее состояние
    ushort SelectWeaponNext;
    undefined field11_0x1e;
    undefined field12_0x1f;
    struct Car *car;
    int ID_1;
    undefined1 field15_0x28;
    undefined1 field16_0x29;
    undefined field17_0x2a;
    undefined field18_0x2b;
    undefined2 field19_0x2c;
    byte IDs;
    undefined1 AllControlStatus;
    undefined1 EnterControlStatus;
    bool field23_0x31;
    undefined field24_0x32;
    undefined field25_0x33;
    undefined4 RESPECT;
    undefined4 field27_0x38;
    undefined4 field28_0x3c;
    struct S103 *S103;
    int PlayerState;
    undefined1 field31_0x48;
    undefined field32_0x49;
    undefined field33_0x4a;
    undefined field34_0x4b;
    undefined4 field35_0x4c;
    undefined field36_0x50;
    undefined field37_0x51;
    undefined field38_0x52;
    undefined field39_0x53;
    undefined4 field40_0x54;
    undefined4 theta;
    struct Car *pCar_2;
    undefined4 Revs;
    undefined4 field44_0x64;
    undefined4 ID;
    undefined4 field46_0x6c;
    undefined1 field47_0x70;
    undefined1 field48_0x71;
    undefined1 field49_0x72;
    undefined1 field50_0x73;
    undefined1 field51_0x74;
    undefined1 field52_0x75;
    byte field53_0x76;
    byte field54_0x77;
    bool KEY_UP;
    bool Backward;
    bool RotateLeft;
    bool RotateRight;
    bool Attack;
    bool Enter;
    undefined1 Jump;
    undefined1 NextWeaponZ;
    undefined1 PrevWeaponX;
    undefined1 keySpecial;
    undefined1 keySpecial2;
    undefined1 field66_0x83;
    undefined1 field67_0x84;
    undefined field68_0x85;
    undefined field69_0x86;
    undefined1 field70_0x87;
    undefined1 field71_0x88;
    undefined1 field72_0x89;
    undefined1 field73_0x8a;
    undefined1 field74_0x8b;
    undefined1 AttackIsChanged;
    undefined1 field76_0x8d;
    bool NextPlayer;
    undefined1 field78_0x8f;
    struct CameraOrPhysics *CameraOrPhysics;
    undefined field80_0x94;
    // Продолжение структуры можно добавить при необходимости
};

// Player function declarations
Player* Game__Game_FUN_003f11a8(Game *this);

#endif // PLAYER_H
