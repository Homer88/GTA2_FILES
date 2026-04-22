// Auto-generated structure: _D3DPRESENT_PARAMETERS_
// Source: _D3DPRESENT_PARAMETERS_.txt
// Fields count: 14
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _D3DPRESENT_PARAMETERS_
{
    UINT BackBufferWidth;
    UINT BackBufferHeight;
    D3DFORMAT BackBufferFormat;
    UINT BackBufferCount;
    D3DMULTISAMPLE_TYPE MultiSampleType;
    DWORD MultiSampleQuality;
    D3DSWAPEFFECT SwapEffect;
    HWND hDeviceWindow;
    BOOL Windowed;
    BOOL EnableAutoDepthStencil;
    D3DFORMAT AutoDepthStencilFormat;
    DWORD Flags;
    UINT FullScreen_RefreshRateInHz;
    UINT PresentationInterval;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_D3DPRESENT_PARAMETERS_) == EXPECTED_SIZE, "Size mismatch for _D3DPRESENT_PARAMETERS_");
