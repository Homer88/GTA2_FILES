/**
 * @file GameObject.h
 * @brief Базовая структура для всех объектов мира в GTA 2
 * 
 * Адрес структуры в дампе: line 3765 в gta2.exe.h
 * Размер: 0xB4 (180 байт) - 71 поле
 * Основано на: structures_dump/all_structures/GameObject.txt
 * 
 * ВАЖНО: Это базовый класс для Ped, Car и других объектов
 */

#pragma once

#include <cstdint>

// Forward declarations
struct Ped;
struct Car;
struct SpriteS1;

#pragma pack(push, 1)

struct GameObject
{
    // 0x000 - Основные поля
    GameObject* NextGameObject1;          // 0x0000
    char field_4;                         // 0x0004
    char Remap;                           // 0x0005
    char field_6;                         // 0x0006
    char field_7;                         // 0x0007
    int field_8;                          // 0x0008
    int field_C;                          // 0x000C
    int field_10;                         // 0x0010
    int16_t field_14;                     // 0x0014
    char field_16;                        // 0x0016
    char field_17;                        // 0x0017
    int field_18;                         // 0x0018
    int ProbablyPhysics;                  // 0x001C
    int field_20;                         // 0x0020
    int field_24;                         // 0x0024
    int16_t field_28;                     // 0x0028
    int16_t field_2A;                     // 0x002A
    int16_t field_2C;                     // 0x002C
    char field_2E;                        // 0x002E
    char field_2F;                        // 0x002F
    int field_30;                         // 0x0030
    int16_t short_field;                  // 0x0034
    char field_36;                        // 0x0036
    char field_37;                        // 0x0037
    int Speed;                            // 0x0038
    
    // 0x003C - Связанные объекты
    GameObject* NextGameObject;           // 0x003C
    int16_t Rotation;                     // 0x0040
    int16_t field_42;                     // 0x0042
    char field_44;                        // 0x0044
    char field_45;                        // 0x0045
    int16_t field_46;                     // 0x0046
    char field_48;                        // 0x0048
    char field_49;                        // 0x0049
    int16_t CigaretteIdleTimer;           // 0x004A
    Car* Car1;                            // 0x004C
    Car* Car2;                            // 0x0050
    char field_54;                        // 0x0054
    char field_55;                        // 0x0055
    char field_56;                        // 0x0056
    char field_57;                        // 0x0057
    int field_58;                         // 0x0058
    int field_5C;                         // 0x005C
    int field_60;                         // 0x0060
    int field_64;                         // 0x0064
    char field_68;                        // 0x0068
    char field_69;                        // 0x0069
    char field_6A;                        // 0x006A
    char field_6B;                        // 0x006B
    int field_6C;                         // 0x006C
    char field_70;                        // 0x0070
    char field_71;                        // 0x0071
    char field_72;                        // 0x0072
    char field_73;                        // 0x0073
    int16_t field_74;                     // 0x0074
    char field_76;                        // 0x0076
    char field_77;                        // 0x0077
    
    // 0x0078 - Указатели на связанные объекты
    GameObject* GameObject_ptr;           // 0x0078
    Ped* pPed;                            // 0x007C - Связанный Ped (если есть)
    SpriteS1* pSpriteS1;                  // 0x0080 - Спрайт объекта
    Car* pGetVehicle;                     // 0x0084
    Car* pCar;                            // 0x0088 - Связанный Car (если есть)
    int field_8C;                         // 0x008C
    int Speed1;                           // 0x0090
    int field_94;                         // 0x0094
    
    // 0x0098 - Позиция и телепортация
    int deltaX;                           // 0x0098
    int deltaY;                           // 0x009C
    int field_A0;                         // 0x00A0
    int teleportX;                        // 0x00A4
    int teleportY;                        // 0x00A8
    int teleportZ;                        // 0x00AC
    int field_B0;                         // 0x00B0
};

#pragma pack(pop)


// ============================================================================
// ФУНКЦИИ GAMEOBJECT (адреса из gta2.exe.map)
// Всего: 60 функций
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif
// Адрес: 0x00412900 - GameObject__GetVehicle
Car* GameObject__GetVehicle(GameObject* obj);

// Адрес: 0x0041B080 - GameObject__sub_41B080
void GameObject__sub_41B080(GameObject* obj);

// Адрес: 0x00433880 - GameObject__sub_433880
void GameObject__sub_433880(GameObject* obj);

// Адрес: 0x004338D0 - GameObject__GetSpriteS1
SpriteS1* GameObject__GetSpriteS1(GameObject* obj);

// Адрес: 0x004338E0 - GameObject__SetPed
void GameObject__SetPed(GameObject* obj, Ped* ped);

// Адрес: 0x004338F0 - GameObject__sub_4338F0
void GameObject__sub_4338F0(GameObject* obj);

// Адрес: 0x00433900 - GameObject__SetCar
void GameObject__SetCar(GameObject* obj, Car* car);

// Адрес: 0x00433910 - GameObject__set_ped_state_1
void GameObject__set_ped_state_1(GameObject* obj);

// Адрес: 0x00433920 - GameObject__SetSpeed
void GameObject__SetSpeed(GameObject* obj, float speed);

// Адрес: 0x00433930 - GameObject__sub_433930
void GameObject__sub_433930(GameObject* obj);

// Адрес: 0x00433940 - GameObject__sub_433940
void GameObject__sub_433940(GameObject* obj);

// Адрес: 0x00433970 - GameObject__sub_433970
void GameObject__sub_433970(GameObject* obj);

// Адрес: 0x004339C0 - GameObject__GetX
float GameObject__GetX(GameObject* obj);

// Адрес: 0x004339E0 - GameObject__GetY
float GameObject__GetY(GameObject* obj);

// Адрес: 0x00433A00 - GameObject__GetZ
float GameObject__GetZ(GameObject* obj);

// Адрес: 0x00433A20 - GameObject__sub_433A20
void GameObject__sub_433A20(GameObject* obj);

// Адрес: 0x00433A30 - GameObject__SetRotation
void GameObject__SetRotation(GameObject* obj, float rotation);

// Адрес: 0x00433A40 - GameObject__get_rotation
float GameObject__get_rotation(GameObject* obj);

// Адрес: 0x00433A50 - GameObject__sub_433A50
void GameObject__sub_433A50(GameObject* obj);

// Адрес: 0x00433A60 - GameObject__sub_433A60
void GameObject__sub_433A60(GameObject* obj);

// Адрес: 0x00433A70 - GameObject__sub_433A70
void GameObject__sub_433A70(GameObject* obj);

// Адрес: 0x00433A80 - GameObject__sub_433A80
void GameObject__sub_433A80(GameObject* obj);

// Адрес: 0x00433A90 - GameObject__sub_433A90
void GameObject__sub_433A90(GameObject* obj);

// Адрес: 0x00491DE0 - GameObject__sub_491DE0
void GameObject__sub_491DE0(GameObject* obj);

// Адрес: 0x00491E00 - GameObject__sub_491E00
void GameObject__sub_491E00(GameObject* obj);

// Адрес: 0x00491E40 - GameObject__sub_491E40
void GameObject__sub_491E40(GameObject* obj);

// Адрес: 0x00491E60 - GameObject__sub_491E60
void GameObject__sub_491E60(GameObject* obj);

// Адрес: 0x00491EA0 - GameObject__sub_491EA0
void GameObject__sub_491EA0(GameObject* obj);

// Адрес: 0x00491EC0 - GameObject__sub_491EC0
void GameObject__sub_491EC0(GameObject* obj);

// Адрес: 0x00491FA0 - GameObject__sub_491FA0
void GameObject__sub_491FA0(GameObject* obj);

#ifdef __cplusplus
}
#endif

