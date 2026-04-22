// Auto-generated structure: _SHRINK_VOLUME_INFORMATION
// Source: _SHRINK_VOLUME_INFORMATION.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SHRINK_VOLUME_INFORMATION
{
    _SHRINK_VOLUME_REQUEST_TYPES ShrinkRequestType;
    __int64 NewNumberOfSectors;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SHRINK_VOLUME_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _SHRINK_VOLUME_INFORMATION");
