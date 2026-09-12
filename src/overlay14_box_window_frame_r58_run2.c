#include "overlay14_box_window_frame_r58_private.h"
void ov14_021F6208(UnkStruct_0201956C *mgr, int id, Window *window) {
    u32 width;
    u32 height;
    u32 bg = GetWindowBgId(window);
    width = GetWindowWidth(window);
    height = GetWindowHeight(window);
    sub_020195F4(mgr, id, bg, width, height);
    sub_02019A60(mgr, id, window);
}
void ov14_021F6244(void *p) {
    ov14_021F6208(PTR_AT(p, 0x2f0), 3, (Window *)((u8 *)p + 0x200));
    ov14_021F6208(PTR_AT(p, 0x2f0), 4, (Window *)((u8 *)p + 0x210));
    ov14_021F6208(PTR_AT(p, 0x2f0), 5, (Window *)((u8 *)p + 0x220));
    ov14_021F6208(PTR_AT(p, 0x2f0), 6, (Window *)((u8 *)p + 0x230));
    ov14_021F6208(PTR_AT(p, 0x2f0), 7, (Window *)((u8 *)p + 0x240));
    ov14_021F60BC(PTR_AT(p, 0x2f0), 0xc, (Window *)((u8 *)p + 0x2c0));
    ov14_021F6208(PTR_AT(p, 0x2f0), 0xe, (Window *)((u8 *)p + 0x2d0));
    ov14_021F6208(PTR_AT(p, 0x2f0), 0xf, (Window *)((u8 *)p + 0x2e0));
}
