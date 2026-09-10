#include "overlay_02_legendary_internal.h"

void ov02_022460AC(void *task, u32 value) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_022460CC(field, value);
    TaskManager_Call(task, ov02_022460FC, env);
}

void *ov02_022460CC(void *field, u32 value) {
    void *p = Heap_Alloc(4, 0x14);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0x14);
    *(void **)((u8 *)p + 4) = field;
    *(u16 *)((u8 *)p + 0x10) = value;
    *(u32 *)p = 4;
    return p;
}

int ov02_022460FC(void *task) {
    u8 *p = TaskManager_GetEnvironment(task);
    s32 pos[3];
    switch (*(u16 *)(p + 0xC)) {
    case 0:
        *(void **)(p + 8) = ov02_02245E04((void *)(ov02_02253264 + *(u16 *)(p + 0x10) * 12), *(u32 *)p);
        PlayerAvatar_CopyPositionVector(*(void **)((u8 *)*(void **)(p + 4) + 0x40), pos);
        Field3dObject_SetPosEx((u8 *)*(void **)(p + 8) + 0x10, pos[0], pos[1], pos[2]);
        PlaySE(*(u16 *)(ov02_02253264 + 8 + *(u16 *)(p + 0x10) * 12));
        (*(u16 *)(p + 0xC))++;
        break;
    case 1:
        if (ov02_02245FD0(*(void **)(p + 8))) {
            (*(u16 *)(p + 0xC))++;
        }
        break;
    case 2:
        ov02_02245E68(*(void **)(p + 8));
        Heap_Free(p);
        return 1;
    }
    return 0;
}

void ShowLegendaryWing(void *task, u32 value) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_022461AC(field, value);
    TaskManager_Call(task, ov02_022461DC, env);
}

void *ov02_022461AC(void *field, u32 value) {
    void *p = Heap_Alloc(4, 0x18);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0x18);
    *(void **)((u8 *)p + 4) = field;
    *((u8 *)p + 0x10) = value;
    *(u32 *)p = 4;
    return p;
}
