#include "overlay96_shop_assets_r53_tail_private.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))

BOOL ov96_021F107C(void *course) {
    u8 *work;
    u8 *copy;
    u8 *touch;

    work = PokeathlonCourse_GetHeapAllocPtr4(course);
    copy = PokeathlonCourse_GetDataCopyArea(course);
    touch = ov96_021E8A20(copy);
    *(u32 *)touch = 0;
    copy = ov96_021E8A20(copy + 0xF0);
    {
        s32 raw = *(s32 *)(copy + 0x20);
        u8 flag = (raw >> 12) & 1;
        if (flag) {
            ov96_021EB63C(PTR_AT(work, 0x18), 1);
            ov96_021EB144(PTR_AT(work, 0x76C), 1);
            ov96_021E65A4(course);
            touch = ov96_021F46B4(PTR_AT(work, 0x774));
            ov96_021E8318(course, touch);
            ov96_021F2EFC(work, touch);
            return TRUE;
        }
    }
    if (U8_AT(work, 0x72A) != 0) {
        int kind;
        u8 mode = U8_AT(work, 0x727);
        if (mode < 1) {
            kind = 0;
        } else if (mode < 3) {
            kind = 1;
        } else if (mode < 4) {
            kind = 2;
        } else {
            kind = 3;
        }
        U16_AT(work, 0x732) = ov96_021F30F8((u8)U16_AT(work, 0x732), kind);
        U8_AT(work, 0x72A) = 0;
    }
    if (System_GetTouchNew()) {
        ov96_021E8228(course, (u8)ov96_021E5F24(course), 3, 0, 1);
    }
    if (System_GetTouchHeld()) {
        touch[4] = gSystem.touchX;
        touch[5] = gSystem.touchY;
        *(u32 *)touch = 1;
    }
    ov96_021F1614(course);
    return FALSE;
}
