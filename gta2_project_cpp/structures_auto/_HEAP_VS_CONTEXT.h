// Auto-generated structure: _HEAP_VS_CONTEXT
// Source: _HEAP_VS_CONTEXT.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP_VS_CONTEXT
{
    _RTLP_HP_LOCK_TYPE LockType;
    _RTL_RB_TREE FreeChunkTree;
    _LIST_ENTRY SubsegmentList;
    _HEAP_SUBALLOCATOR_CALLBACKS Callbacks;
    _RTL_HP_VS_CONFIG Config;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP_VS_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _HEAP_VS_CONTEXT");
