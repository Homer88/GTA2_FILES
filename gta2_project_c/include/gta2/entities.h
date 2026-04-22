#ifndef GTA2_ENTITIES_H
#define GTA2_ENTITIES_H

#include "types.h"

// Forward declarations
struct Ped;
struct Player;
struct SpriteS1;
struct CarSystemManager;

// ============================================================================
// Turret structure (from MAP: Turret__Turret constructor exists)
// Size: 8 bytes (based on typical usage in Car structure)
// ============================================================================
struct Turret {
    void* TargetPtr;        // 0x0 - Pointer to target or flags
    u16 Counter;            // 0x4 - Counter/timer (value 45 = full)
    u8 State;               // 0x6 - Turret state
    u8 Padding;             // 0x7 - Alignment
};

// ============================================================================
// Passenger structure
// From MAP: Passenger__Passenger = 0x42FE90, Passenger__Passenger_des = 0x42FEA0
// Constructor size: 7 bytes code (0x42FEA0 - 0x42FE90) - very simple init
// Global: gPassenger at 0x5E5EE0 (pointer to Passenger list head)
// 
// From gta2.exe.h (IDA): Linked list structure for passenger management
// Size: 0x0C bytes (2 pointers + state)
// ============================================================================
struct Passenger {
    struct Passenger* Next;     // 0x0 - Next passenger in linked list
    struct Ped* PedPtr;         // 0x4 - Pointer to Ped in this passenger slot
    u8 State;                   // 0x8 - Passenger state (active/inactive)
    u8 Padding[3];              // 0x9 - Alignment
};
// static_assert(sizeof(struct Passenger) == 0x0C, "Passenger size mismatch");

// ============================================================================
// Ped Objective enum
// ============================================================================
enum PedObjective {
    PED_OBJ_NONE = 0,
    PED_OBJ_WANDER = 1,
    PED_OBJ_FOLLOW = 2,
    PED_OBJ_FLEE = 3,
    PED_OBJ_ATTACK = 4,
    PED_OBJ_ENTER_CAR = 5,
    PED_OBJ_EXIT_CAR = 6,
    PED_OBJ_DRIVE_CAR = 7,
    PED_OBJ_SHOOT = 8,
    PED_OBJ_RUN_TO = 9,
    PED_OBJ_WAIT = 10,
    PED_OBJ_DEAD = 11
};

// ============================================================================
// Ped State enum
// ============================================================================
enum PedState {
    PED_STATE_IDLE = 0,
    PED_STATE_WALK = 1,
    PED_STATE_RUN = 2,
    PED_STATE_SPRINT = 3,
    PED_STATE_CROUCH = 4,
    PED_STATE_JUMP = 5,
    PED_STATE_FALL = 6,
    PED_STATE_IN_CAR = 7,
    PED_STATE_ENTERING_CAR = 8,
    PED_STATE_EXITING_CAR = 9,
    PED_STATE_AIM = 10,
    PED_STATE_SHOOT = 11,
    PED_STATE_RELOAD = 12,
    PED_STATE_DEAD = 13,
    PED_STATE_DYING = 14,
    PED_STATE_STUNNED = 15
};

// ============================================================================
// Ped Group structure
// From MAP: Ped__PedGroupCreate, Ped__PedGroupChangeLeader
// ============================================================================
struct PedGroup {
    struct Ped* Leader;         // 0x0 - Group leader
    struct Ped* Members[4];     // 0x4 - Group members (max 4)
    u8 MemberCount;             // 0x14 - Number of members
    u8 Formation;               // 0x15 - Formation type
    u16 Reserved;               // 0x16 - Alignment
};

// ============================================================================
// Ped structure
// From MAP: 
//   Ped__Ped = 0x49E70 (constructor)
//   Ped__Ped_des = 0x44660 (destructor)
//   231+ methods including: SetSearchType, SetCarId, SetOccupation, 
//   GetPositionX/Y, EnterCarAsPassenger, GiveWeapon, etc.
// Global: gPed at 0x0EF794, gPed1 at 0x0E7DE0
// 
// CONFIRMED SIZE from constructor analysis:
//   Construct(this->Ped, 0x294, 200, Ped::Ped, Ped::Ped_des);
//   Size: 0x294 bytes (660 bytes)
//   NextPed field offset: 0xA5 (165 bytes) - from loop: pNextPed += 165
// ============================================================================
struct Ped {
    // === Block 1: Links and Identification (0x00 - 0x0F) ===
    struct Ped* Next;           // 0x0 - Next ped in linked list
    struct Ped* Previous;       // 0x4 - Previous ped in linked list
    s32 ObjectID;               // 0x8 - Unique object ID
    s32 CarID;                  // 0xC - Current car ID (if in vehicle)
    
    // === Block 2: Position and Movement (0x10 - 0x2F) ===
    f32 PositionX;              // 0x10 - World X coordinate
    f32 PositionY;              // 0x14 - World Y coordinate
    f32 VelocityX;              // 0x18 - Velocity X
    f32 VelocityY;              // 0x1C - Velocity Y
    f32 Direction;              // 0x20 - Facing direction (radians)
    enum PedState State;        // 0x24 - Current state
    enum PedObjective Objective;// 0x28 - Current objective
    u8 SubState;                // 0x2C - Sub-state for animations
    u8 MovementFlags;           // 0x2D - Movement flags
    u16 Reserved1;              // 0x2E - Alignment
    
    // === Block 3: Health and Stats (0x30 - 0x4F) ===
    s16 Health;                 // 0x30 - Health (0-100)
    s16 MaxHealth;              // 0x32 - Maximum health
    u8 Armour;                  // 0x34 - Armour level
    u8 WantedLevel;             // 0x35 - Police wanted level (0-6)
    u8 Occupation;              // 0x36 - Occupation type (civilian, cop, gang)
    u8 SearchType;              // 0x37 - Search behavior type
    s32 Money;                  // 0x38 - Money value
    u32 Flags;                  // 0x3C - General flags (bitmask)
    
    // === Block 4: Vehicle Interaction (0x40 - 0x5F) ===
    struct Car* CurrentCar;     // 0x40 - Pointer to current car
    struct CarDoor* TargetDoor; // 0x44 - Target door for entering/exiting
    struct Ped* DriverPed;      // 0x48 - Driver if passenger
    struct Ped* PassengerPed;   // 0x4C - Passenger if driver
    u8 SeatIndex;               // 0x50 - Seat index in car
    u8 DoorInteractionState;    // 0x51 - Door interaction state
    u16 Reserved2;              // 0x52 - Alignment
    f32 EnterExitTimer;         // 0x54 - Timer for enter/exit animation
    
    // === Block 5: Combat and Weapons (0x58 - 0x77) ===
    void* Weapon;               // 0x58 - Current weapon pointer
    struct Ped* TargetPed;      // 0x5C - Target ped for combat
    struct Ped* Attacker;       // 0x60 - Last attacker
    f32 AimDirection;           // 0x64 - Aim direction
    u8 WeaponReady;             // 0x68 - Weapon ready flag
    u8 AttackFlags;             // 0x69 - Attack flags
    u8 ReloadState;             // 0x6A - Reload state
    u8 Reserved3;               // 0x6B - Alignment
    s32 ShootTimer;             // 0x6C - Shooting cooldown timer
    s32 ReloadTimer;            // 0x70 - Reload timer
    
    // === Block 6: Group AI (0x74 - 0x9F) ===
    struct PedGroup* Group;     // 0x74 - Group membership
    struct Ped* Leader;         // 0x78 - Leader if in group
    struct Ped* FollowTarget;   // 0x7C - Ped to follow
    f32 FollowDistance;         // 0x80 - Distance to maintain when following
    u8 GroupRole;               // 0x84 - Role in group (leader/member)
    u8 AIFlags;                 // 0x85 - AI behavior flags
    u16 Reserved4;              // 0x86 - Alignment
    s32 ObjectiveTimer;         // 0x88 - Timer for current objective
    s32 WaitTimer;              // 0x8C - Wait timer
    u8 Reserved5[20];           // 0x90 - Padding to reach NextPed at 0xA5
    
    // === CRITICAL: NextPed field at offset 0xA5 (165 bytes) ===
    // Confirmed from constructor loop: pNextPed += 165
    struct Ped* NextPed;        // 0xA5 - Next ped in manager's array
    
    // === Remaining fields (0xA9 - 0x293) - TO BE ANALYZED FROM ASM ===
    // Total remaining: 0x294 - 0xA9 = 0x1EB (491 bytes)
    u8 UnknownData[491];        // 0xA9-0x293 - Placeholder for unanalyzed fields
};
static_assert(sizeof(struct Ped) == 0x294, "Ped size must be 0x294 bytes");
static_assert(offsetof(struct Ped, NextPed) == 0xA5, "NextPed must be at offset 0xA5");

// ============================================================================
// CarDoor structure  
// From MAP: 
//   CarDoor__CarDoor = 0x421310 (constructor, 0x20 bytes code from IDA)
//   CarDoor__CarDoor_Des = 0x421330 (destructor, 8 bytes code)
//   CarDoor__SetPedInDoor = 0x421380 (10 bytes)
//   CarDoor__GetPedInDoor = 0x4351B0 (4 bytes - likely inline getter)
// 
// From gta2.exe.h (IDA): Confirmed structure
// Size: 0x10 bytes
// ============================================================================
struct CarDoor {
    u8 AnimationFrame[4];   // 0x0 - Animation frame data (array of 4 bytes)
    s32 DoorState;          // 0x4 - State: 0=closed, 1=open, 2=opening, 3=closing, etc.
    struct Ped* PedInDoor;  // 0x8 - Ped entering/exiting through door
    u8 Field_C;             // 0xC - Unknown byte (timer/flags)
    u8 Reserved1;           // 0xD - Reserved
    u8 Reserved2;           // 0xE - Reserved
    u8 Reserved3;           // 0xF - Reserved
};
// static_assert(sizeof(struct CarDoor) == 0x10, "CarDoor size mismatch");

// ============================================================================
// EngineStruct - Engine parameters
// Size: ~0x70 bytes based on typical engine data structures
// ============================================================================
struct EngineStruct {
    struct EngineStruct* Next;      // 0x0 - Next element in list
    f32 Rpm;                        // 0x4 - Engine RPM
    u8 Flags;                       // 0x8 - State flags (bit 0: started, bit 1: damaged)
    u8 Phase;                       // 0x9 - Work phase (0=start, 1=running, 2=stop)
    u8 DamageLevel;                 // 0xA - Damage level (0-100)
    u8 Padding;                     // 0xB - Alignment
    // More fields to be determined from ASM analysis
    u8 Reserved[20];                // Placeholder for remaining fields
};

// ============================================================================
// Model - Car model static data
// Size: ~0x20 bytes based on typical model structures
// ============================================================================
struct Model {
    u32 ModelId;            // 0x0 - Car model ID
    u8 Flags;               // 0x4 - Model flags (bit 0: visible, bit 1: reflection)
    u8 BodyType;            // 0x5 - Body type (sedan, truck, sport)
    u8 Class;               // 0x6 - Vehicle class (civilian, military, special)
    u8 RenderPriority;      // 0x7 - Rendering priority
    f32 Mass;               // 0x8 - Vehicle mass (kg)
    f32 Length;             // 0xC - Length (X dimension)
    f32 Width;              // 0x10 - Width (Y dimension)
    f32 Height;             // 0x14 - Height (Z dimension)
    void* SpriteData;       // 0x18 - Pointer to sprite data
    u32 CurrentSprite;      // 0x1C - Current sprite index
};

// ============================================================================
// Rect2D - Bounding box for collisions
// ============================================================================
struct Rect2D {
    f32 MinX;               // 0x0
    f32 MinY;               // 0x4
    f32 MaxX;               // 0x8
    f32 MaxY;               // 0xC
};

// ============================================================================
// CollisionInfo - Last collision information
// ============================================================================
struct CollisionInfo {
    void* HitObject;        // 0x0 - Object hit
    f32 ImpactForce;        // 0x4 - Impact force
    f32 NormalX;            // 0x8 - Collision normal X
    f32 NormalY;            // 0xC - Collision normal Y
    u32 CollisionTime;      // 0x10 - Collision timestamp
    u8 Reserved[12];        // Placeholder
};

// ============================================================================
// CarType enum
// ============================================================================
enum CarType {
    CAR_TYPE_CIVILIAN = 0,
    CAR_TYPE_POLICE = 1,
    CAR_TYPE_FIRETRUCK = 2,
    CAR_TYPE_AMBULANCE = 3,
    CAR_TYPE_MILITARY = 4,
    CAR_TYPE_TAXI = 5,
    CAR_TYPE_BUS = 6,
    CAR_TYPE_TRUCK = 7
};

// ============================================================================
// TRAFFIC_CAR_TYPE enum
// ============================================================================
enum TRAFFIC_CAR_TYPE {
    TRAFFIC_CAR_NORMAL = 0,
    TRAFFIC_CAR_TRUCK = 1,
    TRAFFIC_CAR_TAXI = 2,
    TRAFFIC_CAR_EMERGENCY = 3
};

// ============================================================================
// Main Car structure
// From MAP: Car__sub_403800 (constructor), Car__sub_403820
// Constructor size: needs verification from ASM
// ============================================================================
struct Car {
    // === Block 1: Weapons and Passengers (0x00 - 0x0F) ===
    struct Turret* Turret;              // 0x0 - Pointer to turret structure
    struct Passenger* Passengers;       // 0x4 - Array of passengers
    s32 LightsState;                    // 0x8 - Light state (bitmask)
    struct CarDoor Doors[4];            // 0xC - Door array [0]=hood, [1]=trunk, [2]=left, [3]=right
    
    // === Block 2: Links and Visualization (0x4C - 0x6B) ===
    struct Car* PreviousCar;            // 0x4C - Previous car in linked list (trains, trailers)
    struct SpriteS1* Sprite;            // 0x50 - Sprite for rendering (color 24)
    struct Ped* Driver;                 // 0x54 - Pointer to driver (NULL if none)
    struct Player* ControlledByPlayer;  // 0x58 - Player controlling the car
    struct EngineStruct* Engine;        // 0x5C - Engine parameters
    struct Model* ModelData;            // 0x60 - Static model data
    void* pVehicleStats;                // 0x64 - Pointer to global vehicle stats
    u32 PhysicsFlags;                   // 0x68 - Physics flags (collisions, gravity, friction)
    
    // === Block 3: Identification and Damage (0x6C - 0x8B) ===
    s32 ObjectID;                       // 0x6C - Unique object ID in world
    struct Ped* Attacker;               // 0x70 - Last ped that dealt damage
    s16 Health;                         // 0x74 - Car health (0 = destroyed)
    s16 VisibilityTimer;                // 0x76 - Invisibility timer
    u16 StatusFlags;                    // 0x78 - State flags (engine, alarm, theft)
    u16 Reserved1;                      // 0x7A - Alignment
    s32 SpecialTimer;                   // 0x7C - Special event timer (e.g., time to explosion)
    
    // === Block 4: State and Type (0x80 - 0x8F) ===
    u32 Reserved2;                      // 0x80 - Alignment
    enum CarType Type;                  // 0x84 - Car type
    s32 State;                          // 0x88 - State: 0=inactive, 1=active, 5=destroyed, 7=special
    u8 FireFlags;                       // 0x8C - Fire flags (bit 0: burning, bit 1: exploding)
    u8 SirenFlags;                      // 0x8D - Siren flags (type, priority)
    u8 SirenTimer;                      // 0x8E - Siren timer (frames until next sound)
    u8 HornTimer;                       // 0x8F - Horn timer
    
    // === Block 5: Damage and Player (0x90 - 0x9F) ===
    u32 DamageSource;                   // 0x90 - Last damage type (bullet, ram, explosion)
    u8 DamageCooldown;                  // 0x94 - Damage cooldown
    u8 OwnerPlayerId;                   // 0x95 - Owner player ID (multiplayer)
    u16 Reserved3;                      // 0x96 - Alignment
    s32 DoorLockState;                  // 0x98 - Door lock state (1=locked, 2=unlocked)
    s32 EngineStatus;                   // 0x9C - Engine status (0=off, 1=started, 2=broken)
    
    // === Block 6: Traffic and Effects (0xA0 - 0xBF) ===
    enum TRAFFIC_CAR_TYPE TrafficType;  // 0xA0 - Traffic AI type
    char SirenState;                    // 0xA4 - Siren state (off/on/blinking)
    u8 SirenPhase;                      // 0xA5 - Siren blink phase
    u8 Reserved4;                       // 0xA6 - Alignment
    u8 HornActive;                      // 0xA7 - Horn active flag
    u8 Reserved5;                       // 0xA8 - Alignment
    u8 FireDuration;                    // 0xA9 - Fire duration timer
    u8 Reserved6[6];                    // 0xAA - Alignment / future expansion
    u32 ExplosionTimer;                 // 0xB0 - Time until explosion
    u32 UpgradeSoundID;                 // 0xB4 - Upgrade sound ID (turbo, nitro)
    u32 Reserved7;                      // 0xB8 - Alignment to end of structure
    
    // === Block 7: Collisions ===
    struct Rect2D BoundingBox;          // 0xBC - Bounding box for collisions
    struct CollisionInfo LastCollision; // 0xCC - Last collision info
};

// Size assertion - will be verified after constructor analysis
// static_assert(sizeof(struct Car) == 0xE8, "Car size mismatch");

#endif // GTA2_ENTITIES_H
