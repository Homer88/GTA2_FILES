// Auto-generated structure: DXGI_ADAPTER_DESC
// Source: DXGI_ADAPTER_DESC.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DXGI_ADAPTER_DESC
{
    UINT VendorId;
    UINT DeviceId;
    UINT SubSysId;
    UINT Revision;
    SIZE_T DedicatedVideoMemory;
    SIZE_T DedicatedSystemMemory;
    SIZE_T SharedSystemMemory;
    LUID AdapterLuid;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DXGI_ADAPTER_DESC) == EXPECTED_SIZE, "Size mismatch for DXGI_ADAPTER_DESC");
