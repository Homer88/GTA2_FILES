// Auto-generated structure: BITMAPV5HEADER
// Source: BITMAPV5HEADER.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct BITMAPV5HEADER
{
    int bV5Width;
    int bV5Height;
    int bV5XPelsPerMeter;
    int bV5YPelsPerMeter;
    tagICEXYZTRIPLE bV5Endpoints;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(BITMAPV5HEADER) == EXPECTED_SIZE, "Size mismatch for BITMAPV5HEADER");
