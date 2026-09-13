#include "r40_overlay_96_residual_10_private.h"

void ov96_021E87B4(void *a0, void *a1, s32 value, Ov96R10Dispatch *dispatch) {
    if (dispatch->check != 0 && value > 0x26) {
        GF_AssertFail();
    }
    if (dispatch->mode == 1) {
        sub_02037030(a0, a1, value);
    } else {
        ov96_021E8914(dispatch->data, a0, a1, value);
    }
}

void ov96_021E87EC(void *a0, void *a1, void *a2, Ov96R10Dispatch *dispatch) {
    if (dispatch->mode == 1) {
        sub_02036FD8(a0, a1, a2);
    } else {
        ov96_021E8988(dispatch->data, a0, a1, a2);
    }
}

void ov96_021E8810(Ov96R10Dispatch *dispatch) {
    if (dispatch->mode == 0) {
        ov96_021E88FC(dispatch->data);
    }
    Heap_Free(dispatch);
}
