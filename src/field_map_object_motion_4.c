#include "field_map_object_motion_internal.h"

void ov01_021F796C(void *u, void *obj, const s8 *s, int i) {
    if (i != s[2]) {
        sub_02023EE0(obj, ov01_021FA44C(i));
        sub_02023F40(obj, 0);
    } else {
        ov01_021F8C30(obj);
    }
    sub_02023F04(obj, 0);
}

void ov01_021F79A0(void *owner, void *obj, const s8 *s, int i) {
    if (i != s[2]) {
        sub_02023EE0(obj, ov01_021FA44C(i));
        sub_02023F40(obj, 0);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, 2 << 10);
    }
}

void ov01_021F79DC(void *owner, void *obj, const s8 *s, int i) {
    if (i != s[2]) {
        sub_02023EE0(obj, ov01_021FA44C(i));
        sub_02023F40(obj, 0);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, FX32_ONE);
    }
}

void ov01_021F7A18(void *owner, void *obj, const s8 *s, int i) {
    if (i != s[2]) {
        sub_02023EE0(obj, ov01_021FA44C(i));
        sub_02023F40(obj, 0);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, 2 * FX32_ONE);
    }
}

void ov01_021F7A54(void *owner, void *obj, const s8 *s, int i) {
    if (i != s[2]) {
        sub_02023EE0(obj, ov01_021FA44C(i));
        sub_02023F40(obj, 0);
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, 4 * FX32_ONE);
    }
}
