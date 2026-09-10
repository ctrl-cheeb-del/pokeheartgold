#include "field_overlay_effects_internal.h"

void ov01_021F029C(void *p) {
    if (*(void **)((u8 *)p + 0x3C)) {
        ov01_021F03F8(p);
    }
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    Heap_Free(p);
}
