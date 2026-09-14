#include "overlay89_r2u1_private.h"

#define SLOT(w, off) (*(void **)((u8 *)(w) + (off)))

void ov89_02259264(Ov89WorkHead *work, NARC *narc) {
    void *tilemap;
    int frame;

    PaletteData_LoadNarc(work->palette, (NarcId)0xd2, 0x13, (enum HeapID)0x7d, (PaletteBufferId)0, 0x1c0, 0);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x12, work->bg, (GFBgLayer)2, 0, 0, FALSE, (enum HeapID)0x7d);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x11, work->bg, (GFBgLayer)2, 0, 0, FALSE, (enum HeapID)0x7d);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x14, work->bg, (GFBgLayer)3, 0, 0, FALSE, (enum HeapID)0x7d);
    PaletteData_LoadNarc(work->palette, (NarcId)0xd2, 0x17, (enum HeapID)0x7d, (PaletteBufferId)1, 0, 0);
    if (((u8 *)work->args)[4] == 0) {
        PaletteData_CopyPalette(work->palette, 1, 0x10, 1, 0, 0x20);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x16, work->bg, (GFBgLayer)6, 0, 0, FALSE, (enum HeapID)0x7d);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x15, work->bg, (GFBgLayer)6, 0, 0, FALSE, (enum HeapID)0x7d);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x18, work->bg, (GFBgLayer)7, 0, 0, FALSE, (enum HeapID)0x7d);
    tilemap = GetBgTilemapBuffer(work->bg, 6);
    MI_CpuCopy16(tilemap, (u8 *)work + 0x9c0, 0x800);
    MIi_CpuClear16(0, tilemap, 0x800);
    frame = Options_GetFrame(Save_PlayerData_GetOptionsAddr(work->save));
    PaletteData_LoadNarc(work->palette, (NarcId)0x26, sub_0200E640(frame), (enum HeapID)0x7d, (PaletteBufferId)0, 0x20, 0xe0);
    LoadUserFrameGfx2(work->bg, (GFBgLayer)1, 1, 0xe, frame, (enum HeapID)0x7d);
    PaletteData_LoadNarc(work->palette, (NarcId)0x10, 7, (enum HeapID)0x7d, (PaletteBufferId)0, 0x20, 0xd0);
    if (((u8 *)work->args)[4] == 0) {
        PaletteData_LoadNarc(work->palette, (NarcId)0x10, 7, (enum HeapID)0x7d, (PaletteBufferId)1, 0x20, 0xd0);
    } else {
        PaletteData_LoadNarc(work->palette, (NarcId)0xd2, 0x19, (enum HeapID)0x7d, (PaletteBufferId)1, 0x20, 0xd0);
    }
    ScheduleBgTilemapBufferTransfer(work->bg, 6);
}

void ov89_02259408(Ov89WorkHead *work, NARC *narc) {
    int i;
    int color;
    u8 palette;
    palette = SpriteSystem_LoadPaletteBufferFromOpenNarc(work->palette, (PaletteBufferId)2, work->spriteSystem, work->spriteManager, narc, 3, FALSE, 3, 1, 0x2711);
    SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 4, FALSE, 1, 0x2717);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 5, FALSE, 0x2712);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 6, FALSE, 0x2712);
    for (i = 0; i < 6; i++) {
        SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0x10, FALSE, 1, 0x2711 + i);
    }
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0xf, FALSE, 0x2711);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0xe, FALSE, 0x2711);
    palette = SpriteSystem_LoadPaletteBufferFromOpenNarc(work->palette, (PaletteBufferId)2, work->spriteSystem, work->spriteManager, narc, 3, FALSE, 1, 1, 0x2712);
    if (((u8 *)work->args)[4] == 0) {
        color = 0;
    } else {
        color = 0x7fff;
    }
    PaletteData_FillPaletteInBuffer(work->palette, (PaletteBufferId)2, (PaletteSelector)2, color, (u16)(palette << 4), (u16)((palette << 4) + 0x10));
    SpriteSystem_LoadCharResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 2, FALSE, 1, 0x2718);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 1, FALSE, 0x2713);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->spriteSystem, work->spriteManager, narc, 0, FALSE, 0x2713);
    ((u8 *)work)[0x921] = SpriteSystem_LoadPaletteBuffer(work->palette, (PaletteBufferId)2, work->spriteSystem, work->spriteManager, (NarcId)0xd2, 0x1a, FALSE, 1, 1, 0x2713);
}
