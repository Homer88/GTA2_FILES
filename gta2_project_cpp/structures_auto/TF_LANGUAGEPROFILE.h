// Auto-generated structure: TF_LANGUAGEPROFILE
// Source: TF_LANGUAGEPROFILE.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct TF_LANGUAGEPROFILE
{
    CLSID clsid;
    LANGID langid;
    GUID catid;
    BOOL fActive;
    GUID guidProfile;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(TF_LANGUAGEPROFILE) == EXPECTED_SIZE, "Size mismatch for TF_LANGUAGEPROFILE");
