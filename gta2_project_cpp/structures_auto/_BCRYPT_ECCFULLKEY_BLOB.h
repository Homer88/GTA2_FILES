// Auto-generated structure: _BCRYPT_ECCFULLKEY_BLOB
// Source: _BCRYPT_ECCFULLKEY_BLOB.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _BCRYPT_ECCFULLKEY_BLOB
{
    ECC_CURVE_TYPE_ENUM dwCurveType;
    ECC_CURVE_ALG_ID_ENUM dwCurveGenerationAlgId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_BCRYPT_ECCFULLKEY_BLOB) == EXPECTED_SIZE, "Size mismatch for _BCRYPT_ECCFULLKEY_BLOB");
