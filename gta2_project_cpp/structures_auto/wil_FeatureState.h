// Auto-generated structure: wil_FeatureState
// Source: wil_FeatureState.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct wil_FeatureState
{
    wil_FeatureEnabledState enabledState;
    wil_FeatureVariantPayloadKind payloadKind;
    int hasNotification;
    int isVariantConfiguration;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(wil_FeatureState) == EXPECTED_SIZE, "Size mismatch for wil_FeatureState");
