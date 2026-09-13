#include "r40_overlay_45_thumb_residual_32_private.h"

void ov45_0222E688(void) {
    if (_022577C0 == NULL) {
        GF_AssertFail();
    }
    ov45_022303FC((u8 *)_022577C0 + 0x6A0);
    ov45_0222FA10(_022577C0);
    ov45_0222F878(_022577C0);
    Heap_Free(_022577C0);
    _022577C0 = NULL;
}
