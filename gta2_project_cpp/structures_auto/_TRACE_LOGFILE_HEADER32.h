// Auto-generated structure: _TRACE_LOGFILE_HEADER32
// Source: _TRACE_LOGFILE_HEADER32.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TRACE_LOGFILE_HEADER32
{
    _LARGE_INTEGER EndTime;
    _TIME_ZONE_INFORMATION TimeZone;
    _LARGE_INTEGER BootTime;
    _LARGE_INTEGER PerfFreq;
    _LARGE_INTEGER StartTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TRACE_LOGFILE_HEADER32) == EXPECTED_SIZE, "Size mismatch for _TRACE_LOGFILE_HEADER32");
