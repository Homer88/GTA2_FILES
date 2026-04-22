// Auto-generated structure: _SPC_INDIRECT_DATA_CONTENT
// Source: _SPC_INDIRECT_DATA_CONTENT.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SPC_INDIRECT_DATA_CONTENT
{
    _CRYPT_ATTRIBUTE_TYPE_VALUE Data;
    _CRYPT_ALGORITHM_IDENTIFIER DigestAlgorithm;
    _CRYPTOAPI_BLOB Digest;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SPC_INDIRECT_DATA_CONTENT) == EXPECTED_SIZE, "Size mismatch for _SPC_INDIRECT_DATA_CONTENT");
