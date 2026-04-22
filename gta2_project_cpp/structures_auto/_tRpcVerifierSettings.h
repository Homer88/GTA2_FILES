// Auto-generated structure: _tRpcVerifierSettings
// Source: _tRpcVerifierSettings.txt
// Fields count: 18
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _tRpcVerifierSettings
{
    int fFaultInjectImpersonateClient;
    int fCorruptionInjectServerReceives;
    int fCorruptionInjectClientReceives;
    int fCorruptionInjectSends;
    int fCorruptionInjectNdrSends;
    int fCorruptionInjectNdrReturns;
    int fCorruptionInjectNdr;
    tCorruptionPattern CorruptionPattern;
    tCorruptionSizeType CorruptionSizeType;
    tCorruptionDistributionType CorruptionDistributionType;
    int fFaultInjectTransports;
    int fSendReplay;
    int fPauseInject;
    tDelayType PauseInjectIntervalType;
    tDelayType PauseInjectPauseType;
    int fPauseInjectExternalAPIs;
    int IsHighPrivilege;
    int fSupressAppVerifierBreaks;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_tRpcVerifierSettings) == EXPECTED_SIZE, "Size mismatch for _tRpcVerifierSettings");
