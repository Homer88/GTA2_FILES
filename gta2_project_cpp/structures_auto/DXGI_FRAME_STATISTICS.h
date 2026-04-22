// Auto-generated structure: DXGI_FRAME_STATISTICS
// Source: DXGI_FRAME_STATISTICS.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DXGI_FRAME_STATISTICS
{
    UINT PresentCount;
    UINT PresentRefreshCount;
    UINT SyncRefreshCount;
    LARGE_INTEGER SyncQPCTime;
    LARGE_INTEGER SyncGPUTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DXGI_FRAME_STATISTICS) == EXPECTED_SIZE, "Size mismatch for DXGI_FRAME_STATISTICS");
