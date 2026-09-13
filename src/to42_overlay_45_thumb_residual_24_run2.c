#include "to42_overlay_45_thumb_residual_24_private.h"

void ov45_0222C480(Ov45Grid *p, u32 value) {
    int i = ov45_0222C5B4(p, value);
    if (i != -1) {
        u32 q = (u32)i / 3, r = (u32)i % 3;
        ((Ov45Triple *)((u8 *)p + 0x50))[q].x[r] = (u32)-1;
    }
}

int ov45_0222C4B4(Ov45Grid *p, u32 i) {
    u32 q, r;
    u8 *slot;
    if (i >= 27) {
        GF_AssertFail();
    }
    q = i / 3;
    r = i % 3;
    slot = (u8 *)&((Ov45Triple *)((u8 *)p + 0x50))[q].x[r];
    return *(u32 *)slot;
}

int ov45_0222C4E4(Ov45Grid *p, u32 i) {
    if (i >= 9) {
        GF_AssertFail();
    }
    return p->pad2C[i];
}

int ov45_0222C4FC(Ov45Grid *p, u32 i) {
    if (i >= 9) {
        GF_AssertFail();
    }
    return p->counters[i];
}
