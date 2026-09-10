#include "overlay_resource_actor_internal.h"

void sub_02075D08(void *task, Work *work) {
    sub_02075E14(work);
    if (work->overlayMan == 0) {
        PokepicManager_DrawAll(work->pokepicMgr);
        sub_020774E0();
        RequestSwap3DBuffers(1, 0);
    }
    if (work->done != 0) {
        SysTask_Destroy(task);
    }
}

BOOL sub_02075D3C(Work *work) {
    if (work->done == 1) {
        return 1;
    }
    return 0;
}

void sub_02075D4C(Work *work) {
    sub_0200FBF4(0, 0);
    sub_0200FBF4(1, 0);
    Main_SetVBlankIntrCB(0, 0);
    FontID_Release(4);
    sub_02075770(work);
    WindowArray_Delete(work->windows, 1);
    RemoveWindow(work->window1);
    RemoveWindow(work->window2);
    PaletteData_FreeBuffers(work->palette, 0);
    PaletteData_FreeBuffers(work->palette, 1);
    PaletteData_FreeBuffers(work->palette, 2);
    PaletteData_Free(work->palette);
    PokepicManager_Delete(work->pokepicMgr);
    sub_02016F2C(work->unk44);
    GF_3DVramMan_Delete(work->vramMan);
    sub_020771A0(work->bg);
    DestroyMsgData(work->msgData);
    MessageFormat_Delete(work->msgFmt);
    Heap_Free(work->string);
    Heap_Free(work->summaryArgs);
    sub_020164C4(work->unk58);
    Heap_Free(work->bg);
    NARC_Delete(*(void **)((u8 *)work + 0x84));
    Heap_Free(work);
    TextFlags_SetCanABSpeedUpPrint(0);
    TextFlags_SetCanTouchSpeedUpPrint(0);
    gSystem[0x69] = 1;
    GfGfx_SwapDisplay();
}
