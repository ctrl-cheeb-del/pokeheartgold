#include "r40_overlay_40_residual_27_unmatched_17_private.h"

void ov40_02235940(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
    G2_SetWnd0InsidePlane(0x1f, TRUE);
    G2_SetWndOutsidePlane(0x1e, TRUE);
    G2_SetWnd0Position(0x48, 0x10, 0xb8, 0x90);
}
