// Auto-generated structure: _TIMEZONE_CHANGE_EVENT
// Source: _TIMEZONE_CHANGE_EVENT.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TIMEZONE_CHANGE_EVENT
{
    _KDPC Dpc;
    _KTIMER Timer;
    _WORK_QUEUE_ITEM WorkItem;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TIMEZONE_CHANGE_EVENT) == EXPECTED_SIZE, "Size mismatch for _TIMEZONE_CHANGE_EVENT");
