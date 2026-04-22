// Auto-generated structure: _AHC_SERVICE_DATA
// Source: _AHC_SERVICE_DATA.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _AHC_SERVICE_DATA
{
    _AHC_SERVICE_LOOKUP Lookup;
    _AHC_SERVICE_UPDATE Update;
    _AHC_SERVICE_DATACACHE Cache;
    _AHC_SERVICE_LOOKUP_CDB LookupCdb;
    _AHC_SERVICE_CLEAR Clear;
    _AHC_SERVICE_REMOVE Remove;
    _AHC_SERVICE_HWID_QUERY HwIdQuery;
    _AHC_SERVICE_INIT_PROCESS_DATA InitData;
    int DriverStatus;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_AHC_SERVICE_DATA) == EXPECTED_SIZE, "Size mismatch for _AHC_SERVICE_DATA");
