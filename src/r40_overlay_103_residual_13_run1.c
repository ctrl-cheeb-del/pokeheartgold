#include "global.h"

#include "r40_overlay_103_residual_13_private.h"

u32 ov103_021EDA98(R40Ov103Work13 *work, u32 arg, u32 out) {
    u16 size0;
    u16 size1;
    s8 coords[2];
    R40Cfg13 *cfg;
    sub_02019B1C(*(void **)(work->ctx + 4), arg, &coords[1], &coords[0]);
    sub_02019B44(*(void **)(work->ctx + 4), arg, &size0, &size1);
    cfg = (R40Cfg13 *)(work->ctx + 0x2E4);
    cfg->bit0 = 1;
    cfg->bits1 = 2;
    cfg->lo = 2;
    cfg->hi = 1;
    cfg->zero2 = 0;
    cfg->zero3 = 0;
    cfg->y = coords[1];
    cfg->x = coords[0];
    cfg->h = (u8)size0;
    cfg->w = (u8)size1;
    work->out28 = out;
    return 5;
}
