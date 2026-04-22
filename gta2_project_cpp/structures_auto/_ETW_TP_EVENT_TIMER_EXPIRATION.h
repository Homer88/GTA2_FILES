// Auto-generated structure: _ETW_TP_EVENT_TIMER_EXPIRATION
// Source: _ETW_TP_EVENT_TIMER_EXPIRATION.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ETW_TP_EVENT_TIMER_EXPIRATION
{
    _SYSTEM_TRACE_HEADER Header;
    __int64 DueTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ETW_TP_EVENT_TIMER_EXPIRATION) == EXPECTED_SIZE, "Size mismatch for _ETW_TP_EVENT_TIMER_EXPIRATION");
