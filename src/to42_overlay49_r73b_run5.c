#include "to42_overlay49_r73b_private.h"

#pragma require_prototypes off

void ov49_022683FC(Ov49Ctl *ctl, u32 index, VecFx32 *v, fx32 a, fx32 b, fx32 c, u32 d, u32 kind) {
    fx32 x;
    fx32 y;
    fx32 z;
    switch (index) {
    case 0:
        x = v->x - a;
        y = v->y + b;
        z = v->z;
        break;
    case 1:
        x = v->x + a;
        y = v->y + b;
        z = v->z;
        break;
    case 2:
        x = v->x - c;
        y = v->y + d;
        z = v->z;
        break;
    case 3:
        x = v->x + c;
        y = v->y + d;
        z = v->z;
        break;
    }
    ov49_0226540C(&ctl->emitters[index], v->x, x, v->y, y, v->z, z, kind);
    sub_020182A8(ctl->objects[index], v->x, v->y, v->z);
}

void *ov49_02268490(u32 heapId, u32 a, u32 b) {
    Ov49Allocated *p = Heap_Alloc(heapId, sizeof(Ov49Allocated));
    int i;
    memset(p, 0, sizeof(Ov49Allocated));
    ov49_022686C0(p, &ov49_0226A7E0[a * 10]);
    ov49_022686E4(p, &ov49_0226A7D8[b]);
    for (i = 0; i < 2; i++) {
        p->values48[i] = 60;
    }
    for (i = 0; i < 4; i++) {
        p->values50[i] = 60;
    }
    ov49_022686F0(p);
    return p;
}
