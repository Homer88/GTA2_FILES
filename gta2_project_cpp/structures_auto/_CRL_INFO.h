// Auto-generated structure: _CRL_INFO
// Source: _CRL_INFO.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CRL_INFO
{
    _CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    _CRYPTOAPI_BLOB Issuer;
    _FILETIME ThisUpdate;
    _FILETIME NextUpdate;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CRL_INFO) == EXPECTED_SIZE, "Size mismatch for _CRL_INFO");
