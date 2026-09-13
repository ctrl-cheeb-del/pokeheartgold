#include "r40_overlay_96_residual_103_private.h"

int ov96_0220FF68(u32 value) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (ov96_0221CF1C[i] <= value) {
            return i;
        }
    }
    return -1;
}
