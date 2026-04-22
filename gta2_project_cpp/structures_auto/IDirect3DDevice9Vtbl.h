// Auto-generated structure: IDirect3DDevice9Vtbl
// Source: IDirect3DDevice9Vtbl.txt
// Fields count: 24
// Generated for GTA 2 project (DirectX 6.1)

#pragma once

#include <windows.h>

// Forward declarations will be added later as needed

#pragma pack(push, 1)

struct IDirect3DDevice9Vtbl
{
    D3DDEVICE_CREATION_PARAMETERS CreationParameters;
    D3DPRESENT_PARAMETERS PresentParameters;
    D3DDISPLAYMODE DisplayMode;
    D3DCAPS9 Caps;
    UINT AvailableTextureMem;
    UINT SwapChains;
    UINT Textures;
    UINT VertexBuffers;
    UINT IndexBuffers;
    UINT VertexShaders;
    UINT PixelShaders;
    D3DVIEWPORT9 Viewport;
    D3DMATRIX ProjectionMatrix;
    D3DMATRIX ViewMatrix;
    D3DMATRIX WorldMatrix;
    DWORD FVF;
    UINT VertexSize;
    DWORD VertexShaderVersion;
    DWORD PixelShaderVersion;
    BOOL SoftwareVertexProcessing;
    D3DMATERIAL9 Material;
    D3DGAMMARAMP GammaRamp;
    RECT ScissorRect;
    BOOL DialogBoxMode;
};

#pragma pack(pop)

// Static size check (uncomment after verifying size)
// static_assert(sizeof(IDirect3DDevice9Vtbl) == EXPECTED_SIZE, "Size mismatch for IDirect3DDevice9Vtbl");
