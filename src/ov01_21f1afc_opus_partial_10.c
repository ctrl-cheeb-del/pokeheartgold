#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

int ov01_021F2998(struct WaterfallWork *work, TaskManager *taskManager) {
    if (work->surf.unk0 == 1) {
        ov01_021F3054(work->fieldSystem, &work->surf);
        work->state++;
        return 0;
    }
    work->state = 2;
    return 1;
}

int ov01_021F29C0(struct WaterfallWork *work, TaskManager *taskManager) {
    if (ov01_021F3068(&work->surf) == TRUE) {
        PlaySE(SEQ_SE_DP_FW463);
        work->state++;
    }
    return 0;
}
