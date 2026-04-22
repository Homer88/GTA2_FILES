// Auto-generated structure: _CMSG_CMS_SIGNER_INFO
// Source: _CMSG_CMS_SIGNER_INFO.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CMSG_CMS_SIGNER_INFO
{
    _CERT_ID SignerId;
    _CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    _CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
    _CRYPTOAPI_BLOB EncryptedHash;
    _CRYPT_ATTRIBUTES AuthAttrs;
    _CRYPT_ATTRIBUTES UnauthAttrs;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CMSG_CMS_SIGNER_INFO) == EXPECTED_SIZE, "Size mismatch for _CMSG_CMS_SIGNER_INFO");
