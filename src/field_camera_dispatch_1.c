#include "field_camera_dispatch_internal.h"
typedef void (*LocalCallback)(LocalCameraTask *);
extern const LocalCallback ov01_02208E0C[];
void ov01_021FCD2C(void *fieldSystem, int heapId) {
    LocalCameraTask *s = Heap_AllocAtEnd(heapId, sizeof(LocalCameraTask));
    memset(s, 0, sizeof(LocalCameraTask));
    s->heapId = heapId;
    s->mode = 0;
    s->fieldSystem = fieldSystem;
    s->camera = *(void **)((u8 *)fieldSystem + 0x24);
    s->initial = Camera_GetDistance(s->camera);
    s->current = s->initial;
    SysTask_CreateOnMainQueue((void (*)(void *, void *))ov01_021FCDA8, s, 0xffff);
}
BOOL ov01_021FCD6C(void *task) {
    return ((LocalCameraTask *)SysTask_GetData(task))->done;
}
void ov01_021FCD78(void *task) {
    Heap_Free(SysTask_GetData(task));
    SysTask_Destroy(task);
}
void ov01_021FCD8C(void *task, int mode, fx32 amount, u32 duration) {
    LocalCameraTask *s = SysTask_GetData(task);
    s->state = 0;
    s->done = 0;
    s->mode = mode;
    s->amount = amount;
    s->duration = duration;
    s->elapsed = 0;
}
void ov01_021FCDA8(void *task, LocalCameraTask *s) {
    ov01_02208E0C[s->mode](s);
}
void ov01_021FCDBC(LocalCameraTask *s) {
    s->done = 1;
}
void ov01_021FCDC4(LocalCameraTask *s) {
    switch (s->state) {
    case 0:
        ov01_021FCE44(s);
        s->state++;
    case 1:
        if (ov01_021FCE74(s) == TRUE) {
            s->state++;
            s->done = 1;
        }
        break;
    default:
        return;
    }
    ov01_021FCE34(s);
}
void ov01_021FCDFC(LocalCameraTask *s) {
    switch (s->state) {
    case 0:
        ov01_021FCE5C(s);
        s->state++;
    case 1:
        if (ov01_021FCE74(s) == TRUE) {
            s->state++;
            s->done = 1;
        }
        break;
    default:
        return;
    }
    ov01_021FCE34(s);
}
void ov01_021FCE34(LocalCameraTask *s) {
    Camera_SetDistance(s->current, s->camera);
}
void ov01_021FCE44(LocalCameraTask *s) {
    s->step = s->amount / (s32)s->duration;
    s->target = s->current + s->amount;
}
void ov01_021FCE5C(LocalCameraTask *s) {
    s->step = (s->initial - s->current) / (s32)s->duration;
    s->target = s->initial;
}
BOOL ov01_021FCE74(LocalCameraTask *s) {
    s->current += s->step;
    s->elapsed++;
    if (s->elapsed >= s->duration) {
        s->elapsed = s->duration;
        s->current = s->target;
        return TRUE;
    }
    return FALSE;
}
