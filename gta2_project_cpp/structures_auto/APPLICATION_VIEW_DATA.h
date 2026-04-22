// Auto-generated structure: APPLICATION_VIEW_DATA
// Source: APPLICATION_VIEW_DATA.txt
// Fields count: 11
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct APPLICATION_VIEW_DATA
{
    APPLICATION_VIEW_STATE viewState;
    APPLICATION_VIEW_ORIENTATION viewOrientation;
    ADJACENT_DISPLAY_EDGES displayEdges;
    int fIsOnLockScreen;
    int fIsFullScreenMode;
    USER_INTERACTION_MODE userInteractionMode;
    VIEW_PRESENTATION_MODE presentationMode;
    APPLICATION_VIEW_MODE viewMode;
    APPLICATION_VIEW_MODE_FLAGS allowedViewModes;
    WindowTransparencyMode windowTransparencyMode;
    int canOpenInNewTab;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(APPLICATION_VIEW_DATA) == EXPECTED_SIZE, "Size mismatch for APPLICATION_VIEW_DATA");
