// Auto-generated structure: _D3DSURFACE_DESC
// Source: _D3DSURFACE_DESC.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _D3DSURFACE_DESC
{
    D3DFORMAT Format;
    D3DRESOURCETYPE Type;
    DWORD Usage;
    D3DPOOL Pool;
    D3DMULTISAMPLE_TYPE MultiSampleType;
    DWORD MultiSampleQuality;
    UINT Width;
    UINT Height;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_D3DSURFACE_DESC) == EXPECTED_SIZE, "Size mismatch for _D3DSURFACE_DESC");
