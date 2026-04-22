// Auto-generated structure: _WHEA_ERROR_RECORD_HEADER
// Source: _WHEA_ERROR_RECORD_HEADER.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_ERROR_RECORD_HEADER
{
    _WHEA_REVISION Revision;
    _WHEA_ERROR_SEVERITY Severity;
    _WHEA_ERROR_RECORD_HEADER_VALIDBITS ValidBits;
    _WHEA_TIMESTAMP Timestamp;
    _GUID PlatformId;
    _GUID PartitionId;
    _GUID CreatorId;
    _GUID NotifyType;
    _WHEA_ERROR_RECORD_HEADER_FLAGS Flags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_ERROR_RECORD_HEADER) == EXPECTED_SIZE, "Size mismatch for _WHEA_ERROR_RECORD_HEADER");
