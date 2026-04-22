// Auto-generated structure: _CTL_INFO
// Source: _CTL_INFO.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CTL_INFO
{
    _CTL_USAGE SubjectUsage;
    _CRYPTOAPI_BLOB ListIdentifier;
    _CRYPTOAPI_BLOB SequenceNumber;
    _FILETIME ThisUpdate;
    _FILETIME NextUpdate;
    _CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CTL_INFO) == EXPECTED_SIZE, "Size mismatch for _CTL_INFO");
