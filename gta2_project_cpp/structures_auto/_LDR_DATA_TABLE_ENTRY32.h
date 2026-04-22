// Auto-generated structure: _LDR_DATA_TABLE_ENTRY32
// Source: _LDR_DATA_TABLE_ENTRY32.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _LDR_DATA_TABLE_ENTRY32
{
    LIST_ENTRY32 InLoadOrderLinks;
    LIST_ENTRY32 InMemoryOrderLinks;
    LIST_ENTRY32 InInitializationOrderLinks;
    _STRING32 FullDllName;
    _STRING32 BaseDllName;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_LDR_DATA_TABLE_ENTRY32) == EXPECTED_SIZE, "Size mismatch for _LDR_DATA_TABLE_ENTRY32");
