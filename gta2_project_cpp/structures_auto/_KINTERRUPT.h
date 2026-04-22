// Auto-generated structure: _KINTERRUPT
// Source: _KINTERRUPT.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KINTERRUPT
{
    __int16 Type;
    __int16 Size;
    _LIST_ENTRY InterruptListEntry;
    int InternalState;
    _KINTERRUPT_MODE Mode;
    _KINTERRUPT_POLARITY Polarity;
    _ISRDPCSTATS IsrDpcStats;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KINTERRUPT) == EXPECTED_SIZE, "Size mismatch for _KINTERRUPT");
