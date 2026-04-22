// Auto-generated structure: Gang
// Source: Gang.txt
// Fields count: 35
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct Gang
{
    bool inUse;
    GANG CurrentGang;
    char field_C;
    char field_D;
    char field_E;
    char field_F;
    char field_10;
    char remap;
    char pad;
    char field_103;
    bool max_out;
    char field_111;
    char field_112;
    char field_113;
    char field_114;
    char field_115;
    char field_116;
    char field_117;
    char field_118;
    char field_119;
    char field_11A;
    char Reting;
    char field_124;
    int X;
    int Y;
    int Z;
    GANG NextGang;
    byte Visible;
    char field_13A;
    char field_13B;
    CarModel CarType;
    char Car_remap;
    char field_141;
    char field_142;
    char field_0;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(Gang) == EXPECTED_SIZE, "Size mismatch for Gang");
