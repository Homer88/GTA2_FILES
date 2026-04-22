// Auto-generated structure: _SYSTEM_POWER_POLICY
// Source: _SYSTEM_POWER_POLICY.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_POWER_POLICY
{
    POWER_ACTION_POLICY PowerButton;
    POWER_ACTION_POLICY SleepButton;
    POWER_ACTION_POLICY LidClose;
    _SYSTEM_POWER_STATE LidOpenWake;
    POWER_ACTION_POLICY Idle;
    _SYSTEM_POWER_STATE MinSleep;
    _SYSTEM_POWER_STATE MaxSleep;
    _SYSTEM_POWER_STATE ReducedLatencySleep;
    POWER_ACTION_POLICY OverThrottled;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_POWER_POLICY) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_POWER_POLICY");
