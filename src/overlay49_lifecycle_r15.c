#include "global.h"

#include "heap.h"
#include "overlay_manager.h"
#include "system.h"

#pragma require_prototypes off

typedef struct Ov49Interpolation15 {
    u8 active;
    u8 value;
    s8 start;
    s8 delta;
    s16 frame;
    s16 duration;
} Ov49Interpolation15;

typedef struct Ov49Args15 {
    u8 pad00[0x18];
    u32 result;
} Ov49Args15;

typedef struct Ov49Work15 {
    u8 eventDone;
    u8 result;
    u8 pad002;
    u8 fading;
    u8 mode : 4;
    u8 exitMode : 4;
    u8 pad005;
    u8 exitRequested;
    u8 suppressExit;
    s32 timer;
    u8 pad00C[0x28];
    void *owner;
    void *state38;
    u8 pad03C[0x3BC];
} Ov49Work15;

extern void ov45_02230700(void *, u8);
extern void ov49_02268850(void *);
extern void ov49_0226535C(void *);
extern void ov49_0225EEF8(void *);
extern void ov49_0225B4E4(void *, void *, void *);
extern void ov49_0225B35C(void *);
extern void ov49_0225AB14(void *);
extern void ov49_0225ACBC(void *);
extern void ov49_0225AE4C(void *, void *);
extern void ov49_0225B244(void *);
extern void ov49_0225B200(void *);
extern void ov49_0225B0D8(void *);
extern void ov49_0225CBDC(void *);
extern void ov49_0225E2B4(void *);
extern void ov49_02258B20(void *);
extern void ov49_02258994(void *);
extern void ov49_0225A7D0(void *);
extern void sub_0200616C(u32);
extern void sub_02006300(u32);
extern u32 ov45_0222A53C(void *);
extern void GF_AssertFail(void);
extern void TextFlags_SetCanABSpeedUpPrint(BOOL);
extern void TextFlags_SetAutoScrollParam(int);
extern void TextFlags_SetCanTouchSpeedUpPrint(BOOL);
extern void *Save_PlayerData_GetProfile(void *);
extern u32 PlayerProfile_GetTrainerGender(void *);
extern void ov49_0225A5EC(void *, void *, u32);
extern void *ov49_02258958(u32);
extern void *ov49_02258AB4(u32, u32, void *, u32, u32);
extern void *ov49_0225DF18(void *, void *, void *, u32, u32);
extern void *ov49_0225CB78(u32);
extern void ov49_0225AAC8(void *, void *, void *, u32);
extern void ov49_0225ACA8(void *, void *, void *, u32);
extern void ov49_0225AD20(void *, void *, u32);
extern void ov49_0225B214(void *, void *, u32);
extern void ov49_0225B0D4(void *, void *, u32);
extern void ov49_0225B308(void *, u32);
extern void ov49_0225B198(void *, void *, u32);
extern void ov49_0225B450(void *, void *, void *, void *, u32);
extern void *ov45_0222A5C0(void *);
extern u32 ov45_0222AADC(void *);
extern void ov49_0225B9AC(void *, void *, void *, u32, void *);
extern void *ov49_0225EEAC(void *, u32);
extern void ov49_0225F1A8(void *);
extern void ov49_0225F1F0(void *);
extern void *ov49_022652E8(void *, void *, void *, void *, u32, u32);
extern void *ov49_02268764(u32, void *);
extern void ov49_0225A5C8(void *);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern u32 IsPaletteFadeFinished(void);
extern u32 ov45_0222D844(void);
extern u32 ov45_0222A1FC(void *);
extern u32 ov45_0222A33C(void *);
extern void ov49_0225AC74(void *);
extern void ov49_0225B014(void *, u32, u32);
extern u32 sub_020393C8(void);
extern u32 sub_020397FC(void);
extern u32 ov45_0222E7CC(void);
extern void ov49_0225B284(void *, void *);
extern void ov49_0225B2C0(void *, void *, u32);
extern void ov49_0225B2F0(void *, void *, u32);
extern void ov49_0225B124(void *);
extern u32 ov49_0225B388(void *, u32, u32);
extern void ov49_0225AB44(void *, u32);
extern u32 ov49_0225AC5C(void *);
extern u32 ov49_0225B898(void *);
extern void ov49_0225A98C(void *);
extern void ov49_0225AA2C(void *);

BOOL ov49_02259A54(Ov49Interpolation15 *state, void *target) {
    if (state->active == 0) {
        return TRUE;
    }
    state->frame++;
    if (state->frame >= state->duration) {
        state->active = 0;
    }
    state->value = state->frame * state->delta / state->duration;
    state->value += state->start;
    ov45_02230700(target, state->value);
    return FALSE;
}

BOOL ov49_02259AA4(OverlayManager *manager, int *unused) {
    Ov49Work15 *work;
    Ov49Args15 *args = OverlayManager_GetArgs(manager);

    Heap_Create((enum HeapID)3, (enum HeapID)0x77, 0x3A000);
    Heap_Create((enum HeapID)3, (enum HeapID)0x78, 0x3D000);
    work = OverlayManager_CreateAndGetData(manager, 0x3F8, (enum HeapID)0x77);
    memset(work, 0, 0x3F8);
    work->state38 = (u8 *)args + 0xC;
    work->owner = *(void **)((u8 *)args + 0x1C);
    work->pad002 = ov45_0222A53C(work->owner);
    if (ov45_0222A53C(work->owner) == -1) {
        GF_AssertFail();
    }
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    *(void **)((u8 *)work + 0x3F4) = Save_PlayerData_GetProfile(*(void **)args);
    ov49_0225A5EC((u8 *)work + 0x3C, *(void **)args, 0x77);
    *(void **)((u8 *)work + 0x3E8) = ov49_02258958(0x77);
    *(void **)((u8 *)work + 0x3E0) = ov49_02258AB4(0x18, PlayerProfile_GetTrainerGender(*(void **)((u8 *)work + 0x3F4)), *(void **)((u8 *)work + 0x3E8), 0x77, 0x78);
    *(void **)((u8 *)work + 0x3E4) = ov49_0225DF18(*(void **)((u8 *)args + 4), *(void **)((u8 *)args + 8), *(void **)((u8 *)work + 0x3E8), 0x77, 0x78);
    *(void **)((u8 *)work + 0x3EC) = ov49_0225CB78(0x77);
    ov49_0225AAC8((u8 *)work + 0x2F8, (u8 *)work + 0x3C, *(void **)args, 0x77);
    ov49_0225ACA8((u8 *)work + 0x318, (u8 *)work + 0x3C, *(void **)args, 0x77);
    ov49_0225AD20((u8 *)work + 0x338, (u8 *)work + 0x3C, 0x77);
    ov49_0225B214((u8 *)work + 0x390, (u8 *)work + 0x3C, 0x77);
    ov49_0225B0D4((u8 *)work + 0x3C4, (u8 *)work + 0x3C, 0x77);
    ov49_0225B308((u8 *)work + 0x2DC, 0x77);
    ov49_0225B198((u8 *)work + 0x3A0, (u8 *)work + 0x2DC, 0x77);
    ov49_0225B450((u8 *)work + 0x184, work->state38, (u8 *)work + 0x3C, *(void **)((u8 *)work + 0x3F4), 0x77);
    args = ov45_0222A5C0(work->owner);
    if (ov45_0222AADC(args) == 1) {
        ov49_0225B9AC((u8 *)work + 0x184, (u8 *)work + 0x3C, (u8 *)work + 0x2DC, 0x77, args);
    }
    *(void **)((u8 *)work + 0x3F0) = ov49_0225EEAC(work, 0x77);
    ov49_0225F1A8(work);
    ov49_0225F1F0(work);
    *(void **)((u8 *)work + 0x3D4) = ov49_022652E8(work->owner, *(void **)((u8 *)work + 0x3E8), *(void **)((u8 *)work + 0x3EC), *(void **)((u8 *)work + 0x3E0), 0x77, 0x78);
    *(void **)((u8 *)work + 0x3DC) = ov49_02268764(0x77, work);
    Main_SetVBlankIntrCB(ov49_0225A5C8, work);
    HBlankInterruptDisable();
    return TRUE;
}

BOOL ov49_02259C90(OverlayManager *manager, int *state) {
    Ov49Work15 *work = OverlayManager_GetData(manager);
    u32 result;

    OverlayManager_GetArgs(manager);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x77);
        work->fading = 1;
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == 1) {
            work->fading = 0;
            (*state)++;
        }
        break;
    case 2:
        if (work->mode == 1) {
            if (ov45_0222D844() == 1 || ov45_0222A1FC(work->owner) != 0) {
                work->exitMode = 1;
            }
        }
        if (work->suppressExit == 0 && ov45_0222A33C(work->owner) == 1) {
            work->exitRequested = 1;
            ov49_0225A038(work, 8);
        }
        if (work->eventDone == 1 || work->exitMode == 1 || work->exitRequested == 1) {
            if (work->exitMode != 0) {
                *state = 3;
            } else if (work->exitRequested == 1) {
                *state = 5;
            } else {
                *state = 7;
            }
        }
        break;
    case 3:
        ov49_0225AC74((u8 *)work + 0x2F8);
        ov49_0225B014((u8 *)work + 0x338, 0, 0);
        ov49_0225B124((u8 *)work + 0x3C4);
        ov49_0225B200((u8 *)work + 0x3A0);
        if (sub_020393C8() != 0) {
            ov49_0225B284((u8 *)work + 0x390, (u8 *)work + 0x2DC);
        } else if (sub_020397FC() != 0) {
            ov49_0225B2C0((u8 *)work + 0x390, (u8 *)work + 0x2DC, ov45_0222E7CC());
        } else {
            ov49_0225B2F0((u8 *)work + 0x390, (u8 *)work + 0x2DC, ov45_0222A1FC(work->owner));
        }
        *state = 4;
        break;
    case 4:
        if (gSystem.newKeys & 1) {
            *state = 7;
        }
        break;
    case 5:
        ov49_0225AC74((u8 *)work + 0x2F8);
        ov49_0225B014((u8 *)work + 0x338, 0, 0);
        ov49_0225B124((u8 *)work + 0x3C4);
        ov49_0225B200((u8 *)work + 0x3A0);
        ov49_0225AB44((u8 *)work + 0x2F8, ov49_0225B388((u8 *)work + 0x2DC, 1, 0x46));
        *state = 6;
        work->timer = 0x3C;
        break;
    case 6:
        if (ov49_0225AC5C((u8 *)work + 0x2F8) != 0) {
            work->timer--;
            if (work->timer <= 0) {
                *state = 7;
            }
        }
        break;
    case 7:
        result = ov49_0225B898((u8 *)work + 0x184);
        if (result == 5) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x77);
            work->fading = 1;
            (*state)++;
        } else if (result == 0) {
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x77);
            work->fading = 1;
            (*state)++;
        }
        break;
    case 8:
        if (IsPaletteFadeFinished() == 1) {
            work->fading = 0;
            return TRUE;
        }
        break;
    }
    ov49_0225A98C(work);
    ov49_0225AA2C(work);
    return FALSE;
}

BOOL ov49_02259EF8(OverlayManager *manager) {
    Ov49Work15 *work = OverlayManager_GetData(manager);
    Ov49Args15 *args = OverlayManager_GetArgs(manager);

    args->result = work->result;
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    ov49_02268850(*(void **)((u8 *)work + 0x3DC));
    ov49_0226535C(*(void **)((u8 *)work + 0x3D4));
    ov49_0225EEF8(*(void **)((u8 *)work + 0x3F0));
    ov49_0225B4E4((u8 *)work + 0x184, (u8 *)work + 0x318, (u8 *)work + 0x3C);
    ov49_0225B35C((u8 *)work + 0x2DC);
    ov49_0225AB14((u8 *)work + 0x2F8);
    ov49_0225ACBC((u8 *)work + 0x318);
    ov49_0225AE4C((u8 *)work + 0x338, (u8 *)work + 0x3C);
    ov49_0225B244((u8 *)work + 0x390);
    ov49_0225B200((u8 *)work + 0x3A0);
    ov49_0225B0D8((u8 *)work + 0x3C4);
    ov49_0225CBDC(*(void **)((u8 *)work + 0x3EC));
    ov49_0225E2B4(*(void **)((u8 *)work + 0x3E4));
    ov49_02258B20(*(void **)((u8 *)work + 0x3E0));
    ov49_02258994(*(void **)((u8 *)work + 0x3E8));
    ov49_0225A7D0((u8 *)work + 0x3C);
    Heap_Free(work);
    Heap_Destroy((enum HeapID)0x77);
    Heap_Destroy((enum HeapID)0x78);
    sub_0200616C(0);
    sub_02006300(0);
    return TRUE;
}
