#include "field_map_object_render_internal.h"

u8 ov01_021FA28C(u32 p) {
    return *((u8 *)sub_021FA248(p) + 2);
}

u8 ov01_021FA298(u32 p) {
    return ov01_021FA28C(p);
}

u8 ov01_021FA2A0(u32 p) {
    return *((u8 *)sub_021FA248(p) + 3);
}

u32 ov01_021FA2AC(u32 p) {
    return *(u32 *)((u8 *)sub_021FA248(p) + 4);
}

void ov01_021FA2B8(void *obj, BOOL set) {
    if (set == TRUE) {
        MapObject_SetFlagsBits(obj, 1 << 22);
    } else {
        MapObject_ClearFlagsBits(obj, 1 << 22);
    }
}

BOOL ov01_021FA2D4(void *obj) {
    return MapObject_GetFlagsBitsMask(obj, 1 << 22) != 0;
}

void ov01_021FA2EC(void *p, void *v) {
    u32 args[2];
    args[1] = 4;
    args[0] = (u32)v;
    ov01_021FA1C8(p, sub_020237EC(args));
    ov01_021FA1D8(p, v);
}

void *ov01_021FA314(void *p) {
    return sub_02023874(p);
}
