// Auto-generated structure: _CRYPT_ECC_PRIVATE_KEY_INFO
// Source: _CRYPT_ECC_PRIVATE_KEY_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CRYPT_ECC_PRIVATE_KEY_INFO
{
    _CRYPTOAPI_BLOB PrivateKey;
    _CRYPT_BIT_BLOB PublicKey;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CRYPT_ECC_PRIVATE_KEY_INFO) == EXPECTED_SIZE, "Size mismatch for _CRYPT_ECC_PRIVATE_KEY_INFO");
