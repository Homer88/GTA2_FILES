// Auto-generated structure: DIEFFECT
// Source: DIEFFECT.txt
// Fields count: 14
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DIEFFECT
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDuration;
    DWORD dwSamplePeriod;
    DWORD dwGain;
    DWORD dwTriggerButton;
    DWORD dwTriggerRepeatInterval;
    DWORD cAxes;
    LPDWORD rgdwAxes;
    LPLONG rglDirection;
    LPDIENVELOPE lpEnvelope;
    DWORD cbTypeSpecificParams;
    LPVOID lpvTypeSpecificParams;
    DWORD dwStartDelay;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DIEFFECT) == EXPECTED_SIZE, "Size mismatch for DIEFFECT");
