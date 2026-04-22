// Auto-generated structure: _INTERRUPT_VECTOR_DATA
// Source: _INTERRUPT_VECTOR_DATA.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _INTERRUPT_VECTOR_DATA
{
    INTERRUPT_CONNECTION_TYPE Type;
    _KINTERRUPT_POLARITY Polarity;
    _KINTERRUPT_MODE Mode;
    _GROUP_AFFINITY TargetProcessors;
    _INTERRUPT_REMAPPING_INFO IntRemapInfo;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_INTERRUPT_VECTOR_DATA) == EXPECTED_SIZE, "Size mismatch for _INTERRUPT_VECTOR_DATA");
