#include "overlay40_pc_box_grid_private.h"

int ov40_0223169C(void *p) {
    if (System_GetTouchNew() && PTR(p, 0x89C) == NULL) {
        ov40_0222DE40(p);
    }
    if (WORD(p, 0) == 0) {
        switch (ov40_02231700()) {
        case 1:
            PlaySE(0x57B);
            ov40_0222BF80(p, 7);
            return 0;
        case 2:
            PlaySE(0x57B);
            ov40_0222BF80(p, 8);
            return 0;
        }
    }
    ov40_0222C474(p);
    return 0;
}

int ov40_02231700(void) {
    if (TouchscreenHitbox_TouchHeldIsIn(ov40_02245100)) {
        return 1;
    }
    if (TouchscreenHitbox_TouchHeldIsIn(ov40_02245104)) {
        return 2;
    }
    return 0;
}

int ov40_0223172C(void *p) {
    GF_AssertFail();
    WORD(p, 0x44) = 1;
    ov40_0222BF80(p, 0);
    return ov40_0223169C(p);
}
