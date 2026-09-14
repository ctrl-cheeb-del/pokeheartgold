#include "bug_contest_swap_mon_states_internal.h"

BOOL BugContestSwapMon_Init(OverlayManager *manager, int *state) {
    Ov111WorkR6 *work;
    switch (*state) {
    case 0:
        ov111_021E5E34(manager);
        (*state)++;
        break;
    case 1:
        work = OverlayManager_GetData(manager);
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, work->heapId);
        (*state)++;
        break;
    case 2:
        if (IsPaletteFadeFinished()) {
            *state = 0;
            return TRUE;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return FALSE;
}

BOOL BugContestSwapMon_Exit(OverlayManager *manager, int *state) {
    Ov111WorkR6 *work = OverlayManager_GetData(manager);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, work->heapId);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            ov111_021E5F04(manager);
            return TRUE;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return FALSE;
}

BOOL BugContestSwapMon_Main(OverlayManager *manager, int *state) {
    Ov111WorkR6 *work = OverlayManager_GetData(manager);
    if (work == NULL) {
        GF_AssertFail();
    }
    if (_021E6D40[work->state](work)) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov111_021E59E4(Ov111WorkR6 *work) {
    int result = -1;
    void *mon;
    void *format = ov111_021E6A2C(work->text);
    if (ov111_021E6888(work->text)) {
        return FALSE;
    }
    switch (work->substate) {
    case 0:
        mon = work->args->mons[0];
        ov111_021E6738(work->animSystem, 0, 0x80, 0x48, mon);
        BufferBoxMonSpeciesName(format, 0, Mon_GetBoxMon(mon));
        result = 0;
        work->substate = 2;
        break;
    case 1:
        if (!ov111_021E6888(work->text)) {
            work->substate = 2;
        }
        break;
    case 2:
        if (System_GetTouchNew() || (gSystem.newKeys & 1)) {
            PlaySE(0x5dc);
            work->substate = 3;
        }
        break;
    case 3:
        return TRUE;
    default:
        GF_AssertFail();
        break;
    }
    if (result != -1) {
        ov111_021E68FC(work->text, result);
    }
    return FALSE;
}

BOOL ov111_021E5AA0(Ov111WorkR6 *work) {
    int result = -1;
    ov111_021E6A2C(work->text);
    if (ov111_021E6888(work->text)) {
        return FALSE;
    }
    switch (work->substate) {
    case 0:
        result = 1;
        ov111_021E5BE4(work);
        work->substate = result;
        break;
    case 1:
        ov111_021E5C54(work);
        work->substate = 2;
        break;
    case 2:
        switch (YesNoPrompt_HandleInput(work->yesNo)) {
        case 1:
            YesNoPrompt_Reset(work->yesNo);
            ManagedSprite_SetDrawFlag(work->sprite, 0);
            ov111_021E6770(work->animSystem, 0, (void *)1, 0x48);
            ov111_021E6770(work->animSystem, 1, (void *)1, 0xf2);
            ov111_021E5D08(work, 1);
            work->substate = 3;
            break;
        case 2:
            YesNoPrompt_Reset(work->yesNo);
            ManagedSprite_SetDrawFlag(work->sprite, 0);
            ov111_021E6770(work->animSystem, 0, (void *)1, -0x32);
            ov111_021E6770(work->animSystem, 1, (void *)1, 0x48);
            ov111_021E5D08(work, 2);
            work->substate = 4;
            break;
        }
        break;
    case 3:
        ov111_021E6784(work->animSystem);
        if (ov111_021E67A4(work->animSystem)) {
            result = 2;
            work->substate = 5;
        }
        break;
    case 4:
        ov111_021E6784(work->animSystem);
        if (ov111_021E67A4(work->animSystem)) {
            result = 3;
            work->substate = 5;
        }
        break;
    case 5:
        if (System_GetTouchNew() || (gSystem.newKeys & 1)) {
            PlaySE(0x5dc);
            work->substate = 6;
        }
        break;
    case 6:
        return TRUE;
    default:
        GF_AssertFail();
        break;
    }
    if (result != -1) {
        ov111_021E68FC(work->text, result);
    }
    return FALSE;
}

void ov111_021E5BE4(Ov111WorkR6 *work) {
    void *format = ov111_021E6A2C(work->text);
    void *mon0 = work->args->mons[0];
    void *mon1 = work->args->mons[1];
    void *sprite;
    ov111_021E6738(work->animSystem, 0, 0x80, 0x20, mon0);
    ov111_021E6738(work->animSystem, 1, 0x80, 0x70, mon1);
    BufferBoxMonSpeciesName(format, 0, Mon_GetBoxMon(mon0));
    BufferBoxMonSpeciesName(format, 1, Mon_GetBoxMon(mon1));
    sprite = ov111_021E6330(work->spriteSystem, work->spriteManager, 0x80, 0x48, 1, 0);
    work->sprite = sprite;
    ManagedSprite_SetPaletteOverride(sprite, 1);
}

void ov111_021E5C54(Ov111WorkR6 *work) {
    YesNoPromptTemplateR6 template = { 0 };
    template.bgConfig = work->bgConfig;
    template.bgId = 1;
    template.tileStart = 0xc8;
    template.plttSlot = 6;
    template.x = 0x19;
    template.y = 0xa;
    template.initialCursor = 0;
    YesNoPrompt_InitFromTemplate(work->yesNo, &template);
}
