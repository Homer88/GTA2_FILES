// Auto-generated structure: _ETW_COVERAGE_SAMPLER_BLOOM_INFO
// Source: _ETW_COVERAGE_SAMPLER_BLOOM_INFO.txt
// Fields count: 2
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ETW_COVERAGE_SAMPLER_BLOOM_INFO
{
    _EVENT_TRACE_COVERAGE_SAMPLER_INFORMATION Common;
    _ETW_COVERAGE_SAMPLER_BLOOM_FILTER Bloom;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ETW_COVERAGE_SAMPLER_BLOOM_INFO) == EXPECTED_SIZE, "Size mismatch for _ETW_COVERAGE_SAMPLER_BLOOM_INFO");
