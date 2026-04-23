/**
 * @file Ped.h
 * @brief Структура пешехода (Ped) - персонажи, NPC, враги
 * 
 * Адрес структуры в дампе: line 3418 в gta2.exe.h
 * Размер: 0x5F0 (1520 байт) - требует проверки по бинарнику
 * Основано на: gta2.exe/ida_pro/gta2.exe.h, gta2.exe.map
 * 
 * Функции: 251 функция из gta2.exe.map
 */

#pragma once

#ifndef PED_H
#define PED_H

#include <cstdint>

// Forward declarations
struct Car;
struct Player;
struct Weapon;
struct Gang;
struct GameObject;

#pragma pack(push, 1)

struct Ped
{
    // === Базовые поля GameObject (наследуется концептуально) ===
    void* vtable;                       // 0x0000 - VTable
    void* SpriteS1;                     // 0x0004 - Спрайт
    void* Model;                        // 0x0008 - Модель
    float X;                            // 0x000C - Позиция X
    float Y;                            // 0x0010 - Позиция Y
    float Z;                            // 0x0014 - Позиция Z
    float Rotation;                     // 0x0018 - Вращение
    int ID;                             // 0x001C - Идентификатор
    int Flags;                          // 0x0020 - Флаги
    int Type;                           // 0x0024 - Тип
    
    // === Специфичные поля Ped ===
    int Health;                         // 0x0028 - Здоровье
    int MaxHealth;                      // 0x002C - Максимальное здоровье
    int Armour;                         // 0x0030 - Броня
    Weapon* pCurrentWeapon;             // 0x0034 - Текущее оружие
    Car* pCurrentCar;                   // 0x0038 - Текущий автомобиль
    int State;                          // 0x003C - Состояние (AI state)
    int Action;                         // 0x0040 - Текущее действие
    int AnimationState;                 // 0x0044 - Состояние анимации
    int Occupation;                     // 0x0048 - Профессия/род занятий
    Gang* pGang;                        // 0x004C - Принадлежность к банде
    Player* pPlayer;                    // 0x0050 - Если это игрок
    int SearchType;                     // 0x0054 - Тип поиска цели
    int TargetX;                        // 0x0058 - Целевая точка X
    int TargetY;                        // 0x005C - Целевая точка Y
    int TargetZ;                        // 0x0060 - Целевая точка Z
    float Speed;                        // 0x0064 - Скорость движения
    int Stance;                         // 0x0068 - Стойка (стоять/бежать)
    int DamageState;                    // 0x006C - Состояние повреждений
    int ExitAnim;                       // 0x0070 - Анимация выхода из авто
    int field_74;                       // 0x0074
    int field_78;                       // 0x0078
    int field_7C;                       // 0x007C
    // ... остальные поля требуют анализа дампа
    char reserved[0x5F0 - 0x80];        // Заполнитель до размера структуры
};

#pragma pack(pop)


// ============================================================================
// ФУНКЦИИ PED (адреса из gta2.exe.map)
// Всего: 251 функция
// ============================================================================


// === Основные функции управления (0x00412920 - 0x00412B90) ===
#ifdef __cplusplus
extern "C" {
#endif
// Адрес: 0x00412920 - Ped__SetSearchType
void Ped__SetSearchType(Ped* ped, int searchType);

// Адрес: 0x00412930 - Ped__sub_403930
void Ped__sub_403930(Ped* ped);

// Адрес: 0x00412940 - Ped__SetAssignedCarIndex
void Ped__SetAssignedCarIndex(Ped* ped, int carIndex);

// Адрес: 0x00412950 - Ped__ClearFlags
void Ped__ClearFlags(Ped* ped, int flags);

// Адрес: 0x00412960 - Ped__UpdateState
void Ped__UpdateState(Ped* ped);

// Адрес: 0x00412970 - Ped__SetCurrentOccupation
void Ped__SetCurrentOccupation(Ped* ped, int occupation);

// Адрес: 0x00412980 - Ped__GetCurrentOccupation
int Ped__GetCurrentOccupation(Ped* ped);

// Адрес: 0x00412990 - Ped__GetPedState
int Ped__GetPedState(Ped* ped);

// Адрес: 0x004129A0 - Ped__SetHealth
void Ped__SetHealth(Ped* ped, int health);

// Адрес: 0x004129B0 - Ped__SetTargetCarDoor
void Ped__SetTargetCarDoor(Ped* ped, int doorIndex);

// Адрес: 0x004129C0 - Ped__GetTargetCarDoor
int Ped__GetTargetCarDoor(Ped* ped);

// Адрес: 0x004129D0 - Ped__GetExitAnim
int Ped__GetExitAnim(Ped* ped);

// Адрес: 0x004129E0 - Ped__GetDamageState
int Ped__GetDamageState(Ped* ped);

// Адрес: 0x004129F0 - Ped__GetSub_4039F0
void* Ped__GetSub_4039F0(Ped* ped);

// Адрес: 0x00412A00 - Ped__GetXCoordinate
float Ped__GetXCoordinate(Ped* ped);

// Адрес: 0x00412A10 - Ped__GetYCoordinate
float Ped__GetYCoordinate(Ped* ped);

// Адрес: 0x00412A20 - Ped__SetSub_403A20
void Ped__SetSub_403A20(Ped* ped, int value);

// Адрес: 0x00412A30 - Ped__ResetToDefaults
void Ped__ResetToDefaults(Ped* ped);

// Адрес: 0x00412A40 - Ped__Initialize
void Ped__Initialize(Ped* ped);

// Адрес: 0x00412A50 - Ped__SetFlags
void Ped__SetFlags(Ped* ped, int flags);

// Адрес: 0x00412A60 - Ped__GetAnimationState
int Ped__GetAnimationState(Ped* ped);

// Адрес: 0x00412A70 - Ped__SetAnimationState_0
void Ped__SetAnimationState_0(Ped* ped, int animState);

// Адрес: 0x00412A80 - Ped__GetActionParam
int Ped__GetActionParam(Ped* ped);

// Адрес: 0x00412A90 - Ped__GetCurrentAction
int Ped__GetCurrentAction(Ped* ped);

// Адрес: 0x00412AA0 - Ped__EnterCar
void Ped__EnterCar(Ped* ped, Car* car);

// Адрес: 0x00412AB0 - Ped__GetVehicle
Car* Ped__GetVehicle(Ped* ped);

// Адрес: 0x00412AC0 - Ped__SetAsDriver
void Ped__SetAsDriver(Ped* ped, Car* car);

// Адрес: 0x00412AD0 - Ped__GetPassenger
void* Ped__GetPassenger(Ped* ped);

// Адрес: 0x00412AE0 - Ped__SetPed2
void Ped__SetPed2(Ped* ped, Ped* otherPed);

// Адрес: 0x00412AF0 - Ped__GetLinkedPed
Ped* Ped__GetLinkedPed(Ped* ped);

// Адрес: 0x00412B00 - Ped__SetCarPed
void Ped__SetCarPed(Ped* ped, Car* car);

// Адрес: 0x00412B10 - Ped__GetCurrentVehicle
Car* Ped__GetCurrentVehicle(Ped* ped);

// Адрес: 0x00412B20 - Ped__Get_sub_403B20
void* Ped__Get_sub_403B20(Ped* ped);

// Адрес: 0x00412B30 - Ped__Get_sub_403B30
void* Ped__Get_sub_403B30(Ped* ped);

// Адрес: 0x00412B40 - Ped__sub_403B40
void Ped__sub_403B40(Ped* ped);

// Адрес: 0x00412B50 - Ped__SetExitAnimationState
void Ped__SetExitAnimationState(Ped* ped, int state);

// Адрес: 0x00412B60 - Ped__GetDeadPed
Ped* Ped__GetDeadPed(Ped* ped);

// Адрес: 0x00412B70 - Ped__GetExitAnimState
int Ped__GetExitAnimState(Ped* ped);

// Адрес: 0x00412B80 - Ped__IsInsideVehicle
bool Ped__IsInsideVehicle(Ped* ped);

// Адрес: 0x00412B90 - Ped__GetStance
int Ped__GetStance(Ped* ped);

// === Дополнительные функции (выборочно из 251) ===
// Адрес: 0x004117D0 - Ped__sub_4117D0
void Ped__sub_4117D0(Ped* ped);

// Адрес: 0x004117F0 - Ped__Set_4117F0
void Ped__Set_4117F0(Ped* ped, int value);

// Адрес: 0x00425B50 - Ped__GetPositionZ
float Ped__GetPositionZ(Ped* ped);

// Адрес: 0x00425B60 - Ped__GetCarPlayers
void* Ped__GetCarPlayers(Ped* ped);

// Адрес: 0x0042A0A0 - Ped__IsPlayerControlled
bool Ped__IsPlayerControlled(Ped* ped);

// Адрес: 0x00420B60 - Ped__sub_420B60
void Ped__sub_420B60(Ped* ped);

// Адрес: 0x00420B70 - Ped__sub_420B70
void Ped__sub_420B70(Ped* ped);

// Адрес: 0x00420B80 - Ped__SetPoliceNoStar
void Ped__SetPoliceNoStar(Ped* ped);

// Адрес: 0x00433190 - Ped__GetOccupationStatus
int Ped__GetOccupationStatus(Ped* ped);

// Адрес: 0x004331D0 - Ped__Set_4331D0
void Ped__Set_4331D0(Ped* ped, int value);

// Адрес: 0x004331E0 - Ped__sub_4331E0
void Ped__sub_4331E0(Ped* ped);

// Адрес: 0x00433200 - Ped__GetCar
Car* Ped__GetCar(Ped* ped);

// Адрес: 0x00433270 - Ped__UpdatePedState
void Ped__UpdatePedState(Ped* ped);

// Адрес: 0x004333A0 - Ped__IsSearchType
bool Ped__IsSearchType(Ped* ped, int type);

// Адрес: 0x00433B70 - Ped__GetHealth
int Ped__GetHealth(Ped* ped);

// Адрес: 0x00433B80 - Ped__SetParam
void Ped__SetParam(Ped* ped, int param);

// Адрес: 0x00433B90 - Ped__SetRemap
void Ped__SetRemap(Ped* ped, int remapId);

// Адрес: 0x00433BA0 - Ped__GetRemap
int Ped__GetRemap(Ped* ped);

// Адрес: 0x00433C00 - Ped__SetRotation
void Ped__SetRotation(Ped* ped, float rotation);

// Адрес: 0x00433DC0 - Ped__GetPoliceStar
int Ped__GetPoliceStar(Ped* ped);


#ifdef __cplusplus
}
#endif

#endif // PED_H
