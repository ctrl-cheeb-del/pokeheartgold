#include "to45_overlay96_r102_gap2_private.h"

BOOL ov96_0220FCB0(const s16 *point, int value) {
    BOOL result = TRUE;
    BOOL proceed = TRUE;
    BOOL first = FALSE;
    s16 y = point[1];

    if (y == value - 1) {
        BOOL outside = TRUE;
        if (point[0] >= 8 && point[0] <= 23) {
            outside = FALSE;
        }
        if (outside) {
            first = TRUE;
        }
    }
    if (!first) {
        BOOL second = FALSE;
        if (y == value - 2) {
            BOOL outside = TRUE;
            if (point[0] >= 5 && point[0] <= 26) {
                outside = FALSE;
            }
            if (outside) {
                second = TRUE;
            }
        }
        if (!second) {
            proceed = FALSE;
        }
    }
    if (!proceed) {
        BOOL third = FALSE;
        if (y == value - 3) {
            BOOL outside = TRUE;
            if (point[0] >= 2 && point[0] <= 29) {
                outside = FALSE;
            }
            if (outside) {
                third = TRUE;
            }
        }
        if (!third) {
            result = FALSE;
        }
    }
    return result;
}

void ov96_0220FD28(void *object, void *groups, const u8 *input) {
    s16 point[2];
    Ov96Gap2Group *group;
    int value;
    int type;
    void *sprite;

    point[0] = *(const s16 *)(input + 0) / 8;
    point[1] = *(const s16 *)(input + 2) / 8;
    if (point[1] < 9) {
        *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0xC;
        if (ov96_0220FCB0(point, 9)) {
            *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0x10;
        }
    } else if (point[1] < 15) {
        *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0x10;
        if (ov96_0220FCB0(point, 15)) {
            *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0x14;
        }
    } else if (point[1] < 20) {
        *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0x14;
        if (ov96_0220FCB0(point, 20)) {
            *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0x18;
        }
    } else {
        *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~0x1C) | 0x18;
    }

    group = (Ov96Gap2Group *)groups + input[4];
    sprite = group->sprite;
    type = ov96_0220F3BC(object);
    value = group->score;
    value += type;
    if (value > 200) {
        value = 200;
    }
    group->score = value;
    *(u32 *)((u8 *)object + 4) = (*(u32 *)((u8 *)object + 4) & ~3) | (input[4] & 3);
    ov96_021E8228(sprite, input[4], input[5], 3, 1);
}
