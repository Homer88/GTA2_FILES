/*
 * File: weapon.cpp
 * Description: C++ обертка для Weapon
 * Старое имя: Weapon
 * Размер: 48 байт (0x30)
 */

#include "../../include/entities/weapon.h"

#ifdef __cplusplus
extern "C" {
#endif

// Объявление C функции
CWeapon* Weapon_Constructor(CWeapon* this);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// Минимальная C++ обертка без выдуманных методов
struct CWeaponCpp {
    CWeapon base;
    
    CWeaponCpp() {
        Weapon_Constructor(&base);
    }
};
#endif
