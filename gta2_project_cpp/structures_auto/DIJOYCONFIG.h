// Auto-generated structure: DIJOYCONFIG
// Source: DIJOYCONFIG.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DIJOYCONFIG
{
    DWORD dwSize;
    GUID guidInstance;
    JOYREGHWCONFIG hwc;
    DWORD dwGain;
    GUID guidGameport;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DIJOYCONFIG) == EXPECTED_SIZE, "Size mismatch for DIJOYCONFIG");
