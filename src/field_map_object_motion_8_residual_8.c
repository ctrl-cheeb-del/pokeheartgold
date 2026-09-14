#include "global.h"

#include "field_map_object_motion_internal.h"

typedef struct MotionSequence4 {
    fx32 values[4];
} MotionSequence4;

typedef struct MotionSequence7 {
    fx32 values[7];
} MotionSequence7;

typedef struct MotionSequence8 {
    fx32 values[8];
} MotionSequence8;

extern const MotionSequence4 ov01_022089D8;
extern const MotionSequence7 ov01_02208A48;
extern const MotionSequence8 ov01_02208AA0;

void ov01_021F80C4(void *owner, void *obj, s8 *state, int index) {
    if (index != state[0]) {
        sub_02023EE0(obj, ov01_021FA44C(index));
        sub_02023F40(obj, 0);
        state[1] = 0;
    } else if (state[2] == 9) {
        ov01_021F8C64(obj, ov01_021FA44C(index));
    }
    if (state[2] != 6) {
        state[1] = 0;
    }
    if (!ov01_021F9344(owner)) {
        MotionSequence7 sequence = ov01_02208A48;
        sub_02023F04(obj, sequence.values[state[1]]);
        state[1]++;
        if (sequence.values[state[1]] == 0) {
            state[1] = 0;
        }
    }
}

void ov01_021F8164(void *owner, void *obj, s8 *state, int index) {
    if (index != state[0]) {
        sub_02023EE0(obj, ov01_021FA44C(index));
        sub_02023F40(obj, 0);
        state[1] = 0;
    } else if (state[2] == 9) {
        ov01_021F8C64(obj, ov01_021FA44C(index));
    }
    if (state[2] != 7) {
        state[1] = 0;
    }
    if (!ov01_021F9344(owner)) {
        MotionSequence4 sequence = ov01_022089D8;
        sub_02023F04(obj, sequence.values[state[1]]);
        state[1]++;
        if (sequence.values[state[1]] == 0) {
            state[1] = 0;
        }
    }
}

void ov01_021F81FC(void *owner, void *obj, s8 *state, int index) {
    if (index != state[0]) {
        sub_02023EE0(obj, ov01_021FA44C(index));
        sub_02023F40(obj, 0);
        state[1] = 0;
    } else if (state[2] == 9) {
        ov01_021F8C64(obj, ov01_021FA44C(index));
    }
    if (state[2] != 8) {
        state[1] = 0;
    }
    if (!ov01_021F9344(owner)) {
        MotionSequence8 sequence = ov01_02208AA0;
        sub_02023F04(obj, sequence.values[state[1]]);
        state[1]++;
        if (sequence.values[state[1]] == 0) {
            state[1] = 0;
        }
    }
}
