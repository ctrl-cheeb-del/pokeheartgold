#include "overlay40_pc_box_grid_private.h"

void ov40_02233C3C(void *p) {
    const s16 *tbl = _02245CC0;
    void *w = PTR(p, 0x860);
    s16 x;
    s16 y;
    int i;
    for (i = 0; i < 5; i++) {
        ManagedSprite_SetPositonFxXY(PTR(w, 0x68), tbl[0] << 12, tbl[1] << 12);
        ManagedSprite_GetPositionXY(PTR(w, 0x68), &x, &y);
        ManagedSprite_SetPositionXY(PTR(w, 0x40), x - 0x20, y - 2);
        ManagedSprite_SetPositionXY(PTR(w, 0x54), x + 0x10, y - 2);
        tbl += 2;
        w = (u8 *)w + 4;
    }
}
