// Auto-generated structure: _OCSP_BASIC_SIGNED_RESPONSE_INFO
// Source: _OCSP_BASIC_SIGNED_RESPONSE_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OCSP_BASIC_SIGNED_RESPONSE_INFO
{
    _CRYPTOAPI_BLOB ToBeSigned;
    _OCSP_SIGNATURE_INFO SignatureInfo;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OCSP_BASIC_SIGNED_RESPONSE_INFO) == EXPECTED_SIZE, "Size mismatch for _OCSP_BASIC_SIGNED_RESPONSE_INFO");
