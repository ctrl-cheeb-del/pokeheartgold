#include "overlay90_motion_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov90_02259F44(void *p, u16 value) {
    ov90_02258CF0((u8 *)p + 0x1C, U32(p, 0x1C), 0xFFF01000, 0, 8);
    S16(p, 0x30) = 0;
    S16(p, 0x32) = value;
    U32(p, 0x34) = 0x57F;
    ov90_02259FC8(p, -(S32(p, 0x1C) >> 12));
}

int ov90_02259F7C(void *p) {
    int ret;
    if (S16(p, 0x32) <= 0) {
        if (S16(p, 0x30) == 0) {
            PlaySE((u16)U32(p, 0x34));
        }
        S16(p, 0x30)
        ++;
        ret = ov90_02258D4C((u8 *)p + 0x1C, S16(p, 0x30));
        ov90_02259FC8(p, -(S32(p, 0x1C) >> 12));
        return ret;
    } else {
        S16(p, 0x32)
        --;
        return 0;
    }
}
