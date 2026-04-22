// Auto-generated structure: _EXTENT_READ_CACHE_INFO_BUFFER
// Source: _EXTENT_READ_CACHE_INFO_BUFFER.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _EXTENT_READ_CACHE_INFO_BUFFER
{
    _LARGE_INTEGER AllocatedCache;
    _LARGE_INTEGER PopulatedCache;
    _LARGE_INTEGER InErrorCache;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_EXTENT_READ_CACHE_INFO_BUFFER) == EXPECTED_SIZE, "Size mismatch for _EXTENT_READ_CACHE_INFO_BUFFER");
