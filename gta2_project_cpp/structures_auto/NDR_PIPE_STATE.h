// Auto-generated structure: NDR_PIPE_STATE
// Source: NDR_PIPE_STATE.txt
// Fields count: 14
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct NDR_PIPE_STATE
{
    int CurrentState;
    int TotalElemsCount;
    int OrigElemsInChunk;
    int ElemsInChunk;
    int ElemAlign;
    int ElemWireSize;
    int ElemMemSize;
    int PartialBufferSize;
    int PartialElemSize;
    int PartialOffset;
    int LowChunkLimit;
    int HighChunkLimit;
    int fBlockCopy;
    int ElemPad;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(NDR_PIPE_STATE) == EXPECTED_SIZE, "Size mismatch for NDR_PIPE_STATE");
