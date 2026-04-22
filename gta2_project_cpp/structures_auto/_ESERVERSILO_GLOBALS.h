// Auto-generated structure: _ESERVERSILO_GLOBALS
// Source: _ESERVERSILO_GLOBALS.txt
// Fields count: 11
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ESERVERSILO_GLOBALS
{
    _OBP_SILODRIVERSTATE ObSiloState;
    _SEP_SILOSTATE SeSiloState;
    _WNF_SILODRIVERSTATE WnfSiloState;
    _DBGK_SILOSTATE DbgkSiloState;
    _UNICODE_STRING PsProtectedCurrentDirectory;
    _UNICODE_STRING PsProtectedEnvironment;
    _UNICODE_STRING NtSystemRoot;
    _UNICODE_STRING SiloRootDirectoryName;
    _SERVERSILO_STATE State;
    int ExitStatus;
    _WORK_QUEUE_ITEM TerminateWorkItem;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ESERVERSILO_GLOBALS) == EXPECTED_SIZE, "Size mismatch for _ESERVERSILO_GLOBALS");
