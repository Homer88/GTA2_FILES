/**
 * @file train_component.cpp
 * @brief C++ wrappers for TrainComponent (S83) logic.
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
void S83_Init(S83_TrainComponent* self);
void S83_Update(S83_TrainComponent* self);
void S83_SetTrainLength(S83_TrainComponent* self, int length);
int S83_GetTrainLength(S83_TrainComponent* self);
void S83_LinkToEngine(S83_TrainComponent* self, S81_PublicTransport* engine);
S81_PublicTransport* S83_GetLinkedEngine(S83_TrainComponent* self);

#ifdef __cplusplus
}
#endif

namespace GTA2 {
namespace Vehicles {

/**
 * @brief Initialize TrainComponent structure
 * old_name: FUN_00420000 (S83 constructor)
 */
void TrainComponent_Init(S83_TrainComponent* self) {
    S83_Init(self);
}

/**
 * @brief Update TrainComponent state
 * old_name: FUN_00420100 (S83 update)
 */
void TrainComponent_Update(S83_TrainComponent* self) {
    S83_Update(self);
}

/**
 * @brief Set train length (number of cars)
 * old_name: FUN_00420200
 * @param self Pointer to TrainComponent structure
 * @param length Number of cars in the train
 */
void TrainComponent_SetTrainLength(S83_TrainComponent* self, int length) {
    S83_SetTrainLength(self, length);
}

/**
 * @brief Get train length
 * old_name: FUN_00420300
 * @return Number of cars in the train
 */
int TrainComponent_GetTrainLength(S83_TrainComponent* self) {
    return S83_GetTrainLength(self);
}

/**
 * @brief Link train component to engine (PublicTransport)
 * old_name: FUN_00420400
 * @param self Pointer to TrainComponent structure
 * @param engine Pointer to engine (PublicTransport)
 */
void TrainComponent_LinkToEngine(S83_TrainComponent* self, S81_PublicTransport* engine) {
    S83_LinkToEngine(self, engine);
}

/**
 * @brief Get linked engine
 * old_name: FUN_00420500
 * @return Pointer to linked engine (PublicTransport), or NULL if not linked
 */
S81_PublicTransport* TrainComponent_GetLinkedEngine(S83_TrainComponent* self) {
    return S83_GetLinkedEngine(self);
}

} // namespace Vehicles
} // namespace GTA2
