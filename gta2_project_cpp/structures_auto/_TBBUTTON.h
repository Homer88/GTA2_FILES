// Auto-generated structure: _TBBUTTON
// Source: _TBBUTTON.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TBBUTTON
{
    int iBitmap;
    int idCommand;
    BYTE fsState;
    BYTE fsStyle;
    DWORD_PTR dwData;
    INT_PTR iString;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TBBUTTON) == EXPECTED_SIZE, "Size mismatch for _TBBUTTON");
