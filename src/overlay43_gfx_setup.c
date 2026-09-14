#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
#include "gf_gfx_loader.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "sprite_transfer.h"
#include "unk_02009D48.h"
#include "unk_0200B150.h"
#include "vram_transfer_manager.h"

typedef struct Ov43Work {
    BgConfig *bgConfig;
    SpriteList *spriteList;
    u8 renderSurface[0x50];
    NARC *narc;
    u8 padding_5C[0x2C];
    SpriteResourcesHeader resourceHeader;
    SpriteResource *resourceObjects[4];
    G2dRenderer renderer;
    GF_2DGfxResMan *resourceManagers[4];
} Ov43Work;

extern const GraphicsBanks ov43_0222EE5C;
extern const GraphicsModes ov43_0222EDC8;
extern const BgTemplate ov43_0222EFFC[7];
extern const ObjCharTransferTemplate ov43_0222EDD8;
extern NNSG2dViewRect ov43_0222F0FC;

extern void Heap_Free(void *);
extern void SpriteList_Delete(void *);

void ov43_0222A550(void);
void ov43_0222A570(Ov43Work *, enum HeapID);
void ov43_0222A66C(Ov43Work *);
void ov43_0222A690(Ov43Work *, enum HeapID);
void ov43_0222A81C(Ov43Work *);

void ov43_0222A550(void) {
    GraphicsBanks banks = ov43_0222EE5C;
    GfGfx_SetBanks(&banks);
}

void ov43_0222A570(Ov43Work *work, enum HeapID heapId) {
    GraphicsModes modes;
    int i;

    work->bgConfig = BgConfig_Alloc(heapId);
    modes = ov43_0222EDC8;
    SetBothScreensModesAndDisable(&modes);
    for (i = 0; i < 7; i++) {
        InitBgFromTemplate(work->bgConfig, i, &ov43_0222EFFC[i], 0);
        BG_ClearCharDataRange(i, 0x20, 0, heapId);
        BgClearTilemapBufferAndCommit(work->bgConfig, i);
    }
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 5, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x160, heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 4, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0xA0, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 7, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 7, work->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 6, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 0xA, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 8, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, heapId);
}

void ov43_0222A66C(Ov43Work *work) {
    int i;

    for (i = 0; i < 7; i++) {
        FreeBgTilemapBuffer(work->bgConfig, i);
    }
    Heap_Free(work->bgConfig);
    work->bgConfig = NULL;
}

void ov43_0222A690(Ov43Work *work, enum HeapID heapId) {
    ObjCharTransferTemplate template;
    int i;

    NNS_G2dInitOamManagerModule();
    GF_CreateVramTransferManager(0x10, heapId);
    OamManager_Create(0, 0x7E, 0, 0x1E, 0, 0x7E, 0, 0x1E, heapId);
    template = ov43_0222EDD8;
    template.heapID = heapId;
    ObjCharTransfer_InitEx(&template, (GXOBJVRamModeChar)0x10, (GXOBJVRamModeChar)0x10);
    ObjPlttTransfer_Init(0x40, heapId);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    work->spriteList = G2dRenderer_Init(0x40, &work->renderer, heapId);
    sub_0200B27C((NNSG2dRenderSurface *)work->renderSurface, &ov43_0222F0FC, NNS_G2D_VRAM_TYPE_2DMAIN, &work->renderer.rendererInstance);
    for (i = 0; i < 4; i++) {
        work->resourceManagers[i] = Create2DGfxResObjMan(0x40, (GfGfxResType)i, heapId);
    }
    work->resourceObjects[0] = AddCharResObjFromOpenNarc(work->resourceManagers[0], work->narc, 1, TRUE, 0x64, NNS_G2D_VRAM_TYPE_2DMAIN, heapId);
    work->resourceObjects[1] = AddPlttResObjFromOpenNarc(work->resourceManagers[1], work->narc, 0, FALSE, 0x64, NNS_G2D_VRAM_TYPE_2DMAIN, 5, heapId);
    work->resourceObjects[2] = AddCellOrAnimResObjFromOpenNarc(work->resourceManagers[2], work->narc, 2, TRUE, 0x64, GF_GFX_RES_TYPE_CELL, heapId);
    work->resourceObjects[3] = AddCellOrAnimResObjFromOpenNarc(work->resourceManagers[3], work->narc, 3, TRUE, 0x64, GF_GFX_RES_TYPE_ANIM, heapId);
    GF_ASSERT(SpriteTransfer_CreateCharTransferTask_AllocAtEnd(work->resourceObjects[0]));
    GF_ASSERT(SpriteTransfer_CreatePlttTransferTask(work->resourceObjects[1]));
    sub_0200A740(work->resourceObjects[0]);
    sub_0200A740(work->resourceObjects[1]);
    CreateSpriteResourcesHeader(&work->resourceHeader, 0x64, 0x64, 0x64, 0x64, -1, -1, 0, 0, work->resourceManagers[0], work->resourceManagers[1], work->resourceManagers[2], work->resourceManagers[3], NULL, NULL);
}

void ov43_0222A81C(Ov43Work *work) {
    int i;

    SpriteTransfer_DeleteCharTransferTask(work->resourceObjects[0]);
    SpriteTransfer_DeletePlttTransferTask(work->resourceObjects[1]);
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(work->resourceManagers[i], work->resourceObjects[i]);
    }
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(work->resourceManagers[i]);
    }
    SpriteList_Delete(work->spriteList);
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    OamManager_Free();
    GF_DestroyVramTransferManager();
}
