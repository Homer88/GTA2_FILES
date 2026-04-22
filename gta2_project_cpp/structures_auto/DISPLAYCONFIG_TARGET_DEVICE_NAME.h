// Auto-generated structure: DISPLAYCONFIG_TARGET_DEVICE_NAME
// Source: DISPLAYCONFIG_TARGET_DEVICE_NAME.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DISPLAYCONFIG_TARGET_DEVICE_NAME
{
    DISPLAYCONFIG_DEVICE_INFO_HEADER header;
    DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS flags;
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY outputTechnology;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DISPLAYCONFIG_TARGET_DEVICE_NAME) == EXPECTED_SIZE, "Size mismatch for DISPLAYCONFIG_TARGET_DEVICE_NAME");
