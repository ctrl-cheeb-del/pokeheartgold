#include "field_map_object_render_internal.h"

void *ov01_021FA3DC(void *obj) {
    return sub_0205F1A0(MapObject_GetManager(obj));
}

int ov01_021FA3E8(void *a, void *b) {
    int v[3];
    ov01_021F93AC(a, v);
    v[2] += 0x6000;
    sub_02023E50(b, v);
    return 0;
}

void ov01_021FA40C(void *obj, void *dst) {
    BOOL visible = TRUE;
    if (MapObject_TestFlagsBits(obj, 1 << 9) == TRUE) {
        visible = FALSE;
    }
    if (MapObject_TestFlagsBits(obj, 1 << 12) == TRUE && MapObject_TestFlagsBits(obj, 2 << 12) == FALSE) {
        visible = FALSE;
    }
    sub_02023EA4(dst, (u8)visible);
}

u32 ov01_021FA44C(u32 i) {
    return ov01_02208B70[i];
}

u32 ov01_021FA458(u32 i) {
    return ov01_02208B80[i];
}

u32 ov01_021FA464(u32 i) {
    return ov01_02208B90[i];
}
