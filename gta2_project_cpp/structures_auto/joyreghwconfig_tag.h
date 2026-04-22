// Auto-generated structure: joyreghwconfig_tag
// Source: joyreghwconfig_tag.txt
// Fields count: 5
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct joyreghwconfig_tag
{
    JOYREGHWSETTINGS hws;
    DWORD dwUsageSettings;
    JOYREGHWVALUES hwv;
    DWORD dwType;
    DWORD dwReserved;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(joyreghwconfig_tag) == EXPECTED_SIZE, "Size mismatch for joyreghwconfig_tag");
