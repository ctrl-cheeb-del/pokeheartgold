#include "overlay92_battle_sequence_r18_private.h"

void ov92_022616D8(void *data) {
    Ov92Work18 *work = data;
    s32 *base = work->paletteBase;
    s32 *blend = work->blend;
    BOOL done[5];
    int i;
    switch (work->animState) {
    case 0:
        ov92_02260860(&work->tweens[0], 0, 0x28000, 10);
        ov92_02260860(&work->tweens[1], 0, 0x50000, 10);
        ov92_02260860(&work->tweens[2], 0, -0x50000, 10);
        work->animState++;
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            done[i] = ov92_02260870(&work->tweens[i]);
        }
        ScheduleSetBgPosText(work->context->bgConfig, 7, 3, *(s32 *)&work->tweens[0] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 5, 0, *(s32 *)&work->tweens[1] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 6, 0, *(s32 *)&work->tweens[2] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 1, 0, *(s32 *)&work->tweens[1] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 2, 0, *(s32 *)&work->tweens[2] >> 12);
        if (done[0] && done[1] && done[2]) {
            work->animState++;
        }
        break;
    case 2:
        work->direction = 1;
        work->animState = 0;
        break;
    }
    if (*blend < 6) {
        (*blend)++;
    } else {
        *blend = 6;
    }
    PaletteData_BlendPalettes(work->context->paletteData, 0, 1, *base + *blend, 0);
    PaletteData_BlendPalettes(work->context->paletteData, 1, 1, *base + *blend, 0);
}

void ov92_02261850(void *data) {
    Ov92Work18 *work = data;
    s32 *base = work->paletteBase;
    s32 *blend = work->blend;
    BOOL done[5];
    int i;
    switch (work->animState) {
    case 0:
        ov92_02260860(&work->tweens[0], 0x28000, 0, 10);
        ov92_02260860(&work->tweens[1], 0x50000, 0, 10);
        ov92_02260860(&work->tweens[2], -0x50000, 0, 10);
        work->animState++;
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            done[i] = ov92_02260870(&work->tweens[i]);
        }
        ScheduleSetBgPosText(work->context->bgConfig, 7, 3, *(s32 *)&work->tweens[0] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 5, 0, *(s32 *)&work->tweens[1] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 6, 0, *(s32 *)&work->tweens[2] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 1, 0, *(s32 *)&work->tweens[1] >> 12);
        ScheduleSetBgPosText(work->context->bgConfig, 2, 0, *(s32 *)&work->tweens[2] >> 12);
        if (done[0] && done[1] && done[2]) {
            work->animState++;
        }
        break;
    case 2:
        work->direction = 0;
        work->animState = 0;
        break;
    }
    if (*blend > 4) {
        (*blend)--;
    } else {
        *blend = 0;
    }
    PaletteData_BlendPalettes(work->context->paletteData, 0, 1, *base + *blend, 0);
    PaletteData_BlendPalettes(work->context->paletteData, 1, 1, *base + *blend, 0);
}

int ov92_022619C4(int value) {
    switch (value) {
    case 1:
        return 0x1c;
    case 2:
        return 0xe;
    case 3:
        return 0xc;
    case 4:
        return 0xa;
    case 5:
        return 9;
    case 6:
        return 0x20;
    case 7:
        return 0xe;
    case 8:
        return 0xc;
    case 9:
        return 0xb;
    case 10:
        return 0xb;
    default:
        return 9;
    }
}
