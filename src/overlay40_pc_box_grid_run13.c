#include "overlay40_pc_box_grid_private.h"

int ov40_02233EE8(void *p) {
    u32 x;
    u32 y;
    if (System_GetTouchNewCoords(&x, &y)) {
        if (x > 0x50 && x < 0xB0 && y > 0x98 && y < 0xB0) {
            PlaySE(0x57B);
            ov40_0222BF80(p, 2);
        }
    }
    return 0;
}
