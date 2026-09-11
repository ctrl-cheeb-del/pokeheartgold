#include "overlay14_box_item_panel_private.h"

void ov14_021F49E0(void *p);
void ov14_021F4A20(void *p, u32 slot);
void ov14_021F4A64(void *p, u32 box, void *dst);
void ov14_021F4B90(void *q, u32 i, s32 x, s32 y, u32 v);
void ov14_021F4BC0(void *p);
void ov14_021F4CA0(void *p);
void ov14_021F4D10(void *q);
void ov14_021F4E68(void *q);
void ov14_021F4EA0(void *q, void *window, u32 i);
void ov14_021F4ED0(void *p);
void ov14_021F4F00(void *p);
void ov14_021F4F24(void *window, void *str, s32 x, s32 y, u32 font, u32 color, u32 align);
void ov14_021F4F84(void *q, void *msgData, u32 win, u32 msgId, s32 x, s32 y, u32 font, u32 color, u32 align);
void ov14_021F4FBC(void *q, void *msgData, u32 win, u32 msgId, s32 x, s32 y, u32 font, u32 color, u32 align);
void ov14_021F5000(void *q, BoxMonView *mon, u32 win);
void ov14_021F5054(void *q, BoxMonView *mon, u32 win);
void ov14_021F50A0(void *q, BoxMonView *mon, u32 win);
void ov14_021F5114(void *q, BoxMonView *mon, u32 win);
void ov14_021F5190(void *p, BoxMonView *mon, u32 win);
void ov14_021F521C(void *q, BoxMonView *mon, u32 win);
void ov14_021F528C(void *q, BoxMonView *mon, u32 win);
void ov14_021F52FC(void *q, BoxMonView *mon, u32 win);
void ov14_021F5368(void *p, BoxMonView *mon);
void ov14_021F53C0(void *q);
u32 ov14_021F5404(void *p, BoxMonView *mon);
u32 ov14_021F5564(void *p, u32 itemId);
void ov14_021F5620(void *p);
void ov14_021F566C(void *p);
void ov14_021F5718(void *p, void *src, u32 a2, u32 a3, u32 a5);
void ov14_021F57B8(void *p);
void ov14_021F58B8(void *p);
void ov14_021F5950(void *p, u32 win, u32 msgId, u32 style);
void ov14_021F5BD8(void *p, u32 win, u32 msgId, u32 style, u8 align);
void ov14_021F5C84(void *p, u32 style);
void ov14_021F5C94(void *p, u32 win, u32 msgId);
void ov14_021F5E94(void *p);
void ov14_021F5EB4(void *p, u32 style);
void ov14_021F5EC4(void *p, u32 style);
void ov14_021F5ED4(void *p, u32 style);
void ov14_021F5EE4(void *p, BoxMenuEntry *list, u32 count);
void ov14_021F5FBC(void *p, u32 which);

void ov14_021F5E94(void *p) {
    if (U32_AT(PTR_AT(p, 0), 8) == 3) {
        ov14_021F5C94(p, 0x19, 0x40);
    } else {
        ov14_021F5C94(p, 0x19, 0x3d);
    }
}

void ov14_021F5EB4(void *p, u32 style) {
    ov14_021F5950(p, 0x1a, 0x3e, style);
}

void ov14_021F5EC4(void *p, u32 style) {
    ov14_021F5950(p, 0x1b, 0x4c, style);
}

void ov14_021F5ED4(void *p, u32 style) {
    ov14_021F5950(p, 0x1c, 0x47, style);
}

void ov14_021F5EE4(void *p, BoxMenuEntry *list, u32 count) {
    u16 v[2];
    u32 i;

    sub_02019B44(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 3, &v[1], &v[0]);
    for (i = 0; i < count; i++) {
        BoxMenuEntry *e = &list[count - 1 - i];
        if (e->kind == 0) {
            ov14_021F5950(p, 0x21 - i, e->msgId, 0);
            sub_020199F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 7 - i, 0, 0, (u8)v[1], (u8)v[0], 0xc);
        } else {
            ov14_021F5C94(p, 0x21 - i, e->msgId);
            sub_020199F4(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 7 - i, 0, 0, (u8)v[1], (u8)v[0], 2);
        }
    }
    for (; count < 5; count++) {
        FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + (0x21 - count) * 0x10, 0);
        CopyWindowPixelsToVram_TextMode((u8 *)PTR_AT(p, 0x34) + 0x30 + (0x21 - count) * 0x10);
    }
}

void ov14_021F5FBC(void *p, u32 which) {
    FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x1d * 0x10, 0);
    FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x1e * 0x10, 0);
    FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x1f * 0x10, 0);
    FillWindowPixelBuffer((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x20 * 0x10, 0);
    CopyWindowPixelsToVram_TextMode((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x1d * 0x10);
    CopyWindowPixelsToVram_TextMode((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x1e * 0x10);
    CopyWindowPixelsToVram_TextMode((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x1f * 0x10);
    CopyWindowPixelsToVram_TextMode((u8 *)PTR_AT(p, 0x34) + 0x30 + 0x20 * 0x10);
    if (which == 0) {
        ov14_021F5950(p, 0x21, 0x51, 0);
    } else {
        ov14_021F5950(p, 0x21, 0x50, 0);
    }
}
