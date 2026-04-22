// Auto-generated structure: _SYSTEM_PROCESS_INFORMATION
// Source: _SYSTEM_PROCESS_INFORMATION.txt
// Fields count: 12
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SYSTEM_PROCESS_INFORMATION
{
    _LARGE_INTEGER WorkingSetPrivateSize;
    _LARGE_INTEGER CreateTime;
    _LARGE_INTEGER UserTime;
    _LARGE_INTEGER KernelTime;
    _UNICODE_STRING ImageName;
    int BasePriority;
    _LARGE_INTEGER ReadOperationCount;
    _LARGE_INTEGER WriteOperationCount;
    _LARGE_INTEGER OtherOperationCount;
    _LARGE_INTEGER ReadTransferCount;
    _LARGE_INTEGER WriteTransferCount;
    _LARGE_INTEGER OtherTransferCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SYSTEM_PROCESS_INFORMATION) == EXPECTED_SIZE, "Size mismatch for _SYSTEM_PROCESS_INFORMATION");
