// Auto-generated structure: _TOKEN_CONTROL
// Source: _TOKEN_CONTROL.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TOKEN_CONTROL
{
    _LUID TokenId;
    _LUID AuthenticationId;
    _LUID ModifiedId;
    _TOKEN_SOURCE TokenSource;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TOKEN_CONTROL) == EXPECTED_SIZE, "Size mismatch for _TOKEN_CONTROL");
