// Auto-generated structure: _KPROCESS
// Source: _KPROCESS.txt
// Fields count: 13
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KPROCESS
{
    _DISPATCHER_HEADER Header;
    _LIST_ENTRY ProfileListHead;
    _KGDTENTRY LdtDescriptor;
    _KIDTENTRY Int21Descriptor;
    _LIST_ENTRY ThreadListHead;
    _KAFFINITY_EX Affinity;
    _LIST_ENTRY ReadyListHead;
    _SINGLE_LIST_ENTRY SwapListEntry;
    char BasePriority;
    char QuantumReset;
    char Visited;
    _KEXECUTE_OPTIONS Flags;
    _LIST_ENTRY ProcessListEntry;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KPROCESS) == EXPECTED_SIZE, "Size mismatch for _KPROCESS");
