#include "overlay96_grid_logic_r56_private.h"

BOOL ov96_021F3A5C(Ov96R17Circle *circles, fx32 x, fx32 y) {
    VecFx32 point;
    VecFx32 delta;
    s32 i;

    point.x = x;
    point.y = y;
    point.z = 0;
    for (i = 0; i < 4; i++, circles++) {
        if (circles->radius <= 0) {
            break;
        }
        delta.x = circles->x << 12;
        delta.y = circles->y << 12;
        delta.z = 0;
        VEC_Subtract(&point, &delta, &delta);
        if (VEC_Mag(&delta) < circles->radius << 12) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov96_021F3AB0(void *work, u8 cell) {
    s32 i;
    for (i = 0; i < 4; i++, work = (u8 *)work + 4) {
        s32 value = R17_S32(work, 0x4A0);
        if (value == -1) {
            break;
        }
        if (cell == value) {
            return TRUE;
        }
    }
    return FALSE;
}

void ov96_021F3AD8(void *work, Ov96R17Circle *circles, s32 cell, s32 *x, s32 *y) {
    s32 i;
    for (i = 0; i < 4; i++, work = (u8 *)work + 4) {
        if (cell == R17_S32(work, 0x4A0)) {
            *x = circles[i].x;
            *y = circles[i].y;
            return;
        }
    }
}

BOOL ov96_021F3B04(s32 x, s32 y, s16 *cellX, s16 *cellY) {
    *cellX = (x - 16) / 32;
    *cellY = (y - 16) / 32;
    if (*cellX < 0 || *cellY < 0) {
        return FALSE;
    }
    return TRUE;
}
