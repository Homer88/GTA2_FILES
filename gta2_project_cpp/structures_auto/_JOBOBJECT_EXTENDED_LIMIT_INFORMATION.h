// Auto-generated structure: _JOBOBJECT_EXTENDED_LIMIT_INFORMATION
// Source: _JOBOBJECT_EXTENDED_LIMIT_INFORMATION.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _JOBOBJECT_EXTENDED_LIMIT_INFORMATION
{
    _JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
    _IO_COUNTERS IoInfo;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_JOBOBJECT_EXTENDED_LIMIT_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _JOBOBJECT_EXTENDED_LIMIT_INFORMATION");
