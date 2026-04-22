// Auto-generated structure: _CRYPT_PROVIDER_SIGSTATE
// Source: _CRYPT_PROVIDER_SIGSTATE.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CRYPT_PROVIDER_SIGSTATE
{
    int fFirstAttemptMade;
    int fNoMoreSigs;
    int fSupportMultiSig;
    int fCheckedSealing;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CRYPT_PROVIDER_SIGSTATE) == EXPECTED_SIZE, "Size mismatch for _CRYPT_PROVIDER_SIGSTATE");
