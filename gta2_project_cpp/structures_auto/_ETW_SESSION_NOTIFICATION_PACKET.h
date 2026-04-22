// Auto-generated structure: _ETW_SESSION_NOTIFICATION_PACKET
// Source: _ETW_SESSION_NOTIFICATION_PACKET.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ETW_SESSION_NOTIFICATION_PACKET
{
    _ETW_NOTIFICATION_HEADER NotificationHeader;
    _ETW_SESSION_NOTIFICATION_TYPE Type;
    int Status;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ETW_SESSION_NOTIFICATION_PACKET) == EXPECTED_SIZE, "Size mismatch for _ETW_SESSION_NOTIFICATION_PACKET");
