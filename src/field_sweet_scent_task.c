#include "field_sweet_scent_task_internal.h"

BOOL Task_UseSweetScentInField(TaskManager *taskManager);
void ov01_021FCFEC(FieldSystem *fieldSystem);
BOOL ov01_021FD014(TaskManager *taskManager);
void ov01_021FD064(enum HeapID heapID, FieldSystem *fieldSystem, SweetScentAnimWork *work);
void ov01_021FD128(SweetScentAnimWork *work);
BOOL ov01_021FD154(Field3DModelAnimation *anims, u32 count);
void ov01_021FD190(Field3DModelAnimation *anims, u32 count, fx32 frame);

BOOL Task_UseSweetScentInField(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveEnvironment *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);
    SweetScentFieldEnv *work = (SweetScentFieldEnv *)env->moveData;

    switch (*state) {
    case 0: {
        u32 partySlot = ((FieldMoveData *)work)->partySlot;
        Heap_Free(work);
        work = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(SweetScentFieldEnv));
        env->moveData = (FieldMoveData *)work;
        work->partySlot = partySlot;
        ++*state;
        break;
    }
    case 1: {
        u32 size = GetHoneySweetScentWorkSize();
        work->honeyWork = Heap_AllocAtEnd(HEAP_ID_FIELD2, size);
        memset(work->honeyWork, 0, size);
        {
            int avatarState = PlayerAvatar_GetState(fieldSystem->playerAvatar);
            if (avatarState == 1 || avatarState == 2) { // walking or biking?
                ++*state;
                break;
            }
        }
        if (work->partySlot == ov01_022062CC(fieldSystem) && FollowMon_IsVisible(fieldSystem)) {
            TaskManager_Call(taskManager, ov01_02205A60, NULL);
            *state = 4;
            break;
        }
        ++*state;
        break;
    }
    case 2:
        work->effect = ov02_02249458(fieldSystem, 0, env->mon, PlayerAvatar_GetGender(fieldSystem->playerAvatar));
        ++*state;
        break;
    case 3:
        if (ov02_0224953C(work->effect)) {
            ov02_02249548(work->effect);
            *state = 6;
        }
        break;
    case 4: {
        u8 kind;
        if (ov02_02250780(fieldSystem, 12)) {
            kind = 2;
            FieldSystem_UnkSub108_AddMonMood(fieldSystem->unk108, 1);
        } else {
            kind = 1;
        }
        ov02_022507B4(fieldSystem, kind);
        ++*state;
        break;
    }
    case 5:
        ov01_021FCFEC(fieldSystem);
        ++*state;
        break;
    case 6:
        TaskManager_Call(taskManager, Task_HoneyOrSweetScent, work->honeyWork);
        ++*state;
        break;
    case 7:
        Heap_Free(work);
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void ov01_021FCFEC(FieldSystem *fieldSystem) {
    SweetScentAnimWork *work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(SweetScentAnimWork));
    ov01_021FD064(HEAP_ID_FIELD1, fieldSystem, work);
    TaskManager_Call(fieldSystem->taskman, ov01_021FD014, work);
}

BOOL ov01_021FD014(TaskManager *taskManager) {
    SweetScentAnimWork *work = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);

    switch (*state) {
    case 0:
        if (ov01_021FD154(work->anims, 3)) {
            ++*state;
        }
        Field3dObject_Draw(&work->object);
        break;
    case 1:
        ov01_021FD128(work);
        Heap_Free(work);
        return TRUE;
    }
    return FALSE;
}

void ov01_021FD064(enum HeapID heapID, FieldSystem *fieldSystem, SweetScentAnimWork *work) {
    VecFx32 position;

    HeapExp_FndInitAllocator(&work->allocator, heapID, 0x20);
    Field3dModel_LoadFromFilesystem(&work->model, NARC_a_1_3_4, 23, heapID);
    Field3dModelAnimation_LoadFromFilesystem(&work->anims[0], &work->model, NARC_a_1_3_4, 21, heapID, &work->allocator);
    Field3dModelAnimation_LoadFromFilesystem(&work->anims[1], &work->model, NARC_a_1_3_4, 22, heapID, &work->allocator);
    Field3dModelAnimation_LoadFromFilesystem(&work->anims[2], &work->model, NARC_a_1_3_4, 20, heapID, &work->allocator);
    Field3dObject_InitFromModel(&work->object, &work->model);
    Field3dObject_AddAnimation(&work->object, &work->anims[0]);
    Field3dObject_AddAnimation(&work->object, &work->anims[1]);
    Field3dObject_AddAnimation(&work->object, &work->anims[2]);
    ov01_021FD190(work->anims, 3, 0);
    MapObject_CopyPositionVector(FollowMon_GetMapObject(fieldSystem), &position);
    Field3dObject_SetPosEx(&work->object, position.x, position.y, position.z);
    Field3dObject_SetActiveFlag(&work->object, TRUE);
}

void ov01_021FD128(SweetScentAnimWork *work) {
    Field3dModelAnimation_Unload(&work->anims[2], &work->allocator);
    Field3dModelAnimation_Unload(&work->anims[1], &work->allocator);
    Field3dModelAnimation_Unload(&work->anims[0], &work->allocator);
    Field3dModel_Unload(&work->model);
}

BOOL ov01_021FD154(Field3DModelAnimation *anims, u32 count) {
    u8 i;
    u8 numDone = 0;

    for (i = 0; i < count; ++i) {
        if (Field3dModelAnimation_FrameAdvanceAndCheck(&anims[i], FX32_ONE)) {
            ++numDone;
        }
    }
    return numDone == count;
}

void ov01_021FD190(Field3DModelAnimation *anims, u32 count, fx32 frame) {
    u8 i;

    for (i = 0; i < count; ++i) {
        Field3dModelAnimation_FrameSet(&anims[i], frame);
    }
}
