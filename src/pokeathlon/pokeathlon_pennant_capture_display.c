#include "global.h"

#include "application/choose_starter/choose_starter_sub_res.naix"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_pennant_capture.h"

#include "assert.h"
#include "bg_window.h"
#include "char_tiles.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "pm_string.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"
#include "text.h"

extern const PokeathlonPennantCaptureSpriteIds gPokeathlonPennantCaptureSpriteIds[];

#define DISPLAY_CURSOR_STEP(cursor, size) ((PokeathlonPennantCaptureDisplay *)((u8 *)(cursor) + (size)))

static void PokeathlonPennantCaptureDisplay_SetIcon(PokeathlonPennantCaptureDisplay *display, int participant, int member);
static void PokeathlonPennantCaptureDisplay_PrintName(PokeathlonPennantCaptureDisplay *display, u32 member);

PokeathlonPennantCaptureDisplay *PokeathlonPennantCaptureDisplay_New(enum HeapID heapId, BgConfig *bgConfig, PokeathlonCourseData *course) {
    PokeathlonPennantCaptureDisplay *display = Heap_Alloc(heapId, sizeof(PokeathlonPennantCaptureDisplay));
    int i;
    PokeathlonCourseMon *mons;

    MI_CpuFill8(display, 0, sizeof(PokeathlonPennantCaptureDisplay));
    display->heapId = heapId;
    display->bgConfig = bgConfig;
    display->course = course;
    PokeathlonPennantCaptureDisplay_InitWindow(display);
    display->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, heapId);
    display->msgFormat = MessageFormat_New(heapId);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        display->names[i] = String_New(11, heapId);
    }
    mons = PokeathlonCourse_GetParticipantMons(course, PokeathlonCourse_GetNetId(course));
    for (int j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
        CopyU16ArrayToString(display->names[j], mons[j].nickname);
    }
    PokeathlonPennantCaptureDisplay_PrintName(display, 1);
    return display;
}

void PokeathlonPennantCaptureDisplay_Delete(PokeathlonPennantCaptureDisplay *display) {
    int i;

    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        Heap_Free(display->monPics[i].chars);
        Heap_Free(display->monPics[i].palette);
    }
    {
        PokeathlonPennantCaptureDisplay *cursor = display;
        int j = 0;
        for (; j < POKEATHLON_MONS; j++, cursor = DISPLAY_CURSOR_STEP(cursor, sizeof(void *))) {
            Heap_Free(cursor->u.raw.iconFiles[0]);
        }
    }
    Heap_Free(display->scoreScreenFile);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        String_Delete(display->names[i]);
    }
    MessageFormat_Delete(display->msgFormat);
    DestroyMsgData(display->msgData);
    RemoveWindow(&display->window);
    Heap_Free(display);
}

void PokeathlonPennantCaptureDisplay_LoadBgGfx(PokeathlonPennantCaptureDisplay *display) {
    GfGfxLoader_LoadCharData(NARC_a_2_2_4, 5, display->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, display->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_2_4, 6, display->bgConfig, GF_BG_LYR_SUB_2, 0, 0x2000, FALSE, display->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_2_4, 7, display->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, display->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_2_4, 8, display->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, display->heapId);
    display->scoreScreenFile = GfGfxLoader_GetScrnData(NARC_a_2_2_4, 9, FALSE, &display->scoreScreen, display->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_2_4, 4, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x40, display->heapId);
    PokeathlonPennantCaptureDisplay_SetScore(display, 0);
}

void PokeathlonPennantCaptureDisplay_LoadSpriteResources(PokeathlonPennantCaptureDisplay *display, PokeathlonCourseSpritePool *pool) {
    u32 ids[2];
    u32 *id = ids;
    int i;

#pragma unused(display)
    ids[0] = gPokeathlonPennantCaptureSpriteIds[1].ids[0];
    ids[1] = gPokeathlonPennantCaptureSpriteIds[1].ids[1];
    for (i = 0; i < 2; i++) {
        PokeathlonCourseSpritePool_LoadChar(pool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000009_NCGR, *id, NNS_G2D_VRAM_TYPE_2DSUB);
        PokeathlonCourseSpritePool_LoadPltt(pool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000006_NCLR, *id, NNS_G2D_VRAM_TYPE_2DSUB, 1);
        PokeathlonCourseSpritePool_LoadCell(pool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, *id);
        PokeathlonCourseSpritePool_LoadAnim(pool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, *id);
        id++;
    }
    PokeathlonCourseSpritePool_LoadChar(pool, NARC_a_2_2_4, 13, 0x65, NNS_G2D_VRAM_TYPE_2DSUB);
    PokeathlonCourseSpritePool_LoadPltt(pool, NARC_a_2_2_4, 10, 0x65, NNS_G2D_VRAM_TYPE_2DSUB, 8);
    PokeathlonCourseSpritePool_LoadCell(pool, NARC_a_2_2_4, 12, 0x65);
    PokeathlonCourseSpritePool_LoadAnim(pool, NARC_a_2_2_4, 11, 0x65);
}

void PokeathlonPennantCaptureDisplay_CreateSprites(PokeathlonPennantCaptureDisplay *display, PokeathlonCourseSpritePool *pool, PokeathlonCourseSpriteResources *resources) {
    int participant;
    int i;
    PokeathlonPennantCaptureDisplay *row;
    PokeathlonCourseSpritePoolSprite **status;
    PokeathlonCourseSpritePoolSprite **point;
    VecFx32 digitPosition;
    VecFx32 initialPosition;

    participant = 0;
    row = display;
    status = display->statusSprites[0];
    point = display->pointSprites[0];
    for (; participant < POKEATHLON_PARTICIPANTS; participant++) {
        row->u.mons[0].icon = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 2);
        row->u.mons[0].frame = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 3);
        row->u.mons[0].carryMark = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 10);
        status[2] = PokeathlonCourseSpritePool_CreateAndTake(pool, 2, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 19);
        PokeathlonCourseSpritePoolSprite_SetAnim(status[2], 0);
        PokeathlonCourseSpritePoolSprite_Show(status[2], TRUE, TRUE);
        status[1] = PokeathlonCourseSpritePool_CreateAndTake(pool, 2, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 21);
        PokeathlonCourseSpritePoolSprite_SetAnim(status[1], 9);
        PokeathlonCourseSpritePoolSprite_Show(status[1], TRUE, TRUE);
        status[0] = PokeathlonCourseSpritePool_CreateAndTake(pool, 2, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 20);
        PokeathlonCourseSpritePoolSprite_SetAnim(row->u.mons[0].icon, participant + 19);
        PokeathlonCourseSpritePoolSprite_SetAnim(row->u.mons[0].frame, participant + 5);
        PokeathlonCourseSpritePoolSprite_SetAnim(status[0], 3);
        PokeathlonCourseSpritePoolSprite_Show(status[0], TRUE, TRUE);
        for (i = 0; i < 2; i++) {
            point[i] = PokeathlonCourseSpritePool_CreateAndTake(pool, 2, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 24);
            PokeathlonCourseSpritePoolSprite_SetAnim(point[i], 2);
        }
        row = DISPLAY_CURSOR_STEP(row, sizeof(PokeathlonPennantCaptureDisplayMon));
        status += 4;
        point += 2;
    }
    initialPosition = gPokeathlonPennantCaptureInitialPosition;
    display->goalSprite = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 0x65, 22);
    PokeathlonCourseSpritePoolSprite_SetAnim(display->goalSprite, 4);
    PokeathlonCourseSpritePoolSprite_Show(display->goalSprite, TRUE, TRUE);
    PokeathlonCourseSpritePoolSprite_SetPosition(display->goalSprite, &initialPosition);
    PokeathlonPennantCaptureDisplay_CreatePicSprites(pool, display);
    for (i = 0; i < 2; i++) {
        display->timerDigits[i] = PokeathlonCourseSprites_CreateTimerDigit(resources, PokeathlonCourseSpritePool_GetSpriteList(pool), 3, display->heapId);
        Sprite_SetDrawFlag(display->timerDigits[i], TRUE);
        digitPosition.x = gPennantCaptureTimerDigitX[i] << FX32_SHIFT;
        digitPosition.y = FX32_CONST(708);
        digitPosition.z = 0;
        Sprite_SetMatrix(display->timerDigits[i], &digitPosition);
        Sprite_SetAnimCtrlSeq(display->timerDigits[i], gPennantCaptureTimerDigitAnims[i]);
    }
}

void PokeathlonPennantCaptureDisplay_LoadIcons(PokeathlonPennantCaptureDisplay *display, const PokeathlonPennantCaptureIconMon *mons) {
    NARC *volatile narc;
    volatile int x;
    PokeathlonPennantCaptureDisplay *pointRow;
    u32 iconNarc;
    int i;
    PokeathlonPennantCaptureDisplay *fileRow;
    NNSG2dCharacterData **chars;
    PokeathlonPennantCaptureDisplay *monRow;
    PokeathlonPennantCaptureDisplay *statusRow;
    VecFx32 position;

    struct {
        u32 species;
        u32 form;
    } current;

    narc = NARC_New(NARC_poketool_icongra_poke_icon, display->heapId);
    iconNarc = GetMonIconPlttNaix();
    GfGfxLoader_GXLoadPal(NARC_poketool_icongra_poke_icon, iconNarc, GF_PAL_LOCATION_SUB_OBJ, GF_PAL_SLOT_6_OFFSET, 0x60, display->heapId);
    fileRow = display;
    i = 0;
    chars = display->iconChars;
    for (; i < POKEATHLON_MONS; i++) {
        fileRow->u.raw.iconFiles[0] = Heap_AllocAtEnd(display->heapId, 0x1000);
        current.form = (u8)mons->form;
        current.species = mons->species;
        NARC_ReadWholeMember(narc, GetMonIconNaixEx(current.species, FALSE, current.form), fileRow->u.raw.iconFiles[0]);
        NNS_G2dGetUnpackedBGCharacterData(fileRow->u.raw.iconFiles[0], chars);
        display->iconPalettes[i] = GetMonIconPaletteEx(current.species, current.form, FALSE) + 6;
        fileRow = DISPLAY_CURSOR_STEP(fileRow, sizeof(void *));
        mons++;
        chars++;
    }
    NARC_Delete(narc);

    i = 0;
    monRow = display;
    x = 0x70;
    pointRow = display;
    statusRow = display;
    for (; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonPennantCaptureDisplay_SetIcon(display, (u8)i, 0);
        PokeathlonCourseSpritePoolSprite_Show(monRow->u.mons[0].icon, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_Show(monRow->u.mons[0].frame, TRUE, TRUE);
        position.z = 0;
        position.x = x << FX32_SHIFT;
        position.y = FX32_CONST(848);
        PokeathlonCourseSpritePoolSprite_SetPosition(monRow->u.mons[0].icon, &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(monRow->u.mons[0].frame, &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(monRow->u.mons[0].carryMark, &position);
        {
            int j;
            PokeathlonPennantCaptureDisplay *point = pointRow;
            for (j = 0; j < 2; j++) {
                PokeathlonCourseSpritePoolSprite_SetPosition(point->pointSprites[0][0], &position);
                point = DISPLAY_CURSOR_STEP(point, sizeof(void *));
            }
        }
        position.y -= FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(statusRow->statusSprites[0][0], &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(statusRow->statusSprites[0][1], &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(statusRow->statusSprites[0][2], &position);
        monRow = DISPLAY_CURSOR_STEP(monRow, sizeof(PokeathlonPennantCaptureDisplayMon));
        x += 0x28;
        statusRow = DISPLAY_CURSOR_STEP(statusRow, sizeof(display->statusSprites[0]));
        pointRow = DISPLAY_CURSOR_STEP(pointRow, sizeof(display->pointSprites[0]));
    }
}

void PokeathlonPennantCaptureDisplay_LoadMonPics(PokeathlonPennantCaptureDisplay *display, const PokeathlonPennantCapturePicMon *mons) {
    PokepicTemplate template;
    int i = 0;

    for (; i < POKEATHLON_TEAM_SIZE; i++) {
        GetMonSpriteCharAndPlttNarcIdsEx(&template, mons[i].species, mons[i].gender, 2, mons[i].shiny, mons[i].form, mons[i].personality);
        display->monPics[i].chars = CharTiles_AllocAndLoadMonPicAsObjFromNarc((NarcId)template.narcID, template.charDataID, display->heapId, mons[i].personality, FALSE, 2, mons[i].species);
        display->monPics[i].palette = AllocAndLoadPltt16FromNarc((NarcId)template.narcID, template.palDataID, display->heapId);
    }
}

void PokeathlonPennantCaptureDisplay_LoadMonPicToVram(PokeathlonPennantCaptureDisplay *display, u32 slot, u32 member) {
    GF_ASSERT(slot < 2);
    GF_ASSERT(member < POKEATHLON_TEAM_SIZE);
    DC_FlushRange(display->monPics[member].chars, 0xC80);
    GXS_LoadOBJ(display->monPics[member].chars, display->picCharOffsets[slot], 0xC80);
    DC_FlushRange(display->monPics[member].palette, 0x20);
    GXS_LoadOBJPltt(display->monPics[member].palette, display->picPlttOffsets[slot], 0x20);
}

static void PokeathlonPennantCaptureDisplay_SetIcon(PokeathlonPennantCaptureDisplay *display, int participant, int member) {
    Sprite *sprite;
    int slot;

    sprite = PokeathlonCourseSpritePoolSprite_GetSprite(display->u.mons[participant].icon);
    slot = member + participant * 3;
    DC_FlushRange(display->iconChars[slot]->pRawData, 0x200);
    GXS_LoadOBJ(display->iconChars[slot]->pRawData, 0x1800 + participant * 0x200, 0x200);
    Sprite_SetPaletteOverride(sprite, display->iconPalettes[slot]);
}

void PokeathlonPennantCaptureDisplay_SetScore(PokeathlonPennantCaptureDisplay *display, int score) {
    u8 x[3];
    u8 y[3];
    u8 digit;
    u8 i;

    digit = score / 100;
    x[0] = (digit % 5) * 4;
    y[0] = (digit / 5) * 8;
    digit = (score - digit * 100) / 10;
    x[1] = (digit % 5) * 4;
    y[1] = (digit / 5) * 8;
    digit = score % 10;
    x[2] = (digit % 5) * 4;
    y[2] = (digit / 5) * 8;

    for (i = 0; i < 3; i++) {
        CopyRectToBgTilemapRect(display->bgConfig, GF_BG_LYR_SUB_1, 14 + i * 4, 3, 4, 8, display->scoreScreen->rawData, x[i], y[i], 20, 16);
    }
    ScheduleBgTilemapBufferTransfer(display->bgConfig, GF_BG_LYR_SUB_1);
}

// Slides the picture of the outgoing team member out and the incoming one in (two sprites in turn).
BOOL PokeathlonPennantCaptureDisplay_SlideMonPic(PokeathlonPennantCaptureDisplay *display, int member) {
    int *state = &display->picState;

    switch (*state) {
    case 0: {
        VecFx32 position = *PokeathlonCourseSpritePoolSprite_GetPosition(display->picSprites[display->picSlot]);
        position.y += FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(display->picSprites[display->picSlot], &position);
        if (position.y >= FX32_CONST(924)) {
            position.y = FX32_CONST(660);
            PokeathlonCourseSpritePoolSprite_SetPosition(display->picSprites[display->picSlot], &position);
            (*state)++;
        }
        break;
    }
    case 1:
        PokeathlonPennantCaptureDisplay_LoadMonPicToVram(display, (u8)display->picSlot, member);
        display->picSlot = (display->picSlot + 1) % 2;
        (*state)++;
        break;
    case 2: {
        VecFx32 position = *PokeathlonCourseSpritePoolSprite_GetPosition(display->picSprites[display->picSlot]);
        position.y += FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(display->picSprites[display->picSlot], &position);
        if (position.y >= FX32_CONST(836)) {
            position.y = FX32_CONST(836);
            PokeathlonCourseSpritePoolSprite_SetPosition(display->picSprites[display->picSlot], &position);
            display->picSlot = (display->picSlot + 1) % 2;
            (*state)++;
        }
        break;
    }
    case 3: {
        VecFx32 position = *PokeathlonCourseSpritePoolSprite_GetPosition(display->picSprites[display->picSlot]);
        position.y += FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(display->picSprites[display->picSlot], &position);
        if (position.y >= FX32_CONST(748)) {
            position.y = FX32_CONST(748);
            PokeathlonCourseSpritePoolSprite_SetPosition(display->picSprites[display->picSlot], &position);
            display->picSlot = (display->picSlot + 1) % 2;
            PokeathlonPennantCaptureDisplay_PrintName(display, (u8)((member + 2) % 3));
            *state = 0;
            return TRUE;
        }
        break;
    }
    }
    return FALSE;
}

BOOL PokeathlonPennantCaptureDisplay_StepSwapWait(PokeathlonPennantCaptureDisplay *display, u32 participant) {
    GF_ASSERT(participant != 0 && participant < POKEATHLON_PARTICIPANTS);
    participant--;
    display->counters[participant].x += 0x20;
    if (display->counters[participant].x >= 0x58) {
        display->counters[participant].x = 0;
        display->counters[participant].y++;
    }
    if (display->counters[participant].y >= 3) {
        display->counters[participant].y = 0;
        return TRUE;
    }
    return FALSE;
}

void PokeathlonPennantCaptureDisplay_UpdateMon(PokeathlonPennantCaptureDisplay *display, u8 participant, u16 member, BOOL hidden, int active) {
    if (display->shownMember[participant] != member) {
        display->shownMember[participant] = member;
        PokeathlonPennantCaptureDisplay_SetIcon(display, participant, member);
    }
    if (hidden) {
        VecFx32 position;
        position.z = 0;
        position.x = (participant * 0x28 + 0x70) << FX32_SHIFT;
        position.y = 0x350004;
        PokeathlonCourseSpritePoolSprite_SetPosition(display->u.mons[participant].icon, &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(display->u.mons[participant].frame, &position);
        PokeathlonPennantCaptureDisplay_ShowStatus(display->statusSprites[participant], FALSE);
    } else {
        VecFx32 position;
        position.z = 0;
        position.x = (participant * 0x28 + 0x70) << FX32_SHIFT;
        position.y = FX32_CONST(848);
        PokeathlonCourseSpritePoolSprite_SetPosition(display->u.mons[participant].icon, &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(display->u.mons[participant].frame, &position);
        PokeathlonPennantCaptureDisplay_ShowStatus(display->statusSprites[participant], TRUE);
        if (active == 1) {
            if (display->u.mons[participant].active != active) {
                PokeathlonCourseSpritePoolSprite_Show(display->u.mons[participant].carryMark, TRUE, TRUE);
                PokeathlonCourseSpritePoolSprite_SetAnim(display->u.mons[participant].carryMark, 1);
            }
        } else {
            PokeathlonCourseSpritePoolSprite_Show(display->u.mons[participant].carryMark, TRUE, FALSE);
        }
    }
    display->u.mons[participant].active = active;
}

void PokeathlonPennantCaptureDisplay_SetTimer(PokeathlonPennantCaptureDisplay *display, int frames) {
    u8 seconds = frames / 30;
    u8 anim = seconds / 10;
    Sprite_SetAnimCtrlSeq(display->timerDigits[0], anim + 1);
    anim = seconds % 10;
    Sprite_SetAnimCtrlSeq(display->timerDigits[1], anim + 1);
}

// Draws the given participant's top-screen sprites above the others'.
void PokeathlonPennantCaptureDisplay_BringToFront(PokeathlonPennantCaptureDisplay *display, int chosen) {
    u8 order[4];
    int i;
    u8 next;

    for (i = 0; i < 2; i++) {
        Sprite_SetDrawPriority(display->timerDigits[i], 2);
    }
    for (i = 0; i < 2; i++) {
        Sprite_SetDrawPriority(PokeathlonCourseSpritePoolSprite_GetSprite(display->picSprites[i]), 2);
    }
    next = 1;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (i == chosen) {
            order[0] = i;
        }
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (order[0] != i) {
            order[next++] = i;
        }
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(display->u.mons[order[i]].carryMark, 3 + i * 2);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(display->u.mons[order[i]].icon, 4 + i * 2);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(display->u.mons[order[i]].frame, 11 + i);
    }
}

void PokeathlonPennantCaptureDisplay_SetPennants(PokeathlonPennantCaptureDisplay *display, int participant, u32 pennants) {
    GF_ASSERT(pennants <= PENNANT_CAPTURE_MAX_CARRIED);
    PokeathlonCourseSpritePoolSprite_SetAnim(display->statusSprites[participant][1], pennants + 9);
}

void PokeathlonPennantCaptureDisplay_ShowPoint(PokeathlonPennantCaptureDisplay *display, int participant) {
    PokeathlonCourseSpritePoolSprite_SetAnim(display->pointSprites[participant][display->nextPointSprite], 2);
    PokeathlonCourseSpritePoolSprite_Show(display->pointSprites[participant][display->nextPointSprite], TRUE, TRUE);
    display->nextPointSprite = (display->nextPointSprite + 1) % 2;
}

static void PokeathlonPennantCaptureDisplay_PrintName(PokeathlonPennantCaptureDisplay *display, u32 member) {
    String *string;
    FillWindowPixelBuffer(&display->window, 0);
    BufferString(display->msgFormat, 0, display->names[member], 2, 1, 2);
    string = ReadMsgData_ExpandPlaceholders(display->msgFormat, display->msgData, msg_0309_00154, display->heapId);
    AddTextPrinterParameterizedWithColor(&display->window, 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(&display->window);
}
