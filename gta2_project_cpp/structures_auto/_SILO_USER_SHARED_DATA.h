// Auto-generated structure: _SILO_USER_SHARED_DATA
// Source: _SILO_USER_SHARED_DATA.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SILO_USER_SHARED_DATA
{
    __int64 ConsoleSessionForegroundProcessId;
    _NT_PRODUCT_TYPE NtProductType;
    _KSYSTEM_TIME TimeZoneBias;
    _LARGE_INTEGER TimeZoneBiasEffectiveStart;
    _LARGE_INTEGER TimeZoneBiasEffectiveEnd;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SILO_USER_SHARED_DATA) == EXPECTED_SIZE, "Size mismatch for _SILO_USER_SHARED_DATA");
