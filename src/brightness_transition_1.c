#include "brightness_transition_internal.h"

void sub_02010AB0(s32 *starts, s32 *ends, s32 *deltas, const u8 *startBytes, const u8 *endBytes, s32 steps) {
    starts[0] = startBytes[0] << 7;
    starts[1] = startBytes[1] << 7;
    starts[2] = startBytes[2] << 7;
    starts[3] = startBytes[3] << 7;
    ends[0] = endBytes[0];
    ends[1] = endBytes[1];
    ends[2] = endBytes[2];
    ends[3] = endBytes[3];
    deltas[0] = sub_02010A6C(startBytes[0], endBytes[0], steps);
    deltas[1] = sub_02010A6C(startBytes[1], endBytes[1], steps);
    deltas[2] = sub_02010A6C(startBytes[2], endBytes[2], steps);
    deltas[3] = sub_02010A6C(startBytes[3], endBytes[3], steps);
}

void sub_02010B14(BrightnessController *ctl, BOOL direction) {
    s32 start;
    s32 end;
    BrightnessTransition *transition = Heap_Alloc(ctl->heapId, sizeof(BrightnessTransition));
    ctl->transition = transition;
    memset(transition, 0, sizeof(BrightnessTransition));
    transition = ctl->transition;
    if (!direction) {
        if (ctl->setting == 0x7fff) {
            start = 0x10;
            end = 0;
        } else if (ctl->setting == 0) {
            start = -0x10;
            end = 0;
        } else {
            start = -0x10;
            end = 0;
            GF_AssertFail();
        }
    } else {
        if (ctl->setting == 0x7fff) {
            start = 0;
            end = 0x10;
        } else if (ctl->setting == 0) {
            start = 0;
            end = -0x10;
        } else {
            start = 0;
            end = -0x10;
            GF_AssertFail();
        }
    }
    SetMasterBrightness(ctl->screen, start);
    transition->steps = ctl->duration;
    transition->delay = ctl->target;
    transition->counter = 0;
    transition->current = start << 7;
    transition->target = end << 7;
    transition->delta = sub_02010A6C(start, end, ctl->duration);
    transition->screen = ctl->screen;
    ctl->state++;
}

BOOL sub_02010BB4(BrightnessController *ctl) {
    BOOL done = FALSE;
    BrightnessTransition *transition = ctl->transition;
    switch (ctl->state) {
    case 1:
        if (sub_02010BF4(transition) == TRUE) {
            ctl->state++;
        }
        break;
    case 2:
        Heap_Free(transition);
        ctl->transition = NULL;
        done = TRUE;
        ctl->state++;
        break;
    case 3:
        done = TRUE;
        break;
    }
    return done;
}
