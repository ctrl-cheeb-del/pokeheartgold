#include "overlay85_arcade_gfx_init_private.h"

void ov85_021E67F4(ArcScene *work);
void ov85_021E6854(void);
void ov85_021E6874(void);
void ov85_021E692C(void);
void ov85_021E6980(ArcScene *work);
void ov85_021E6A2C(ArcScene *work);
void ov85_021E6B68(ArcScene *work);
void ov85_021E6D68(ArcScene *work);
void ov85_021E6DAC(ArcScene *work, u32 a1);



void ov85_021E67F4(ArcScene *work) {
    Thunk_G3X_Reset();
    Camera_PushLookAtToNNSGlb();
    NNS_G3dGlbLightVector(GX_LIGHTID_0, 0, -FX16_ONE, 0);
    NNS_G3dGlbLightColor(GX_LIGHTID_0, GX_RGB(31, 31, 31));
    NNS_G3dGlbMaterialColorDiffAmb(GX_RGB(31, 31, 31), GX_RGB(31, 31, 31), FALSE);
    NNS_G3dGlbMaterialColorSpecEmi(GX_RGB(31, 31, 31), GX_RGB(31, 31, 31), FALSE);
    ov85_021E7628(work);
    ov85_021E782C(work);
    RequestSwap3DBuffers(0, 0);
    SpriteSystem_DrawSprites(work->unk_D98);
}

void ov85_021E6854(void) {
    GraphicsBanks banks = *(const GraphicsBanks *)ov85_021EA700;
    GfGfx_SetBanks(&banks);
}

void ov85_021E6874(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    reg_G2_BG0CNT = (u16)((reg_G2_BG0CNT & ~3) | 1);
    reg_G2_BG1CNT = (u16)(reg_G2_BG1CNT & ~3);
    reg_G2_BG2CNT = (u16)((reg_G2_BG2CNT & ~3) | 2);
    reg_G2_BG3CNT = (u16)((reg_G2_BG3CNT & ~3) | 3);
    reg_G2S_DB_BG0CNT = (u16)(reg_G2S_DB_BG0CNT & ~3);
    reg_G2S_DB_BG1CNT = (u16)((reg_G2S_DB_BG1CNT & ~3) | 1);
    reg_G2S_DB_BG2CNT = (u16)((reg_G2S_DB_BG2CNT & ~3) | 2);
    reg_G2S_DB_BG3CNT = (u16)((reg_G2S_DB_BG3CNT & ~3) | 3);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_BD, 11, 10);
}

void ov85_021E692C(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, FALSE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, FALSE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, FALSE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, FALSE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, FALSE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, FALSE);
}

void ov85_021E6980(ArcScene *work) {
    int i;

    NNS_G3dInit();
    G3X_InitMtxStack();
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(TRUE);
    for (i = 0; i < 8; i++) {
        work->unk_DA0[i] = 0x1084;
    }
    G3X_SetEdgeColorTable(work->unk_DA0);
    G3X_SetClearColor(GX_RGB(31, 31, 31), 0, 0x7FFF, 0x3F, FALSE);
    G3_SwapBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_W);
    G3_ViewPort(0, 0, 255, 191);
    GF_3DVramMan_InitFrameTexVramManager(1, TRUE);
    GF_3DVramMan_InitFramePlttVramManager(0x4000, TRUE);
}

void ov85_021E6A2C(ArcScene *work) {
    work->unk_D84 = BgConfig_Alloc(HEAP_ID_102);
    reg_GX_POWCNT |= 0x8000;
    {
        GraphicsModes modes = ov85_021EA538;
        SetBothScreensModesAndDisable(&modes);
    }
    {
        BgTemplate t = ov85_021EA60C;
        InitBgFromTemplate(work->unk_D84, GF_BG_LYR_MAIN_1, &t, GF_BG_TYPE_TEXT);
    }
    BgClearTilemapBufferAndCommit(work->unk_D84, GF_BG_LYR_MAIN_1);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 0x20, 0, HEAP_ID_102);
    {
        BgTemplate t = ov85_021EA628;
        InitBgFromTemplate(work->unk_D84, GF_BG_LYR_MAIN_2, &t, GF_BG_TYPE_TEXT);
    }
    BgClearTilemapBufferAndCommit(work->unk_D84, GF_BG_LYR_MAIN_2);
    {
        BgTemplate t = ov85_021EA644;
        InitBgFromTemplate(work->unk_D84, GF_BG_LYR_MAIN_3, &t, GF_BG_TYPE_TEXT);
    }
    BgClearTilemapBufferAndCommit(work->unk_D84, GF_BG_LYR_MAIN_3);
    {
        BgTemplate t = ov85_021EA660;
        InitBgFromTemplate(work->unk_D84, GF_BG_LYR_SUB_2, &t, GF_BG_TYPE_TEXT);
    }
    BgClearTilemapBufferAndCommit(work->unk_D84, GF_BG_LYR_SUB_2);
    {
        BgTemplate t = ov85_021EA67C;
        InitBgFromTemplate(work->unk_D84, GF_BG_LYR_SUB_3, &t, GF_BG_TYPE_TEXT);
    }
    BgClearTilemapBufferAndCommit(work->unk_D84, GF_BG_LYR_SUB_3);
}

void ov85_021E6B68(ArcScene *work) {
    void *buf;

    buf = ov85_021E8588(work, 0x11, 0);
    NNS_G2dGetUnpackedPaletteData(buf, &work->unk_D90);
    PaletteData_LoadPalette(work->unk_D9C, work->unk_D90->pRawData, PLTTBUF_MAIN_BG, 0, 0x40);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x14, 0);
    NNS_G2dGetUnpackedPaletteData(buf, &work->unk_D90);
    PaletteData_LoadPalette(work->unk_D9C, work->unk_D90->pRawData, PLTTBUF_SUB_BG, 0, 0x40);
    Heap_Free(buf);

    PaletteData_BlendPalettes(work->unk_D9C, PLTTBUF_SUB_BG, 0xFFFF, 8, 0);

    buf = ov85_021E8588(work, 0x10, 0);
    NNS_G2dGetUnpackedCharacterData(buf, &work->unk_D8C);
    BG_LoadCharTilesData(work->unk_D84, GF_BG_LYR_MAIN_3, work->unk_D8C->pRawData, work->unk_D8C->szByte, 0);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x16, 0);
    NNS_G2dGetUnpackedCharacterData(buf, &work->unk_D8C);
    BG_LoadCharTilesData(work->unk_D84, GF_BG_LYR_SUB_2, work->unk_D8C->pRawData, work->unk_D8C->szByte, 0);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x15, 0);
    NNS_G2dGetUnpackedCharacterData(buf, &work->unk_D8C);
    BG_LoadCharTilesData(work->unk_D84, GF_BG_LYR_SUB_3, work->unk_D8C->pRawData, work->unk_D8C->szByte, 0);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x13, 0);
    NNS_G2dGetUnpackedScreenData(buf, &work->unk_D88);
    BG_LoadScreenTilemapData(work->unk_D84, GF_BG_LYR_MAIN_2, work->unk_D88->rawData, work->unk_D88->szByte);
    BgCommitTilemapBufferToVram(work->unk_D84, GF_BG_LYR_MAIN_2);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x12, 0);
    NNS_G2dGetUnpackedScreenData(buf, &work->unk_D88);
    BG_LoadScreenTilemapData(work->unk_D84, GF_BG_LYR_MAIN_3, work->unk_D88->rawData, work->unk_D88->szByte);
    BgCommitTilemapBufferToVram(work->unk_D84, GF_BG_LYR_MAIN_3);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x18, 0);
    NNS_G2dGetUnpackedScreenData(buf, &work->unk_D88);
    BG_LoadScreenTilemapData(work->unk_D84, GF_BG_LYR_SUB_2, work->unk_D88->rawData, work->unk_D88->szByte);
    BgCommitTilemapBufferToVram(work->unk_D84, GF_BG_LYR_SUB_2);
    Heap_Free(buf);

    buf = ov85_021E8588(work, 0x17, 0);
    NNS_G2dGetUnpackedScreenData(buf, &work->unk_D88);
    BG_LoadScreenTilemapData(work->unk_D84, GF_BG_LYR_SUB_3, work->unk_D88->rawData, work->unk_D88->szByte);
    BgCommitTilemapBufferToVram(work->unk_D84, GF_BG_LYR_SUB_3);
    Heap_Free(buf);
}

void ov85_021E6D68(ArcScene *work) {
    FreeBgTilemapBuffer(work->unk_D84, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(work->unk_D84, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(work->unk_D84, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(work->unk_D84, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(work->unk_D84, GF_BG_LYR_SUB_3);
    Heap_Free(work->unk_D84);
}

void ov85_021E6DAC(ArcScene *work, u32 a1) {
    void *buf = ov85_021E8588(work, a1, 0);
    NNS_G2dGetUnpackedScreenData(buf, &work->unk_D88);
    BG_LoadScreenTilemapData(work->unk_D84, GF_BG_LYR_SUB_2, work->unk_D88->rawData, work->unk_D88->szByte);
    BgCommitTilemapBufferToVram(work->unk_D84, GF_BG_LYR_SUB_2);
    Heap_Free(buf);
}
