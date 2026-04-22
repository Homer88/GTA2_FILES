// Auto-generated structure: EDP_REQUEST_ACCESS_OPTIONS
// Source: EDP_REQUEST_ACCESS_OPTIONS.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct EDP_REQUEST_ACCESS_OPTIONS
{
    EDP_REQUEST_ACCESS_OVERRIDE overrideOption;
    EDP_TELEMETRY_CALLER telemetryCaller;
    EDP_SOURCE_ENTERPRISEID_OPTION sourceEnterpriseIdOption;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(EDP_REQUEST_ACCESS_OPTIONS) == EXPECTED_SIZE, "Size mismatch for EDP_REQUEST_ACCESS_OPTIONS");
