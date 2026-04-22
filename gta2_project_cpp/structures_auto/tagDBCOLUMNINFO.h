// Auto-generated structure: tagDBCOLUMNINFO
// Source: tagDBCOLUMNINFO.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagDBCOLUMNINFO
{
    LPOLESTR pwszName;
    DBORDINAL iOrdinal;
    DBCOLUMNFLAGS dwFlags;
    DBLENGTH ulColumnSize;
    DBTYPE wType;
    BYTE bPrecision;
    BYTE bScale;
    DBID columnid;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagDBCOLUMNINFO) == EXPECTED_SIZE, "Size mismatch for tagDBCOLUMNINFO");
