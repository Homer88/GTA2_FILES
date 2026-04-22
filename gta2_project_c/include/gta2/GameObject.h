/**
 * @file GameObject.h
 * @brief Базовая структура для всех объектов мира в GTA 2
 * 
 * Адрес структуры в дампе: line 3765 в gta2.exe.h
 * Размер: 0x40 (64 байта) - требует проверки по бинарнику
 * Основано на: gta2.exe/ida_pro/gta2.exe.h, gta2.exe.map
 * 
 * ВАЖНО: Это базовый класс для Ped, Car и других объектов
 */

#pragma once

#include <cstdint>

// Forward declarations
struct Ped;
struct Car;
struct SpriteS1;
struct Model;

#pragma pack(push, 1)

struct GameObject
{
    void* vtable;                       // 0x0000 - Указатель на таблицу виртуальных методов
    SpriteS1* SpriteS1;                 // 0x0004 - Спрайт объекта
    Model* Model;                       // 0x0008 - Модель объекта
    float X;                            // 0x000C - Позиция X
    float Y;                            // 0x0010 - Позиция Y
    float Z;                            // 0x0014 - Позиция Z
    float Rotation;                     // 0x0018 - Вращение
    int ID;                             // 0x001C - Идентификатор объекта
    int Flags;                          // 0x0020 - Флаги состояния
    int Type;                           // 0x0024 - Тип объекта (Ped, Car, etc.)
    Ped* pPed;                          // 0x0028 - Связанный Ped (если есть)
    Car* pCar;                          // 0x002C - Связанный Car (если есть)
    int field_30;                       // 0x0030
    int field_34;                       // 0x0034
    int field_38;                       // 0x0038
    int field_3C;                       // 0x003C
};

#pragma pack(pop)

static_assert(sizeof(GameObject) == 0x40, "GameObject structure size mismatch");

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

#endif // GAMEOBJECT_H
