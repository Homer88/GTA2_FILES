// Auto-generated structure: tagEMRBITBLT
// Source: tagEMRBITBLT.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagEMRBITBLT
{
    tagEMR emr;
    _RECTL rclBounds;
    int xDest;
    int yDest;
    int cxDest;
    int cyDest;
    int xSrc;
    int ySrc;
    tagXFORM xformSrc;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagEMRBITBLT) == EXPECTED_SIZE, "Size mismatch for tagEMRBITBLT");
