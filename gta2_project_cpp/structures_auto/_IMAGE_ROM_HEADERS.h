// Auto-generated structure: _IMAGE_ROM_HEADERS
// Source: _IMAGE_ROM_HEADERS.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _IMAGE_ROM_HEADERS
{
    _IMAGE_FILE_HEADER FileHeader;
    _IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_IMAGE_ROM_HEADERS) == EXPECTED_SIZE, "Size mismatch for _IMAGE_ROM_HEADERS");
