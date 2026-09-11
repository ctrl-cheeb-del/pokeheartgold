#include "overlay_37_internal.h"

u32 ov37_021E5900(void *manager, u32 *state) {
    Ov37Work *work;
    void *narc;
    switch (*state) {
    case 0:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(volatile u32 *)0x04000000 &= 0xffffe0ff;
        *(volatile u32 *)0x04001000 &= 0xffffe0ff;
        Heap_Create(3, 0x27, 0x40000);
        work = OverlayManager_CreateAndGetData(manager, 0x940c, 0x27);
        memset(work, 0, 0x940c);
        work->bgConfig = BgConfig_Alloc(0x27);
        work->msgFormat = MessageFormat_New(0x27);
        work->msgData = NewMsgDataFromNarc(0, 0x1b, 0xfc, 0x27);
        SetKeyRepeatTimers(4, 8);
        ov37_021E5CF0();
        ov37_021E5D10(work->bgConfig);
        sub_0200FBF4(0, 0);
        sub_0200FBF4(1, 0);
        BeginNormalPaletteFade(0, 0x11, 0x11, 0, 0x10, 1, 0x27);
        work->args = OverlayManager_GetArgs(manager);
        narc = NARC_New(0x4e, 0x27);
        ov37_021E5F98(work, narc);
        sub_020210BC();
        sub_02021148(2);
        Main_SetVBlankIntrCB(ov37_021E5CC8, work->bgConfig);
        ov37_021E5E30(work);
        ov37_021E6090();
        ov37_021E60C0(work, narc);
        ov37_021E6244(work);
        ov37_021E6418(work, manager);
        Sound_SetSceneAndPlayBGM(0x34, 0, 0);
        *(volatile u16 *)0x04000304 &= 0xffff7fff;
        sub_0208F814(work);
        sub_020398D4(0, 1);
        if (sub_0203769C() == 0) {
            sub_02038C1C(3);
        }
        sub_0203A880();
        if (sub_0203769C() == 0) {
            sub_0205A904(1);
            sub_020356EC(1);
        }
        NARC_Delete(narc);
        (*state)++;
        break;
    case 1:
        OverlayManager_GetData(manager);
        *state = 0;
        return 1;
    }
    return 0;
}
