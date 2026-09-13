#include "overlay40_pc_state_handlers_tail_35_private.h"

void ov40_0223D618(void *p) {
    Ov40PtTbl buf = ov40_02245948;
    int j;
    void *q;
    int idx;
    int i;
    j = 0;
    q = PTR(p, 0x860);
    idx = j;
    for (; j < 5; j++) {
        void *r = q;
        for (i = 0; i < 6; i++) {
            if (PTR(r, 0x51C) != NULL) {
                ManagedSprite_SetPositionXY(PTR(r, 0x51C), buf.e[idx + i].x, buf.e[idx + i].y);
            }
            r = (u8 *)r + 8;
        }
        q = (u8 *)q + 0x30;
        idx += 6;
    }
}
