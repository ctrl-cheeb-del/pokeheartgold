#include "overlay_93_arm_opus_partial_internal.h"
#include <nitro/code32.h>

void ov93_0225EE98(void) {
    u8 buf[0x80];
    u8 *p = buf;
    u8 i;
    s32 n;

    for (i = 0; i < 0x7f; i++) {
        n = i * 2 + 1;
        p[i] = (u8)(((s64)n * n * n * n) >> 24);
    }
    p[0x7f] = 0xff;
    NNS_G3dGeBufferOP_N(0x34, (u32 *)buf, 0x20);
}

void ov93_0225EF0C(Ov93VtxSet *set) {
    s32 i;
    s32 y;

    for (i = 0, y = 0; i < 8; i++, y -= 0x10000) {
        set->lo[i].a = 0;
        set->lo[i].b = y;
        set->lo[i].c = 0;
        set->lo[i].d = y - 0x10000;
        set->lo[i].e = 0x80000;
        set->lo[i].f = y;
        set->lo[i].g = 0x80000;
        set->lo[i].h = y - 0x10000;
    }
}

void ov93_0225EF5C(Ov93VtxSet *set) {
    s32 i;
    s32 y;

    for (i = 0, y = 0; i < 8; i++, y += 0x10000) {
        set->hi[i].a = 0;
        set->hi[i].b = y;
        set->hi[i].c = 0;
        set->hi[i].d = y + 0x10000;
        set->hi[i].e = 0x80000;
        set->hi[i].f = y;
        set->hi[i].g = 0x80000;
        set->hi[i].h = y + 0x10000;
    }
}
