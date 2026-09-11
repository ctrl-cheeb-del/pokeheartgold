#include "overlay96_object_internal.h"
#define STRIDE 0xA8

u8 ov96_02215E48(Course *course, int index) {
    u8 *base = (u8 *)PokeathlonCourse_GetHeapAllocPtr4(course);
    void *object = *(void **)(base + index * STRIDE + 0x1A8);
    return *(s32 *)((u8 *)object + 8) >> 12;
}

u8 ov96_02215E68(Course *course, int index) {
    u8 *base = (u8 *)PokeathlonCourse_GetHeapAllocPtr4(course);
    u8 *object = *(u8 **)(base + index * STRIDE + 0x1A8);
    return (FX_Div(*(fx32 *)(object + 8), *(fx32 *)(*(u8 **)(object + 4) + 8)) * 100) >> 12;
}
