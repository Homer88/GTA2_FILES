// Auto-generated structure: _PROCESSOR_POWER_STATE
// Source: _PROCESSOR_POWER_STATE.txt
// Fields count: 10
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _PROCESSOR_POWER_STATE
{
    _PROC_IDLE_POLICY IdlePolicy;
    _PROC_FEEDBACK PerfFeedback;
    _PROC_HYPERVISOR_STATE Hypervisor;
    int WmiInterfaceEnabled;
    _PPM_FFH_THROTTLE_STATE_INFO FFHThrottleStateInfo;
    _KDPC PerfActionDpc;
    _PROC_IDLE_SNAP HvIdleCheck;
    _PROC_PERF_CHECK_CONTEXT CheckContext;
    _KHETERO_CPU_QOS RequestedQosClass;
    _KHETERO_CPU_QOS ResolvedQosClass;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_PROCESSOR_POWER_STATE) == EXPECTED_SIZE, "Size mismatch for _PROCESSOR_POWER_STATE");
