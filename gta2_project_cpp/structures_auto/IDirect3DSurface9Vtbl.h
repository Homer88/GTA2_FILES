// Auto-generated structure: IDirect3DSurface9Vtbl
// Source: IDirect3DSurface9Vtbl.txt
// Fields count: 11
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct IDirect3DSurface9Vtbl
{
    LPCWSTR Name;
    UINT Width;
    UINT Height;
    DWORD Usage;
    D3DFORMAT Format;
    D3DPOOL Pool;
    D3DMULTISAMPLE_TYPE MultiSampleType;
    DWORD MultiSampleQuality;
    DWORD Priority;
    UINT LockCount;
    UINT DCCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(IDirect3DSurface9Vtbl) == EXPECTED_SIZE, "Size mismatch for IDirect3DSurface9Vtbl");
