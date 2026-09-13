#include "r40_overlay_73_residual_16_private.h"

BOOL ov73_021E808C(void *manager, int *state) {
    void *p = OverlayManager_GetData(manager);

    Heap_Free(PTR(p, 0x24));
    UnloadOVY38();
    UnloadDwcOverlay();
    ov73_021E847C(p);
    DestroyMsgData(PTR(p, 0xBDC));
    DestroyMsgData(PTR(p, 0xBD8));
    DestroyMsgData(PTR(p, 0xBD4));
    MessageFormat_Delete(PTR(p, 0xBD0));
    ov73_021E8164(p);
    sub_02034DE0();
    Heap_Free(PTR(p, 4));
    OverlayManager_FreeData(manager);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(0x96);
    return TRUE;
}

void ov73_021E8100(void *p) {
    vu32 *base = (vu32 *)0x027E0000;

    GF_RunVramTransferTasks();
    DoScheduledBgGpuUpdates(PTR(p, 4));
    OamManager_ApplyAndResetBuffers();
    base[0x3FF8 / 4] |= 1;
}

void ov73_021E8128(void) {
    SolBanks banks = ov73_021EA6AC;
    GfGfx_SetBanks(&banks);
}
