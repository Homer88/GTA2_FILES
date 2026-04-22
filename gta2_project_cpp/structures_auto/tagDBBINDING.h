// Auto-generated structure: tagDBBINDING
// Source: tagDBBINDING.txt
// Fields count: 12
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagDBBINDING
{
    DBORDINAL iOrdinal;
    DBBYTEOFFSET obValue;
    DBBYTEOFFSET obLength;
    DBBYTEOFFSET obStatus;
    DBPART dwPart;
    DBMEMOWNER dwMemOwner;
    DBPARAMIO eParamIO;
    DBLENGTH cbMaxLen;
    DWORD dwFlags;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagDBBINDING) == EXPECTED_SIZE, "Size mismatch for tagDBBINDING");
