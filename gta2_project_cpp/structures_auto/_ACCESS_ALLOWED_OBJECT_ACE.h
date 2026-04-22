// Auto-generated structure: _ACCESS_ALLOWED_OBJECT_ACE
// Source: _ACCESS_ALLOWED_OBJECT_ACE.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ACCESS_ALLOWED_OBJECT_ACE
{
    _ACE_HEADER Header;
    _GUID ObjectType;
    _GUID InheritedObjectType;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ACCESS_ALLOWED_OBJECT_ACE) == EXPECTED_SIZE, "Size mismatch for _ACCESS_ALLOWED_OBJECT_ACE");
