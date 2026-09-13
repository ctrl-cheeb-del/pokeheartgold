#include "to42_overlay49_r73b_private.h"

#pragma require_prototypes off

void ov49_0226813C(Ov49Ctl *ctl, void *object) {
    VecFx32 v;
    fx32 x;
    fx32 y;
    fx32 z;
    int i;
    ov49_02259154(object, &v);
    v.x += 0x8000;
    v.y += 0x8000;
    v.z -= 0x8000;
    for (i = 0; i < ctl->count; i++) {
        switch (i) {
        case 0:
            x = v.x - 0x10000;
            y = v.y;
            z = v.z + 0x10000;
            break;
        case 1:
            x = v.x + 0x10000;
            y = v.y;
            z = v.z + 0x10000;
            break;
        case 2:
            if (ctl->count == 3) {
                x = v.x;
                y = v.y;
                z = v.z - 0x20000;
            } else {
                x = v.x - 0x10000;
                y = v.y;
                z = v.z - 0x10000;
            }
            break;
        case 3:
            x = v.x + 0x10000;
            y = v.y;
            z = v.z - 0x10000;
            break;
        }
        ov49_0226540C(&ctl->emitters[i], v.x, x, v.y, y, v.z, z, 19);
        ov49_022655F4(&ctl->motions[i], 0x1555, 0x71C, 0x20000);
    }
    ov49_02268230(ctl);
}
