#include "to47_overlay49_color_fade_private.h"

void ov49_022684FC(Ov49Fade *p) {
    int i;
    int changed;

    changed = 0;
    for (i = 0; i < 2; i++) {
        if (p->aTimer[i] + 1 <= 60) {
            p->aTimer[i]++;
            ov49_02268664(p->aFrom[i], p->aTo[i], p->a[i], p->aTimer[i], 60);
            changed = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (p->bTimer[i] + 1 <= 60) {
            p->bTimer[i]++;
            ov49_02268664(p->bFrom[i], p->bTo[i], p->b[i], p->bTimer[i], 60);
            changed = 1;
        }
    }
    if (changed) {
        ov49_022686F0(p);
    }
}

void ov49_02268588(Ov49Fade *p, int idx) {
    int i;
    const u16 *src;

    p->aFrom[0][0] = p->a[0][0];
    p->aFrom[0][1] = p->a[0][1];
    p->aFrom[0][2] = p->a[0][2];
    p->aFrom[0][3] = p->a[0][3];
    p->aTimer[0] = 0;
    src = ov49_0226A7E0[idx].c;
    ov49_02268640(p->aTo[0], src);
    for (i = 0; i < 4; i++) {
        p->bFrom[i][0] = p->b[i][0];
        p->bFrom[i][1] = p->b[i][1];
        p->bFrom[i][2] = p->b[i][2];
        p->bFrom[i][3] = p->b[i][3];
        p->bTimer[i] = 0;
        ov49_02268640(p->bTo[i], src + 1 + i);
    }
}

void ov49_022685F8(void *p, int idx) {
    U8(p, 0x1c) = U8(p, 4);
    U8(p, 0x1d) = U8(p, 5);
    U8(p, 0x1e) = U8(p, 6);
    U8(p, 0x1f) = U8(p, 7);
    U32(p, 0x4c) = 0;
    ov49_02268640((u8 *)p + 0x34, &ov49_0226A7D8[idx]);
}
