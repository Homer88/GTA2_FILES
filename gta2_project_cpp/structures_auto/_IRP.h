// Auto-generated structure: _IRP
// Source: _IRP.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _IRP
{
    __int16 Type;
    _LIST_ENTRY ThreadListEntry;
    _IO_STATUS_BLOCK IoStatus;
    char RequestorMode;
    char StackCount;
    char CurrentLocation;
    char ApcEnvironment;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_IRP) == EXPECTED_SIZE, "Size mismatch for _IRP");
