// Auto-generated structure: IDirect3DVolume9Vtbl
// Source: IDirect3DVolume9Vtbl.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct IDirect3DVolume9Vtbl
{
    LPCWSTR Name;
    UINT Width;
    UINT Height;
    UINT Depth;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    UINT LockCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(IDirect3DVolume9Vtbl) == EXPECTED_SIZE, "Size mismatch for IDirect3DVolume9Vtbl");
