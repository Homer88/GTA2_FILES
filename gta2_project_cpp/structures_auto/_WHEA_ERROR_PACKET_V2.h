// Auto-generated structure: _WHEA_ERROR_PACKET_V2
// Source: _WHEA_ERROR_PACKET_V2.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_ERROR_PACKET_V2
{
    _WHEA_ERROR_PACKET_FLAGS Flags;
    _WHEA_ERROR_TYPE ErrorType;
    _WHEA_ERROR_SEVERITY ErrorSeverity;
    _WHEA_ERROR_SOURCE_TYPE ErrorSourceType;
    _GUID NotifyType;
    _WHEA_ERROR_PACKET_DATA_FORMAT DataFormat;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_ERROR_PACKET_V2) == EXPECTED_SIZE, "Size mismatch for _WHEA_ERROR_PACKET_V2");
