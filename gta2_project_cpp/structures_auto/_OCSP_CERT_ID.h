// Auto-generated structure: _OCSP_CERT_ID
// Source: _OCSP_CERT_ID.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OCSP_CERT_ID
{
    _CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    _CRYPTOAPI_BLOB IssuerNameHash;
    _CRYPTOAPI_BLOB IssuerKeyHash;
    _CRYPTOAPI_BLOB SerialNumber;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OCSP_CERT_ID) == EXPECTED_SIZE, "Size mismatch for _OCSP_CERT_ID");
