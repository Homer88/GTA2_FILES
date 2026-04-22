// Auto-generated structure: _RTL_USER_PROCESS_INFORMATION64
// Source: _RTL_USER_PROCESS_INFORMATION64.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_USER_PROCESS_INFORMATION64
{
    __int64 Process;
    __int64 Thread;
    _CLIENT_ID64 ClientId;
    _SECTION_IMAGE_INFORMATION64 ImageInformation;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_USER_PROCESS_INFORMATION64) == EXPECTED_SIZE, "Size mismatch for _RTL_USER_PROCESS_INFORMATION64");
