#include "field_ui_overlay_controller_internal.h"

int sub_020850F4(void *overlayManager) {
    SummaryAppData *data;

    Heap_Create(HEAP_ID_3, HEAP_ID_108, 0x40000);
    data = OverlayManager_CreateAndGetData(overlayManager, sizeof(SummaryAppData), HEAP_ID_108);
    memset(data, 0, sizeof(SummaryAppData));
    data->args = *OverlayManager_GetArgs(overlayManager);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(vu32 *)0x04000000 &= 0xFFFFE0FF;
    *(vu32 *)0x04001000 &= 0xFFFFE0FF;
    data->narc = NARC_New(0xBE, HEAP_ID_108);
    data->bgConfig = BgConfig_Alloc(HEAP_ID_108);
    data->paletteData = PaletteData_Init(HEAP_ID_108);
    PaletteData_SetAutoTransparent(data->paletteData, TRUE);
    PaletteData_AllocBuffers(data->paletteData, 0, 0x200, HEAP_ID_108);
    PaletteData_AllocBuffers(data->paletteData, 1, 0x200, HEAP_ID_108);
    PaletteData_AllocBuffers(data->paletteData, 2, 0x200, HEAP_ID_108);
    PaletteData_AllocBuffers(data->paletteData, 3, 0x200, HEAP_ID_108);
    sub_0208545C(data->bgConfig);
    sub_020863F4(data);
    sub_02085688(data);
    sub_020210BC();
    sub_02021148(4);
    sub_020860B8(data);
    if (data->args.words[12] != 0) {
        sub_0203A880((void *)data->args.words[12]);
        sub_0203A948(1, HEAP_ID_108);
    }
    G2x_SetBlendAlpha_(0x04000050, 0, 6, 0xF, 7);
    G2x_SetBlendAlpha_(0x04001050, 0, 0xE, 7, 8);
    Main_SetVBlankIntrCB((void (*)(void *))sub_020855CC, data);
    return TRUE;
}

int sub_0208524C(void *overlayManager) {
    SummaryAppData *data = OverlayManager_GetData(overlayManager);
    BOOL done = sub_02085BEC(data);

    if (data->args.words[12] != 0) {
        sub_0203A930(3 - ov00_021EC9D4((void *)data->args.words[12]));
    }
    if (done != FALSE) {
        return TRUE;
    }
    return FALSE;
}

int sub_0208527C(void *overlayManager) {
    SummaryAppData *data = OverlayManager_GetData(overlayManager);

    if (data->args.words[12] != 0) {
        sub_0203A914((void *)data->args.words[12]);
    }
    sub_020866CC(data);
    GfGfx_EngineATogglePlanes(1, FALSE);
    GfGfx_EngineATogglePlanes(2, FALSE);
    GfGfx_EngineATogglePlanes(4, FALSE);
    GfGfx_EngineATogglePlanes(8, FALSE);
    GfGfx_EngineBTogglePlanes(1, FALSE);
    GfGfx_EngineBTogglePlanes(2, FALSE);
    GfGfx_EngineBTogglePlanes(4, FALSE);
    GfGfx_EngineBTogglePlanes(8, FALSE);
    FreeBgTilemapBuffer(data->bgConfig, 1);
    FreeBgTilemapBuffer(data->bgConfig, 2);
    FreeBgTilemapBuffer(data->bgConfig, 3);
    FreeBgTilemapBuffer(data->bgConfig, 4);
    FreeBgTilemapBuffer(data->bgConfig, 5);
    FreeBgTilemapBuffer(data->bgConfig, 6);
    FreeBgTilemapBuffer(data->bgConfig, 7);
    Heap_Free(data->bgConfig);
    PaletteData_FreeBuffers(data->paletteData, 0);
    PaletteData_FreeBuffers(data->paletteData, 1);
    PaletteData_FreeBuffers(data->paletteData, 2);
    PaletteData_FreeBuffers(data->paletteData, 3);
    PaletteData_Free(data->paletteData);
    NARC_Delete(data->narc);
    sub_02021238();
    SpriteSystem_FreeResourcesAndManager(data->spriteSystem, data->spriteManager);
    SpriteSystem_Free(data->spriteSystem);
    TouchHitboxController_Destroy(data->touchController);
    OverlayManager_FreeData(overlayManager);
    Heap_Destroy(HEAP_ID_108);
    return TRUE;
}

SummaryStringData *sub_020853B4(enum HeapID heapId, u32 length, const u32 *values, u32 param20, u32 param2C, u32 param30) {
    SummaryStringData *data = Heap_Alloc(heapId, sizeof(SummaryStringData));
    int i;

    data->length = length;
    data->string = String_New(length + 1, heapId);
    data->param20 = param20;
    for (i = 0; i < 4; i++) {
        data->values[i] = values[i];
    }
    data->values[i] = values[i - 1];
    data->param2C = param2C;
    data->param30 = param30;
    return data;
}

SummaryStringData *sub_02085400(enum HeapID heapId, u32 length, const u32 *values, u32 param20, u32 param2C, u32 param30) {
    SummaryStringData *data = sub_020853B4(heapId, length, values, param20, param2C, param30);
    data->param24 = 0;
    data->param28 = 0;
    return data;
}

SummaryStringData *sub_0208541C(enum HeapID heapId, u32 length, const u32 *values, u32 param20, u32 param2C, u32 param30, u32 param24, u32 param28) {
    SummaryStringData *data = sub_020853B4(heapId, length, values, param20, param2C, param30);
    data->param24 = param24;
    data->param28 = param28;
    return data;
}

void sub_02085438(SummaryStringData *data) {
    if (data->string == NULL) {
        GF_AssertFail();
    }
    if (data == NULL) {
        GF_AssertFail();
    }
    String_Delete(data->string);
    Heap_Free(data);
}

void sub_0208545C(void *bgConfig) {
    SummaryGfxBanks banks;
    SummaryBgTemplates3 engineA;
    SummaryBgTemplates4 engineB;

    GfGfx_DisableEngineAPlanes();
    banks = _02102630;
    GfGfx_SetBanks(&banks);
    MIi_CpuClear32(0, (u32 *)0x06000000, 0x80000);
    MIi_CpuClear32(0, (u32 *)0x06200000, 0x20000);
    MIi_CpuClear32(0, (u32 *)0x06400000, 0x40000);
    MIi_CpuClear32(0, (u32 *)0x06600000, 0x20000);
    engineA = _02102658;
    InitBgFromTemplate(bgConfig, 1, &engineA.items[0], 0);
    InitBgFromTemplate(bgConfig, 2, &engineA.items[1], 0);
    InitBgFromTemplate(bgConfig, 3, &engineA.items[2], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    GfGfx_EngineATogglePlanes(1, FALSE);
    GfGfx_EngineATogglePlanes(2, TRUE);
    GfGfx_EngineATogglePlanes(4, FALSE);
    GfGfx_EngineATogglePlanes(8, FALSE);
    engineB = _021026AC;
    InitBgFromTemplate(bgConfig, 4, &engineB.items[0], 0);
    InitBgFromTemplate(bgConfig, 5, &engineB.items[1], 0);
    InitBgFromTemplate(bgConfig, 6, &engineB.items[2], 0);
    InitBgFromTemplate(bgConfig, 7, &engineB.items[3], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    BgClearTilemapBufferAndCommit(bgConfig, 5);
    BgClearTilemapBufferAndCommit(bgConfig, 6);
    BgClearTilemapBufferAndCommit(bgConfig, 7);
    GfGfx_EngineBTogglePlanes(1, TRUE);
    GfGfx_EngineBTogglePlanes(2, TRUE);
    GfGfx_EngineBTogglePlanes(4, FALSE);
    GfGfx_EngineBTogglePlanes(8, FALSE);
    gSystem.screensFlipped = TRUE;
    GfGfx_SwapDisplay();
    GfGfx_EngineATogglePlanes(0x10, TRUE);
    GfGfx_EngineBTogglePlanes(0x10, TRUE);
}

void sub_020855CC(SummaryAppData *data) {
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    PaletteData_PushTransparentBuffers(data->paletteData);
    DoScheduledBgGpuUpdates(data->bgConfig);
    *(u32 *)((u8 *)OS_IRQTable + 0x3FF8) |= 1;
}
