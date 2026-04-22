// Auto-generated structure: tagEMRSETDIBITSTODEVICE
// Source: tagEMRSETDIBITSTODEVICE.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagEMRSETDIBITSTODEVICE
{
    tagEMR emr;
    _RECTL rclBounds;
    int xDest;
    int yDest;
    int xSrc;
    int ySrc;
    int cxSrc;
    int cySrc;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagEMRSETDIBITSTODEVICE) == EXPECTED_SIZE, "Size mismatch for tagEMRSETDIBITSTODEVICE");
