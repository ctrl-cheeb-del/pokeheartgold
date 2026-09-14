#include "overlay41_accessory_portrait_r4_private.h"

void ov41_0224B8F0(Ov41AccessoryList *list, SaveFashionDataSub *fashionData) {
    int i;

    list->mon = sub_0202BE14(fashionData);
    list->count = 0;
    for (i = 0; i < 10; i++) {
        if (sub_0202BDEC(fashionData, i)) {
            list->items[list->count] = sub_0202BE2C(fashionData, i);
            list->count++;
        }
    }
    list->background = sub_0202BE80(fashionData);
}

void ov41_0224B938(Ov41Work *work, Ov41GfxManagers *managers, Ov41AccessoryList *list, enum HeapID heapId) {
    ov41_022464AC(managers, heapId);
    ov41_0224B958(work, managers, list, heapId);
}

void ov41_0224B958(Ov41Work *work, Ov41GfxManagers *managers, Ov41AccessoryList *list, enum HeapID heapId) {
    int i;
    int id;
    void *raw;

    for (i = 0; i < list->count; i++) {
        id = sub_0202BEFC(list->items[i]);
        if (GF2dGfxRawResMan_DoesNotHaveObjWithId(managers->charManager, id) == TRUE) {
            raw = GfGfxLoader_LoadFromOpenNarc(work->narc, id + 1, FALSE, heapId, TRUE);
            GF2dGfxRawResMan_AllocObj(managers->charManager, raw, id);
            NNS_G2dGetUnpackedCharacterData(raw, &managers->charEntries[id].unpacked);
            managers->charEntries[id].owner = work->fashionData;
        }
    }
    raw = GfGfxLoader_LoadFromOpenNarc(work->narc, 0, FALSE, heapId, TRUE);
    GF2dGfxRawResMan_AllocObj(managers->paletteManager, raw, 0);
    NNS_G2dGetUnpackedPaletteData(raw, &managers->paletteEntry->unpacked);
    managers->paletteEntry->owner = work->fashionData;
    managers->paletteEntry->mode = 3;
}

BOOL AccessoryPortrait_Init(OverlayManager *man, int *state) {
    Ov41Work *work;
    FashionAppData *args;
    Ov41PortraitConfig config;

    Heap_Create((enum HeapID)3, HEAP_ID_13, 0x20000);
    Heap_Create((enum HeapID)3, HEAP_ID_14, 0x40000);
    work = OverlayManager_CreateAndGetData(man, sizeof(Ov41Work), HEAP_ID_13);
    memset(work, 0, sizeof(Ov41Work));
    Main_SetVBlankIntrCB(ov41_0224BBF0, work);
    HBlankInterruptDisable();
    args = OverlayManager_GetArgs(man);
    work->fashionData = sub_0202B9B8(args->saveFashionData, args->unk_4);
    work->selection = args->unk_4;
    work->mode = args->unk_8;
    ov41_02246130();
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    ov41_02246670(work->gfx, HEAP_ID_14);
    config.value = *(u32 *)&work->gfx[0x40];
    config.x = 0x48;
    config.y = 0x10;
    config.heapId = HEAP_ID_14;
    work->portrait = ov41_0224B530(&config, work->fashionData);
    ov41_0224BC04(work);
    ov41_0224BCA4(work);
    ov41_0224BCF0(work);
    ov41_0224BDCC(work);
    ov41_0224BE5C(work);
    return TRUE;
}

BOOL AccessoryPortrait_Main(OverlayManager *man, int *state) {
    Ov41Work *work = OverlayManager_GetData(man);

    Thunk_G3X_Reset();
    NNS_G2dSetupSoftwareSpriteCamera();
    ov41_0224B554(work->portrait);
    RequestSwap3DBuffers(0, 0);
    ov41_022466C8(work->gfx);
    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)5, (enum FadeType)1, 0, 6, 1, HEAP_ID_13);
        (*state)++;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case 3:
        if ((gSystem.newKeys & 3) || System_GetTouchNew()) {
            PlaySE(0x5DD);
            (*state)++;
        }
        break;
    case 4:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)2, (enum FadeType)0, 0, 6, 1, HEAP_ID_13);
        (*state)++;
        break;
    case 5:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL AccessoryPortrait_Exit(OverlayManager *man, int *state) {
    Ov41Work *work = OverlayManager_GetData(man);

    ov41_0224B57C(work->portrait);
    ov41_0224BD8C(work);
    ov41_0224BE34(work);
    ov41_02246698(work->gfx);
    ov41_02246150();
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_13);
    Heap_Destroy(HEAP_ID_14);
    return TRUE;
}
