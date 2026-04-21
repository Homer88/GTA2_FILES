/*
 * File: weapon_database.c
 * Description: Реализация WeaponDatabase (пул оружия)
 * Старое имя: Weapon1
 * Размер: 12252 байта (0x2FDC)
 * Конструктор: вызывается внутри Turrel
 */

#include "../../include/entities/weapon_database.h"
#include "../../include/entities/weapon.h"
#include <stdint.h>
#include <string.h>

// Внешняя функция Construct из runtime
extern void Construct(void* arr, size_t elemSize, size_t count, void (*ctor)(void*), void (*dtor)(void*));

CWeaponDatabase* WeaponDatabase_Constructor(CWeaponDatabase* this) {
    if (!this) return 0;

    // Инициализация массива из 255 элементов по 48 байт
    Construct(this->sWeapon_Arr255, sizeof(CWeapon), 255,
              (void(*)(void*))Weapon_Constructor,
              0); // Деструктор пока не определен

    // Построение связного списка через поле NextWeapon
    // sWeapon_Arr255[0].NextWeapon = &sWeapon_Arr255[1]
    // ...
    // sWeapon_Arr255[254].NextWeapon = 0
    for (int i = 0; i < 254; i++) {
        this->sWeapon_Arr255[i].NextWeapon = &this->sWeapon_Arr255[i + 1];
    }
    this->sWeapon_Arr255[254].NextWeapon = 0;

    // Инициализация заголовков
    this->sWeapon = &this->sWeapon_Arr255[0];
    this->NextWeapon = 0;
    this->field_2FD8 = 0;

    return this;
}

_Static_assert(sizeof(CWeaponDatabase) == 0x2FDC, "CWeaponDatabase size must be 0x2FDC");
