// Auto-generated structure: IDirect3DCubeTexture9Vtbl
// Source: IDirect3DCubeTexture9Vtbl.txt
// Fields count: 11
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct IDirect3DCubeTexture9Vtbl
{
    LPCWSTR Name;
    UINT Width;
    UINT Height;
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
// static_assert(sizeof(IDirect3DCubeTexture9Vtbl) == EXPECTED_SIZE, "Size mismatch for IDirect3DCubeTexture9Vtbl");
