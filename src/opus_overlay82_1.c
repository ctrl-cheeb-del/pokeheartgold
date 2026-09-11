#include "overlay_82_internal.h"

BOOL ov82_0223DD60(void *man, int *state) {
    Ov82Work *work;
    Ov82Args *args;

    HandleLoadOverlay(FS_OVERLAY_ID(OVY_80), 2);
    ov82_0223E9B0();
    Heap_Create(HEAP_ID_3, HEAP_ID_105, 0x20000);
    work = OverlayManager_CreateAndGetData(man, sizeof(Ov82Work), HEAP_ID_105);
    memset(work, 0, sizeof(Ov82Work));
    work->bgConfig = BgConfig_Alloc(HEAP_ID_105);
    work->unk000 = man;
    args = OverlayManager_GetArgs(man);
    work->saveData = args->unk00;
    work->unk009 = args->unk04;
    work->unk210 = &args->unk06;
    work->options = Save_PlayerData_GetOptionsAddr(work->saveData);
    work->party = args->unk0C;
    work->unk218 = args->unk08;
    work->unk21C = args->unk14;
    work->unk01C = args->unk18 + 1;
    work->unk00D = args->unk05;
    work->unk27C = 0xff;
    work->unk018 = 0xff;
    work->unk01F = 0x75;
    ov82_0223E9E8(work);
    if (ov80_0223792C(work->unk009) == TRUE) {
        sub_02096910(work);
    }
    *state = 0;
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    return TRUE;
}

BOOL ov82_0223DE20(void *man, int *state) {
    Ov82Work *work = OverlayManager_GetData(man);

    if (work->unk018 != 0xff && *state == 2 && work->unk010 == 0) {
        ov82_0223F834(work);
        ov82_0223F2F8(work, state, 3);
    }
    switch (*state) {
    case 1:
        if (ov82_0223E2A4(work) == TRUE) {
            ov82_0223F2F8(work, state, 0);
        } else {
            return FALSE;
        }
    case 0:
        if (ov82_0223DFBC(work) == TRUE) {
            ov82_0223F2F8(work, state, 2);
        }
        break;
    case 2:
        if (ov82_0223E2EC(work) == TRUE) {
            if (work->unk017 == 1) {
                ov82_0223F2F8(work, state, 3);
            } else if (work->unk00B == 1) {
                ov82_0223F2F8(work, state, 1);
                return FALSE;
            } else if (ov80_0223792C(work->unk009) == TRUE) {
                ov82_0223F2F8(work, state, 4);
            } else {
                ov82_0223F2F8(work, state, 5);
            }
        }
        break;
    case 3:
        if (ov82_0223E5D4(work) == TRUE) {
            if (work->unk019 == 1) {
                work->unk019 = 0;
                ov82_0223F2F8(work, state, 2);
            } else if (ov80_0223792C(work->unk009) == TRUE) {
                ov82_0223F2F8(work, state, 4);
            } else {
                ov82_0223F2F8(work, state, 5);
            }
        }
        break;
    case 4:
        if (ov82_0223E7E8(work) == TRUE) {
            ov82_0223F2F8(work, state, 5);
        }
        break;
    case 5:
        if (ov82_0223E820(work) == TRUE) {
            return TRUE;
        }
        break;
    case 6:
        if (ov82_0223E888(work) == TRUE) {
            ov82_0223F2F8(work, state, 4);
        }
        break;
    }
    SpriteList_RenderAndAnimateSprites(work->spriteList);
    return FALSE;
}

BOOL ov82_0223DF74(void *man) {
    Ov82Work *work = OverlayManager_GetData(man);

    *work->unk210 = work->unk00D;
    ov82_0223E8C4(work);
    OverlayManager_FreeData(man);
    reg_GX_POWCNT |= 0x8000;
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(HEAP_ID_105);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_80));
    return TRUE;
}

BOOL ov82_0223DFBC(Ov82Work *work) {
    switch (work->unk008) {
    case 0:
        if (work->unk012 == 0 && ov80_0223792C(work->unk009) == TRUE) {
            sub_02037BEC();
            sub_02037AC0(0x70);
        }
        work->unk008++;
        break;
    case 1:
        if (work->unk012 == 0 && ov80_0223792C(work->unk009) == TRUE) {
            if (sub_02037B38(0x70) == TRUE) {
                sub_02037BEC();
                work->unk012 = 1;
                work->unk008++;
            }
        } else {
            work->unk008++;
        }
        break;
    case 2:
        ov82_0223E070(work);
        ov82_0223E0B0(work);
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 3, HEAP_ID_105);
        work->unk008++;
        break;
    case 3:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void ov82_0223E070(Ov82Work *work) {
    ov82_0223F040(work, &work->windows[2], 1, 2, 0, 0);
    ov82_0223F134(work, &work->windows[2]);
    ov82_0223EFCC(work, &work->windows[1], 0, 0, 1, 2, 0, 0);
}

void ov82_0223E0B0(Ov82Work *work) {
    u8 x = GetWindowX(&work->windows[3]) - 1;
    u8 y = GetWindowY(&work->windows[3]) - 1;
    u8 w = GetWindowWidth(&work->windows[3]) + 2;
    u8 h = GetWindowHeight(&work->windows[3]) + 2;
    u8 bgId = GetWindowBgId(&work->windows[3]);

    ov82_0223F1AC(work, &work->windows[3], 0, 0, 1, 2, 0xf, 0);
    ov82_0223EECC(work, 4);
    ov82_0223E140(work->bgConfig, bgId, x, y, w, h, 1, 1);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, bgId);
}
