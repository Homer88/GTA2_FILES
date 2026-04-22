// Auto-generated structure: _CRL_ISSUING_DIST_POINT
// Source: _CRL_ISSUING_DIST_POINT.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CRL_ISSUING_DIST_POINT
{
    _CRL_DIST_POINT_NAME DistPointName;
    int fOnlyContainsUserCerts;
    int fOnlyContainsCACerts;
    _CRYPT_BIT_BLOB OnlySomeReasonFlags;
    int fIndirectCRL;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CRL_ISSUING_DIST_POINT) == EXPECTED_SIZE, "Size mismatch for _CRL_ISSUING_DIST_POINT");
