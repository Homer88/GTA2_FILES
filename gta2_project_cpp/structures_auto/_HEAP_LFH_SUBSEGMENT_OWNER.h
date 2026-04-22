// Auto-generated structure: _HEAP_LFH_SUBSEGMENT_OWNER
// Source: _HEAP_LFH_SUBSEGMENT_OWNER.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HEAP_LFH_SUBSEGMENT_OWNER
{
    _LIST_ENTRY AvailableSubsegmentList;
    _LIST_ENTRY FullSubsegmentList;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HEAP_LFH_SUBSEGMENT_OWNER) == EXPECTED_SIZE, "Size mismatch for _HEAP_LFH_SUBSEGMENT_OWNER");
