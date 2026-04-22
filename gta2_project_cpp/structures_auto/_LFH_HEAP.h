// Auto-generated structure: _LFH_HEAP
// Source: _LFH_HEAP.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _LFH_HEAP
{
    _RTL_SRWLOCK Lock;
    _LIST_ENTRY SubSegmentZones;
    _HEAP_LFH_MEM_POLICIES MemoryPolicies;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_LFH_HEAP) == EXPECTED_SIZE, "Size mismatch for _LFH_HEAP");
