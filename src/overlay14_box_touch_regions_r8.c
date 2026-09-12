#include "overlay14_box_touch_regions_r8_private.h"

u32 ov14_021E7940(s32 x, s32 y, const u8 *r) {
    if (x >= r[0] && x <= r[1] && y >= r[2] && y < r[3]) {
        return 1;
    }
    return 0;
}
u32 ov14_021E7960(s32 x, s32 y) {
    if (ov14_021E7940(x, y, _021F7BBC) == 1) {
        if (x < 12) {
            x = 0;
        } else if (x >= 156) {
            x = 5;
        } else {
            x = (s16)((x - 12) / 24);
        }
        return x + (s16)((y - 40) / 24) * 6;
    }
    return 0xff;
}
u32 ov14_021E79AC(s32 x, s32 y, const u8 *rect) {
    u32 i;
    for (i = 0; i < 6; i++, rect += 4) {
        if (ov14_021E7940(x, y, rect) == 1) {
            return i + 0x1e;
        }
    }
    return 0xff;
}
u32 ov14_021E79D8(s32 x, s32 y) {
    u32 i;
    const u8 *rect = ov14_021F7BD8;
    for (i = 0; i < 6; i++, rect += 4) {
        if (ov14_021E7940(x, y, rect) == 1) {
            return i + 0x80;
        }
    }
    return 0xff;
}
