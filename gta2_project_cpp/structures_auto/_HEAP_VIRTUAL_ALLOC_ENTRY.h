// Auto-generated structure: _HEAP_VIRTUAL_ALLOC_ENTRY
// Source: _HEAP_VIRTUAL_ALLOC_ENTRY.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP_VIRTUAL_ALLOC_ENTRY
{
    _LIST_ENTRY Entry;
    _HEAP_ENTRY_EXTRA ExtraStuff;
    _HEAP_ENTRY BusyBlock;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP_VIRTUAL_ALLOC_ENTRY) == EXPECTED_SIZE, "Size mismatch for _HEAP_VIRTUAL_ALLOC_ENTRY");
