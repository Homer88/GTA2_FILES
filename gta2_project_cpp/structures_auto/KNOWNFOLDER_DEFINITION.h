// Auto-generated structure: KNOWNFOLDER_DEFINITION
// Source: KNOWNFOLDER_DEFINITION.txt
// Fields count: 13
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct KNOWNFOLDER_DEFINITION
{
    KF_CATEGORY category;
    LPWSTR pszName;
    LPWSTR pszDescription;
    KNOWNFOLDERID fidParent;
    LPWSTR pszRelativePath;
    LPWSTR pszParsingName;
    LPWSTR pszTooltip;
    LPWSTR pszLocalizedName;
    LPWSTR pszIcon;
    LPWSTR pszSecurity;
    DWORD dwAttributes;
    KF_DEFINITION_FLAGS kfdFlags;
    FOLDERTYPEID ftidType;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(KNOWNFOLDER_DEFINITION) == EXPECTED_SIZE, "Size mismatch for KNOWNFOLDER_DEFINITION");
