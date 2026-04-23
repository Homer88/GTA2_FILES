#pragma once

#ifndef GANG_H
#define GANG_H

#include <cstdint>
#include "gta2_types.h"

// Forward declarations
struct Ped;
struct Car;
struct Player;

// Gang structure size: 0xA8 (168 bytes)
// Fields count: 42
// Based on IDA Pro analysis of gta2.exe
// Functions from gta2.exe.map: 26 functions
#pragma pack(push, 1)
struct Gang {
    // === Basic Identity (0x00 - 0x0F) ===
    char* Name;                // 0x0000 - Gang name string pointer
    int GangId;                // 0x0004 - Unique gang identifier
    int RemapId;               // 0x0008 - Remap/color scheme ID
    int TerritoryZone;         // 0x000C - Current territory zone ID
    
    // === Gang Members & Leadership (0x10 - 0x2F) ===
    Ped* Leader;               // 0x0010 - Pointer to gang leader Ped
    Ped* Members[8];           // 0x0014 - Array of gang member Peds (max 8)
    u8 MemberCount;            // 0x0034 - Current number of members
    u8 MaxMembers;             // 0x0035 - Maximum allowed members
    u16 Reserved1;             // 0x0036 - Alignment padding
    
    // === Weapons & Equipment (0x38 - 0x47) ===
    int WeaponType1;           // 0x0038 - Primary weapon type
    int WeaponType2;           // 0x003C - Secondary weapon type
    int WeaponType3;           // 0x0040 - Tertiary weapon type
    int WeaponAmmo;            // 0x0044 - Available ammunition
    
    // === Vehicles (0x48 - 0x57) ===
    int PreferredCarType;      // 0x0048 - Preferred vehicle type
    int CarRemapId;            // 0x004C - Vehicle remap/color ID
    Car* AssignedCar;          // 0x0050 - Pointer to assigned vehicle
    int CarSpawnChance;        // 0x0054 - Chance of car spawning (0-100)
    
    // === Relations & Respect (0x58 - 0x77) ===
    int WarMask;               // 0x0058 - Bitmask of gangs at war with
    int RespectMatrix[8];      // 0x005C - Respect values for other gangs (8 gangs)
    int AllyMask;              // 0x007C - Bitmask of allied gangs
    
    // === Behavior & AI (0x80 - 0x97) ===
    float SpawnX;              // 0x0080 - Spawn point X coordinate
    float SpawnY;              // 0x0084 - Spawn point Y coordinate
    float SpawnZ;              // 0x0088 - Spawn point Z coordinate
    int AggressionLevel;       // 0x008C - Aggression level (0-100)
    int CourageLevel;          // 0x0090 - Courage level (0-100)
    int TerritoryRadius;       // 0x0094 - Territory defense radius
    
    // === State & Flags (0x98 - 0xA7) ===
    u32 Flags;                 // 0x0098 - Gang state flags
    u8 Visible;                // 0x009C - Is gang visible on map
    u8 Active;                 // 0x009D - Is gang currently active
    u8 HostileToPlayer;        // 0x009E - Hostility towards player
    u8 Padding1;               // 0x009F - Alignment
    Ped* TargetPed;            // 0x00A0 - Current target Ped (for attacks)
    int AttackMode;            // 0x00A4 - Current attack mode
};
#pragma pack(pop)


// ============================================================================
// Gang Functions (26 functions from gta2.exe.map)
// Addresses extracted from gta2.exe/ida_pro/gta2.exe.map
// ============================================================================

// Address: 0x00433B30 - Initialize gang with default values
void Gang_Init(Gang* gang);

// Address: 0x0045AE40 - Constructor: Gang1 (alternative constructor)
void Gang_Gang1(Gang* gang);

// Address: 0x0045AE50 - Destructor: Gang_Des
void Gang_Gang_Des(Gang* gang);

// Address: 0x0045D920 - Update gang state and AI
void Gang_Update(Gang* gang);

// Address: 0x0045D960 - Constructor: Gang (main constructor)
void Gang_Gang(Gang* gang);

// Address: 0x0045D9E0 - Reset gang to initial state
void Gang_Reset(Gang* gang);

// Address: 0x0045DA20 - Set respect value for a specific player
void Gang_SetRespectForPlayer(Gang* gang, Player* player, int respect);

// Address: 0x0045DA80 - Decrease respect for a player by amount
void Gang_decreaseRespect(Gang* gang, Player* player, int amount);

// Address: 0x0045DAC0 - Get current respect value for a player
int Gang_GetRespectForPlayer(Gang* gang, Player* player);

// Address: 0x0045DAE0 - Internal gang calculation/update
void Gang_InternalUpdate(Gang* gang);

// Address: 0x0045DB20 - Set war mask (bitmask of enemy gangs)
void Gang_SetWarMaskGang(Gang* gang, int mask);

// Address: 0x0045DB40 - Set gang name string
void Gang_SetName(Gang* gang, const char* name);

// Address: 0x0045DB70 - Initialize gang relationships
void Gang_InitRelations(Gang* gang);

// Address: 0x0045DD50 - Get currently visible gang on map
Gang* Gang_GetVisibleGang();

// Address: 0x0045DE10 - Update gang territory control
void Gang_UpdateTerritory(Gang* gang);

// Address: 0x0045DEA0 - Process gang member AI
void Gang_ProcessMembers(Gang* gang);

// Address: 0x004758A0 - Set remap/color scheme ID
void Gang_SetRemap(Gang* gang, int remapId);

// Address: 0x004758B0 - Set primary weapon type for gang members
void Gang_SetWeapon1(Gang* gang, int weaponType);

// Address: 0x004758C0 - Set secondary weapon type for gang members
void Gang_SetWeapon2(Gang* gang, int weaponType);

// Address: 0x004758D0 - Set tertiary weapon type for gang members
void Gang_SetWeapon3(Gang* gang, int weaponType);

// Address: 0x004758E0 - Set preferred vehicle type
void Gang_SetTypeCar(Gang* gang, int carType);

// Address: 0x004758F0 - Set vehicle remap/color ID
void Gang_SetCar_remap(Gang* gang, int remapId);

// Address: 0x00475900 - Set internal gang parameter (unknown purpose)
void Gang_SetInternalParam(Gang* gang, int value);

// Address: 0x00475910 - Set gang spawn point coordinates
void Gang_SetXYZ(Gang* gang, float x, float y, float z);

// Address: 0x00475940 - Set gang ID identifier
void Gang_SetGang(Gang* gang, int gangId);

// Address: 0x00475950 - Set target Ped for gang attacks
void Gang_SetKillChar(Gang* gang, Ped* ped);

#ifdef __cplusplus
}
#endif

#endif // GANG_H
