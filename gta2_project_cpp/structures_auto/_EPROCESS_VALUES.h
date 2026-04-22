// Auto-generated structure: _EPROCESS_VALUES
// Source: _EPROCESS_VALUES.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _EPROCESS_VALUES
{
    __int64 ReadOperationCount;
    __int64 WriteOperationCount;
    __int64 OtherOperationCount;
    __int64 ReadTransferCount;
    __int64 WriteTransferCount;
    __int64 OtherTransferCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_EPROCESS_VALUES) == EXPECTED_SIZE, "Size mismatch for _EPROCESS_VALUES");
