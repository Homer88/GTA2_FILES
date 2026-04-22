// Auto-generated structure: DXGI_GAMMA_CONTROL_CAPABILITIES
// Source: DXGI_GAMMA_CONTROL_CAPABILITIES.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DXGI_GAMMA_CONTROL_CAPABILITIES
{
    BOOL ScaleAndOffsetSupported;
    float MaxConvertedValue;
    float MinConvertedValue;
    UINT NumGammaControlPoints;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DXGI_GAMMA_CONTROL_CAPABILITIES) == EXPECTED_SIZE, "Size mismatch for DXGI_GAMMA_CONTROL_CAPABILITIES");
