// Auto-generated structure: tagNONCLIENTMETRICSW
// Source: tagNONCLIENTMETRICSW.txt
// Fields count: 15
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagNONCLIENTMETRICSW
{
    int iBorderWidth;
    int iScrollWidth;
    int iScrollHeight;
    int iCaptionWidth;
    int iCaptionHeight;
    tagLOGFONTW lfCaptionFont;
    int iSmCaptionWidth;
    int iSmCaptionHeight;
    tagLOGFONTW lfSmCaptionFont;
    int iMenuWidth;
    int iMenuHeight;
    tagLOGFONTW lfMenuFont;
    tagLOGFONTW lfStatusFont;
    tagLOGFONTW lfMessageFont;
    int iPaddedBorderWidth;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagNONCLIENTMETRICSW) == EXPECTED_SIZE, "Size mismatch for tagNONCLIENTMETRICSW");
