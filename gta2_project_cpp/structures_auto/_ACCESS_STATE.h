// Auto-generated structure: _ACCESS_STATE
// Source: _ACCESS_STATE.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ACCESS_STATE
{
    _LUID OperationID;
    _SECURITY_SUBJECT_CONTEXT SubjectSecurityContext;
    _UNICODE_STRING ObjectName;
    _UNICODE_STRING ObjectTypeName;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ACCESS_STATE) == EXPECTED_SIZE, "Size mismatch for _ACCESS_STATE");
