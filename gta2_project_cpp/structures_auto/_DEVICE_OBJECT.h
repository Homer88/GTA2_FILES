// Auto-generated structure: _DEVICE_OBJECT
// Source: _DEVICE_OBJECT.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DEVICE_OBJECT
{
    __int16 Type;
    int ReferenceCount;
    char StackSize;
    _KDEVICE_QUEUE DeviceQueue;
    _KDPC Dpc;
    _KEVENT DeviceLock;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DEVICE_OBJECT) == EXPECTED_SIZE, "Size mismatch for _DEVICE_OBJECT");
