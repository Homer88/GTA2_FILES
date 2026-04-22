/**
 * @file car_physics_world.cpp
 * @brief C++-реализация физического мира автомобилей GTA 2.
 * 
 * Размер: 0x8F74 (36724 байт)
 * Старое имя: S10
 */

#include "entities/car_physics_world.h"
#include <cstring>

CarPhysicsWorld* gCarPhysicsWorld = nullptr;

extern "C" {

CarPhysicsWorld* CarPhysicsWorld__ctor(CarPhysicsWorld* this) {
    if (!this) return nullptr;
    std::memset(this->data, 0, sizeof(this->data));
    return this;
}

void CarPhysicsWorld__dtor(CarPhysicsWorld* this) {
    (void)this;
}

} /* extern "C" */
