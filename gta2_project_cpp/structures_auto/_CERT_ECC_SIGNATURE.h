// Auto-generated structure: _CERT_ECC_SIGNATURE
// Source: _CERT_ECC_SIGNATURE.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CERT_ECC_SIGNATURE
{
    _CRYPTOAPI_BLOB r;
    _CRYPTOAPI_BLOB s;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CERT_ECC_SIGNATURE) == EXPECTED_SIZE, "Size mismatch for _CERT_ECC_SIGNATURE");
