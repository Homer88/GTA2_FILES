// Auto-generated structure: TF_INPUTPROCESSORPROFILE
// Source: TF_INPUTPROCESSORPROFILE.txt
// Fields count: 9
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct TF_INPUTPROCESSORPROFILE
{
    DWORD dwProfileType;
    LANGID langid;
    CLSID clsid;
    GUID guidProfile;
    GUID catid;
    HKL hklSubstitute;
    DWORD dwCaps;
    HKL hkl;
    DWORD dwFlags;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(TF_INPUTPROCESSORPROFILE) == EXPECTED_SIZE, "Size mismatch for TF_INPUTPROCESSORPROFILE");
