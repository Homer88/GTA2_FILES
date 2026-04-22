// Auto-generated structure: _RTL_IMAGE_MITIGATION_PAYLOAD_RESTRICTION_POLICY
// Source: _RTL_IMAGE_MITIGATION_PAYLOAD_RESTRICTION_POLICY.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_IMAGE_MITIGATION_PAYLOAD_RESTRICTION_POLICY
{
    _RTL_IMAGE_MITIGATION_POLICY EnableExportAddressFilter;
    _RTL_IMAGE_MITIGATION_POLICY EnableExportAddressFilterPlus;
    _RTL_IMAGE_MITIGATION_POLICY EnableImportAddressFilter;
    _RTL_IMAGE_MITIGATION_POLICY EnableRopStackPivot;
    _RTL_IMAGE_MITIGATION_POLICY EnableRopCallerCheck;
    _RTL_IMAGE_MITIGATION_POLICY EnableRopSimExec;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_IMAGE_MITIGATION_PAYLOAD_RESTRICTION_POLICY) == EXPECTED_SIZE, "Size mismatch for _RTL_IMAGE_MITIGATION_PAYLOAD_RESTRICTION_POLICY");
