#include "global.h"

#include "field_map_object_motion_internal.h"
#include "to45_ov01_motion_sequences_r5_private.h"

extern const Ov01Table7R5 ov01_02208A64;
extern const Ov01Table4R5 ov01_02208A08;
extern const Ov01Table8R5 ov01_02208A80;

#define DEFINE_TRACKED_SEQUENCE(name, expected, table_type, table_name) \
    void name(void *owner, void *object, s8 *stateRaw, int direction) { \
        Ov01MotionStateR5 *state = (Ov01MotionStateR5 *)stateRaw;       \
        if (direction != state->previousDirection) {                    \
            sub_02023EE0(object, ov01_021FA44C(direction));             \
            sub_02023F40(object, 0);                                    \
            state->index = 0;                                           \
        }                                                               \
        if (state->kind != expected) {                                  \
            state->index = 0;                                           \
        }                                                               \
        if (!ov01_021F9344(owner)) {                                    \
            table_type sequence = table_name;                           \
            sub_02023F04(object, sequence.values[state->index]);        \
            state->index++;                                             \
            if (sequence.values[state->index] == 0) {                   \
                state->index = 0;                                       \
            }                                                           \
        }                                                               \
    }

DEFINE_TRACKED_SEQUENCE(ov01_021F7A90, 6, Ov01Table7R5, ov01_02208A64)
DEFINE_TRACKED_SEQUENCE(ov01_021F7B14, 7, Ov01Table4R5, ov01_02208A08)
DEFINE_TRACKED_SEQUENCE(ov01_021F7B90, 8, Ov01Table8R5, ov01_02208A80)
