// Auto-generated structure: DXGI_MODE_DESC
// Source: DXGI_MODE_DESC.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DXGI_MODE_DESC
{
    UINT Width;
    UINT Height;
    DXGI_RATIONAL RefreshRate;
    DXGI_FORMAT Format;
    DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
    DXGI_MODE_SCALING Scaling;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DXGI_MODE_DESC) == EXPECTED_SIZE, "Size mismatch for DXGI_MODE_DESC");
