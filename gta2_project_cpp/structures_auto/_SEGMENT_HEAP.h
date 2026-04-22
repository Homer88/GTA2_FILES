// Auto-generated structure: _SEGMENT_HEAP
// Source: _SEGMENT_HEAP.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SEGMENT_HEAP
{
    RTL_HP_ENV_HANDLE EnvHandle;
    _RTL_RB_TREE LargeAllocMetadata;
    _RTL_RUN_ONCE StackTraceInitVar;
    _HEAP_VS_CONTEXT VsContext;
    _HEAP_LFH_CONTEXT LfhContext;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SEGMENT_HEAP) == EXPECTED_SIZE, "Size mismatch for _SEGMENT_HEAP");
