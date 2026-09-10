#include "field_map_object_motion_internal.h"

void ov01_021F8400(void *owner, void *obj, const s8 *s, int i) {
    u32 value = ov01_021FA464(i);
    if (i != s[0] || s[2] != 0) {
        sub_02023EE0(obj, value);
        sub_02023F40(obj, 0);
    } else if (s[2] != 10) {
        sub_02023EE0(obj, value);
        sub_02023F40(obj, 0);
    } else if (sub_02023EF4(obj) != value) {
        sub_02023EE0(obj, value);
        sub_02023F40(obj, 0);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, 2 << 10);
    }
}

void ov01_021F847C(void *owner, void *obj, const s8 *s, int i) {
    u32 value = ov01_021FA464(i);
    if (i != s[0]) {
        sub_02023EE0(obj, value);
        sub_02023F40(obj, 0);
    } else if (s[2] != 11) {
        sub_02023EE0(obj, value);
        sub_02023F40(obj, 0);
    } else if (sub_02023EF4(obj) != value) {
        sub_02023EE0(obj, value);
        sub_02023F40(obj, 0);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, FX32_ONE);
    }
}
