// Auto-generated structure: _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER
// Source: _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER
{
    _LARGE_INTEGER DirectoryCount;
    _LARGE_INTEGER FileCount;
    _LARGE_INTEGER FormatTime;
    _LARGE_INTEGER LastUpdateTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FILE_QUERY_ON_DISK_VOL_INFO_BUFFER) == EXPECTED_SIZE, "Size mismatch for _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER");
