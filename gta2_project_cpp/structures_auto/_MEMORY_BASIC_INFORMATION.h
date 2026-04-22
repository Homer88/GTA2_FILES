// Auto-generated structure: _MEMORY_BASIC_INFORMATION
// Source: _MEMORY_BASIC_INFORMATION.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _MEMORY_BASIC_INFORMATION
{
    PVOID BaseAddress;
    PVOID AllocationBase;
    DWORD AllocationProtect;
    SIZE_T RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_MEMORY_BASIC_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _MEMORY_BASIC_INFORMATION");
