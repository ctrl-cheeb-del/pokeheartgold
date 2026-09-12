#include "overlay14_box_tilemap_loader_r7_private.h"

void ov14_021E76D0(void *work, s32 member, u32 unused, u32 offset) {
    GfxCharData *data;
    void *allocation = GfGfxLoader_GetCharData(0x13, member + 0x10, 1, &data, 0xa);

    BG_LoadCharTilesData(PTR_AT(PTR_AT(work, 0x34), 0x14), 3, data->raw, data->size, offset);
    ov14_021F5718(work, (u8 *)data->raw + 0x2a0, offset + 0x15, 0x15, 3);
    Heap_Free(allocation);
}

void ov14_021E7720(void *unused, s32 member, u32 palette) {
    GfGfxLoader_GXLoadPal(0x13, member + 0x28, 0, palette << 5, 0x20, 0xa);
}

void ov14_021E7740(void *work, s32 unused, u32 tile, u32 addend, u32 palette) {
    GfxScreenData *screen;
    void *allocation;
    u16 *raw;
    u32 y;
    u8 row;
    u32 x;
    u8 column;
    u16 *src;
    u16 value;

    allocation = GfGfxLoader_GetScrnData(0x13, 0xf, 1, &screen, 0xa);
    raw = screen->raw;
    for (row = 0; row < 0x14; row++) {
        src = raw + row * 0x15;
        x = tile;
        y = (row + 1) << 24;
        column = 0;
        y >>= 24;
        do {
            value = (src[column] & 0xfff) + (palette << 12) + addend;
            LoadRectToBgTilemapRect(PTR_AT(PTR_AT(work, 0x34), 0x14), 3, &value, (u8)x, y, 1, 1);
            x++;
            if (x >= 0x40) {
                x = 0;
            }
            column++;
        } while (column < 0x15);
    }
    Heap_Free(allocation);
    FillBgTilemapRect(PTR_AT(PTR_AT(work, 0x34), 0x14), 3, 0x1001, (u8)x, 0, 2, 0x14, 0x11);
}

void ov14_021E7808(void *work, s32 member, u32 a2, u32 a3, u32 a4) {
    ov14_021E76D0(work, member, a2, a3);
    ov14_021E7720(work, member, a4);
    ov14_021E7740(work, member, a2, a3, a4);
    ScheduleBgTilemapBufferTransfer(PTR_AT(PTR_AT(work, 0x34), 0x14), 3);
}

void ov14_021E783C(void *work, s32 member, u32 direction) {
    u32 x;
    u32 tile;

    if (direction == 0) {
        S8_AT(PTR_AT(work, 0x34), 0x448) -= 0x17;
        if (S8_AT(PTR_AT(work, 0x34), 0x448) < 0) {
            S8_AT(PTR_AT(work, 0x34), 0x448) += 0x40;
        }
    } else if (direction == 1) {
        S8_AT(PTR_AT(work, 0x34), 0x448) += 0x17;
        if (S8_AT(PTR_AT(work, 0x34), 0x448) >= 0x40) {
            S8_AT(PTR_AT(work, 0x34), 0x448) -= 0x40;
        }
    }
    if (U8_AT(PTR_AT(work, 0x34), 0x449) == 0) {
        x = 0x25c;
        tile = 0xe;
    } else {
        x = 0xb8;
        tile = 0xf;
    }
    U8_AT(PTR_AT(work, 0x34), 0x449) ^= 1;
    ov14_021E7808(work, member, S8_AT(PTR_AT(work, 0x34), 0x448), x, tile);
}

void ov14_021E78AC(void *work, s32 member) {
    u32 x;
    u32 tile;

    if (U8_AT(PTR_AT(work, 0x34), 0x449) == 0) {
        x = 0x25c;
        tile = 0xe;
    } else {
        x = 0xb8;
        tile = 0xf;
    }
    U8_AT(PTR_AT(work, 0x34), 0x449) ^= 1;
    ov14_021E76D0(work, member, S8_AT(PTR_AT(work, 0x34), 0x448), x);
    PaletteData_LoadNarc(PTR_AT(PTR_AT(work, 0x34), 0x18), 0x13, member + 0x28, 0xa, 0, 0x20, (tile << 20) >> 16);
    ov14_021E7740(work, member, S8_AT(PTR_AT(work, 0x34), 0x448), x, tile);
    ScheduleBgTilemapBufferTransfer(PTR_AT(PTR_AT(work, 0x34), 0x14), 3);
}
