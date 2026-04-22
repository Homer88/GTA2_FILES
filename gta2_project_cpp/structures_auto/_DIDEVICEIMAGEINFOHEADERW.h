// Auto-generated structure: _DIDEVICEIMAGEINFOHEADERW
// Source: _DIDEVICEIMAGEINFOHEADERW.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DIDEVICEIMAGEINFOHEADERW
{
    DWORD dwSize;
    DWORD dwSizeImageInfo;
    DWORD dwcViews;
    DWORD dwcButtons;
    DWORD dwcAxes;
    DWORD dwcPOVs;
    DWORD dwBufferSize;
    DWORD dwBufferUsed;
    LPDIDEVICEIMAGEINFOW lprgImageInfoArray;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DIDEVICEIMAGEINFOHEADERW) == EXPECTED_SIZE, "Size mismatch for _DIDEVICEIMAGEINFOHEADERW");
