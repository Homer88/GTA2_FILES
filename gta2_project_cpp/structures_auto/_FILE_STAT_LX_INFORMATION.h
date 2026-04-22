// Auto-generated structure: _FILE_STAT_LX_INFORMATION
// Source: _FILE_STAT_LX_INFORMATION.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FILE_STAT_LX_INFORMATION
{
    _LARGE_INTEGER FileId;
    _LARGE_INTEGER CreationTime;
    _LARGE_INTEGER LastAccessTime;
    _LARGE_INTEGER LastWriteTime;
    _LARGE_INTEGER ChangeTime;
    _LARGE_INTEGER AllocationSize;
    _LARGE_INTEGER EndOfFile;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FILE_STAT_LX_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _FILE_STAT_LX_INFORMATION");
