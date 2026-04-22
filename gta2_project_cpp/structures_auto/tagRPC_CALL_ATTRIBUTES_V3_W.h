// Auto-generated structure: tagRPC_CALL_ATTRIBUTES_V3_W
// Source: tagRPC_CALL_ATTRIBUTES_V3_W.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagRPC_CALL_ATTRIBUTES_V3_W
{
    int NullSession;
    int KernelModeCaller;
    tagRpcCallClientLocality IsClientLocal;
    tagRpcCallType CallType;
    _GUID InterfaceUuid;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagRPC_CALL_ATTRIBUTES_V3_W) == EXPECTED_SIZE, "Size mismatch for tagRPC_CALL_ATTRIBUTES_V3_W");
