// Auto-generated structure: _OCSP_SIGNATURE_INFO
// Source: _OCSP_SIGNATURE_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OCSP_SIGNATURE_INFO
{
    _CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    _CRYPT_BIT_BLOB Signature;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OCSP_SIGNATURE_INFO) == EXPECTED_SIZE, "Size mismatch for _OCSP_SIGNATURE_INFO");
