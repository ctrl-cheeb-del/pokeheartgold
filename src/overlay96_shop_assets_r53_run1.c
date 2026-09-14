#include "overlay96_shop_assets_r53_tail_private.h"

void ov96_021F0D60(Ov96ShopWorkR53 *work) {
    void *allocation;
    NNSG2dScreenData *screen;

    GfGfxLoader_LoadCharData((NarcId)0xA7, 5, work->bgConfig, (GFBgLayer)0, 0, 0, FALSE, work->heapId);
    GfGfxLoader_LoadCharData((NarcId)0xA7, 9, work->bgConfig, (GFBgLayer)2, 0, 0, FALSE, work->heapId);
    GfGfxLoader_LoadCharData((NarcId)0xA7, 12, work->bgConfig, (GFBgLayer)5, 0, 0x1000, FALSE, work->heapId);
    GfGfxLoader_LoadCharData((NarcId)0xA7, 22, work->bgConfig, (GFBgLayer)7, 0, 0, FALSE, work->heapId);
    GfGfxLoader_LoadCharData((NarcId)0xA7, 15, work->bgConfig, (GFBgLayer)6, 0x80, 0, FALSE, work->heapId);
    GfGfxLoader_LoadScrnData((NarcId)0xA7, 6, work->bgConfig, (GFBgLayer)0, 0, 0, FALSE, work->heapId);
    allocation = GfGfxLoader_GetScrnData((NarcId)0xA7, 10, FALSE, &screen, work->heapId);
    BG_LoadScreenTilemapData(work->bgConfig, 2, (u8 *)screen + 0xC, screen->szByte);
    BgTilemapRectChangePalette(work->bgConfig, 2, 0, 0, 0x20, 0x18, 1);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 2);
    Heap_Free(allocation);
    work->screenAlloc = GfGfxLoader_GetScrnData((NarcId)0xA7, 7, FALSE, &work->screenData, work->heapId);
    BG_LoadScreenTilemapData(work->bgConfig, 1, (u8 *)work->screenData + 0xC, work->screenData->szByte);
    BgCopyOrUncompressTilemapBufferRangeToVram(work->bgConfig, 1, (u8 *)work->screenData + 0xC, work->screenData->szByte, 0);
    ov96_021F3CBC(work->graphicsObject);
    GfGfxLoader_GXLoadPal((NarcId)0xA7, 4, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0x20, work->heapId);
    GfGfxLoader_GXLoadPal((NarcId)0xA7, 8, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0x20, 0x20, work->heapId);
    GfGfxLoader_GXLoadPal((NarcId)0xA7, 21, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x40, work->heapId);
    GfGfxLoader_GXLoadPal((NarcId)0xA7, 11, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0x40, 0x20, work->heapId);
    GfGfxLoader_GXLoadPal((NarcId)0xA7, 14, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0x60, 0x20, work->heapId);
    *(vu32 *)0x04000018 = 0x00800000;
}
