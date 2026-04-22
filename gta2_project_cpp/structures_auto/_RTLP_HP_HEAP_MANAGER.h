// Auto-generated structure: _RTLP_HP_HEAP_MANAGER
// Source: _RTLP_HP_HEAP_MANAGER.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTLP_HP_HEAP_MANAGER
{
    _RTLP_HP_ALLOC_TRACKER AllocTracker;
    _HEAP_VAMGR_CTX VaMgr;
    _RTL_HP_SUB_ALLOCATOR_CONFIGS SubAllocConfigs;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTLP_HP_HEAP_MANAGER) == EXPECTED_SIZE, "Size mismatch for _RTLP_HP_HEAP_MANAGER");
