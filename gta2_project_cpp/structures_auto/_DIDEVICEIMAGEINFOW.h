// Auto-generated structure: _DIDEVICEIMAGEINFOW
// Source: _DIDEVICEIMAGEINFOW.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DIDEVICEIMAGEINFOW
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
// static_assert(sizeof(_DIDEVICEIMAGEINFOW) == EXPECTED_SIZE, "Size mismatch for _DIDEVICEIMAGEINFOW");
