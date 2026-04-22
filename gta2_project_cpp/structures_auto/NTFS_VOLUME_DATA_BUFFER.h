// Auto-generated structure: NTFS_VOLUME_DATA_BUFFER
// Source: NTFS_VOLUME_DATA_BUFFER.txt
// Fields count: 10
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct NTFS_VOLUME_DATA_BUFFER
{
    _LARGE_INTEGER VolumeSerialNumber;
    _LARGE_INTEGER NumberSectors;
    _LARGE_INTEGER TotalClusters;
    _LARGE_INTEGER FreeClusters;
    _LARGE_INTEGER TotalReserved;
    _LARGE_INTEGER MftValidDataLength;
    _LARGE_INTEGER MftStartLcn;
    _LARGE_INTEGER Mft2StartLcn;
    _LARGE_INTEGER MftZoneStart;
    _LARGE_INTEGER MftZoneEnd;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(NTFS_VOLUME_DATA_BUFFER) == EXPECTED_SIZE, "Size mismatch for NTFS_VOLUME_DATA_BUFFER");
