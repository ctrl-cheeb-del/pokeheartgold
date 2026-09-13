#include "r40_overlay_108_residual_6_private.h"

void ov108_021E6B00(SafariAreaCustomizer *work) {
    YesNoPromptTemplate template;

    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = work->bgConfig;
    template.bgId = 0;
    template.tileStart = 0x379;
    template.plttSlot = 13;
    template.x = 26;
    template.y = 16;
    template.ignoreTouchFlag = (u8)work->unk10;
    template.initialCursorPos = 0;
    YesNoPrompt_InitFromTemplate(work->yesNoPrompt, &template);
    ov108_021E79A8(work, 1, work->unk184E0, 1);
    ov108_021E7BB4(work, work->unk184DF, (u8)(work->unk184E0 + 6 * work->unk184DE));
    ov108_021E767C(work, 1);
    ov108_021E7700(work, 1, 3, 1);
}

void ov108_021E6BA0(SafariAreaCustomizer *work) {
    vu32 *irqBase;

    ov108_021E8490(work);
    if (work->flag0) {
        BgSetPosTextAndCommit(work->bgConfig, 1, BG_POS_OP_SET_Y, work->unk184E4);
        BgSetPosTextAndCommit(work->bgConfig, 2, BG_POS_OP_SET_Y, work->unk184E4);
        BgSetPosTextAndCommit(work->bgConfig, 4, BG_POS_OP_SET_Y, work->unk184E6);
        BgSetPosTextAndCommit(work->bgConfig, 6, BG_POS_OP_SET_Y, work->unk184E6);
        BgSetPosTextAndCommit(work->bgConfig, 5, BG_POS_OP_SET_Y, work->unk184E6);
        work->flag0 = 0;
    }
    GF_RunVramTransferTasks();
    DoScheduledBgGpuUpdates(work->bgConfig);
    irqBase = (vu32 *)0x027E0000;
    irqBase[0x3FF8 / 4] |= 1;
}
