// Auto-generated structure: USN_RECORD_V4
// Source: USN_RECORD_V4.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct USN_RECORD_V4
{
    USN_RECORD_COMMON_HEADER Header;
    _FILE_ID_128 FileReferenceNumber;
    _FILE_ID_128 ParentFileReferenceNumber;
    __int64 Usn;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(USN_RECORD_V4) == EXPECTED_SIZE, "Size mismatch for USN_RECORD_V4");
