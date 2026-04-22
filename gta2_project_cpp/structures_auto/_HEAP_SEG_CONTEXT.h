// Auto-generated structure: _HEAP_SEG_CONTEXT
// Source: _HEAP_SEG_CONTEXT.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP_SEG_CONTEXT
{
    __int16 OlpStatsOffset;
    __int16 MemStatsOffset;
    RTL_HP_ENV_HANDLE EnvHandle;
    _LIST_ENTRY SegmentListHead;
    _RTL_RB_TREE FreePageRanges;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP_SEG_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _HEAP_SEG_CONTEXT");
