// Auto-generated structure: _FILE_OBJECT
// Source: _FILE_OBJECT.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _FILE_OBJECT
{
    __int16 Type;
    __int16 Size;
    int FinalStatus;
    _UNICODE_STRING FileName;
    _LARGE_INTEGER CurrentByteOffset;
    _KEVENT Lock;
    _KEVENT Event;
    _LIST_ENTRY IrpList;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_FILE_OBJECT) == EXPECTED_SIZE, "Size mismatch for _FILE_OBJECT");
