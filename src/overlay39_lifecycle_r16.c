#include "overlay39_lifecycle_r16_private.h"

BOOL ov39_02228308(OverlayManager *manager, int *state) {
    Ov39R16App *app = OverlayManager_GetData(manager);
    BOOL result;
    u32 oldState;

    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished() == TRUE) {
            *state = 1;
        }
        break;
    case 1:
        oldState = app->state;
        result = ov39_0222AA20[oldState](app);
        if (oldState != app->state) {
            app->substate = 0;
            app->unk9C = 0;
            app->timer = 0;
        }
        if (result == TRUE) {
            *state = 2;
        }
        break;
    case 2:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov39_02228370(OverlayManager *manager) {
    Ov39R16App *app = OverlayManager_GetData(manager);

    if (app->sysTask != NULL) {
        SysTask_Destroy(app->sysTask);
        app->sysTask = NULL;
        app->unkAC = NULL;
    }
    DestroyMsgData(app->msgData2C);
    DestroyMsgData(app->msgData28);
    DestroyMsgData(app->msgData24);
    MessageFormat_Delete(app->messageFormat);
    String_Delete(app->string38);
    String_Delete(app->string3C);
    String_Delete(app->string34);
    ov39_02228948(app);
    Heap_Free(app->bgConfig);
    ov39_022285A8(app->bgConfig);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GF_DestroyVramTransferManager();
    sub_02021238();
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    sub_0203A914();
    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_124);
    gSystem.screensFlipped = 0;
    GfGfx_SwapDisplay();
    return TRUE;
}

void ov39_02228418(Ov39R16App *app) {
    vu32 *base = (vu32 *)0x027E0000;

    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(app->bgConfig);
    base[0x3FF8 / sizeof(u32)] |= 1;
}

void ov39_02228440(void *rawBgConfig) {
    BgConfig *bgConfig = rawBgConfig;
    GraphicsBanks banks;
    GraphicsModes modes;
    Ov39R16Templates mainTemplates;
    Ov39R16Templates subTemplates;

    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    banks = ov39_0222A8E4;
    GfGfx_SetBanks(&banks);
    MI_CpuClear32((void *)0x06000000, 0x80000);
    MI_CpuClear32((void *)0x06200000, 0x20000);
    MI_CpuClear32((void *)0x06400000, 0x40000);
    MI_CpuClear32((void *)0x06600000, 0x20000);
    modes = ov39_0222A8D4;
    SetBothScreensModesAndDisable(&modes);
    mainTemplates = ov39_0222A90C;
    InitBgFromTemplate(bgConfig, 0, &mainTemplates.templates[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    BgSetPosTextAndCommit(bgConfig, 0, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 0, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 1, &mainTemplates.templates[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    BgSetPosTextAndCommit(bgConfig, 1, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 1, BG_POS_OP_SET_Y, 0);
    subTemplates = ov39_0222A944;
    InitBgFromTemplate(bgConfig, 4, &subTemplates.templates[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    BgSetPosTextAndCommit(bgConfig, 4, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 4, BG_POS_OP_SET_Y, 0);
    InitBgFromTemplate(bgConfig, 5, &subTemplates.templates[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 5);
    BgSetPosTextAndCommit(bgConfig, 5, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 5, BG_POS_OP_SET_Y, 0);
    BG_ClearCharDataRange(0, 0x20, 0, HEAP_ID_124);
    BG_ClearCharDataRange(4, 0x20, 0, HEAP_ID_124);
}
