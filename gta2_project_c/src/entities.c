/*
 * GTA 2 Entity Constructors and Destructors
 * Based on gta2.exe.map function addresses
 */

#include "../include/gta2/entities.h"
#include <string.h>

/* ============================================================================
 * Passenger Constructor
 * MAP: Passenger__Passenger = 0x42FE90
 * Size: 0x10 bytes
 * ============================================================================ */
void Passenger__Passenger(struct Passenger* this) {
    if (!this) return;
    
    this->PedPtr = NULL;
    this->SeatIndex = -1;
    this->StateFlags = 0;
    this->ActionTimer = 0;
    this->ActionState = 0;
    memset(this->Reserved, 0, sizeof(this->Reserved));
}

/* ============================================================================
 * Passenger Destructor  
 * MAP: Passenger__Passenger_des = 0x42FEA0
 * ============================================================================ */
void Passenger__Passenger_des(struct Passenger* this) {
    if (!this) return;
    /* Destructor body - cleanup if needed */
    /* No dynamic allocation in Passenger structure itself */
}

/* ============================================================================
 * CarDoor Constructor
 * MAP: CarDoor__sub_41F680 = 0x41F680
 * ============================================================================ */
void CarDoor__CarDoor(struct CarDoor* this) {
    if (!this) return;
    
    this->AnimationFrame = 0;
    this->DoorState = 0;  /* Closed */
    this->PedInDoor = NULL;
    this->DoorTimer = 0;
    this->AnimationFlags = 0;
    this->TotalFrames = 0;
    this->Padding = 0;
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
