// Auto-generated structure: _RTL_STACKDB_CONTEXT
// Source: _RTL_STACKDB_CONTEXT.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_STACKDB_CONTEXT
{
    _RTL_HASH_TABLE StackSegmentTable;
    _RTL_HASH_TABLE StackEntryTable;
    _RTL_SRWLOCK StackEntryTableLock;
    _RTL_SRWLOCK SegmentTableLock;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_STACKDB_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _RTL_STACKDB_CONTEXT");
