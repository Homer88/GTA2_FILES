// Auto-generated structure: tagEMRALPHABLEND
// Source: tagEMRALPHABLEND.txt
// Fields count: 11
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagEMRALPHABLEND
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
    int cxSrc;
    int cySrc;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagEMRALPHABLEND) == EXPECTED_SIZE, "Size mismatch for tagEMRALPHABLEND");
