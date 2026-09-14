#include "sol_r14_ov48_ad_controls_private.h"

void ov48_0225AD54(void *p, void *arg) {
    if (S16AT(p, 0x32) > 0) {
        S16AT(p, 0x32)
        --;
        if (S16AT(p, 0x32) == 0) {
            if (ov48_0225ADBC(p, S16AT(p, 0x30), arg) == 1) {
                PlaySE(0x5d8);
            }
        }
    } else if (ov48_0225ADF8(p, S16AT(p, 0x30), arg) == 1) {
        s32 value = S16AT(p, 0x30) - 1;
        if (value >= 0) {
            S16AT(p, 0x30) = value;
            ov48_0225ADBC(p, S16AT(p, 0x30), arg);
        } else {
            StopSE(0x5d8, 0);
            S16AT(p, 0x30) = 2;
            S16AT(p, 0x32) = 0x80;
        }
    }
}

u32 ov48_0225ADBC(void *p, u32 index, void *arg) {
    u32 spriteIndex;
    if (U8AT(p, 0x34 + index) == 0) {
        return 0;
    }
    ov48_0225AEA8(ADD(p, index * 0x10), arg);
    spriteIndex = U8AT(p, 0x38 + index);
    Sprite_SetDrawFlag(PTRAT(p, 0x3c + spriteIndex * 4), TRUE);
    ov48_0225B010(p, index);
    return 1;
}

u32 ov48_0225ADF8(void *p, u32 index, void *arg) {
    u32 result;
    u32 spriteIndex;
    if (U8AT(p, 0x34 + index) == 0) {
        return 1;
    }
    result = ov48_0225AE60(ADD(p, index * 0x10), arg);
    ov48_0225B010(p, index);
    if (result == 1) {
        spriteIndex = U8AT(p, 0x38 + index);
        Sprite_SetDrawFlag(PTRAT(p, 0x3c + spriteIndex * 4), FALSE);
    }
    return result;
}
