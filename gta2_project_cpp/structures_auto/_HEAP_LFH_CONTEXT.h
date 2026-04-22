// Auto-generated structure: _HEAP_LFH_CONTEXT
// Source: _HEAP_LFH_CONTEXT.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP_LFH_CONTEXT
{
    _HEAP_SUBALLOCATOR_CALLBACKS Callbacks;
    __int16 MemStatsOffset;
    _RTL_HP_LFH_CONFIG Config;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP_LFH_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _HEAP_LFH_CONTEXT");
