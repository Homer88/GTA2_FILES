// Auto-generated structure: _ETW_PRIORITY_EVENT
// Source: _ETW_PRIORITY_EVENT.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ETW_PRIORITY_EVENT
{
    char OldPriority;
    char NewPriority;
    char DynamicPriority;
    char Reserved;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ETW_PRIORITY_EVENT) == EXPECTED_SIZE, "Size mismatch for _ETW_PRIORITY_EVENT");
