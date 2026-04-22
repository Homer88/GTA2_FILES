// Auto-generated structure: _stat64i32
// Source: _stat64i32.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _stat64i32
{
    __int16 st_nlink;
    __int16 st_uid;
    __int16 st_gid;
    int st_size;
    __int64 st_atime;
    __int64 st_mtime;
    __int64 st_ctime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_stat64i32) == EXPECTED_SIZE, "Size mismatch for _stat64i32");
