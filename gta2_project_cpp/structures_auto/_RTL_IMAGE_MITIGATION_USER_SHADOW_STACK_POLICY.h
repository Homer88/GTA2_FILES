// Auto-generated structure: _RTL_IMAGE_MITIGATION_USER_SHADOW_STACK_POLICY
// Source: _RTL_IMAGE_MITIGATION_USER_SHADOW_STACK_POLICY.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_IMAGE_MITIGATION_USER_SHADOW_STACK_POLICY
{
    _RTL_IMAGE_MITIGATION_POLICY UserShadowStack;
    _RTL_IMAGE_MITIGATION_POLICY SetContextIpValidation;
    _RTL_IMAGE_MITIGATION_POLICY BlockNonCetBinaries;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_IMAGE_MITIGATION_USER_SHADOW_STACK_POLICY) == EXPECTED_SIZE, "Size mismatch for _RTL_IMAGE_MITIGATION_USER_SHADOW_STACK_POLICY");
