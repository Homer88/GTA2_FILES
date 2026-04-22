// Auto-generated structure: _FLOATING_SAVE_AREA
// Source: _FLOATING_SAVE_AREA.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FLOATING_SAVE_AREA
{
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    DWORD Spare0;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FLOATING_SAVE_AREA) == EXPECTED_SIZE, "Size mismatch for _FLOATING_SAVE_AREA");
