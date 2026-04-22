// Auto-generated structure: _TIME_ZONE_INFORMATION
// Source: _TIME_ZONE_INFORMATION.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TIME_ZONE_INFORMATION
{
    LONG Bias;
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TIME_ZONE_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _TIME_ZONE_INFORMATION");
