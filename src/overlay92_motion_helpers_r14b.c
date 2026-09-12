#include "overlay92_motion_helpers_r14b_private.h"
BOOL ov92_02261E88(Ov92Motion *p, s32 duration, s32 xdir, s32 ydir) {
    fx32 x, y;
    BOOL done;
    switch (p->state) {
    case 0:
        ManagedSprite_GetPositionFxXYWithSubscreenOffset(p->sprite, &x, &y, 1 << 20);
        if (xdir == 0) {
            ov92_02260860(p->tweenX, x, x - 0xb4000, ov92_022619C4(duration));
        } else {
            ov92_02260860(p->tweenX, x, x + 0xb4000, ov92_022619C4(duration));
        }
        if (ydir == 2) {
            ov92_02260860(p->tweenY, y, y - 0x18000, ov92_022619C4(duration));
        } else {
            ov92_02260860(p->tweenY, y, y + 0x18000, ov92_022619C4(duration));
        }
        p->state++;
    case 1:
        done = ov92_02260870(p->tweenX);
        ov92_02260870(p->tweenY);
        ManagedSprite_SetPositionFxXYWithSubscreenOffset(p->sprite, *(fx32 *)p->tweenX, *(fx32 *)p->tweenY, 1 << 20);
        if (done) {
            return TRUE;
        }
        break;
    default:
        return TRUE;
    }
    return FALSE;
}
BOOL ov92_02261F60(Ov92Motion *p, s32 duration, s32 xdir, s32 ydir) {
    BOOL done;
    switch (p->state) {
    case 0:
        if (xdir == 0) {
            ov92_02260860(p->tweenX, 0x134000, 0x80000, ov92_022619C4(duration));
        } else {
            ov92_02260860(p->tweenX, -0x3e000, 0x80000, ov92_022619C4(duration));
        }
        if (ydir == 2) {
            ov92_02260860(p->tweenY, 0xa0000, 0x88000, ov92_022619C4(duration));
        } else {
            ov92_02260860(p->tweenY, 0xa0000, 0xb8000, ov92_022619C4(duration));
        }
        p->state++;
    case 1:
        done = ov92_02260870(p->tweenX);
        ov92_02260870(p->tweenY);
        ManagedSprite_SetPositionFxXYWithSubscreenOffset(p->sprite, *(fx32 *)p->tweenX, *(fx32 *)p->tweenY, 1 << 20);
        if (done) {
            return TRUE;
        }
        break;
    default:
        return TRUE;
    }
    return FALSE;
}
BOOL ov92_02262018(Ov92Motion *p, s32 duration, s32 xdir, s32 ydir) {
    BOOL done;
    switch (p->state) {
    case 0:
        if (xdir == 0) {
            ov92_02260860(p->tweenX, 0x134000, 0x80000, ov92_022619C4(duration));
        } else {
            ov92_02260860(p->tweenX, -0x3e000, 0x80000, ov92_022619C4(duration));
        }
        if (ydir == 2) {
            ov92_02260860(p->tweenY, 0x60000, 0x48000, ov92_022619C4(duration));
        } else {
            ov92_02260860(p->tweenY, 0x60000, 0x78000, ov92_022619C4(duration));
        }
        p->state++;
    case 1:
        done = ov92_02260870(p->tweenX);
        ov92_02260870(p->tweenY);
        ManagedSprite_SetPositionFxXYWithSubscreenOffset(p->sprite, *(fx32 *)p->tweenX, *(fx32 *)p->tweenY, 1 << 20);
        if (done) {
            return TRUE;
        }
        break;
    default:
        return TRUE;
    }
    return FALSE;
}
BOOL ov92_022620D0(Ov92Motion *p, s32 speed, s32 xdir, s32 cycles) {
    fx32 oldX, oldY;
    fx32 x, y;
    switch (p->state) {
    case 0:
        p->cycles = 0;
        p->angle = 0;
        p->state++;
    case 1:
        p->angle += 360 / ov92_022619C4(speed);
        if (p->angle >= 360) {
            p->angle = 0;
        }
        ManagedSprite_GetPositionFxXYWithSubscreenOffset(p->sprite, &oldX, &oldY, 1 << 20);
        if (xdir == 0) {
            x = (p->baseX << 12) - GF_SinDeg(p->angle) * p->radiusX;
            y = (p->baseY << 12) - GF_CosDeg(p->angle) * p->radiusY;
        } else {
            x = (p->baseX << 12) + GF_SinDeg(p->angle) * p->radiusX;
            y = (p->baseY << 12) - GF_CosDeg(p->angle) * p->radiusY;
        }
        ManagedSprite_SetPositionFxXYWithSubscreenOffset(p->sprite, x, y, 1 << 20);
        if (p->angle == 0) {
            p->cycles++;
            if (p->cycles >= cycles) {
                p->state++;
                return TRUE;
            }
            p->state = 1;
        }
        break;
    default:
        return TRUE;
    }
    return FALSE;
}
