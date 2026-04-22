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
// S200 structure - Sub-structure used in Ped (3 instances at start)
// From constructor: Construct(this, 3, 100, S200::S200, S200::S200_des)
// Size: 100 bytes (0x64)
// ============================================================================
struct S200 {
    u8 Data[100];           // 0x0-0x63 - Exact content unknown, initialized by S200::S200
};
static_assert(sizeof(struct S200) == 0x64, "S200 size must be 100 bytes");

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
//   
// CONSTRUCTOR ANALYSIS (Ped::Ped):
//   - 3x S200 structures: 0x0 - 0x12C (300 bytes)
//   - 5x WORD fields: 0x12C, 0x12E, 0x130, 0x132, 0x134 (10 bytes total)
//   - ID field: 0x134 (4 bytes)
//   - Rest initialized by Ped::Clean()
//   - NextPed at end of structure
//
// CLEAN FUNCTION FIELDS (from Ped::Clean):
//   Flags, SearchType, CarId, Occupation, Health, Remap
//   XCoordinate, PositionY, Camer_Z_View (integers)
//   field_12C, field_12E, field_130, field_132, field_134 (WORD fields)
//   TargetCarDoor, AnimationState, Car1, DamageState, ExitAnimState
//   ActionState, CurrentAction, ObjectiveTimer, CarStateTimer
//   PositionX1, PositionY1, PositionZ2, X, Y, Z (coordinates)
//   Driver, LinkedPed, Vehicle, CurrentVehicle, TargetCarForEnter
//   Player, PedState, S169, GameObject, CurrentCar
//   SelectedWeapon, Weapon1, Weapon2, Gang, DriverPed, IDPed
//   DamageType, S94, SavedState, Invulnerability, PoliceStar
//   LastCharPunched, GraphicType, GameObject1
//   GangCarModel, ElvisLeader, field_260
// ============================================================================
struct Ped {
    // === Block 1: Three S200 sub-structures (0x00 - 0x12B) ===
    struct S200 S200_1;               // 0x00-0x63   - First S200 instance
    struct S200 S200_2;               // 0x64-0xC7   - Second S200 instance  
    struct S200 S200_3;               // 0xC8-0x12B  - Third S200 instance
    
    // === Block 2: Word fields from constructor (0x12C - 0x137) ===
    u16 field_12C;                    // 0x12C - Initialized to unk_5E5C60
    u16 field_12E;                    // 0x12E - Initialized to unk_5E5C60
    u16 field_130;                    // 0x130 - Initialized to *(_WORD *)&sub_401C80(...)
    u16 field_132;                    // 0x132 - Initialized to unk_5E5C60
    u16 field_134;                    // 0x134 - Initialized to unk_5E5C60
    
    // === Block 3: ID and basic state (0x138 - 0x13F) ===
    u32 ID;                           // 0x138 - Ped ID (set to 0 in constructor)
    u32 Flags;                        // 0x13C - General flags (bitmask)
    
    // === Block 4: Search and occupation (0x140 - 0x14F) ===
    u8 SearchType;                    // 0x140 - SEARCHTYPE_AREA default
    u8 Occupation;                    // 0x141 - DUMMY default
    u8 Remap;                         // 0x142 - REMAP_NAKED_PEDESTRIAN|REMAP_REDNECK_1|0xE0
    u8 Padding1;                      // 0x143 - Alignment
    s32 Health;                       // 0x144 - Health (set to 0)
    u32 field_20E;                    // 0x148 - Unknown field (set to 0)
    
    // === Block 5: Primary coordinates (0x14C - 0x15B) ===
    s32 XCoordinate;                  // 0x14C - World X (initialized to unk_5E5CFC)
    s32 PositionY;                    // 0x150 - World Y (initialized to unk_5E5CFC)
    s32 Camer_Z_View;                 // 0x154 - Camera Z view (initialized to unk_5E5CFC)
    
    // === Block 6: Car interaction (0x158 - 0x16F) ===
    u8 TargetCarDoor;                 // 0x158 - Target car door (default 1)
    u8 AnimationState;                // 0x159 - Animation state (default 0)
    u16 Car1;                         // 0x15A - Car ID or flag (default 0)
    u32 field_22C;                    // 0x15C - Unknown (default 0)
    u32 field_230;                    // 0x160 - Unknown (default 1)
    u32 field_234;                    // 0x164 - Unknown (cleared in Clean)
    u32 field_270;                    // 0x168 - Unknown (default 1)
    
    // === Block 7: Damage and action state (0x16C - 0x187) ===
    u8 DamageState;                   // 0x16C - Damage state (default 0)
    u8 ExitAnimState;                 // 0x16D - Exit animation state (default 0)
    u8 ActionState;                   // 0x16E - Action state (default 0)
    u8 CurrentAction;                 // 0x16F - Current action (default 0)
    s32 ObjectiveTimer;               // 0x170 - Objective timer (default 9999)
    s32 CarStateTimer;                // 0x174 - Car state timer (default 9999)
    
    // === Block 8: Secondary coordinates (0x178 - 0x193) ===
    s32 PositionX1;                   // 0x178 - Secondary X position
    s32 PositionY1;                   // 0x17C - Secondary Y position
    s32 PositionZ2;                   // 0x180 - Secondary Z position
    s32 X;                            // 0x184 - Primary X coordinate
    s32 Y;                            // 0x188 - Primary Y coordinate
    s32 Z;                            // 0x18C - Primary Z coordinate
    
    // === Block 9: Links and relationships (0x190 - 0x1AF) ===
    struct Ped* Driver;               // 0x190 - Driver pointer (if passenger)
    struct Ped* LinkedPed;            // 0x194 - Linked ped pointer
    void* Vehicle;                    // 0x198 - Vehicle pointer
    void* CurrentVehicle;             // 0x19C - Current vehicle pointer
    void* TargetCarForEnter;          // 0x1A0 - Target car for entering
    u8 field_227;                     // 0x1A4 - Unknown byte
    u8 field_228;                     // 0x1A5 - Unknown byte
    u16 Padding2;                     // 0x1A6 - Alignment
    struct Player* Player;            // 0x1A8 - Player pointer
    
    // === Block 10: State and objects (0x1AC - 0x1CF) ===
    enum PedState PedState;           // 0x1AC - Ped state (default PEDSTATE_MOVE_TURN)
    u32 field_27C;                    // 0x1B0 - Unknown (default 0)
    void* S169;                       // 0x1B4 - S169 pointer (default 0)
    void* GameObject;                 // 0x1B8 - Game object pointer (default 0)
    void* CurrentCar;                 // 0x1BC - Current car pointer (default 0)
    
    // === Block 11: Weapons (0x1C0 - 0x1D7) ===
    void* SelectedWeapon;             // 0x1C0 - Selected weapon (default 0)
    void* Weapon1;                    // 0x1C4 - Weapon slot 1 (default 0)
    void* Weapon2;                    // 0x1C8 - Weapon slot 2 (default 0)
    
    // === Block 12: Gang and identification (0x1CC - 0x1E7) ===
    void* Gang;                       // 0x1CC - Gang pointer (default 0)
    u8 field_262;                     // 0x1D0 - Unknown byte
    u8 field_263;                     // 0x1D1 - Unknown byte
    u16 Padding3;                     // 0x1D2 - Alignment
    struct Ped* DriverPed;            // 0x1D4 - Driver ped pointer (default 0)
    struct Ped* IDPed;                // 0x1D8 - ID ped pointer (default 0)
    u8 DamageType;                    // 0x1DC - Damage type (default 0)
    u8 Padding4[3];                   // 0x1DD - Alignment
    u32 field_264;                    // 0x1E0 - Unknown (default 0)
    
    // === Block 13: S200_50 array (0x1E4 - 0x1FB) ===
    // From Clean: this->S200_50[0].A = 0, this->S200_50[0].B = 0
    struct {
        u32 A;                        // 0x0
        u32 B;                        // 0x4
    } S200_50[2];                     // 0x1E4-0x1EB - Array of 2 elements (8 bytes each)
    
    // === Block 14: Additional fields (0x1EC - 0x223) ===
    u8 field_261;                     // 0x1EC - Unknown byte (default 0)
    u8 Padding5[3];                   // 0x1ED - Alignment
    u32 field_18C;                    // 0x1F0 - Unknown (default 0)
    u32 S94;                          // 0x1F4 - S94 field (default 0)
    u32 field_194;                    // 0x1F8 - Unknown (default 0)
    u8 field_265;                     // 0x1FC - Unknown byte (default 0)
    u8 Padding6[3];                   // 0x1FD - Alignment
    s32 field_1D0;                    // 0x200 - Unknown (initialized to unk_5E5CFC)
    s32 field_1D4;                    // 0x204 - Unknown (initialized to unk_5E5CFC)
    s32 field_1D8;                    // 0x208 - Unknown (initialized to unk_5E5CFC)
    s32 PositionX2;                   // 0x20C - Secondary X (initialized to unk_5E5CFC)
    struct Ped* DriverPed1;           // 0x210 - Driver ped pointer 1
    s32 PositionZ1;                   // 0x214 - Secondary Z (initialized to unk_5E5CFC)
    s32 field_1E8;                    // 0x218 - Unknown (initialized to unk_5E5CFC)
    s32 field_1EC;                    // 0x21C - Unknown (initialized to unk_5E5CFC)
    u32 field_184;                    // 0x220 - Unknown (default 0)
    u8 field_267;                     // 0x224 - Unknown byte (default 0)
    u8 Padding7[3];                   // 0x225 - Alignment
    
    // === Block 15: State and special fields (0x228 - 0x257) ===
    u32 SavedState;                   // 0x228 - Saved state (default 11)
    u32 field_284;                    // 0x22C - Unknown (default 28)
    u32 Invulnerability;              // 0x230 - Invulnerability flag (default 0)
    u32 PoliceStar;                   // 0x234 - Police star level (default 0)
    u32 field_20C;                    // 0x238 - Unknown (default 0)
    u32 field_288;                    // 0x23C - Unknown (default 2)
    u32 field_28C;                    // 0x240 - Unknown (default 0)
    void* LastCharPunched;            // 0x244 - Last character punched (default 0)
    u8 field_266;                     // 0x248 - Unknown byte (default 0)
    u8 Padding8[3];                   // 0x249 - Alignment
    u32 field_210;                    // 0x24C - Unknown (default 0)
    u16 field_212;                    // 0x250 - Unknown (default 100)
    u16 Padding9;                     // 0x252 - Alignment
    s32 field_1F4;                    // 0x254 - Unknown (initialized to unk_5E5D90)
    s32 field_1F0;                    // 0x258 - Unknown (initialized to unk_5E5D28)
    
    // === Block 16: Final fields (0x25C - 0x293) ===
    u32 field_268;                    // 0x25C - Unknown (default 0)
    void* sPed3;                      // 0x260 - sPed3 pointer (default 0)
    void* Gang1;                      // 0x264 - Gang pointer 1 (default 0)
    u8 field_269;                     // 0x268 - Unknown byte (default -1)
    u8 Padding10[3];                  // 0x269 - Alignment
    u32 field_214;                    // 0x26C - Unknown (default 0)
    u8 field_26A;                     // 0x270 - Unknown byte (default 0)
    u8 Padding11[3];                  // 0x271 - Alignment
    u8 GraphicType;                   // 0x274 - Graphic type (default GRAPHIC_EMERG)
    u8 Padding12[3];                  // 0x275 - Alignment
    u32 field_250;                    // 0x278 - Unknown (default 0)
    u8 field_224;                     // 0x27C - Unknown byte (flags, default set to 0x20)
    u8 Padding13[3];                  // 0x27D - Alignment
    void* GameObject1;                // 0x280 - Game object pointer 1 (default 0)
    u32 field_13C;                    // 0x284 - Unknown (default 0)
    u32 field_220;                    // 0x288 - Unknown (default 0)
    u8 field_229;                     // 0x28C - Unknown byte (default 0)
    u8 Padding14[3];                  // 0x28D - Alignment
    u8 GangCarModel;                  // 0x290 - Gang car model (default 35)
    u8 ElvisLeader;                   // 0x291 - Elvis leader flag (default 0)
    u8 field_260;                     // 0x292 - Unknown byte (default 0)
    u8 Padding15;                     // 0x293 - Alignment
    
    // === CRITICAL: NextPed field MUST be at offset 0xA5 (165 bytes) ===
    // This conflicts with our current layout - NEEDS REVISION!
    // The constructor loop shows: pNextPed += 165 (0xA5)
    // But our fields extend beyond this point.
    // POSSIBLE EXPLANATION: NextPed is part of a different structure overlay
    // or the PedManager uses a separate linked list structure.
};

// NOTE: Current size calculation shows mismatch with NextPed offset
// Need to re-analyze: either NextPed is not in Ped struct,
// or Ped struct is smaller than 0x294, or there's an overlay.
// static_assert(sizeof(struct Ped) == 0x294, "Ped size must be 0x294 bytes");
// static_assert(offsetof(struct Ped, NextPed) == 0xA5, "NextPed must be at offset 0xA5");

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
