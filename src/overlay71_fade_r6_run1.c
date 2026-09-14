#include "overlay71_fade_r6_private.h"
void ov71_02246F90(void *task, Ov71PlaneTask *work) {
    if (++work->counter >= work->current) {
        work->counter = 0;
        if (work->direction == 1) {
            if (work->index + 1 >= 15) {
                ov71_02246E84(work->system, work->index, work->index + 1, 0);
                ov71_02246F60(work->system, work->delay);
                return;
            }
            ov71_02246E84(work->system, work->index, work->index + 1, 0x7fff);
            work->index++;
            return;
        }
        if (work->index < 0) {
            ov71_02246E84(work->system, work->index, work->index + 1, 0);
            ov71_02246F60(work->system, work->delay);
            return;
        }
        ov71_02246E84(work->system, work->index + 1, work->index, 0x7fff);
        work->index--;
    }
}

Ov71FadeTask *ov71_02247000(void *bgConfig, s32 start, s32 target, s32 delta, s32 step, s32 bgId, int *finished) {
    Ov71FadeTask *work = Heap_Alloc(0x38, sizeof(Ov71FadeTask));
    *finished = 1;
    if (work != NULL) {
        work->bgConfig = bgConfig;
        work->current = start;
        work->target = target;
        work->delta = delta;
        work->step = step;
        work->direction = start < target ? 0 : 1;
        work->bgId = bgId;
        work->finished = finished;
        *finished = 0;
        work->task = SysTask_CreateOnVBlankQueue((void (*)(void *, void *))ov71_02247068, work, 0);
        if (work->task == NULL) {
            *finished = 1;
            Heap_Free(work);
        }
    }
    return work;
}

void ov71_02247068(void *task, Ov71FadeTask *work) {
    s32 amount = ((work->current * work->delta) >> 12) / 32;
    s32 current = work->current;
    switch (work->direction) {
    case 0: {
        s32 target = work->target;
        current += amount;
        if (current < target) {
            work->current = current;
        } else {
            work->current = target;
            *work->finished = 1;
        }
    } break;
    case 1: {
        s32 target = work->target;
        current -= amount;
        if (current > target) {
            work->current = current;
        } else {
            work->current = target;
            *work->finished = 1;
        }
    } break;
    }
    ov71_022470DC(work);
    if (*work->finished != 0) {
        ov71_02247424(work);
        SysTask_Destroy(task);
    } else {
        work->delta += work->step;
    }
}

void ov71_022470DC(Ov71FadeTask *work) {
    Ov71ScaleMatrix matrix;
    matrix.x = work->current;
    matrix.z0 = 0;
    matrix.z1 = 0;
    matrix.y = work->current;
    SetBgAffine(work->bgConfig, 2, &matrix, 0x80, _0224BBD4[work->bgId]);
    SetBgAffine(work->bgConfig, 6, &matrix, 0x80, _0224BBD4[work->bgId]);
}
