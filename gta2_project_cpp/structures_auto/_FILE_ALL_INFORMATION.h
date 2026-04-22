// Auto-generated structure: _FILE_ALL_INFORMATION
// Source: _FILE_ALL_INFORMATION.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FILE_ALL_INFORMATION
{
    _FILE_BASIC_INFORMATION BasicInformation;
    _FILE_STANDARD_INFORMATION StandardInformation;
    _FILE_INTERNAL_INFORMATION InternalInformation;
    _FILE_EA_INFORMATION EaInformation;
    _FILE_ACCESS_INFORMATION AccessInformation;
    _FILE_POSITION_INFORMATION PositionInformation;
    _FILE_MODE_INFORMATION ModeInformation;
    _FILE_ALIGNMENT_INFORMATION AlignmentInformation;
    _FILE_NAME_INFORMATION NameInformation;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FILE_ALL_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _FILE_ALL_INFORMATION");
