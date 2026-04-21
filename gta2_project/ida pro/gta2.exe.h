#ifndef GTA2_EXE_H
#define GTA2_EXE_H

/**
 * @file gta2.exe.h
 * @brief Заголовочный файл для импорта в IDA Pro
 * 
 * Содержит структуры и прототипы функций с комментариями адресов.
 * Все имена функций имеют формат: new_name (old_name: sub_XXXXXX)
 * 
 * Инструкция по использованию:
 * 1. Скопируйте структуры в IDA через File -> Load File -> Parse C Header File
 * 2. Используйте скрипт IDAPython (см. rename_functions.py) для переименования
 * 3. Или вручную переименуйте функции по адресам
 */

#include <stdint.h>
#include <stdbool.h>

// ============================================================================
// TYPED STRUCTURES (GTA 2 Vehicle Hierarchy)
// Names aligned with IDA Pro logic (no 'S' prefix for clean usage)
// ============================================================================

// Forward declarations
typedef struct BaseCar BaseCar;
typedef struct PublicTransport PublicTransport;
typedef struct TrainComponent TrainComponent;
typedef struct RouteNode RouteNode;

// ----------------------------------------------------------------------------
// Enums
// ----------------------------------------------------------------------------
typedef enum VehicleType {
    VEHICLE_CAR = 0,
    VEHICLE_PUBLIC_TRANSPORT = 1,
    VEHICLE_TRAIN = 2,
    VEHICLE_BOAT = 3,
    VEHICLE_HELI = 4
} VehicleType;

typedef enum PublicTransportState {
    PT_STATE_IDLE = 0,
    PT_STATE_MOVING_TO_STOP = 1,
    PT_STATE_WAITING = 2,
    PT_STATE_DEPARTING = 3
} PublicTransportState;

typedef enum RouteFlags {
    ROUTE_FLAG_LOOP = 0x1,
    ROUTE_FLAG_REVERSE = 0x2
} RouteFlags;

// ----------------------------------------------------------------------------
// Data Structures
// ----------------------------------------------------------------------------

/**
 * Route Node Structure
 * Size: 0x0C (12 bytes)
 * Used by: PublicTransport
 */
typedef struct RouteNode {
    float x;                // 0x00: World X coordinate
    float y;                // 0x04: World Y coordinate
    uint32_t flags;         // 0x08: Stop type / Wait time / Flags
    // IDA Ref: sub_XXXXXX (Node processing logic)
} RouteNode;

/**
 * Base Car Class (Parent)
 * Size: 0x68 (104 bytes)
 * Address: 0x[Base Address]
 * Contains: Physics, Rendering, Basic State
 */
struct BaseCar {
    void* vtable;           // 0x00: Virtual Table Pointer
    int16_t sprite_id;      // 0x04: Sprite/Model ID
    int16_t status;         // 0x06: Status flags (damaged, on fire, etc.)
    float x;                // 0x08: Position X
    float y;                // 0x0C: Position Y
    float z;                // 0x10: Position Z (elevation)
    float angle;            // 0x14: Heading angle
    float speed;            // 0x18: Current speed
    float max_speed;        // 0x1C: Max speed capability
    float acceleration;     // 0x20: Acceleration rate
    float mass;             // 0x24: Mass for collision physics
    float friction;         // 0x28: Friction coefficient
    // ... padding up to 0x68 based on actual dump ...
    uint8_t padding[0x40];  // 0x2C - 0x67: Reserved / Other physics vars
    
    // IDA Ref: sub_4B5500 (BaseCar Constructor/Destructor)
    // IDA Ref: sub_4B5620 (BaseCar Update Physics)
};

/**
 * Public Transport Class (Child of BaseCar)
 * Size: 0x7C (124 bytes) = 0x68 (Base) + 0x14 (Extra)
 * Address: 0x[Derived Address]
 * Contains: Route logic, Schedule, Stop handling
 */
struct PublicTransport {
    BaseCar base;           // 0x00: Inherited BaseCar data (0x68 bytes)
    
    // Extended fields (Public Transport specific)
    RouteNode* route_nodes; // 0x68: Pointer to array of RouteNodes
    int32_t node_count;     // 0x6C: Number of nodes in current route
    int32_t current_node;   // 0x70: Index of next target node
    PublicTransportState state; // 0x74: Current AI state (Idle, Moving, Waiting)
    int32_t wait_timer;     // 0x78: Timer for dwelling at stop
    uint32_t route_flags;   // 0x7C: Loop/Reverse flags (if fits, else padding)
    
    // Note: If size is strictly 0x7C, route_flags might be at 0x78 and wait_timer adjusted.
    // Adjust based on your specific memory dump alignment.
    
    // IDA Ref: sub_4A1000 (PublicTransport Constructor)
    // IDA Ref: sub_4A1150 (PublicTransport Update Route)
    // IDA Ref: sub_4A1340 (PublicTransport Find Nearest Stop)
};

/**
 * Train Component (Special Case)
 * Size: Varies (often linked list)
 * Contains: Link to engine/carriage, track logic
 */
struct TrainComponent {
    BaseCar base;           // 0x00: Inherited BaseCar data
    TrainComponent* next;   // 0x68: Pointer to next carriage/engine
    TrainComponent* prev;   // 0x6C: Pointer to previous carriage
    float track_offset;     // 0x70: Offset along the track spline
    int32_t train_id;       // 0x74: Unique train set ID
    // IDA Ref: sub_4C2000 (Train Link Logic)
};

// ============================================================================
// FUNCTION PROTOTYPES (C Interface)
// Comments contain placeholder 'sub_XXXXXX' - Replace with your IDA names!
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif

// --- BaseCar Methods (S82) ---
void BaseCar_Init(BaseCar* self, VehicleType type); 
// old_name: sub_4B5500 (Constructor)
// vars: this=a1, type=a2

void BaseCar_UpdatePhysics(BaseCar* self);
// old_name: sub_4B5620 (Physics Step)
// vars: this=a1, dt=a2(implied)

void BaseCar_ApplyForce(BaseCar* self, float fx, float fy);
// old_name: sub_4B5890 (Add Force Vector)

void BaseCar_SetSpeed(BaseCar* self, float speed);
// old_name: sub_4B5A10 (Set Velocity)

void BaseCar_Turn(BaseCar* self, float angle_delta);
// old_name: sub_4B5C40 (Steering Input)

bool BaseCar_CheckCollision(BaseCar* self, BaseCar* other);
// old_name: sub_4B6000 (Collision Check)

// --- PublicTransport Methods (S81) ---
void PublicTransport_Init(PublicTransport* self, RouteNode* nodes, int count);
// old_name: sub_4A1000 (PT Constructor)
// vars: this=a1, nodes=a2, count=a3

void PublicTransport_Update(PublicTransport* self);
// old_name: sub_4A1150 (PT AI Update)
// vars: this=a1

void PublicTransport_SetRoute(PublicTransport* self, RouteNode* nodes, int count);
// old_name: sub_4A1280 (Assign Route)

void PublicTransport_StopAtNode(PublicTransport* self);
// old_name: sub_4A1340 (Open Doors/Wait)

int PublicTransport_GetNextNodeIndex(PublicTransport* self);
// old_name: sub_4A1450 (Pathfinding Next)

void PublicTransport_Depart(PublicTransport* self);
// old_name: sub_4A1520 (Close Doors/Start)

// --- TrainComponent Methods (S83) ---
void TrainComponent_Init(TrainComponent* self, int is_engine);
// old_name: sub_4C2000 (TC Constructor)

void TrainComponent_Link(TrainComponent* self, TrainComponent* other);
// old_name: sub_4C2150 (Couple Cars)

void TrainComponent_UpdateChain(TrainComponent* head);
// old_name: sub_4C2280 (Update Whole Train)

void TrainComponent_Unlink(TrainComponent* self);
// old_name: sub_4C2450 (Uncouple Cars)

int TrainComponent_GetLength(TrainComponent* head);
// old_name: sub_4C2520 (Get Train Length)

#ifdef __cplusplus
}
#endif

#endif // GTA2_EXE_H
