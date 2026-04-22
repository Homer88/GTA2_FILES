// Auto-generated structure: CONFIRM_CONFLICT_ITEM
// Source: CONFIRM_CONFLICT_ITEM.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct CONFIRM_CONFLICT_ITEM
{
    LPWSTR pszOriginalName;
    LPWSTR pszAlternateName;
    LPWSTR pszLocationShort;
    LPWSTR pszLocationFull;
    SYNCMGR_CONFLICT_ITEM_TYPE nType;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(CONFIRM_CONFLICT_ITEM) == EXPECTED_SIZE, "Size mismatch for CONFIRM_CONFLICT_ITEM");
