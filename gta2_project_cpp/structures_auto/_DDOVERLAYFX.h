// Auto-generated structure: _DDOVERLAYFX
// Source: _DDOVERLAYFX.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DDOVERLAYFX
{
    DWORD dwSize;
    DWORD dwAlphaEdgeBlendBitDepth;
    DWORD dwAlphaEdgeBlend;
    DWORD dwReserved;
    DWORD dwAlphaDestConstBitDepth;
    DWORD dwAlphaDestConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaDest;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DDOVERLAYFX) == EXPECTED_SIZE, "Size mismatch for _DDOVERLAYFX");
