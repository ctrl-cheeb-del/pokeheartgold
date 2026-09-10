#include "field_overlay_effects_internal.h"

void ov01_021F0028(void *p) {
    if (*(void **)((u8 *)p + 0x24)) {
        ov01_021F0174(p);
    }
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    Heap_Free(p);
}
