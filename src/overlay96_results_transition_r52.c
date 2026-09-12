#include "overlay96_results_transition_r52_private.h"

void ov96_021EFB58(Ov96R52Work *work) {
    MtxFx22 matrix;
    int x;

    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 6, work->bgConfig, (enum GFBgLayer)0, 0, 0, TRUE, work->heapId);
    ov96_021EF3A8(work);
    ov96_021EF95C(work, 0);
    ManagedSprite_SetDrawFlag(work->sprites[0], TRUE);
    ManagedSprite_SetDrawFlag(work->sprites[1], TRUE);
    ManagedSprite_SetDrawFlag(work->sprites[2], TRUE);
    ManagedSprite_SetDrawFlag(work->sprites[3], TRUE);
    ToggleBgLayer(5, TRUE);
    ToggleBgLayer(6, TRUE);
    ToggleBgLayer(4, TRUE);
    ToggleBgLayer(1, TRUE);
    ov96_021EF610(work);
    x = 0;
    if (work->showRecord == 0) {
        x = -32;
    }
    matrix._00 = FX32_ONE;
    matrix._01 = 0;
    matrix._10 = 0;
    matrix._11 = FX32_ONE;
    OS_WaitVBlankIntr();
    SetBgAffine(work->bgConfig, 7, &matrix, 0, 0);
    Bg_SetTextDimAndAffineParams(work->bgConfig, 7, BG_POS_OP_SET_Y, x, &matrix, 0, 0);
}

void ov96_021EFC10(Ov96R52Work *work) {
    ov96_021EF430(work, work->selection);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 7, work->bgConfig, (enum GFBgLayer)0, 0, 0, TRUE, work->heapId);
    ov96_021EF95C(work, 1);
    ManagedSprite_SetDrawFlag(work->sprites[0], TRUE);
    ManagedSprite_SetDrawFlag(work->sprites[1], FALSE);
    ManagedSprite_SetDrawFlag(work->sprites[2], FALSE);
    ManagedSprite_SetDrawFlag(work->sprites[3], FALSE);
    ToggleBgLayer(5, FALSE);
    ToggleBgLayer(6, FALSE);
    ToggleBgLayer(4, FALSE);
    ToggleBgLayer(1, FALSE);
    ov96_021EF770(work);
}

void ov96_021EFC8C(Ov96R52Work *work) {
    ov96_021EF430(work, work->selection);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 7, work->bgConfig, (enum GFBgLayer)0, 0, 0, TRUE, work->heapId);
    ov96_021EF95C(work, 1);
    ManagedSprite_SetDrawFlag(work->sprites[0], FALSE);
    ManagedSprite_SetDrawFlag(work->sprites[1], TRUE);
    ManagedSprite_SetDrawFlag(work->sprites[2], TRUE);
    ManagedSprite_SetDrawFlag(work->sprites[3], FALSE);
    ToggleBgLayer(5, FALSE);
    ToggleBgLayer(6, FALSE);
    ToggleBgLayer(4, FALSE);
    ToggleBgLayer(1, FALSE);
    ov96_021EF7C4(work);
}

void ov96_021EFD08(PokeathlonCourseData *course) {
    Ov96R52Work *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    BgClearTilemapBufferAndCommit(work->bgConfig, 0);
    BgClearTilemapBufferAndCommit(work->bgConfig, 2);
    BgClearTilemapBufferAndCommit(work->bgConfig, 4);
    BgClearTilemapBufferAndCommit(work->bgConfig, 5);
    BgClearTilemapBufferAndCommit(work->bgConfig, 6);
    BgClearTilemapBufferAndCommit(work->bgConfig, 7);
    ov96_021EF98C(work);
    switch (work->screenMode) {
    case 1:
        ov96_021EFB58(work);
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)1, (enum FadeType)1, 0x7FFF, 4, 1, work->heapId);
        break;
    case 2:
        ov96_021EFC10(work);
        break;
    case 3:
        ov96_021EFC8C(work);
        break;
    default:
        GF_AssertFail();
        break;
    }
    PokeathlonCourse_SetStateField07(course, work->screenMode);
}

u32 ov96_021EFD9C(PokeathlonCourseData *course, u8 *state) {
    u8 *st = state;
    PokeathlonCourseData *data = course;
    Ov96R52Work *work = PokeathlonCourse_GetHeapAllocPtr4(data);
    ov96_021EF924(work);
    switch (*st) {
    case 0:
        PlayBGM(0x470);
        (*st)++;
        break;
    case 1:
        if (ov96_021EF280(0, 0)) {
            BeginNormalPaletteFade((enum FadeMode)4, (enum FadeType)1, (enum FadeType)1, 0x7FFF, 1, 1, work->heapId);
            (*st)++;
        }
        break;
    case 2:
        if (ov96_021EF280(0, 1)) {
            ov96_021EFA3C(work);
            (*st)++;
        }
        break;
    case 3:
        if (work->flag2C != 0) {
            ov96_021EFACC(work);
        } else if (ov96_021EF280(0, 3)) {
            BeginNormalPaletteFade((enum FadeMode)3, (enum FadeType)1, (enum FadeType)1, 0x7FFF, 12, 1, work->heapId);
            ManagedSprite_SetAnimateFlag(work->sprites[2], TRUE);
            ManagedSprite_SetDrawFlag(work->sprites[3], work->mode == 0);
            (*st)++;
        }
        break;
    case 4:
        if (IsPaletteFadeFinished()) {
            if (work->mode != 0) {
                work->animCounter = 0;
                (*st)++;
            } else {
                PokeathlonCourse_SetStateField07(data, 1);
            }
        }
        break;
    case 5:
        work->animCounter++;
        if (work->animCounter >= 180) {
            PokeathlonCourse_SetStateField07(data, 4);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_021EFEB8(PokeathlonCourseData *course, u8 *state) {
    Ov96R52Work *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EF924(work);
    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished()) {
            int hit = TouchscreenHitbox_FindRectAtTouchNew(ov96_0221BA20);
            if (hit != -1) {
                switch (hit) {
                case 0:
                    PlaySE(0x5DC);
                    ov96_021EFB20(course, 2);
                    break;
                case 1:
                    PokeathlonCourse_SetStateField07(course, 4);
                    break;
                default:
                    GF_AssertFail();
                    break;
                }
                (*state)++;
            }
        }
        break;
    case 1:
        if (ov96_021EFB50(course)) {
            ov96_021EFD08(course);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_021EFF3C(PokeathlonCourseData *course, u8 *state) {
    Ov96R52Work *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EF924(work);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)1, (enum FadeType)1, 0x7FFF, 4, 1, work->heapId);
        (*state)++;
    case 1:
        if (IsPaletteFadeFinished()) {
            int hit = TouchscreenHitbox_FindRectAtTouchNew(ov96_0221BA2C);
            if (hit == 0) {
                PlaySE(0x5DC);
                ov96_021EFB20(course, 3);
                (*state)++;
            } else if (hit == 1) {
                PlaySE(0x5DC);
                ov96_021EFB20(course, 1);
                (*state)++;
            }
        }
        break;
    case 2:
        if (ov96_021EFB50(course)) {
            ov96_021EFD08(course);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_021EFFE4(PokeathlonCourseData *course, u8 *state) {
    Ov96R52Work *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EF924(work);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)1, (enum FadeType)1, 0x7FFF, 4, 1, work->heapId);
        (*state)++;
    case 1:
        if (IsPaletteFadeFinished()) {
            int hit = TouchscreenHitbox_FindRectAtTouchNew(ov96_0221BA38);
            if (hit == 0) {
                PlaySE(0x5DC);
                ov96_021EFB20(course, 2);
                (*state)++;
            } else if (hit == 1) {
                PlaySE(0x5DC);
                ov96_021EFB20(course, 1);
                (*state)++;
            }
        }
        break;
    case 2:
        if (ov96_021EFB50(course)) {
            ov96_021EFD08(course);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

u32 ov96_021F008C(PokeathlonCourseData *course, u8 *state) {
    Ov96R52Work *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EF924(work);
    switch (*state) {
    case 0:
        if (PokeathlonCourse_GetCurrentParticipantIndex(course) == 0) {
            PlaySE(0x8E4);
        } else {
            PlaySE(0x8D6);
        }
        GF_SndStartFadeOutBGM(0, 24);
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)0, (enum FadeType)0, 0x7FFF, 24, 1, work->heapId);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            return 1;
        }
        break;
    }
    return 0;
}
