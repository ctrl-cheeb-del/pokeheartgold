#include "overlay68_helpers_internal.h"

void ov68_021E5B14(MoveRelearner *d) {
    ov68_021E7604(d);
    ov68_021E68C4(d);
    ov68_021E5E94(d);
    ov68_021E5E38(d);
    ov68_021E5CD8(d->bgConfig);
    ov68_021E5F18(d);
    ov68_021E7388(&d->pokepic);
    ov68_021E6E84(d);
    MenuInputStateMgr_SetState(d->args->unk_0C, d->unk_1B4);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    GF_DestroyVramTransferManager();
    Main_SetVBlankIntrCB(NULL, NULL);
}

void ov68_021E5B6C(MoveRelearner *d) {
    DoScheduledBgGpuUpdates(d->bgConfig);
    PokepicManager_HandleLoadImgAndOrPltt(d->pokepic.pokepicMan);
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}
