// Auto-generated structure: _NT_TIB
// Source: _NT_TIB.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _NT_TIB
{
    PVOID StackBase;
    PVOID StackLimit;
    PVOID SubSystemTib;
    PVOID FiberData;
    DWORD Version;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_NT_TIB) == EXPECTED_SIZE, "Size mismatch for _NT_TIB");
