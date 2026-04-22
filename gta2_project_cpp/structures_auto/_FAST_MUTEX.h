// Auto-generated structure: _FAST_MUTEX
// Source: _FAST_MUTEX.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FAST_MUTEX
{
    int Count;
    _KEVENT Event;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FAST_MUTEX) == EXPECTED_SIZE, "Size mismatch for _FAST_MUTEX");
