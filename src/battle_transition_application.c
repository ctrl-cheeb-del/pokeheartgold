#include "battle_transition_application_internal.h"

void *sub_02087A78(OverlayManager *manager) {
    return ((void **)OverlayManager_GetArgs(manager))[5];
}

void sub_02087A84(Pair87 *pair, u32 first, u32 second) {
    pair->first = first;
    pair->second = second;
}

void sub_02087A8C(OverlayManager *manager, u32 mode) {
    Unk87Work *work;
    u8 *large;
    void *args;
    void *value;
    u32 index;

    Heap_Create((enum HeapID)3, (enum HeapID)0x7E, 0x10000);
    work = OverlayManager_CreateAndGetData(manager, sizeof(Unk87Work), (enum HeapID)0x7E);
    MI_CpuFill8(work, 0, sizeof(Unk87Work));
    args = OverlayManager_GetArgs(manager);
    work->args = args;
    work->saveData = ((void **)args)[3];
    work->large = Heap_Alloc((enum HeapID)0x7E, 0x4170);
    MI_CpuFill8(work->large, 0, 0x4170);
    *(void **)(work->large + 0x868) = &work->result;
    *(void **)(work->large + 0x830) = work->saveData;
    *(u32 *)work->large = mode;
    large = work->large;
    value = sub_02087FF8(large, *(u32 *)large);
    index = *(u32 *)(large + 0x6D8);
    *(void **)(large + 0x81C + index * 4) = value;
}

BOOL sub_02087B10(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 0);
    return TRUE;
}

BOOL sub_02087B1C(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 1);
    return TRUE;
}

BOOL sub_02087B28(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 2);
    return TRUE;
}

BOOL sub_02087B34(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 3);
    return TRUE;
}

BOOL sub_02087B40(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 4);
    return TRUE;
}

BOOL sub_02087B4C(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 5);
    return TRUE;
}

BOOL sub_02087B58(OverlayManager *manager, int *state) {
    sub_02087A8C(manager, 6);
    return TRUE;
}

BOOL sub_02087B64(OverlayManager *manager, int *state) {
    Unk87Work *work = OverlayManager_GetData(manager);
    switch (*state) {
    case 0:
        if (sub_02087BE8(work, (enum HeapID)0x7E)) {
            if (work->result == 1) {
                *state = 1;
                work->state = 0;
            } else {
                return TRUE;
            }
        }
        break;
    case 1:
        if (sub_02087C38(work, (enum HeapID)0x7E)) {
            *state = 0;
            work->state = 0;
        }
        break;
    }
    return FALSE;
}

BOOL sub_02087BAC(OverlayManager *manager, int *state) {
    Unk87Work *work = OverlayManager_GetData(manager);
    if (sub_0202FC48() == TRUE) {
        sub_0202FC24();
    }
    Heap_Free(work->large);
    OverlayManager_FreeData(manager);
    GF_SndHandleSetPlayerVolume(1, 0x7F);
    GF_SndHandleSetPlayerVolume(7, 0x7F);
    Heap_Destroy((enum HeapID)0x7E);
    return TRUE;
}

BOOL sub_02087BE8(Unk87Work *work, enum HeapID heapId) {
    if (work->state == 0) {
        if (*(u32 *)work->large == 0) {
            work->manager = OverlayManager_New(&_021028B4, work, heapId);
        } else {
            work->manager = OverlayManager_New(&_021028C4, work, heapId);
        }
        work->state++;
    } else if (OverlayManager_Run(work->manager)) {
        OverlayManager_Delete(work->manager);
        return TRUE;
    }
    return FALSE;
}
