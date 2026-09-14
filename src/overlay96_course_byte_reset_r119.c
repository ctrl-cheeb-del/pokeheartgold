#include "overlay96_course_byte_reset_r119_private.h"

void ov96_02218784(void *course, s32 index) {
    u8 *ptr = (u8 *)PokeathlonCourse_GetHeapAllocPtr4(course) + 0x188 + index * 4;
    s32 i = 0;

    do {
        i++;
        *ptr = 0;
        ptr++;
    } while (i < 4);
}
