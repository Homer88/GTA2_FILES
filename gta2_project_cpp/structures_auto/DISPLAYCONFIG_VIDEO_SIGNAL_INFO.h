// Auto-generated structure: DISPLAYCONFIG_VIDEO_SIGNAL_INFO
// Source: DISPLAYCONFIG_VIDEO_SIGNAL_INFO.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DISPLAYCONFIG_VIDEO_SIGNAL_INFO
{
    DISPLAYCONFIG_RATIONAL hSyncFreq;
    DISPLAYCONFIG_RATIONAL vSyncFreq;
    DISPLAYCONFIG_2DREGION activeSize;
    DISPLAYCONFIG_2DREGION totalSize;
    DISPLAYCONFIG_SCANLINE_ORDERING scanLineOrdering;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DISPLAYCONFIG_VIDEO_SIGNAL_INFO) == EXPECTED_SIZE, "Size mismatch for DISPLAYCONFIG_VIDEO_SIGNAL_INFO");
