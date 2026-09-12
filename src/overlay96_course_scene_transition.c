#include "overlay96_course_scene_internal.h"

BOOL ov96_0220935C(void *course, u8 *state) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    switch (*state) {
    case 0:
        ov96_0220A4DC(course);
        ov96_0220A14C(course);
        if (ov96_022091B4(course)) {
            (*state)++;
        }
        break;
    case 1:
        if (ov96_021E667C(course) && OV96_R92_U32_AT(work, 0x268) == 0) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, OV96_R92_U32_AT(work, 0));
            PokeathlonCourse_SetStateField07(course, 2);
        }
        break;
    }
    return FALSE;
}
