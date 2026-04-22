// Auto-generated structure: _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX
// Source: _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX
{
    _LARGE_INTEGER IdleTime;
    _LARGE_INTEGER KernelTime;
    _LARGE_INTEGER UserTime;
    _LARGE_INTEGER DpcTime;
    _LARGE_INTEGER InterruptTime;
    _LARGE_INTEGER AvailableTime;
    _LARGE_INTEGER Spare1;
    _LARGE_INTEGER Spare2;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX");
