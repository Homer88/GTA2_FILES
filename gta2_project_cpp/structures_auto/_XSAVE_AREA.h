// Auto-generated structure: _XSAVE_AREA
// Source: _XSAVE_AREA.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _XSAVE_AREA
{
    _XSAVE_FORMAT LegacyState;
    _XSAVE_AREA_HEADER Header;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_XSAVE_AREA) == EXPECTED_SIZE, "Size mismatch for _XSAVE_AREA");
