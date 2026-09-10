#include "field_map_object_motion_internal.h"

void ov01_021F7CBC(void *unused, void *obj, const s8 *state, int index) {
    if (state[3] != 9) {
        sub_02023EE0(obj, 4);
        sub_02023F40(obj, 0);
    }
    sub_02023F04(obj, FX32_ONE);
}
