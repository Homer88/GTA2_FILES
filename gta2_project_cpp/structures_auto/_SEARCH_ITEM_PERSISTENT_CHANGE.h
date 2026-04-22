// Auto-generated structure: _SEARCH_ITEM_PERSISTENT_CHANGE
// Source: _SEARCH_ITEM_PERSISTENT_CHANGE.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SEARCH_ITEM_PERSISTENT_CHANGE
{
    SEARCH_KIND_OF_CHANGE Change;
    LPWSTR URL;
    LPWSTR OldURL;
    SEARCH_NOTIFICATION_PRIORITY Priority;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SEARCH_ITEM_PERSISTENT_CHANGE) == EXPECTED_SIZE, "Size mismatch for _SEARCH_ITEM_PERSISTENT_CHANGE");
