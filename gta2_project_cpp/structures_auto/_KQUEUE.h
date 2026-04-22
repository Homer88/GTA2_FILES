// Auto-generated structure: _KQUEUE
// Source: _KQUEUE.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KQUEUE
{
    _DISPATCHER_HEADER Header;
    _LIST_ENTRY EntryListHead;
    _LIST_ENTRY ThreadListHead;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KQUEUE) == EXPECTED_SIZE, "Size mismatch for _KQUEUE");
