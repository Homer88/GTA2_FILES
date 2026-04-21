#ifndef GTA2_WEAPON_H
#define GTA2_WEAPON_H

#include <stdint.h>

// Старое имя: Weapon
// Размер: 48 байт (0x30)
// Конструктор: 0x00426760 (Weapon::Weapon)
// Назначение: Экземпляр оружия у персонажа или машины

typedef enum EWeaponType {
    Pistolet = 0,
    // Другие типы оружия будут добавлены после анализа
    WEAPON_TYPE_UNKNOWN = 0xFF
} EWeaponType;

// Структура Weapon - точные поля из конструктора
typedef struct CWeapon {
    int32_t Ammo;           // 0x00: Текущее количество патронов
    void* Ped;              // 0x04: Указатель на владельца-персонажа (Ped*)
    void* Car;              // 0x08: Указатель на владельца-машину (Car*)
    int32_t TimeToReload;   // 0x0C: Таймер до завершения перезарядки
    int32_t SMG;            // 0x10: Флаг наличия/типа SMG
    struct CWeapon* NextWeapon; // 0x14: Указатель на следующее оружие (список/пул)
    EWeaponType TypeWeapon; // 0x18: Тип оружия
    int16_t ClipAmmo;       // 0x19: Патроны в магазине (short)
    uint8_t _pad1;          // 0x1B: Выравнивание
    int32_t field_1C;       // 0x1C: Неизвестное поле (field_8 в декомпиляции)
    int32_t field_20;       // 0x20: Неизвестное поле (field_C в декомпиляции, init -1)
    uint8_t field_24;       // 0x24: Флаг 1 (field_20 в декомпиляции)
    uint8_t field_25;       // 0x25: Флаг 2 (field_21 в декомпиляции)
    uint8_t _pad2[2];       // 0x26: Выравнивание
    int32_t field_28;       // 0x28: Неизвестное поле (field_2C в декомпиляции)
    int32_t SoundWeapon;    // 0x2C: ID звука оружия
} CWeapon;

// Проверка размера
static_assert(sizeof(CWeapon) == 0x30, "CWeapon size must be 48 bytes (0x30)");

#ifdef __cplusplus
extern "C" {
#endif

// Только подтвержденная функция из бинарника
CWeapon* Weapon_Constructor(CWeapon* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_WEAPON_H
