#include "global.h"

#include "overlay90_residual_16_residual_2_private.h"

void ov90_0225A088(Ov90A088Work *work, void *bgConfig, void *arg) {
    int i;

    GF_ASSERT(work->task == NULL);
    work->bgConfig = bgConfig;
    BgSetPosTextAndCommit(*(u32 *)bgConfig, 0, 0, -255);
    BgSetPosTextAndCommit(*(u32 *)work->bgConfig, 1, 0, -255);
    for (i = 0; i < 2; i++) {
        MIi_CpuClear16(0xFF01, (u16 *)work->buffers[i], 0x180);
    }
    work->task = sub_02014A08(arg, work->buffers[0], work->buffers[1]);
    sub_02014A78(work->task, 0);
    Main_SetHBlankIntrCB(ov90_0225A1B8, work);
}
