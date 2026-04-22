// Auto-generated structure: _GENERAL_LOOKASIDE_POOL
// Source: _GENERAL_LOOKASIDE_POOL.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _GENERAL_LOOKASIDE_POOL
{
    _POOL_TYPE Type;
    _LIST_ENTRY ListEntry;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_GENERAL_LOOKASIDE_POOL) == EXPECTED_SIZE, "Size mismatch for _GENERAL_LOOKASIDE_POOL");
