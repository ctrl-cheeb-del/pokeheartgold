#include "config.h"
#include "overlay45_bootstrap_r14_internal.h"

BOOL ov45_02229EE0(void *manager) {
    Ov45BaseState *state;
    Ov45Args *args;
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_42), 2);
    LoadDwcOverlay();
    LoadOVY38();
    sub_02039FD8(3);
    Heap_Create(3, 0x6f, 0x5000);
    state = OverlayManager_CreateAndGetData(manager, 0x10, 0x6f);
    {
        u8 *dst = state->data;
        u32 count = 0x10;
        do {
            *dst++ = 0;
            count--;
        } while (count != 0);
    }
    args = OverlayManager_GetArgs(manager);
    {
        void *owner = args->unk4;
        PTR(state, 0) = owner;
        PTR(state, 4) = ov45_02229FF4(owner, 0x6f);
    }
    PTR(state, 8) = ov45_0222CD1C(args->unk8, args->unk4, args->unk0, PTR(state, 4), 0x6f);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    PTR(state, 0xc) = SysTask_CreateOnVWaitQueue(ov45_02229FE0, state, 0);
    ov45_0222CD84(PTR(state, 8));
    return TRUE;
}

BOOL ov45_02229F70(void *manager) {
    Ov45BaseState *state = OverlayManager_GetData(manager);
    int done = ov45_0222CD90(PTR(state, 8));
    ov45_0222A15C(PTR(state, 4));
    if (done == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov45_02229F94(void *manager) {
    Ov45BaseState *state;
    void *saved = manager;
    state = OverlayManager_GetData(manager);
    SysTask_Destroy(PTR(state, 0xc));
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    ov45_0222CD68(PTR(state, 8));
    ov45_0222A0F0(PTR(state, 4));
    OverlayManager_FreeData(saved);
    Heap_Destroy(0x6f);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_42));
    UnloadOVY38();
    UnloadDwcOverlay();
    return TRUE;
}

void ov45_02229FE0(void *task, void *state) {
    ov45_0222CDC0(PTR(state, 8));
    ov45_0222A1F8(PTR(state, 4));
}
