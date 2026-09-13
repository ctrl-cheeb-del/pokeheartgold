#include "to42_overlay_45_thumb_residual_24_private.h"

void ov45_0222C5E8(Ov45Grid *p, u32 i, u32 n) {
    u32 q, r;
    u8 *slot;
    if (i >= 27) {
        GF_AssertFail();
    }
    q = i / 3;
    r = i % 3;
    slot = (u8 *)&((Ov45Triple *)((u8 *)p + 0xBC))[q].x[r];
    *(u32 *)slot = n + 1;
}

BOOL ov45_0222C61C(Ov45Grid *p, u32 i, u32 n) {
    u32 q, r;
    u8 *slot;
    if (i >= 27) {
        GF_AssertFail();
    }
    q = i / 3;
    r = i % 3;
    slot = (u8 *)&((Ov45Triple *)((u8 *)p + 0xBC))[q].x[r];
    if (*(u32 *)slot <= n) {
        return FALSE;
    }
    return TRUE;
}

u32 ov45_0222C658(Ov45Grid *p, u32 i) {
    u32 q, r;
    u8 *slot;
    if (i >= 27) {
        GF_AssertFail();
    }
    q = i / 3;
    r = i % 3;
    slot = (u8 *)&((Ov45Triple *)((u8 *)p + 0xBC))[q].x[r];
    return *(u32 *)slot;
}
