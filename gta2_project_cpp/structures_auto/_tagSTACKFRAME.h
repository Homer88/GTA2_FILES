// Auto-generated structure: _tagSTACKFRAME
// Source: _tagSTACKFRAME.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _tagSTACKFRAME
{
    _tagADDRESS AddrPC;
    _tagADDRESS AddrReturn;
    _tagADDRESS AddrFrame;
    _tagADDRESS AddrStack;
    int Far;
    int Virtual;
    _KDHELP KdHelp;
    _tagADDRESS AddrBStore;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_tagSTACKFRAME) == EXPECTED_SIZE, "Size mismatch for _tagSTACKFRAME");
