// Auto-generated structure: _TEB32
// Source: _TEB32.txt
// Fields count: 12
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TEB32
{
    _NT_TIB32 NtTib;
    _CLIENT_ID32 ClientId;
    char PlaceholderCompatibilityMode;
    _ACTIVATION_CONTEXT_STACK32 _ActivationStack;
    int ExceptionCode;
    _GDI_TEB_BATCH32 GdiTebBatch;
    _CLIENT_ID32 RealClientId;
    _STRING32 StaticUnicodeString;
    LIST_ENTRY32 TlsLinks;
    _GUID ActivityId;
    int WowTebOffset;
    _GUID EffectiveContainerId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TEB32) == EXPECTED_SIZE, "Size mismatch for _TEB32");
