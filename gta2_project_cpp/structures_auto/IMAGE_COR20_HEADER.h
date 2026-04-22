// Auto-generated structure: IMAGE_COR20_HEADER
// Source: IMAGE_COR20_HEADER.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct IMAGE_COR20_HEADER
{
    _IMAGE_DATA_DIRECTORY MetaData;
    _IMAGE_DATA_DIRECTORY Resources;
    _IMAGE_DATA_DIRECTORY StrongNameSignature;
    _IMAGE_DATA_DIRECTORY CodeManagerTable;
    _IMAGE_DATA_DIRECTORY VTableFixups;
    _IMAGE_DATA_DIRECTORY ExportAddressTableJumps;
    _IMAGE_DATA_DIRECTORY ManagedNativeHeader;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(IMAGE_COR20_HEADER) == EXPECTED_SIZE, "Size mismatch for IMAGE_COR20_HEADER");
