#include "overlay96_record_ui_private.h"

void ov96_0220BD38(R22Scene *p) {
    u32 a0;
    u32 a1;
    WSlot *sl;
    void *spr;
    s32 i;
    s32 n;
    if (p->f40.b.h == 3) {
        return;
    }
    for (i = 0, sl = p->slot; i < 3; i++, sl++) {
        if (i == p->f40.b.g) {
            a0 = 0x1a;
            a1 = 0x18;
            spr = p->spr[2];
            p->f44.b.f = 0;
        } else {
            n = p->f40.b.g + 1;
            if (n >= 3) {
                n = 0;
            }
            spr = SPRC(p, n == i);
            a1 = 0x11;
        }
        if (sl->b.k == 0) {
            ManagedSprite_SetAnimNoRestart(spr, a0);
            if (!ManagedSprite_GetDrawFlag(spr)) {
                ManagedSprite_SetDrawFlag(spr, 1);
            }
            if (!IsSEPlaying(0x890)) {
                PlaySE(0x890);
            }
        } else if (ov96_0220C768(spr, sl->b.k << 12, sl->b.w << 12)) {
            ManagedSprite_SetAnimNoRestart(spr, a1);
            ManagedSprite_SetDrawFlag(spr, 1);
            if (i == p->f40.b.g) {
                p->f44.b.f = 1;
            }
        } else {
            ManagedSprite_SetDrawFlag(spr, 0);
            ManagedSprite_SetAnimSpeed(spr, 0x1000);
        }
    }
}
