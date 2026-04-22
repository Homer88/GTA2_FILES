// Auto-generated structure: _MULTI_TIME
// Source: _MULTI_TIME.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _MULTI_TIME
{
    _LARGE_INTEGER Qpc;
    _LARGE_INTEGER HostQpc;
    __int64 SystemTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_MULTI_TIME) == EXPECTED_SIZE, "Size mismatch for _MULTI_TIME");
