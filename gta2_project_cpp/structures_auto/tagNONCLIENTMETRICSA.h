// Auto-generated structure: tagNONCLIENTMETRICSA
// Source: tagNONCLIENTMETRICSA.txt
// Fields count: 15
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagNONCLIENTMETRICSA
{
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    tagLOGFONTA lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    tagLOGFONTA lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    tagLOGFONTA lfMenuFont;
    tagLOGFONTA lfStatusFont;
    tagLOGFONTA lfMessageFont;
    int iPaddedBorderWidth;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagNONCLIENTMETRICSA) == EXPECTED_SIZE, "Size mismatch for tagNONCLIENTMETRICSA");
