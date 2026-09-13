#include "to42_overlay_45_thumb_residual_24_private.h"

void ov45_0222C3B0(Ov45Grid *p) {
    int i;
    if (p->active != 0) {
        for (i = 0; i < 9; i++) {
            if (p->target == ov45_02254A3C[i]) {
                p->pad2C[i] = 1;
            }
            if (p->pad2C[i] == 1) {
                if (p->counters[i] + 1 <= 0x4B0) {
                    p->counters[i]++;
                } else {
                    p->pad2C[i] = 2;
                }
            }
        }
        if (p->target + 1 <= 0x10E0) {
            p->target++;
        }
    }
}
