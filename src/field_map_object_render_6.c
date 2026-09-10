#include "field_map_object_render_internal.h"

void ov01_021F9D48(void *p) {
    ov01_021F9AAC(ov01_021FA1FC(p), 0xffff, 0x20);
}

void ov01_021F9D5C(void *p, u32 value) {
    u32 count = (u32)ov01_021FA22C(p);
    u32 *a = ov01_021FA1FC(p);
    if (!ov01_021F9AB4(a, value, 0xffff, count)) {
        GF_AssertFail();
    }
}

BOOL ov01_021F9D88(void *p, u32 value) {
    u32 count = (u32)ov01_021FA22C(p);
    u32 *a = ov01_021FA1FC(p);
    return ov01_021F9AD0(a, value, count);
}

int ov01_021F9DA4(void *p, u32 v) {
    if (ov01_021F9D88(p, v) == 1) {
        return 1;
    }
    if (ov01_021F9E9C(p, v) == 1) {
        return 2;
    }
    return ov01_021FA524(p, v);
}
