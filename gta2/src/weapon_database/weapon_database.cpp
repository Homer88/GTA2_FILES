/*
 * File: weapon_database.cpp
 * Description: C++ реализация менеджера пула оружия
 * Original Name: Weapon1 -> WeaponDatabase
 * Size: 12252 bytes (0x2FDC)
 */

#include "../../include/entities/weapon_database.h"

// Конструктор
WeaponDatabase::WeaponDatabase() {
    WeaponDatabase_Constructor(this);
}

// Деструктор
WeaponDatabase::~WeaponDatabase() {
    // Очистка не требуется, т.к. память массива статическая
}

// Методы-обертки
Weapon* WeaponDatabase::Allocate() {
    return WeaponDatabase_Allocate(this);
}

void WeaponDatabase::Free(Weapon* weapon) {
    WeaponDatabase_Free(this, weapon);
}

int32_t WeaponDatabase::GetActiveCount() const {
    return field_2FD8;
}

// Статический метод создания
WeaponDatabase* WeaponDatabase::CreateInstance() {
    void* mem = operator new(sizeof(WeaponDatabase));
    if (mem) {
        return new(mem) WeaponDatabase(); // Placement new
    }
    return nullptr;
}

// Статический метод удаления
void WeaponDatabase::DestroyInstance(WeaponDatabase* db) {
    if (db) {
        db->~WeaponDatabase();
        operator delete(db);
    }
}
