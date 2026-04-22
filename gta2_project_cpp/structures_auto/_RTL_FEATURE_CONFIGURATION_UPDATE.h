// Auto-generated structure: _RTL_FEATURE_CONFIGURATION_UPDATE
// Source: _RTL_FEATURE_CONFIGURATION_UPDATE.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _RTL_FEATURE_CONFIGURATION_UPDATE
{
    _RTL_FEATURE_CONFIGURATION_PRIORITY Priority;
    _RTL_FEATURE_ENABLED_STATE EnabledState;
    _RTL_FEATURE_ENABLED_STATE_OPTIONS EnabledStateOptions;
    _RTL_FEATURE_VARIANT_PAYLOAD_KIND VariantPayloadKind;
    _RTL_FEATURE_CONFIGURATION_OPERATION Operation;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_RTL_FEATURE_CONFIGURATION_UPDATE) == EXPECTED_SIZE, "Size mismatch for _RTL_FEATURE_CONFIGURATION_UPDATE");
