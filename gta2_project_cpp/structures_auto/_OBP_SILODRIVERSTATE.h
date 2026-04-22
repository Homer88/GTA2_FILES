// Auto-generated structure: _OBP_SILODRIVERSTATE
// Source: _OBP_SILODRIVERSTATE.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OBP_SILODRIVERSTATE
{
    _OBP_SYSTEM_DOS_DEVICE_STATE SystemDosDeviceState;
    _EX_PUSH_LOCK DeviceMapLock;
    _OBJECT_NAMESPACE_LOOKUPTABLE PrivateNamespaceLookupTable;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OBP_SILODRIVERSTATE) == EXPECTED_SIZE, "Size mismatch for _OBP_SILODRIVERSTATE");
