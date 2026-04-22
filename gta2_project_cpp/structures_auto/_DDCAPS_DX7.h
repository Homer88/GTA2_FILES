// Auto-generated structure: _DDCAPS_DX7
// Source: _DDCAPS_DX7.txt
// Fields count: 52
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _DDCAPS_DX7
{
    DWORD dwSize;
    DWORD dwCaps;
    DWORD dwCaps2;
    DWORD dwCKeyCaps;
    DWORD dwFXCaps;
    DWORD dwFXAlphaCaps;
    DWORD dwPalCaps;
    DWORD dwSVCaps;
    DWORD dwAlphaBltConstBitDepths;
    DWORD dwAlphaBltPixelBitDepths;
    DWORD dwAlphaBltSurfaceBitDepths;
    DWORD dwAlphaOverlayConstBitDepths;
    DWORD dwAlphaOverlayPixelBitDepths;
    DWORD dwAlphaOverlaySurfaceBitDepths;
    DWORD dwZBufferBitDepths;
    DWORD dwVidMemTotal;
    DWORD dwVidMemFree;
    DWORD dwMaxVisibleOverlays;
    DWORD dwCurrVisibleOverlays;
    DWORD dwNumFourCCCodes;
    DWORD dwAlignBoundarySrc;
    DWORD dwAlignSizeSrc;
    DWORD dwAlignBoundaryDest;
    DWORD dwAlignSizeDest;
    DWORD dwAlignStrideAlign;
    DDSCAPS ddsOldCaps;
    DWORD dwMinOverlayStretch;
    DWORD dwMaxOverlayStretch;
    DWORD dwMinLiveVideoStretch;
    DWORD dwMaxLiveVideoStretch;
    DWORD dwMinHwCodecStretch;
    DWORD dwMaxHwCodecStretch;
    DWORD dwReserved1;
    DWORD dwReserved2;
    DWORD dwReserved3;
    DWORD dwSVBCaps;
    DWORD dwSVBCKeyCaps;
    DWORD dwSVBFXCaps;
    DWORD dwVSBCaps;
    DWORD dwVSBCKeyCaps;
    DWORD dwVSBFXCaps;
    DWORD dwSSBCaps;
    DWORD dwSSBCKeyCaps;
    DWORD dwSSBFXCaps;
    DWORD dwMaxVideoPorts;
    DWORD dwCurrVideoPorts;
    DWORD dwSVBCaps2;
    DWORD dwNLVBCaps;
    DWORD dwNLVBCaps2;
    DWORD dwNLVBCKeyCaps;
    DWORD dwNLVBFXCaps;
    DDSCAPS2 ddsCaps;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_DDCAPS_DX7) == EXPECTED_SIZE, "Size mismatch for _DDCAPS_DX7");
