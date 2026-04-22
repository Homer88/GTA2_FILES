// Auto-generated structure: _EXCEPTION_RECORD
// Source: _EXCEPTION_RECORD.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _EXCEPTION_RECORD
{
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_EXCEPTION_RECORD) == EXPECTED_SIZE, "Size mismatch for _EXCEPTION_RECORD");
