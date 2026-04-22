// Auto-generated structure: _SE_CODEINTEGRITY_ORIGIN_CLAIM
// Source: _SE_CODEINTEGRITY_ORIGIN_CLAIM.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SE_CODEINTEGRITY_ORIGIN_CLAIM
{
    _SE_SAFE_OPEN_PROMPT_RESULTS PromptResults;
    _SINGLE_LIST_ENTRY AppIdTaggingClaimsHead;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SE_CODEINTEGRITY_ORIGIN_CLAIM) == EXPECTED_SIZE, "Size mismatch for _SE_CODEINTEGRITY_ORIGIN_CLAIM");
