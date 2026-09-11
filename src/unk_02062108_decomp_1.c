#include "unk_02062108_internal.h"

EventObjectMovementMan *EventObjectMovementMan_Create(LocalMapObject *object, const MovementScriptCommand *command) {
    struct EventObjectMovementWork *work;
    SysTask *task;

    work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(struct EventObjectMovementWork));
    if (work == NULL) {
        GF_AssertFail();
    }
    {
        u8 *dest = (u8 *)work;
        u32 size = sizeof(struct EventObjectMovementWork);
        while (size != 0) {
            *dest++ = 0;
            size--;
        }
    }
    {
        u32 priority = MapObjectManager_GetPriority(MapObject_GetManager(object)) - 1;
        task = SysTask_CreateOnMainQueue(MovementScriptMachine, work, priority);
    }
    if (task == NULL) {
        GF_AssertFail();
    }
    work->object = object;
    work->command = command;
    return (EventObjectMovementMan *)task;
}

BOOL EventObjectMovementMan_IsFinish(EventObjectMovementMan *movementMan) {
    struct EventObjectMovementWork *work = SysTask_GetData((SysTask *)movementMan);
    return work->finished;
}

void EventObjectMovementMan_Delete(EventObjectMovementMan *movementMan) {
    SysTask *task = (SysTask *)movementMan;
    struct EventObjectMovementWork *work = SysTask_GetData(task);

    if (MapObject_IsMovementPaused(work->object) != TRUE) {
        GF_AssertFail();
    }
    MapObject_ClearHeldMovementIfActive(work->object);
    Heap_FreeExplicit(HEAP_ID_FIELD1, work);
    SysTask_Destroy(task);
}

void MovementScriptMachine(SysTask *task, void *data) {
    struct EventObjectMovementWork *work = data;
    while (sMovementScriptMachineStateFuncs[work->state](work) == TRUE) {}
}

BOOL MovementScriptMachineSub_Init(struct EventObjectMovementWork *work) {
    work->index = 0;
    work->state = 1;
    return TRUE;
}

BOOL MovementScriptMachineSub_WaitReady(struct EventObjectMovementWork *work) {
    if (!MapObject_AreBitsSetForMovementScriptInit(work->object)) {
        return FALSE;
    }
    work->state = 2;
    return TRUE;
}

BOOL MovementScriptMachineSub_SetMovementCommand(struct EventObjectMovementWork *work) {
    MapObject_SetHeldMovement(work->object, work->command->command);
    work->state = 3;
    return FALSE;
}

BOOL MovementScriptMachineSub_WaitMovementCommand(struct EventObjectMovementWork *work) {
    if (!MapObject_IsMovementPaused(work->object)) {
        return FALSE;
    }
    work->state = 4;
    return TRUE;
}

BOOL MovementScriptMachineSub_LoopCheck(struct EventObjectMovementWork *work) {
    s32 index = work->index;
    const MovementScriptCommand *command = work->command;
    index++;
    work->index = index;
    if (index < command->length) {
        work->state = 1;
        return TRUE;
    }
    work->command = command + 1;
    if (command[1].command != 0xfe) {
        work->state = 0;
        return TRUE;
    }
    work->finished = TRUE;
    work->state = 5;
    return FALSE;
}

BOOL MovementScriptMachineSub_Done(struct EventObjectMovementWork *work) {
    return FALSE;
}

u32 sub_0206234C(s32 index, u32 movement) {
    s32 i;
    const u32 *const *table;
    const u32 *scan;
    const u32 *entry;

    if (index >= 4) {
        GF_AssertFail();
    }
    table = _020FD198;
    entry = *table;
    if (entry != NULL) {
        do {
            i = 0;
            scan = entry;
            do {
                if (movement == *scan) {
                    return entry[index];
                }
                i++;
                scan++;
            } while (i < 4);
            table++;
            entry = *table;
        } while (entry != NULL);
    }
    GF_AssertFail();
    return movement;
}

s32 sub_02062390(u32 movement) {
    s32 i;
    const u32 *const *table = _020FD198;
    const u32 *entry = *table;

    if (entry != NULL) {
        do {
            for (i = 0; i < 4; i++) {
                if (entry[i] == movement) {
                    return i;
                }
            }
            table++;
            entry = *table;
        } while (entry != NULL);
    }
    return -1;
}

BOOL sub_020623C8(u32 value) {
    value -= 0x38;
    if (value <= 3) {
        return TRUE;
    }
    return FALSE;
}

u32 sub_020623D8(s32 index) {
    struct FourWords {
        u32 v[4];
    };
    struct FourWords values = *(const struct FourWords *)_020FDA28;
    if (index >= 4) {
        GF_AssertFail();
    }
    return values.v[index];
}

void sub_02062400(LocalMapObject *object) {
    u32 command;
    do {
        command = MapObject_GetMovementCommand(object);
        if (command == 0xff) {
            break;
        }
    } while (MapObject_RunMovementCommand(object, command, MapObject_GetMovementStep(object)) != FALSE);
}

BOOL sub_02062428(LocalMapObject *object) {
    sub_02062400(object);
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return FALSE;
    }
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK5);
    MapObject_SetMovementCommand(object, 0xff);
    MapObject_SetMovementStep(object, 0);
    return TRUE;
}

BOOL MapObject_RunMovementCommand(LocalMapObject *object, u32 command, u32 step) {
    return gMovementCmdTable[command][step](object);
}

BOOL MapObjectMovementCmd098_Step2(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK5);
    return FALSE;
}

void sub_0206247C(LocalMapObject *object, u32 direction) {
    MapObject_SetFacingDirection(object, direction);
    sub_0205F328(object, 0);
    sub_02060F78(object);
    MapObject_IncrementMovementStep(object);
}
