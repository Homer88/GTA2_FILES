// Auto-generated structure: _FSCTL_QUERY_GHOSTED_FILE_EXTENTS_INPUT_RANGE
// Source: _FSCTL_QUERY_GHOSTED_FILE_EXTENTS_INPUT_RANGE.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FSCTL_QUERY_GHOSTED_FILE_EXTENTS_INPUT_RANGE
{
    _LARGE_INTEGER FileOffset;
    _LARGE_INTEGER ByteCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FSCTL_QUERY_GHOSTED_FILE_EXTENTS_INPUT_RANGE) == EXPECTED_SIZE, "Size mismatch for _FSCTL_QUERY_GHOSTED_FILE_EXTENTS_INPUT_RANGE");
