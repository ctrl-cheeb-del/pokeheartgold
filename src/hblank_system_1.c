#include "hblank_system_internal.h"

HBlankSystem *HBlankSystem_New(u32 heapId) {
    HBlankSystem *system = Heap_Alloc(heapId, sizeof(HBlankSystem));
    ov01_021FB55C(system);
    return system;
}

void HBlankSystem_Delete(HBlankSystem *system) {
    if (system != NULL) {
        if (system->running == TRUE) {
            HBlankSystem_Stop(system);
        }
        ov01_021FB55C(system);
        Heap_Free(system);
    }
}

void HBlankSystem_Start(HBlankSystem *system) {
    if (Main_SetHBlankIntrCB(ov01_021FB594, system) != TRUE) {
        GF_AssertFail();
    }
    system->running = TRUE;
}

void HBlankSystem_Stop(HBlankSystem *system) {
    if (Main_SetHBlankIntrCB(NULL, NULL) != TRUE) {
        GF_AssertFail();
    }
    system->running = FALSE;
}

HBlankTask *ov01_021FB530(HBlankSystem *system, HBlankTaskCallback callback, void *arg) {
    HBlankTask *task = ov01_021FB5B4(system);
    if (task == NULL) {
        GF_AssertFail();
    }
    if (task != NULL) {
        task->arg = arg;
        task->callback = callback;
        task->active = TRUE;
    }
    return task;
}

void ov01_021FB554(HBlankTask *task) {
    ov01_021FB584(task);
}

void ov01_021FB55C(HBlankSystem *system) {
    memset(system, 0, sizeof(HBlankSystem));
    system->running = FALSE;
    {
        s32 i;
        for (i = 0; i < 2; i++) {
            ov01_021FB584(&system->tasks[i]);
        }
    }
}

void ov01_021FB584(HBlankTask *task) {
    task->active = FALSE;
    task->callback = ov01_021FB5B0;
    task->arg = NULL;
}

void ov01_021FB594(void *arg) {
    HBlankSystem *system = arg;
    s32 i;
    for (i = 0; i < 2; i++) {
        system->tasks[i].callback(&system->tasks[i], system->tasks[i].arg);
    }
}

void ov01_021FB5B0(HBlankTask *task, void *arg) {
}

HBlankTask *ov01_021FB5B4(HBlankSystem *system) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (system->tasks[i].active == FALSE) {
            return &system->tasks[i];
        }
    }
    return NULL;
}
