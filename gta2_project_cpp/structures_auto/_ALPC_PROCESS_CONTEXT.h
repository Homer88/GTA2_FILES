// Auto-generated structure: _ALPC_PROCESS_CONTEXT
// Source: _ALPC_PROCESS_CONTEXT.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ALPC_PROCESS_CONTEXT
{
    _EX_PUSH_LOCK Lock;
    _LIST_ENTRY ViewListHead;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ALPC_PROCESS_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _ALPC_PROCESS_CONTEXT");
