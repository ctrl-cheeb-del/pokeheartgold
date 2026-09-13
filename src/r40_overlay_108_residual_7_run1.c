#include "r40_overlay_108_residual_7_private.h"

void ov108_021E6C68(SafariAreaCustomizer *work) {
    GraphicsModes modes;
    Ov108BgTemplates templates;
    int i;
    int count;
    BgTemplate *template;

    ov108_021E6C48();
    *(vu16 *)0x04000304 &= 0xFFFF7FFF;
    work->bgConfig = BgConfig_Alloc(work->heapId);
    modes = ov108_021EA738;
    SetBothScreensModesAndDisable(&modes);
    templates = ov108_021EA898;
    i = 0;
    count = 0;
    template = templates.items;
    while (count < 8) {
        InitBgFromTemplate(work->bgConfig, (u8)i, template, 0);
        BgClearTilemapBufferAndCommit(work->bgConfig, (u8)i);
        BG_ClearCharDataRange((u8)i, 0x40, 0, work->heapId);
        count++;
        i++;
        template++;
    }
    G2x_SetBlendAlpha_(0x04000050, 2, 0x1C, 0x1C, 4);
    G2x_SetBlendAlpha_(0x04001050, 1, 0x1E, 0x1C, 4);
}

void ov108_021E6D24(SafariAreaCustomizer *work) {
    int i;

    G2x_SetBlendAlpha_(0x04000050, 0, 0, 0x1F, 0);
    G2x_SetBlendAlpha_(0x04001050, 0, 0, 0x1F, 0);
    for (i = 0; i < 8; i++) {
        FreeBgTilemapBuffer(work->bgConfig, (u8)i);
    }
    Heap_Free(work->bgConfig);
    *(vu16 *)0x04000304 |= 0x8000;
}

void ov108_021E6D80(SafariAreaCustomizer *work) {
    NARC *narc = NARC_New((NarcId)0xA6, work->heapId);

    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 6, (GFBgLayer)3, (BgGfxAssetType)0, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 6, (GFBgLayer)4, (BgGfxAssetType)0, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 1, (GFBgLayer)7, (BgGfxAssetType)0, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 5, (GFBgLayer)3, (BgGfxAssetType)2, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 0, (GFBgLayer)7, (BgGfxAssetType)2, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 10, (GFBgLayer)2, (BgGfxAssetType)1, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 7, (GFBgLayer)3, (BgGfxAssetType)1, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, 4, (GFBgLayer)6, (BgGfxAssetType)1, 0, 0);
    BgConfig_LoadAssetFromOpenNarc(work->bgConfig, work->heapId, narc, (NarcId)0xA6, (work->unk184E3 == 0) + 2, (GFBgLayer)7, (BgGfxAssetType)1, 0, 0);

    work->screenAllocation1 = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 8, FALSE, &work->screenData1, work->heapId);
    work->screenAllocation2 = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 9, FALSE, &work->screenData2, work->heapId);
    NARC_Delete(narc);
    ov108_021E7ADC(work);
    ov108_021E7BB4(work, 0xFF, 0);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 0);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 2);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 3);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 6);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 7);
}
