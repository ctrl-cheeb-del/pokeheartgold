#include "overlay96_course_scene_internal.h"

void *ov96_02208FB8(void *work) {
    Ov96CourseSceneRect *sorted[48];
    Ov96CourseSceneRect *list[48];
    s32 i;
    s32 count;
    u8 index;

    for (i = 0; i < 48; i++) {
        list[i] = (Ov96CourseSceneRect *)((u8 *)work + 0x190 + i * 0x14);
    }
    count = ov96_02208FF0(list, sorted);
    index = LCRandom() % count;
    return sorted[index];
}
