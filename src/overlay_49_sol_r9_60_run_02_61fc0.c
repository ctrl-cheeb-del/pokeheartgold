#include "overlay49_sol_r9_60_private.h"

BOOL ov49_02261FC0(void *ctx, void *map, void **items, u32 count, u16 *out) {
    u32 i;
    u16 y;
    u16 x;

    for (i = 0; i < count; i++) {
        if (ov49_022589D8(ctx, items[i], &y, &x, 0) == TRUE && ov49_02258F7C(map, y, x) == FALSE) {
            out[0] = y << 4;
            out[1] = x << 4;
            return TRUE;
        }
    }
    return FALSE;
}
