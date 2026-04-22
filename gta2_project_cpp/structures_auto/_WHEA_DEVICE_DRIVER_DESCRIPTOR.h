// Auto-generated structure: _WHEA_DEVICE_DRIVER_DESCRIPTOR
// Source: _WHEA_DEVICE_DRIVER_DESCRIPTOR.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_DEVICE_DRIVER_DESCRIPTOR
{
    _GUID SourceGuid;
    _WHEA_ERROR_SOURCE_CONFIGURATION_DD Config;
    _GUID CreatorId;
    _GUID PartitionId;
    int OpenHandles;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_DEVICE_DRIVER_DESCRIPTOR) == EXPECTED_SIZE, "Size mismatch for _WHEA_DEVICE_DRIVER_DESCRIPTOR");
