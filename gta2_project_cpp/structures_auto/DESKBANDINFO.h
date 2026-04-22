// Auto-generated structure: DESKBANDINFO
// Source: DESKBANDINFO.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DESKBANDINFO
{
    DWORD dwMask;
    POINTL ptMinSize;
    POINTL ptMaxSize;
    POINTL ptIntegral;
    POINTL ptActual;
    DWORD dwModeFlags;
    COLORREF crBkgnd;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DESKBANDINFO) == EXPECTED_SIZE, "Size mismatch for DESKBANDINFO");
