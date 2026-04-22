// Auto-generated structure: _RTL_CRITICAL_SECTION_DEBUG
// Source: _RTL_CRITICAL_SECTION_DEBUG.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_CRITICAL_SECTION_DEBUG
{
    WORD Type;
    WORD CreatorBackTraceIndex;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_CRITICAL_SECTION_DEBUG) == EXPECTED_SIZE, "Size mismatch for _RTL_CRITICAL_SECTION_DEBUG");
