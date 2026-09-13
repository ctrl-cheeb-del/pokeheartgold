#include "overlay96_course_touch_hit_test_private.h"

BOOL ov96_021FDE08(u8 *p, int index, int c, int d) {
    s32 y;
    s32 x;
    u8 *item = p + 0x30 + index * 0xd4;
    void *obj;

    if (item[0x8b] >= 3) {
        GF_AssertFail();
    }
    obj = PTR(item, item[0x8b] * 4);
    ov96_021EB0A4(obj, 0x50, *(s32 *)(item + 0x80) / 4096, &y, &x);
    if (ov96_021EB0CC(obj, y << 12, x << 12, c, d)) {
        return TRUE;
    }
    return FALSE;
}
