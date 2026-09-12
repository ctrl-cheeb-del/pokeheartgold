#include "overlay41_lifecycle_r17_private.h"

void ov41_02246CC0(void *work, u32 heapId, u32 texSize, u32 plttSize) {
    u32 key;

    PTR_AT(work, 0x20) = PokepicManager_Create(heapId);
    U32_AT(work, 0x24) = NNS_GfdDefaultFuncAllocTexVram(texSize, FALSE, 0);
    U32_AT(work, 0x28) = NNS_GfdDefaultFuncAllocPlttVram(plttSize, FALSE, 1);

    key = U32_AT(work, 0x24);
    PokepicManager_SetCharBaseAddrAndSize(PTR_AT(work, 0x20), (key << 16) >> 13, ((key & 0x7FFF0000) >> 16) << 4);
    key = U32_AT(work, 0x28);
    PokepicManager_SetPlttBaseAddrAndSize(PTR_AT(work, 0x20), (key << 16) >> 13, ((key & 0xFFFF0000) >> 16) << 3);
    U32_AT(work, 0x2C) = 1;
}

void ov41_02246D2C(void *work) {
    PokepicManager_Delete(PTR_AT(work, 0x20));
    NNS_GfdDefaultFuncFreeTexVram(U32_AT(work, 0x24));
    NNS_GfdDefaultFuncFreePlttVram(U32_AT(work, 0x28));
    U32_AT(work, 0x2C) = 0;
}

void ov41_02246D54(void *work, u32 count1, u32 count2, u32 heapId) {
    u32 size = count1 * 8;
    PTR_AT(work, 0) = Heap_Alloc(heapId, size);
    memset(PTR_AT(work, 0), 0, size);
    PTR_AT(work, 0x10) = GF2dGfxRawResMan_Create(count1, heapId);
    U32_AT(work, 4) = count1;

    size = count2 * 12;
    PTR_AT(work, 8) = Heap_Alloc(heapId, size);
    memset(PTR_AT(work, 8), 0, size);
    PTR_AT(work, 0x14) = GF2dGfxRawResMan_Create(count2, heapId);
    U32_AT(work, 0xC) = count2;
}

void ov41_02246DA8(void *work) {
    if (PTR_AT(work, 0x10) != NULL) {
        GF2dGfxRawResObj_Destroy(PTR_AT(work, 0x10));
        PTR_AT(work, 0x10) = NULL;
    }
    if (PTR_AT(work, 0x14) != NULL) {
        GF2dGfxRawResObj_Destroy(PTR_AT(work, 0x14));
        PTR_AT(work, 0x14) = NULL;
    }
    Heap_Free(PTR_AT(work, 0));
    PTR_AT(work, 0) = NULL;
    Heap_Free(PTR_AT(work, 8));
    PTR_AT(work, 8) = NULL;
}

BOOL ov41_02246DE0(void *manager, int *state) {
    void *work;
    void *args;

    Heap_Create(3, 13, 0x20000);
    Heap_Create(3, 14, 0x40000);
    work = OverlayManager_CreateAndGetData(manager, 0x6F0, 13);
    memset(work, 0, 0x6F0);
    Main_SetVBlankIntrCB(ov41_02247478, work);
    HBlankInterruptDisable();
    args = OverlayManager_GetArgs(manager);
    PTR_AT(work, 0x6DC) = PTR_AT(args, 0xC);
    if (PTR_AT(args, 0x20) != NULL) {
        U32_AT(work, 0x6EC) = MenuInputStateMgr_GetState(PTR_AT(args, 0x20));
    } else {
        U32_AT(work, 0x6EC) = 0;
    }
    sub_020210BC();
    sub_02021148(4);
    ov41_02248E84(PTR_AT(args, 8), (u8 *)work + 0x184);
    ov41_02247240(work);
    ov41_022499B4((u8 *)work + 0x35C, 0x35C - 0x8D, 13);
    PTR_AT(work, 0x364) = ov41_02245EA0(0x2BC, 13);
    ov41_02247288(work, PTR_AT(args, 0), 10, 0);
    ov41_02247334(work);
    ov41_02247480(work, 0);
    ov41_022474D4(work);
    ov41_0224765C(work, PTR_AT(args, 0xC));
    ov41_02248F18((u8 *)work + 0x498, (u8 *)work + 0x3F4, (u8 *)work + 0x368, work, (u8 *)work + 0x568, 1);
    PTR_AT(work, 0x6B8) = YesNoPrompt_Create(13);
    PTR_AT(work, 0x6BC) = AllocWindows(13, 1);
    U32_AT(work, 0x6B0) = 0;
    Sound_SetSceneAndPlayBGM(0x35, 0, 0);
    return TRUE;
}

BOOL ov41_02246F08(void *manager, int *state) {
    void *work = OverlayManager_GetData(manager);
    BOOL done = FALSE;
    void *args = OverlayManager_GetArgs(manager);

    switch (*state) {
    case 0:
    case 1:
        BeginNormalPaletteFade(1, 5, 5, 0, 6, 1, 13);
        *state = 2;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case 3:
        if (U32_AT(args, 0x1C) == 1) {
            TextFlags_SetCanTouchSpeedUpPrint(1);
            U32_AT(work, 0x6E0) = ov41_0224AC40((u8 *)work + 0x568, 0x1B, 0xD7, 0x2F);
            (*state)++;
        } else {
            *state = 6;
        }
        break;
    case 4:
        if (!TextPrinterCheckActive((u8)U32_AT(work, 0x6E0))) {
            ov41_0224AC80((u8 *)work + 0x568);
            (*state)++;
        }
        break;
    case 5:
        if (((U32_AT(&gSystem, 0x48) & 3) | U16_AT(&gSystem, 0x64)) != 0) {
            ov41_0224AC08((u8 *)work + 0x568, 0x1B, 0xD7, 0x30);
            TextFlags_SetCanTouchSpeedUpPrint(0);
            (*state)++;
        }
        break;
    case 6:
        if (U32_AT(work, 0x6B0) == 3) {
            ov41_022476B8(work, (u8 *)work + 0x6B4);
            *state = 7;
        }
        ov41_02248E44((u8 *)work + 0x498);
        ov41_02247D44(work);
        ov41_0224ABF0((u8 *)work + 0x568);
        ov41_02247578(work);
        break;
    case 7:
        if (U32_AT(work, 0x6B4) != 0) {
            U32_AT(work, 0x6B4) = 0;
            *state = 8;
            U32_AT(work, 0x6B0) = 4;
            ov41_0224B4E8((u8 *)work + 0x47C, (u8 *)work + 0x3F4, 14);
        }
        break;
    case 8:
        if (U32_AT(work, 0x6B0) == 9) {
            ov41_02247828(work, (u8 *)work + 0x6B4);
            *state = 10;
        } else if (U32_AT(work, 0x6B0) == 8) {
            *state = 9;
            U32_AT(work, 0x6B0) = 5;
            ov41_02247D64(work);
        } else {
            U32_AT(work, 0x6B0) = ov41_02247B7C(work);
            ov41_0224B50C((u8 *)work + 0x47C);
        }
        break;
    case 9:
        if (U32_AT(work, 0x6B0) == 6) {
            U32_AT(work, 0x6C0) = 1;
            *state = 11;
        } else if (U32_AT(work, 0x6B0) == 7) {
            U32_AT(work, 0x6C0) = 0;
            *state = 11;
        } else {
            U32_AT(work, 0x6B0) = ov41_02247DF8(work);
            ov41_0224B50C((u8 *)work + 0x47C);
        }
        break;
    case 10:
        if (U32_AT(work, 0x6B4) != 0) {
            U32_AT(work, 0x6B4) = 0;
            *state = 6;
            U32_AT(work, 0x6B0) = 0;
            ov41_0224B518((u8 *)work + 0x47C);
        }
        break;
    case 11:
        BeginNormalPaletteFade(1, 0, 0, 0, 6, 1, 13);
        (*state)++;
        break;
    case 12:
        if (IsPaletteFadeFinished()) {
            *state = 0;
            U32_AT(work, 0x6B0) = 10;
            done = TRUE;
            ov41_0224B518((u8 *)work + 0x47C);
        }
        break;
    }
    ov41_0224726C(work);
    return done;
}

BOOL ov41_02247150(void *manager, int *state) {
    void *work = OverlayManager_GetData(manager);
    void *args = OverlayManager_GetArgs(manager);

    if (U32_AT(work, 0x6C0) == 1) {
        GameStats_AddScore(PTR_AT(args, 0x10), 8);
        ov41_022479A8(PTR_AT(args, 4), (u8 *)work + 0x3F4, PTR_AT(args, 0x14));
    }
    if (PTR_AT(args, 0x18) != NULL) {
        if (U32_AT(work, 0x6C0) == 1) {
            U32_AT(PTR_AT(args, 0x18), 0) = 1;
        } else {
            U32_AT(PTR_AT(args, 0x18), 0) = 0;
        }
    }
    if (PTR_AT(args, 0x20) != NULL) {
        MenuInputStateMgr_SetState(PTR_AT(args, 0x20), U32_AT(work, 0x6EC));
    }
    YesNoPrompt_Destroy(PTR_AT(work, 0x6B8));
    WindowArray_Delete(PTR_AT(work, 0x6BC), 1);
    ov41_022476A8(work);
    ov41_02248F6C((u8 *)work + 0x498);
    ov41_02247568(work);
    ov41_022474C4(work);
    ov41_02247310(work);
    ov41_022473F0(work);
    ov41_02245ECC(PTR_AT(work, 0x364));
    PTR_AT(work, 0x364) = NULL;
    ov41_022499DC((u8 *)work + 0x35C);
    ov41_02247274(work);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    if (sub_02021238() != 1) {
        GF_AssertFail();
    }
    OverlayManager_FreeData(manager);
    Heap_Destroy(13);
    Heap_Destroy(14);
    return TRUE;
}

void ov41_02247240(void *work) {
    u8 data[0x18];

    ov41_02246130(work);
    ov41_02246170(work);
    ov41_022463B0(work, data);
    ov41_02246250(work, data);
    ov41_022463D4(data);
}
