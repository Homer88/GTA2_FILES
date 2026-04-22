// Auto-generated structure: _CRYPT_TIMESTAMP_INFO
// Source: _CRYPT_TIMESTAMP_INFO.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CRYPT_TIMESTAMP_INFO
{
    _CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    _CRYPTOAPI_BLOB HashedMessage;
    _CRYPTOAPI_BLOB SerialNumber;
    _FILETIME ftTime;
    int fOrdering;
    _CRYPTOAPI_BLOB Nonce;
    _CRYPTOAPI_BLOB Tsa;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CRYPT_TIMESTAMP_INFO) == EXPECTED_SIZE, "Size mismatch for _CRYPT_TIMESTAMP_INFO");
