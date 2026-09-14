#include "global.h"

#define U8AT(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8AT(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define PAT(p, o)  (*(void **)((u8 *)(p) + (o)))

void sub_02013794(void *, s32 *, s32 *);
void sub_020136B4(void *, s32, s32);
u32 ov93_02262108(void *);
u32 ov93_02262130(void *);
void ov93_02261FC8(void *);
void ov93_02262034(void *, void *);
void ov93_02262098(void *, s32);
void ov93_022620D4(void *);

void ov93_02261FC8(void *work) {
    s32 x;
    s32 y;
    s32 i;
    s32 b;
    u8 *slot;
    s32 a;

    for (i = 0, slot = work; i < 6; i++, slot += 0x28) {
        s32 value = U8AT(work, 0x180 + i);

        if (value < 0x40) {
            a = 0x40 - value;
            b = a - 0x50;
        } else if (value < 0x80) {
            b = 0xA0 - value;
            b -= 0x10;
            a = b - 0x50;
        } else {
            value -= 0xA0;
            a = 0x40 - value;
            b = a - 0x50;
        }
        sub_02013794(PAT(slot, 4), &x, &y);
        sub_020136B4(PAT(slot, 4), x, 0xA8 - a);
        sub_020136B4(PAT(slot, 0x18), x, 0xA8 - b);
    }
}

void ov93_02262034(void *unused, void *work) {
    u32 done;

    if (S8AT(work, 0x19E) > 0) {
        S8AT(work, 0x19E)
        --;
        return;
    }
    switch (U8AT(work, 0x1A0)) {
    case 0:
        if (ov93_02262108(work) == 1) {
            ov93_022620D4(work);
            return;
        }
        U8AT(work, 0x1A0)
        ++;
    case 1:
        done = ov93_02262130(work);
        ov93_02261FC8(work);
        if (done == 1) {
            S8AT(work, 0x19E) = 15;
            U8AT(work, 0x1A0)
            --;
        }
        break;
    }
}

void ov93_02262098(void *out_, s32 value) {
    u8 *out = out_;
    s32 i;
    s32 divisor = 100000;

    for (i = 0; i < 6; i++) {
        s32 digit = value / divisor;
        out[0x18C + i] = digit << 4;
        value -= digit * divisor;
        divisor /= 10;
    }
}

void ov93_022620D4(void *work) {
    s32 i;

    for (i = 0; i < 6; i++) {
        U8AT(work, 0x186 + i) = U8AT(work, 0x18C + i);
        U8AT(work, 0x198 + i) = (5 - i) * 2;
        U8AT(work, 0x192 + i) = 0;
    }
    U8AT(work, 0x19F) = 0;
}
