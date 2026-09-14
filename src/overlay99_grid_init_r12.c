#include "overlay99_residual_12_private.h"

void ov99_021E9038(Ov99GridR12 *work) {
    u32 outer = 0;
    u32 inner;
    u32 base = 0;
    s32 y = 6;

    do {
        s32 anim = 1;
        s32 ySigned;
        inner = 0;
        ySigned = (s16)(u16)y;
        do {
            u8 index = inner + base;
            s32 draw;
            s32 spriteIndex;
            if (work->override != 0) {
                draw = 1;
            } else if (work->entries[index] == NULL) {
                draw = 1;
            } else {
                draw = 0;
            }
            spriteIndex = index + 12;
            ManagedSprite_SetDrawFlag(*(void **)((u8 *)work + 0x18 + spriteIndex * 4),
                work->override != 0 ? 0 : draw);
            ManagedSprite_SetDrawFlag(*(void **)((u8 *)work + 0x20 + index * 4),
                ov99_021E8518((u8 *)work, (s8)index, (void *)1));
            ov99_021E86D4(work, index, (s16)(u16)anim, ySigned, draw, 0);
            anim += 6;
            inner++;
        } while (inner < 5);
        base += 5;
        y += 8;
        outer++;
    } while (outer < 2);
}
