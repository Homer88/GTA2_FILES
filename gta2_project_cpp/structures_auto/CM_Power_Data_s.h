// Auto-generated structure: CM_Power_Data_s
// Source: CM_Power_Data_s.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct CM_Power_Data_s
{
    _DEVICE_POWER_STATE PD_MostRecentPowerState;
    _SYSTEM_POWER_STATE PD_DeepestSystemWake;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(CM_Power_Data_s) == EXPECTED_SIZE, "Size mismatch for CM_Power_Data_s");
