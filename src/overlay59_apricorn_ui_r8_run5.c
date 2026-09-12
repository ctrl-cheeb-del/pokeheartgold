#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

int ov59_0223A564(int value, int max, int delta) {
    if (delta > 0) {
        if (value == max) {
            return 1;
        }
        value += delta;
        if (value > max) {
            return max;
        }
    } else {
        if (value == 1) {
            return max;
        }
        value += delta;
        if (value <= 0) {
            return 1;
        }
    }
    return value;
}

int ov59_0223A58C(Ov59R8Work *work) {
    u32 keys = gSystem.newKeys;
    int unused;
    if (keys & 0xCF3) {
        U32(work, 0x40) = 0;
    }
    keys = gSystem.newKeys;
    if (keys & 2) {
        return ov59_0223A48C(work, 1);
    }
    if (keys & 1) {
        return ov59_0223A48C(work, 0);
    }
    if (keys & 0x40) {
        return ov59_0223A48C(work, 2);
    }
    unused = keys & 0x80;
    if (unused) {
        return ov59_0223A48C(work, 3);
    }
    if (keys & 0x10) {
        return ov59_0223A48C(work, 4);
    }
    if (keys & 0x20) {
        return ov59_0223A48C(work, 5);
    }
    if (unused != 0) {
        PlaySE(0x5DC);
        return 6;
    }
    return 6;
}
