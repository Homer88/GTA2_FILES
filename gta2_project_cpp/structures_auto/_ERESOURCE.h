// Auto-generated structure: _ERESOURCE
// Source: _ERESOURCE.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ERESOURCE
{
    _LIST_ENTRY SystemResourcesList;
    __int16 ActiveCount;
    _OWNER_ENTRY OwnerEntry;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ERESOURCE) == EXPECTED_SIZE, "Size mismatch for _ERESOURCE");
