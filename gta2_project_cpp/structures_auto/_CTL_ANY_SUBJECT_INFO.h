// Auto-generated structure: _CTL_ANY_SUBJECT_INFO
// Source: _CTL_ANY_SUBJECT_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CTL_ANY_SUBJECT_INFO
{
    _CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    _CRYPTOAPI_BLOB SubjectIdentifier;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CTL_ANY_SUBJECT_INFO) == EXPECTED_SIZE, "Size mismatch for _CTL_ANY_SUBJECT_INFO");
