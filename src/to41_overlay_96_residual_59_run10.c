#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void ov96_021F6E38(Ov96R59Work *w) {
    u16 total = 0;
    int i;
    u8 *p;
    for (i = 0, p = (u8 *)w; i < 3; i++, p += 0x38) {
        total = total + *(u16 *)(p + 0xb0);
    }
    if (total > 999) {
        total = 999;
    }
    ov96_021F6E68(w, total);
}
