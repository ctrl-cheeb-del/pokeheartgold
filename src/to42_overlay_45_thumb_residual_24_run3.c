#include "to42_overlay_45_thumb_residual_24_private.h"

int ov45_0222C54C(Ov45Grid *p, u32 i) {
    u32 q, r;
    u8 *slot;
    if (i >= 27) {
        GF_AssertFail();
    }
    q = i / 3;
    r = i % 3;
    slot = (u8 *)&((Ov45Triple *)((u8 *)p + 0x128))[q].x[r];
    return *(u32 *)slot;
}

void ov45_0222C580(Ov45Grid *p, u32 i) {
    u32 q, r;
    u8 *slot;
    if (i >= 27) {
        GF_AssertFail();
    }
    q = i / 3;
    r = i % 3;
    slot = (u8 *)&((Ov45Triple *)((u8 *)p + 0x128))[q].x[r];
    *(u32 *)slot = 0;
}
