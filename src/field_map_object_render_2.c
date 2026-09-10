#include "field_map_object_render_internal.h"

void ov01_021F9890(void *p) {
    ov01_021FC520(*(void **)((u8 *)p + 0xf8));
    ov01_021FC520(*(void **)((u8 *)p + 0xfc));
    GF3dGfxRawResMan_Destroy(ov01_021FA1F4(p));
}

void *ov01_021F98B4(u16 a, u16 terminator, u16 *p) {
    volatile u16 *scan = p;
    for (;;) {
        if (*scan == a) {
            return (void *)scan;
        }
        scan += 2;
        if (*scan == terminator) {
            return NULL;
        }
    }
}
