/*
 * GTA 2 Entity Constructors and Destructors
 * Based on gta2.exe.map function addresses
 */

#include "../include/gta2/entities.h"
#include <string.h>

/* ============================================================================
 * Passenger Constructor
 * MAP: Passenger__Passenger = 0x42FE90
 * Constructor size: 7 bytes - simple initialization
 * Struct size: 0x08 bytes (linked list node)
 * 
 * From IDA: Initializes linked list pointers
 * ============================================================================ */
void Passenger__Passenger(struct Passenger* this) {
    if (!this) return;
    
    /* Initialize as single-element circular list or NULL */
    this->Next = NULL;
    this->Prev = NULL;
}

/* ============================================================================
 * Passenger Destructor  
 * MAP: Passenger__Passenger_des = 0x42FEA0
 * Size: 7 bytes - minimal cleanup
 * ============================================================================ */
void Passenger__Passenger_des(struct Passenger* this) {
    if (!this) return;
    /* Destructor body - no dynamic allocation in Passenger */
}

/* ============================================================================
 * CarDoor Constructor
 * MAP: CarDoor__CarDoor = 0x421310 (constructor, 0x20 bytes)
 *       CarDoor__CarDoor_Des = 0x421330 (destructor, 8 bytes)
 * Struct size: 0x10 bytes
 * 
 * From IDA gta2.exe.h:
 *   - AnimationFrame[4]: byte array for animation state
 *   - doorState: int for door state machine
 *   - PedInDoor: pointer to ped
 *   - field_C + 3 reserved bytes
 * ============================================================================ */
void CarDoor__CarDoor(struct CarDoor* this) {
    if (!this) return;
    
    /* Initialize animation frame array */
    this->AnimationFrame[0] = 0;
    this->AnimationFrame[1] = 0;
    this->AnimationFrame[2] = 0;
    this->AnimationFrame[3] = 0;
    
    /* Initialize door state (0 = closed) */
    this->DoorState = 0;
    
    /* No ped in door initially */
    this->PedInDoor = NULL;
    
    /* Clear remaining fields */
    this->Field_C = 0;
    this->Reserved1 = 0;
    this->Reserved2 = 0;
    this->Reserved3 = 0;
}

/* ============================================================================
 * Car Constructor (stub - needs ASM analysis for full implementation)
 * MAP: Car__sub_403800 = 0x403800
 * ============================================================================ */
void Car__Car(struct Car* this) {
    if (!this) return;
    
    /* Initialize pointers to NULL */
    this->Turret = NULL;
    this->Passengers = NULL;
    this->PreviousCar = NULL;
    this->Sprite = NULL;
    this->Driver = NULL;
    this->ControlledByPlayer = NULL;
    this->Engine = NULL;
    this->ModelData = NULL;
    this->pVehicleStats = NULL;
    this->Attacker = NULL;
    
    /* Initialize scalar fields */
    this->LightsState = 0;
    this->PhysicsFlags = 0;
    this->ObjectID = -1;
    this->Health = 100;  /* Full health */
    this->VisibilityTimer = 0;
    this->StatusFlags = 0;
    this->Reserved1 = 0;
    this->SpecialTimer = 0;
    this->Reserved2 = 0;
    this->Type = CAR_TYPE_CIVILIAN;
    this->State = 0;  /* Inactive */
    this->FireFlags = 0;
    this->SirenFlags = 0;
    this->SirenTimer = 0;
    this->HornTimer = 0;
    this->DamageSource = 0;
    this->DamageCooldown = 0;
    this->OwnerPlayerId = 0;
    this->Reserved3 = 0;
    this->DoorLockState = 2;  /* Unlocked */
    this->EngineStatus = 0;   /* Off */
    this->TrafficType = TRAFFIC_CAR_NORMAL;
    this->SirenState = 0;
    this->SirenPhase = 0;
    this->Reserved4 = 0;
    this->HornActive = 0;
    this->Reserved5 = 0;
    this->FireDuration = 0;
    memset(this->Reserved6, 0, sizeof(this->Reserved6));
    this->ExplosionTimer = 0;
    this->UpgradeSoundID = 0;
    this->Reserved7 = 0;
    
    /* Initialize door array */
    for (int i = 0; i < 4; i++) {
        CarDoor__CarDoor(&this->Doors[i]);
    }
    
    /* Initialize bounding box */
    this->BoundingBox.MinX = 0.0f;
    this->BoundingBox.MinY = 0.0f;
    this->BoundingBox.MaxX = 0.0f;
    this->BoundingBox.MaxY = 0.0f;
    
    /* Initialize collision info */
    memset(&this->LastCollision, 0, sizeof(this->LastCollision));
}

/* ============================================================================
 * Turret Constructor (stub)
 * ============================================================================ */
void Turret__Turret(struct Turret* this) {
    if (!this) return;
    
    this->TargetPtr = NULL;
    this->Counter = 0;
    this->State = 0;
    this->Padding = 0;
}
