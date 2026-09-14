#include "overlay96_course_touch_r46_77_private.h"

BOOL ov96_021FDB64(void *course) {
    u8 *work;
    u8 *copy;
    u8 *touch;
    u8 j;
    u8 i;

    work = PokeathlonCourse_GetHeapAllocPtr4(course);
    copy = PokeathlonCourse_GetDataCopyArea(course);
    touch = ov96_021E8A20(copy);
    *(u32 *)touch = 0;
    copy = ov96_021E8A20(copy + 0xf0);
    {
        u8 flag = ((s32) * (u32 *)(copy + 0x14) >> 24) & 1;
        if (flag) {
            ov96_021EB52C(PTR8(work, 0x28), 1, 0);
            Sprite_SetDrawFlag(PTR8(work, 0x20), FALSE);
            Sprite_SetDrawFlag(PTR8(work, 0x24), FALSE);
            ov96_021EB63C(PTR8(work, 0x18), 1);
            ov96_021EB144(PTR8(work, 0x3c8), 1);
            ov96_021E8324(course, ov96_021FFEE8);
            if (!ov96_021E5F24(course)) {
                for (i = 0; i < 4; i++) {
                    u8 *entry = work + i * 0xd4;
                    for (j = 0; j < 3; j++) {
                        s32 value = *(s32 *)(entry + 0x3c + j * 4) / 1024;
                        ov96_021E8228(course, i, j, 3, (u8)(value / 4096));
                    }
                }
            }
            return TRUE;
        }
    }
    if (System_GetTouchNew()) {
        ov96_021E8228(course, (u8)ov96_021E5F24(course), 3, 0, 1);
    }
    if (System_GetTouchHeld()) {
        touch[4] = *(u16 *)(gSystem + 0x60);
        touch[5] = *(u16 *)(gSystem + 0x62);
        *(u32 *)touch = 1;
    }
    ov96_021FDC7C(course);
    return FALSE;
}
