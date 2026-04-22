// Auto-generated structure: _EXCEPTION_LOG
// Source: _EXCEPTION_LOG.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _EXCEPTION_LOG
{
    _EXCEPTION_RECORD ExceptionRecord;
    _CONTEXT ContextRecord;
    _EXCEPTION_LOG_TYPE Type;
    int Disposition;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_EXCEPTION_LOG) == EXPECTED_SIZE, "Size mismatch for _EXCEPTION_LOG");
