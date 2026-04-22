// Auto-generated structure: _JOBOBJECT_LIMIT_VIOLATION_INFORMATION_V2
// Source: _JOBOBJECT_LIMIT_VIOLATION_INFORMATION_V2.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _JOBOBJECT_LIMIT_VIOLATION_INFORMATION_V2
{
    _LARGE_INTEGER PerJobUserTime;
    _LARGE_INTEGER PerJobUserTimeLimit;
    _JOBOBJECT_RATE_CONTROL_TOLERANCE RateControlTolerance;
    _JOBOBJECT_RATE_CONTROL_TOLERANCE RateControlToleranceLimit;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_JOBOBJECT_LIMIT_VIOLATION_INFORMATION_V2) == EXPECTED_SIZE, "Size mismatch for _JOBOBJECT_LIMIT_VIOLATION_INFORMATION_V2");
