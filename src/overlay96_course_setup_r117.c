#include "overlay96_course_setup_r117_private.h"

void ov96_02217AE4(Ov96R117Work *work, void *course) {
    struct {
        Ov96R117Work *p;
    } saved;
    void *sprites;

    saved.p = work;
    sprites = SpriteManager_GetSpriteList(saved.p->spriteManager);
    saved.p->objectManager = ov96_021EA854(saved.p->course, 12, 7, saved.p->field18, sprites);
    {
        Ov96R117ParticipantView views[12];
        u32 values[17] = { 0 };
        int i;

        for (i = 0; i < 12; i++) {
            int column = i % 3;
            int row = i / 3;
            ov96_021E6168(course, row, column, &views[i]);
            values[i + 5] = ov96_021E6108(ov96_021E60C0(course, row, column));
        }
        values[1] = 3;
        values[3] = 1;
        values[4] = 1;
        ov96_021EA8A8(saved.p->objectManager, 12, views, values, 0, 0);
    }
}
