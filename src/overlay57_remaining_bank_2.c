#include "overlay57_remaining_bank_internal.h"
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov57_0223B828(Work *w, u32 a, u32 b, u32 c) {
    if (b == 0xff) {
        U32AT(w, 0x3fc) = U32AT(w, 0x400);
    } else {
        U32AT(w, 0x3fc) = b;
    }
    U32AT(w, 0x3f4) = a;
    U32AT(w, 0x400) = c;
    U32AT(w, 0x404) = 0;
}

void ov57_0223B858(void *s, u32 v) {
    switch (v) {
    case 0:
        ManagedSprite_SetAnimationFrame(s, 1);
        break;
    case 2:
        ManagedSprite_SetAnimationFrame(s, 2);
        break;
    case 1:
    case 3:
        ManagedSprite_SetAnimationFrame(s, 0);
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void ov57_0223B890(void *o, s32 x, s32 y) {
    s32 a, b;
    if (o) {
        sub_02013794(o, &a, &b);
        sub_020136B4(o, a + x, b + y);
    }
}

void ov57_0223B8B8(void *task, TaskData *d) {
    switch (d->state) {
    case 3:
        ov57_0223B890(d->obj, 0, -1);
        ManagedSprite_SetAnimationFrame(d->sprite, 2);
        d->state++;
        break;
    case 6:
        ov57_0223B890(d->obj, 0, 2);
        ManagedSprite_SetAnimationFrame(d->sprite, 0);
        SysTask_Destroy(task);
        Heap_Free(d);
        break;
    default:
        d->state++;
        break;
    }
}
