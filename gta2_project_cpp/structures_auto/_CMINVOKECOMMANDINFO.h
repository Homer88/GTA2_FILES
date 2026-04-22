// Auto-generated structure: _CMINVOKECOMMANDINFO
// Source: _CMINVOKECOMMANDINFO.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CMINVOKECOMMANDINFO
{
    DWORD cbSize;
    DWORD fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    DWORD dwHotKey;
    HANDLE hIcon;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CMINVOKECOMMANDINFO) == EXPECTED_SIZE, "Size mismatch for _CMINVOKECOMMANDINFO");
