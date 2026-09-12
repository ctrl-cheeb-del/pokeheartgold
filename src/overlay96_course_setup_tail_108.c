#include "overlay96_course_setup_108_private.h"
void ov96_022132FC(void *course) {
    u8 *base = PokeathlonCourse_GetHeapAllocPtr4(course);
    u8 i;
    int three = 3;

    base += 0x5C;
    for (i = 0; i < 12; i++) {
        int row = i / 3;
        int col = i % 3;
        u8 *entry = base + row * 0x174 + col * 0x7C;
        u32 state = *(u32 *)(entry + 0x78);
        if (state != 2) {
            if (entry[0x71] < 30) {
                *(u32 *)(entry + 0x78) = three;
            } else if (state != 1) {
                *(u32 *)(entry + 0x78) = 0;
            }
        }
    }
}
