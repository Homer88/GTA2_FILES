// Auto-generated structure: _WHEA_EVENT_LOG_ENTRY_HEADER
// Source: _WHEA_EVENT_LOG_ENTRY_HEADER.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_EVENT_LOG_ENTRY_HEADER
{
    _WHEA_EVENT_LOG_ENTRY_TYPE Type;
    _WHEA_EVENT_LOG_ENTRY_ID Id;
    _WHEA_EVENT_LOG_ENTRY_FLAGS Flags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_EVENT_LOG_ENTRY_HEADER) == EXPECTED_SIZE, "Size mismatch for _WHEA_EVENT_LOG_ENTRY_HEADER");
