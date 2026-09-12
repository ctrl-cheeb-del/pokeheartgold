#include "overlay96_course_scene_r86_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

int ov96_0220549C(void *course, u8 *state) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    switch (*state) {
    case 0:
        ov96_02205D30(course);
        if (ov96_021E637C(course)) {
            (*state)++;
        }
        break;
    case 1:
        ov96_022055AC(course);
        if (ov96_02205C94(course)) {
            (*state)++;
        }
        break;
    case 2:
        ov96_022055AC(course);
        if (ov96_021E667C(course)) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, PTR(p, 0x14));
            PokeathlonCourse_SetStateField07(course, 2);
        }
        break;
    }
    return 0;
}
