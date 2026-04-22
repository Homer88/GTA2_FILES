// Auto-generated structure: _WER_MODERN_APP_DIAG_DATA
// Source: _WER_MODERN_APP_DIAG_DATA.txt
// Fields count: 24
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _WER_MODERN_APP_DIAG_DATA
{
    _WER_EXTENDED_DIAG_DATA_HEADER Header;
    _FILETIME AppObjectRunStartTime;
    _FILETIME AppObjectMainViewInitializeStartTime;
    _FILETIME AppObjectMainViewInitializeEndTime;
    _FILETIME AppObjectPrelaunchActivationStartTime;
    _FILETIME AppObjectFirstActivationStartTime;
    _FILETIME AppObjectActivationEventFiredTime;
    int AppObjectActivationWasThrottled;
    _FILETIME AppObjectLastSuspendStartTime;
    int AppObjectSuspendWasThrottled;
    _FILETIME AppObjectLastResumeStartTime;
    int CoreWindowMainWindowActivated;
    _FILETIME CoreWindowMainWindowActivatedTime;
    int CoreWindowLastVisibilityChangedVisibleStatus;
    _FILETIME CoreWindowLastVisibilityChangedNotificationTime;
    _WER_WWA_DIAG_DATA WwaFramework;
    _FILETIME LastAsyncOperationStartTime;
    _FILETIME AppObjectBackgroundTransitionStartTime;
    _FILETIME AppObjectBackgroundTransitionDispatchStartTime;
    int AppObjectVisibleViewCount;
    int AppObjectLastLifecycleAction;
    _FILETIME AppObjectLastLifecycleActionStartTime;
    _FILETIME AppObjectLastGetWindowFactoryStartTime;
    _FILETIME AppObjectLastForegroundActivationStartTime;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_WER_MODERN_APP_DIAG_DATA) == EXPECTED_SIZE, "Size mismatch for _WER_MODERN_APP_DIAG_DATA");
