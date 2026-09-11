#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

int ov01_021F2694(struct RockClimbWork *work, TaskManager *taskManager) {
    ov01_021F3054(work->fieldSystem, &work->surf);
    work->state++;
    return 0;
}

int ov01_021F26AC(struct RockClimbWork *work, TaskManager *taskManager) {
    if (ov01_021F3068(&work->surf) == TRUE) {
        ov01_02205D68(work->fieldSystem);
        work->state++;
    }
    return 0;
}
