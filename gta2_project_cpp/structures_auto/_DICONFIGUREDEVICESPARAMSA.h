// Auto-generated structure: _DICONFIGUREDEVICESPARAMSA
// Source: _DICONFIGUREDEVICESPARAMSA.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DICONFIGUREDEVICESPARAMSA
{
    DWORD dwSize;
    DWORD dwcUsers;
    LPSTR lptszUserNames;
    DWORD dwcFormats;
    LPDIACTIONFORMATA lprgFormats;
    HWND hwnd;
    DICOLORSET dics;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DICONFIGUREDEVICESPARAMSA) == EXPECTED_SIZE, "Size mismatch for _DICONFIGUREDEVICESPARAMSA");
