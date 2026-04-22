// Auto-generated structure: REFS_VOLUME_DATA_BUFFER
// Source: REFS_VOLUME_DATA_BUFFER.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct REFS_VOLUME_DATA_BUFFER
{
    _LARGE_INTEGER VolumeSerialNumber;
    _LARGE_INTEGER NumberSectors;
    _LARGE_INTEGER TotalClusters;
    _LARGE_INTEGER FreeClusters;
    _LARGE_INTEGER TotalReserved;
    _LARGE_INTEGER MaximumSizeOfResidentFile;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(REFS_VOLUME_DATA_BUFFER) == EXPECTED_SIZE, "Size mismatch for REFS_VOLUME_DATA_BUFFER");
