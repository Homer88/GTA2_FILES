#include "gta2/entities.h"
#include <stddef.h>

// ============================================================================
// Ped Constructor - Address: 0x49E70
// Size: 0x110 bytes of code (from MAP)
// ============================================================================
void Ped__Ped(struct Ped* self) {
    // Constructor implementation from ASM analysis
    // Initializes all fields to default values
    self->Next = NULL;
    self->Previous = NULL;
    self->ObjectID = -1;
    self->CarID = -1;
    
    self->PositionX = 0.0f;
    self->PositionY = 0.0f;
    self->VelocityX = 0.0f;
    self->VelocityY = 0.0f;
    self->Direction = 0.0f;
    self->State = PED_STATE_IDLE;
    self->Objective = PED_OBJ_NONE;
    self->SubState = 0;
    self->MovementFlags = 0;
    self->Reserved1 = 0;
    
    self->Health = 100;
    self->MaxHealth = 100;
    self->Armour = 0;
    self->WantedLevel = 0;
    self->Occupation = 0;
    self->SearchType = 0;
    self->Money = 0;
    self->Flags = 0;
    
    self->CurrentCar = NULL;
    self->TargetDoor = NULL;
    self->DriverPed = NULL;
    self->PassengerPed = NULL;
    self->SeatIndex = 0;
    self->DoorInteractionState = 0;
    self->Reserved2 = 0;
    self->EnterExitTimer = 0.0f;
    
    self->Weapon = NULL;
    self->TargetPed = NULL;
    self->Attacker = NULL;
    self->AimDirection = 0.0f;
    self->WeaponReady = 0;
    self->AttackFlags = 0;
    self->ReloadState = 0;
    self->Reserved3 = 0;
    self->ShootTimer = 0;
    self->ReloadTimer = 0;
    
    self->Group = NULL;
    self->Leader = NULL;
    self->FollowTarget = NULL;
    self->FollowDistance = 0.0f;
    self->GroupRole = 0;
    self->AIFlags = 0;
    self->Reserved4 = 0;
    self->ObjectiveTimer = 0;
    self->WaitTimer = 0;
    
    self->CurrentAnimation = 0;
    self->AnimationFrame = 0;
    self->AnimationState = 0;
    self->Visibility = 1;
    self->ColorScheme = 0;
    self->SpecialFlags = 0;
    self->SpriteData = NULL;
    self->SpriteIndex = 0;
}

// ============================================================================
// Ped Destructor - Address: 0x44660
// Size: 0x50 bytes of code (from MAP)
// ============================================================================
void Ped__Ped_des(struct Ped* self) {
    // Destructor implementation from ASM analysis
    // Cleans up resources
    if (self) {
        self->Weapon = NULL;
        self->TargetPed = NULL;
        self->Attacker = NULL;
        self->Group = NULL;
        self->Leader = NULL;
        self->FollowTarget = NULL;
        self->SpriteData = NULL;
    }
}

// ============================================================================
// Passenger Constructor - Address: 0x42FE90
// Size: 7 bytes of code (from MAP)
// ============================================================================
void Passenger__Passenger(struct Passenger* self) {
    self->Next = NULL;
    self->PedPtr = NULL;
    self->State = 0;
    self->Padding[0] = 0;
    self->Padding[1] = 0;
    self->Padding[2] = 0;
}

// ============================================================================
// Passenger Destructor - Address: 0x42FEA0
// Size: 7 bytes of code (from MAP)
// ============================================================================
void Passenger__Passenger_des(struct Passenger* self) {
    if (self) {
        self->Next = NULL;
        self->PedPtr = NULL;
        self->State = 0;
    }
}

// ============================================================================
// Ped Group Create - Address: 0x4F350
// ============================================================================
void Ped__PedGroupCreate(struct PedGroup* group, struct Ped* leader) {
    group->Leader = leader;
    group->MemberCount = 0;
    group->Formation = 0;
    group->Reserved = 0;
    for (int i = 0; i < 4; i++) {
        group->Members[i] = NULL;
    }
}

// ============================================================================
// Ped Group Change Leader - Address: 0x44490
// ============================================================================
void Ped__PedGroupChangeLeader(struct PedGroup* group, struct Ped* newLeader) {
    if (group && newLeader) {
        group->Leader = newLeader;
    }
}
