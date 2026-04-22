// Auto-generated structure: _DIACTIONW
// Source: _DIACTIONW.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DIACTIONW
{
    UINT_PTR uAppData;
    DWORD dwSemantic;
    DWORD dwFlags;
    LPCWSTR lptszActionName;
    UINT uResIdString;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DIACTIONW) == EXPECTED_SIZE, "Size mismatch for _DIACTIONW");
