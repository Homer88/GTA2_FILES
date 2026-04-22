// Auto-generated structure: _APPCOMPAT_EXE_DATA
// Source: _APPCOMPAT_EXE_DATA.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _APPCOMPAT_EXE_DATA
{
    int bLoadShimEngine;
    tagSDBQUERYRESULT SdbQueryResult;
    tagSWITCH_CONTEXT SwitchContext;
    int bLatestOs;
    int bPackageId;
    int bSwitchBackManifest;
    int bUacManifest;
    int bLegacyInstaller;
    _SDB_CSTRUCT_COBALT_PROCFLAG CobaltProcFlags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_APPCOMPAT_EXE_DATA) == EXPECTED_SIZE, "Size mismatch for _APPCOMPAT_EXE_DATA");
