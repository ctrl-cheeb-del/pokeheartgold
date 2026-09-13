#include "r40_overlay_68_residual_9_private.h"

void ov68_021E66A0(MoveRelearner *d, u32 x, u32 y, u32 width, u8 height, u8 srcX, u8 srcY) {
    Ov68TileSourceR9 *src = *(Ov68TileSourceR9 **)((u8 *)d + 0x1c4);

    CopyToBgTilemapRect(d->bgConfig, 7, x, y, width, height, src->data, srcX, srcY, (u8)(src->width / 8), (u8)(src->height / 8));
    ScheduleBgTilemapBufferTransfer(d->bgConfig, 7);
}
