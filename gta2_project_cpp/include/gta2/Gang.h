#pragma once

#include <cstdint>
#include "gta2_types.h"

// Forward declarations
struct Ped;
struct Car;
struct Player;

// Gang structure size: 0xA8 (168 bytes)
// Fields count: 42
// Based on IDA Pro analysis of gta2.exe
#pragma pack(push, 1)
struct Gang {
    char field_0[4];             // 0x0000 - placeholder
    char field_4[4];             // 0x0004 - placeholder
    char field_8[4];             // 0x0008 - placeholder
    char field_C[4];             // 0x000C - placeholder
    char field_10[4];            // 0x0010 - placeholder
    char field_14[4];            // 0x0014 - placeholder
    char field_18[4];            // 0x0018 - placeholder
    char field_1C[4];            // 0x001C - placeholder
    char field_20[4];            // 0x0020 - placeholder
    char field_24[4];            // 0x0024 - placeholder
    char field_28[4];            // 0x0028 - placeholder
    char field_2C[4];            // 0x002C - placeholder
    char field_30[4];            // 0x0030 - placeholder
    char field_34[4];            // 0x0034 - placeholder
    char field_38[4];            // 0x0038 - placeholder
    char field_3C[4];            // 0x003C - placeholder
    char field_40[4];            // 0x0040 - placeholder
    char field_44[4];            // 0x0044 - placeholder
    char field_48[4];            // 0x0048 - placeholder
    char field_4C[4];            // 0x004C - placeholder
    char field_50[4];            // 0x0050 - placeholder
    char field_54[4];            // 0x0054 - placeholder
    char field_58[4];            // 0x0058 - placeholder
    char field_5C[4];            // 0x005C - placeholder
    char field_60[4];            // 0x0060 - placeholder
    char field_64[4];            // 0x0064 - placeholder
    char field_68[4];            // 0x0068 - placeholder
    char field_6C[4];            // 0x006C - placeholder
    char field_70[4];            // 0x0070 - placeholder
    char field_74[4];            // 0x0074 - placeholder
    char field_78[4];            // 0x0078 - placeholder
    char field_7C[4];            // 0x007C - placeholder
    char field_80[4];            // 0x0080 - placeholder
    char field_84[4];            // 0x0084 - placeholder
    char field_88[4];            // 0x0088 - placeholder
    char field_8C[4];            // 0x008C - placeholder
    char field_90[4];            // 0x0090 - placeholder
    char field_94[4];            // 0x0094 - placeholder
    char field_98[4];            // 0x0098 - placeholder
    char field_9C[4];            // 0x009C - placeholder
    char field_A0[4];            // 0x00A0 - placeholder
    char field_A4[4];            // 0x00A4 - placeholder
};
#pragma pack(pop)

static_assert(sizeof(Gang) == 0xA8, "Gang size must be 0xA8");

// ============================================================================
// Gang Functions (26 functions from gta2.exe.map)
// Addresses extracted from gta2.exe/ida_pro/gta2.exe.map
// ============================================================================

// Address: 0x00433B30
void Gang_sub_433B30(Gang* gang);

// Address: 0x0045AE40
void Gang_Gang1(Gang* gang);

// Address: 0x0045AE50
void Gang_Gang_Des(Gang* gang);

// Address: 0x0045D920
void Gang_sub_45D920(Gang* gang);

// Address: 0x0045D960
void Gang_Gang(Gang* gang);

// Address: 0x0045D9E0
void Gang_sub_45D9E0(Gang* gang);

// Address: 0x0045DA20
void Gang_SetRespectForPlayer(Gang* gang, Player* player, int respect);

// Address: 0x0045DA80
void Gang_decreaseRespect(Gang* gang, Player* player, int amount);

// Address: 0x0045DAC0
int Gang_GetRespectForPlayer(Gang* gang, Player* player);

// Address: 0x0045DAE0
void Gang_sub_45DAE0(Gang* gang);

// Address: 0x0045DB20
void Gang_SetWarMaskGang(Gang* gang, int mask);

// Address: 0x0045DB40
void Gang_SetName(Gang* gang, const char* name);

// Address: 0x0045DB70
void Gang_sub_45DB70(Gang* gang);

// Address: 0x0045DD50
Gang* Gang_GetVisibleGang();

// Address: 0x0045DE10
void Gang_sub_45DE10(Gang* gang);

// Address: 0x0045DEA0
void Gang_sub_45DEA0(Gang* gang);

// Address: 0x004758A0
void Gang_SetRemap(Gang* gang, int remapId);

// Address: 0x004758B0
void Gang_SetWeapon1(Gang* gang, int weaponType);

// Address: 0x004758C0
void Gang_SetWeapon2(Gang* gang, int weaponType);

// Address: 0x004758D0
void Gang_SetWeapon3(Gang* gang, int weaponType);

// Address: 0x004758E0
void Gang_SetTypeCar(Gang* gang, int carType);

// Address: 0x004758F0
void Gang_SetCar_remap(Gang* gang, int remapId);

// Address: 0x00475900
void Gang_Set_475900(Gang* gang, int value);

// Address: 0x00475910
void Gang_SetXYZ(Gang* gang, float x, float y, float z);

// Address: 0x00475940
void Gang_SetGang(Gang* gang, int gangId);

// Address: 0x00475950
void Gang_SetKillChar(Gang* gang, Ped* ped);

// End of Gang.h
