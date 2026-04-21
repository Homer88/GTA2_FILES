// ============================================================================
// GTA2 Reverse Engineering - C++ обёртки для IDA Pro
// Файл: gta2.exe.cpp
// Описание: C++ обёртки над C структурами (без классов, только структуры)
// Архитектура: x86 (32-бит), calling convention: __stdcall
// ============================================================================
//
// ВАЖНО: Используются структуры вместо классов для совместимости с C
// Все функции являются свободными функциями, принимающими указатель this
// ============================================================================

#include "gta2.exe.h"

// ============================================================================
// S81 (PublicTransport) - C++ обёртки для общественного транспорта
// ============================================================================

namespace GTA2 {

// ----------------------------------------------------------------------------
// PublicTransport::Init()
// Адрес: 0x004AF640
// old_name: sub_004af640
// ----------------------------------------------------------------------------
void PublicTransport_Init_Wrapper(PublicTransport* thiz) {
    // Вызов C функции
    PublicTransport_Init(thiz);
}

// ----------------------------------------------------------------------------
// PublicTransport::Update()
// Адрес: 0x004AF700
// old_name: sub_004af700
// ----------------------------------------------------------------------------
void PublicTransport_Update_Wrapper(PublicTransport* thiz) {
    PublicTransport_Update(thiz);
}

// ----------------------------------------------------------------------------
// PublicTransport::SetRoute()
// Адрес: 0x004AF8A0
// old_name: sub_004af8a0
// ----------------------------------------------------------------------------
void PublicTransport_SetRoute_Wrapper(PublicTransport* thiz, RouteNode* route, int nodeCount) {
    PublicTransport_SetRoute(thiz, route, nodeCount);
}

// ----------------------------------------------------------------------------
// PublicTransport::NextStop()
// Адрес: 0x004AF9C0
// old_name: sub_004af9c0
// ----------------------------------------------------------------------------
void PublicTransport_NextStop_Wrapper(PublicTransport* thiz) {
    PublicTransport_NextStop(thiz);
}

// ----------------------------------------------------------------------------
// PublicTransport::IsThisBus()
// Адрес: 0x004AFB20
// old_name: sub_004afb20
// ----------------------------------------------------------------------------
bool PublicTransport_IsThisBus_Wrapper(PublicTransport* thiz, Car* car) {
    return PublicTransport_IsThisBus(thiz, car) != 0;
}

// ----------------------------------------------------------------------------
// PublicTransport::FindCarField()
// Адрес: 0x004B1B40
// old_name: sub_004b1b40
// ----------------------------------------------------------------------------
S3* PublicTransport_FindCarField_Wrapper(PublicTransport* thiz, Car* car) {
    return PublicTransport_FindCarField(thiz, car);
}

// ----------------------------------------------------------------------------
// PublicTransport::ProcessCarInteraction()
// Адрес: 0x004B0D70
// old_name: sub_004b0d70
// ----------------------------------------------------------------------------
void PublicTransport_ProcessCarInteraction_Wrapper(PublicTransport* thiz, Car* car) {
    PublicTransport_ProcessCarInteraction(thiz, car);
}

// ----------------------------------------------------------------------------
// PublicTransport::HasReachedBusSkipLimit()
// Адрес: 0x004AFC80
// old_name: sub_004afc80
// ----------------------------------------------------------------------------
bool PublicTransport_HasReachedBusSkipLimit_Wrapper(PublicTransport* thiz) {
    return PublicTransport_HasReachedBusSkipLimit(thiz) != 0;
}

// ============================================================================
// BaseCar - C++ обёртки для базового класса автомобиля
// ============================================================================

// ----------------------------------------------------------------------------
// BaseCar::Init()
// Адрес: 0x004E5A10
// old_name: sub_004e5a10
// ----------------------------------------------------------------------------
void BaseCar_Init_Wrapper(BaseCar* thiz) {
    BaseCar_Init(thiz);
}

// ----------------------------------------------------------------------------
// BaseCar::UpdatePhysics()
// Адрес: 0x004E5B30
// old_name: sub_004e5b30
// ----------------------------------------------------------------------------
void BaseCar_UpdatePhysics_Wrapper(BaseCar* thiz) {
    BaseCar_UpdatePhysics(thiz);
}

// ----------------------------------------------------------------------------
// BaseCar::ApplyForce()
// Адрес: 0x004E5C50
// old_name: sub_004e5c50
// ----------------------------------------------------------------------------
void BaseCar_ApplyForce_Wrapper(BaseCar* thiz, f32 forceX, f32 forceY) {
    BaseCar_ApplyForce(thiz, forceX, forceY);
}

// ----------------------------------------------------------------------------
// BaseCar::SetSpeed()
// Адрес: 0x004E5D70
// old_name: sub_004e5d70
// ----------------------------------------------------------------------------
void BaseCar_SetSpeed_Wrapper(BaseCar* thiz, f32 speed) {
    BaseCar_SetSpeed(thiz, speed);
}

// ----------------------------------------------------------------------------
// BaseCar::Turn()
// Адрес: 0x004E5E90
// old_name: sub_004e5e90
// ----------------------------------------------------------------------------
void BaseCar_Turn_Wrapper(BaseCar* thiz, f32 angle) {
    BaseCar_Turn(thiz, angle);
}

// ----------------------------------------------------------------------------
// BaseCar::CheckCollision()
// Адрес: 0x004E5FB0
// old_name: sub_004e5fb0
// ----------------------------------------------------------------------------
bool BaseCar_CheckCollision_Wrapper(BaseCar* thiz) {
    return BaseCar_CheckCollision(thiz) != 0;
}

} // namespace GTA2

// ============================================================================
// Пример использования (для документации):
// ============================================================================
/*
#include "gta2.exe.cpp"

void example() {
    using namespace GTA2;
    
    // Создание общественного транспорта
    PublicTransport bus = {};
    
    // Инициализация
    PublicTransport_Init_Wrapper(&bus);
    
    // Установка маршрута
    RouteNode route[5] = {};
    PublicTransport_SetRoute_Wrapper(&bus, route, 5);
    
    // Обновление в игровом цикле
    PublicTransport_Update_Wrapper(&bus);
    
    // Проверка типа транспорта
    Car myCar = {};
    if (PublicTransport_IsThisBus_Wrapper(&bus, &myCar)) {
        // Это автобус
    }
    
    // Базовая физика
    BaseCar* base = &bus.Base;
    BaseCar_Init_Wrapper(base);
    BaseCar_ApplyForce_Wrapper(base, 10.0f, 5.0f);
    BaseCar_UpdatePhysics_Wrapper(base);
}
*/

// ============================================================================
// КОНЕЦ ФАЙЛА
// ============================================================================
