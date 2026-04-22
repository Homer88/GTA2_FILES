// Auto-generated structure: _KUSER_SHARED_DATA
// Source: _KUSER_SHARED_DATA.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _KUSER_SHARED_DATA
{
    _NT_PRODUCT_TYPE NtProductType;
    _ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;
    _LARGE_INTEGER SystemExpirationDate;
    __int64 QpcFrequency;
    __int64 ConsoleSessionForegroundProcessId;
    _LARGE_INTEGER TimeZoneBiasEffectiveStart;
    _LARGE_INTEGER TimeZoneBiasEffectiveEnd;
    _XSTATE_CONFIGURATION XState;
    _KSYSTEM_TIME FeatureConfigurationChangeStamp;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_KUSER_SHARED_DATA) == EXPECTED_SIZE, "Size mismatch for _KUSER_SHARED_DATA");
