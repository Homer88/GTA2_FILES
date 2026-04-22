// Auto-generated structure: tagFUNCDESC
// Source: tagFUNCDESC.txt
// Fields count: 10
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagFUNCDESC
{
    MEMBERID memid;
    FUNCKIND funckind;
    INVOKEKIND invkind;
    CALLCONV callconv;
    SHORT cParams;
    SHORT cParamsOpt;
    SHORT oVft;
    SHORT cScodes;
    ELEMDESC elemdescFunc;
    WORD wFuncFlags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagFUNCDESC) == EXPECTED_SIZE, "Size mismatch for tagFUNCDESC");
