// Auto-generated structure: _VOLUME_REFS_INFO_BUFFER
// Source: _VOLUME_REFS_INFO_BUFFER.txt
// Fields count: 78
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _VOLUME_REFS_INFO_BUFFER
{
    _LARGE_INTEGER CacheSizeInBytes;
    _LARGE_INTEGER AllocatedCacheInBytes;
    _LARGE_INTEGER PopulatedCacheInBytes;
    _LARGE_INTEGER InErrorCacheInBytes;
    _LARGE_INTEGER MemoryUsedForCacheMetadata;
    int CacheTransactionsOutstanding;
    int CacheLinesFree;
    int CacheLinesInError;
    _LARGE_INTEGER CacheHitsInBytes;
    _LARGE_INTEGER CacheMissesInBytes;
    _LARGE_INTEGER CachePopulationUpdatesInBytes;
    _LARGE_INTEGER CacheWriteThroughUpdatesInBytes;
    _LARGE_INTEGER CacheInvalidationsInBytes;
    _LARGE_INTEGER CacheOverReadsInBytes;
    _LARGE_INTEGER MetadataWrittenBytes;
    int CacheHitCounter;
    int CacheMissCounter;
    int CacheLineAllocationCounter;
    int CacheInvalidationsCounter;
    int CachePopulationUpdatesCounter;
    int CacheWriteThroughUpdatesCounter;
    int MaxCacheTransactionsOutstanding;
    int DataWritesReallocationCount;
    int DataInPlaceWriteCount;
    int MetadataAllocationsFastTierCount;
    int MetadataAllocationsSlowTierCount;
    int DataAllocationsFastTierCount;
    int DataAllocationsSlowTierCount;
    int DestagesSlowTierToFastTier;
    int DestagesFastTierToSlowTier;
    int SlowTierDataFillRatio;
    int FastTierDataFillRatio;
    int SlowTierMetadataFillRatio;
    int FastTierMetadataFillRatio;
    int SlowToFastDestageReadLatency;
    int SlowToFastDestageReadLatencyBase;
    int SlowToFastDestageWriteLatency;
    int SlowToFastDestageWriteLatencyBase;
    int FastToSlowDestageReadLatency;
    int FastToSlowDestageReadLatencyBase;
    int FastToSlowDestageWriteLatency;
    int FastToSlowDestageWriteLatencyBase;
    int SlowTierContainerFillRatio;
    int SlowTierContainerFillRatioBase;
    int FastTierContainerFillRatio;
    int FastTierContainerFillRatioBase;
    int TreeUpdateLatency;
    int TreeUpdateLatencyBase;
    int CheckpointLatency;
    int CheckpointLatencyBase;
    int TreeUpdateCount;
    int CheckpointCount;
    int LogWriteCount;
    int LogFillRatio;
    int ReadCacheInvalidationsForOverwrite;
    int ReadCacheInvalidationsForReuse;
    int ReadCacheInvalidationsGeneral;
    int ReadCacheChecksOnMount;
    int ReadCacheIssuesOnMount;
    int TrimLatency;
    int TrimLatencyBase;
    int DataCompactionCount;
    int CompactionReadLatency;
    int CompactionReadLatencyBase;
    int CompactionWriteLatency;
    int CompactionWriteLatencyBase;
    _LARGE_INTEGER DataInPlaceWriteClusterCount;
    int CompactionFailedDueToIneligibleContainer;
    int CompactionFailedDueToMaxFragmentation;
    int CompactedContainerFillRatio;
    int CompactedContainerFillRatioBase;
    int ContainerMoveRetryCount;
    int ContainerMoveFailedDueToIneligibleContainer;
    int CompactionFailureCount;
    int ContainerMoveFailureCount;
    _LARGE_INTEGER NumberOfDirtyMetadataPages;
    int NumberOfDirtyTableListEntries;
    int NumberOfDeleteQueueEntries;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_VOLUME_REFS_INFO_BUFFER) == EXPECTED_SIZE, "Size mismatch for _VOLUME_REFS_INFO_BUFFER");
