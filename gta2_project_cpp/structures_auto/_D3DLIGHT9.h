// Auto-generated structure: _D3DLIGHT9
// Source: _D3DLIGHT9.txt
// Fields count: 13
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct _D3DLIGHT9
{
    D3DLIGHTTYPE Type;
    D3DCOLORVALUE Diffuse;
    D3DCOLORVALUE Specular;
    D3DCOLORVALUE Ambient;
    D3DVECTOR Position;
    D3DVECTOR Direction;
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(_D3DLIGHT9) == EXPECTED_SIZE, "Size mismatch for _D3DLIGHT9");
