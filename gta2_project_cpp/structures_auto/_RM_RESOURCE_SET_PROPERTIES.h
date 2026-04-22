// Auto-generated structure: _RM_RESOURCE_SET_PROPERTIES
// Source: _RM_RESOURCE_SET_PROPERTIES.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RM_RESOURCE_SET_PROPERTIES
{
    _RM_RESOURCE_REQUEST ResourcesRequested;
    _RM_ACTIVITY_IMPORTANCE Importance;
    _RM_RESOURCE_LIMITS ResourceLimits;
    _RM_COMMON_POLICY_FLAGS CommonPolicyFlags;
    _RM_APPMODEL_POLICY_FLAGS AppModelPolicyFlags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RM_RESOURCE_SET_PROPERTIES) == EXPECTED_SIZE, "Size mismatch for _RM_RESOURCE_SET_PROPERTIES");
