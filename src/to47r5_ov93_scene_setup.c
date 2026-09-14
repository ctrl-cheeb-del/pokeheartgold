#include "to47r5_ov93_scene_setup_private.h"

void ov93_0225D07C(void *unused, void *p) {
    VecFx32 scale;
    VecFx32 trans;
    MtxFx33 rot;
    u32 one;

    scale.x = FX32_ONE;
    scale.y = FX32_ONE;
    scale.z = FX32_ONE;
    trans.x = 0;
    trans.y = 0;
    trans.z = 0;
    MTX_Identity33_(&rot);
    ov93_02262034(p, BAT(p, 0x15A8));
    ov93_02261354(p, BAT(p, 0x1468));
    ov93_02261D1C(p, BAT(p, 0x1560));
    ov93_0225FFF8(p);
    ov93_0225FE80(p, PAT(p, 0x2C), BAT(p, 0x1428));
    ov93_02260660(p);
    ov93_0225E03C(p);
    ov93_02260A30(p);
    Thunk_G3X_Reset();
    Camera_SetStaticPtr(PAT(p, 0x9C));
    Camera_ApplyPerspectiveType(1, PAT(p, 0x9C));
    Camera_PushLookAtToNNSGlb();
    NNS_G3dGlbLightVector(GX_LIGHTID_0, 0, -FX32_ONE, 0);
    NNS_G3dGlbLightColor(GX_LIGHTID_0, 0x739C);
    NNS_G3dGlbMaterialColorDiffAmb(0x7FFF, 0x7FFF, FALSE);
    NNS_G3dGlbMaterialColorSpecEmi(0x7FFF, 0x7FFF, FALSE);
    NNS_G3dGlbSetBaseTrans(&trans);
    MI_Copy36B(&rot, &NNS_G3dGlb.prmBaseRot);
    NNS_G3dGlb.flag &= ~0xa4;
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbFlushP();
    ov93_0225E898(p, PAT(p, 0xD4));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    sub_020181EC(BAT(p, 0x13B0));
    sub_020181EC(BAT(p, 0xE8));
    ov93_0225E0A4(p);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    Thunk_G3X_Reset();
    if (sub_0201543C() > 0) {
        Thunk_G3X_Reset();
    }
    sub_02015460();
    SpriteSystem_DrawSprites(PAT(p, 0x28));
    SpriteSystem_UpdateTransfer();
    RequestSwap3DBuffers(0, 0);
    sub_020399FC(0x75, PAT(p, 0x2C));
}

void ov93_0225D1D8(BgConfig *bgConfig) {
    BgTemplate templates[3];
    GraphicsBanks banks;
    GraphicsModes modes;
    s32 i;

    GfGfx_DisableEngineAPlanes();
    banks = ov93_02262AC8;
    GfGfx_SetBanks(&banks);
    MIi_CpuClear32(0, (u32 *)0x06000000, 0x80000);
    MIi_CpuClear32(0, (u32 *)0x06200000, 0x20000);
    MIi_CpuClear32(0, (u32 *)0x06400000, 0x40000);
    MIi_CpuClear32(0, (u32 *)0x06600000, 0x20000);
    modes = ov93_02262A44;
    SetBothScreensModesAndDisable(&modes);
    ARRAY_ASSIGN(templates, ov93_02262B40);
    InitBgFromTemplate(bgConfig, 1, &templates[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    BgSetPosTextAndCommit(bgConfig, 1, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 1, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 2, &templates[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    BgSetPosTextAndCommit(bgConfig, 2, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 2, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 3, &templates[2], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    BgSetPosTextAndCommit(bgConfig, 3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 3, BG_POS_OP_SET_Y, 0);
    G2_SetBG0Priority(2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    for (i = 0; i < NELEMS(ov93_02262B94); i++) {
        if (i < 3) {
            InitBgFromTemplate(bgConfig, (u8)(i + 4), &ov93_02262B94[i], 0);
        } else {
            InitBgFromTemplate(bgConfig, (u8)(i + 4), &ov93_02262B94[i], 1);
        }
        BG_ClearCharDataRange((u8)(i + 4), 0x20, 0, HEAP_ID_117);
        BgClearTilemapBufferAndCommit(bgConfig, (u8)(i + 4));
        BgSetPosTextAndCommit(bgConfig, (u8)(i + 4), BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, (u8)(i + 4), BG_POS_OP_SET_Y, 0);
    }
    ToggleBgLayer(7, 0);
}

void ov93_0225D380(void *p) {
    AddWindowParameterized(PAT(p, 0x2C), (Window *)BAT(p, 0x30), 1, 0xB, 0x13, 0x14, 4, 0xE, 0x300);
    AddWindowParameterized(PAT(p, 0x2C), (Window *)BAT(p, 0x40), 4, 0x12, 1, 0xA, 2, 5, 0x314);
    AddWindowParameterized(PAT(p, 0x2C), (Window *)BAT(p, 0x50), 4, 0x15, 0xE, 0xA, 2, 5, 0x328);
    AddWindowParameterized(PAT(p, 0x2C), (Window *)BAT(p, 0x60), 4, 1, 0xE, 0xA, 2, 5, 0x33C);
    FillWindowPixelBuffer((Window *)BAT(p, 0x40), 0xF);
    FillWindowPixelBuffer((Window *)BAT(p, 0x50), 0xF);
    FillWindowPixelBuffer((Window *)BAT(p, 0x60), 0xF);
    AddWindowParameterized(PAT(p, 0x2C), (Window *)BAT(p, 0x70), 4, 2, 0x13, 0x1C, 4, 5, 0x359);
    FillWindowPixelBuffer((Window *)BAT(p, 0x70), 0xF);
}
