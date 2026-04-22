// Auto-generated structure: wil_details_StagingConfig
// Source: wil_details_StagingConfig.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct wil_details_StagingConfig
{
    wil_FeatureStore store;
    int forUpdate;
    int modified;
    int changedInSession;
    int bufferOwned;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(wil_details_StagingConfig) == EXPECTED_SIZE, "Size mismatch for wil_details_StagingConfig");
