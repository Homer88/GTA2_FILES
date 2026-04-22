/*
 * File: weapon.c
 * Description: Реализация структуры Weapon (CWeapon)
 * Старое имя: Weapon
 * Размер: 48 байт (0x30)
 * Конструктор: 0x00426760
 */

#include "../../include/entities/weapon.h"
#include <stdint.h>

// Конструктор Weapon - только подтвержденная логика из бинарника
CWeapon* Weapon_Constructor(CWeapon* this) {
    if (!this) return 0;

    // Инициализация полей согласно ассемблерному листингу
    this->Ammo = 0;
    this->Ped = 0;
    this->Car = 0;
    this->TimeToReload = 0;
    this->SMG = 0;
    this->NextWeapon = 0;
    this->TypeWeapon = Pistolet;
    this->ClipAmmo = 0;
    this->_pad1 = 0;
    this->field_1C = 0;
    this->field_20 = -1;  // Инициализируется в -1
    this->field_24 = 0;
    this->field_25 = 0;
    this->_pad2[0] = 0;
    this->_pad2[1] = 0;
    this->field_28 = 0;
    this->SoundWeapon = 0;

    return this;
}

// Проверка размера при компиляции
_Static_assert(sizeof(CWeapon) == 0x30, "CWeapon size must be 48 bytes");
