#include "screen_fade_update_internal.h"

void sub_0200FF5C(FadeBlankPair *data, int index) {
    data->active[index] = 0;
    if (data->active[0] == 0 && data->active[1] == 0) {
        HBlankInterruptDisable();
    }
    data->funcs[index] = sub_02010014;
    data->values[index] = 0;
}

void sub_0200FF88(void *a0, u32 a1, u32 a2, u32 a3, enum HeapID heapId) {
    FadeSetTaskData *data = Heap_AllocAtEnd(heapId, sizeof(FadeSetTaskData));
    data->a0 = a0;
    data->a1 = a1;
    data->a2 = a2;
    data->a3 = a3;
    SysTask_CreateOnVWaitQueue(sub_0200FFD8, data, 0x400);
}

void sub_0200FFB4(FadeBlankPair *fade, int index, enum HeapID heapId) {
    FadeClearTaskData *data = Heap_AllocAtEnd(heapId, sizeof(FadeClearTaskData));
    data->data = fade;
    data->index = index;
    SysTask_CreateOnVWaitQueue(sub_0200FFF8, data, 0x400);
}

void sub_0200FFD8(SysTask *task, void *arg) {
    FadeSetTaskData *data = arg;
    sub_0200FEE4(data->a0, data->a1, data->a2, data->a3);
    SysTask_Destroy(task);
    Heap_Free(data);
}

void sub_0200FFF8(SysTask *task, void *arg) {
    FadeClearTaskData *data = arg;
    sub_0200FF5C(data->data, data->index);
    SysTask_Destroy(task);
    Heap_Free(data);
}

void sub_02010014(u32 value) {
}

u16 sub_02010018(u8 *data, u16 color) {
    if (color == 0xFFFF) {
        color = *(u16 *)(data + 0x150);
    }
    return color;
}

u16 sub_0201002C(u8 *data) {
    FadeParam *param;
    if (*(u32 *)(data + 0xC) == 1) {
        param = (FadeParam *)(data + 0x14);
    } else {
        param = (FadeParam *)(data + 0x44);
    }
    if (param->state == 1) {
        return param->color;
    }
    return *(u16 *)(data + 0x150);
}

void sub_02010050(SysTask *task, void *arg) {
    FadeParam *param = arg;
    SetMasterBrightness((PMLCDTarget)param->screen, 0);
    SysTask_Destroy(task);
}

void sub_02010064(FadeParam *param) {
    if (param->state == 0 && (param->color == 0x7FFF || param->color == 0) && param->task == NULL) {
        SysTask_CreateOnVWaitQueue(sub_02010050, param, 0x400);
    }
}

void sub_02010094(FadeParam *param) {
    if (param->state == 1 && (param->color == 0x7FFF || param->color == 0) && param->task == NULL) {
        sub_0200FBF4((PMLCDTarget)param->screen, param->color);
        ResetVisibleHardwareWindows((PMLCDTarget)param->screen);
    }
}
