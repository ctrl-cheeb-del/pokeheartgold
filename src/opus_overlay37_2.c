#include "overlay_37_internal.h"

u32 ov37_021E5B94(void *manager, u32 *state) {
    Ov37Work *work;
    u32 *args;
    s32 i;
    work = OverlayManager_GetData(manager);
    args = OverlayManager_GetArgs(manager);
    switch (*state) {
    case 0:
        Main_SetVBlankIntrCB(NULL, NULL);
        SpriteTransfer_DeleteCharTransferTask(work->charTask0);
        SpriteTransfer_DeleteCharTransferTask(work->charTask1);
        SpriteTransfer_DeletePlttTransferTask(work->plttTask0);
        SpriteTransfer_DeletePlttTransferTask(work->plttTask1);
        for (i = 0; i < 4; i++) {
            Destroy2DGfxResObjMan(work->resObjMan[i]);
        }
        SpriteList_Delete(work->spriteList);
        OamManager_Free();
        ObjCharTransfer_Destroy();
        ObjPlttTransfer_Destroy();
        ov37_021E6540(work);
        ov37_021E5F5C(work->bgConfig);
        sub_02021238();
        DestroyMsgData(work->msgData);
        MessageFormat_Delete(work->msgFormat);
        (*state)++;
        break;
    case 1:
        sub_02038C1C(1);
        sub_02037FF0();
        sub_0205AD24(args[0]);
        *(volatile u16 *)0x04000304 |= 0x8000;
        sub_0205A904(0);
        sub_020356EC(0);
        (*state)++;
        break;
    case 2:
        if (work->unk_9400 != 0) {
            if (sub_02033250() == 1) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 3:
        sub_02038C1C(2);
        ov37_021E5F20(work);
        Heap_Free(work->args);
        OverlayManager_FreeData(manager);
        Main_SetVBlankIntrCB(NULL, NULL);
        Heap_Destroy(0x27);
        sub_02038C1C(2);
        return 1;
    }
    return 0;
}

void ov37_021E5CC8(void *bgConfig) {
    volatile u32 *a = (volatile u32 *)0x027e0000;
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(bgConfig);
    a[0x3ff8 / 4] |= 1;
}

void ov37_021E5CF0(void) {
    Ov37GraphicsBanks banks = ov37_021E7A24;
    GfGfx_SetBanks(&banks);
}

void ov37_021E5D10(void *bgConfig) {
    Ov37GraphicsModes modes;
    Ov37BgTemplate tA;
    Ov37BgTemplate tB;
    Ov37BgTemplate tC;
    Ov37BgTemplate tD;
    Ov37BgTemplate tE;
    modes = ov37_021E7978;
    SetBothScreensModesAndDisable(&modes);
    tA = ov37_021E7998;
    InitBgFromTemplate(bgConfig, 0, &tA, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    tB = ov37_021E79D0;
    InitBgFromTemplate(bgConfig, 1, &tB, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    tC = ov37_021E79EC;
    InitBgFromTemplate(bgConfig, 2, &tC, 0);
    tD = ov37_021E7A08;
    InitBgFromTemplate(bgConfig, 4, &tD, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    tE = ov37_021E79B4;
    InitBgFromTemplate(bgConfig, 5, &tE, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x27);
    BG_ClearCharDataRange(4, 0x20, 0, 0x27);
    BG_ClearCharDataRange(1, 0x20, 0, 0x27);
    BG_ClearCharDataRange(5, 0x20, 0, 0x27);
}

void ov37_021E5E30(Ov37Work *work) {
    s32 i;
    for (i = 0; i < 5; i++) {
        work->strbuf[i] = String_New(8, 0x27);
        ((Ov37Rec10 *)((u8 *)work + 0x438a))[i].flags &= ~0x38;
        work->unk_43B4[i].unk_02 = 0;
        work->pair[i].cur = 0;
        work->pair[i].prev = 0;
    }
    work->unk_0028 = String_New(0xa, 0x27);
    work->unk_002C = String_New(0x50, 0x27);
    work->unk_4376 = 0;
    work->unk_4377 = 1;
    work->unk_93F4 = 1;
    work->unk_93F8 = 0;
    work->unk_0318 = 2;
    work->unk_031C = sub_02033250();
    work->unk_93FC = 0;
    work->unk_9400 = 0;
    work->prevState = 0;
    work->unk_9404 = 0;
    work->unk_9408 = 0;
    sub_0203769C();
    ov37_021E7844(work, 4);
    ReadMsgDataIntoString(work->msgData, 7, work->unk_0028);
    work->unk_43C8 = Heap_Alloc(0x27, 0xf << 0xa);
    work->yesNoPrompt = YesNoPrompt_Create(0x27);
    work->unk_0314 = 0;
}
