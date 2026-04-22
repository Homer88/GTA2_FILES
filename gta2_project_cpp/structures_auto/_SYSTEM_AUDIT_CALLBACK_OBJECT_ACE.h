// Auto-generated structure: _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE
// Source: _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE
{
    _ACE_HEADER Header;
    _GUID ObjectType;
    _GUID InheritedObjectType;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_AUDIT_CALLBACK_OBJECT_ACE) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE");
