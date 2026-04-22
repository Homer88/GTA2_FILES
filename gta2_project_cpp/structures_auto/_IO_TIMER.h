// Auto-generated structure: _IO_TIMER
// Source: _IO_TIMER.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _IO_TIMER
{
    __int16 Type;
    __int16 TimerFlag;
    _LIST_ENTRY TimerList;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_IO_TIMER) == EXPECTED_SIZE, "Size mismatch for _IO_TIMER");
