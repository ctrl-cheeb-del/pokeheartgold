#include "../include/overlay18_dex_window_private.h"

void ov18_021F8F10(Ov18Work *work) {
    u32 i;
    for (i = 0; i < 9; i++) {
        RemoveWindow(&work->windows[i]);
    }
}

void ov18_021F8F28(Ov18Work *work) {
    ObjCharTransferTemplate template = ov18_021FBD50;
    template.heapID = work->heapId;
    ObjCharTransfer_InitEx(&template, GX_OBJVRAMMODE_CHAR_1D_64K, (GXOBJVRamModeChar)16);
}

void ov18_021F8F58(void) {
    ObjCharTransfer_Destroy();
}

void ov18_021F8F60(Ov18Work *work) {
    int i;
    for (i = 0; i < 4; i++) {
        work->gfxManagers[i] = Create2DGfxResObjMan(8, i, work->heapId);
    }
}
