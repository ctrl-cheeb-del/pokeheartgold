#include "overlay40_pc_box_grid_private.h"

int ov40_02234470(void *p) {
    void *w = PTR(p, 0x860);
    if (TouchscreenHitbox_TouchNewIsIn(ov40_022451C8)) {
        ov40_02230944(p);
        ov40_0222BF80(p, 5);
    }
    if (TouchscreenHitbox_TouchNewIsIn(ov40_022451CC)) {
        ov40_02230944(p);
        ov40_0222BF80(p, 4);
    }
    if (PTR(w, 0x228) != NULL) {
        Thunk_G3X_Reset();
        ov41_0224B554(PTR(w, 0x228));
        RequestSwap3DBuffers(0, 0);
    }
    return 0;
}
