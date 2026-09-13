#include "r40_unk_020755E8_residual_3_private.h"

void sub_02077270(Work *work) {
    u8 *raw = (u8 *)work;

    G2_SetWnd0Position(raw[0x72], raw[0x73], raw[0x74], raw[0x75]);

    PokepicManager_HandleLoadImgAndOrPltt(work->pokepicMgr);
    if (work->spritesReady != NULL) {
        if (work->spriteManager == NULL) {
            GF_AssertFail();
        }
        SpriteSystem_DrawSprites(work->spriteManager);
        SpriteSystem_TransferOam();
    }
    GF_RunVramTransferTasks();
    PaletteData_PushTransparentBuffers(work->palette);
    DoScheduledBgGpuUpdates(work->bg);
    *(u32 *)((u8 *)OS_IRQTable + 0x3ff8) |= 1;
}
