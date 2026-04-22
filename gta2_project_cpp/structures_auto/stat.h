// Auto-generated structure: stat
// Source: stat.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct stat
{
    __int16 st_nlink;
    __int16 st_uid;
    __int16 st_gid;
    int st_size;
    int st_atime;
    int st_mtime;
    int st_ctime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(stat) == EXPECTED_SIZE, "Size mismatch for stat");
