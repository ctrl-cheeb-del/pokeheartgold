#include "r46_overlay83_private.h"

BOOL ov83_0223DFBC(OverlayManager *manager) {
    u8 *work = OverlayManager_GetData(manager);

    **(u16 **)(work + 0x7A0) = work[0xD];
    *(vu16 *)0x04000050 = 0;
    GF_DestroyVramTransferManager();
    ov83_0223F058(work);
    OverlayManager_FreeData(manager);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(HEAP_ID_107);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_80));
    return TRUE;
}
