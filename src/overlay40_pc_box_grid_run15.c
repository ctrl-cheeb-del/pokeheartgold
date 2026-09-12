#include "overlay40_pc_box_grid_private.h"

int ov40_02234A14(void *p) {
    if (WORD(p, 8) == 0) {
        ov40_022359B4(p, 1);
        WORD(p, 8) = WORD(p, 8) + 1;
    } else {
        ov40_0222BF80(p, 3);
    }
    return 0;
}
