#include "r40_unk_0202B614_private.h"

void sub_0202BCAC(Unk0202BCACRoot *root, const Unk0202BCACDesc *desc, int index) {
    volatile Unk0202BCACCoords coords;
    u32 packed;
    int value;
    int y;
    u32 mask;

    packed = sub_02015FCC(desc->object);
    coords.a = packed;
    coords.b = packed >> 16;
    coords.c = coords.a;
    coords.d = coords.b;
    value = sub_02015FF8(desc->object);
    if (index >= 10) {
        GF_AssertFail();
    }
    if ((s16)coords.c >= 256) {
        GF_AssertFail();
    }
    y = (s16)coords.d;
    if (((volatile int *)&coords)[-1] >= 256) {
        GF_AssertFail();
    }
    if (value <= -128) {
        GF_AssertFail();
    }
    mask = 1 << index;
    if (root->flags & mask) {
        GF_AssertFail();
    }
    if (!sub_0202B614(root->owner)) {
        GF_AssertFail();
    }
    sub_0202B770(&root->entries[index], (u8)desc->id, (u8)(s16)coords.c, (u8)y, (u8)value);
    root->flags |= mask;
}
