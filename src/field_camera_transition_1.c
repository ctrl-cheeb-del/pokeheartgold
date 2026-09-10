#include "field_camera_transition_internal.h"
static inline void *LocalAvatar(LocalTeleportState *s) {
    return *(void **)((u8 *)s->fieldSystem + 0x40);
}
void ov01_021F3378(LocalTeleportState *s) {
    switch (s->facing) {
    case 0:
        s->facing = 2;
        break;
    case 2:
        s->facing = 1;
        break;
    case 1:
        s->facing = 3;
        break;
    case 3:
        s->facing = 0;
        break;
    }
    PlayerAvatar_SetFacingDirection(LocalAvatar(s), s->facing);
}

void ov01_021F33B8(void *task, LocalTeleportState *s) {
    VecFx32 pos;
    void *obj = PlayerAvatar_GetMapObject(LocalAvatar(s));
    switch (s->state) {
    case 0:
        s->state = 1;
        PlaySE(1614);
    case 1:
        break;
    default:
        return;
    }
    if (s->counter % 2 != 0) {
        ov01_021F3378(s);
    }
    sub_0205F990(obj, &pos);
    pos.y = (fx32)((double)s->counter * ((double)(s->counter << 11) + 9011.2));
    sub_0205F9A0(obj, &pos);
    s->counter++;
    if (s->counter == 20) {
        BeginNormalPaletteFade(2, 0, 0, 0, 6, 1, 4);
        return;
    }
    if (s->counter > 20 && IsPaletteFadeFinished()) {
        *s->done = 1;
        Heap_Free(s);
        SysTask_Destroy(task);
    }
}

void ov01_021F348C(void *task, LocalTeleportState *s) {
    VecFx32 pos;
    void *obj = PlayerAvatar_GetMapObject(LocalAvatar(s));
    int n;
    switch (s->state) {
    case 0:
        MapObject_UnpauseMovement(obj);
        sub_0205F990(obj, &pos);
        n = 20 - s->counter;
        pos.y = (fx32)((double)n * ((double)(n << 11) + 9011.2));
        sub_0205F9A0(obj, &pos);
        ov01_021F92A0(obj);
        PlaySE(1614);
        s->state = 1;
    case 1:
        if (s->counter % 2 != 0) {
            ov01_021F3378(s);
        }
        sub_0205F990(obj, &pos);
        n = 20 - s->counter;
        pos.y = (fx32)((double)n * ((double)(n << 11) + 9011.2));
        sub_0205F9A0(obj, &pos);
        s->counter++;
        if (s->counter == 2) {
            BeginNormalPaletteFade(1, 1, 1, 0, 6, 1, 4);
        }
        if (s->counter > 20) {
            s->state = 2;
            return;
        }
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            PlayerAvatar_SetFacingDirection(LocalAvatar(s), 1);
            *s->done = 1;
            Heap_Free(s);
            SysTask_Destroy(task);
        }
        break;
    default:
        return;
    }
}

void ov01_021F35C4(void *fieldSystem, BOOL exit, int *done) {
    LocalTeleportState *s = Heap_AllocAtEnd(4, sizeof(LocalTeleportState));
    MI_CpuFill8(s, 0, sizeof(LocalTeleportState));
    s->fieldSystem = fieldSystem;
    s->done = done;
    s->facing = PlayerAvatar_GetFacingDirection(*(void **)((u8 *)fieldSystem + 0x40));
    if (exit) {
        SysTask_CreateOnMainQueue((void (*)(void *, void *))ov01_021F33B8, s, 0x64);
    } else {
        SysTask_CreateOnMainQueue((void (*)(void *, void *))ov01_021F348C, s, 0x64);
    }
}
