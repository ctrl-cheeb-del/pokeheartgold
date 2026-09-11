#include "overlay_01_021EFB38_internal.h"

void ov01_021EFB38(void *arg0, void *arg1) {
    ov01_022068C4[ov01_02209B64.callbackIndex](arg0, arg1);
    ov01_02209B64.callCount++;
    OS_GetTick();
    OS_SetTick(0);
}

void ov01_021EFB64(s32 value) {
    if (value >= 12 && value <= 33) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_115), OVY_LOAD_ASYNC);
        return;
    }
    if ((u32)(value - 34) <= 2) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_116), OVY_LOAD_ASYNC);
        return;
    }
    if (value >= 39 && value <= 44) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_117), OVY_LOAD_ASYNC);
        return;
    }
    if (value == 45) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_118), OVY_LOAD_ASYNC);
        return;
    }
    if (value >= 0 && value <= 5) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_120), OVY_LOAD_ASYNC);
        return;
    }
    if (value >= 6 && value <= 11) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_119), OVY_LOAD_ASYNC);
        return;
    }
    if (value == 46) {
        HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_120), OVY_LOAD_ASYNC);
        return;
    }
    HandleLoadOverlay(LOCAL_OVERLAY_ID(OVY_114), OVY_LOAD_ASYNC);
}

void ov01_021EFC04(s32 value) {
    if (value >= 12 && value <= 33) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_115));
        return;
    }
    if ((u32)(value - 34) <= 2) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_116));
        return;
    }
    if (value >= 39 && value <= 44) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_117));
        return;
    }
    if (value == 45) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_118));
        return;
    }
    if (value >= 0 && value <= 5) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_120));
        return;
    }
    if (value >= 6 && value <= 11) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_119));
        return;
    }
    if (value == 46) {
        UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_120));
        return;
    }
    UnloadOverlayByID(LOCAL_OVERLAY_ID(OVY_114));
}
