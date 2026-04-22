// Auto-generated structure: _D3DDEVICE_CREATION_PARAMETERS
// Source: _D3DDEVICE_CREATION_PARAMETERS.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _D3DDEVICE_CREATION_PARAMETERS
{
    UINT AdapterOrdinal;
    D3DDEVTYPE DeviceType;
    HWND hFocusWindow;
    DWORD BehaviorFlags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_D3DDEVICE_CREATION_PARAMETERS) == EXPECTED_SIZE, "Size mismatch for _D3DDEVICE_CREATION_PARAMETERS");
