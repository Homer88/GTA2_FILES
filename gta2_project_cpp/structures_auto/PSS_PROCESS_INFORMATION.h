// Auto-generated structure: PSS_PROCESS_INFORMATION
// Source: PSS_PROCESS_INFORMATION.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct PSS_PROCESS_INFORMATION
{
    int BasePriority;
    PSS_PROCESS_FLAGS Flags;
    _FILETIME CreateTime;
    _FILETIME ExitTime;
    _FILETIME KernelTime;
    _FILETIME UserTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(PSS_PROCESS_INFORMATION) == EXPECTED_SIZE, "Size mismatch for PSS_PROCESS_INFORMATION");
