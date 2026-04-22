// Auto-generated structure: _CONSOLE_SCREEN_BUFFER_INFO
// Source: _CONSOLE_SCREEN_BUFFER_INFO.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _CONSOLE_SCREEN_BUFFER_INFO
{
    _COORD dwSize;
    _COORD dwCursorPosition;
    _SMALL_RECT srWindow;
    _COORD dwMaximumWindowSize;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_CONSOLE_SCREEN_BUFFER_INFO) == EXPECTED_SIZE, "Size mismatch for _CONSOLE_SCREEN_BUFFER_INFO");
