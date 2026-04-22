// Auto-generated structure: _KTIMER
// Source: _KTIMER.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KTIMER
{
    _DISPATCHER_HEADER Header;
    _ULARGE_INTEGER DueTime;
    _LIST_ENTRY TimerListEntry;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KTIMER) == EXPECTED_SIZE, "Size mismatch for _KTIMER");
