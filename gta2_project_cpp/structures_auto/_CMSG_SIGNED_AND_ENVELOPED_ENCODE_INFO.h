// Auto-generated structure: _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
// Source: _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO
{
    _CMSG_SIGNED_ENCODE_INFO SignedInfo;
    _CMSG_ENVELOPED_ENCODE_INFO EnvelopedInfo;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO) == EXPECTED_SIZE, "Size mismatch for _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO");
