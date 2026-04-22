// Auto-generated structure: tagSTAT_CHUNK
// Source: tagSTAT_CHUNK.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagSTAT_CHUNK
{
    ULONG idChunk;
    CHUNK_BREAKTYPE breakType;
    CHUNKSTATE flags;
    LCID locale;
    FULLPROPSPEC attribute;
    ULONG idChunkSource;
    ULONG cwcStartSource;
    ULONG cwcLenSource;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagSTAT_CHUNK) == EXPECTED_SIZE, "Size mismatch for tagSTAT_CHUNK");
