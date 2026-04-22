// Auto-generated structure: _DIDEVICEIMAGEINFOHEADERA
// Source: _DIDEVICEIMAGEINFOHEADERA.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DIDEVICEIMAGEINFOHEADERA
{
    DWORD dwSize;
    DWORD dwSizeImageInfo;
    DWORD dwcViews;
    DWORD dwcButtons;
    DWORD dwcAxes;
    DWORD dwcPOVs;
    DWORD dwBufferSize;
    DWORD dwBufferUsed;
    LPDIDEVICEIMAGEINFOA lprgImageInfoArray;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DIDEVICEIMAGEINFOHEADERA) == EXPECTED_SIZE, "Size mismatch for _DIDEVICEIMAGEINFOHEADERA");
