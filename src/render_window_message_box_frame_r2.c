#include "global.h"

void *sub_0200E63C(void *);
void *sub_0200E640(void *);
void GfGfxLoader_LoadCharData(u32, u32, void *, u32, u32, u32, u32, u32);
void GfGfxLoader_GXLoadPal(u32, u32, u32, u32, u32, u32);
void FillBgTilemapRect(void *, u8, u16, u8, u8, u8, u8, u8);
void LoadUserFrameGfx2(void *, u32, u32, u32, u8, u32);
void sub_0200E6B4(void *, u8, u8, u8, u8, u8, u8, u16);

void LoadUserFrameGfx2(void *bgConfig, u32 layer, u32 baseTile, u32 paletteNum, u8 frame, u32 heapID) {
    GfGfxLoader_LoadCharData(0x26, (u32)sub_0200E63C((void *)(u32)frame), bgConfig, layer, baseTile, 0, 0, heapID);
    if (layer < 4) {
        GfGfxLoader_GXLoadPal(0x26, (u32)sub_0200E640((void *)(u32)frame), 0, paletteNum * 0x20, 0x20, heapID);
    } else {
        GfGfxLoader_GXLoadPal(0x26, (u32)sub_0200E640((void *)(u32)frame), 4, paletteNum * 0x20, 0x20, heapID);
    }
}

void sub_0200E6B4(void *bgConfig, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 mode, u16 baseTile) {
    FillBgTilemapRect(bgConfig, bgId, baseTile, x - 2, y - 1, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 1, x - 1, y - 1, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 2, x, y - 1, width, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 3, x + width, y - 1, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 4, x + width + 1, y - 1, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 5, x + width + 2, y - 1, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 6, x - 2, y, 1, height, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 7, x - 1, y, 1, height, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 9, x + width, y, 1, height, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 10, x + width + 1, y, 1, height, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 11, x + width + 2, y, 1, height, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 12, x - 2, y + height, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 13, x - 1, y + height, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 14, x, y + height, width, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 15, x + width, y + height, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 16, x + width + 1, y + height, 1, 1, mode);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 17, x + width + 2, y + height, 1, 1, mode);
}
