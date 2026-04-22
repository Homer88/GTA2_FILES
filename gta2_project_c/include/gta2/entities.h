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
// Constructor size: 0x42FEA0 - 0x42FE90 = 0x10 bytes
// ============================================================================
struct Passenger {
    struct Ped* PedPtr;     // 0x0 - Pointer to ped entity
    s32 SeatIndex;          // 0x4 - Seat index (-1 = empty, 0 = driver, 1+ = passengers)
    u8 StateFlags;          // 0x5 - State flags (bit 0: alive, bit 1: entering, bit 2: exiting)
    u16 ActionTimer;        // 0x6 - Timer or animation frame for entering/exiting
    u8 ActionState;         // 0x8 - Action state (0=sitting, 1=boarding, 2=exiting)
    u8 Reserved[3];         // 0x9 - Alignment to 0xC
};

// ============================================================================
// CarDoor structure  
// From MAP: CarDoor__sub_41F680, CarDoor__sub_41F6C0 exist
// Typical size: 0x10 bytes based on constructor patterns
// ============================================================================
struct CarDoor {
    s32 AnimationFrame;     // 0x0 - Current animation frame / delay timer
    s32 DoorState;          // 0x4 - State: 0=closed, 1=open, 2=opening, 3=closing, 4=transition, 5=delay, 6=forced closed
    struct Ped* PedInDoor;  // 0x8 - Ped entering/exiting through door
    u8 DoorTimer;           // 0xC - Delay timer before opening (decreases in state 5)
    u8 AnimationFlags;      // 0xD - Animation flags (bit 0: active, bit 1: reverse direction)
    u8 TotalFrames;         // 0xE - Total animation frames
    u8 Padding;             // 0xF - Alignment
};

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
