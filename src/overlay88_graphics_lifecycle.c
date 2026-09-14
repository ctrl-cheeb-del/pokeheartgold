#include "overlay88_graphics_lifecycle_private.h"

void ov88_02258B34(Ov88R3Work *work, enum HeapID heapID) {
    int i;

    SetBothScreensModesAndDisable(&ov88_02259934);
    work->bg = BgConfig_Alloc(heapID);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    for (i = 0; i < 5; i++) {
        InitBgFromTemplate(work->bg, (u8)ov88_02259944[i], &ov88_022599C0[i], 0);
        BG_ClearCharDataRange((u8)ov88_02259944[i], 0x20, 0, heapID);
        BgClearTilemapBufferAndCommit(work->bg, (u8)ov88_02259944[i]);
    }
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, heapID);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0x140, heapID);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 1, work->bg, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapID);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 3, work->bg, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapID);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 4, work->bg, GF_BG_LYR_MAIN_2, 0, 0, FALSE, heapID);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapID);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 2, work->bg, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 6, work->bg, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
}

void ov88_02258C60(Ov88R3Work *work) {
    int i;

    for (i = 0; i < 5; i++) {
        FreeBgTilemapBuffer(work->bg, (u8)ov88_02259944[i]);
    }
    Heap_Free(work->bg);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
}

void ov88_02258C98(Ov88R3Work *work, enum HeapID heapID) {
    int i;
    u32 mode = 0x00200010;

    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x7E, 0, 0x1F, 0, 0x7E, 0, 0x1F, heapID);
    ObjCharTransfer_InitEx((ObjCharTransferTemplate *)&ov88_02259914, (GXOBJVRamModeChar)mode, (GXOBJVRamModeChar)(u8)mode);
    ObjPlttTransfer_Init(0x20, heapID);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    G2dRenderer_SetObjCharTransferReservedRegion((NNS_G2D_VRAM_TYPE)1, (GXOBJVRamModeChar)mode);
    G2dRenderer_SetPlttTransferReservedRegion((NNS_G2D_VRAM_TYPE)1);
    work->sprites = G2dRenderer_Init(0x20, &work->renderer, heapID);
    G2dRenderer_SetSubSurfaceCoords(&work->renderer, 0, 1 << 20);
    for (i = 0; i < 4; i++) {
        work->managers[i] = Create2DGfxResObjMan(0x20, (GfGfxResType)i, heapID);
    }
    sub_0203A880();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, TRUE);
}

void ov88_02258D38(Ov88R3Work *work) {
    int i;

    SpriteList_Delete(work->sprites);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(work->managers[i]);
    }
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    OamManager_Free();
}
