#include "global.h"

#include "r40_overlay_103_residual_2_private.h"
#define BG(work) (*(BgConfig **)((work)->ctx))

void ov103_021EC9E8(R40Ov103Work2 *work) {
    GraphicsModes modes;
    BgTemplate bg4, bg5, bg6, bg7, bg0, bg1, bg2, bg3;

    BG(work) = BgConfig_Alloc(HEAP_ID_157);
    modes = ov103_021EEB40;
    SetBothScreensModesAndDisable(&modes);
    bg4 = ov103_021EEBC0;
    InitBgFromTemplate(BG(work), 4, &bg4, 0);
    BgClearTilemapBufferAndCommit(BG(work), 4);
    BG_ClearCharDataRange(4, 0x20, 0, HEAP_ID_157);
    bg5 = ov103_021EEBA4;
    InitBgFromTemplate(BG(work), 5, &bg5, 0);
    BgClearTilemapBufferAndCommit(BG(work), 5);
    BG_ClearCharDataRange(5, 0x20, 0, HEAP_ID_157);
    bg6 = ov103_021EEB88;
    InitBgFromTemplate(BG(work), 6, &bg6, 0);
    BgClearTilemapBufferAndCommit(BG(work), 6);
    BG_ClearCharDataRange(6, 0x20, 0, HEAP_ID_157);
    bg7 = ov103_021EEC14;
    InitBgFromTemplate(BG(work), 7, &bg7, 0);
    bg0 = ov103_021EEBDC;
    InitBgFromTemplate(BG(work), 0, &bg0, 0);
    BgClearTilemapBufferAndCommit(BG(work), 0);
    BG_ClearCharDataRange(0, 0x20, 0, HEAP_ID_157);
    bg1 = ov103_021EEB50;
    InitBgFromTemplate(BG(work), 1, &bg1, 0);
    BgClearTilemapBufferAndCommit(BG(work), 1);
    BG_ClearCharDataRange(1, 0x20, 0, HEAP_ID_157);
    bg2 = ov103_021EEB6C;
    InitBgFromTemplate(BG(work), 2, &bg2, 0);
    BgClearTilemapBufferAndCommit(BG(work), 2);
    bg3 = ov103_021EEBF8;
    InitBgFromTemplate(BG(work), 3, &bg3, 0);
}
