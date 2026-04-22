// Auto-generated structure: _TEB64
// Source: _TEB64.txt
// Fields count: 12
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _TEB64
{
    _NT_TIB64 NtTib;
    _CLIENT_ID64 ClientId;
    char PlaceholderCompatibilityMode;
    _ACTIVATION_CONTEXT_STACK64 _ActivationStack;
    int ExceptionCode;
    _GDI_TEB_BATCH64 GdiTebBatch;
    _CLIENT_ID64 RealClientId;
    _STRING64 StaticUnicodeString;
    LIST_ENTRY64 TlsLinks;
    _GUID ActivityId;
    int WowTebOffset;
    _GUID EffectiveContainerId;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_TEB64) == EXPECTED_SIZE, "Size mismatch for _TEB64");
