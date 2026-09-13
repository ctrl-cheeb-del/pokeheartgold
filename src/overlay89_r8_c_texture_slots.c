#include "overlay89_r8_private.h"

BOOL ov89_0225A958(Ov89Work *work, NNSG3dResTex *texture) {
    int i;

    for (i = 0; i < 32; i++) {
        if (work->textures[i] == NULL) {
            work->textures[i] = texture;
            return TRUE;
        }
    }
    return FALSE;
}

void ov89_0225A988(Ov89Work *work, NNSG3dResTex *texture) {
    int i;

    for (i = 0; i < 32; i++) {
        if (work->textures[i] == texture) {
            work->textures[i] = NULL;
            return;
        }
    }
}

BOOL ov89_0225A9B4(NNSG3dResTex *texture) {
    u32 textureSize;
    u32 paletteSize;
    NNSG3dTexKey textureKey;
    NNSG3dPlttKey paletteKey;

    texture->texInfo.vramKey = 0;
    textureSize = NNS_G3dTexGetRequiredSize(texture);
    paletteSize = NNS_G3dPlttGetRequiredSize(texture);
    textureKey = NNS_GfdDefaultFuncAllocTexVram(textureSize, FALSE, 0);
    if (textureKey == 0) {
        return FALSE;
    }
    paletteKey = NNS_GfdDefaultFuncAllocPlttVram(paletteSize, *(u16 *)((u8 *)texture + 0x20) & NNS_G3D_RESPLTT_USEPLTT4, 0);
    if (paletteKey == 0) {
        NNS_GfdDefaultFuncFreeTexVram(textureKey);
        return FALSE;
    }
    NNS_G3dTexSetTexKey(texture, textureKey, 0);
    NNS_G3dPlttSetPlttKey(texture, paletteKey);
    return TRUE;
}
