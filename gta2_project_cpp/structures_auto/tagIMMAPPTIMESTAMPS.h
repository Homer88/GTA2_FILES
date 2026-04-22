// Auto-generated structure: tagIMMAPPTIMESTAMPS
// Source: tagIMMAPPTIMESTAMPS.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagIMMAPPTIMESTAMPS
{
    _FILETIME ftCreation;
    _FILETIME ftClosed;
    _FILETIME ftActivation;
    _FILETIME ftInactive;
    _FILETIME ftVisible;
    _FILETIME ftHidden;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagIMMAPPTIMESTAMPS) == EXPECTED_SIZE, "Size mismatch for tagIMMAPPTIMESTAMPS");
