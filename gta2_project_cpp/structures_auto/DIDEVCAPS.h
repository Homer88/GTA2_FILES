// Auto-generated structure: DIDEVCAPS
// Source: DIDEVCAPS.txt
// Fields count: 11
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DIDEVCAPS
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDevType;
    DWORD dwAxes;
    DWORD dwButtons;
    DWORD dwPOVs;
    DWORD dwFFSamplePeriod;
    DWORD dwFFMinTimeResolution;
    DWORD dwFirmwareRevision;
    DWORD dwHardwareRevision;
    DWORD dwFFDriverVersion;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DIDEVCAPS) == EXPECTED_SIZE, "Size mismatch for DIDEVCAPS");
