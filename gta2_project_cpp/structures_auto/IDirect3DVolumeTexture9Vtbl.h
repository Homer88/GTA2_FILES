// Auto-generated structure: IDirect3DVolumeTexture9Vtbl
// Source: IDirect3DVolumeTexture9Vtbl.txt
// Fields count: 12
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct IDirect3DVolumeTexture9Vtbl
{
    LPCWSTR Name;
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT Levels;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    DWORD Priority;
    DWORD LOD;
    D3DTEXTUREFILTERTYPE FilterType;
    UINT LockCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(IDirect3DVolumeTexture9Vtbl) == EXPECTED_SIZE, "Size mismatch for IDirect3DVolumeTexture9Vtbl");
