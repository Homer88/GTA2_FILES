// Auto-generated structure: _KSCHEDULING_GROUP
// Source: _KSCHEDULING_GROUP.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KSCHEDULING_GROUP
{
    _KSCHEDULING_GROUP_POLICY Policy;
    __int64 NotificationCycles;
    __int64 MaxQuotaLimitCycles;
    _LIST_ENTRY ChildList;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KSCHEDULING_GROUP) == EXPECTED_SIZE, "Size mismatch for _KSCHEDULING_GROUP");
