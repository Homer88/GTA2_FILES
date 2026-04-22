// Auto-generated structure: _SAFER_IDENTIFICATION_HEADER
// Source: _SAFER_IDENTIFICATION_HEADER.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SAFER_IDENTIFICATION_HEADER
{
    _SAFER_IDENTIFICATION_TYPES dwIdentificationType;
    _GUID IdentificationGuid;
    _FILETIME lastModified;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SAFER_IDENTIFICATION_HEADER) == EXPECTED_SIZE, "Size mismatch for _SAFER_IDENTIFICATION_HEADER");
