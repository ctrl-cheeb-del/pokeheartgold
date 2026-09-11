#include "overlay_82_internal.h"

BOOL ov82_0223E2A4(Ov82Work *work) {
    if (work->unk008 == 0) {
        if (OverlayManager_Run(work->unk004) == TRUE) {
            work->unk20C = *(u8 *)((u8 *)work->unk0A4 + 0x14);
            Heap_Free(work->unk0A4);
            Heap_Free(work->unk004);
            work->unk004 = NULL;
            ov82_0223E974(work);
            work->unk010 = 0;
            return TRUE;
        }
    }
    return FALSE;
}
