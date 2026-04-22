// Auto-generated structure: _MINIDUMP_THREAD_EX
// Source: _MINIDUMP_THREAD_EX.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _MINIDUMP_THREAD_EX
{
    _MINIDUMP_MEMORY_DESCRIPTOR Stack;
    _MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
    _MINIDUMP_MEMORY_DESCRIPTOR BackingStore;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_MINIDUMP_THREAD_EX) == EXPECTED_SIZE, "Size mismatch for _MINIDUMP_THREAD_EX");
