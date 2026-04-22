// Auto-generated structure: _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO
// Source: _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO
{
    _CRYPT_BIT_BLOB RecipientPublicKey;
    _CERT_ID RecipientId;
    _FILETIME Date;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO) == EXPECTED_SIZE, "Size mismatch for _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO");
