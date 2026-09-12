#include "global.h"

#include "overlay96_event_behavior_r14_private.h"

BOOL ov96_0221A3AC(R123Rec *r) {
    s32 roll = MTRandom() % 100;
    s32 chance = 0;
    u32 v = ov96_02215E68(r->ctx, (u8)r->bits.index);
    if (v < 10) {
        chance = 100;
    } else if (v < 20) {
        chance = 70;
    } else if (v < 30) {
        chance = 50;
    } else if (v < 40) {
        chance = 30;
    } else if (v < 50) {
        chance = 10;
    }
    return roll < chance;
}
