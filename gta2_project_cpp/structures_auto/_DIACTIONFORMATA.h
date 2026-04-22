// Auto-generated structure: _DIACTIONFORMATA
// Source: _DIACTIONFORMATA.txt
// Fields count: 13
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DIACTIONFORMATA
{
    DWORD dwSize;
    DWORD dwActionSize;
    DWORD dwDataSize;
    DWORD dwNumActions;
    LPDIACTIONA rgoAction;
    GUID guidActionMap;
    DWORD dwGenre;
    DWORD dwBufferSize;
    LONG lAxisMin;
    LONG lAxisMax;
    HINSTANCE hInstString;
    FILETIME ftTimeStamp;
    DWORD dwCRC;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DIACTIONFORMATA) == EXPECTED_SIZE, "Size mismatch for _DIACTIONFORMATA");
