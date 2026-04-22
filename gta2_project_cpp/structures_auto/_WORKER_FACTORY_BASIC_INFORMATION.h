// Auto-generated structure: _WORKER_FACTORY_BASIC_INFORMATION
// Source: _WORKER_FACTORY_BASIC_INFORMATION.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WORKER_FACTORY_BASIC_INFORMATION
{
    _LARGE_INTEGER Timeout;
    _LARGE_INTEGER RetryTimeout;
    _LARGE_INTEGER IdleTimeout;
    __int64 InfiniteWaitGoal;
    int LastThreadCreationStatus;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WORKER_FACTORY_BASIC_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _WORKER_FACTORY_BASIC_INFORMATION");
