/**
 * @file base_car.cpp
 * @brief C++ wrappers for BaseCar (S82) logic.
 * 
 * Uses structures instead of classes as per project requirements.
 * Wrappers allow easy integration with C++ code while keeping core logic in C.
 * 
 * Source: gta2.exe/ida pro/gta2.exe.c
 * Old function names preserved in comments for IDA Pro mapping.
 */

#include "entities/vehicle_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations of C implementations
void S82_Init(S82_BaseCar* self, VehicleType type);
void S82_UpdatePhysics(S82_BaseCar* self);
void S82_ApplyForce(S82_BaseCar* self, float forceX, float forceY);
void S82_SetSpeed(S82_BaseCar* self, float speed);
void S82_Turn(S82_BaseCar* self, float angle);
int S82_CheckCollision(S82_BaseCar* self);

#ifdef __cplusplus
}
#endif

namespace GTA2 {
namespace Vehicles {

/**
 * @brief Initialize BaseCar structure
 * old_name: FUN_004XXXX (S82 constructor)
 */
void BaseCar_Init(S82_BaseCar* self, VehicleType type) {
    S82_Init(self, type);
}

/**
 * @brief Update physics for BaseCar
 * old_name: FUN_004YYYY (S82 update)
 */
void BaseCar_UpdatePhysics(S82_BaseCar* self) {
    S82_UpdatePhysics(self);
}

/**
 * @brief Apply force to BaseCar
 * old_name: FUN_004ZZZZ
 * @param self Pointer to BaseCar structure
 * @param forceX Force on X axis
 * @param forceY Force on Y axis
 */
void BaseCar_ApplyForce(S82_BaseCar* self, float forceX, float forceY) {
    S82_ApplyForce(self, forceX, forceY);
}

/**
 * @brief Set speed for BaseCar
 * old_name: FUN_004AAAA
 */
void BaseCar_SetSpeed(S82_BaseCar* self, float speed) {
    S82_SetSpeed(self, speed);
}

/**
 * @brief Turn BaseCar by angle
 * old_name: FUN_004BBBB
 */
void BaseCar_Turn(S82_BaseCar* self, float angle) {
    S82_Turn(self, angle);
}

/**
 * @brief Check collision for BaseCar
 * old_name: FUN_004CCCC
 * @return 1 if collision detected, 0 otherwise
 */
int BaseCar_CheckCollision(S82_BaseCar* self) {
    return S82_CheckCollision(self);
}

} // namespace Vehicles
} // namespace GTA2
