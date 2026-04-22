// Auto-generated structure: MINIDUMP_EXCEPTION_STREAM
// Source: MINIDUMP_EXCEPTION_STREAM.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct MINIDUMP_EXCEPTION_STREAM
{
    _MINIDUMP_EXCEPTION ExceptionRecord;
    _MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(MINIDUMP_EXCEPTION_STREAM) == EXPECTED_SIZE, "Size mismatch for MINIDUMP_EXCEPTION_STREAM");
