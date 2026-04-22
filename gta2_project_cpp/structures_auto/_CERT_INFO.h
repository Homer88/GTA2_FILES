// Auto-generated structure: _CERT_INFO
// Source: _CERT_INFO.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CERT_INFO
{
    _CRYPTOAPI_BLOB SerialNumber;
    _CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    _CRYPTOAPI_BLOB Issuer;
    _FILETIME NotBefore;
    _FILETIME NotAfter;
    _CRYPTOAPI_BLOB Subject;
    _CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    _CRYPT_BIT_BLOB IssuerUniqueId;
    _CRYPT_BIT_BLOB SubjectUniqueId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CERT_INFO) == EXPECTED_SIZE, "Size mismatch for _CERT_INFO");
