// Auto-generated structure: DISPLAYCONFIG_PATH_TARGET_INFO
// Source: DISPLAYCONFIG_PATH_TARGET_INFO.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DISPLAYCONFIG_PATH_TARGET_INFO
{
    _LUID adapterId;
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY outputTechnology;
    DISPLAYCONFIG_ROTATION rotation;
    DISPLAYCONFIG_SCALING scaling;
    DISPLAYCONFIG_RATIONAL refreshRate;
    DISPLAYCONFIG_SCANLINE_ORDERING scanLineOrdering;
    int targetAvailable;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DISPLAYCONFIG_PATH_TARGET_INFO) == EXPECTED_SIZE, "Size mismatch for DISPLAYCONFIG_PATH_TARGET_INFO");
