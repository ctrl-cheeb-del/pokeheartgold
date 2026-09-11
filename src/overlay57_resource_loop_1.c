#include "overlay57_resource_loop_internal.h"

void ov57_0223A034(void *w, u32 flag) {
    int i;
    u8 *p = w;
    for (i = 0; i < 13; i++, p += 4) {
        void *s = *(void **)(p + 0x414);
        if (s) {
            ManagedSprite_SetDrawFlag(s, flag);
        }
    }
}
