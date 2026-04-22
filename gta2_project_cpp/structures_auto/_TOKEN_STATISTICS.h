// Auto-generated structure: _TOKEN_STATISTICS
// Source: _TOKEN_STATISTICS.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TOKEN_STATISTICS
{
    _LUID TokenId;
    _LUID AuthenticationId;
    _LARGE_INTEGER ExpirationTime;
    _TOKEN_TYPE TokenType;
    _SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    _LUID ModifiedId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TOKEN_STATISTICS) == EXPECTED_SIZE, "Size mismatch for _TOKEN_STATISTICS");
