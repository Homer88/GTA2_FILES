// Auto-generated structure: _HEAP_SEGMENT
// Source: _HEAP_SEGMENT.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP_SEGMENT
{
    _HEAP_ENTRY Entry;
    _LIST_ENTRY SegmentListEntry;
    _LIST_ENTRY UCRSegmentList;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP_SEGMENT) == EXPECTED_SIZE, "Size mismatch for _HEAP_SEGMENT");
