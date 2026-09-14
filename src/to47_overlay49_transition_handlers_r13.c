#include "to47_overlay49_transition_handlers_r13_private.h"

void ov49_022594D8(Ov49R13Work *work, void *ctx) {
    int value;
    int pos;

    switch (work->state) {
    case 0:
        work->timer = ov49_02259294(ov49_02269658, 4);
        work->state++;
        break;
    case 1:
        work->timer--;
        if (work->timer == 0) {
            work->state++;
        }
        break;
    case 2:
        value = ov42_02228188(work->field, 4);
        pos = ov42_02228188(work->field, 6);
        work->selected = ov49_02259294(ov49_0226965C, 4);
        if (ov49_022592A8(ctx, work, work->selected, value + 4) == TRUE) {
            if (pos == work->selected) {
                ov49_02258E7C(ctx, work, 2, work->selected);
                work->state = 4;
            } else {
                ov49_02258E7C(ctx, work, 1, work->selected);
                work->state = 3;
            }
        } else {
            ov49_02258E7C(ctx, work, 1, work->selected);
            work->state = 4;
        }
        break;
    case 3:
        if (ov42_02228188(work->field, 5) == 0) {
            ov49_02258E7C(ctx, work, 2, work->selected);
            work->state++;
        }
        break;
    case 4:
        if (ov42_02228188(work->field, 5) == 0) {
            work->state = 0;
        }
        break;
    }
}

void ov49_022595CC(Ov49R13Work *work) {
    int done;
    Ov49R13Position position;

    switch (work->state) {
    case 0:
        ov45_0223089C(work->object, 0);
        ov45_0223093C(work->object, 0);
        ov49_02259320(&work->interpolation, 0, 0x1F4000, 0x18);
        work->counter = 0x20;
        work->state++;
        /* fallthrough */
    case 1:
        work->counter--;
        if (work->counter == 0) {
            work->state++;
            work->counter = 0;
            PlaySE(0x64E);
        }
        break;
    case 2:
        done = ov49_0225932C(&work->interpolation, work->counter);
        work->counter++;
        ov45_02230908(work->object, &position);
        position.z = ov49_022593BC(&work->interpolation);
        ov45_022308E4(work->object, &position);
        if (done == TRUE) {
            work->state++;
            ov45_02230968(work->object);
            work->finished = TRUE;
        }
        break;
    case 3:
        break;
    }
}

void ov49_0225967C(Ov49R13Work *work) {
    int done;
    Ov49R13Position position;

    switch (work->state) {
    case 0:
        ov45_0223089C(work->object, 0);
        ov45_0223093C(work->object, 0);
        ov49_02259320(&work->interpolation, 0x1F4000, 0, 0x18);
        work->counter = 0;
        work->state++;
        PlaySE(0x64E);
        /* fallthrough */
    case 1:
        done = ov49_0225932C(&work->interpolation, work->counter);
        work->counter++;
        ov45_02230908(work->object, &position);
        position.z = ov49_022593BC(&work->interpolation);
        ov45_022308E4(work->object, &position);
        if (done == TRUE) {
            work->counter = 0x20;
            work->state++;
            return;
        }
        break;
    case 2:
        work->counter--;
        if (work->counter == 0) {
            work->state++;
            ov45_02230968(work->object);
            ov45_0223089C(work->object, 1);
            work->finished = TRUE;
        }
        break;
    case 3:
        break;
    }
}
