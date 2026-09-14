#include "to46_overlay27_r17_private.h"

void ov27_0225C434(SysTask *task, Ov27R17TaskState *state) {
    if (!FieldSystem_TaskIsRunning((FieldSystem *)state->fieldSystem)) {
        if (state->fieldSystem->taskState == 2) {
            state->fieldSystem->taskState = 3;
        }
        *(vu16 *)0x04001050 = 0;
    } else if (ov27_0225D4D4[state->state](state) == TRUE) {
        state->fieldSystem->taskState = 0;
        ov01_021F6A9C((FieldSystem *)state->fieldSystem, 0, NULL);
    }
    SpriteList_RenderAndAnimateSprites(state->spriteList);
}

void ov27_0225C4AC(Ov27R17Work *work) {
    NNSG2dScreenData *screenData;
    void *screenRaw;
    NARC *narc = NARC_New(NARC_a_2_3_7, HEAP_ID_8);

    *(vu16 *)0x04001050 = 0;
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0xA0, HEAP_ID_8);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, HEAP_ID_8);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 9, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, HEAP_ID_8);
    screenRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 9, FALSE, &screenData, HEAP_ID_8);
    BG_LoadScreenTilemapData(work->bgConfig, GF_BG_LYR_SUB_2, screenData->rawData, screenData->szByte);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, GF_BG_LYR_SUB_2);
    Heap_Free(screenRaw);
    NARC_Delete(narc);
}

void ov27_0225C540(Ov27R17Work *work) {
    NARC *narc = NARC_New(NARC_a_2_3_7, HEAP_ID_8);

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, HEAP_ID_8);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, HEAP_ID_8);
    NARC_Delete(narc);
    AddWindowParameterized(work->bgConfig, &work->window28, GF_BG_LYR_SUB_1, 12, 8, 8, 2, 4, 0x80);
    AddWindowParameterized(work->bgConfig, &work->window38, GF_BG_LYR_SUB_1, 12, 14, 8, 2, 4, 0x90);
    ov27_0225C8D0(&work->window28, work->msgData, 46);
    ov27_0225C8D0(&work->window38, work->msgData, 47);
}
