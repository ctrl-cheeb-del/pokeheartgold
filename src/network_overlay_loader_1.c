#include "network_overlay_loader_internal.h"

BOOL LoadDwcOverlay(void) {
    return HandleLoadOverlay(FS_OVERLAY_ID(OVY_0), 2);
}

void UnloadDwcOverlay(void) {
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_0));
}

BOOL LoadOVY13(void) {
    return HandleLoadOverlay(FS_OVERLAY_ID(OVY_13), 2);
}

void UnloadOVY13(void) {
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_13));
}

void sub_020915F0(void *unused, void *args) {
    (void)unused;
    LoadDwcOverlay();
    LoadOVY13();
    ov13_0221BA00(args);
    UnloadOVY13();
    UnloadDwcOverlay();
    OS_ResetSystem(0);
}

BOOL LoadOVY38(void) {
    return HandleLoadOverlay(FS_OVERLAY_ID(OVY_38), 2);
}

void UnloadOVY38(void) {
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_38));
}

BOOL sub_02091634(void *manager, u32 *state) {
    void *args;
    (void)state;
    Heap_Create(3, 0x30, 0x41000);
    args = OverlayManager_GetArgs(manager);
    sub_020915F0(*(void **)((u8 *)args + 8), (void *)0x30);
    Heap_Destroy(0x30);
    OS_ResetSystem(0);
    return TRUE;
}
