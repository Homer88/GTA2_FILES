// Auto-generated structure: tagSTGMEDIUM
// Source: tagSTGMEDIUM.txt
// Fields count: 6
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct tagSTGMEDIUM
{
    DWORD tymed;
    HBITMAP hBitmap;
    HMETAFILEPICT hMetaFilePict;
    HENHMETAFILE hEnhMetaFile;
    HGLOBAL hGlobal;
    LPOLESTR lpszFileName;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(tagSTGMEDIUM) == EXPECTED_SIZE, "Size mismatch for tagSTGMEDIUM");
