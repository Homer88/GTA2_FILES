// Auto-generated structure: USN_JOURNAL_DATA_V0
// Source: USN_JOURNAL_DATA_V0.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct USN_JOURNAL_DATA_V0
{
    __int64 FirstUsn;
    __int64 NextUsn;
    __int64 LowestValidUsn;
    __int64 MaxUsn;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(USN_JOURNAL_DATA_V0) == EXPECTED_SIZE, "Size mismatch for USN_JOURNAL_DATA_V0");
