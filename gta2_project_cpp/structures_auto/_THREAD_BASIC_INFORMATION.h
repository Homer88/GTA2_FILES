// Auto-generated structure: _THREAD_BASIC_INFORMATION
// Source: _THREAD_BASIC_INFORMATION.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _THREAD_BASIC_INFORMATION
{
    int ExitStatus;
    _CLIENT_ID ClientId;
    int Priority;
    int BasePriority;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_THREAD_BASIC_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _THREAD_BASIC_INFORMATION");
