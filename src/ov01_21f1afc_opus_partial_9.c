#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

int ov01_021F2894(struct RockClimbWork *work, TaskManager *taskManager) {
    if (!MapObject_IsMovementPaused(work->obj)) {
        return 0;
    }
    MapObject_ClearHeldMovementIfActive(work->obj);
    ov01_021F1640(work->unk18);
    return 1;
}

void *ov01_021F28B8(FieldSystem *fieldSystem, int a1, struct SurfWork *a2) {
    struct WaterfallWork *work = ov01_021F30D0(sizeof(struct WaterfallWork));
    work->direction = a1;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = fieldSystem->playerAvatar;
    work->obj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    if (a2 != NULL) {
        work->surf = *a2;
    }
    return work;
}

void ov01_021F28EC(FieldSystem *fieldSystem, u32 a1) {
    FieldSystem_CreateTask(fieldSystem, ov01_021F2944, ov01_021F28B8(fieldSystem, a1, 0));
}

void CallFieldTask_Waterfall(TaskManager *taskManager, int direction, int partySlot) {
    struct SurfWork work;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    ov01_021F3040(fieldSystem, (u32)ov01_021F3100(fieldSystem, partySlot), &work);
    TaskManager_Call(taskManager, ov01_021F2944, ov01_021F28B8(fieldSystem, direction, &work));
}
