#include "field_map_object_render_internal.h"

void ov01_021FA61C(void *p, u32 id, void *resource, u32 which) {
    if (GF3dGfxRawResMan_AllocObjAndKeys(*(void **)((u8 *)p + 0xf0), resource, id, 1, 4) == NULL) {
        GF_AssertFail();
    }
    ov01_021FA668(p, id);
    if (which == 0) {
        ov01_021F9D5C(p, id);
    } else {
        ov01_021F9DD0(p, id);
    }
}
