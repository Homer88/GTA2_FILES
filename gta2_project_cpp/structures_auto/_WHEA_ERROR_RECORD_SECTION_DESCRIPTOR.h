// Auto-generated structure: _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR
// Source: _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR
{
    _WHEA_REVISION Revision;
    _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS ValidBits;
    _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS Flags;
    _GUID SectionType;
    _GUID FRUId;
    _WHEA_ERROR_SEVERITY SectionSeverity;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WHEA_ERROR_RECORD_SECTION_DESCRIPTOR) == EXPECTED_SIZE, "Size mismatch for _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR");
