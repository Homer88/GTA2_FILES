#ifndef GTA2_WEAPON_DATABASE_H
#define GTA2_WEAPON_DATABASE_H

#include "weapon.h"

// Старое имя: Weapon1
// Размер: 12252 байта (0x2FDC)
// Конструктор: WeaponDatabase::WeaponDatabase
// Назначение: Менеджер пула оружия (255 экземпляров)

struct WeaponDatabase {
    // Массив из 255 элементов оружия (255 * 48 = 12240 байт, 0x2FD0)
    Weapon sWeapon_Arr255[255];   // 0x0000 - 0x2FCF
    
    // Поля управления пулом (следуют сразу после массива)
    Weapon* sWeapon;              // 0x2FD0 Указатель на первый элемент (голова списка)
    Weapon* NextWeapon;           // 0x2FD4 Голова списка свободных/активных
    int32_t field_2FD8;           // 0x2FD8 Счетчик или флаг (инициализируется в 0)
    
    // Итого: 0x2FD0 + 4 + 4 + 4 = 0x2FDC (12252 байта)
};

static_assert(sizeof(WeaponDatabase) == 0x2FDC, "WeaponDatabase size must be 0x2FDC");

#ifdef __cplusplus
extern "C" {
#endif

WeaponDatabase* WeaponDatabase_Constructor(WeaponDatabase* this);
Weapon* WeaponDatabase_Allocate(WeaponDatabase* this);
void WeaponDatabase_Free(WeaponDatabase* this, Weapon* weapon);
int32_t WeaponDatabase_GetActiveCount(WeaponDatabase* this);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
struct WeaponDatabaseCpp : public WeaponDatabase {
    WeaponDatabaseCpp() { WeaponDatabase_Constructor(this); }
    ~WeaponDatabaseCpp() {}
    
    Weapon* Allocate() { return WeaponDatabase_Allocate(this); }
    void Free(Weapon* w) { WeaponDatabase_Free(this, w); }
    int32_t GetActiveCount() { return WeaponDatabase_GetActiveCount(this); }
};
#endif

#endif // GTA2_WEAPON_DATABASE_H
