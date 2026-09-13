#include "field_map_object_render_internal.h"
#include "r40_overlay_01_021F944C_residual_5_private.h"

void ov01_021F9C78(void *p, u32 value) {
    u32 *a = ov01_021FA204(p);
    u32 offset = (u32)ov01_021FA21C(p) << 2;
    u32 count = (u32)ov01_021FA224(p);
    if (!ov01_021F9AB4((u32 *)((u8 *)a + offset), value, 0xFF, count)) {
        GF_AssertFail();
    }
}

BOOL ov01_021F9CA8(void *p, u32 value) {
    u32 *a = ov01_021FA204(p);
    u32 offset = (u32)ov01_021FA21C(p) << 2;
    u32 count = (u32)ov01_021FA224(p);
    return ov01_021F9AD0((u32 *)((u8 *)a + offset), value, count);
}

int ov01_021F9CD0(void *p, u32 value) {
    u32 *a = ov01_021FA204(p);
    u32 offset = (u32)ov01_021FA21C(p) << 2;
    u32 count = (u32)ov01_021FA224(p);
    return ov01_021F9AE4((u32 *)((u8 *)a + offset), value, 0xFF, count);
}
