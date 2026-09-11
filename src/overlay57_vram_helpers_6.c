#include "overlay57_vram_helpers_private.h"

void ov57_0223921C(void *work) {
    if (R20_PTR(work, 0xd8) != NULL) {
        s32 i;
        u8 *p = work;
        for (i = 0; i < 4; i++, p += 4) ManagedSprite_TickFrame(R20_PTR(p, 0x33c));
    }
}
