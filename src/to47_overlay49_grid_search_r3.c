#include "to47_overlay49_grid_search_r3_private.h"

BOOL ov49_022589D8(void *ctx, u16 target, u16 *outX, u16 *outY, u32 ordinal) {
    int x;
    int y;
    u32 count = 0;

    for (y = 0; y < 42; y++) {
        u16 narrowedY = y;

        for (x = 0; x < 35; x++) {
            int value = ov49_022589B8(ctx, x, narrowedY);

            if (value == target) {
                if (count >= ordinal) {
                    *outX = x;
                    *outY = y;
                    return TRUE;
                }
                count++;
            }
        }
    }
    return FALSE;
}

BOOL ov49_02258A30(u8 value) {
    u32 i;

    for (i = 0; i < 32; i++) {
        if (value == ov49_02269634[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov49_02258A50(u8 value) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (value == _02269624[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov49_02258A70(u8 value) {
    u32 i;

    for (i = 0; i < 7; i++) {
        if (value == ov49_0226962C[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov49_02258A90(u8 value) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (value == ov49_02269628[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
