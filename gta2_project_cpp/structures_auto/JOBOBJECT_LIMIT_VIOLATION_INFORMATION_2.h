// Auto-generated structure: JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2
// Source: JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2
{
    _LARGE_INTEGER PerJobUserTime;
    _LARGE_INTEGER PerJobUserTimeLimit;
    _JOBOBJECT_RATE_CONTROL_TOLERANCE IoRateControlTolerance;
    _JOBOBJECT_RATE_CONTROL_TOLERANCE IoRateControlToleranceLimit;
    _JOBOBJECT_RATE_CONTROL_TOLERANCE NetRateControlTolerance;
    _JOBOBJECT_RATE_CONTROL_TOLERANCE NetRateControlToleranceLimit;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2) == EXPECTED_SIZE, "Size mismatch for JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2");
