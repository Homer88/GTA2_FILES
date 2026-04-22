// Auto-generated structure: _RTL_IMAGE_MITIGATION_SYSTEM_CALL_DISABLE_POLICY
// Source: _RTL_IMAGE_MITIGATION_SYSTEM_CALL_DISABLE_POLICY.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_IMAGE_MITIGATION_SYSTEM_CALL_DISABLE_POLICY
{
    _RTL_IMAGE_MITIGATION_POLICY BlockWin32kSystemCalls;
    _RTL_IMAGE_MITIGATION_POLICY BlockFsctlSystemCalls;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_IMAGE_MITIGATION_SYSTEM_CALL_DISABLE_POLICY) == EXPECTED_SIZE, "Size mismatch for _RTL_IMAGE_MITIGATION_SYSTEM_CALL_DISABLE_POLICY");
