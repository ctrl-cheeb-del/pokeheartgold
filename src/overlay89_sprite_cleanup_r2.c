#include "overlay89_sprite_cleanup_r2_private.h"

void ov89_022598A8(void *work) {
    int i;
    u8 *entry = work;

    Sprite_DeleteAndFreeResources(PTR(work, 0x96c));
    for (i = 0; i < 8; i++, entry += 4) {
        Sprite_DeleteAndFreeResources(PTR(entry, 0x970));
    }
}
