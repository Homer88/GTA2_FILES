// Auto-generated structure: _D3DADAPTER_IDENTIFIER9
// Source: _D3DADAPTER_IDENTIFIER9.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _D3DADAPTER_IDENTIFIER9
{
    LARGE_INTEGER DriverVersion;
    DWORD VendorId;
    DWORD DeviceId;
    DWORD SubSysId;
    DWORD Revision;
    GUID DeviceIdentifier;
    DWORD WHQLLevel;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_D3DADAPTER_IDENTIFIER9) == EXPECTED_SIZE, "Size mismatch for _D3DADAPTER_IDENTIFIER9");
