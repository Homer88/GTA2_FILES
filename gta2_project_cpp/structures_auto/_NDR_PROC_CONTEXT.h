// Auto-generated structure: _NDR_PROC_CONTEXT
// Source: _NDR_PROC_CONTEXT.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _NDR_PROC_CONTEXT
{
    SYNTAX_TYPE CurrentSyntaxType;
    _SYNTAX_DISPATCH_TABLE SyntaxDispatch;
    _GUID CurrentActivityID;
    _NDR_ALLOCA_CONTEXT AllocateContext;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_NDR_PROC_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _NDR_PROC_CONTEXT");
