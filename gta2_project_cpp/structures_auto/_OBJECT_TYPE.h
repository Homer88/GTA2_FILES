// Auto-generated structure: _OBJECT_TYPE
// Source: _OBJECT_TYPE.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OBJECT_TYPE
{
    _LIST_ENTRY TypeList;
    _UNICODE_STRING Name;
    _OBJECT_TYPE_INITIALIZER TypeInfo;
    _EX_PUSH_LOCK TypeLock;
    _LIST_ENTRY CallbackList;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OBJECT_TYPE) == EXPECTED_SIZE, "Size mismatch for _OBJECT_TYPE");
