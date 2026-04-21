/**
 * @file public_transport.cpp
 * @brief C++ wrappers for PublicTransport (S81) logic.
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
void S81_Init(S81_PublicTransport* self, VehicleType type);
void S81_Update(S81_PublicTransport* self);
void S81_SetRoute(S81_PublicTransport* self, RouteNode* nodes, int count);
void S81_AddRouteNode(S81_PublicTransport* self, float x, float y, int waitTime);
void S81_GetNextWaypoint(S81_PublicTransport* self, float* outX, float* outY);
int S81_IsAtWaypoint(S81_PublicTransport* self);
void S81_SetState(S81_PublicTransport* self, PublicTransportState state);
PublicTransportState S81_GetState(S81_PublicTransport* self);

#ifdef __cplusplus
}
#endif

namespace GTA2 {
namespace Vehicles {

/**
 * @brief Initialize PublicTransport structure
 * old_name: FUN_00410000 (S81 constructor)
 */
void PublicTransport_Init(S81_PublicTransport* self, VehicleType type) {
    S81_Init(self, type);
}

/**
 * @brief Update PublicTransport state and route logic
 * old_name: FUN_00410100 (S81 update)
 */
void PublicTransport_Update(S81_PublicTransport* self) {
    S81_Update(self);
}

/**
 * @brief Set route for PublicTransport
 * old_name: FUN_00410200
 * @param self Pointer to PublicTransport structure
 * @param nodes Array of route nodes
 * @param count Number of nodes in the route
 */
void PublicTransport_SetRoute(S81_PublicTransport* self, RouteNode* nodes, int count) {
    S81_SetRoute(self, nodes, count);
}

/**
 * @brief Add a route node to PublicTransport
 * old_name: FUN_00410300
 * @param self Pointer to PublicTransport structure
 * @param x X coordinate of the node
 * @param y Y coordinate of the node
 * @param waitTime Wait time at this node (in game ticks)
 */
void PublicTransport_AddRouteNode(S81_PublicTransport* self, float x, float y, int waitTime) {
    S81_AddRouteNode(self, x, y, waitTime);
}

/**
 * @brief Get next waypoint coordinates
 * old_name: FUN_00410400
 * @param self Pointer to PublicTransport structure
 * @param outX Output X coordinate
 * @param outY Output Y coordinate
 */
void PublicTransport_GetNextWaypoint(S81_PublicTransport* self, float* outX, float* outY) {
    S81_GetNextWaypoint(self, outX, outY);
}

/**
 * @brief Check if PublicTransport is at waypoint
 * old_name: FUN_00410500
 * @return 1 if at waypoint, 0 otherwise
 */
int PublicTransport_IsAtWaypoint(S81_PublicTransport* self) {
    return S81_IsAtWaypoint(self);
}

/**
 * @brief Set PublicTransport state
 * old_name: FUN_00410600
 */
void PublicTransport_SetState(S81_PublicTransport* self, PublicTransportState state) {
    S81_SetState(self, state);
}

/**
 * @brief Get current PublicTransport state
 * old_name: FUN_00410700
 */
PublicTransportState PublicTransport_GetState(S81_PublicTransport* self) {
    return S81_GetState(self);
}

} // namespace Vehicles
} // namespace GTA2
