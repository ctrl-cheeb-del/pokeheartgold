#include "overlay96_course_scene_r86_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov96_02205D30(void *course) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    u8 *copy = PokeathlonCourse_GetDataCopyArea(course);
    u8 *v = ov96_021E8A20(copy + 0xF0);
    u8 mode = ov96_021E5F24(course);
    u32 packed = *(u32 *)(v + mode * 4);
    u32 x = packed & 0x1FF;
    u32 y = (packed >> 9) & 0x1FF;
    ScheduleSetBgPosText(PTR(p, 0), 0, 0, x - 0x80);
    ScheduleSetBgPosText(PTR(p, 0), 0, 3, y - 0x60);
    ov96_02206380(course, mode, p + 0x24, copy);
    ov96_02206A24(p, x, y);
    ov96_02206AC0(p, x, y);
    ov96_02206B80(p, v, x, y);
    ov96_02207BE4(p);
    ov96_02208740(PTR(p, 0x370), *(u16 *)(v + 0x22));
    ov96_021E6454(course, *(u16 *)(v + 0x22));
}

BOOL ov96_02205DD4(u8 *p, int index, int delta, int value) {
    u8 *item = p + 0x24 + index * 0xB8;
    int x;
    int y;
    void *obj;
    if (item[0xB1] >= 3) {
        GF_AssertFail();
    }
    obj = PTR(item, item[0xB1] * 4);
    ov96_021EB0A4(obj, 0x80, 0x60, &x, &y);
    if (ov96_021EB0CC(obj, x << 12, y << 12, delta, value)) {
        return TRUE;
    }
    return FALSE;
}
