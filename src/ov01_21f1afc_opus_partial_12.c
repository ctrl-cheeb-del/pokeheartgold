#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

void CallFieldTask_Whirlpool(TaskManager *taskManager, int direction, int partySlot) {
    struct SurfWork work;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    ov01_021F3040(fieldSystem, (u32)ov01_021F3100(fieldSystem, partySlot), &work);
    ov01_021F2D68(fieldSystem, direction, &work);
}
