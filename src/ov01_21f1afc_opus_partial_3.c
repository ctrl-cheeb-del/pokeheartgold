#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

BOOL ov01_021F2004(TaskManager *taskManager, FieldSystem *fieldSystem, LocalMapObject *obj) {
    if (ov01_021F1F8C(fieldSystem, obj) == 0) {
        return TRUE;
    }
    StartScriptFromMenu(taskManager, 0x271F, NULL);
    return FALSE;
}
