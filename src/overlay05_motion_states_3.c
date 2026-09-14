#include "overlay05_motion_states_3_internal.h"

int ov05_0221C050(Ov05WorkR3 *work) {
    if (Bg_GetXpos(work->bgConfig, 3) <= 0x18) {
        work->frame = 0;
        work->x = 0;
        work->y = 0;
        ScheduleSetBgPosText(work->bgConfig, 3, 0, 0x18);
        ScheduleSetBgPosText(work->bgConfig, 2, 0, -0x18);
        ov05_0221D3AC(work, 0, 0, 0);
        ov05_0221D3AC(work, 1, 0, 0);
        ov05_0221D3AC(work, 2, 0, 0);
        ov05_0221D3AC(work, 3, 0, 0);
        ov05_0221D664(work, 0, 0, 0);
        ov05_0221D664(work, 1, 0, 0);
        ov05_0221D664(work, 2, 0, 0);
        ov05_0221D664(work, 3, 0, 0);
        return 1;
    }

    ScheduleSetBgPosText(work->bgConfig, 3, 2, work->step);
    ScheduleSetBgPosText(work->bgConfig, 2, 1, work->step);
    work->frame++;
    ov05_0221D3AC(work, 0, (s16)(work->step * work->frame - 0x100), 0);
    ov05_0221D3AC(work, 1, (s16)(work->step * work->frame - 0x100), 0);
    ov05_0221D3AC(work, 2, (s16)(0x100 - work->step * work->frame), 0);
    ov05_0221D3AC(work, 3, (s16)(0x100 - work->step * work->frame), 0);
    ov05_0221D664(work, 0, (s16)(work->step * work->frame - 0x100), 0);
    ov05_0221D664(work, 1, (s16)(work->step * work->frame - 0x100), 0);
    ov05_0221D664(work, 2, (s16)(0x100 - work->step * work->frame), 0);
    ov05_0221D664(work, 3, (s16)(0x100 - work->step * work->frame), 0);
    return 0;
}

int ov05_0221C21C(Ov05WorkR3 *work) {
    s16 dx;
    s16 dy;

    if (ov05_0221DAE0(work) == 0 && work->frame > 0x18) {
        work->frame = 0;
        return 1;
    }
    if (work->frame == 0) {
        if (work->root->direction == 1) {
            PlaySE(0x715);
        } else {
            PlaySE(0x852);
        }
    }
    if (work->frame == 0x18) {
        ScheduleSetBgPosText(work->bgConfig, 3, 0, 0x18);
        ScheduleSetBgPosText(work->bgConfig, 2, 0, -0x18);
        ScheduleSetBgPosText(work->bgConfig, 3, 3, 0);
        ScheduleSetBgPosText(work->bgConfig, 2, 3, 0);
        ov05_0221D3AC(work, 0, 0, 0);
        ov05_0221D3AC(work, 1, 0, 0);
        ov05_0221D3AC(work, 2, 0, 0);
        ov05_0221D3AC(work, 3, 0, 0);
        ov05_0221D664(work, 0, 0, 0);
        ov05_0221D664(work, 1, 0, 0);
        ov05_0221D664(work, 2, 0, 0);
        ov05_0221D664(work, 3, 0, 0);
    } else if (work->frame < 0x18) {
        dx = (s16)((s32)LCRandom() % work->rangeX - work->rangeX / 2);
        dy = (s16)((s32)LCRandom() % work->rangeY - work->rangeY / 2);
        if ((dx < 0 && work->x < 0) || (dx > 0 && work->x > 0)) {
            dx *= -1;
        }
        if ((dy < 0 && work->y < 0) || (dy > 0 && work->y > 0)) {
            dy *= -1;
        }
        ScheduleSetBgPosText(work->bgConfig, 3, 0, dx + 0x18);
        ScheduleSetBgPosText(work->bgConfig, 2, 0, dx - 0x18);
        ScheduleSetBgPosText(work->bgConfig, 3, 3, dy);
        ScheduleSetBgPosText(work->bgConfig, 2, 3, dy);
        ov05_0221D3AC(work, 0, dx, dy);
        ov05_0221D3AC(work, 1, dx, dy);
        ov05_0221D3AC(work, 2, dx, dy);
        ov05_0221D3AC(work, 3, dx, dy);
        ov05_0221D664(work, 0, dx, dy);
        ov05_0221D664(work, 1, dx, dy);
        ov05_0221D664(work, 2, dx, dy);
        ov05_0221D664(work, 3, dx, dy);
        work->x = dx;
        work->y = dy;
    }
    work->frame++;
    return 0;
}

int ov05_0221C430(Ov05WorkR3 *work) {
    if (work->frame == 8) {
        BeginNormalPaletteFade(0, 0, 0, 0x7fff, 6, 1, work->root->heapId);
    }
    if (work->frame >= 8 && IsPaletteFadeFinished() == 1) {
        work->state = 2;
        return 1;
    }
    if (work->frame == 0) {
        PlaySE(0x719);
    }
    ScheduleSetBgPosText(work->bgConfig, 3, 1, 0x10);
    ScheduleSetBgPosText(work->bgConfig, 2, 2, 0x10);
    work->frame++;
    ov05_0221D3AC(work, 0, (s16) - (work->frame << 4), 0);
    ov05_0221D3AC(work, 1, (s16) - (work->frame << 4), 0);
    ov05_0221D3AC(work, 2, (s16)(work->frame << 4), 0);
    ov05_0221D3AC(work, 3, (s16)(work->frame << 4), 0);
    ov05_0221D664(work, 0, (s16) - (work->frame << 4), 0);
    ov05_0221D664(work, 1, (s16) - (work->frame << 4), 0);
    ov05_0221D664(work, 2, (s16)(work->frame << 4), 0);
    ov05_0221D664(work, 3, (s16)(work->frame << 4), 0);
    return 0;
}
