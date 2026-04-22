// Auto-generated structure: _DDBLTBATCH
// Source: _DDBLTBATCH.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DDBLTBATCH
{
    LPRECT lprDest;
    LPDIRECTDRAWSURFACE lpDDSSrc;
    LPRECT lprSrc;
    DWORD dwFlags;
    LPDDBLTFX lpDDBltFx;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DDBLTBATCH) == EXPECTED_SIZE, "Size mismatch for _DDBLTBATCH");
