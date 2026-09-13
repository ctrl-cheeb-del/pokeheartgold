#include "overlay96_course_r85_private.h"

int ov96_022043C0(Ov96R85Work *work, void *arg) {
    int result = 12;
    int first;
    int selected;

    if (work->done == 4) {
        return 0;
    }

    work->timer++;
    if (work->timer >= work->limit) {
        work->active = 1;
        work->timer = 0;
    }

    if (work->active != 0) {
        first = work->base + work->current;
        selected = work->group + first * 3;
        if (selected < work->base) {
            GF_AssertFail();
        }
        if ((work->states[selected]->state == 0 || work->states[selected]->state == 2) && work->objects[selected]->flag != 1) {
            ov96_022044A0(work, (u8)first, (u8)selected, arg);
        }
        result = (u8)selected;
        work->current++;
        if (work->current >= work->groupCount) {
            work->current = 0;
            work->group = (work->group + 1) % 3;
            work->active = 0;
        }
    }

    return result;
}
