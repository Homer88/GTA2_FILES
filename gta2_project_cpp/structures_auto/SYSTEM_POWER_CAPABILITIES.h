// Auto-generated structure: SYSTEM_POWER_CAPABILITIES
// Source: SYSTEM_POWER_CAPABILITIES.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct SYSTEM_POWER_CAPABILITIES
{
    _SYSTEM_POWER_STATE AcOnLineWake;
    _SYSTEM_POWER_STATE SoftLidWake;
    _SYSTEM_POWER_STATE RtcWake;
    _SYSTEM_POWER_STATE MinDeviceWakeState;
    _SYSTEM_POWER_STATE DefaultLowLatencyWake;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(SYSTEM_POWER_CAPABILITIES) == EXPECTED_SIZE, "Size mismatch for SYSTEM_POWER_CAPABILITIES");
