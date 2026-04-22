// Auto-generated structure: _tagBINDINFO
// Source: _tagBINDINFO.txt
// Fields count: 13
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _tagBINDINFO
{
    ULONG cbSize;
    LPWSTR szExtraInfo;
    STGMEDIUM stgmedData;
    DWORD grfBindInfoF;
    DWORD dwBindVerb;
    LPWSTR szCustomVerb;
    DWORD cbstgmedData;
    DWORD dwOptions;
    DWORD dwOptionsFlags;
    DWORD dwCodePage;
    SECURITY_ATTRIBUTES securityAttributes;
    IID iid;
    DWORD dwReserved;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_tagBINDINFO) == EXPECTED_SIZE, "Size mismatch for _tagBINDINFO");
