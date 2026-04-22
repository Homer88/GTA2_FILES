// Auto-generated structure: _DPH_HEAP_ROOT
// Source: _DPH_HEAP_ROOT.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DPH_HEAP_ROOT
{
    _RTL_AVL_TABLE BusyNodesTable;
    _LIST_ENTRY AvailableAllocationHead;
    _LIST_ENTRY NextHeap;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DPH_HEAP_ROOT) == EXPECTED_SIZE, "Size mismatch for _DPH_HEAP_ROOT");
