#include "overlay89_r8_private.h"

void ov89_0225A5A4(Ov89Work *work) {
    int i;

    for (i = 0; i < 128; i++) {
        Ov89Object *object = work->objects[i];
        if (object != NULL) {
            u32 kind = (object->packed << 16) >> 24;
            if (ov89_0225CDB0[kind].tick != NULL) {
                ov89_0225CDB0[kind].tick(work, object);
            } else {
                sub_020181EC(&object->instance);
            }
        }
    }
}
