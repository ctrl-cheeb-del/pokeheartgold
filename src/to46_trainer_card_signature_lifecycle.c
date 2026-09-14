#include "trainer_card_signature_internal.h"

typedef int (*TrainerCardSignatureStateFunc)(void *, int);
typedef struct TrainerCardSignatureWork {
    u8 pad_000[0x3c];
    void *spriteList;
    u8 pad_040[0x30c - 0x40];
    u32 activeState;
    u8 pad_310[0x4318 - 0x310];
    u16 angle;
} TrainerCardSignatureWork;

extern const TrainerCardSignatureStateFunc ov52_021E96C0[];
int TrainerCardSignature_Exit(void *manager, int *state);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void Destroy2DGfxResObjMan(void *);
extern int SpriteList_Delete(void *);
extern void OamManager_Free(void);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void FontID_Release(int);
extern int sub_02021238(void);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void Heap_Destroy(int);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
extern void TextFlags_SetCanABSpeedUpPrint(int);
extern void OverlayManager_FreeData(void *);
int TrainerCardSignature_Init(void *manager, int *state);
extern void sub_0200FBF4(int, int);
extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void Heap_Create(int, int, u32);
extern void *OverlayManager_CreateAndGetData(void *, u32, int);
extern void *BgConfig_Alloc(int);
extern void *NARC_New(int, int);
extern void *MessageFormat_New(int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void SetKeyRepeatTimers(int, int);
extern void ov52_021E83C4(void *);
extern void *OverlayManager_GetArgs(void *);
extern void *Save_TrainerCard_Get(void *);
extern void *TrainerCard_GetSignature(void *);
extern void *Save_GameStats_Get(void *);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void ov52_021E85DC(void *, void *);
extern void sub_020210BC(void);
extern void sub_02021148(int);
extern void ov52_021E84CC(void *);
extern void ov52_021E870C(void *, void *);
extern void ov52_021E888C(void *);
extern void ov52_021E89D4(void *, void *);
extern void Sound_SetSceneAndPlayBGM(int, int, int);
extern void NARC_Delete(void *);
extern void *memset(void *, int, u32);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void FontID_Alloc(int, int);

int TrainerCardSignature_Init(void *manager, int *state) {
    void *work;
    void *narc;

    switch (*state) {
    case 0:
        sub_0200FBF4(0, 0);
        sub_0200FBF4(1, 0);
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(vu32 *)0x04000000 &= 0xffffe0ff;
        *(vu32 *)0x04001000 &= 0xffffe0ff;
        Heap_Create(3, 0x27, 0x40000);
        work = OverlayManager_CreateAndGetData(manager, 0x5cb0, 0x27);
        memset(work, 0, 0x5cb0);
        PTR(work, 0) = BgConfig_Alloc(0x27);
        narc = NARC_New(0x5b, 0x27);
        PTR(work, 0x10) = MessageFormat_New(0x27);
        PTR(work, 0x14) = NewMsgDataFromNarc(0, 0x1b, 0xfc, 0x27);
        TextFlags_SetCanTouchSpeedUpPrint(TRUE);
        TextFlags_SetCanABSpeedUpPrint(TRUE);
        SetKeyRepeatTimers(4, 8);
        ov52_021E83A4();
        ov52_021E83C4(PTR(work, 0));
        BeginNormalPaletteFade(0, 1, 1, 0, 0x10, 1, 0x27);
        PTR(work, 0x5b98) = TrainerCard_GetSignature(Save_TrainerCard_Get(OverlayManager_GetArgs(manager)));
        PTR(work, 8) = Save_GameStats_Get(OverlayManager_GetArgs(manager));
        PTR(work, 0xc) = Save_PlayerData_GetOptionsAddr(OverlayManager_GetArgs(manager));
        ov52_021E85DC(work, narc);
        sub_020210BC();
        sub_02021148(1);
        Main_SetVBlankIntrCB(ov52_021E837C, PTR(work, 0));
        FontID_Alloc(2, 0x27);
        ov52_021E84CC(work);
        ov52_021E86DC();
        ov52_021E870C(work, narc);
        ov52_021E888C(work);
        ov52_021E89D4(work, manager);
        Sound_SetSceneAndPlayBGM(0x38, 0, 0);
        *(vu16 *)0x04000304 &= 0xffff7fff;
        NARC_Delete(narc);
        (*state)++;
        break;
    case 1:
        OverlayManager_GetData(manager);
        *state = 0;
        return TRUE;
    }
    return FALSE;
}

int TrainerCardSignature_Main(void *manager, int *state) {
    TrainerCardSignatureStateFunc func;
    TrainerCardSignatureWork *work = OverlayManager_GetData(manager);

    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        break;
    case 1: {
        func = ov52_021E96C0[work->activeState];
        if (func != NULL) {
            *state = func(work, *state);
        }
        ov52_021E921C(&work->angle);
        break;
    }
    case 2:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }

    SpriteList_RenderAndAnimateSprites(work->spriteList);
    return FALSE;
}

int TrainerCardSignature_Exit(void *manager, int *state) {
    void *work = OverlayManager_GetData(manager);
    int i;
    u8 *walker;

    ov52_021E9300(PTR(work, 0x5b98), PTR(work, 0x2d0));
    Main_SetVBlankIntrCB(NULL, NULL);
    SpriteTransfer_DeleteCharTransferTask(PTR(work, 0x178));
    SpriteTransfer_DeleteCharTransferTask(PTR(work, 0x188));
    SpriteTransfer_DeletePlttTransferTask(PTR(work, 0x17c));
    SpriteTransfer_DeletePlttTransferTask(PTR(work, 0x18c));

    i = 0;
    walker = work;
    for (; i < 4; i++, walker += 4) {
        Destroy2DGfxResObjMan(PTR(walker, 0x168));
    }

    SpriteList_Delete(PTR(work, 0x3c));
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    ov52_021E8B94(work);
    FontID_Release(2);
    ov52_021E85A0(PTR(work, 0));
    sub_02021238();
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    DestroyMsgData(PTR(work, 0x14));
    MessageFormat_Delete(PTR(work, 0x10));
    ov52_021E8568(work);
    OverlayManager_FreeData(manager);
    *(vu16 *)0x04000304 |= (u16)((u32)0x04000304 >> 11);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(0x27);
    return TRUE;
}
