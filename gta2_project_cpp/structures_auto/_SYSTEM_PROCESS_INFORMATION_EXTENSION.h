// Auto-generated structure: _SYSTEM_PROCESS_INFORMATION_EXTENSION
// Source: _SYSTEM_PROCESS_INFORMATION_EXTENSION.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_PROCESS_INFORMATION_EXTENSION
{
    _PROCESS_DISK_COUNTERS DiskCounters;
    _PROCESS_ENERGY_VALUES EnergyValues;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_PROCESS_INFORMATION_EXTENSION) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_PROCESS_INFORMATION_EXTENSION");
