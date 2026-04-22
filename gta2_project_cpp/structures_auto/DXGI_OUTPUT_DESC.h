// Auto-generated structure: DXGI_OUTPUT_DESC
// Source: DXGI_OUTPUT_DESC.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DXGI_OUTPUT_DESC
{
    RECT DesktopCoordinates;
    BOOL AttachedToDesktop;
    DXGI_MODE_ROTATION Rotation;
    HMONITOR Monitor;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DXGI_OUTPUT_DESC) == EXPECTED_SIZE, "Size mismatch for DXGI_OUTPUT_DESC");
