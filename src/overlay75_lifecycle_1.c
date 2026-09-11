#include "overlay75_lifecycle_internal.h"

BOOL ov75_02246960(OverlayManager *manager) {
    Overlay75State *state;
    void **args;

    Heap_Create((enum HeapID)3, (enum HeapID)0x73, 0x28000);
    Heap_Create((enum HeapID)0, (enum HeapID)0x59, 0x570);
    state = OverlayManager_CreateAndGetData(manager, sizeof(Overlay75State), (enum HeapID)0x73);
    MI_CpuFill8(state, 0, sizeof(Overlay75State));
    args = OverlayManager_GetArgs(manager);
    state->saveData = args[2];
    state->options = Save_PlayerData_GetOptionsAddr(state->saveData);
    state->string110 = String_New(100, (enum HeapID)0x73);
    state->string114 = String_New(100, (enum HeapID)0x73);
    Sound_SetSceneAndPlayBGM(0x11, 0x47D, 1);
    state->selection = 0;
    return TRUE;
}

BOOL ov75_022469D8(OverlayManager *manager, int *step) {
    Overlay75State *state = OverlayManager_GetData(manager);
    void *args;

    if (state->onlineLoaded == 1) {
        ov00_021ECB40();
        ov70_022378DC();
        sub_0203A930(3 - ov00_021EC9D4());
    }

    switch (*step) {
    case 0:
        ov75_02246B48(state);
        *step = 1;
        break;
    case 1:
        if (sub_02034DB8()) {
            _02249BE0 = state->expHeap;
            ov00_021EC294(ov75_02246BF0, ov75_02246C18);
            state->onlineLoaded = 1;
            *step = 2;
        }
        break;
    case 2:
        args = ov75_02249904[state->selection].createArgs(state);
        state->child = OverlayManager_New(ov75_02249904[state->selection].template, args, (enum HeapID)0x73);
        state->previousSelection = state->selection;
        state->selection = 6;
        *step = 3;
        break;
    case 3:
        if (OverlayManager_Run(state->child) == TRUE) {
            ov75_02249904[state->previousSelection].destroyArgs(state);
            OverlayManager_Delete(state->child);
            if (state->selection == 6) {
                *step = 4;
            } else if (ov75_02249904[state->selection].unloadOnline == 1) {
                ov75_02246B98(state);
                *step = 2;
            } else if (state->onlineLoaded == 1) {
                *step = 2;
            } else {
                *step = 0;
            }
        }
        break;
    case 4:
        return TRUE;
    }
    return FALSE;
}

BOOL ov75_02246B00(OverlayManager *manager) {
    Overlay75State *state = OverlayManager_GetData(manager);

    ov75_02246B98(state);
    String_Delete(state->string114);
    String_Delete(state->string110);
    OverlayManager_FreeData(manager);
    Heap_Destroy((enum HeapID)0x73);
    Heap_Destroy((enum HeapID)0x59);
    RegisterMainOverlay(FS_OVERLAY_ID(intro_title), &gApplication_TitleScreen);
    return TRUE;
}

void ov75_02246B48(Overlay75State *state) {
    if (state->onlineLoaded == 0) {
        HandleLoadOverlay(FS_OVERLAY_ID(OVY_70), (PMOverlayLoadType)2);
        LoadDwcOverlay();
        LoadOVY38();
        sub_02039FD8((enum HeapID)0x73);
        state->heapAllocation = Heap_Alloc((enum HeapID)0x73, 0x20020);
        state->expHeap = NNS_FndCreateExpHeapEx((void *)(((u32)state->heapAllocation + 0x1F) & ~0x1F), 0x20000, 0);
        sub_02034D8C();
        Sys_ClearSleepDisableFlag(4);
    }
}

void ov75_02246B98(Overlay75State *state) {
    if (state->onlineLoaded == 1) {
        NNS_FndDestroyExpHeap(state->expHeap);
        Heap_Free(state->heapAllocation);
        UnloadOVY38();
        UnloadDwcOverlay();
        sub_02034DE0();
        UnloadOverlayByID(FS_OVERLAY_ID(OVY_70));
        state->onlineLoaded = 0;
    }
}
