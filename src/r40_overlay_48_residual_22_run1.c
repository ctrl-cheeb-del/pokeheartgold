#include "global.h"

#include "bg_window.h"

typedef struct Ov48TileSourceR22 {
    u16 width;
    u16 height;
    u8 filler04[8];
    u8 pixels[1];
} Ov48TileSourceR22;

typedef struct Ov48WorkR22 {
    u8 filler00[0x98];
    Ov48TileSourceR22 *tileSource;
} Ov48WorkR22;

void ov48_0225A57C(Ov48WorkR22 *, int, BgConfig **);

void ov48_0225A57C(Ov48WorkR22 *work, int row, BgConfig **bg) {
    Ov48TileSourceR22 *source = work->tileSource;

    CopyToBgTilemapRect(*bg, (GFBgLayer)6, 0, (u8)row, 0x20, 1, source->pixels, 0, (u8)row, (u8)(source->width >> 3), (u8)(source->height >> 3));
    ScheduleBgTilemapBufferTransfer(*bg, (GFBgLayer)6);
}
