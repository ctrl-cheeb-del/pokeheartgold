#include "to42_overlay49_r73b_private.h"

#pragma require_prototypes off

void ov49_022682D4(Ov49Ctl *ctl, void *object) {
    VecFx32 v;
    int i;
    ov49_02259154(object, &v);
    v.x += 0x8000;
    v.y += 0x14000;
    v.z -= 0x8000;
    for (i = 0; i < ctl->count; i++) {
        ov49_022683FC(ctl, i, &v, 0xD000, 0x5000, 0x7000, 0xE000, 8);
    }
}
