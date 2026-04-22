// Auto-generated structure: _SYSTEM_TIMEOFDAY_INFORMATION
// Source: _SYSTEM_TIMEOFDAY_INFORMATION.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_TIMEOFDAY_INFORMATION
{
    _LARGE_INTEGER BootTime;
    _LARGE_INTEGER CurrentTime;
    _LARGE_INTEGER TimeZoneBias;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_TIMEOFDAY_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_TIMEOFDAY_INFORMATION");
