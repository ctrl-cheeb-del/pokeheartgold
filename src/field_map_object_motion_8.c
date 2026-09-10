#include "field_map_object_motion_internal.h"

void ov01_021F829C(void *owner, void *obj, const s8 *s, int i) {
    if (i != s[0]) {
        sub_02023EE0(obj, ov01_021FA458(i));
        sub_02023F40(obj, 0);
    } else if (s[2] != 9) {
        ov01_021F8C3C(obj, ov01_021FA458(i), 4);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, FX32_ONE);
    }
}
