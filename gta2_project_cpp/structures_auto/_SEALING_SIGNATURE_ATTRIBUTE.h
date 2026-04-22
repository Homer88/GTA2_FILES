// Auto-generated structure: _SEALING_SIGNATURE_ATTRIBUTE
// Source: _SEALING_SIGNATURE_ATTRIBUTE.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SEALING_SIGNATURE_ATTRIBUTE
{
    _CRYPT_ALGORITHM_IDENTIFIER signatureAlgorithm;
    _CRYPTOAPI_BLOB encryptedDigest;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SEALING_SIGNATURE_ATTRIBUTE) == EXPECTED_SIZE, "Size mismatch for _SEALING_SIGNATURE_ATTRIBUTE");
