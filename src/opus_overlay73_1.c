#include "overlay_73_internal.h"

int ov73_021E5900(OverlayManager *mgr, u32 *state) {
    Ov73Work *work;
    void *narc;
    switch (*state) {
    case 0:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(vu32 *)0x04000000 &= 0xFFFFE0FF;
        *(vu32 *)0x04001000 &= 0xFFFFE0FF;
        Heap_Create((enum HeapID)3, (enum HeapID)0x32, 0x41000);
        narc = NARC_New(0x54, 0x32);
        work = OverlayManager_CreateAndGetData(mgr, 0x4A8C, 0x32);
        memset(work, 0, 0x4A8C);
        work->bgConfig = BgConfig_Alloc((enum HeapID)0x32);
        work->args = OverlayManager_GetArgs(mgr);
        work->unk_4A0C = *(void **)work->args;
        work->menuState = MenuInputStateMgr_GetState(*(void **)((u8 *)work->args + 0x10));
        work->msgFmt = MessageFormat_New(0x32);
        work->msgData = NewMsgDataFromNarc(0, 0x1B, 0x1A6, 0x32);
        FontID_Alloc(4, 0x32);
        SetKeyRepeatTimers(4, 8);
        ov73_021E5D00();
        ov73_021E5D20(work->bgConfig);
        SetMasterBrightnessNeutral(0);
        SetMasterBrightnessNeutral(1);
        BeginNormalPaletteFade(0, 0x11, 0x11, 0, 0x10, 1, 0x32);
        ov73_021E5F38(work, narc);
        sub_020210BC();
        sub_02021148(2);
        Main_SetVBlankIntrCB((void (*)(void *))ov73_021E5CD8, work);
        ov73_021E5E0C(work, narc);
        ov73_021E6060();
        ov73_021E6090(work, narc);
        ov73_021E6184(work);
        ov73_021E629C(work, mgr);
        ov73_021E7230(work);
        Sound_SetSceneAndPlayBGM(0x34, 0, 0);
        *(vu16 *)0x04000304 &= 0xFFFF7FFF;
        sub_0208FB64(work);
        sub_0203893C();
        sub_02038C1C(3);
        if (!sub_0203769C()) {
            sub_0205A904(2);
        }
        sub_0203A880();
        ov73_021EA374(work->unk_4A0C, work->unk_388);
        work->task = SysTask_CreateOnVBlankQueue(ov73_021E5C74, work, 5);
        NARC_Delete(narc);
        (*state)++;
        break;
    case 1:
        OverlayManager_GetData(mgr);
        *state = 0;
        return 1;
    }
    return 0;
}
