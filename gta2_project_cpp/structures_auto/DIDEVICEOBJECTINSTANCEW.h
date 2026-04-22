// Auto-generated structure: DIDEVICEOBJECTINSTANCEW
// Source: DIDEVICEOBJECTINSTANCEW.txt
// Fields count: 14
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DIDEVICEOBJECTINSTANCEW
{
    DWORD dwSize;
    GUID guidType;
    DWORD dwOfs;
    DWORD dwType;
    DWORD dwFlags;
    DWORD dwFFMaxForce;
    DWORD dwFFForceResolution;
    WORD wCollectionNumber;
    WORD wDesignatorIndex;
    WORD wUsagePage;
    WORD wUsage;
    DWORD dwDimension;
    WORD wExponent;
    WORD wReportId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DIDEVICEOBJECTINSTANCEW) == EXPECTED_SIZE, "Size mismatch for DIDEVICEOBJECTINSTANCEW");
