// Auto-generated structure: tagEMRSTRETCHDIBITS
// Source: tagEMRSTRETCHDIBITS.txt
// Fields count: 10
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagEMRSTRETCHDIBITS
{
    tagEMR emr;
    _RECTL rclBounds;
    int xDest;
    int yDest;
    int xSrc;
    int ySrc;
    int cxSrc;
    int cySrc;
    int cxDest;
    int cyDest;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagEMRSTRETCHDIBITS) == EXPECTED_SIZE, "Size mismatch for tagEMRSTRETCHDIBITS");
