// Auto-generated structure: _SPC_IMAGE
// Source: _SPC_IMAGE.txt
// Fields count: 4
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _SPC_IMAGE
{
    _CRYPTOAPI_BLOB Bitmap;
    _CRYPTOAPI_BLOB Metafile;
    _CRYPTOAPI_BLOB EnhancedMetafile;
    _CRYPTOAPI_BLOB GifFile;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_SPC_IMAGE) == EXPECTED_SIZE, "Size mismatch for _SPC_IMAGE");
