// Auto-generated structure: _KTHREAD
// Source: _KTHREAD.txt
// Fields count: 15
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KTHREAD
{
    _DISPATCHER_HEADER Header;
    _KWAIT_STATUS_REGISTER WaitRegister;
    char Spare12;
    char WaitMode;
    _KTIMER Timer;
    _LIST_ENTRY QueueListEntry;
    int QueuePriority;
    char SuspendCount;
    char Saturation;
    _KEVENT SuspendEvent;
    _LIST_ENTRY ThreadListEntry;
    _LIST_ENTRY MutantListHead;
    char SystemPriority;
    _SINGLE_LIST_ENTRY PropagateBoostsEntry;
    _SINGLE_LIST_ENTRY IoSelfBoostsEntry;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KTHREAD) == EXPECTED_SIZE, "Size mismatch for _KTHREAD");
