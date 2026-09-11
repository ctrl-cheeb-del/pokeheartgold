#include "overlay46_state_internal.h"

int ov46_02258800(void *manager) {
    void **args;
    u8 *work;
    Heap_Create(3, 0x77, 2 << 16);
    work = OverlayManager_CreateAndGetData(manager, 0x404, 0x77);
    memset(work, 0, 0x404);
    args = OverlayManager_GetArgs(manager);
    *(void **)work = args[0];
    Sound_SetSceneAndPlayBGM(0xB, 0x47D, 0);
    *(u32 *)((u8 *)args + 0x10) = 0;
    ov46_02258F78(work, 0x77);
    ov46_022592EC(work + 0x40, *(void **)(work + 0xC), 1, 0x30A, 2, 0x13, 0x1B, 4, 0x28, *(void **)work, 0x77);
    ov46_022592EC(work + 0x70, *(void **)(work + 0xC), 1, 0x320, 2, 0x13, 0x1B, 4, 0x28, *(void **)work, 0x77);
    ov46_022592EC(work + 0xA0, *(void **)(work + 0xC), 0, 0x320, 4, 4, 0x17, 0x10, 0x94, *(void **)work, 0x77);
    ov46_022592EC(work + 0x10, *(void **)(work + 0xC), 1, 0x30A, 5, 1, 0x16, 2, 0x204, *(void **)work, 0x77);
    ov46_022594E0(work + 0x10, 0x15);
    Main_SetVBlankIntrCB(ov46_02258F70, work);
    HBlankInterruptDisable();
    gSystem[0x69] = 1;
    GfGfx_SwapDisplay();
    return 1;
}

int ov46_0225892C(void *manager, int *state) {
    u8 *work;
    void **args;
    work = OverlayManager_GetData(manager);
    args = OverlayManager_GetArgs(manager);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0xFFFF, 6, 1, 0x77);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case 2:
        if (args[2] == NULL) {
            ov46_02259374(work + 0x70, 0x11);
            *(void **)(work + 0xD0) = ov46_02259550(*(void **)(work + 0xC), 0x230);
            (*state)++;
        } else {
            *state = 4;
        }
        break;
    case 3: {
        int result = YesNoPrompt_HandleInput(*(void **)(work + 0xD0));
        if (result == 1) {
            YesNoPrompt_Destroy(*(void **)(work + 0xD0));
            *state = 4;
        } else if (result == 2) {
            YesNoPrompt_Destroy(*(void **)(work + 0xD0));
            ov46_022593F8(work + 0x40);
            *state = 7;
        }
        break;
    }
    case 4:
        sub_0203976C(*(void **)work, ov45_0222A5C0(args[1]));
        ov46_02259374(work + 0x70, 0x17);
        ov46_02259450(work + 0x70);
        (*state)++;
        break;
    case 5:
        if (sub_020393C8() || sub_020397FC()) {
            ov46_02259474(work + 0x70);
            *state = 9;
        }
        if (sub_020397E4() == 1) {
            ov45_0222B244(args[1]);
            (*state)++;
        }
        break;
    case 6:
        if (sub_020393C8() || sub_020397FC()) {
            ov46_02259474(work + 0x70);
            *state = 9;
        }
        if (sub_02039274()) {
            s64 seconds;
            ov46_02259474(work + 0x70);
            GameStats_AddScore(Save_GameStats_Get(*(void **)work), 0x21);
            seconds = GF_RTC_DateTimeToSec();
            *(s64 *)args[3] = seconds;
            *(u32 *)((u8 *)args + 0x10) = 1;
            (*state)++;
        }
        break;
    case 9: {
        u32 value;
        int msg;
        if (sub_020393C8()) {
            u32 *pair = sub_020392D8();
            msg = ov45_0222D7CC(pair[0], pair[1]);
            value = pair[0];
        } else {
            ov45_0222E7CC();
            value = ov45_0222E7FC();
            msg = 0x20;
        }
        ov45_0222B270(args[1]);
        ov46_022593F8(work + 0x40);
        ov46_022593F8(work + 0x70);
        ov46_02259534(work + 0xA0, value);
        ov46_02259374(work + 0xA0, msg);
        (*state)++;
        break;
    }
    case 10:
        if ((*(u32 *)(gSystem + 0x48) & 3) || System_GetTouchNew() == 1) {
            if (sub_020393C8()) {
                u32 *pair = sub_020392D8();
                if (ov45_0222D7FC(pair[0], pair[1]) == 0) {
                    *state = 11;
                } else {
                    *state = 14;
                }
            } else {
                *state = 11;
            }
        }
        break;
    case 11:
        ov46_022593F8(work + 0xA0);
        ov46_02259374(work + 0x40, 0x58);
        *(void **)(work + 0xD0) = ov46_02259550(*(void **)(work + 0xC), 0x230);
        (*state)++;
        break;
    case 12: {
        int result = YesNoPrompt_HandleInput(*(void **)(work + 0xD0));
        if (result == 1) {
            YesNoPrompt_Destroy(*(void **)(work + 0xD0));
            sub_020397C8();
            *state = 13;
        } else if (result == 2) {
            YesNoPrompt_Destroy(*(void **)(work + 0xD0));
            *state = 14;
        }
        break;
    }
    case 13:
        if (!sub_02037D78()) {
            *state = 4;
        }
        break;
    case 14:
        ov46_022593F8(work + 0x40);
        ov46_022593F8(work + 0x70);
        ov46_022593F8(work + 0xA0);
        sub_020397C8();
        (*state)++;
        break;
    case 15:
        if (!sub_02037D78()) {
            ov46_022593F8(work + 0x40);
            ov46_022593F8(work + 0x70);
            *state = 7;
        }
        break;
    case 7:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x77);
        (*state)++;
        break;
    case 8:
        if (IsPaletteFadeFinished()) {
            return 1;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

int ov46_02258C38(void *manager) {
    u8 *work = OverlayManager_GetData(manager);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    if (*(void **)(work + 0xD4) != NULL) {
        SysTask_Destroy(*(void **)(work + 0xD4));
        *(void **)(work + 0xD4) = NULL;
        *(u32 *)(work + 0xD8) = 0;
    }
    ov46_02259494(work + 0x40);
    ov46_02259494(work + 0x70);
    ov46_02259494(work + 0xA0);
    ov46_02259494(work + 0x10);
    ov46_022592B8(work);
    *(u32 *)(work + 0xD8) = 0;
    Heap_Free(work);
    Heap_Destroy(0x77);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    return 1;
}

int ov46_02258CB4(void *manager) {
    u8 *work;
    void *args;
    Heap_Create(3, 0x77, 2 << 16);
    work = OverlayManager_CreateAndGetData(manager, 0x404, 0x77);
    memset(work, 0, 0x404);
    args = OverlayManager_GetArgs(manager);
    *(void **)work = *(void **)args;
    ov46_02258F78(work, 0x77);
    ov46_022592EC(work + 0x40, *(void **)(work + 0xC), 1, 0x320, 2, 0x13, 0x1B, 4, 0x28, *(void **)work, 0x77);
    ov46_022592EC(work + 0xA0, *(void **)(work + 0xC), 0, 0x320, 4, 4, 0x17, 0x10, 0x94, *(void **)work, 0x77);
    ov46_022592EC(work + 0x10, *(void **)(work + 0xC), 1, 0x30A, 5, 1, 0x16, 2, 0x204, *(void **)work, 0x77);
    ov46_022594E0(work + 0x10, 0x15);
    sub_0203A880();
    Main_SetVBlankIntrCB(ov46_02258F70, work);
    HBlankInterruptDisable();
    gSystem[0x69] = 1;
    GfGfx_SwapDisplay();
    return 1;
}

int ov46_02258DA8(void *manager, int *state) {
    u8 *work;
    void **args;
    work = OverlayManager_GetData(manager);
    args = OverlayManager_GetArgs(manager);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0xFFFF, 6, 1, 0x77);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            *state = 2;
        }
        break;
    case 2:
        ov46_02259374(work + 0x40, 0x1A);
        if (sub_020393C8() || sub_020397FC()) {
            *state = 5;
            ov46_02259450(work + 0x40);
        } else {
            *state = 3;
            ov46_02259450(work + 0x40);
        }
        break;
    case 3:
        ov45_0222ED7C();
        *(u32 *)(work + 8) = 0x384;
        *state = 4;
        break;
    case 4:
        --*(u32 *)(work + 8);
        if (ov45_0222EDA8() || *(u32 *)(work + 8) == 0) {
            *state = 5;
        }
        break;
    case 5:
        sub_020397C8();
        *state = 6;
        break;
    case 6:
        if (!sub_02037D78()) {
            ov46_02259474(work + 0x70);
            ov45_0222B270(args[1]);
            *state = 7;
        }
        break;
    case 7:
        ov46_02259374(work + 0x40, 0x1B);
        *(u32 *)(work + 8) = 0x5A;
        *state = 8;
        break;
    case 8:
        if (--*(u32 *)(work + 8) == 0) {
            *state = 9;
        }
        break;
    case 9:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x77);
        (*state)++;
        break;
    case 10:
        if (IsPaletteFadeFinished()) {
            ov46_02259474(work + 0x40);
            return 1;
        }
        break;
    }
    return 0;
}

int ov46_02258EFC(void *manager) {
    u8 *work = OverlayManager_GetData(manager);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    if (*(void **)(work + 0xD4) != NULL) {
        SysTask_Destroy(*(void **)(work + 0xD4));
        *(void **)(work + 0xD4) = NULL;
        *(u32 *)(work + 0xD8) = 0;
    }
    ov46_02259494(work + 0x40);
    ov46_02259494(work + 0xA0);
    ov46_02259494(work + 0x10);
    ov46_022592B8(work);
    *(u32 *)(work + 0xD8) = 0;
    Heap_Free(work);
    Heap_Destroy(0x77);
    gSystem[0x69] = 0;
    GfGfx_SwapDisplay();
    return 1;
}
