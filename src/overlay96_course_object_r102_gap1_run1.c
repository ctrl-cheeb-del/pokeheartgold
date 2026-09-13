#include "overlay96_course_object_r102_gap1_private.h"

void ov96_0220F3FC(Ov96R102Gap1Work *work) {
    struct {
        Ov96R102Gap1Work *p;
    } saved;
    void *sprites;
    void *course;
    saved.p = work;
    sprites = SpriteManager_GetSpriteList(saved.p->spriteManager);
    saved.p->objectManager = ov96_021EA854(saved.p->heapId, 12, 7, saved.p->field1C, sprites);
    ov96_021EB138(saved.p->objectManager);
    {
        Ov96R102Gap1ParticipantView views[12];
        u32 values[17] = { 0 };
        int i;
        course = saved.p->course;
        for (i = 0; i < 12; i++) {
            int column = i % 3;
            int row = i / 3;
            ov96_021E6168(course, row, column, &views[i]);
            values[i + 5] = ov96_021E6108(ov96_021E60C0(course, row, column));
        }
        values[1] = 1;
        values[3] = 1;
        values[4] = 1;
        ov96_021EA8A8(saved.p->objectManager, 12, views, values, 0, 0);
    }
}
