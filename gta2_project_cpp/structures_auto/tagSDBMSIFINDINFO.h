// Auto-generated structure: tagSDBMSIFINDINFO
// Source: tagSDBMSIFINDINFO.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagSDBMSIFINDINFO
{
    _GUID guidID;
    _FIND_INFO sdbFindInfo;
    tagSDBMSILOOKUPSTATE sdbLookupState;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagSDBMSIFINDINFO) == EXPECTED_SIZE, "Size mismatch for tagSDBMSIFINDINFO");
