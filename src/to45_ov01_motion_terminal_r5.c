#include "global.h"

#include "field_map_object_motion_internal.h"
#include "to45_ov01_motion_sequences_r5_private.h"

void ov01_021F7C80(void *owner, void *object, const s8 *state, int direction) {
    if (direction != state[2] || state[3] == 9) {
        sub_02023EE0(object, ov01_021FA44C(direction));
        sub_02023F40(object, 0);
    } else {
        ov01_021F8C30(object);
    }
    sub_02023F04(object, 0);
}
