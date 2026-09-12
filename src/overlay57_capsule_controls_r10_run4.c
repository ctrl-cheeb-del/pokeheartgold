#include "overlay57_capsule_controls_r10_private.h"

int ov57_0223B45C(void *w) {
    int selection = ov57_0223B578(w);
    if (selection < 0) {
        return 1;
    }
    return ov57_0223B3A4(w, (u8)selection);
}

BOOL ov57_0223B478(int *selection) {
    u32 keys = U32(gSystem, 0x4c);
    if (keys & 0x10) {
        (*selection)++;
        *selection %= 12;
    } else if (keys & 0x20) {
        if (*selection > 0) {
            (*selection)--;
        } else {
            *selection = 11;
        }
    } else if (keys & 0x40) {
        if (*selection / 4 != 0) {
            *selection -= 4;
            *selection %= 12;
        } else {
            return FALSE;
        }
    } else if (keys & 0x80) {
        if (*selection / 4 != 2) {
            *selection += 4;
            *selection %= 12;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
    return TRUE;
}

void ov57_0223B504(void *w, int which, int copy) {
    struct {
        s16 y, x;
    } position;
    Ov57Residual10Work *work = w;
    int other = 0;
    if (which == 0) {
        other = 1;
    }
    ov57_02238DAC(work->values[which], &position.x, &position.y);
    ManagedSprite_SetPositionXY(work->sprites[which], position.x, position.y);
    if (copy == 1) {
        work->values[other] = work->values[which];
        ov57_02238DAC(work->values[other], &position.x, &position.y);
        ManagedSprite_SetPositionXY(work->sprites[other], position.x, position.y);
    }
}
