// Auto-generated structure: _BCRYPT_DSA_PARAMETER_HEADER_V2
// Source: _BCRYPT_DSA_PARAMETER_HEADER_V2.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _BCRYPT_DSA_PARAMETER_HEADER_V2
{
    HASHALGORITHM_ENUM hashAlgorithm;
    DSAFIPSVERSION_ENUM standardVersion;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_BCRYPT_DSA_PARAMETER_HEADER_V2) == EXPECTED_SIZE, "Size mismatch for _BCRYPT_DSA_PARAMETER_HEADER_V2");
