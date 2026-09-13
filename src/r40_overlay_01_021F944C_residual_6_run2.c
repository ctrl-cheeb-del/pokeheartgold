#include "field_map_object_render_internal.h"
#include "r40_overlay_01_021F944C_residual_6_private.h"

BOOL ov01_021F9E9C(void *p, u32 value) {
    u32 *a = ov01_021FA1FC(p);
    u32 offset = (u32)ov01_021FA22C(p) << 2;
    u32 count = (u32)ov01_021FA234(p);
    return ov01_021F9AD0((u32 *)((u8 *)a + offset), value, count);
}
