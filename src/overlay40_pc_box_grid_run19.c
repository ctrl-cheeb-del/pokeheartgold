#include "overlay40_pc_box_grid_private.h"

void ov40_02235FA0(void *p) {
    void *w = PTR(p, 0x860);
    DestroyMsgData(PTR(w, 0x1E0));
    Heap_Free(PTR(w, 0x1E8));
    Heap_Free(PTR(w, 0x1DC));
    PTR(w, 0x1E4) = NULL;
}

void ov40_02235FD0(u32 sel, int flag, void *scene) {
    if (flag != 0) {
        return;
    }
    if (!ov40_02235DAC(scene, sel)) {
        PlaySE(0x57C);
        return;
    }
    ov40_02235E34(scene, sel);
}
