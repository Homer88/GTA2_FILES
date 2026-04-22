// Auto-generated structure: WNDCLASSA
// Source: WNDCLASSA.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct WNDCLASSA
{
    UINT style;
    WNDPROC lpfnWndProc;
    int style_2;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(WNDCLASSA) == EXPECTED_SIZE, "Size mismatch for WNDCLASSA");
