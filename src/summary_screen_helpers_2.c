#include "summary_screen_helpers_internal.h"

void sub_020885DC(void *data) {
    DoScheduledBgGpuUpdates(*(BgConfig **)data);
    PokepicManager_HandleLoadImgAndOrPltt(*(void **)((u8 *)data + 0x2A0));
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    *(u32 *)((u8 *)OS_IRQTable + 0x3FF8) |= 1;
}

void sub_02088610(void) {
    SummaryBanks banks = _02103990;
    GfGfx_SetBanks(&banks);
}
