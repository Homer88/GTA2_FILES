// Auto-generated structure: _OUTLINETEXTMETRICW
// Source: _OUTLINETEXTMETRICW.txt
// Fields count: 17
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _OUTLINETEXTMETRICW
{
    tagTEXTMETRICW otmTextMetrics;
    tagPANOSE otmPanoseNumber;
    int otmsCharSlopeRise;
    int otmsCharSlopeRun;
    int otmItalicAngle;
    int otmAscent;
    int otmDescent;
    tagRECT otmrcFontBox;
    int otmMacAscent;
    int otmMacDescent;
    tagPOINT otmptSubscriptSize;
    tagPOINT otmptSubscriptOffset;
    tagPOINT otmptSuperscriptSize;
    tagPOINT otmptSuperscriptOffset;
    int otmsStrikeoutPosition;
    int otmsUnderscoreSize;
    int otmsUnderscorePosition;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_OUTLINETEXTMETRICW) == EXPECTED_SIZE, "Size mismatch for _OUTLINETEXTMETRICW");
