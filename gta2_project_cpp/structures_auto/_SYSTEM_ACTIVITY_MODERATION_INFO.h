// Auto-generated structure: _SYSTEM_ACTIVITY_MODERATION_INFO
// Source: _SYSTEM_ACTIVITY_MODERATION_INFO.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_ACTIVITY_MODERATION_INFO
{
    _UNICODE_STRING Identifier;
    _SYSTEM_ACTIVITY_MODERATION_STATE ModerationState;
    _SYSTEM_ACTIVITY_MODERATION_APP_TYPE AppType;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_ACTIVITY_MODERATION_INFO) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_ACTIVITY_MODERATION_INFO");
