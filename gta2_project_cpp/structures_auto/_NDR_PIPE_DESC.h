// Auto-generated structure: _NDR_PIPE_DESC
// Source: _NDR_PIPE_DESC.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _NDR_PIPE_DESC
{
    __int16 CurrentPipe;
    __int16 PrevPipe;
    __int16 InPipes;
    __int16 OutPipes;
    __int16 TotalPipes;
    __int16 PipeVersion;
    _PIPEDESC_FLAGS Flags;
    NDR_PIPE_STATE RuntimeState;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_NDR_PIPE_DESC) == EXPECTED_SIZE, "Size mismatch for _NDR_PIPE_DESC");
