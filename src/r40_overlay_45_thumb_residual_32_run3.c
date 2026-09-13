#include "r40_overlay_45_thumb_residual_32_private.h"

void ov45_0222E7CC(void) {
    if (_022577C0 == NULL) {
        GF_AssertFail();
    }
    if (*(u32 *)((u8 *)_022577C0 + 0x984) != 0) {
        ov45_02233220();
    } else {
        ov45_022331E8();
    }
}
