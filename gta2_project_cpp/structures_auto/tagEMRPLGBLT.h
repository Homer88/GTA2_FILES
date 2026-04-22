// Auto-generated structure: tagEMRPLGBLT
// Source: tagEMRPLGBLT.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagEMRPLGBLT
{
    tagEMR emr;
    _RECTL rclBounds;
    int xSrc;
    int ySrc;
    int cxSrc;
    int cySrc;
    tagXFORM xformSrc;
    int xMask;
    int yMask;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagEMRPLGBLT) == EXPECTED_SIZE, "Size mismatch for tagEMRPLGBLT");
