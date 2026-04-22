// Auto-generated structure: tagSTATPROPSETSTG
// Source: tagSTATPROPSETSTG.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagSTATPROPSETSTG
{
    FMTID fmtid;
    CLSID clsid;
    DWORD grfFlags;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD dwOSVersion;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagSTATPROPSETSTG) == EXPECTED_SIZE, "Size mismatch for tagSTATPROPSETSTG");
