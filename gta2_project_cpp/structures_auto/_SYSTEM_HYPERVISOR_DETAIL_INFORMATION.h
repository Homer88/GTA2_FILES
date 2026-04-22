// Auto-generated structure: _SYSTEM_HYPERVISOR_DETAIL_INFORMATION
// Source: _SYSTEM_HYPERVISOR_DETAIL_INFORMATION.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_HYPERVISOR_DETAIL_INFORMATION
{
    _HV_DETAILS HvVendorAndMaxFunction;
    _HV_DETAILS HypervisorInterface;
    _HV_DETAILS HypervisorVersion;
    _HV_DETAILS HvFeatures;
    _HV_DETAILS HwFeatures;
    _HV_DETAILS EnlightenmentInfo;
    _HV_DETAILS ImplementationLimits;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_HYPERVISOR_DETAIL_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_HYPERVISOR_DETAIL_INFORMATION");
