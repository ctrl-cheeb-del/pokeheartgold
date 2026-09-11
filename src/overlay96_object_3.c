#include "overlay96_object_internal.h"
#define STRIDE 0xA8

void ov96_02215F64(Course *course, int index) {
    u8 *base = (u8 *)PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_0221910C(base + 0x1A4 + index * STRIDE);
}

void ov96_02215F80(Course *course, int index, void *arg) {
    u8 *base = (u8 *)PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_022186B8(base + 0x1A4 + index * STRIDE, arg);
}
