// Auto-generated structure: _IMAGEHLP_MODULE64
// Source: _IMAGEHLP_MODULE64.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _IMAGEHLP_MODULE64
{
    SYM_TYPE SymType;
    _GUID PdbSig70;
    int PdbUnmatched;
    int DbgUnmatched;
    int LineNumbers;
    int GlobalSymbols;
    int TypeInfo;
    int SourceIndexed;
    int Publics;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_IMAGEHLP_MODULE64) == EXPECTED_SIZE, "Size mismatch for _IMAGEHLP_MODULE64");
