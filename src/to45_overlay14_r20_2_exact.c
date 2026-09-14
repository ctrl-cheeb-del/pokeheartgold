#include "to45_overlay14_r20_2_private.h"
u32 ov14_021E9F20(void *p) {
    s16 pos[2];
    Ov14Motion *motion = PTR_AT(PTR_AT(p, 0x34), 0xc);

    sub_02019978(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 15);
    if (motion->frames == 0) {
        ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), motion->x, motion->y);
        if (U8_AT(PTR_AT(p, 0x34), 0x44b) == 1) {
            if (U32_AT(PTR_AT(p, 0), 8) == 3) {
                ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x328), motion->x, (s16)(motion->y + 8));
            } else {
                ManagedSprite_SetPositionXY(
                    PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc),
                    motion->x,
                    (s16)(motion->y + 4));
            }
        }
        return 0;
    }

    motion->frames--;
    ManagedSprite_GetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), (s32 *)&pos[1], (s32 *)&pos[0]);
    if (motion->xNegative == 0) {
        pos[1] += motion->dx;
    } else {
        pos[1] -= motion->dx;
    }
    if (motion->yNegative == 0) {
        pos[0] += motion->dy;
    } else {
        pos[0] -= motion->dy;
    }
    ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x320), pos[1], pos[0]);
    if (U8_AT(PTR_AT(p, 0x34), 0x44b) == 1) {
        if (U32_AT(PTR_AT(p, 0), 8) == 3) {
            ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(p, 0x34), 0x328), pos[1], (s16)(pos[0] + 8));
        } else {
            ManagedSprite_SetPositionXY(
                PTR_AT((u8 *)PTR_AT(p, 0x34) + U8_AT((u8 *)PTR_AT(p, 0x34) + U8_AT(p, 0x21), 0x4094) * 4, 0x2fc),
                pos[1],
                (s16)(pos[0] + 4));
        }
    }
    return 1;
}
