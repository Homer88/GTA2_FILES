// Auto-generated structure: _WHEA_GENERIC_ERROR_DESCRIPTOR_V2
// Source: _WHEA_GENERIC_ERROR_DESCRIPTOR_V2.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_GENERIC_ERROR_DESCRIPTOR_V2
{
    _LARGE_INTEGER ErrStatusAddress;
    _WHEA_NOTIFICATION_DESCRIPTOR Notify;
    _LARGE_INTEGER ReadAckAddress;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_GENERIC_ERROR_DESCRIPTOR_V2) == EXPECTED_SIZE, "Size mismatch for _WHEA_GENERIC_ERROR_DESCRIPTOR_V2");
