// Auto-generated structure: _CMSG_CONTENT_ENCRYPT_INFO
// Source: _CMSG_CONTENT_ENCRYPT_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CMSG_CONTENT_ENCRYPT_INFO
{
    _CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    int fCNG;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CMSG_CONTENT_ENCRYPT_INFO) == EXPECTED_SIZE, "Size mismatch for _CMSG_CONTENT_ENCRYPT_INFO");
