// Auto-generated structure: _SHELLEXECUTEINFOA
// Source: _SHELLEXECUTEINFOA.txt
// Fields count: 14
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SHELLEXECUTEINFOA
{
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpFile;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPCSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    HANDLE hIcon;
    HANDLE hMonitor;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SHELLEXECUTEINFOA) == EXPECTED_SIZE, "Size mismatch for _SHELLEXECUTEINFOA");
