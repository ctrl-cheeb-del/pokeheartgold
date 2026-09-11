#include "overlay96_object_internal.h"
#define STRIDE 0xA8

void ov96_02215ECC(Course *course, int index) {
    u8 *base = (u8 *)PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_02218688(base + 0x1A4 + index * STRIDE);
}
