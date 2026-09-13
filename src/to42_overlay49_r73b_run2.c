#include "to42_overlay49_r73b_private.h"

#pragma require_prototypes off

void ov49_02267EBC(Ov49Ctl *ctl, void *a, void *b, void *c, void *d, void *arg, u32 kind) {
    GF_ASSERT(kind < 3);
    ctl->objects[0] = a;
    ctl->objects[1] = b;
    ctl->objects[2] = c;
    ctl->objects[3] = d;
    ctl->callbackArg = arg;
    ctl->kind = kind;
}

void ov49_02267EF8(Ov49Ctl *ctl, u32 count) {
    int i;
    for (i = 0; i < count; i++) {
        sub_020182A0(ctl->objects[i], 1);
    }
    ctl->state = 0;
    ctl->active = 1;
    ctl->count = count;
    ov49_0226A4CC[ctl->kind](ctl, (u32)ctl->callbackArg);
}

u32 ov49_02267F40(Ov49Ctl *ctl) {
    u32 result;
    int i;
    if (ctl->active == 0) {
        return 1;
    }
    result = ov49_0226A484[ctl->kind](ctl);
    ctl->state++;
    if (result == 1) {
        for (i = 0; i < ctl->count; i++) {
            sub_020182A0(ctl->objects[i], 0);
        }
        ctl->active = 0;
    }
    return result;
}
