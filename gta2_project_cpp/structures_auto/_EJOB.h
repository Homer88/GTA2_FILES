// Auto-generated structure: _EJOB
// Source: _EJOB.txt
// Fields count: 31
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _EJOB
{
    _KEVENT Event;
    _LIST_ENTRY JobLinks;
    _LIST_ENTRY ProcessListHead;
    _ERESOURCE JobLock;
    _LARGE_INTEGER TotalUserTime;
    _LARGE_INTEGER TotalKernelTime;
    _LARGE_INTEGER TotalCycleTime;
    _LARGE_INTEGER ThisPeriodTotalUserTime;
    _LARGE_INTEGER ThisPeriodTotalKernelTime;
    _LARGE_INTEGER PerProcessUserTimeLimit;
    _LARGE_INTEGER PerJobUserTimeLimit;
    _KAFFINITY_EX Affinity;
    _PROCESS_DISK_COUNTERS DiskIoInfo;
    _KAFFINITY_EX EffectiveAffinity;
    _LARGE_INTEGER EffectivePerProcessUserTimeLimit;
    _JOBOBJECT_WAKE_FILTER WakeFilter;
    _EX_PUSH_LOCK MemoryLimitsLock;
    _LIST_ENTRY SiblingJobLinks;
    _LIST_ENTRY ChildJobListHead;
    _LIST_ENTRY IteratorListHead;
    _EPROCESS_VALUES Accounting;
    _GUID ContainerId;
    _GUID ContainerTelemetryId;
    _PS_PROPERTY_SET PropertySet;
    _JOB_RATE_CONTROL_HEADER IoRateControlHeader;
    _PS_IO_CONTROL_ENTRY GlobalIoControl;
    _RTL_RB_TREE VolumeIoControlTree;
    _EX_PUSH_LOCK IoControlLock;
    int SiloHardReferenceCount;
    _WORK_QUEUE_ITEM RundownWorkItem;
    _JOBOBJECT_ENERGY_TRACKING_STATE EnergyTrackingState;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_EJOB) == EXPECTED_SIZE, "Size mismatch for _EJOB");
