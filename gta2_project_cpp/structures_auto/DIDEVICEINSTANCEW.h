// Auto-generated structure: DIDEVICEINSTANCEW
// Source: DIDEVICEINSTANCEW.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DIDEVICEINSTANCEW
{
    DWORD dwSize;
    GUID guidInstance;
    GUID guidProduct;
    DWORD dwDevType;
    GUID guidFFDriver;
    WORD wUsagePage;
    WORD wUsage;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DIDEVICEINSTANCEW) == EXPECTED_SIZE, "Size mismatch for DIDEVICEINSTANCEW");
