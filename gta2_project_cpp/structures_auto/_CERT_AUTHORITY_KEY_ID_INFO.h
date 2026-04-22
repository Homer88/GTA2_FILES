// Auto-generated structure: _CERT_AUTHORITY_KEY_ID_INFO
// Source: _CERT_AUTHORITY_KEY_ID_INFO.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CERT_AUTHORITY_KEY_ID_INFO
{
    _CRYPTOAPI_BLOB KeyId;
    _CRYPTOAPI_BLOB CertIssuer;
    _CRYPTOAPI_BLOB CertSerialNumber;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CERT_AUTHORITY_KEY_ID_INFO) == EXPECTED_SIZE, "Size mismatch for _CERT_AUTHORITY_KEY_ID_INFO");
