// Auto-generated structure: BITMAPV4HEADER
// Source: BITMAPV4HEADER.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct BITMAPV4HEADER
{
    int bV4Width;
    int bV4Height;
    int bV4XPelsPerMeter;
    int bV4YPelsPerMeter;
    tagICEXYZTRIPLE bV4Endpoints;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(BITMAPV4HEADER) == EXPECTED_SIZE, "Size mismatch for BITMAPV4HEADER");
