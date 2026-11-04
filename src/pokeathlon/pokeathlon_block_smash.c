#include "pokeathlon/pokeathlon_block_smash.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_course_ui.h"
#include "pokeathlon/pokeathlon_event_points.h"
#include "pokeathlon/pokeathlon_pennant_capture.h"

#include "assert.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "pm_string.h"
#include "pokemon_icon_idx.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite_resource_header.h"
#include "sprite_system.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"

enum {
    BLOCK_SMASH_STATE_INTRO,
    BLOCK_SMASH_STATE_PLAY,
    BLOCK_SMASH_STATE_FINISH,
};

enum PokeathlonBlockSmashInitState {
    BLOCK_SMASH_INIT_CREATE,
    BLOCK_SMASH_INIT_LOAD_BGS,
    BLOCK_SMASH_INIT_LOAD_MONS,
    BLOCK_SMASH_INIT_WAIT_MONS,
    BLOCK_SMASH_INIT_CREATE_BLOCKS,
    BLOCK_SMASH_INIT_CREATE_TEAMS,
    BLOCK_SMASH_INIT_SEND_REPORT,
    BLOCK_SMASH_INIT_WAIT_FADE_IN,
};

typedef struct PokeathlonBlockSmashBgTemplates {
    BgTemplate templates[6];
} PokeathlonBlockSmashBgTemplates;

PokeathlonBlockSmashMon *PokeathlonBlockSmashMon_New(enum HeapID heapId, SpriteSystem *spriteSystem, SpriteManager *spriteManager, PokeathlonCourseData *course);
void PokeathlonBlockSmashMon_Delete(PokeathlonBlockSmashMon *mon);
void PokeathlonBlockSmashMon_Update(PokeathlonBlockSmashMon *mon, BOOL stackDropping);
void PokeathlonBlockSmashMon_OnHit(PokeathlonBlockSmashMon *mon, BOOL hitSpot, int broken);
void PokeathlonBlockSmashMon_StartSwitch(PokeathlonBlockSmashMon *mon);
void PokeathlonBlockSmashMon_SetAnimate(PokeathlonBlockSmashMon *mon, BOOL animate);
u8 PokeathlonBlockSmashMon_GetMode(PokeathlonBlockSmashMon *mon);
PokeathlonBlockSmashMember *PokeathlonBlockSmashMon_GetActiveMember(PokeathlonBlockSmashMon *mon);
BOOL PokeathlonBlockSmashMon_CanSwitch(PokeathlonBlockSmashMon *mon);
BOOL PokeathlonBlockSmashMon_IsGaugeFull(PokeathlonBlockSmashMon *mon);
BOOL PokeathlonBlockSmashMon_IsTired(PokeathlonBlockSmashMon *mon);
u16 PokeathlonBlockSmashMon_GetGauge(PokeathlonBlockSmashMon *mon);
u8 PokeathlonBlockSmashMon_GetActiveMemberIndex(PokeathlonBlockSmashMon *mon);
BOOL PokeathlonBlockSmashMon_CanHit(PokeathlonBlockSmashMon *mon);
PokeathlonBlockSmashRivals *PokeathlonBlockSmashRivals_New(enum HeapID heapId, SpriteSystem *spriteSystem, SpriteManager *spriteManager, PokeathlonCourseData *course, PokeathlonCourseMonObjects *monPics);
void PokeathlonBlockSmashRivals_Delete(PokeathlonBlockSmashRivals *rivals);
void PokeathlonBlockSmashRivals_Update(PokeathlonBlockSmashRivals *rivals);
void PokeathlonBlockSmashRivals_Pause(PokeathlonBlockSmashRivals *rivals);
PokeathlonBlockSmashCpu *PokeathlonBlockSmashCpu_New(PokeathlonCourseData *course, enum HeapID heapId);
void PokeathlonBlockSmashCpu_Delete(PokeathlonBlockSmashCpu *cpu);
void PokeathlonBlockSmashCpu_Update(PokeathlonBlockSmashCpu *cpu);
void PokeathlonBlockSmashCpu_WriteReports(PokeathlonBlockSmashCpu *cpu);
ManagedSprite *PokeathlonBlockSmash_NewMainSprite(SpriteSystem *spriteSystem, SpriteManager *spriteManager, u16 x, u16 y, u16 anim, u16 priority);
ManagedSprite *PokeathlonBlockSmash_NewSubSprite(SpriteSystem *spriteSystem, SpriteManager *spriteManager, s16 x, s16 y, u16 anim, u8 priority);

// The sprites of a participant's row on the top screen
typedef struct PokeathlonBlockSmashRowSprites {
    u32 unk0;
    u32 bar;
    u32 star;
} PokeathlonBlockSmashRowSprites;

static void PokeathlonBlockSmash_SetVramBanks(void);
static void PokeathlonBlockSmash_InitSpriteSystem(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_FreeSpriteSystem(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_CreateHudSprites(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_DeleteHudSprites(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_LoadSpriteResources(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_LoadMainAndSubSpriteRes(SpriteSystem *spriteSystem, SpriteManager *spriteManager);
static void PokeathlonBlockSmash_UpdateScoreDigits(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_StopHudAnims(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_InitBgs(BgConfig *bgConfig, enum HeapID heapId);
static void PokeathlonBlockSmash_FreeBgsAndText(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_LoadBgGraphics(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_InitText(PokeathlonCourseData *course);
static void PokeathlonBlockSmash_UpdateTimer(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_PrintInitialText(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_PrintMessage(Window *window, MessageFormat *msgFormat, MsgData *msgData, u32 msgId, enum HeapID heapId);
static void PokeathlonBlockSmash_CreateTeamRows(PokeathlonCourseData *course);
static void PokeathlonBlockSmash_DeleteTeamRows(PokeathlonBlockSmash *work);
static void PokeathlonBlockSmash_UpdateTeamRows(PokeathlonCourseData *course);
static void PokeathlonBlockSmash_SetTeamRowIcon(PokeathlonCourseData *course, u32 participant, u32 member);
static void PokeathlonBlockSmash_HandleSwipe(PokeathlonBlockSmash *work, BOOL anywhere);
static void PokeathlonBlockSmash_WriteReport(PokeathlonCourseData *course);
static void PokeathlonBlockSmash_UpdateLinkData(PokeathlonCourseData *course);
static void PokeathlonBlockSmash_PrintScore(PokeathlonCourseData *course, u32 score);
static void PokeathlonBlockSmash_StartShake(PokeathlonBlockSmash *work, int offset, int decay);

static const PokeathlonCoursePoint sPokeathlonBlockSmashBannerPosition = { 120, 132 };

static const TouchscreenHitbox sPokeathlonBlockSmashSwipeHitboxes[] = {
    { .rect = { 8, 32, 0, 64 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const GraphicsModes sPokeathlonBlockSmashGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const OamCharTransferParam sPokeathlonBlockSmashOamCharTransferParam = {
    .maxTasks = 0,
    .sizeMain = 0x40000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_256K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_256K,
};

static const u32 sPokeathlonBlockSmashBgLayers[6] = { GF_BG_LYR_MAIN_0, GF_BG_LYR_MAIN_1, GF_BG_LYR_MAIN_2, GF_BG_LYR_SUB_0, GF_BG_LYR_SUB_1, GF_BG_LYR_SUB_2 };

static const SpriteResourceCountsListUnion sPokeathlonBlockSmashSpriteResourceCounts = {
    .numChar = 9,
    .numPltt = 10,
    .numCell = 7,
    .numAnim = 7,
    .numMcel = 0,
    .numManm = 0,
};

static const WindowTemplate sPokeathlonBlockSmashWindowTemplates[4] = {
    { GF_BG_LYR_MAIN_1, 6,  22, 4,  2, 15, 1    },
    { GF_BG_LYR_MAIN_1, 25, 22, 7,  2, 15, 9    },
    { GF_BG_LYR_MAIN_2, 0,  20, 32, 2, 15, 0x17 },
    { GF_BG_LYR_SUB_2,  0,  22, 15, 2, 15, 1    },
};

static const OamManagerParam sPokeathlonBlockSmashOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 126,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 1,
    .numOBJsub = 126,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const GraphicsBanks sPokeathlonBlockSmashGraphicsBanks = {
    .bg = GX_VRAM_BG_64_E,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_256_AB,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

static const PokeathlonBlockSmashRowSprites sPokeathlonBlockSmashRowSprites[4] = {
    { 1,  2,  3  },
    { 4,  5,  6  },
    { 7,  8,  9  },
    { 10, 11, 12 },
};

static const PokeathlonBlockSmashBgTemplates sPokeathlonBlockSmashBgTemplates = {
    {
     {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
     {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0800,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
     {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x0c000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
     {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
     {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0800,
            .charBase = GX_BG_CHARBASE_0x0c000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
     {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
     },
};

BOOL PokeathlonPennantCaptureCpu_IsNearCellTarget(PokeathlonCourseCpuCell *cell, s32 x, s32 y) {
    s32 left = cell->targetX - 16;
    s32 right = cell->targetX + 16;
    s32 top = cell->targetY - 16;
    s32 bottom = cell->targetY + 16;
    if (left <= x && x < right && top <= y && y < bottom) {
        return TRUE;
    }
    return FALSE;
}

// The field is narrower below y = 392 (the goal opening).
BOOL PokeathlonPennantCaptureCpu_IsCellTargetOnField(PokeathlonCourseCpuCell *cell) {
    s32 y = cell->targetY;
    BOOL right;
    BOOL left;
    if (y < 104) {
        return FALSE;
    }
    if (y <= 392) {
        right = cell->targetX >= 144;
        left = cell->targetX <= 368;
        if (right & left) {
            return TRUE;
        }
    } else {
        right = cell->targetX >= 208;
        left = cell->targetX <= 304;
        if (right & left) {
            return TRUE;
        }
    }
    return FALSE;
}

enum PokeathlonBlockSmashIntroState {
    BLOCK_SMASH_INTRO_WAIT_BLOCKS,
    BLOCK_SMASH_INTRO_COUNTDOWN,
};

// Event state 0: wait for the first stack, then show the start banner.
BOOL PokeathlonBlockSmash_Intro(PokeathlonCourseData *course, u8 *state) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    switch (*state) {
    case BLOCK_SMASH_INTRO_WAIT_BLOCKS:
        PokeathlonBlockSmashBlocks_Update(work->blocks);
        if (PokeathlonBlockSmashBlocks_GetState(work->blocks) == BLOCKS_STATE_READY) {
            PokeathlonCoursePoint position;
            SpriteList *spriteList;
            position = sPokeathlonBlockSmashBannerPosition;
            spriteList = SpriteManager_GetSpriteList(work->spriteManager);
            PokeathlonCourse_CreateStartSprites(course, 0, work->iconResources, spriteList, NNS_G2D_VRAM_TYPE_2DMAIN, 1, &position);
            (*state)++;
        }
        break;
    case BLOCK_SMASH_INTRO_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            PokeathlonCourseObjects_PauseAnims(work->monPics, FALSE);
            PokeathlonCourse_SetNextState(course, BLOCK_SMASH_STATE_PLAY);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

// Returns TRUE once the host's frame says the event is over.
static BOOL PokeathlonBlockSmash_UpdateGame(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    int state;
    BOOL touched;
    PokeathlonBlockSmashMember *member;
    u32 strongHit;
    int hitSpot;
    int broken;
    if (((PokeathlonBlockSmashFrame *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN))->finished == 1) {
        PokeathlonBlockSmash_PrintScore(course, PokeathlonBlockSmashBlocks_GetScore(work->blocks));
        PokeathlonBlockSmash_StopHudAnims(work);
        PokeathlonBlockSmashMon_SetAnimate(work->mon, FALSE);
        PokeathlonBlockSmashRivals_Pause(work->rivals);
        PokeathlonBlockSmashBlocks_Pause(work->blocks);
        PokeathlonCourseObjects_PauseAnims(work->monPics, TRUE);
        return TRUE;
    }
    if (System_GetTouchNew()) {
        PokeathlonCourse_AddMonCounter(course, PokeathlonCourse_GetNetId(course), 3, POKEATHLON_COUNTER_INSTRUCTIONS, 1);
    }
    PokeathlonBlockSmash_UpdateTimer(work);
    PokeathlonBlockSmashBlocks_Update(work->blocks);
    state = PokeathlonBlockSmashBlocks_GetState(work->blocks);
    PokeathlonBlockSmashMon_Update(work->mon, state == BLOCKS_STATE_DROPPING);
    if (PokeathlonCourse_GetNetId(course) == 0) {
        PokeathlonBlockSmashCpu_Update(work->cpu);
    }
    PokeathlonBlockSmashRivals_Update(work->rivals);
    touched = PokeathlonBlockSmashBlocks_IsTopBlockTouched(work->blocks);
    PokeathlonBlockSmash_HandleSwipe(work, touched);
    if (PokeathlonBlockSmashMon_CanHit(work->mon) && state == BLOCKS_STATE_READY && touched) {
        member = PokeathlonBlockSmashMon_GetActiveMember(work->mon);
        strongHit = PokeathlonBlockSmashMon_IsGaugeFull(work->mon);
        hitSpot = PokeathlonBlockSmashBlocks_IsSpotTouched(work->blocks, member->kind);
        {
            int count = PokeathlonBlockSmashBlocks_Hit(work->blocks, PokeathlonBlockSmashMon_GetActiveMemberIndex(work->mon), (u16)member->power, hitSpot, strongHit, &broken);
            PokeathlonBlockSmashMon_OnHit(work->mon, hitSpot, count);
        }
        PokeathlonBlockSmash_UpdateScoreDigits(work);
        if (hitSpot) {
            PokeathlonBlockSmash_StartShake(work, 16, 2);
        } else if (broken) {
            PokeathlonBlockSmash_StartShake(work, 4, 1);
        } else if (PokeathlonBlockSmashMon_IsGaugeFull(work->mon)) {
            PokeathlonBlockSmash_StartShake(work, 4, 1);
        }
    }
    if (work->timer > 0) {
        work->timer--;
    }
    PokeathlonCourse_UpdateTimeUpCountdown(course, work->timer);
    if (work->timer == 0 && PokeathlonCourse_GetNetId(course) == 0) {
        PokeathlonBlockSmashFrame *frame = (PokeathlonBlockSmashFrame *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT);
        frame->finished = TRUE;
    }
    return FALSE;
}

enum PokeathlonBlockSmashPlayState {
    BLOCK_SMASH_PLAY_RUN,
    BLOCK_SMASH_PLAY_FINISH,
};

// Event state 1: play until the host ends the event and the shake is over, then fade out.
BOOL PokeathlonBlockSmash_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    switch (*state) {
    case BLOCK_SMASH_PLAY_RUN:
        PokeathlonBlockSmash_UpdateLinkData(course);
        PokeathlonBlockSmash_UpdateTeamRows(course);
        if (PokeathlonBlockSmash_UpdateGame(course)) {
            (*state)++;
        }
        break;
    case BLOCK_SMASH_PLAY_FINISH:
        if (PokeathlonCourse_RunFinish(course) && work->shakeTask == NULL) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, work->heapId);
            PokeathlonCourse_SetNextState(course, BLOCK_SMASH_STATE_FINISH);
        }
        break;
    }
    return FALSE;
}

// Event state 2: after the fade, store the scores (the host also those of the CPU participants).
BOOL PokeathlonBlockSmash_Finish(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    u32 participant;
    s32 count;
    u32 offset;
    u16 score;
    if (IsPaletteFadeFinished()) {
        participant = PokeathlonCourse_GetNetId(course);
        score = PokeathlonBlockSmashBlocks_GetScore(work->blocks);
        PokeathlonCourse_SetEventScore(course, (u8)participant, score);
        if (participant == 0) {
            count = PokeathlonCourse_GetParticipantCount(course);
            if (count < 4) {
                offset = count * POKEATHLON_COURSE_DATA_SLOT_SIZE;
                do {
                    u8 *block = PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_INPUTS + offset;
                    PokeathlonCourse_SetEventScore(course, (u8)count, ((PokeathlonBlockSmashReport *)PokeathlonCourse_ToBytes(block))->score);
                    count++;
                    offset += POKEATHLON_COURSE_DATA_SLOT_SIZE;
                } while (count < 4);
            }
        }
        return TRUE;
    }
    return FALSE;
}

// Sets up the event over several frames; TRUE when done.
BOOL PokeathlonBlockSmash_Init(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    int i, j;
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case BLOCK_SMASH_INIT_CREATE:
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_141, 0x60000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonBlockSmash_SetVramBanks();
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        work = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonBlockSmash));
        MI_CpuFill8(work, 0, sizeof(PokeathlonBlockSmash));
        work->heapId = HEAP_ID_141;
        work->timer = 900;
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case BLOCK_SMASH_INIT_LOAD_BGS:
        work->bgConfig = BgConfig_Alloc(work->heapId);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG2);
        PokeathlonBlockSmash_InitBgs(work->bgConfig, work->heapId);
        PokeathlonBlockSmash_InitText(course);
        PokeathlonBlockSmash_LoadBgGraphics(work);
        PokeathlonBlockSmash_InitSpriteSystem(work);
        work->monPics = PokeathlonCourseMonObjects_Create(work->heapId, 9, 32, work->iconResources, SpriteManager_GetSpriteList(work->spriteManager));
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case BLOCK_SMASH_INIT_LOAD_MONS: {
        PokeathlonCourseMonInfo mons[9];
        int count = 0;
        PokeathlonCourseMonGfxTemplate params = { 0 };
        for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
            if (i != PokeathlonCourse_GetNetId(course)) {
                for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                    GF_ASSERT(count < 9);
                    PokeathlonCourse_GetMonInfo(course, i, j, &mons[count]);
                    params.sizeTypes[count] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, i, j));
                    count++;
                }
            }
        }
        params.priority = 1;
        params.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        params.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(work->monPics, 9, mons, &params, 0, 0);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case BLOCK_SMASH_INIT_WAIT_MONS:
        if (PokeathlonCourseMonObjects_IsLoaded(work->monPics)) {
            PokeathlonBlockSmash_LoadSpriteResources(work);
            PokeathlonBlockSmash_LoadMainAndSubSpriteRes(work->spriteSystem, work->spriteManager);
            Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSprites(course, 0, work->iconResources, SpriteManager_GetSpriteList(work->spriteManager)), 0);
            PokeathlonCourse_AdvanceEventInitState(course);
        }
        break;
    case BLOCK_SMASH_INIT_CREATE_BLOCKS:
        PokeathlonBlockSmash_CreateHudSprites(work);
        work->blocks = PokeathlonBlockSmashBlocks_New(work->heapId, work->spriteSystem, work->spriteManager, course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case BLOCK_SMASH_INIT_CREATE_TEAMS:
        work->mon = PokeathlonBlockSmashMon_New(work->heapId, work->spriteSystem, work->spriteManager, course);
        work->rivals = PokeathlonBlockSmashRivals_New(work->heapId, work->spriteSystem, work->spriteManager, course, work->monPics);
        PokeathlonCourseObjects_PauseAnims(work->monPics, TRUE);
        if (PokeathlonCourse_GetNetId(course) == 0) {
            work->cpu = PokeathlonBlockSmashCpu_New(course, work->heapId);
        }
        PokeathlonBlockSmash_PrintInitialText(work);
        PokeathlonBlockSmash_CreateTeamRows(course);
        PokeathlonCourse_SetVBlankIntrCB(work->bgConfig);
        WirelessStatusIcon_CreateOnScreenIfConnected(1);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonBlockSmashCpu_WriteReports(work->cpu);
        }
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 6, 1, work->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case BLOCK_SMASH_INIT_SEND_REPORT:
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonBlockSmash_WriteReport(course);
        }
        PokeathlonBlockSmash_UpdateLinkData(course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case BLOCK_SMASH_INIT_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

BOOL PokeathlonBlockSmash_Draw(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    SpriteSystem_DrawSprites(work->spriteManager);
    return TRUE;
}

BOOL PokeathlonBlockSmash_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *graphics = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    PokeathlonCourseScoreList_Init(graphics);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        u16 value = PokeathlonCourse_GetReceivedScore(course, (u8)i);
        PokeathlonCourse_AddScoreEntry(course, graphics, i, value, 0, 3, msg_0309_00294);
    }
    PokeathlonCourseScoreList_Rank(graphics, 1);
    PokeathlonEvent_CalcPoints(graphics, 3);
    PokeathlonCourseScoreList_AddPointsToTotals(graphics);
    PokeathlonCourseScoreList_SaveEventPoints(graphics, 3);
    return TRUE;
}

// Frees everything Init created.
BOOL PokeathlonBlockSmash_Exit(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    PokeathlonBlockSmash_DeleteTeamRows(work);
    if (!PokeathlonCourse_GetNetId(course)) {
        PokeathlonBlockSmashCpu_Delete(work->cpu);
    }
    PokeathlonBlockSmashBlocks_Delete(work->blocks);
    PokeathlonBlockSmashRivals_Delete(work->rivals);
    PokeathlonBlockSmashMon_Delete(work->mon);
    PokeathlonBlockSmash_DeleteHudSprites(work);
    PokeathlonBlockSmash_FreeSpriteSystem(work);
    PokeathlonBlockSmash_FreeBgsAndText(work);
    WirelessStatusIcon_Destroy();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    Heap_Destroy(HEAP_ID_141);
    return TRUE;
}

static void PokeathlonBlockSmash_SetVramBanks(void) {
    GraphicsBanks banks = sPokeathlonBlockSmashGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokeathlonBlockSmash_InitSpriteSystem(PokeathlonBlockSmash *work) {
    SpriteResourceCountsListUnion counts = sPokeathlonBlockSmashSpriteResourceCounts;
    OamManagerParam oamParam = sPokeathlonBlockSmashOamManagerParam;
    OamCharTransferParam transferParam = sPokeathlonBlockSmashOamCharTransferParam;
    transferParam.maxTasks = 128;
    work->spriteSystem = SpriteSystem_Alloc(work->heapId);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    SpriteSystem_Init(work->spriteSystem, &oamParam, &transferParam, 32);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 256);
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, FX32_CONST(256));
    work->iconResources = PokeathlonCourseSprites_CreateResources(work->heapId, 743, NNS_G2D_VRAM_TYPE_2DMAIN);
    work->icons.narc = NARC_New(NARC_poketool_icongra_poke_icon, work->heapId);
}

static void PokeathlonBlockSmash_FreeSpriteSystem(PokeathlonBlockSmash *work) {
    NARC_Delete(work->icons.narc);
    PokeathlonCourseMonObjects_Free(work->monPics);
    PokeathlonCourseSprites_FreeResources(work->iconResources);
    SpriteSystem_FreeResourcesAndManager(work->spriteSystem, work->spriteManager);
    SpriteSystem_Free(work->spriteSystem);
}

// The timer (top screen), the score frame and the digits.
static void PokeathlonBlockSmash_CreateHudSprites(PokeathlonBlockSmash *work) {
    VecFx32 position = { 0, 0, 0 };
    int i;
    fx32 x = FX32_CONST(8);
    for (i = 0; i < 3; i++) {
        position.x = x;
        position.y = FX32_CONST(176);
        work->scoreDigits[i] = PokeathlonCourseSprites_CreateTimeUpCountdown(work->iconResources, SpriteManager_GetSpriteList(work->spriteManager), 0, work->heapId);
        Sprite_SetMatrix(work->scoreDigits[i], &position);
        Sprite_SetDrawPriority(work->scoreDigits[i], 2);
        Sprite_SetAnimCtrlSeq(work->scoreDigits[i], 1);
        Sprite_SetDrawFlag(work->scoreDigits[i], TRUE);
        x += FX32_CONST(16);
    }
    work->timerFrame = PokeathlonBlockSmash_NewMainSprite(work->spriteSystem, work->spriteManager, 192, 184, 25, 2);
    for (i = 0; i < 2; i++) {
        VecFx32 digitPosition = { 0, 0, 0 };
        work->timerDigits[i] = PokeathlonCourse_CreateTimerDigitSprite(work->iconResources, SpriteManager_GetSpriteList(work->spriteManager), 2, work->heapId);
        digitPosition.x = (212 + i * 16) << FX32_SHIFT;
        digitPosition.y = 184 << FX32_SHIFT;
        digitPosition.z = 0;
        Sprite_SetMatrix(work->timerDigits[i], &digitPosition);
        Sprite_SetDrawFlag(work->timerDigits[i], TRUE);
    }
    work->switchButton = PokeathlonBlockSmash_NewMainSprite(work->spriteSystem, work->spriteManager, 32, 16, 19, 2);
}

static void PokeathlonBlockSmash_DeleteHudSprites(PokeathlonBlockSmash *work) {
    s32 i;
    GF_ASSERT(work != NULL);
    for (i = 0; i < 2; i++, work = (PokeathlonBlockSmash *)((u8 *)work + sizeof(ManagedSprite *))) {
        GF_ASSERT(work->timerFrame != NULL);
        Sprite_DeleteAndFreeResources(work->timerFrame);
    }
}

static void PokeathlonBlockSmash_LoadSpriteResources(PokeathlonBlockSmash *work) {
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    spriteManager = work->spriteManager;
    spriteSystem = work->spriteSystem;
    NNS_G2D_VRAM_TYPE vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 8, TRUE, vram, 10000);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 7, FALSE, 2, vram, 10000);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 9, TRUE, 10000);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 10, TRUE, 10000);
    vram = NNS_G2D_VRAM_TYPE_2DSUB;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 12, TRUE, vram, 10001);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 11, FALSE, 3, vram, 10001);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 13, TRUE, 10001);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 14, TRUE, 10001);
    work->icons.plttId = SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_poketool_icongra_poke_icon, GetMonIconPlttNaix(), FALSE, 3, vram, 10002);
}

#pragma opt_propagation off

static void PokeathlonBlockSmash_LoadMainAndSubSpriteRes(SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    int i;
    NNS_G2D_VRAM_TYPE vram;
    vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 16, TRUE, vram, 10002);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 15, FALSE, 1, vram, 10003);
    vram = NNS_G2D_VRAM_TYPE_2DSUB;
    i = 0;
    do {
        SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 16, TRUE, vram, 10003 + i);
        SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 15, FALSE, 1, vram, 10004 + i);
        i++;
    } while (i < 2);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 17, TRUE, 10002);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_2_3_2, 18, TRUE, 10002);
}

#pragma opt_propagation reset

static void PokeathlonBlockSmash_UpdateScoreDigits(PokeathlonBlockSmash *work) {
    s32 i;
    u16 score;
    GF_ASSERT(work != NULL);
    score = PokeathlonBlockSmashBlocks_GetScore(work->blocks);
    for (i = 0; i < 3; i++) {
        Sprite_SetAnimCtrlSeq(work->scoreDigits[2 - i], (u16)(score % 10) + 1);
        if (score < 10) {
            break;
        }
        score = score / 10;
    }
}

static void PokeathlonBlockSmash_StopHudAnims(PokeathlonBlockSmash *work) {
    s32 i;
    for (i = 0; i < 2; i++, work = (PokeathlonBlockSmash *)((u8 *)work + sizeof(ManagedSprite *))) {
        ManagedSprite_SetAnimateFlag(work->timerFrame, FALSE);
    }
}

static void PokeathlonBlockSmash_InitBgs(BgConfig *bgConfig, enum HeapID heapId) {
    GraphicsModes modes = sPokeathlonBlockSmashGraphicsModes;
    s32 i;
    SetBothScreensModesAndDisable(&modes);
    {
        PokeathlonBlockSmashBgTemplates templates = sPokeathlonBlockSmashBgTemplates;
        for (i = 0; i < 6; i++) {
            InitBgFromTemplate(bgConfig, sPokeathlonBlockSmashBgLayers[i], &templates.templates[i], GF_BG_TYPE_TEXT);
            BgClearTilemapBufferAndCommit(bgConfig, sPokeathlonBlockSmashBgLayers[i]);
            BG_ClearCharDataRange(sPokeathlonBlockSmashBgLayers[i], 0x20, 0, heapId);
        }
        FontID_Alloc(4, heapId);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, 16);
    }
}

static void PokeathlonBlockSmash_FreeBgsAndText(PokeathlonBlockSmash *work) {
    s32 i;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        String_Delete(work->names[i]);
    }
    MessageFormat_Delete(work->msgFormat);
    DestroyMsgData(work->msgData);
    for (i = 0; i < 4; i++) {
        RemoveWindow(&work->windows[i]);
    }
    for (i = 0; i < 6; i++) {
        FreeBgTilemapBuffer(work->bgConfig, sPokeathlonBlockSmashBgLayers[i]);
    }
    FontID_Release(4);
    Heap_Free(work->bgConfig);
}

static void PokeathlonBlockSmash_LoadBgGraphics(PokeathlonBlockSmash *work) {
    GfGfxLoader_LoadCharData(NARC_a_2_3_2, 1, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_2, 2, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_3_2, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, work->heapId);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, work->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_2, 4, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_2, 4, work->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_2, 5, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_2, 6, work->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_3_2, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, work->heapId);
}

static void PokeathlonBlockSmash_InitText(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    int i;
    PokeathlonCourseMon *mons;
    work->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, work->heapId);
    work->msgFormat = MessageFormat_New(work->heapId);
    for (i = 0; i < 4; i++) {
        AddWindow(work->bgConfig, &work->windows[i], &sPokeathlonBlockSmashWindowTemplates[i]);
        FillWindowPixelBuffer(&work->windows[i], 0);
        ClearWindowTilemap(&work->windows[i]);
    }
    mons = PokeathlonCourse_GetParticipantMons(course, PokeathlonCourse_GetNetId(course));
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        work->names[i] = String_New(POKEMON_NAME_LENGTH + 1, work->heapId);
        CopyU16ArrayToString(work->names[i], mons[i].nickname);
    }
}

// The seconds left and the name of the Pokemon next in line.
static void PokeathlonBlockSmash_UpdateTimer(PokeathlonBlockSmash *work) {
    int seconds;
    u8 value;
    GF_ASSERT(work != NULL);
    GF_ASSERT(work->mon != NULL);
    seconds = work->timer / 30;
    if (seconds < 0) {
        seconds = 0;
    }
    value = seconds % 100;
    Sprite_SetAnimCtrlSeq(work->timerDigits[0], (u8)(value / 10) + 1);
    Sprite_SetAnimCtrlSeq(work->timerDigits[1], (u8)(value % 10) + 1);
    u8 next = (PokeathlonBlockSmashMon_GetActiveMemberIndex(work->mon) + 1) % 3;
    BufferString(work->msgFormat, 0, work->names[next], 2, 1, 2);
    PokeathlonBlockSmash_PrintMessage(&work->windows[3], work->msgFormat, work->msgData, msg_0309_00154, work->heapId);
}

static void PokeathlonBlockSmash_PrintInitialText(PokeathlonBlockSmash *work) {
    PokeathlonBlockSmash_PrintMessage(&work->windows[0], work->msgFormat, work->msgData, msg_0309_00301, work->heapId);
    PokeathlonBlockSmash_UpdateTimer(work);
}

static void PokeathlonBlockSmash_PrintMessage(Window *window, MessageFormat *msgFormat, MsgData *msgData, u32 msgId, enum HeapID heapId) {
    String *string;
    FillWindowPixelBuffer(window, 0);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msgId, heapId);
    AddTextPrinterParameterizedWithColor(window, 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(window);
}

// The four participants' rows on the top screen.
static void PokeathlonBlockSmash_CreateTeamRows(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work;
    int i;
    PokeathlonBlockSmashTeamRow *row;
    int x;
    const PokeathlonBlockSmashRowSprites *sprites;
    int j;
    int y;
    s16 barX;
    work = PokeathlonCourse_GetWork(course);
    GF_ASSERT(work != NULL);
    GF_ASSERT(work->spriteSystem != NULL);
    GF_ASSERT(work->spriteManager != NULL);
    GF_ASSERT(work->rivals != NULL);
    for (i = 0, row = work->icons.rows, x = 120, sprites = sPokeathlonBlockSmashRowSprites; i < POKEATHLON_PARTICIPANTS; row++, x += 32, sprites++, i++) {
        s16 iconX = x;
        row->icon = PokeathlonBlockSmash_NewSubSprite(work->spriteSystem, work->spriteManager, iconX, 152, i + 13, 3);
        PokeathlonBlockSmash_SetTeamRowIcon(course, (u8)i, 0);
        row->switching = PokeathlonBlockSmash_NewSubSprite(work->spriteSystem, work->spriteManager, iconX, 152, 18, 3);
        ManagedSprite_SetDrawFlag(row->switching, FALSE);
        for (j = 0, y = 0; j < 5; y += 16, j++) {
            row->stars[j] = PokeathlonBlockSmash_NewSubSprite(work->spriteSystem, work->spriteManager, (s16)x + 6, (s16)(136 - y) - 20, sprites->star, 44 - j);
            ManagedSprite_SetDrawFlag(row->stars[j], FALSE);
        }
        barX = x;
        for (j = 0; j < 20; j++) {
            row->bars[j] = PokeathlonBlockSmash_NewSubSprite(work->spriteSystem, work->spriteManager, barX, 136 - j * 4, sprites->bar, 24 - j);
            ManagedSprite_SetDrawFlag(row->bars[j], FALSE);
        }
    }
}

static void PokeathlonBlockSmash_DeleteTeamRows(PokeathlonBlockSmash *work) {
    s32 i, j;
    PokeathlonBlockSmashTeamRow *row;
    for (i = 0, row = work->icons.rows; i < POKEATHLON_PARTICIPANTS; i++, row++) {
        GF_ASSERT(row->icon != NULL);
        Sprite_DeleteAndFreeResources(row->icon);
        GF_ASSERT(row->switching != NULL);
        Sprite_DeleteAndFreeResources(row->switching);
        for (j = 0; j < 20; j++) {
            GF_ASSERT(row->bars[j] != NULL);
            Sprite_DeleteAndFreeResources(row->bars[j]);
        }
        for (j = 0; j < 5; j++) {
            GF_ASSERT(row->stars[j] != NULL);
            Sprite_DeleteAndFreeResources(row->stars[j]);
        }
    }
}

// Shows each participant's score as bars (one per 5 blocks) and its active Pokemon.
static void PokeathlonBlockSmash_UpdateTeamRows(PokeathlonCourseData *course) {
    PokeathlonBlockSmashTeamRow *row;
    int participant;
    PokeathlonBlockSmashReport *report;
    GF_ASSERT(course != NULL);
    row = PokeathlonCourse_GetWork(course);
    report = (PokeathlonBlockSmashReport *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    participant = 0;
    row = ((PokeathlonBlockSmash *)row)->icons.rows;
    do {
        int bars = report->score / 5u;
        int i;
        if (bars > 20) {
            if (!ManagedSprite_GetDrawFlag(row->stars[0])) {
                for (i = 0; i < 5; i++) {
                    ManagedSprite_SetDrawFlag(row->stars[i], TRUE);
                }
                for (i = 0; i < 20; i++) {
                    ManagedSprite_SetDrawFlag(row->bars[i], FALSE);
                }
            }
            bars -= 20;
        }
        if (bars > 20) {
            bars = 20;
        }
        {
            int j;
            for (j = 0; j < bars; j++) {
                if (!ManagedSprite_GetDrawFlag(row->bars[j])) {
                    ManagedSprite_ResetSpriteAnimCtrlState(row->bars[j]);
                    ManagedSprite_SetDrawFlag(row->bars[j], TRUE);
                }
            }
        }
        if (report->showSwitching) {
            int member = report->member;
            if (member != row->member) {
                PokeathlonBlockSmash_SetTeamRowIcon(course, (u8)participant, (u8)member);
                row->member = report->member;
            }
            ManagedSprite_SetDrawFlag(row->icon, FALSE);
            ManagedSprite_SetDrawFlag(row->switching, TRUE);
        } else {
            ManagedSprite_SetDrawFlag(row->switching, FALSE);
            ManagedSprite_SetDrawFlag(row->icon, TRUE);
        }
        row++;
        report++;
        participant++;
    } while (participant < POKEATHLON_PARTICIPANTS);
}

static void PokeathlonBlockSmash_SetTeamRowIcon(PokeathlonCourseData *course, u32 participant, u32 member) {
    PokeathlonCourseMonInfo info;
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    PokeathlonBlockSmashTeamIcons *icons = &work->icons;
    PokeathlonCourse_GetMonInfo(course, participant, member, &info);
    PokeathlonCourse_LoadMonIcon(icons->rows[participant].icon, &info, icons->plttId, work->icons.narc, participant << 9, work->heapId);
}

// Swiping the active Pokemon up (from inside the block area unless `anywhere`) switches to the next
// one; the switch button does the same.
static void PokeathlonBlockSmash_HandleSwipe(PokeathlonBlockSmash *work, BOOL anywhere) {
    u32 x, y, heldX, heldY;
    int anim;
    PokeathlonBlockSmashSwipe *swipe;
    PokeathlonBlockSmashMon_GetMode(work->mon);
    swipe = &work->swipe;
    if (System_GetTouchNew()) {
        BOOL inside, inTop, inX;
        System_GetTouchNewCoords(&x, &y);
        inside = FALSE;
        inTop = FALSE;
        inX = FALSE;
        if (x >= 96 && x <= 176) {
            inX = TRUE;
        }
        if (inX && y >= 72) {
            inTop = TRUE;
        }
        if (inTop && y <= 152) {
            inside = TRUE;
        }
        if (anywhere || inside) {
            swipe->startY = y;
            swipe->y = y;
            swipe->frames = 1;
            swipe->active = TRUE;
        }
    } else if (swipe->active && !System_GetTouchHeld()) {
        if ((int)(swipe->startY - swipe->y) >= 32 && PokeathlonBlockSmashMon_CanSwitch(work->mon)) {
            PokeathlonBlockSmashMon_StartSwitch(work->mon);
        }
        swipe->active = FALSE;
    } else if (swipe->active) {
        System_GetTouchHeldCoords(&heldX, &heldY);
        swipe->y = heldY;
        swipe->frames++;
        if (swipe->frames >= 10) {
            swipe->active = FALSE;
        }
    }
    if (System_GetTouchNew() || System_GetTouchHeld() <= 0) {
        if (TouchscreenHitbox_FindRectAtTouchNew(sPokeathlonBlockSmashSwipeHitboxes) != TOUCH_MENU_NO_INPUT) {
            if (PokeathlonBlockSmashMon_CanSwitch(work->mon)) {
                anim = 20;
                PlaySE(SEQ_SE_GS_CHANGE1);
                PokeathlonBlockSmashMon_StartSwitch(work->mon);
            } else {
                anim = 22;
                PlaySE(SEQ_SE_GS_CHANGE2);
            }
        } else if (!PokeathlonBlockSmashMon_CanSwitch(work->mon)) {
            anim = 21;
        } else if (PokeathlonBlockSmashMon_IsTired(work->mon)) {
            anim = 23;
        } else {
            anim = 19;
        }
        ManagedSprite_SetAnimNoRestart(work->switchButton, anim);
    }
}

// Fills in the own report of the link data.
static void PokeathlonBlockSmash_WriteReport(PokeathlonCourseData *course) {
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    PokeathlonBlockSmashReport *report = (PokeathlonBlockSmashReport *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course));
    PokeathlonBlockSmashMember *member = PokeathlonBlockSmashMon_GetActiveMember(work->mon);
    u32 mode = PokeathlonBlockSmashMon_GetMode(work->mon);
    report->score = PokeathlonBlockSmashBlocks_GetScore(work->blocks);
    report->stamina = member->stamina;
    report->gauge = PokeathlonBlockSmashMon_GetGauge(work->mon);
    report->gaugeFull = PokeathlonBlockSmashMon_IsGaugeFull(work->mon);
    report->switching = mode == 3;
    report->member = PokeathlonBlockSmashMon_GetActiveMemberIndex(work->mon);
}

// The host builds the frame from all reports; every participant then writes its own report.
static void PokeathlonBlockSmash_UpdateLinkData(PokeathlonCourseData *course) {
    int netId = PokeathlonCourse_GetNetId(course);
    PokeathlonBlockSmash *work = PokeathlonCourse_GetWork(course);
    u8 *data = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonBlockSmashReport *out;
    int i;
    GF_ASSERT(work != NULL);
    GF_ASSERT(work->mon != NULL);
    GF_ASSERT(work->blocks != NULL);
    if (netId == 0) {
        out = (PokeathlonBlockSmashReport *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_FRAME_OUT);
        *(PokeathlonBlockSmashLinkBlock *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_INPUTS) = *(PokeathlonBlockSmashLinkBlock *)PokeathlonCourse_ToBytes(data);
        data += POKEATHLON_COURSE_DATA_INPUTS;
        for (i = 0; i < POKEATHLON_PARTICIPANTS; i++, data += POKEATHLON_COURSE_DATA_SLOT_SIZE, out++) {
            PokeathlonBlockSmashReport *report = (PokeathlonBlockSmashReport *)PokeathlonCourse_ToBytes(data);
            out->score = report->score;
            out->stamina = report->stamina;
            out->gauge = report->gauge;
            out->member = report->member;
            out->gaugeFull = report->gaugeFull;
            out->showSwitching = report->switching;
        }
    }
    PokeathlonBlockSmash_WriteReport(course);
}

static void PokeathlonBlockSmash_PrintScore(PokeathlonCourseData *course, u32 score) {
    PokeathlonBlockSmash *work;
    MessageFormat *msgFormat;
    MsgData *msgData;
    String *string;
    work = PokeathlonCourse_GetWork(course);
    msgFormat = work->msgFormat;
    msgData = work->msgData;
    PokeathlonCourse_SetRecordScore(course, score);
    FillWindowPixelBuffer(&work->windows[2], 0);
    BufferIntegerAsString(msgFormat, 0, score, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msg_0309_00159, work->heapId);
    AddTextPrinterParameterizedWithColor(&work->windows[2], 4, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(&work->windows[2]);
}

// Shakes the touch screen up and down with a shrinking amplitude.
static void PokeathlonBlockSmash_ShakeTask(SysTask *task, void *data) {
    PokeathlonBlockSmash *work = data;
    s32 offset;
    s32 sign;
    if (work->shakeSide) {
        sign = 1;
    } else {
        sign = -1;
    }
    offset = work->shakeOffset * sign;
    ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, offset);
    ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, offset);
    G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, -offset << FX32_SHIFT);
    work->shakeOffset = work->shakeOffset - work->shakeDecay;
    work->shakeSide = work->shakeSide ^ 1;
    if (work->shakeOffset <= 0) {
        ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, 16);
        ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 0);
        G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, 0);
        work->shakeTask = NULL;
        SysTask_Destroy(task);
    }
}

static void PokeathlonBlockSmash_StartShake(PokeathlonBlockSmash *work, int offset, int decay) {
    if (work->shakeTask != NULL) {
        SysTask_Destroy(work->shakeTask);
    }
    work->shakeSide = 0;
    work->shakeOffset = offset;
    work->shakeDecay = decay;
    work->shakeTask = SysTask_CreateOnMainQueue(PokeathlonBlockSmash_ShakeTask, work, 2);
}
