#include "global.h"

#include "constants/sndseq.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "trainer_card_main_04_private.h"

void ov51_021E6238(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate bg7;
    TrainerCardBgPair bg45;
    BgTemplate bg6;
    BgTemplate bg2;
    BgTemplate bg3;

    *(vu16 *)0x04000304 |= 0x8000;
    modes = ov51_021E7DC8;
    SetBothScreensModesAndDisable(&modes);

    bg7 = ov51_021E7E8C;
    InitBgFromTemplate(bgConfig, 7, &bg7, 2);
    BgClearTilemapBufferAndCommit(bgConfig, 7);

    bg45 = ov51_021E7ED0;
    InitBgFromTemplate(bgConfig, 4, &bg45.items[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    InitBgFromTemplate(bgConfig, 5, &bg45.items[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 5);

    bg6 = ov51_021E7E70;
    InitBgFromTemplate(bgConfig, 6, &bg6, 2);
    BgClearTilemapBufferAndCommit(bgConfig, 6);
    bg2 = ov51_021E7E38;
    InitBgFromTemplate(bgConfig, 2, &bg2, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    bg3 = ov51_021E7E54;
    InitBgFromTemplate(bgConfig, 3, &bg3, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
}
