#pragma once

#include <cstdint>
#include "gta2_types.h"

// Forward declarations
struct Ped;
struct Car;
struct Player;

// GameObject structure size: 0x1C8 (456 bytes)
// Fields count: 71
// Based on IDA Pro analysis of gta2.exe
#pragma pack(push, 1)
struct GameObject {
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
    char field_A8[4];            // 0x00A8 - placeholder
    char field_AC[4];            // 0x00AC - placeholder
    char field_B0[4];            // 0x00B0 - placeholder
    char field_B4[4];            // 0x00B4 - placeholder
    char field_B8[4];            // 0x00B8 - placeholder
    char field_BC[4];            // 0x00BC - placeholder
    char field_C0[4];            // 0x00C0 - placeholder
    char field_C4[4];            // 0x00C4 - placeholder
    char field_C8[4];            // 0x00C8 - placeholder
    char field_CC[4];            // 0x00CC - placeholder
    char field_D0[4];            // 0x00D0 - placeholder
    char field_D4[4];            // 0x00D4 - placeholder
    char field_D8[4];            // 0x00D8 - placeholder
    char field_DC[4];            // 0x00DC - placeholder
    char field_E0[4];            // 0x00E0 - placeholder
    char field_E4[4];            // 0x00E4 - placeholder
    char field_E8[4];            // 0x00E8 - placeholder
    char field_EC[4];            // 0x00EC - placeholder
    char field_F0[4];            // 0x00F0 - placeholder
    char field_F4[4];            // 0x00F4 - placeholder
    char field_F8[4];            // 0x00F8 - placeholder
    char field_FC[4];            // 0x00FC - placeholder
    char field_100[4];           // 0x0100 - placeholder
    char field_104[4];           // 0x0104 - placeholder
    char field_108[4];           // 0x0108 - placeholder
    char field_10C[4];           // 0x010C - placeholder
    char field_110[4];           // 0x0110 - placeholder
    char field_114[4];           // 0x0114 - placeholder
    char field_118[4];           // 0x0118 - placeholder
    char field_11C[4];           // 0x011C - placeholder
    char field_120[4];           // 0x0120 - placeholder
    char field_124[4];           // 0x0124 - placeholder
    char field_128[4];           // 0x0128 - placeholder
    char field_12C[4];           // 0x012C - placeholder
    char field_130[4];           // 0x0130 - placeholder
    char field_134[4];           // 0x0134 - placeholder
    char field_138[4];           // 0x0138 - placeholder
    char field_13C[4];           // 0x013C - placeholder
    char field_140[4];           // 0x0140 - placeholder
    char field_144[4];           // 0x0144 - placeholder
    char field_148[4];           // 0x0148 - placeholder
    char field_14C[4];           // 0x014C - placeholder
    char field_150[4];           // 0x0150 - placeholder
    char field_154[4];           // 0x0154 - placeholder
    char field_158[4];           // 0x0158 - placeholder
    char field_15C[4];           // 0x015C - placeholder
    char field_160[4];           // 0x0160 - placeholder
    char field_164[4];           // 0x0164 - placeholder
    char field_168[4];           // 0x0168 - placeholder
    char field_16C[4];           // 0x016C - placeholder
    char field_170[4];           // 0x0170 - placeholder
    char field_174[4];           // 0x0174 - placeholder
    char field_178[4];           // 0x0178 - placeholder
    char field_17C[4];           // 0x017C - placeholder
    char field_180[4];           // 0x0180 - placeholder
    char field_184[4];           // 0x0184 - placeholder
    char field_188[4];           // 0x0188 - placeholder
    char field_18C[4];           // 0x018C - placeholder
    char field_190[4];           // 0x0190 - placeholder
    char field_194[4];           // 0x0194 - placeholder
    char field_198[4];           // 0x0198 - placeholder
    char field_19C[4];           // 0x019C - placeholder
    char field_1A0[4];           // 0x01A0 - placeholder
    char field_1A4[4];           // 0x01A4 - placeholder
    char field_1A8[4];           // 0x01A8 - placeholder
    char field_1AC[4];           // 0x01AC - placeholder
    char field_1B0[4];           // 0x01B0 - placeholder
    char field_1B4[4];           // 0x01B4 - placeholder
    char field_1B8[4];           // 0x01B8 - placeholder
    char field_1BC[4];           // 0x01BC - placeholder
    char field_1C0[4];           // 0x01C0 - placeholder
    char field_1C4[4];           // 0x01C4 - placeholder
};
#pragma pack(pop)

static_assert(sizeof(GameObject) == 0x1C8, "GameObject size must be 0x1C8");

// ============================================================================
// GameObject Functions (60 functions from gta2.exe.map)
// Addresses extracted from gta2.exe/ida_pro/gta2.exe.map
// ============================================================================

// Address: 0x00403900
Car* GameObject_GetVehicle(GameObject* obj);

// Address: 0x0041B080
void GameObject_sub_41B080(GameObject* obj);

// Address: 0x00433880
void GameObject_sub_433880(GameObject* obj);

// Address: 0x004338D0
int GameObject_GetSpriteS1(GameObject* obj);

// Address: 0x004338E0
void GameObject_SetPed(GameObject* obj, Ped* ped);

// Address: 0x004338F0
void GameObject_sub_4338F0(GameObject* obj);

// Address: 0x00433900
void GameObject_SetCar(GameObject* obj, Car* car);

// Address: 0x00433910
void GameObject_set_ped_state_1(GameObject* obj, int state);

// Address: 0x00433920
void GameObject_SetSpeed(GameObject* obj, float speed);

// Address: 0x00433930
void GameObject_sub_433930(GameObject* obj);

// Address: 0x00433940
void GameObject_sub_433940(GameObject* obj);

// Address: 0x00433970
void GameObject_sub_433970(GameObject* obj);

// Address: 0x004339C0
float GameObject_GetX(GameObject* obj);

// Address: 0x004339E0
float GameObject_GetY(GameObject* obj);

// Address: 0x00433A00
float GameObject_GetZ(GameObject* obj);

// Address: 0x00433A20
void GameObject_sub_433A20(GameObject* obj);

// Address: 0x00433A30
void GameObject_SetRotation(GameObject* obj, float rotation);

// Address: 0x00433A40
float GameObject_get_rotation(GameObject* obj);

// Address: 0x00433A50
void GameObject_sub_433A50(GameObject* obj);

// Address: 0x00433A60
void GameObject_sub_433A60(GameObject* obj);

// Address: 0x00433A70
void GameObject_sub_433A70(GameObject* obj);

// Address: 0x00433A80
void GameObject_sub_433A80(GameObject* obj);

// Address: 0x00433A90
void GameObject_sub_433A90(GameObject* obj);

// Address: 0x00491DE0
void GameObject_sub_491DE0(GameObject* obj);

// Address: 0x00491E00
void GameObject_sub_491E00(GameObject* obj);

// Address: 0x00491E40
void GameObject_sub_491E40(GameObject* obj);

// Address: 0x00491E60
void GameObject_sub_491E60(GameObject* obj);

// Address: 0x00491EA0
void GameObject_sub_491EA0(GameObject* obj);

// Address: 0x00491EC0
void GameObject_sub_491EC0(GameObject* obj);

// Address: 0x00491FA0
void GameObject_sub_491FA0(GameObject* obj);

// Address: 0x00492190
void GameObject_sub_492190(GameObject* obj);

// Address: 0x004928A0
void GameObject_sub_4928A0(GameObject* obj);

// Address: 0x004930C0
void GameObject_sub_4930C0(GameObject* obj);

// Address: 0x004930F0
void GameObject_sub_4930F0(GameObject* obj);

// Address: 0x00493390
void GameObject_sub_493390(GameObject* obj);

// Address: 0x004935F0
void GameObject_GameObject_des(GameObject* obj);

// Address: 0x00493640
void GameObject_sub_493640(GameObject* obj);

// Address: 0x00493710
void GameObject_sub_493710(GameObject* obj);

// Address: 0x00493850
void GameObject_sub_493850(GameObject* obj);

// Address: 0x004938A0
void GameObject_sub_4938A0(GameObject* obj);

// Address: 0x00494180
void GameObject_sub_494180(GameObject* obj);

// Address: 0x00495220
void GameObject_sub_495220(GameObject* obj);

// Address: 0x00495540
void GameObject_sub_495540(GameObject* obj);

// Address: 0x00495700
void GameObject_sub_495700(GameObject* obj);

// Address: 0x00495980
void GameObject_sub_495980(GameObject* obj);

// Address: 0x00495BF0
void GameObject_sub_495BF0(GameObject* obj);

// Address: 0x00496800
void GameObject_sub_496800(GameObject* obj);

// Address: 0x00496880
void GameObject_sub_496880(GameObject* obj);

// Address: 0x00497A60
void GameObject_GameObject(GameObject* obj);

// Address: 0x00497C20
void GameObject_sub_497C20(GameObject* obj);

// Address: 0x004995A0
void GameObject_sub_4995A0(GameObject* obj);

// Address: 0x0049A560
void GameObject_sub_49A560(GameObject* obj);

// Address: 0x0049B0D0
void GameObject_sub_49B0D0(GameObject* obj);

// Address: 0x0049BAC0
void GameObject_sub_49B0D0_0(GameObject* obj);

// Address: 0x0049BAD0
void GameObject_sub_49BAD0(GameObject* obj);

// Address: 0x0049BC20
void GameObject_sub_49BC20(GameObject* obj);

// Address: 0x0049BD10
void GameObject_sub_49BD10(GameObject* obj);

// Address: 0x0049C120
void GameObject_sub_49C120(GameObject* obj);

// Address: 0x0049C460
void GameObject_sub_49C460(GameObject* obj);

// Address: 0x004A5030
void GameObject_sub_4A5030(GameObject* obj);

// End of GameObject.h
