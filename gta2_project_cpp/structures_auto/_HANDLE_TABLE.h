// Auto-generated structure: _HANDLE_TABLE
// Source: _HANDLE_TABLE.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HANDLE_TABLE
{
    int ExtraInfoPages;
    _LIST_ENTRY HandleTableList;
    _EX_PUSH_LOCK HandleContentionEvent;
    _EX_PUSH_LOCK HandleTableLock;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HANDLE_TABLE) == EXPECTED_SIZE, "Size mismatch for _HANDLE_TABLE");
