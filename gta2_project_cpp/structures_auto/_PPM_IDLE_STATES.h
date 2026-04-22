// Auto-generated structure: _PPM_IDLE_STATES
// Source: _PPM_IDLE_STATES.txt
// Fields count: 8
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _PPM_IDLE_STATES
{
    int PreviousStatus;
    _KAFFINITY_EX PrimaryProcessorMask;
    _KAFFINITY_EX SecondaryProcessorMask;
    _PROCESSOR_IDLE_PREPARE_INFO PrepareInfo;
    _KAFFINITY_EX DeepIdleSnapshot;
    _PPM_SELECTION_MENU ProcessorMenu;
    _PPM_SELECTION_MENU CoordinatedMenu;
    _PPM_COORDINATED_SELECTION CoordinatedSelection;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_PPM_IDLE_STATES) == EXPECTED_SIZE, "Size mismatch for _PPM_IDLE_STATES");
