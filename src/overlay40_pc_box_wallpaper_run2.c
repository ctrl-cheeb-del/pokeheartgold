#include "overlay40_pc_box_wallpaper_private.h"

void ov40_02243E80(u8 *w, int idx, int on) {
    if (on == 1) {
        ManagedSprite_SetDrawFlag(PTR(w + idx * 0x1C, 0x194), TRUE);
    } else {
        ManagedSprite_SetDrawFlag(PTR(w + idx * 0x1C, 0x194), FALSE);
    }
}

void ov40_02243EB0(u8 *w, int idx) {
    s16 x;
    s16 y;
    void *sprite = PTR(w + idx * 0x1C, 0xC);
    WORD(w, 0x188) = idx;
    ManagedSprite_GetPositionXY(sprite, &x, &y);
    ManagedSprite_SetPositionXY(PTR(w, 0x194), x, y + 0x10);
}
