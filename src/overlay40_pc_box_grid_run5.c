#include "overlay40_pc_box_grid_private.h"

int ov40_02231868(void *p) {
    if (ov40_0223142C(p)) {
        if (WORD(p, 0x44) == 1) {
            sub_020879E0(PTR(p, 0x6F0), 0);
            ov40_0222BF80(p, 0);
        } else {
            ov40_0222BF80(p, 1);
        }
    }
    return 0;
}

int ov40_0223189C(void *p) {
    if (WORD(p, 0x44) == 1) {
        sub_020879E0(PTR(p, 0x6F0), 0);
        ov40_0222BF80(p, 0);
    } else {
        ov40_0222BF80(p, 1);
    }
    return 0;
}
