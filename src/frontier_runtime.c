#include "frontier_runtime_internal.h"

int Frontier_Init(void *manager) {
    FrontierWork *work;
    Frontier_LoadOverlays();
    work = OverlayManager_CreateAndGetData(manager, 0xa54, 11);
    MI_CpuFill8(work, 0, 0xa54);
    sub_02096780(work);
    sub_02096884(work);
    work->launchArgs = OverlayManager_GetArgs(manager);
    if (work->launchArgs == 0) {
        GF_AssertFail();
    }
    work->system = FrontierSystem_Create(work, 11, ((FrontierLaunchArgsInternal *)work->launchArgs)->mode);
    FrontierSystem_AddTask(work->system, ((FrontierLaunchArgsInternal *)work->launchArgs)->mode, 0);
    Frontier_CreateMap(work);
    return 1;
}

int Frontier_Main(void *manager, int *state) {
    FrontierWork *work = OverlayManager_GetData(manager);
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        if (work->exitRequested == 1) {
            *state = 2;
            break;
        }
        if (work->mapActive == 0) {
            break;
        }
        if (work->rebuildPending == 1) {
            *state = 5;
            break;
        }
        FrontierSystem_Main(work->system);
        if (work->childManager != 0) {
            *state = 3;
        }
        break;
    case 2:
        return 1;
    case 3:
        ov80_022389C4(work->map);
        Frontier_FreeMap(work);
        Frontier_UnloadOverlays();
        *state = 4;
        break;
    case 4:
        if (OverlayManager_Run(work->childManager) == 1) {
            OverlayManager_Delete(work->childManager);
            Frontier_LoadOverlays();
            if (work->childExit != 0) {
                work->childExit(work->childArgs);
            }
            if (work->childArgs != 0 && work->freeChildArgs == 1) {
                Heap_Free(work->childArgs);
            }
            work->childManager = 0;
            work->childExit = 0;
            work->childArgs = 0;
            Frontier_CreateMap(work);
            ov80_02238A18(work->map);
            *state = 1;
        }
        break;
    case 5:
        Frontier_FreeMap(work);
        sub_02096780(work);
        *state = 6;
        break;
    case 6:
        Frontier_CreateMap(work);
        if (work->taskId == 0xffff) {
            ov80_0222AA7C(work->system, ((FrontierLaunchArgsInternal *)work->launchArgs)->mode, 11);
        } else {
            void *saved = ov80_0222AAD8(work->system, 11);
            ov80_0222A920(work->system);
            work->system = FrontierSystem_Create(work, 11, ((FrontierLaunchArgsInternal *)work->launchArgs)->mode);
            FrontierSystem_AddTask(work->system, ((FrontierLaunchArgsInternal *)work->launchArgs)->mode, work->taskId);
            ov80_0222AAF8(work->system, saved);
        }
        work->rebuildPending = 0;
        *state = 1;
        break;
    }
    return 0;
}

int Frontier_Exit(void *manager) {
    FrontierWork *work = OverlayManager_GetData(manager);
    ov80_0222A920(work->system);
    Frontier_FreeMap(work);
    OverlayManager_FreeData(manager);
    Frontier_UnloadOverlays();
    return 1;
}

void Frontier_CreateMap(FrontierWork *work) {
    work->map = FrontierMap_Init();
    work->mapActive = 1;
}

void Frontier_FreeMap(FrontierWork *work) {
    FrontierMap_Free(work->map);
    work->mapActive = 0;
}

void sub_02096780(FrontierWork *work) {
    int i;
    for (i = 0; i < 24; i++) {
        work->headerRecords[i].value = 0xffff;
    }
    MI_CpuFill8(work->records, 0, sizeof(work->records));
    for (i = 0; i < 32; i++) {
        work->records[i].value = 0xffff;
    }
}

void Frontier_LoadOverlays(void) {
    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_80_ID, 2);
    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_81_ID, 2);
    HandleLoadOverlay((u32)SDK_OVERLAY_OVY_42_ID, 2);
}

void Frontier_UnloadOverlays(void) {
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_80_ID);
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_81_ID);
    UnloadOverlayByID((u32)SDK_OVERLAY_OVY_42_ID);
}

void *Frontier_GetLaunchArgs(FrontierWork *work) {
    return work->launchArgs;
}

void *sub_0209680C(FrontierWork *work) {
    return work->map;
}

void *Frontier_GetData(FrontierWork *work) {
    return *(void **)work->launchArgs;
}

void Frontier_SetData(FrontierWork *work, void *data) {
    *(void **)work->launchArgs = data;
}

void Frontier_LaunchApplication(FrontierWork *work, const void *template, void *args, u8 freeArgs, void (*exit)(void *)) {
    if (work->childManager != 0) {
        GF_AssertFail();
    }
    work->childManager = OverlayManager_New(template, args, 11);
    work->childArgs = args;
    work->freeChildArgs = freeArgs;
    work->childExit = exit;
}

void sub_0209684C(FrontierLaunchArgsInternal *args) {
    ((u8 *)args)[0x22] = 1;
}

void sub_02096854(FrontierWork *work, u8 mode, u16 taskId) {
    ((FrontierLaunchArgsInternal *)work->launchArgs)->mode = mode;
    work->rebuildPending = 1;
    work->taskId = taskId;
}

void *sub_02096864(FrontierWork *work) {
    return (u8 *)work + 0x24;
}

void *sub_02096868(FrontierWork *work) {
    return (u8 *)work + 0x84;
}

void *sub_0209686C(FrontierWork *work, int index) {
    return (u8 *)work + 0x84 + index * 0x3c;
}

void *sub_02096878(FrontierWork *work) {
    return (u8 *)work + 0xa04;
}

void sub_02096884(FrontierWork *work) {
    int i;
    MI_CpuFill8((u8 *)work + 0xa04, 0, 8);
    i = 0;
    do {
        i++;
        *(u16 *)((u8 *)work + 0xa04) = 0xffff;
        work = (FrontierWork *)((u8 *)work + 2);
    } while (i < 8);
}
