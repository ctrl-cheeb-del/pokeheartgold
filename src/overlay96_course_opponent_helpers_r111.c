#include "overlay96_course_opponent_logic_r111_private.h"
#include "unk_02009D48.h"

extern void GF_AssertFail(void);
extern void *SpriteSystem_GetRenderer(void *spriteSystem);

int ov96_02215614(int x, int y, int otherX, int otherY) {
    if (otherX < x && otherY < y) {
        return 0;
    }
    if (otherX >= x && otherY < y) {
        return 1;
    }
    if (otherX < x && otherY >= y) {
        return 2;
    }
    if (otherX >= x && otherY >= y) {
        return 3;
    }
    GF_AssertFail();
    return 4;
}

BOOL ov96_02215650(int x1, int y1, int x2, int y2, u8 quadrant, u8 otherQuadrant) {
    int result = ov96_02215614(x1, y1, x2, y2);
    u8 target;

    if (otherQuadrant != quadrant) {
        target = 3 - quadrant;
    } else {
        target = otherQuadrant;
    }
    return result == target;
}

BOOL ov96_0221567C(int x1, int y1, int x2, int y2, u8 quadrant, u8 otherQuadrant) {
    int result = ov96_02215614(x1, y1, x2, y2);

    if (otherQuadrant == quadrant) {
        return (3 - otherQuadrant) != result;
    }
    return FALSE;
}

BOOL ov96_022156A8(int x, int y, const u16 (*points)[2]) {
    u8 i;

    for (i = 0; i < 3; i++) {
        int dx = x - points[i][0];
        int dy = y - points[i][1];

        if (dx >= -8 && dx <= 8 && dy >= -8 && dy <= 8) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov96_022156E8(const VecFx32 *arg0, fx32 radius, const VecFx32 *arg2, fx32 extra) {
    VecFx32 delta;

    VEC_Subtract(arg0, arg2, &delta);
    return VEC_Mag(&delta) < radius + extra;
}

void ov96_02215710(SysTask *task, Ov96OpponentBgWork *work) {
    int sign;
    int lower;
    int upper;

    if (work->direction == 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    upper = (work->offset >> 12) * sign;
    lower = upper / 2;
    switch (work->frame % 3) {
    case 0:
        lower *= -1;
        break;
    case 1:
        lower = 0;
        break;
    case 2:
        break;
    default:
        GF_AssertFail();
        break;
    }

    ScheduleSetBgPosText(work->bgConfig, 0, BG_POS_OP_SET_X, lower);
    ScheduleSetBgPosText(work->bgConfig, 1, BG_POS_OP_SET_X, lower);
    ScheduleSetBgPosText(work->bgConfig, 2, BG_POS_OP_SET_X, lower);
    ScheduleSetBgPosText(work->bgConfig, 3, BG_POS_OP_SET_X, lower);
    ScheduleSetBgPosText(work->bgConfig, 0, BG_POS_OP_SET_Y, upper);
    ScheduleSetBgPosText(work->bgConfig, 1, BG_POS_OP_SET_Y, upper);
    ScheduleSetBgPosText(work->bgConfig, 2, BG_POS_OP_SET_Y, upper);
    ScheduleSetBgPosText(work->bgConfig, 3, BG_POS_OP_SET_Y, upper);
    G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), lower << 12, upper << 12);

    work->offset -= work->step;
    work->direction ^= 1;
    work->frame++;
    if (work->frame >= work->duration) {
        ScheduleSetBgPosText(work->bgConfig, 0, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(work->bgConfig, 1, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(work->bgConfig, 2, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(work->bgConfig, 3, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(work->bgConfig, 0, BG_POS_OP_SET_Y, 0);
        ScheduleSetBgPosText(work->bgConfig, 1, BG_POS_OP_SET_Y, 0);
        ScheduleSetBgPosText(work->bgConfig, 2, BG_POS_OP_SET_Y, 0);
        ScheduleSetBgPosText(work->bgConfig, 3, BG_POS_OP_SET_Y, 0);
        G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, 0);
        work->task = NULL;
        SysTask_Destroy(task);
    }
}
