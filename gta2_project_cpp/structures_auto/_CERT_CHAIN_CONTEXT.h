// Auto-generated structure: _CERT_CHAIN_CONTEXT
// Source: _CERT_CHAIN_CONTEXT.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CERT_CHAIN_CONTEXT
{
    _CERT_TRUST_STATUS TrustStatus;
    int fHasRevocationFreshnessTime;
    _GUID ChainId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CERT_CHAIN_CONTEXT) == EXPECTED_SIZE, "Size mismatch for _CERT_CHAIN_CONTEXT");
