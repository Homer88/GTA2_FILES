// Auto-generated structure: _DIDEVICEIMAGEINFOA
// Source: _DIDEVICEIMAGEINFOA.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DIDEVICEIMAGEINFOA
{
    DWORD dwFlags;
    DWORD dwViewID;
    RECT rcOverlay;
    DWORD dwObjID;
    DWORD dwcValidPts;
    RECT rcCalloutRect;
    DWORD dwTextAlign;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DIDEVICEIMAGEINFOA) == EXPECTED_SIZE, "Size mismatch for _DIDEVICEIMAGEINFOA");
