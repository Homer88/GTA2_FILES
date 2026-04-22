// Auto-generated structure: tagCStdAsyncProxyBuffer
// Source: tagCStdAsyncProxyBuffer.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagCStdAsyncProxyBuffer
{
    int RefCount;
    _CStdProxyBufferMap map;
    _GUID iidBase;
    _NdrDcomAsyncCallState CallState;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagCStdAsyncProxyBuffer) == EXPECTED_SIZE, "Size mismatch for tagCStdAsyncProxyBuffer");
