// Auto-generated structure: _JOURNAL_TRANSACTION_BOUNDARY_INFORMATION
// Source: _JOURNAL_TRANSACTION_BOUNDARY_INFORMATION.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _JOURNAL_TRANSACTION_BOUNDARY_INFORMATION
{
    _JOURNAL_CHANGE_INFORMATION_CLASS Action;
    _LARGE_INTEGER TimeStamp;
    _GUID TransactionID;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_JOURNAL_TRANSACTION_BOUNDARY_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _JOURNAL_TRANSACTION_BOUNDARY_INFORMATION");
