#include "field_map_object_render_internal.h"
#include "r40_overlay_01_021F944C_residual_4_private.h"

void ov01_021F9B54(void *p, u32 value) {
    u32 *a = ov01_021FA200(p);
    u32 offset = (u32)ov01_021FA20C(p) << 2;
    u32 count = (u32)ov01_021FA214(p);
    if (!ov01_021F9AB4((u32 *)((u8 *)a + offset), value, 0xFF, count)) {
        GF_AssertFail();
    }
}

BOOL ov01_021F9B84(void *p, u32 value) {
    u32 *a = ov01_021FA200(p);
    u32 offset = (u32)ov01_021FA20C(p) << 2;
    u32 count = (u32)ov01_021FA214(p);
    return ov01_021F9AD0((u32 *)((u8 *)a + offset), value, count);
}

int ov01_021F9BAC(void *p, u32 value) {
    u32 *a = ov01_021FA200(p);
    u32 offset = (u32)ov01_021FA20C(p) << 2;
    u32 count = (u32)ov01_021FA214(p);
    return ov01_021F9AE4((u32 *)((u8 *)a + offset), value, 0xFF, count);
}
