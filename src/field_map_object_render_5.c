#include "field_map_object_render_internal.h"

void ov01_021F9C24(void *p) {
    ov01_021F9AAC(ov01_021FA204(p), 0xff, 8);
}

void ov01_021F9C34(void *p, u32 value) {
    u32 count = (u32)ov01_021FA21C(p);
    u32 *a = ov01_021FA204(p);
    if (!ov01_021F9AB4(a, value, 0xff, count)) {
        GF_AssertFail();
    }
}

BOOL ov01_021F9C5C(void *p, u32 value) {
    u32 count = (u32)ov01_021FA21C(p);
    u32 *a = ov01_021FA204(p);
    return ov01_021F9AD0(a, value, count);
}
