// Auto-generated structure: _NDR_ASYNC_MESSAGE
// Source: _NDR_ASYNC_MESSAGE.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _NDR_ASYNC_MESSAGE
{
    int Version;
    int Signature;
    _Flags Flags;
    _RPC_MESSAGE RpcMsg;
    _MIDL_STUB_MESSAGE StubMsg;
    _NDR_PROC_CONTEXT ProcContext;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_NDR_ASYNC_MESSAGE) == EXPECTED_SIZE, "Size mismatch for _NDR_ASYNC_MESSAGE");
