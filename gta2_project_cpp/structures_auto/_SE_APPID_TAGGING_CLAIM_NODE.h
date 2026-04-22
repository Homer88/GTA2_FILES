// Auto-generated structure: _SE_APPID_TAGGING_CLAIM_NODE
// Source: _SE_APPID_TAGGING_CLAIM_NODE.txt
// Fields count: 3
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SE_APPID_TAGGING_CLAIM_NODE
{
    _UNICODE_STRING AppIdTaggingKey;
    _UNICODE_STRING AppIdTaggingValue;
    _SINGLE_LIST_ENTRY ListEntry;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SE_APPID_TAGGING_CLAIM_NODE) == EXPECTED_SIZE, "Size mismatch for _SE_APPID_TAGGING_CLAIM_NODE");
