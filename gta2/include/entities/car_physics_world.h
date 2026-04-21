/**
 * @file car_physics_world.h
 * @brief Физический мир автомобилей GTA 2.
 * 
 * Адрес глобальной переменной: gCarPhysicsWorld (требует уточнения)
 * Размер структуры: 0x8F74 (36724 байт)
 * Конструктор: 0x00??? (S10::S10, требует уточнения)
 * 
 * Старое имя: S10
 * Новое имя: CarPhysicsWorld
 */

#ifndef GTA2_CAR_PHYSICS_WORLD_H
#define GTA2_CAR_PHYSICS_WORLD_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern CarPhysicsWorld* gCarPhysicsWorld;

typedef struct CarPhysicsWorld {
    /* 0x0000 */ uint8_t data[0x8F74];   // Внутренние данные физического мира
} CarPhysicsWorld;

#ifdef __cplusplus
static_assert(sizeof(CarPhysicsWorld) == 0x8F74, "CarPhysicsWorld size must be 0x8F74");
#endif

CarPhysicsWorld* CarPhysicsWorld__ctor(CarPhysicsWorld* this);
void CarPhysicsWorld__dtor(CarPhysicsWorld* this);

#ifdef __cplusplus
}
#endif

#endif // GTA2_CAR_PHYSICS_WORLD_H
