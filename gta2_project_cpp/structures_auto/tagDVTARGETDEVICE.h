// Auto-generated structure: tagDVTARGETDEVICE
// Source: tagDVTARGETDEVICE.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagDVTARGETDEVICE
{
    DWORD tdSize;
    WORD tdDriverNameOffset;
    WORD tdDeviceNameOffset;
    WORD tdPortNameOffset;
    WORD tdExtDevmodeOffset;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagDVTARGETDEVICE) == EXPECTED_SIZE, "Size mismatch for tagDVTARGETDEVICE");
