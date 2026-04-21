/*
 * File: weapon.cpp
 * Description: C++ реализация структуры Weapon
 * Original Name: Weapon
 * Size: 48 bytes (0x30)
 * Constructor Address: 0x00426760
 */

#include "../../include/entities/weapon.h"
#include <cstring>

// Конструктор C++
Weapon::Weapon() {
    Weapon_Constructor(this);
}

// Деструктор C++
Weapon::~Weapon() {
    Weapon_Destructor(this);
}

// Методы-обертки
void Weapon::SetOwner(void* ped, void* car) {
    Weapon_SetOwner(this, ped, car);
}

void Weapon::Reload() {
    Weapon_Reload(this);
}

int32_t Weapon::GetAmmo() const {
    return m_Ammo;
}

void Weapon::SetAmmo(int32_t ammo) {
    m_Ammo = ammo;
}

// Статический метод создания
Weapon* Weapon::Create() {
    Weapon* w = new Weapon();
    return w;
}

// Статический метод удаления
void Weapon::Destroy(Weapon* w) {
    delete w;
}
