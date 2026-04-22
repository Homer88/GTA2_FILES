// Auto-generated structure: _OCSP_BASIC_RESPONSE_ENTRY
// Source: _OCSP_BASIC_RESPONSE_ENTRY.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OCSP_BASIC_RESPONSE_ENTRY
{
    _OCSP_CERT_ID CertId;
    _FILETIME ThisUpdate;
    _FILETIME NextUpdate;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OCSP_BASIC_RESPONSE_ENTRY) == EXPECTED_SIZE, "Size mismatch for _OCSP_BASIC_RESPONSE_ENTRY");
