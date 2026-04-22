// Auto-generated structure: _SYSTEM_PERFORMANCE_INFORMATION
// Source: _SYSTEM_PERFORMANCE_INFORMATION.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_PERFORMANCE_INFORMATION
{
    _LARGE_INTEGER IdleProcessTime;
    _LARGE_INTEGER IoReadTransferCount;
    _LARGE_INTEGER IoWriteTransferCount;
    _LARGE_INTEGER IoOtherTransferCount;
    __int64 ResidentAvailablePages;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_PERFORMANCE_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_PERFORMANCE_INFORMATION");
