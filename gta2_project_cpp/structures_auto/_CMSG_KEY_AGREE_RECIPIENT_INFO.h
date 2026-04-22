// Auto-generated structure: _CMSG_KEY_AGREE_RECIPIENT_INFO
// Source: _CMSG_KEY_AGREE_RECIPIENT_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CMSG_KEY_AGREE_RECIPIENT_INFO
{
    _CRYPTOAPI_BLOB UserKeyingMaterial;
    _CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CMSG_KEY_AGREE_RECIPIENT_INFO) == EXPECTED_SIZE, "Size mismatch for _CMSG_KEY_AGREE_RECIPIENT_INFO");
