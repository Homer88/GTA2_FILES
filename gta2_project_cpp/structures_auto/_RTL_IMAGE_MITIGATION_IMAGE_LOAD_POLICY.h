// Auto-generated structure: _RTL_IMAGE_MITIGATION_IMAGE_LOAD_POLICY
// Source: _RTL_IMAGE_MITIGATION_IMAGE_LOAD_POLICY.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_IMAGE_MITIGATION_IMAGE_LOAD_POLICY
{
    _RTL_IMAGE_MITIGATION_POLICY BlockRemoteImageLoads;
    _RTL_IMAGE_MITIGATION_POLICY BlockLowLabelImageLoads;
    _RTL_IMAGE_MITIGATION_POLICY PreferSystem32;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_IMAGE_MITIGATION_IMAGE_LOAD_POLICY) == EXPECTED_SIZE, "Size mismatch for _RTL_IMAGE_MITIGATION_IMAGE_LOAD_POLICY");
