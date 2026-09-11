#include "ov57_wave42_private.h"

void ov57_02238134(Ov57Work *work) {
    s32 priority[8];
    s32 order[8];
    Ov57Coordinates coords;
    Ov57Coordinates copy;
    s32 i;
    s32 j;
    if (work->needsPrioritySort == 0) {
        return;
    }
    work->needsPrioritySort = 0;
    for (i = 0; i < 8; i++) {
        priority[i] = 0xFF;
        order[i] = 0xFF;
        if (work->slots[i].sprite != NULL) {
            priority[i] = ManagedSprite_GetDrawPriority(work->slots[i].sprite);
            order[i] = i;
        }
    }
    for (i = 0; i < 7; i++) {
        for (j = 7; j > i; j--) {
            if (priority[j - 1] >= priority[j]) {
                s32 value = priority[j];
                s32 index = order[j];
                priority[j] = priority[j - 1];
                order[j] = order[j - 1];
                priority[j - 1] = value;
                order[j - 1] = index;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        coords.values[i * 3] = work->slots[i].x;
        coords.values[i * 3 + 1] = work->slots[i].y;
        coords.values[i * 3 + 2] = work->slots[i].z;
    }
    copy = coords;
    {
        s32 *sorted;
        u8 *dst = (u8 *)work;
        s32 n = 0;
        sorted = order;
        u8 *sourceCoords = copy.values;
        for (; n < 8; n++, sorted++, dst += 0x10) {
            if (*sorted == 0xFF) {
                dst[0x350] = 0;
                dst[0x351] = 0;
                dst[0x352] = 0;
            } else {
                dst[0x350] = sourceCoords[*sorted * 3];
                dst[0x351] = sourceCoords[*sorted * 3 + 1];
                dst[0x352] = sourceCoords[*sorted * 3 + 2];
                if (work->slots[*sorted].sprite != NULL) {
                    ManagedSprite_SetDrawPriority(work->slots[*sorted].sprite, n);
                }
            }
        }
    }
}
