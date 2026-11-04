#include "global.h"

#include "application/choose_starter/choose_starter_sub_res.naix"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "nnsys/g2d/load/g2d_NCG_load.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_relay_run.h"

#include "assert.h"
#include "bg_window.h"
#include "char_tiles.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "pm_string.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"

extern const u32 gPokeathlonRelayRunPicIds[]; // touch screen sprite resource ids

static void PokeathlonRelayRunHud_SetMonIcon(PokeathlonRelayRunHud *hud, u8 teamId, int member);
static void PokeathlonRelayRunHud_PrintMonName(PokeathlonRelayRunHud *hud, s32 member);
static void PokeathlonRelayRunHud_PrintLaps(PokeathlonRelayRunHud *hud);

static const u8 sRelayRunTimerSpriteX[6] = { 144, 152, 168, 184, 192, 208 };

static const u8 sRelayRunTimerSpriteAnims[6] = { 1, 12, 1, 1, 11, 1 };

PokeathlonRelayRunHud *PokeathlonRelayRunHud_New(enum HeapID heapId, BgConfig *bgConfig, PokeathlonCourseData *course) {
    PokeathlonRelayRunHud *hud = Heap_Alloc(heapId, sizeof(PokeathlonRelayRunHud));
    int i;
    PokeathlonCourseMon *mon;
    MI_CpuFill8(hud, 0, sizeof(PokeathlonRelayRunHud));
    hud->heapId = heapId;
    hud->bgConfig = bgConfig;
    hud->course = course;
    PokeathlonRelayRunHud_InitWindows(hud);
    hud->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, heapId);
    hud->msgFormat = MessageFormat_New(heapId);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        hud->names[i] = String_New(11, heapId);
    }
    mon = PokeathlonCourse_GetParticipantMons(course, PokeathlonCourse_GetNetId(course));
    {
        int member;
        for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
            CopyU16ArrayToString(hud->names[member], mon->nickname);
            mon++;
        }
    }
    PokeathlonRelayRunHud_PrintMonName(hud, 1);
    PokeathlonRelayRunHud_PrintLaps(hud);
    hud->benchMembers[0] = 1;
    hud->benchMembers[1] = 2;
    return hud;
}

void PokeathlonRelayRunHud_Free(PokeathlonRelayRunHud *hud) {
    int i;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        Heap_Free(hud->pics[i].chars);
        Heap_Free(hud->pics[i].palette);
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE; i++) {
        Heap_Free(hud->map.icons.files[i]);
    }
    Heap_Free(hud->digitScreenFile);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        String_Delete(hud->names[i]);
    }
    MessageFormat_Delete(hud->msgFormat);
    DestroyMsgData(hud->msgData);
    RemoveWindow(&hud->nameWindow);
    RemoveWindow(&hud->lapsWindow);
    Heap_Free(hud);
}

void PokeathlonRelayRunHud_LoadBgGraphics(PokeathlonRelayRunHud *hud) {
    GfGfxLoader_LoadCharData(NARC_a_1_7_8, 6, hud->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, hud->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_7_8, 7, hud->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, hud->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_7_8, 8, hud->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, hud->heapId);
    hud->digitScreenFile = GfGfxLoader_GetScrnData(NARC_a_1_7_8, 9, FALSE, &hud->digitScreen, hud->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_7_8, 5, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x40, hud->heapId);
}

void PokeathlonRelayRunHud_LoadSpriteGraphics(PokeathlonRelayRunHud *hud, PokeathlonCourseSpritePool *spritePool) {
    u32 resIds[2];
    u32 *resId = resIds;
    int i;
    resIds[0] = gPokeathlonRelayRunPicIds[4];
    resIds[1] = gPokeathlonRelayRunPicIds[5];
    for (i = 0; i < 2; i++, resId++) {
        PokeathlonCourseSpritePool_LoadChar(spritePool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000009_NCGR, *resId, NNS_G2D_VRAM_TYPE_2DSUB);
        PokeathlonCourseSpritePool_LoadPltt(spritePool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000006_NCLR, *resId, NNS_G2D_VRAM_TYPE_2DSUB, 1);
        PokeathlonCourseSpritePool_LoadCell(spritePool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, *resId);
        PokeathlonCourseSpritePool_LoadAnim(spritePool, NARC_application_choose_starter_choose_starter_sub_res, NARC_choose_starter_sub_res_choose_starter_sub_res_00000010_NCER, *resId);
    }
    PokeathlonCourseSpritePool_LoadChar(spritePool, NARC_a_1_7_8, 13, 101, NNS_G2D_VRAM_TYPE_2DSUB);
    PokeathlonCourseSpritePool_LoadPltt(spritePool, NARC_a_1_7_8, 10, 101, NNS_G2D_VRAM_TYPE_2DSUB, 5);
    PokeathlonCourseSpritePool_LoadCell(spritePool, NARC_a_1_7_8, 12, 101);
    PokeathlonCourseSpritePool_LoadAnim(spritePool, NARC_a_1_7_8, 11, 101);
}

// The track map (an icon, a colour mark, a swap mark and a condition mark per team), the "Laps" plate and
// the timer's sprites.

void PokeathlonRelayRunHud_CreateSprites(PokeathlonRelayRunHud *hud, PokeathlonCourseSpritePool *spritePool, PokeathlonCourseSpriteResources *monResources) {
    int i, j;
    PokeathlonCourseSpritePoolSprite *plate;
    VecFx32 timerPosition, platePosition;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 101, 2);
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 101, 3);
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 101, 8);
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 101, 10);
    }
    for (i = 0; i < 2; i++) {
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 101, 16);
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        hud->map.teams[i].icon = PokeathlonCourseSpritePool_Take(spritePool, 101, 2);
        hud->map.teams[i].colorMark = PokeathlonCourseSpritePool_Take(spritePool, 101, 3);
        hud->map.teams[i].swapMark = PokeathlonCourseSpritePool_Take(spritePool, 101, 8);
        hud->map.teams[i].conditionMark = PokeathlonCourseSpritePool_Take(spritePool, 101, 10);
        PokeathlonCourseSpritePoolSprite_SetAnim(hud->map.teams[i].icon, i);
        PokeathlonCourseSpritePoolSprite_SetAnim(hud->map.teams[i].colorMark, i + 4);
        PokeathlonCourseSpritePoolSprite_SetAnim(hud->map.teams[i].swapMark, 10);
    }
    plate = PokeathlonCourseSpritePool_CreateAndTake(spritePool, 3, NNS_G2D_VRAM_TYPE_2DSUB, 101, 17);
    PokeathlonCourseSpritePoolSprite_Show(plate, TRUE, TRUE);
    PokeathlonCourseSpritePoolSprite_SetAnim(plate, 11);
    platePosition.z = 0;
    platePosition.x = FX32_CONST(128);
    platePosition.y = FX32_CONST(568);
    PokeathlonCourseSpritePoolSprite_SetPosition(plate, &platePosition);
    PokeathlonRelayRunHud_CreatePicFrames(spritePool, hud);
    for (j = 0; j < 6; j++) {
        hud->timerSprites[j] = PokeathlonCourseSprites_CreateTimerDigit(monResources, PokeathlonCourseSpritePool_GetSpriteList(spritePool), 3, hud->heapId);
        Sprite_SetDrawFlag(hud->timerSprites[j], TRUE);
        timerPosition.x = sRelayRunTimerSpriteX[j] << FX32_SHIFT;
        timerPosition.y = FX32_CONST(568);
        timerPosition.z = 0;
        Sprite_SetMatrix(hud->timerSprites[j], &timerPosition);
        Sprite_SetAnimCtrlSeq(hud->timerSprites[j], sRelayRunTimerSpriteAnims[j]);
    }
}

// The icons of every team's Pokemon (species, form pairs), shown on the track map at the start line.

void PokeathlonRelayRunHud_LoadMonIcons(PokeathlonRelayRunHud *hud, PokeathlonCoursePoint *mons) {
    NARC *narc;
    int i;
    NNSG2dCharacterData **chars;
    int form, species;
    VecFx32 position;
    PokeathlonRelayRunHud *cursor;
    narc = NARC_New(NARC_poketool_icongra_poke_icon, hud->heapId);
    GfGfxLoader_GXLoadPal(NARC_poketool_icongra_poke_icon, GetMonIconPlttNaix(), GF_PAL_LOCATION_SUB_OBJ, GF_PAL_SLOT_1_OFFSET, 0x60, hud->heapId);
    for (i = 0, cursor = hud, chars = hud->iconChars; i < POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE; cursor = (PokeathlonRelayRunHud *)((u8 *)cursor + sizeof(void *)), mons++, chars++, i++) {
        cursor->map.icons.files[0] = Heap_AllocAtEnd(hud->heapId, 0x1000);
        form = (u8)mons->y;
        species = mons->x;
        NARC_ReadWholeMember(narc, GetMonIconNaixEx(species, FALSE, form), cursor->map.icons.files[0]);
        NNS_G2dGetUnpackedBGCharacterData(cursor->map.icons.files[0], chars);
        hud->iconPalettes[i] = GetMonIconPaletteEx(species, form, FALSE) + 1;
    }
    NARC_Delete(narc);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonRelayRunHud_SetMonIcon(hud, i, 0);
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[i].icon, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[i].colorMark, TRUE, TRUE);
        position.z = 0;
        position.x = FX32_CONST(160);
        position.y = FX32_CONST(688);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->map.teams[i].icon, &position);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->map.teams[i].colorMark, &position);
    }
}

// The pictures of the player's own three Pokemon.
void PokeathlonRelayRunHud_LoadMonPics(PokeathlonRelayRunHud *hud, const PokeathlonCourseMonInfo *mon) {
    PokepicTemplate template;
    int i;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; mon++, i++) {
        GetMonSpriteCharAndPlttNarcIdsEx(&template, mon->species, mon->gender, 2, mon->isShiny, mon->form, mon->personality);
        hud->pics[i].chars = CharTiles_AllocAndLoadMonPicAsObjFromNarc((NarcId) template.narcID, template.charDataID, hud->heapId, mon->personality, FALSE, 2, mon->species);
        hud->pics[i].palette = AllocAndLoadPltt16FromNarc((NarcId) template.narcID, template.palDataID, hud->heapId);
    }
}

// Shows the picture of member in picture slot 0 or 1 (the next and the one after on the touch screen).
void PokeathlonRelayRunHud_ShowMonPic(PokeathlonRelayRunHud *hud, u32 slot, u32 member) {
    GF_ASSERT(slot < 2);
    GF_ASSERT(member < POKEATHLON_TEAM_SIZE);
    DC_FlushRange(hud->pics[member].chars, 0x32 * 64);
    GXS_LoadOBJ(hud->pics[member].chars, hud->picCharLocations[slot], 0x32 * 64);
    DC_FlushRange(hud->pics[member].palette, 0x20);
    GXS_LoadOBJPltt(hud->pics[member].palette, hud->picPaletteLocations[slot], 0x20);
}

// Shows the icon of a team's member on the track map.
static void PokeathlonRelayRunHud_SetMonIcon(PokeathlonRelayRunHud *hud, u8 teamId, int member) {
    Sprite *sprite = PokeathlonCourseSpritePoolSprite_GetSprite(hud->map.teams[teamId].icon);
    int index = member + teamId * POKEATHLON_TEAM_SIZE;
    DC_FlushRange(hud->iconChars[index]->pRawData, 0x200);
    GXS_LoadOBJ(hud->iconChars[index]->pRawData, teamId * 0x200 + 0x600, 0x200);
    Sprite_SetPaletteOverride(sprite, hud->iconPalettes[index]);
}

// Places a team on the track map: x along the lap turns into an angle around the oval.

void PokeathlonRelayRunHud_SetMapPosition(PokeathlonRelayRunHud *hud, u8 teamId, u16 x) {
    VecFx32 position;
    VecFx32 offset;
    VecFx32 centre;
    MtxFx33 rotation;
    int lapX = x % RELAY_RUN_TRACK_LENGTH;
    u16 angle = lapX * 65536 / RELAY_RUN_TRACK_LENGTH;
    angle = 65536 - angle;
    offset = gRelayRunMapStartOffset;
    centre = gRelayRunMapCenter;
    MTX_RotZ33_(&rotation, FX_SinCosTable_[(angle >> 4) * 2], FX_SinCosTable_[(angle >> 4) * 2 + 1]);
    MTX_MultVec33(&offset, &rotation, &offset);
    VEC_Add(&centre, &offset, &position);
    PokeathlonCourseSpritePoolSprite_SetPosition(hud->map.teams[teamId].icon, &position);
    PokeathlonCourseSpritePoolSprite_SetPosition(hud->map.teams[teamId].colorMark, &position);
    PokeathlonCourseSpritePoolSprite_SetPosition(hud->map.teams[teamId].conditionMark, &position);
    PokeathlonCourseSpritePoolSprite_SetPosition(hud->map.teams[teamId].swapMark, &position);
}

// The distance on the touch screen: laps (two big digits) and tenths of the lap so far (x / 102.4), copied
// from the digit tiles (5 x 2 digits of 4 x 8 tiles).
void PokeathlonRelayRunHud_PrintDistance(PokeathlonRelayRunHud *hud, u8 laps, u32 x) {
    u8 srcX[2];
    u8 srcY[2];
    u8 tenths;
    u8 tens;
    u8 ones;
    u8 i;
    tenths = (float)x / 102.4;
    tens = laps / 10;
    srcX[0] = (tens % 5) * 4;
    srcY[0] = (tens / 5) * 8;
    ones = laps % 10;
    srcX[1] = (ones % 5) * 4;
    srcY[1] = (ones / 5) * 8;
    for (i = 0; i < 2; i++) {
        CopyRectToBgTilemapRect(hud->bgConfig, GF_BG_LYR_SUB_1, i * 4 + 14, 8, 4, 8, hud->digitScreen->rawData, srcX[i], srcY[i], 20, 16);
    }
    CopyRectToBgTilemapRect(hud->bgConfig, GF_BG_LYR_SUB_1, 24, 8, 4, 8, hud->digitScreen->rawData, (tenths % 5) * 4, (tenths / 5) * 8, 20, 16);
    ScheduleBgTilemapBufferTransfer(hud->bgConfig, GF_BG_LYR_SUB_1);
}

// The member pictures slide down one place when the members change: the leaving runner's picture drops out of
// slot rotateSlot and comes back at the top with the next member; returns TRUE when done. member: the member
// that ran (its name is shown for the one two places on).

BOOL PokeathlonRelayRunHud_RotateMonPics(PokeathlonRelayRunHud *hud, int member) {
    VecFx32 position0, position2, position3;
    u32 *state = &hud->rotateState;
    switch (*state) {
    default:
        break;
    case 0: {
        position0 = *PokeathlonCourseSpritePoolSprite_GetPosition(hud->picFrames[hud->rotateSlot]);
        position0.y += FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->picFrames[hud->rotateSlot], &position0);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->tiredMarks[hud->rotateSlot], &position0);
        if (position0.y >= FX32_CONST(736)) {
            position0.y = FX32_CONST(472);
            PokeathlonCourseSpritePoolSprite_SetPosition(hud->picFrames[hud->rotateSlot], &position0);
            PokeathlonCourseSpritePoolSprite_SetPosition(hud->tiredMarks[hud->rotateSlot], &position0);
            (*state)++;
        }
        break;
    }
    case 1:
        PokeathlonRelayRunHud_ShowMonPic(hud, (u8)hud->rotateSlot, member);
        if (hud->benchMembers[hud->rotateSlot] == 0) {
            hud->benchMembers[hud->rotateSlot] = 2;
        } else {
            hud->benchMembers[hud->rotateSlot]--;
        }
        hud->rotateSlot = (hud->rotateSlot + 1) % 2;
        (*state)++;
        break;
    case 2: {
        position2 = *PokeathlonCourseSpritePoolSprite_GetPosition(hud->picFrames[hud->rotateSlot]);
        position2.y += FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->picFrames[hud->rotateSlot], &position2);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->tiredMarks[hud->rotateSlot], &position2);
        if (position2.y >= FX32_CONST(648)) {
            position2.y = FX32_CONST(648);
            PokeathlonCourseSpritePoolSprite_SetPosition(hud->picFrames[hud->rotateSlot], &position2);
            PokeathlonCourseSpritePoolSprite_SetPosition(hud->tiredMarks[hud->rotateSlot], &position2);
            hud->rotateSlot = (hud->rotateSlot + 1) % 2;
            (*state)++;
        }
        break;
    }
    case 3: {
        position3 = *PokeathlonCourseSpritePoolSprite_GetPosition(hud->picFrames[hud->rotateSlot]);
        position3.y += FX32_CONST(32);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->picFrames[hud->rotateSlot], &position3);
        PokeathlonCourseSpritePoolSprite_SetPosition(hud->tiredMarks[hud->rotateSlot], &position3);
        if (position3.y >= FX32_CONST(560)) {
            position3.y = FX32_CONST(560);
            PokeathlonCourseSpritePoolSprite_SetPosition(hud->picFrames[hud->rotateSlot], &position3);
            PokeathlonCourseSpritePoolSprite_SetPosition(hud->tiredMarks[hud->rotateSlot], &position3);
            hud->rotateSlot = (hud->rotateSlot + 1) % 2;
            PokeathlonRelayRunHud_PrintMonName(hud, (u8)((member + 2) % POKEATHLON_TEAM_SIZE));
            *state = 0;
            return TRUE;
        }
        break;
    }
    }
    return FALSE;
}

// The same wait for a team without a player (teamId 1-3), counted without pictures; TRUE when done.
BOOL PokeathlonRelayRunHud_RotateCpuMonPics(PokeathlonRelayRunHud *hud, u32 teamId) {
    u32 i;
    GF_ASSERT(teamId != 0 && teamId < POKEATHLON_PARTICIPANTS);
    i = teamId - 1;
    hud->cpuRotations[i].y += 32;
    if (hud->cpuRotations[i].y >= 88) {
        hud->cpuRotations[i].y = 0;
        hud->cpuRotations[i].step++;
    }
    if (hud->cpuRotations[i].step >= 3) {
        hud->cpuRotations[i].step = 0;
        return TRUE;
    }
    return FALSE;
}

// A team on the track map: its running member's icon, the swap mark while it swaps, else the tired /
// exhausted mark.
void PokeathlonRelayRunHud_UpdateTeam(PokeathlonRelayRunHud *hud, u8 teamId, u8 member, u8 swapping, int condition) {
    u8 *shownMembers = hud->shownMembers;
    if (member != shownMembers[teamId]) {
        shownMembers[teamId] = member;
        PokeathlonRelayRunHud_SetMonIcon(hud, teamId, member);
    }
    if (swapping) {
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].icon, TRUE, FALSE);
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].swapMark, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].conditionMark, TRUE, FALSE);
    } else {
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].icon, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].swapMark, TRUE, FALSE);
        switch (condition) {
        case RELAY_RUN_TIRED:
            if (condition != hud->map.teams[teamId].lastCondition) {
                PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].conditionMark, TRUE, TRUE);
                PokeathlonCourseSpritePoolSprite_SetAnim(hud->map.teams[teamId].conditionMark, 8);
            }
            break;
        case RELAY_RUN_EXHAUSTED:
            if (condition != hud->map.teams[teamId].lastCondition) {
                PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].conditionMark, TRUE, TRUE);
                PokeathlonCourseSpritePoolSprite_SetAnim(hud->map.teams[teamId].conditionMark, 9);
            }
            break;
        default:
            PokeathlonCourseSpritePoolSprite_Show(hud->map.teams[teamId].conditionMark, TRUE, FALSE);
            break;
        }
    }
    hud->map.teams[teamId].lastCondition = condition;
}

// The tired marks on the pictures of the two members waiting (conditions of the members in the slots).
void PokeathlonRelayRunHud_ShowTiredMarks(PokeathlonRelayRunHud *hud, u8 condition0, u8 condition1) {
    if (condition0 == RELAY_RUN_TIRED) {
        PokeathlonCourseSpritePoolSprite_Show(hud->tiredMarks[0], TRUE, TRUE);
    } else {
        PokeathlonCourseSpritePoolSprite_Show(hud->tiredMarks[0], TRUE, FALSE);
    }
    if (condition1 == RELAY_RUN_TIRED) {
        PokeathlonCourseSpritePoolSprite_Show(hud->tiredMarks[1], TRUE, TRUE);
    } else {
        PokeathlonCourseSpritePoolSprite_Show(hud->tiredMarks[1], TRUE, FALSE);
    }
}

// The timer (frames at 30 per second): minutes, seconds and tenths.
void PokeathlonRelayRunHud_SetTimer(PokeathlonRelayRunHud *hud, int frames) {
    u8 seconds;
    u8 fraction;
    seconds = frames / 30;
    fraction = frames % 30;
    fraction = 100 * fraction / 30;
    Sprite_SetAnimCtrlSeq(hud->timerSprites[0], (u8)(seconds / 60) + 1);
    seconds = seconds % 60;
    Sprite_SetAnimCtrlSeq(hud->timerSprites[2], (u8)(seconds / 10) + 1);
    Sprite_SetAnimCtrlSeq(hud->timerSprites[3], (u8)(seconds % 10) + 1);
    Sprite_SetAnimCtrlSeq(hud->timerSprites[5], (u8)(fraction / 10) + 1);
}

// Draw priorities of the touch screen: the player's own team (own) in front on the track map.
void PokeathlonRelayRunHud_SetDrawPriorities(PokeathlonRelayRunHud *hud, int own) {
    u8 order[POKEATHLON_PARTICIPANTS];
    int i;
    u8 count;
    for (i = 0; i < 6; i++) {
        Sprite_SetDrawPriority(hud->timerSprites[i], 2);
    }
    for (i = 0; i < 2; i++) {
        Sprite_SetDrawPriority(PokeathlonCourseSpritePoolSprite_GetSprite(hud->picFrames[i]), 2);
    }
    count = 1;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (i == own) {
            order[0] = i;
        }
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (order[0] != i) {
            order[count++] = i;
        }
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(hud->map.teams[order[i]].conditionMark, i * 2 + 3);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(hud->map.teams[order[i]].swapMark, i * 2 + 3);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(hud->map.teams[order[i]].icon, i * 2 + 4);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(hud->map.teams[order[i]].colorMark, i + 11);
    }
}

// The member whose picture is in slot (0: next, 1: the one after).
u8 PokeathlonRelayRunHud_GetBenchMember(PokeathlonRelayRunHud *hud, int slot) {
    return hud->benchMembers[slot];
}

// "Next {name}" for member.
static void PokeathlonRelayRunHud_PrintMonName(PokeathlonRelayRunHud *hud, s32 member) {
    String *string;
    FillWindowPixelBuffer(&hud->nameWindow, 0);
    BufferString(hud->msgFormat, 0, hud->names[member], 2, 1, 2);
    string = ReadMsgData_ExpandPlaceholders(hud->msgFormat, hud->msgData, msg_0309_00154, hud->heapId);
    AddTextPrinterParameterizedWithColor(&hud->nameWindow, 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(&hud->nameWindow);
}

// "Laps"
static void PokeathlonRelayRunHud_PrintLaps(PokeathlonRelayRunHud *hud) {
    String *string;
    FillWindowPixelBuffer(&hud->lapsWindow, 0);
    string = NewString_ReadMsgData(hud->msgData, msg_0309_00305);
    AddTextPrinterParameterizedWithColor(&hud->lapsWindow, 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(&hud->lapsWindow);
}
