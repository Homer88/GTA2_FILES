// Auto-generated structure: _DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO
// Source: _DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO
{
    DISPLAYCONFIG_DEVICE_INFO_HEADER header;
    _DISPLAYCONFIG_COLOR_ENCODING colorEncoding;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO) == EXPECTED_SIZE, "Size mismatch for _DISPLAYCONFIG_GET_ADVANCED_COLOR_INFO");
