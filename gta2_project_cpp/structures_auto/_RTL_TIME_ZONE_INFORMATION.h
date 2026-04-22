// Auto-generated structure: _RTL_TIME_ZONE_INFORMATION
// Source: _RTL_TIME_ZONE_INFORMATION.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_TIME_ZONE_INFORMATION
{
    int Bias;
    _TIME_FIELDS StandardStart;
    int StandardBias;
    _TIME_FIELDS DaylightStart;
    int DaylightBias;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_TIME_ZONE_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _RTL_TIME_ZONE_INFORMATION");
