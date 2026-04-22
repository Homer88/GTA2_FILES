// Auto-generated structure: _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
// Source: _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
{
    _LARGE_INTEGER TotalUserTime;
    _LARGE_INTEGER TotalKernelTime;
    _LARGE_INTEGER ThisPeriodTotalUserTime;
    _LARGE_INTEGER ThisPeriodTotalKernelTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION");
