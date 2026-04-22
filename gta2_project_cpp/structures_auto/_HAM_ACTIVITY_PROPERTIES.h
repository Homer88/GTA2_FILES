// Auto-generated structure: _HAM_ACTIVITY_PROPERTIES
// Source: _HAM_ACTIVITY_PROPERTIES.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _HAM_ACTIVITY_PROPERTIES
{
    _HAM_ACTIVITY_PROPERTIES_FLAGS Flags;
    _HAM_ACTIVITY_START_FLAGS StartFlags;
    _HAM_ACTIVITY_REVOKE_FLAGS RevokeFlags;
    PDC_ACTIVITY_TYPE PdcActivityType;
    _RM_RESOURCE_SET_PROPERTIES CustomResourceSetProperties;
    _HAM_EXTERNAL_RESOURCE_MASK ExternalResourceMaskData;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_HAM_ACTIVITY_PROPERTIES) == EXPECTED_SIZE, "Size mismatch for _HAM_ACTIVITY_PROPERTIES");
