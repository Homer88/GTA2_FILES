// Auto-generated structure: DIDEVICEOBJECTDATA
// Source: DIDEVICEOBJECTDATA.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct DIDEVICEOBJECTDATA
{
    DWORD dwOfs;
    DWORD dwData;
    DWORD dwTimeStamp;
    DWORD dwSequence;
    UINT_PTR uAppData;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(DIDEVICEOBJECTDATA) == EXPECTED_SIZE, "Size mismatch for DIDEVICEOBJECTDATA");
