#include "to47_overlay71_scene_setup_r44_private.h"

void *ov71_0224B138(void *ctx)
{
    void *work = Heap_Alloc(0x39, 0x88);

    if (work != NULL) {
        PTR_AT(work, 0) = ctx;
        U32_AT(work, 4) = 0;
        PTR_AT(work, 0x58) = ov71_02247384(ctx);
        PTR_AT(work, 0x10) = PokepicManager_Create(0x39);
        PTR_AT(work, 0x14) = NULL;
        PTR_AT(work, 0x6c) = String_New(0x12c, 0x39);
        PTR_AT(work, 0x70) = String_New(0x12c, 0x39);
        PTR_AT(work, 0x7c) = NULL;
        PTR_AT(work, 0x80) = NULL;
        PTR_AT(work, 0x74) = NULL;
        PTR_AT(work, 0x84) = NARC_New(0xb4, 0x39);
    }
    return work;
}

void ov71_0224B198(void *work)
{
    if (work != NULL) {
        ov71_0224B970(work);
        ov71_0224B8EC(work);
        ov71_0224BA48(PTR_AT(work, 0x80));
        String_Delete(PTR_AT(work, 0x6c));
        String_Delete(PTR_AT(work, 0x70));
        if (PTR_AT(work, 0x74) != NULL) {
            ov71_02247498(PTR_AT(work, 0x74));
        }
        FreeBgTilemapBuffer(PTR_AT(work, 0x58), 1);
        RemoveWindow((u8 *)work + 0x5c);
        if (PTR_AT(work, 0x14) != NULL) {
            Pokepic_Delete(PTR_AT(work, 0x14));
        }
        NARC_Delete(PTR_AT(work, 0x84));
        PokepicManager_Delete(PTR_AT(work, 0x10));
        Heap_Free(work);
    }
}

BOOL ov71_0224B1FC(void *work, u32 *state)
{
    if (*state < 4) {
        if (ov71_0224BF84[*state](work, (u32 *)((u8 *)work + 4))) {
            (*state)++;
            U32_AT(work, 4) = 0;
        }
        ov71_0224B234(work);
        return FALSE;
    }
    return TRUE;
}

void ov71_0224B234(void *work)
{
    u32 value;

    G3X_Reset();
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeFlushBuffer();
    NNS_G2dSetupSoftwareSpriteCamera();
    PokepicManager_HandleLoadImgAndOrPltt(PTR_AT(work, 0x10));
    PokepicManager_DrawAll(PTR_AT(work, 0x10));
    value = 1;
    NNS_G3dGeBufferOP_N(0x12, &value, 1);
    if (PTR_AT(work, 0x74) != NULL) {
        ov71_022474CC(PTR_AT(work, 0x74));
    }
    RequestSwap3DBuffers(0, 0);
}

BOOL ov71_0224B280(void *work)
{
    Ov71Rotation rotation;
    volatile u16 *reg;

    GfGfx_SetBanks(ov71_0224BFDC);
    reg = (u16 *)0x04000304;
    *reg |= 0x8000;
    SetBothScreensModesAndDisable(ov71_0224BF94);
    InitBgFromTemplate(PTR_AT(work, 0x58), 1, ov71_0224BFA4, 0);
    InitBgFromTemplate(PTR_AT(work, 0x58), 2, ov71_0224BFC0, 0);
    GfGfx_EngineATogglePlanes(1, 1);
    reg = (u16 *)0x04000008;
    *reg = (*reg & ~3) | 1;
    BG_FillCharDataRange(PTR_AT(work, 0x58), 1, 0, 1, 0);
    FillBgTilemapRect(PTR_AT(work, 0x58), 1, 0, 0, 0, 0x20, 0x20, 0);
    LoadUserFrameGfx2(PTR_AT(work, 0x58), 1, 0x6d, 2, (u8)ov71_022473D0(PTR_AT(work, 0)), 0x39);
    AddWindowParameterized(PTR_AT(work, 0x58), (u8 *)work + 0x5c, 1, 2, 0x13, 0x1b, 4, 1, 1);
    FillWindowPixelBuffer((u8 *)work + 0x5c, 0xf);
    GfGfxLoader_GXLoadPal(0x10, 8, 0, 0x20, 0x20, 0x39);
    BgCommitTilemapBufferToVram(PTR_AT(work, 0x58), 1);
    GfGfxLoader_LoadCharData(0x59, 0x16, PTR_AT(work, 0x58), 2, 0, 0, 1, 0x39);
    GfGfxLoader_LoadScrnData(0x59, 0x15, PTR_AT(work, 0x58), 2, 0, 0, 1, 0x39);
    GfGfxLoader_GXLoadPal(0x59, 0x17, 0, 0, 0x20, 0x39);
    ov71_0224B720(work);
    PTR_AT(work, 0x74) = ov71_0224744C(1, 0, 0, 0);
    PTR_AT(work, 0x14) = ov71_0224B7EC(work);
    Pokepic_SetAttr(PTR_AT(work, 0x14), 6, 1);
    PTR_AT(work, 0x78) = ov71_02247610(PTR_AT(work, 0x74), 0, 0x59, 0x1b, 0, 0x13000, 0x78000, 0);
    rotation = ov71_0224BF7C;
    ov71_022476EC(PTR_AT(work, 0x78), &rotation);
    ov71_0224B848(work);
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
    G2x_SetBlendAlpha_(0x04000050, 1, 4, 0x10, 0);
    BeginNormalPaletteFade(3, 1, 1, 0, 0x10, 1, 0x39);
    return TRUE;
}
