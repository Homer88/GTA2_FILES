// Auto-generated structure: _tagSTACKFRAME_EX
// Source: _tagSTACKFRAME_EX.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _tagSTACKFRAME_EX
{
    _tagADDRESS64 AddrPC;
    _tagADDRESS64 AddrReturn;
    _tagADDRESS64 AddrFrame;
    _tagADDRESS64 AddrStack;
    _tagADDRESS64 AddrBStore;
    int Far;
    int Virtual;
    _KDHELP64 KdHelp;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_tagSTACKFRAME_EX) == EXPECTED_SIZE, "Size mismatch for _tagSTACKFRAME_EX");
