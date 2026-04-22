// Auto-generated structure: _KPRCB
// Source: _KPRCB.txt
// Fields count: 38
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KPRCB
{
    char CpuType;
    char CpuID;
    _KPROCESSOR_STATE ProcessorState;
    _KPRCBFLAG PrcbFlags;
    _LARGE_INTEGER IoReadTransferCount;
    _LARGE_INTEGER IoWriteTransferCount;
    _LARGE_INTEGER IoOtherTransferCount;
    int MaximumDpcQueueDepth;
    _KGATE DpcGate;
    _KTIMER_TABLE TimerTable;
    _KDPC CallDpc;
    int ClockKeepAlive;
    int DpcWatchdogPeriod;
    int DpcWatchdogCount;
    _SINGLE_LIST_ENTRY DeferredReadyListHead;
    int AffinitizedSelectionMask;
    _LIST_ENTRY WaitListHead;
    int LookasideIrpFloat;
    _RTL_RB_TREE ScbQueue;
    _LIST_ENTRY ScbList;
    _LARGE_INTEGER UpdateSignature;
    _PROCESSOR_POWER_STATE PowerState;
    _KDPC ForceIdleDpc;
    _KDPC DpcWatchdogDpc;
    _KTIMER DpcWatchdogTimer;
    _SLIST_HEADER HypercallPageList;
    _KAFFINITY_EX PackageProcessorSet;
    _SLIST_HEADER InterruptObjectPool;
    _KDPC TimerExpirationDpc;
    _SYNCH_COUNTERS SynchCounters;
    _FILESYSTEM_DISK_COUNTERS FsCounters;
    _KENTROPY_TIMING_STATE EntropyTimingState;
    _SINGLE_LIST_ENTRY AbSelfIoBoostsList;
    _SINGLE_LIST_ENTRY AbPropagateBoostsList;
    _KDPC AbDpc;
    _IOP_IRP_STACK_PROFILER IoIrpStackProfilerCurrent;
    _IOP_IRP_STACK_PROFILER IoIrpStackProfilerPrevious;
    _KSHARED_READY_QUEUE LocalSharedReadyQueue;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KPRCB) == EXPECTED_SIZE, "Size mismatch for _KPRCB");
