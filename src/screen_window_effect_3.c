#include "screen_window_effect_internal.h"

void sub_020131AC(void *work) {
    u32 *words = work;
    s16 *dst = sub_02010EE0(work, 0);
    s32 i;
    s32 first;
    s32 second;

    for (i = 0; i < 0xC0; i++) {
        sub_02013004(words[5], words[3], words[4], i, words[6], words[7], &first, &second);
        dst[0x180] = first;
        dst[0x240] = second;
        dst++;
    }
}

void sub_020131F4(u32 value, BOOL screen) {
    if (screen == 0) {
        volatile u32 *reg = (volatile u32 *)0x04000000;
        *reg = (*reg & 0xFFFF1FFF) | (value << 13);
    } else {
        volatile u32 *reg = (volatile u32 *)0x04001000;
        *reg = (*reg & 0xFFFF1FFF) | (value << 13);
    }
}

void sub_02013220(u32 value, BOOL enable, BOOL high, BOOL screen) {
    if (high == 0) {
        if (screen == 0) {
            u32 result = (*(volatile u16 *)0x04000048 & ~0x3F) | value;
            if (enable) {
                result |= 0x20;
            }
            *(volatile u16 *)0x04000048 = result;
        } else {
            u32 result = (*(volatile u16 *)0x04001048 & ~0x3F) | value;
            if (enable) {
                result |= 0x20;
            }
            *(volatile u16 *)0x04001048 = result;
        }
    } else {
        if (screen == 0) {
            u32 result = (*(volatile u16 *)0x04000048 & ~0x3F00) | (value << 8);
            if (enable) {
                result |= 0x2000;
            }
            *(volatile u16 *)0x04000048 = result;
        } else {
            u32 result = (*(volatile u16 *)0x04001048 & ~0x3F00) | (value << 8);
            if (enable) {
                result |= 0x2000;
            }
            *(volatile u16 *)0x04001048 = result;
        }
    }
}

void sub_020132A8(u32 value, BOOL enable, BOOL screen) {
    if (screen == 0) {
        u32 result = (*(volatile u16 *)0x0400004A & ~0x3F) | value;
        if (enable) {
            result |= 0x20;
        }
        *(volatile u16 *)0x0400004A = result;
    } else {
        u32 result = (*(volatile u16 *)0x0400104A & ~0x3F) | value;
        if (enable) {
            result |= 0x20;
        }
        *(volatile u16 *)0x0400104A = result;
    }
}

s8 sub_020132E8(BOOL high, BOOL screen) {
    volatile s8 result;
    if (high == 0) {
        if (screen == 0) {
            result = *(volatile u8 *)0x04000048;
        } else {
            result = *(volatile u8 *)0x04001048;
        }
    } else {
        if (screen == 0) {
            result = *(volatile u8 *)0x04000049;
        } else {
            result = *(volatile u8 *)0x04001049;
        }
    }
    return result;
}
