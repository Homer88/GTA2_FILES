// Auto-generated structure: _RDR_CALLOUT_STATE
// Source: _RDR_CALLOUT_STATE.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RDR_CALLOUT_STATE
{
    int LastError;
    _RPC_HTTP_REDIRECTOR_STAGE LastCalledStage;
    _GUID ResourceType;
    _GUID SessionId;
    _RPC_SYNTAX_IDENTIFIER Interface;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RDR_CALLOUT_STATE) == EXPECTED_SIZE, "Size mismatch for _RDR_CALLOUT_STATE");
