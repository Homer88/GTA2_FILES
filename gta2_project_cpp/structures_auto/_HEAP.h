// Auto-generated structure: _HEAP
// Source: _HEAP.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP
{
    _HEAP_ENTRY Encoding;
    _LIST_ENTRY UCRList;
    _LIST_ENTRY VirtualAllocdBlocks;
    _LIST_ENTRY SegmentList;
    _LIST_ENTRY FreeLists;
    _RTL_RUN_ONCE StackTraceInitVar;
    _RTL_HEAP_MEMORY_LIMIT_DATA CommitLimitData;
    _HEAP_COUNTERS Counters;
    _HEAP_TUNING_PARAMETERS TuningParameters;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP) == EXPECTED_SIZE, "Size mismatch for _HEAP");
