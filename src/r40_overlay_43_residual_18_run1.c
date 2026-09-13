#include "global.h"

extern void PlaySE(int);
extern void Sprite_SetDrawFlag(void *, int);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void Sprite_SetAnimActiveFlag(void *, int);
extern void Sprite_SetMatrix(void *, VecFx32 *);
extern void ov43_0222AD74(void *, int, int);
extern s16 ov43_0222EFA0[];
extern s16 ov43_0222EFA2[];

int ov43_0222C620(s16 *p);
void ov43_0222C630(void *, void *, void *, int);
void ov43_0222C65C(u8 *, u8 *);

int ov43_0222C620(s16 *p) {
    int x = p[0] << 3;
    return x + p[2];
}

void ov43_0222C630(void *a0, void *a1, void *a2, int state) {
    if (state == 1) {
        PlaySE(0x5DC);
        return;
    }
    if (state == 2) {
        PlaySE(0x5DC);
        return;
    }
    if (state == 3) {
        PlaySE(0x5DC);
    }
}

void ov43_0222C65C(u8 *p, u8 *other) {
    VecFx32 v;
    int offset;
    u32 reg;
    Sprite_SetDrawFlag(*(void **)(p + 0xF8), 1);
    ov43_0222AD74(other, 0, 0xFF);
    Sprite_SetAnimCtrlSeq(*(void **)(p + 0xF8), 4);
    *(u32 *)(p + 0xFC) = 0;
    Sprite_SetAnimActiveFlag(*(void **)(p + 0xF8), 1);
    offset = *(s16 *)(p + 4) * 10;
    v.x = *(s16 *)((u8 *)ov43_0222EFA0 + offset) * 8;
    v.y = *(s16 *)((u8 *)ov43_0222EFA2 + offset) * 8 + 0xFC;
    v.x <<= 12;
    v.y <<= 12;
    Sprite_SetMatrix(*(void **)(p + 0xF8), &v);
    reg = *(vu16 *)0x0400004A;
    reg = (reg & 0xFFFFC0FF) | 0x700;
    *(vu16 *)0x0400004A = reg;
    reg = *(vu16 *)0x0400004A;
    reg = (reg & ~0x3F) | 0x1F;
    reg |= 0x20;
    *(vu16 *)0x0400004A = reg;
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    PlaySE(0x628);
}
