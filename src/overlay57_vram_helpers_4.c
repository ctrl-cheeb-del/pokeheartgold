#include "overlay57_vram_helpers_private.h"

void ov57_02238F48(void *work) {
    s32 i;
    u8 *p;
    i = 0;
    if (*(s32 *)R20_PTR(work, 0) > 0) {
        p = work;
        do {
            ManagedSprite_SetDrawFlag(R20_PTR(p, 0x324), 0);
            i++;
            p += 4;
        } while (i < *(s32 *)R20_PTR(work, 0));
    }
    {
        u8 *q;
        s32 j;
        for (j = 0, q = work; j < 12; j++, q += 8) {
            u32 slot = R20_U32(q, 4);
            if (slot != 0xff) {
                s16 x, y;
                ov57_02238DAC(j, &x, &y);
                ManagedSprite_SetPositionXY(R20_PTR((u8 *)work + slot * 4, 0x324), x - 0x10, y + 0xc);
                ManagedSprite_SetDrawFlag(R20_PTR((u8 *)work + slot * 4, 0x324), 1);
            }
        }
    }
}

void ov57_02238FC4(void *work) {
    s32 i;
    u8 *p;
    i = 0;
    if (*(s32 *)R20_PTR(work, 0) > 0) {
        p = work;
        do {
            ManagedSprite_TickFrame(R20_PTR(p, 0x324));
            i++;
            p += 4;
        } while (i < *(s32 *)R20_PTR(work, 0));
    }
}

void ov57_02238FEC(void *work) {
    s32 i;
    u8 *p;
    i = 0;
    if (*(s32 *)R20_PTR(work, 0) > 0) {
        p = work;
        do {
            Sprite_DeleteAndFreeResources(R20_PTR(p, 0x324));
            i++;
            p += 4;
        } while (i < *(s32 *)R20_PTR(work, 0));
    }
}
