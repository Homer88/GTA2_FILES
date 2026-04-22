// Auto-generated structure: _PEB
// Source: _PEB.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _PEB
{
    uint8_t InheritedAddressSpace;
    uint8_t ReadImageFileExecOptions;
    uint8_t BeingDebugged;
    uint8_t BitField;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_PEB) == EXPECTED_SIZE, "Size mismatch for _PEB");
