// Auto-generated structure: _LDR_DDAG_NODE
// Source: _LDR_DDAG_NODE.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _LDR_DDAG_NODE
{
    _LIST_ENTRY Modules;
    _LDRP_CSLIST Dependencies;
    _LDRP_CSLIST IncomingDependencies;
    _LDR_DDAG_STATE State;
    _SINGLE_LIST_ENTRY CondenseLink;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_LDR_DDAG_NODE) == EXPECTED_SIZE, "Size mismatch for _LDR_DDAG_NODE");
