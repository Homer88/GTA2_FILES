// Auto-generated structure: tagDDDEVICEIDENTIFIER2
// Source: tagDDDEVICEIDENTIFIER2.txt
// Fields count: 7
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagDDDEVICEIDENTIFIER2
{
    LARGE_INTEGER liDriverVersion;
    DWORD dwVendorId;
    DWORD dwDeviceId;
    DWORD dwSubSysId;
    DWORD dwRevision;
    GUID guidDeviceIdentifier;
    DWORD dwWHQLLevel;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagDDDEVICEIDENTIFIER2) == EXPECTED_SIZE, "Size mismatch for tagDDDEVICEIDENTIFIER2");
