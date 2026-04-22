// Auto-generated structure: _ETW_COVERAGE_SAMPLER_STATS
// Source: _ETW_COVERAGE_SAMPLER_STATS.txt
// Fields count: 15
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _ETW_COVERAGE_SAMPLER_STATS
{
    int SamplesAdded;
    int SamplesFound;
    int SamplesDropped;
    int SamplesRaisedUM;
    int SamplesMappedUM;
    int SamplesRaisedKM;
    int SamplesMappedKM;
    int SamplingPaused;
    int ApcNotAvailable;
    int CaptureBufferNotAvailable;
    int SampleBufferNotAvailable;
    int ProfileSampleCount;
    int CSwitchSampleCount;
    int RThreadSampleCount;
    int PGFaultSampleCount;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_ETW_COVERAGE_SAMPLER_STATS) == EXPECTED_SIZE, "Size mismatch for _ETW_COVERAGE_SAMPLER_STATS");
