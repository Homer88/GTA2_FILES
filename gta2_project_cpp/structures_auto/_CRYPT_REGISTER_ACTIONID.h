// Auto-generated structure: _CRYPT_REGISTER_ACTIONID
// Source: _CRYPT_REGISTER_ACTIONID.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CRYPT_REGISTER_ACTIONID
{
    _CRYPT_TRUST_REG_ENTRY sInitProvider;
    _CRYPT_TRUST_REG_ENTRY sObjectProvider;
    _CRYPT_TRUST_REG_ENTRY sSignatureProvider;
    _CRYPT_TRUST_REG_ENTRY sCertificateProvider;
    _CRYPT_TRUST_REG_ENTRY sCertificatePolicyProvider;
    _CRYPT_TRUST_REG_ENTRY sFinalPolicyProvider;
    _CRYPT_TRUST_REG_ENTRY sTestPolicyProvider;
    _CRYPT_TRUST_REG_ENTRY sCleanupProvider;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CRYPT_REGISTER_ACTIONID) == EXPECTED_SIZE, "Size mismatch for _CRYPT_REGISTER_ACTIONID");
