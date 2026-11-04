#include "global.h"

#include "gf_gfx_loader.h"
#include "render_text.h"
#include "render_window_internal.h"

// Window frames: NARC a/0/3/8 holds the frame-1 tiles (members 0-1) and palettes (0x19, 0x2E) and, for message box
// frame N, tiles N+2 and palette N+0x1A.

void LoadUserFrameGfx1Tiles(BgConfig *bgConfig, u32 layer, u32 baseTile, BOOL frame, enum HeapID heapId) {
    if (frame == 0) {
        GfGfxLoader_LoadCharData(NARC_a_0_3_8, 0, bgConfig, (GFBgLayer)layer, baseTile, 0, FALSE, heapId);
    } else {
        GfGfxLoader_LoadCharData(NARC_a_0_3_8, 1, bgConfig, (GFBgLayer)layer, baseTile, 0, FALSE, heapId);
    }
}

u32 GetUserFrameGfx1PaletteMember(void) {
    return 0x19;
}

void LoadUserFrameGfx1(BgConfig *bgConfig, enum GFBgLayer layer, u16 baseTile, u8 paletteNum, u8 frame, enum HeapID heapId) {
    int member;
    if (frame != 0) {
        member = 1;
    } else {
        member = 0;
    }
    GfGfxLoader_LoadCharData(NARC_a_0_3_8, member, bgConfig, layer, baseTile, 0, FALSE, heapId);
    if (frame == 2) {
        member = 0x2E;
    } else {
        member = 0x19;
    }
    if ((u32)layer < GF_BG_LYR_SUB_FIRST) {
        GfGfxLoader_GXLoadPal(NARC_a_0_3_8, member, GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)(paletteNum << 5), 32, heapId);
        return;
    }
    GfGfxLoader_GXLoadPal(NARC_a_0_3_8, member, GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)(paletteNum << 5), 32, heapId);
}

void DrawFrame1Tilemap(BgConfig *bgConfig, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteNum, u16 baseTile) {
    FillBgTilemapRect(bgConfig, bgId, baseTile, x - 1, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 1, x, y - 1, width, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 2, x + width, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 3, x - 1, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 5, x + width, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 6, x - 1, y + height, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 7, x, y + height, width, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 8, x + width, y + height, 1, 1, paletteNum);
}

void DrawFrameAndWindow1(Window *window, BOOL dontCopyToVram, u16 baseTile, u8 paletteNum) {
    DrawFrame1Tilemap(window->bgConfig, GetWindowBgId(window), GetWindowX(window), GetWindowY(window), GetWindowWidth(window), GetWindowHeight(window), paletteNum, baseTile);
    if (!dontCopyToVram) {
        CopyWindowToVram(window);
    }
}

void EraseFrameAndWindow1(Window *window, BOOL dontCopyToVram) {
    u8 bgId = GetWindowBgId(window);
    u8 x = GetWindowX(window);
    u8 y = GetWindowY(window);
    u8 width = GetWindowWidth(window);
    u8 height = GetWindowHeight(window);

    FillBgTilemapRect(window->bgConfig, bgId, 0, x - 1, y - 1, width + 2, height + 2, 0);
    if (!dontCopyToVram) {
        ClearWindowTilemapAndCopyToVram(window);
    }
}

u32 GetUserFrameGfx2TilesMember(u32 frame) {
    return frame + 2;
}

u32 GetUserFrameGfx2PaletteMember(u32 frame) {
    return frame + 0x1A;
}

void LoadUserFrameGfx2(BgConfig *bgConfig, u32 layer, u16 baseTile, u8 paletteNum, u8 frame, enum HeapID heapId) {
    GfGfxLoader_LoadCharData(NARC_a_0_3_8, GetUserFrameGfx2TilesMember(frame), bgConfig, (GFBgLayer)layer, baseTile, 0, FALSE, heapId);
    if (layer < GF_BG_LYR_SUB_FIRST) {
        GfGfxLoader_GXLoadPal(NARC_a_0_3_8, GetUserFrameGfx2PaletteMember(frame), GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)(paletteNum * 0x20), 0x20, heapId);
    } else {
        GfGfxLoader_GXLoadPal(NARC_a_0_3_8, GetUserFrameGfx2PaletteMember(frame), GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)(paletteNum * 0x20), 0x20, heapId);
    }
}

void DrawFrame2Tilemap(BgConfig *bgConfig, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteNum, u16 baseTile) {
    FillBgTilemapRect(bgConfig, bgId, baseTile, x - 2, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 1, x - 1, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 2, x, y - 1, width, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 3, x + width, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 4, x + width + 1, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 5, x + width + 2, y - 1, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 6, x - 2, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 7, x - 1, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 9, x + width, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 10, x + width + 1, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 11, x + width + 2, y, 1, height, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 12, x - 2, y + height, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 13, x - 1, y + height, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 14, x, y + height, width, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 15, x + width, y + height, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 16, x + width + 1, y + height, 1, 1, paletteNum);
    FillBgTilemapRect(bgConfig, bgId, baseTile + 17, x + width + 2, y + height, 1, 1, paletteNum);
}

void DrawFrame2AroundWindow(Window *window, u32 baseTile, u32 paletteNum) {
    u8 bgId = GetWindowBgId(window);
    u8 x = GetWindowX(window);
    u8 y = GetWindowY(window);
    u8 width = GetWindowWidth(window);
    u8 height = GetWindowHeight(window);

    DrawFrame2Tilemap(window->bgConfig, bgId, x, y, width, height, paletteNum, baseTile);
}

void DrawFrameAndWindow2(Window *window, BOOL dontCopyToVram, u32 baseTile, u32 paletteNum) {
    DrawFrame2AroundWindow(window, baseTile, paletteNum);
    if (!dontCopyToVram) {
        CopyWindowToVram(window);
    }
    TextPrinter_SetDownArrowBaseTile(baseTile);
}

void ClearFrameAndWindow2(Window *window, BOOL dontCopyToVram) {
    u8 bgId = GetWindowBgId(window);
    u8 x = GetWindowX(window);
    u8 y = GetWindowY(window);
    u8 width = GetWindowWidth(window);
    u8 height = GetWindowHeight(window);

    FillBgTilemapRect(window->bgConfig, bgId, 0, x - 2, y - 1, width + 5, height + 2, 0);
    if (!dontCopyToVram) {
        ClearWindowTilemapAndCopyToVram(window);
    }
}

void BlitPixelRect4Bit(void *src, u16 srcX, u16 srcY, u16 srcWidth, u16 srcHeight, void *dest, u16 destWidth, u16 destHeight, u16 destX, u16 destY, u16 width, u16 height) {
    Bitmap srcBitmap;
    Bitmap destBitmap;

    srcBitmap.pixels = src;
    srcBitmap.width = srcWidth;
    srcBitmap.height = srcHeight;
    destBitmap.pixels = dest;
    destBitmap.width = destWidth;
    destBitmap.height = destHeight;
    BlitBitmapRect4Bit(&srcBitmap, &destBitmap, srcX, srcY, destX, destY, width, height, 0);
}
