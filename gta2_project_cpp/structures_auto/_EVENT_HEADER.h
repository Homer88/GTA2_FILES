// Auto-generated structure: _EVENT_HEADER
// Source: _EVENT_HEADER.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _EVENT_HEADER
{
    _LARGE_INTEGER TimeStamp;
    _GUID ProviderId;
    _EVENT_DESCRIPTOR EventDescriptor;
    _GUID ActivityId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_EVENT_HEADER) == EXPECTED_SIZE, "Size mismatch for _EVENT_HEADER");
