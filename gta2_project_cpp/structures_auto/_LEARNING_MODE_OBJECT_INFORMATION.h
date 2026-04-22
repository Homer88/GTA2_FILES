// Auto-generated structure: _LEARNING_MODE_OBJECT_INFORMATION
// Source: _LEARNING_MODE_OBJECT_INFORMATION.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _LEARNING_MODE_OBJECT_INFORMATION
{
    _SINGLE_LIST_ENTRY ListEntry;
    _LEARNING_MODE_LOG_LEVEL LogLevel;
    _UNICODE_STRING FullObjectName;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_LEARNING_MODE_OBJECT_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _LEARNING_MODE_OBJECT_INFORMATION");
