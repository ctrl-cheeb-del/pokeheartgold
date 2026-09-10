#include "frontier_system_internal.h"

FrontierSystem *FrontierSystem_Create(void *parent, u32 heapId, u32 mode) {
    FrontierSystem *system = Heap_Alloc(heapId, sizeof(FrontierSystem));
    MI_CpuFill8(system, 0, sizeof(FrontierSystem));
    system->parent = parent;
    system->heapId = heapId;
    system->mode = mode;
    ov80_0222AA40(&system->narcData, &system->msgData, mode, heapId);
    system->messageFormat = MessageFormat_New_Custom(8, 0x40, heapId);
    system->string1 = String_New(0x400, heapId);
    system->string2 = String_New(0x400, heapId);
    FrontierSystem_deadstripped_0222AA3C(system, mode, 0, 0);
    return system;
}

BOOL FrontierSystem_Main(FrontierSystem *system) {
    s32 i;
    if (system->taskCount == 0) {
        return TRUE;
    }
    if (system->pad38[0] == 0) {
        for (i = 0; i < 8; i++) {
            FrontierScriptContext *task = system->tasks[i];
            if (task != NULL && !FrontierScriptContext_Run(task)) {
                ov80_0222AA0C(system, task);
                system->tasks[i] = NULL;
                system->taskCount--;
            }
        }
        ov80_02239C54(system->parent);
    }
    return system->taskCount == 0;
}

void ov80_0222A920(FrontierSystem *system) {
    if (system->taskCount != 0) {
        GF_AssertFail();
    }
    MessageFormat_Delete(system->messageFormat);
    String_Delete(system->string1);
    String_Delete(system->string2);
    Heap_Free(system->narcData);
    DestroyMsgData(system->msgData);
    Heap_Free(system);
}

void FrontierSystem_AddTask(FrontierSystem *system, u16 mode, u32 value) {
    FrontierScriptContext *task = Heap_Alloc(system->heapId, sizeof(FrontierScriptContext));
    MI_CpuFill8(task, 0, sizeof(FrontierScriptContext));
    FrontierScriptContext_Init(task, gFrontierCommandTable, ov80_0223B9CC);
    task->system = system;
    if (mode == 0xffff || system->mode == mode) {
        task->narcData = system->narcData;
        task->msgData = system->msgData;
    } else {
        ov80_0222AA40(&task->narcData, &task->msgData, mode, system->heapId);
    }
    FrontierScriptContext_Start(task, task->narcData);
    ov80_0222AB14(task, value);
    ov80_0222A9DC(system, task);
}

BOOL ov80_0222A9DC(FrontierSystem *system, FrontierScriptContext *task) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (system->tasks[i] == NULL) {
            system->tasks[i] = task;
            system->taskCount++;
            return TRUE;
        }
    }
    GF_AssertFail();
    return FALSE;
}

void ov80_0222AA0C(FrontierSystem *system, FrontierScriptContext *task) {
    if (task->msgData != system->msgData) {
        DestroyMsgData(task->msgData);
    }
    if (task->narcData != system->narcData) {
        Heap_Free(task->narcData);
    }
    Heap_Free(task);
}

void FrontierSystem_deadstripped_0222AA3C(FrontierSystem *system, u16 mode, u32 a, u32 b) {
}

void ov80_0222AA40(void **narcData, void **msgData, u32 mode, u32 heapId) {
    u32 member = ov80_0222ACA0(mode, 1);
    u32 bank = ov80_0222ACA0(mode, 2);
    *narcData = AllocAndReadWholeNarcMemberByIdPair(0xb6, member, heapId);
    *msgData = NewMsgDataFromNarc(1, 0x1b, bank, heapId);
}

void ov80_0222AA7C(FrontierSystem *system, u16 mode, u32 heapId) {
    s32 i;
    u32 oldBank = ov80_0222ACA0(system->mode, 2);
    u32 newBank = ov80_0222ACA0(mode, 2);
    if (oldBank != newBank) {
        void *msgData = NewMsgDataFromNarc(1, 0x1b, newBank, heapId);
        for (i = 0; i < 8; i++) {
            if (system->tasks[i] != NULL && system->tasks[i]->msgData == system->msgData) {
                system->tasks[i]->msgData = msgData;
            }
        }
        DestroyMsgData(system->msgData);
        system->msgData = msgData;
    }
}

u16 *ov80_0222AAD8(FrontierSystem *system, u32 heapId) {
    u16 *copy = Heap_Alloc(heapId, 0x10);
    u16 *source = system->halfwords;
    u16 *dest = copy;
    u32 count = 8;
    do {
        *dest++ = *source++;
    } while (--count);
    return copy;
}

void ov80_0222AAF8(FrontierSystem *system, u16 *copy) {
    u16 *source = copy;
    u16 *dest = system->halfwords;
    u32 count = 8;
    do {
        *dest++ = *source++;
    } while (--count);
    Heap_Free(copy);
}

void ov80_0222AB14(FrontierScriptContext *task, u32 count) {
    task->script += count * 4;
    task->script += FrontierScriptContext_ReadWord(task);
}

u16 *ov80_0222AB2C(FrontierScriptContext *task, u32 index) {
    return (u16 *)((u8 *)task + 0x24 + index * 2);
}

void *FrontierSystem_GetFrontierMap(FrontierSystem *system) {
    return sub_0209680C(system->parent);
}
