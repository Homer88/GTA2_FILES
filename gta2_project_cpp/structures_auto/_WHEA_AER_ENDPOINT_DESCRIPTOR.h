// Auto-generated structure: _WHEA_AER_ENDPOINT_DESCRIPTOR
// Source: _WHEA_AER_ENDPOINT_DESCRIPTOR.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_AER_ENDPOINT_DESCRIPTOR
{
    _WHEA_PCI_SLOT_NUMBER Slot;
    _AER_ENDPOINT_DESCRIPTOR_FLAGS Flags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_AER_ENDPOINT_DESCRIPTOR) == EXPECTED_SIZE, "Size mismatch for _WHEA_AER_ENDPOINT_DESCRIPTOR");
