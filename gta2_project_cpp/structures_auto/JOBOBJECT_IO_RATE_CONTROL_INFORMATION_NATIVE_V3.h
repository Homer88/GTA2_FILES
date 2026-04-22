// Auto-generated structure: JOBOBJECT_IO_RATE_CONTROL_INFORMATION_NATIVE_V3
// Source: JOBOBJECT_IO_RATE_CONTROL_INFORMATION_NATIVE_V3.txt
// Fields count: 16
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct JOBOBJECT_IO_RATE_CONTROL_INFORMATION_NATIVE_V3
{
    __int64 MaxIops;
    __int64 MaxBandwidth;
    __int64 ReservationIops;
    JOB_OBJECT_IO_RATE_CONTROL_FLAGS ControlFlags;
    __int64 CriticalReservationIops;
    __int64 ReservationBandwidth;
    __int64 CriticalReservationBandwidth;
    __int64 MaxTimePercent;
    __int64 ReservationTimePercent;
    __int64 CriticalReservationTimePercent;
    __int64 SoftMaxIops;
    __int64 SoftMaxBandwidth;
    __int64 SoftMaxTimePercent;
    __int64 LimitExcessNotifyIops;
    __int64 LimitExcessNotifyBandwidth;
    __int64 LimitExcessNotifyTimePercent;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(JOBOBJECT_IO_RATE_CONTROL_INFORMATION_NATIVE_V3) == EXPECTED_SIZE, "Size mismatch for JOBOBJECT_IO_RATE_CONTROL_INFORMATION_NATIVE_V3");
