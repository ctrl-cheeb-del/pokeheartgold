#include "overlay116_scene_internal.h"

const Ov116Sequence ov116_0225F398 = { 0x28, 5, 8, 0x3C, 0x100, -0x226000, 0x800, 5, 13 };
static const Ov116Sequence sSequenceA = { 0x28, 5, 8, 0x3C, 0x100, -0x294000, 0x800, 5, 13 };

static const Ov116CameraKey sPanKeys[] = {
    { 0x29AEC1, 0xD602, 0,      0x05C1, 4 },
    { 0x29AEC1, 0xCF02, 0xFF00, 0x0601, 4 },
    { 0x29AEC1, 0xE602, 0x1000, 0x0691, 4 },
    { 0x29AEC1, 0xD602, 0x0A00, 0x0711, 3 },
    { 0x29AEC1, 0xE102, 0xF000, 0x0780, 3 },
    { 0x29AEC1, 0xC602, 0,      0x0751, 3 },
    { 0x29AEC1, 0xE002, 0xF000, 0x0800, 3 },
    { 0x29AEC1, 0xD602, 0,      0x0802, 3 },
    { 0x29AEC1, 0xD002, 0x1000, 0x0800, 3 },
    { 0x29AEC1, 0xD902, 0xF500, 0x0751, 3 },
    { 0x29AEC1, 0xD002, 0x0A00, 0x04C1, 2 },
    { 0x29AEC1, 0xE002, 0xF000, 0x03C1, 2 },
    { 0x29AEC1, 0xD002, 0xF000, 0x0650, 1 },
    { 0x29AEC1, 0xE002, 0xA000, 0x0241, 1 },
    { 0x29AEC1, 0xE1A2, 0x0500, 0x0500, 1 },
    { 0x29AEC1, 0xD602, 0,      0x0241, 1 },
};

void ov116_0225F020(Ov116FieldSystem *fieldSystem, const Ov116CameraKey *key) {
    Ov116CameraAngle angle;
    Camera_SetPerspectiveAngle(key->perspective, fieldSystem->camera);
    Camera_SetDistance(key->distance, fieldSystem->camera);
    angle.x = key->angleX;
    angle.y = key->angleY;
    angle.z = 0;
    Camera_SetAnglePos(&angle, fieldSystem->camera);
}

void ov116_0225F054(void *arg0, Ov116Task *task) {
    Ov116PanWork *work = task->work;
    switch (task->state) {
    case 0:
        task->work = Heap_Alloc(4, sizeof(Ov116PanWork));
        memset(task->work, 0, sizeof(Ov116PanWork));
        GfGfx_EngineATogglePlanes(2, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(8, 0);
        task->state++;
        break;
    case 1:
        ov01_021EFCF8(1, 0x10, 0x10, &task->done, 1);
        task->state++;
        break;
    case 2:
        if (task->done != 0) {
            task->state++;
        }
        break;
    case 3:
        work->effect = (void *)ov01_021F467C(3, 0xF);
        work->index = 0;
        work->delay = sPanKeys[work->index].delay;
        task->state++;
        break;
    case 4:
        if (--work->delay < 0) {
            ov116_0225F020(task->fieldSystem, &sPanKeys[work->index]);
            work->index++;
            if (work->index >= 16) {
                task->state++;
            } else {
                work->delay = sPanKeys[work->index].delay;
            }
        }
        break;
    case 5:
        BeginNormalPaletteFade(3, 0, 0, 0x7FFF, 10, 1, 4);
        task->state++;
        break;
    case 6:
        if (IsPaletteFadeFinished()) {
            task->done = 0;
            task->state++;
        }
        break;
    case 7:
        sub_0200FBF4(1, 0x7FFF);
        ov01_021F46DC(work);
        *(vu16 *)0x04000050 = 0;
        if (task->completionFlag != NULL) {
            *task->completionFlag = 1;
        }
        ov01_021EFCDC(task, arg0);
        sub_0200FBF4(1, 0x7FFF);
        break;
    }
}

void ov116_0225F1BC(void *arg0, Ov116Task *task, const Ov116Sequence *seq) {
    Ov116MoveWork *work = task->work;
    int done;
    switch (task->state) {
    case 0:
        task->work = Heap_Alloc(4, sizeof(Ov116MoveWork));
        memset(task->work, 0, sizeof(Ov116MoveWork));
        GfGfx_EngineATogglePlanes(2, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(8, 0);
        task->state++;
        break;
    case 1:
        ov01_021EFCF8(1, 0x10, 0x10, &task->done, 1);
        task->state++;
        break;
    case 2:
        if (task->done != 0) {
            task->state++;
        }
        break;
    case 3: {
        s32 start;
        work->effect = (void *)ov01_021F467C(seq->angleX, seq->angleY);
        start = Camera_GetPerspectiveAngle(task->fieldSystem->camera);
        ov01_021EFE34(&work->perspectiveInterp[0], start, start + seq->perspectiveDelta, seq->unk00);
        task->state++;
        break;
    }
    case 4:
        done = ov01_021EFE44(&work->perspectiveInterp[0]);
        Camera_SetPerspectiveAngle((u16)work->perspectiveInterp[0], task->fieldSystem->camera);
        if (done == 1) {
            task->state++;
            work->delay = seq->delay;
        }
        break;
    case 5: {
        s32 start;
        if (--work->delay < 0) {
            start = Camera_GetDistance(task->fieldSystem->camera);
            ov01_021EFEC8(&work->distanceInterp[0], start, start + seq->distanceDelta, seq->distanceDuration, seq->duration);
            task->state++;
        }
        break;
    }
    case 6:
        done = ov01_021EFF28(&work->distanceInterp[0]);
        Camera_SetDistance(work->distanceInterp[0], task->fieldSystem->camera);
        if (done == 1) {
            task->state++;
        }
        break;
    case 7:
        BeginNormalPaletteFade(3, 0, 0, 0x7FFF, seq->fadeFrames, 1, 4);
        task->state++;
        break;
    case 8:
        if (IsPaletteFadeFinished()) {
            task->done = 0;
            task->state++;
        }
        break;
    case 9:
        sub_0200FBF4(1, 0x7FFF);
        ov01_021F46DC(work);
        *(vu16 *)0x04000050 = 0;
        if (task->completionFlag != NULL) {
            *task->completionFlag = 1;
        }
        ov01_021EFCDC(task, arg0);
        sub_0200FBF4(1, 0x7FFF);
        break;
    }
}

void ov116_0225F364(void *arg0, Ov116Task *task) {
    ov116_0225F1BC(arg0, task, &sSequenceA);
}

void ov116_0225F374(void *arg0, Ov116Task *task) {
    ov116_0225F1BC(arg0, task, &ov116_0225F398);
}
