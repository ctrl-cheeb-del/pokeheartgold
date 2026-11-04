#include "global.h"

#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_course_ui.h"
#include "pokeathlon/pokeathlon_ring_drop.h"

#include "assert.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokemon_icon_idx.h"
#include "sprite_system.h"
#include "text.h"

// The UI's sprites (PokeathlonRingDropUi.sprites).
#define RING_DROP_UI_SPRITE_PLATE     0 // the own participant's plate
#define RING_DROP_UI_SPRITE_TIMER     1 // the timer label
#define RING_DROP_UI_SPRITE_ICONS     2 // the participants' Pokemon in the ring
#define RING_DROP_UI_SPRITE_SWITCHING 6 // replaces an icon while that Pokemon switches
#define RING_DROP_UI_SPRITE_RANKS     10
#define RING_DROP_UI_SPRITE_PICS      14 // the own next two team members (sub screen)
#define RING_DROP_UI_SPRITE_PIC_MARKS 16 // above them: ready (stamina at least 30)
#define RING_DROP_UI_SPRITE_COUNT     18

// The windows of the sub screen.
#define RING_DROP_UI_WINDOW_NAME      0 // the Pokemon in the ring
#define RING_DROP_UI_WINDOW_NEXT_NAME 1
#define RING_DROP_UI_WINDOW_LABEL     2
#define RING_DROP_UI_WINDOW_COUNT     3

struct PokeathlonRingDropUi {
    PokeathlonCourseData *course;
    enum HeapID heapId;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    PokeathlonCourseSpriteResources *resources; // the course sprite resources
    BgConfig *bgConfig;
    MsgData *msgData;
    MessageFormat *msgFormat;
    u16 iconPalette;
    u8 participant; // the own one
    NARC *iconNarc;
    void *digitsBuffer;
    NNSG2dScreenData *digits; // the score digits' tilemap
    Window windows[RING_DROP_UI_WINDOW_COUNT];
    ManagedSprite *sprites[RING_DROP_UI_SPRITE_COUNT];
    Sprite *timerDigits[2];
    String *memberNames[POKEATHLON_TEAM_SIZE];
    s8 switchDelays[POKEATHLON_PARTICIPANTS];
    u8 switchStep;
    u16 score;
    BOOL ranksHidden;
};

#define RING_DROP_UI_SPRITE(ui, index) (*(ManagedSprite **)((u8 *)(ui) + offsetof(PokeathlonRingDropUi, sprites) + (index) * sizeof(ManagedSprite *)))

// Sprite templates (resources 10001 and 10000) and the windows: name, next name, label.

static void PokeathlonRingDropUi_AddWindows(PokeathlonRingDropUi *ui);
static void PokeathlonRingDropUi_DrawScore(PokeathlonRingDropUi *ui, s32 score);
static void PokeathlonRingDropUi_PrintNames(PokeathlonRingDropUi *ui);
static void PokeathlonRingDropUi_PrintMessage(Window *window, MessageFormat *msgFormat, MsgData *msgData, u32 msgId, enum HeapID heapId);
static void PokeathlonRingDropUi_PrintMessageAt(Window *window, MessageFormat *msgFormat, MsgData *msgData, u32 msgId, enum HeapID heapId, s16 x, s16 y);
static void PokeathlonRingDropUi_CreateSprites(PokeathlonRingDropUi *ui);
static void PokeathlonRingDropUi_LoadMonPic(PokeathlonCourseData *course, enum HeapID heapId, ManagedSprite *sprite, u32 participant, u8 member);
static void PokeathlonRingDropUi_LoadMonIcon(PokeathlonRingDropUi *ui, u8 participant, u32 member);
static void PokeathlonRingDropUi_CreateTimerSprites(PokeathlonRingDropUi *ui);
static void PokeathlonRingDropUi_PrintNextName(PokeathlonRingDropUi *ui, s32 member);
static void PokeathlonRingDropUi_SetPicPosition(PokeathlonRingDropUi *ui, s32 sprite, s32 x, s32 y);
static void PokeathlonRingDropUi_ShowSwitching(PokeathlonRingDropUi *ui, s32 participant, BOOL switching);

static const WindowTemplate sPokeathlonRingDropUiWindowTemplates[3] = {
    {
        .bgId = GF_BG_LYR_SUB_1,
        .left = 18,
        .top = 19,
        .width = 10,
        .height = 2,
        .palette = 15,
        .baseTile = 1,
    },
    {
        .bgId = GF_BG_LYR_SUB_1,
        .left = 0,
        .top = 22,
        .width = 15,
        .height = 2,
        .palette = 15,
        .baseTile = 0x15,
    },
    {
        .bgId = GF_BG_LYR_SUB_1,
        .left = 14,
        .top = 9,
        .width = 10,
        .height = 2,
        .palette = 15,
        .baseTile = 0x33,
    },
};

static const ManagedSpriteTemplate sPokeathlonRingDropUiSpriteTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 0,
    .drawPriority = 0,
    .pal = 0,
    .vram = NNS_G2D_VRAM_TYPE_2DSUB,
    .resIdList = { 0x2711, 0x2711, 0x2711, 0x2711, 0, 0 },
    .bgPriority = 1,
    .vramTransfer = 0,
};

static const ManagedSpriteTemplate sPokeathlonRingDropUiTimerSpriteTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 0,
    .drawPriority = 0,
    .pal = 0,
    .vram = NNS_G2D_VRAM_TYPE_2DMAIN,
    .resIdList = { 0x2710, 0x2710, 0x2710, 0x2710, 0, 0 },
    .bgPriority = 1,
    .vramTransfer = 0,
};

PokeathlonRingDropUi *PokeathlonRingDropUi_New(SpriteSystem *spriteSystem, SpriteManager *spriteManager, PokeathlonCourseSpriteResources *resources, BgConfig *bgConfig, MsgData *msgData, MessageFormat *msgFormat, u8 participant, enum HeapID heapId, PokeathlonCourseData *course) {
    PokeathlonRingDropUi *ui;
    PokeathlonCourseMon *member;
    int i;

    GF_ASSERT(spriteSystem);
    GF_ASSERT(spriteManager);
    GF_ASSERT(resources);
    GF_ASSERT(bgConfig);
    GF_ASSERT(msgData);
    GF_ASSERT(msgFormat);
    ui = Heap_Alloc(heapId, sizeof(PokeathlonRingDropUi));
    MI_CpuFill8(ui, 0, sizeof(PokeathlonRingDropUi));
    ui->spriteSystem = spriteSystem;
    ui->spriteManager = spriteManager;
    ui->resources = resources;
    ui->participant = participant;
    ui->heapId = heapId;
    ui->bgConfig = bgConfig;
    ui->msgData = msgData;
    ui->msgFormat = msgFormat;
    ui->course = course;
    ui->iconNarc = NARC_New(NARC_poketool_icongra_poke_icon, ui->heapId);
    ui->digitsBuffer = GfGfxLoader_GetScrnData(NARC_a_2_4_0, 7, TRUE, &ui->digits, ui->heapId);
    ui->iconPalette = SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_poketool_icongra_poke_icon, GetMonIconPlttNaix(), FALSE, 3, NNS_G2D_VRAM_TYPE_2DSUB, 10004);
    member = PokeathlonCourse_GetParticipantMons(course, PokeathlonCourse_GetNetId(course));
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++, member++) {
        ui->memberNames[i] = String_New(11, ui->heapId);
        CopyU16ArrayToString(ui->memberNames[i], member->nickname);
    }
    PokeathlonRingDropUi_AddWindows(ui);
    return ui;
}

void PokeathlonRingDropUi_Init(PokeathlonRingDropUi *ui) {
    PokeathlonRingDropUi_CreateSprites(ui);
    PokeathlonRingDropUi_SetTimer(ui, 60);
    PokeathlonRingDropUi_DrawScore(ui, 0);
    PokeathlonRingDropUi_PrintNames(ui);
}

void PokeathlonRingDropUi_Free(PokeathlonRingDropUi *ui) {
    int i;

    GF_ASSERT(ui != NULL);
    NARC_Delete(ui->iconNarc);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        String_Delete(ui->memberNames[i]);
    }
    Heap_Free(ui->digitsBuffer);
    for (i = 0; i < RING_DROP_UI_WINDOW_COUNT; i++) {
        RemoveWindow(&ui->windows[i]);
    }
    for (i = 0; i < RING_DROP_UI_SPRITE_COUNT; i++) {
        GF_ASSERT(ui->sprites[i] != NULL);
        Sprite_DeleteAndFreeResources(ui->sprites[i]);
    }
    Heap_Free(ui);
}

void PokeathlonRingDropUi_StopAnimations(PokeathlonRingDropUi *ui) {
    int i;
    for (i = 0; i < 2; i++) {
        ManagedSprite_SetAnimateFlag(ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS + i], FALSE);
    }
}

// sorted: the participants by score, (score, participant) pairs. Ties share a rank. Redraws the own score.

void PokeathlonRingDropUi_SetRanks(PokeathlonRingDropUi *ui, u16 participant, u16 score, const u8 *sorted) {
    int rank;
    int i;

    GF_ASSERT(ui != NULL);
    GF_ASSERT(participant < POKEATHLON_PARTICIPANTS);
    rank = 0;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++, sorted += 2) {
        ManagedSprite_SetAnimNoRestart(ui->sprites[RING_DROP_UI_SPRITE_RANKS + sorted[1]], rank + 6);
        if (i != 3 && sorted[0] != sorted[2]) {
            rank = i + 1;
        }
    }
    if (participant == PokeathlonCourse_GetNetId(ui->course) && score != ui->score) {
        PokeathlonRingDropUi_DrawScore(ui, (u8)score);
        ui->score = score;
    }
}

// The ranks are hidden in the first and the last ten seconds.
void PokeathlonRingDropUi_SetTimer(PokeathlonRingDropUi *ui, s32 seconds) {
    u8 rest = seconds % 100;
    u8 tens = rest / 10;
    u8 ones = rest % 10;
    int i;
    ui->ranksHidden = seconds < 10 || seconds > 55;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        ManagedSprite_SetDrawFlag(ui->sprites[RING_DROP_UI_SPRITE_RANKS + i], !ui->ranksHidden);
    }
    Sprite_SetAnimCtrlSeq(ui->timerDigits[0], tens + 1);
    Sprite_SetAnimCtrlSeq(ui->timerDigits[1], ones + 1);
}

void PokeathlonRingDropUi_ShowNextReady(PokeathlonRingDropUi *ui, BOOL next, BOOL afterNext) {
    ManagedSprite_SetDrawFlag(ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS], next);
    ManagedSprite_SetDrawFlag(ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS + 1], afterNext);
}

u16 PokeathlonRingDropUi_GetScore(PokeathlonRingDropUi *ui) {
    return ui->score;
}

// The own switch: the next team member's picture moves down to the front, the one after it comes in at the back.
// TRUE when done.

BOOL PokeathlonRingDropUi_RunSwitch(PokeathlonRingDropUi *ui, u8 participant, u8 member) {
    u8 own = PokeathlonCourse_GetNetId(ui->course);
    u8 next = (member + 1) % POKEATHLON_TEAM_SIZE;

    switch (ui->switchStep) {
    case 0: {
        s16 x, y;
        int distance;
        ManagedSprite_GetPositionXYWithSubscreenOffset(ui->sprites[RING_DROP_UI_SPRITE_PICS + 1], &x, &y, FX32_CONST(480));
        if (y < 216) {
            distance = 272 - y;
            if (distance < 0) {
                distance = -distance;
            }
            y += (s16)(distance >> 2);
            if (y > 216) {
                y = 216;
            }
            PokeathlonRingDropUi_SetPicPosition(ui, RING_DROP_UI_SPRITE_PICS + 1, x, y);
        } else {
            x = 40;
            y = -40;
            PokeathlonRingDropUi_SetPicPosition(ui, RING_DROP_UI_SPRITE_PICS + 1, x, y);
            PokeathlonRingDropUi_LoadMonPic(ui->course, ui->heapId, ui->sprites[RING_DROP_UI_SPRITE_PICS + 1], own, member);
            PokeathlonRingDropUi_PrintNextName(ui, next);
            ui->switchStep++;
        }
        break;
    }
    case 1: {
        s16 x, y;
        s16 step;
        int distance;
        ManagedSprite_GetPositionXYWithSubscreenOffset(ui->sprites[RING_DROP_UI_SPRITE_PICS], &x, &y, FX32_CONST(480));
        distance = 136 - y;
        if (distance < 0) {
            distance = -distance;
        }
        step = distance * 3 / 4;
        if (y <= 136) {
            if (step == 0) {
                step = 1;
            }
            y += step;
            PokeathlonRingDropUi_SetPicPosition(ui, RING_DROP_UI_SPRITE_PICS, x, y);
            ManagedSprite_GetPositionXYWithSubscreenOffset(ui->sprites[RING_DROP_UI_SPRITE_PICS + 1], &x, &y, FX32_CONST(480));
            y += step;
            PokeathlonRingDropUi_SetPicPosition(ui, RING_DROP_UI_SPRITE_PICS + 1, x, y);
        } else {
            ManagedSprite *tmp = ui->sprites[RING_DROP_UI_SPRITE_PICS];
            ui->sprites[RING_DROP_UI_SPRITE_PICS] = ui->sprites[RING_DROP_UI_SPRITE_PICS + 1];
            ui->sprites[RING_DROP_UI_SPRITE_PICS + 1] = tmp;
            tmp = ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS];
            ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS] = ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS + 1];
            ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS + 1] = tmp;
            PokeathlonRingDropUi_SetPicPosition(ui, RING_DROP_UI_SPRITE_PICS, 40, 48);
            PokeathlonRingDropUi_SetPicPosition(ui, RING_DROP_UI_SPRITE_PICS + 1, 40, 136);
            ui->switchStep++;
        }
        break;
    }
    case 2:
        ui->switchStep = 0;
        return TRUE;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

// The computer participants' switches take 13 frames. TRUE when done.
BOOL PokeathlonRingDropUi_WaitSwitch(PokeathlonRingDropUi *ui, u8 participant, u8 member) {
    GF_ASSERT(participant != 0 && participant < POKEATHLON_PARTICIPANTS);
    ui->switchDelays[participant]++;
    if (ui->switchDelays[participant] > 12) {
        ui->switchDelays[participant] = 0;
        return TRUE;
    }
    return FALSE;
}

// A participant's icon while it switches (and the new member's icon after it).
void PokeathlonRingDropUi_SetSwitching(PokeathlonRingDropUi *ui, u8 participant, u32 member, BOOL switching) {
    GF_ASSERT(ui != NULL);
    GF_ASSERT(participant < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(member < POKEATHLON_TEAM_SIZE);
    if (!switching) {
        PokeathlonRingDropUi_LoadMonIcon(ui, participant, member);
    }
    PokeathlonRingDropUi_ShowSwitching(ui, participant, switching);
}

static ManagedSprite *PokeathlonRingDropUi_NewSprite(SpriteSystem *spriteSystem, SpriteManager *spriteManager, s16 x, s16 y, u16 animation, u16 priority) {
    ManagedSpriteTemplate template = sPokeathlonRingDropUiSpriteTemplate;
    ManagedSprite *sprite;
    GF_ASSERT(spriteSystem);
    GF_ASSERT(spriteManager);
    template.x = x;
    template.y = y;
    template.animation = animation;
    template.drawPriority = priority;
    sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, FX32_CONST(480));
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    return sprite;
}

static void PokeathlonRingDropUi_AddWindows(PokeathlonRingDropUi *ui) {
    u8 i;
    GF_ASSERT(ui != NULL);
    GF_ASSERT(ui->bgConfig != NULL);
    for (i = 0; i < RING_DROP_UI_WINDOW_COUNT; i++) {
        AddWindow(ui->bgConfig, &ui->windows[i], &sPokeathlonRingDropUiWindowTemplates[i]);
    }
    BG_FillCharDataRange(ui->bgConfig, GF_BG_LYR_SUB_1, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_15_OFFSET, ui->heapId);
}

// The own score, three digits from the digits tilemap (5 digits per row, 4x8 tiles each).
static void PokeathlonRingDropUi_DrawScore(PokeathlonRingDropUi *ui, s32 score) {
    u8 tileX[3];
    u8 tileY[3];
    u8 digit;
    u8 i;
    digit = score / 100;
    tileX[0] = (digit % 5) * 4;
    tileY[0] = (digit / 5) * 8;
    digit = (score - digit * 100) / 10;
    tileX[1] = (digit % 5) * 4;
    tileY[1] = (digit / 5) * 8;
    digit = score % 10;
    tileX[2] = (digit % 5) * 4;
    tileY[2] = (digit / 5) * 8;
    for (i = 0; i < 3; i++) {
        CopyRectToBgTilemapRect(ui->bgConfig, GF_BG_LYR_SUB_2, 16 + i * 4, 11, 4, 8, ui->digits->rawData, tileX[i], tileY[i], 20, 16);
    }
    ScheduleBgTilemapBufferTransfer(ui->bgConfig, GF_BG_LYR_SUB_2);
}

static void PokeathlonRingDropUi_PrintNames(PokeathlonRingDropUi *ui) {
    String *name;
    FillWindowPixelBuffer(&ui->windows[RING_DROP_UI_WINDOW_NAME], 0);
    name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(ui->course, ui->participant), ui->heapId);
    AddTextPrinterParameterizedWithColor(&ui->windows[RING_DROP_UI_WINDOW_NAME], 0, name, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    PokeathlonRingDropUi_PrintMessageAt(&ui->windows[RING_DROP_UI_WINDOW_LABEL], ui->msgFormat, ui->msgData, msg_0309_00304, ui->heapId, 2, 2);
    String_Delete(name);
    CopyWindowToVram(&ui->windows[RING_DROP_UI_WINDOW_NAME]);
    BufferString(ui->msgFormat, 0, ui->memberNames[1], 2, 1, 2);
    PokeathlonRingDropUi_PrintMessage(&ui->windows[RING_DROP_UI_WINDOW_NEXT_NAME], ui->msgFormat, ui->msgData, msg_0309_00154, ui->heapId);
}

static void PokeathlonRingDropUi_PrintMessage(Window *window, MessageFormat *msgFormat, MsgData *msgData, u32 msgId, enum HeapID heapId) {
    PokeathlonRingDropUi_PrintMessageAt(window, msgFormat, msgData, msgId, heapId, 0, 0);
}

static void PokeathlonRingDropUi_PrintMessageAt(Window *window, MessageFormat *msgFormat, MsgData *msgData, u32 msgId, enum HeapID heapId, s16 x, s16 y) {
    String *string;
    FillWindowPixelBuffer(window, 0);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msgId, heapId);
    AddTextPrinterParameterizedWithColor(window, 0, string, x, y, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(window);
}

static void PokeathlonRingDropUi_CreateSprites(PokeathlonRingDropUi *ui) {
    ManagedSpriteTemplate template = { 0 };
    int i;
    s16 x;

    ui->sprites[RING_DROP_UI_SPRITE_PLATE] = PokeathlonRingDropUi_NewSprite(ui->spriteSystem, ui->spriteManager, 134, 160, ui->participant + 12, 6);
    ManagedSprite_SetPaletteOverride(ui->sprites[RING_DROP_UI_SPRITE_PLATE], 1);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        x = i * 32 + 120;
        ui->sprites[RING_DROP_UI_SPRITE_ICONS + i] = PokeathlonRingDropUi_NewSprite(ui->spriteSystem, ui->spriteManager, x, 36, i + 1, 5);
        PokeathlonRingDropUi_LoadMonIcon(ui, i, 0);
        ui->sprites[RING_DROP_UI_SPRITE_SWITCHING + i] = PokeathlonRingDropUi_NewSprite(ui->spriteSystem, ui->spriteManager, x, 36, 10, 4);
        ManagedSprite_SetDrawFlag(ui->sprites[RING_DROP_UI_SPRITE_SWITCHING + i], FALSE);
        ui->sprites[RING_DROP_UI_SPRITE_RANKS + i] = PokeathlonRingDropUi_NewSprite(ui->spriteSystem, ui->spriteManager, i * 32 + 120, 24, 6, 0);
        ManagedSprite_SetDrawFlag(ui->sprites[RING_DROP_UI_SPRITE_RANKS + i], FALSE);
    }
    for (i = 0; i < 2; i++) {
        template.resIdList[0] = 10002 + i;
        template.resIdList[1] = 10002 + i;
        template.resIdList[2] = 10002;
        template.resIdList[3] = 10002;
        template.vram = NNS_G2D_VRAM_TYPE_2DSUB;
        template.x = 40;
        template.y = i * 88 + 48;
        template.drawPriority = i + 2;
        template.bgPriority = 2;
        ui->sprites[RING_DROP_UI_SPRITE_PICS + i] = SpriteSystem_NewSpriteWithYOffset(ui->spriteSystem, ui->spriteManager, &template, FX32_CONST(480));
        ManagedSprite_SetAnimateFlag(ui->sprites[RING_DROP_UI_SPRITE_PICS + i], TRUE);
    }
    for (i = 0; i < 2; i++) {
        PokeathlonRingDropUi_LoadMonPic(ui->course, ui->heapId, ui->sprites[RING_DROP_UI_SPRITE_PICS + i], ui->participant, 2 - i);
        ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS + i] = PokeathlonRingDropUi_NewSprite(ui->spriteSystem, ui->spriteManager, 40, i * 88 + 24, 5, 1);
        ManagedSprite_SetDrawFlag(ui->sprites[RING_DROP_UI_SPRITE_PIC_MARKS + i], FALSE);
    }
    PokeathlonRingDropUi_CreateTimerSprites(ui);
}

static void PokeathlonRingDropUi_LoadMonPic(PokeathlonCourseData *course, enum HeapID heapId, ManagedSprite *sprite, u32 participant, u8 member) {
    PokeathlonCourseMonInfo info;
    PokeathlonCourse_GetMonInfo(course, participant, member, &info);
    PokeathlonCourse_LoadMonPic(sprite, &info, FALSE, 0, heapId);
}

static void PokeathlonRingDropUi_LoadMonIcon(PokeathlonRingDropUi *ui, u8 participant, u32 member) {
    PokeathlonCourseMonInfo info;
    ManagedSprite *sprite = ui->sprites[participant + RING_DROP_UI_SPRITE_ICONS];
    PokeathlonCourse_GetMonInfo(ui->course, participant, member, &info);
    PokeathlonCourse_LoadMonIcon(sprite, &info, ui->iconPalette, ui->iconNarc, participant << 9, ui->heapId);
}

static ManagedSprite *PokeathlonRingDropUi_NewTimerSprite(SpriteSystem *spriteSystem, SpriteManager *spriteManager, u16 x, u16 y, u16 animation, u16 priority) {
    ManagedSpriteTemplate template = sPokeathlonRingDropUiTimerSpriteTemplate;
    ManagedSprite *sprite;
    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    template.x = x;
    template.y = y;
    template.animation = animation;
    template.drawPriority = priority;
    sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, FX32_CONST(480));
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    return sprite;
}

static void PokeathlonRingDropUi_CreateTimerSprites(PokeathlonRingDropUi *ui) {
    s32 i;
    PokeathlonRingDropUi *cursor;
    s32 x;
    ManagedSprite *sprite;

    sprite = PokeathlonRingDropUi_NewTimerSprite(ui->spriteSystem, ui->spriteManager, 114, 180, 20, 1);
    ui->sprites[RING_DROP_UI_SPRITE_TIMER] = sprite;
    ManagedSprite_SetPaletteOverride(sprite, 14);
    i = 0;
    cursor = ui;
    x = 134;
    for (; i < 2; i++) {
        s32 matrix[3] = { 0, 0, 0 };
        s32 position;
        cursor->timerDigits[0] = PokeathlonCourse_CreateTimerDigitSprite(ui->resources, SpriteManager_GetSpriteList(ui->spriteManager), 1, ui->heapId);
        position = x;
        position <<= FX32_SHIFT;
        matrix[0] = position;
        matrix[1] = FX32_CONST(180);
        matrix[2] = 0;
        Sprite_SetMatrix(cursor->timerDigits[0], (VecFx32 *)matrix);
        Sprite_SetDrawFlag(cursor->timerDigits[0], TRUE);
        cursor = (PokeathlonRingDropUi *)((u8 *)cursor + sizeof(Sprite *));
        x += 16;
    }
}

static void PokeathlonRingDropUi_PrintNextName(PokeathlonRingDropUi *ui, s32 member) {
    s32 index;
    index = (member + 1) % POKEATHLON_TEAM_SIZE;
    index = (u8)index;
    BufferString(ui->msgFormat, 0, ui->memberNames[index], 2, 1, 2);
    PokeathlonRingDropUi_PrintMessage(&ui->windows[RING_DROP_UI_WINDOW_NEXT_NAME], ui->msgFormat, ui->msgData, msg_0309_00154, ui->heapId);
}

static void PokeathlonRingDropUi_SetPicPosition(PokeathlonRingDropUi *ui, s32 sprite, s32 x, s32 y) {
    ((void (*)(ManagedSprite *, s32, s32, fx32))ManagedSprite_SetPositionXYWithSubscreenOffset)(ui->sprites[sprite], x, y, FX32_CONST(480));
    ((void (*)(ManagedSprite *, s32, s32, fx32))ManagedSprite_SetPositionXYWithSubscreenOffset)(ui->sprites[sprite + 2], x, (s16)(y - 24), FX32_CONST(480));
}

static void PokeathlonRingDropUi_ShowSwitching(PokeathlonRingDropUi *ui, s32 participant, BOOL switching) {
    ManagedSprite_SetDrawFlag(RING_DROP_UI_SPRITE(ui, participant + RING_DROP_UI_SPRITE_ICONS), !switching);
    ManagedSprite_SetDrawFlag(RING_DROP_UI_SPRITE(ui, participant + RING_DROP_UI_SPRITE_SWITCHING), switching);
}
