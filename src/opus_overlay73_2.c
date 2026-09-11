#include "overlay_73_internal.h"

int ov73_021E5BAC(OverlayManager *mgr, u32 *state) {
    Ov73Work *work = OverlayManager_GetData(mgr);
    s32 i;
    SysTask_Destroy(work->task);
    SpriteTransfer_DeleteCharTransferTask(work->charTransferTask);
    SpriteTransfer_DeletePlttTransferTask(work->plttTransferTask);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(work->resObjMan[i]);
    }
    SpriteList_Delete(work->spriteList);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    ov73_021E6400(work);
    ov73_021E6048(work);
    ov73_021E5F0C(work->bgConfig);
    sub_02038C1C(2);
    sub_02037FF0();
    sub_0205AD24(*(void **)((u8 *)work->args + 4));
    sub_02021238();
    FontID_Release(4);
    DestroyMsgData(work->msgData);
    MessageFormat_Delete(work->msgFmt);
    MenuInputStateMgr_SetState(*(void **)((u8 *)work->args + 0x10), work->menuState);
    ov73_021E5ED4(work);
    OverlayManager_FreeData(mgr);
    *(vu16 *)0x04000304 |= 0x8000;
    sub_0205A904(0);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy((enum HeapID)0x32);
    return 1;
}

void ov73_021E5C74(void *task, Ov73Work *work) {
    Ov73Anim *anim = (Ov73Anim *)&work->unk_0C;
    if (work->unk_0C) {
        if (anim->timer > ov73_021EA52A[anim->frame * 2]) {
            anim->timer = 0;
            anim->frame++;
            if (ov73_021EA52B[anim->frame * 2] == 0xFF) {
                anim->frame = 0;
            }
            GX_LoadOBJPltt(*(u8 **)((u8 *)anim->pltt + 0xC) + ov73_021EA52B[anim->frame * 2] * 0x20, 0, 0x20);
        } else {
            work->unk_14++;
        }
        ov73_021E72F4(work->unk_378);
    }
}

void ov73_021E5CD8(Ov73Work *work) {
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(work->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

void ov73_021E5D00(void) {
    GraphicsBanks banks = ov73_021EA5E8;
    GfGfx_SetBanks(&banks);
}

void ov73_021E5D20(BgConfig *bgConfig) {
    {
        GraphicsModes modes = ov73_021EA540;
        SetBothScreensModesAndDisable(&modes);
    }
    {
        BgTemplate template = ov73_021EA5B0;
        InitBgFromTemplate(bgConfig, 4, &template, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 4);
    }
    {
        BgTemplate template = ov73_021EA5CC;
        InitBgFromTemplate(bgConfig, 5, &template, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 5);
    }
    {
        BgTemplate template = ov73_021EA578;
        InitBgFromTemplate(bgConfig, 0, &template, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 0);
    }
    {
        BgTemplate template = ov73_021EA594;
        InitBgFromTemplate(bgConfig, 1, &template, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 1);
    }
    BG_ClearCharDataRange(0, 0x20, 0, (enum HeapID)0x32);
    BG_ClearCharDataRange(4, 0x20, 0, (enum HeapID)0x32);
}

void ov73_021E5E0C(Ov73Work *work, void *narc) {
    s32 i;
    for (i = 0; i < 5; i++) {
        work->strings[i] = String_New(8, 0x32);
        work->arr_338[i].a = 0;
        work->arr_338[i].b = 0;
        work->arr_4A3C[i].a = 0;
        work->arr_4A3C[i].b = 0;
        work->arr_4A3C[i].c = 0;
        work->arr_4A3C[i].d = 0;
        work->arr_360[i] = 0;
    }
    work->str44 = String_New(0xB4, 0x32);
    work->str48 = String_New(0x28, 0x32);
    work->unk_318 = 0;
    ReadMsgDataIntoString(work->msgData, 0x11, work->str48);
    ov73_021E7740(work, narc);
    work->unk_37C = sub_0205B4A4(0x32);
    work->unk_0C = 0;
    work->unk_14 = 0;
    work->unk_10 = 0;
    work->unk_18 = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 7, &work->unk_1C, 0x32);
    work->unk_4A18 = 0;
    work->unk_4A1C = 2;
    work->unk_4A15 = 0;
}

void ov73_021E5ED4(Ov73Work *work) {
    s32 i;
    ov73_021E77E8(work);
    Heap_Free(work->unk_18);
    Heap_Free(work->unk_37C);
    for (i = 0; i < 5; i++) {
        String_Delete(work->strings[i]);
    }
    String_Delete(work->str48);
    String_Delete(work->str44);
}
