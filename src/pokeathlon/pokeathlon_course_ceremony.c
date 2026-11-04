#include "pokeathlon/pokeathlon_course_ceremony.h"

#include "global.h"

#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_course_ui.h"
#include "pokeathlon/pokeathlon_util.h"

#include "MATH_pop.h"
#include "assert.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "palette.h"
#include "poke_overlay.h"
#include "pokemon.h"
#include "screen_fade.h"
#include "screen_fade_internal.h"
#include "sound.h"
#include "sound_chatot.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "sys_task_api.h"
#include "system.h"
#include "wireless_status_icon.h"

enum {
    CEREMONY_STEP_FADE_IN,
    CEREMONY_STEP_MAIN,
    CEREMONY_STEP_FADE_OUT,
};

enum {
    TRAINER_POSE_STANDING = 1,
    TRAINER_POSE_CHEERING,
};

enum {
    OPENING_STATE_WELCOME,
    OPENING_STATE_FLASH,
    OPENING_STATE_WAIT_FLASH,
    OPENING_STATE_FADE_IN,
    OPENING_STATE_WAIT_FADE_IN,
    OPENING_STATE_TEAM_LINE,
    OPENING_STATE_TEAM_CHEER,
    OPENING_STATE_WAIT_CHEER,
    OPENING_STATE_END,
};

enum {
    CLOSING_STATE_GREETING,
    CLOSING_STATE_CHALLENGE_BONUS,
    CLOSING_STATE_ADD_CHALLENGE_BONUS,
    CLOSING_STATE_TEAM_BONUSES,
    CLOSING_STATE_NO_MISS_BONUS,
    CLOSING_STATE_NO_MISS_MONS,
    CLOSING_STATE_POINTS_LEADER,
    CLOSING_STATE_POINTS_LEADER_MONS,
    CLOSING_STATE_EFFORT_PRIZE,
    CLOSING_STATE_EFFORT_PRIZE_KIND,
    CLOSING_STATE_EFFORT_PRIZE_MONS,
    CLOSING_STATE_EVENT_POINTS,
    CLOSING_STATE_COUNT_EVENT_POINTS,
    CLOSING_STATE_RANK_TEAMS,
    CLOSING_STATE_TIE,
    CLOSING_STATE_WINNER_POINTS,
    CLOSING_STATE_LOAD_WINNER_BG,
    CLOSING_STATE_WINNER,
    CLOSING_STATE_MEDALS,
    CLOSING_STATE_RECORD,
    CLOSING_STATE_FAREWELL,
    CLOSING_STATE_END,
    CLOSING_STATE_WELL_DONE,
};

enum PokeathlonCeremonyFadeState {
    CEREMONY_FADE_START,
    CEREMONY_FADE_WAIT,
};

enum PokeathlonCeremonyCryState {
    CRY_STATE_START_JUMP,
    CRY_STATE_JUMP,
    CRY_STATE_WAIT_CRY,
};

// The statistics the prize for effort can go for.
enum {
    EFFORT_PRIZE_JUMPED,
    EFFORT_PRIZE_HIT,
    EFFORT_PRIZE_FAILED,
    EFFORT_PRIZE_DASHED,
    EFFORT_PRIZE_KIND_COUNT,
    EFFORT_PRIZE_NONE = EFFORT_PRIZE_KIND_COUNT, // no Pokemon has any of them
};

enum PokeathlonCeremonyInitState {
    CEREMONY_INIT_CREATE,
    CEREMONY_INIT_LOAD_MONS,
    CEREMONY_INIT_CREATE_SPRITES,
    CEREMONY_INIT_START,
};

#define INTRO_STATISTICS 29 // the u32 fields of PokeathlonStatistics an introduction can be about
#define CHEER_LEVEL_MAX  12

FS_EXTERN_OVERLAY(OVY_98);

void MATH_QSort(void *head, u32 num, u32 width, int (*compare)(const void *, const void *), void *stackBuffer);

static BOOL PokeathlonCourseCeremony_IsCryActive(PokeathlonCourseCeremony *ceremony);
static void PokeathlonCourseCeremony_LoadWinnerBg(BgConfig *bgConfig, enum HeapID heapId);
static void PokeathlonCourseCeremony_LoadMonPicResources(PokeathlonCourseCeremony *ceremony);
static void PokeathlonCourseCeremony_ShowWinnerTeam(PokeathlonCourseData *course, int team);
static void PokeathlonCourseCeremony_SetTrainerPose(ManagedSprite **sprites, PokeathlonCourseData *course, int team, int pose, enum HeapID heapId);
static void PokeathlonCourseCeremony_UpdateScores(PokeathlonCourseCeremonyScore *scores);
static BOOL PokeathlonCourseCeremony_AreScoresCounted(PokeathlonCourseCeremonyScore *scores);
static void PokeathlonCourseCeremony_AddPoints(PokeathlonCourseCeremonyScore *scores, int team, u32 points);
static u32 PokeathlonCourseCeremony_GetPoints(PokeathlonCourseCeremonyScore *scores, u8 team);
static void PokeathlonCourseCeremony_RankTeams(PokeathlonCourseCeremonyScore *scores, PokeathlonCourseCeremonyRank *ranks, const u8 *drawingLots);
static void PokeathlonCourseCeremonyScore_Update(PokeathlonCourseCeremonyScore *score);
static BOOL PokeathlonCourseCeremonyScore_IsCounted(PokeathlonCourseCeremonyScore *score);
static void PokeathlonCourseCeremonyScore_Add(PokeathlonCourseCeremonyScore *score, u32 points);
static void PokeathlonCourseConfetti_Update(PokeathlonCourseConfetti *confetti);
static void PokeathlonCourseConfetti_Start(PokeathlonCourseConfetti *confetti, BOOL active);
static void PokeathlonCourseConfetti_SpawnPieces(PokeathlonCourseConfetti *confetti, u8 count);
static BOOL PokeathlonCourseCeremony_Init(PokeathlonCourseData *course);
static BOOL PokeathlonCourseCeremony_Main(PokeathlonCourseData *course);
static BOOL PokeathlonCourseCeremony_Exit(PokeathlonCourseData *course);
static void PokeathlonCourseCeremony_BufferMonName(PokeathlonCourseData *course, int team, int member, int field);
static void PokeathlonCourseCeremony_BufferTeamPoints(PokeathlonCourseData *course, int team, int points);
static u32 PokeathlonCourseCeremony_HasNoMissBonus(PokeathlonCourseData *course);
static BOOL PokeathlonCourseCeremony_IsNoMissMon(PokeathlonCourseData *course, int team, int member);
static BOOL PokeathlonCourseCeremony_IsPointsLeader(PokeathlonCourseData *course, int team, int member);
static BOOL PokeathlonCourseCeremony_IsEffortPrizeMon(PokeathlonCourseData *course, int team, int member);
static int PokeathlonCourseConfetti_GetRandomDelay(void);
static u8 PokeathlonCourseCeremony_GetChallengeBonus(PokeathlonCourseData *course, u8 team);
static u32 PokeathlonCourseCeremony_GetEventPoints(PokeathlonCourseData *course, u8 team, u8 round);
static int PokeathlonCourseCeremony_GetNoMissPoints(PokeathlonCourseCeremony *ceremony);
static int PokeathlonCourseCeremony_GetPointsLeaderPoints(PokeathlonCourseCeremony *ceremony);
static int PokeathlonCourseCeremony_GetEffortPrizePoints(PokeathlonCourseCeremony *ceremony);
static u32 PokeathlonCourseCeremony_CountNoMissMons(PokeathlonCourseData *course);
static u32 PokeathlonCourseCeremony_CountPointsLeaders(PokeathlonCourseData *course);
static u32 PokeathlonCourseCeremony_CountEffortPrizes(PokeathlonCourseData *course);
static void PokeathlonCourseCeremony_GetDrawingLots(PokeathlonCourseData *course, u8 *drawingLots);
static u32 PokeathlonCourseCeremony_GetIntroMsgId(PokeathlonCourseData *course, u32 team);
static u32 PokeathlonCourseCeremony_GetIntroValue(PokeathlonCourseData *course, u32 team);
static u32 PokeathlonCourseCeremony_GetIntroCheer(PokeathlonCourseData *course, u32 team);
static void PokeathlonCourseCeremony_ChooseIntros(PokeathlonCourseData *course);
static void PokeathlonCourseCeremony_ChooseAwards(PokeathlonCourseData *course);
static u32 PokeathlonCourseCeremony_GetCourseMedal(u32 course, u32 which);
static u8 PokeathlonCourseCeremony_GetEffortPrizeKind(PokeathlonCourseData *course);
static u32 PokeathlonCourseCeremony_GetMonStat(PokeathlonCourseData *course, u8 kind, u8 team, u8 member);
static BOOL PokeathlonCourseCeremony_AwardNextMon(PokeathlonCourseData *course, PokeathlonCourseCeremonyAwardTest test, int points);
static void PokeathlonCourseCeremony_SaveResult(PokeathlonCourseData *course, PokeathlonCourseCeremonyScore *scores);
static void PokeathlonCourseCeremony_BufferNumber(MessageFormat *msgFormat, s32 value, u32 digits, u32 field);
static void PokeathlonCourseCeremony_ChooseOwnIntro(PokeathlonCourseCeremonyIntro *intro, PokeathlonCourseData *course);
static void PokeathlonCourseCeremony_ChooseLinkIntro(PokeathlonCourseCeremonyIntro *intro, PokeathlonCourseData *course, int team);
static void PokeathlonCourseCeremony_ChooseNpcIntro(PokeathlonCourseCeremonyIntro *intro, PokeathlonCourseData *course, int team);
static int PokeathlonCourseCeremony_FindPlace(const PokeathlonCourseCeremonyRank *ranks, u8 team);
static void PokeathlonCourseCeremony_BreakTie(PokeathlonCourseCeremonyRank *ranks);
static BOOL PokeathlonCourseCeremony_SyncOpening(PokeathlonCourseData *course);
static BOOL PokeathlonCourseCeremony_SyncClosing(PokeathlonCourseData *course);

static const GraphicsModes sPokeathlonCourseCeremonyGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const u32 sPokeathlonCourseCeremonyIntroStatThresholds[4] = { 11, 6, 3, 0 };

static const OamCharTransferParam sPokeathlonCourseCeremonyOamCharTransferParam = {
    .maxTasks = 0,
    .sizeMain = 0x40000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_256K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_64K,
};

static const SpriteResourceCountsListUnion sPokeathlonCourseCeremonySpriteResourceCounts = { 112, 110, 105, 105, 0, 0 };

static const BgTemplate sPokeathlonCourseCeremonyBgTemplate0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCourseCeremonyBgTemplate4 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCourseCeremonyBgTemplate5 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCourseCeremonyBgTemplate1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const OamManagerParam sPokeathlonCourseCeremonyOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 126,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 1,
    .numOBJsub = 126,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const GraphicsBanks sPokeathlonCourseCeremonyGraphicsBanks = {
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

static const s32 sPokeathlonCourseCeremonyCheerThresholds[CHEER_LEVEL_MAX] = { 11, 26, 51, 101, 201, 0x1F5, 0x3E9, 0x7D1, 0x1389, 0x2711, 0x4E21, 0xC351 };

static const s32 sPokeathlonCourseCeremonyCheerPitches[13] = { -64, -32, 0, 32, 64, 96, -32, -16, 0, 16, 32, 48, 64 };

static const ManagedSpriteTemplate sPokeathlonCourseConfettiSpriteTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 11,
    .drawPriority = 0,
    .pal = 0,
    .vram = NNS_G2D_VRAM_TYPE_2DSUB,
    .resIdList = { 105, 105, 101, 101, 0, 0 },
    .bgPriority = 1,
    .vramTransfer = 0,
};

static const ManagedSpriteTemplate sPokeathlonCourseConfettiTopSpriteTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 0,
    .drawPriority = 0,
    .pal = 0,
    .vram = NNS_G2D_VRAM_TYPE_2DMAIN,
    .resIdList = { 106, 106, 102, 102, 0, 0 },
    .bgPriority = 0,
    .vramTransfer = 0,
};

static const u32 sPokeathlonCourseCeremonyIntroStatWeights[INTRO_STATISTICS] = {
    8, 6, 3, 15, 6, 18, 0xBB8, 240, 0x168, 0x3C0, 0x1E0, 12, 0x384, 36, 6, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 120
};

PokeathlonCourseStepFunc gPokeathlonCourseOpeningSteps[3] = {
    PokeathlonCourseOpening_FadeIn,
    PokeathlonCourseOpening_Introduce,
    PokeathlonCourseOpening_FadeOut,
};

PokeathlonCourseStepFunc gPokeathlonCourseClosingSteps[3] = {
    PokeathlonCourseClosing_FadeIn,
    PokeathlonCourseClosing_Awards,
    PokeathlonCourseClosing_FadeOut,
};

BOOL PokeathlonCourseOpening_Init(PokeathlonCourseData *course) {
    return PokeathlonCourseCeremony_Init(course);
}

BOOL PokeathlonCourseOpening_Main(PokeathlonCourseData *course) {
    return PokeathlonCourseCeremony_Main(course);
}

BOOL PokeathlonCourseOpening_Exit(PokeathlonCourseData *course) {
    return PokeathlonCourseCeremony_Exit(course);
}

BOOL PokeathlonCourseClosing_Init(PokeathlonCourseData *course) {
    return PokeathlonCourseCeremony_Init(course);
}

BOOL PokeathlonCourseClosing_Main(PokeathlonCourseData *course) {
    return PokeathlonCourseCeremony_Main(course);
}

BOOL PokeathlonCourseClosing_Exit(PokeathlonCourseData *course) {
    return PokeathlonCourseCeremony_Exit(course);
}

static void PokeathlonCourseCeremony_SetBanks(void) {
    GraphicsBanks banks = sPokeathlonCourseCeremonyGraphicsBanks;

    GfGfx_SetBanks(&banks);
}

BOOL PokeathlonCourseOpening_FadeIn(PokeathlonCourseData *course, u8 *state) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case CEREMONY_FADE_START:
        if (!PokeathlonCourse_GetNetId(course)) {
            PokeathlonCourseCeremony_ChooseIntros(course);
        }
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, ceremony->heapId);
        (*state)++;
        break;
    case CEREMONY_FADE_WAIT:
        if (IsPaletteFadeFinished()) {
            PokeathlonCourse_SetNextState(course, CEREMONY_STEP_MAIN);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

// The commentator welcomes everyone to the course, then introduces every team in turn: its
// line, its name and Pokemon, while the team's Pokemon jump and the crowd cheers.
BOOL PokeathlonCourseOpening_Introduce(PokeathlonCourseData *course, u8 *state) {
    int i;
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    BOOL waiting = FALSE;
    if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_LINK) {
        waiting = PokeathlonCourseCeremony_SyncOpening(course);
    }
    PokeathlonCourseMessageBox_Update(ceremony->messageBox);
    if (!PokeathlonCourseMessageBox_IsBusy(ceremony->messageBox) && !waiting) {
        MessageFormat *msgFormat = PokeathlonCourseMessageBox_GetMsgFormat(ceremony->messageBox);
        int msgId = -1;
        switch (ceremony->state) {
        case OPENING_STATE_WELCOME:
            msgId = msg_0309_00000;
            BufferPokeathlonCourseName(msgFormat, 0, ceremony->course);
            ceremony->state = OPENING_STATE_FLASH;
            break;
        case OPENING_STATE_FLASH:
            SetBothScreensBrightnessByColor(RGB_WHITE);
            PlaySE(SEQ_SE_GS_VOICE01);
            ceremony->state = OPENING_STATE_WAIT_FLASH;
            break;
        case OPENING_STATE_WAIT_FLASH:
            if (ceremony->counter < 4) {
                ceremony->counter++;
            } else {
                ceremony->counter = 0;
                ceremony->state = OPENING_STATE_FADE_IN;
            }
            break;
        case OPENING_STATE_FADE_IN:
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 24, 1, ceremony->heapId);
            ceremony->state = OPENING_STATE_WAIT_FADE_IN;
            break;
        case OPENING_STATE_WAIT_FADE_IN:
            if (IsPaletteFadeFinished()) {
                ceremony->state = OPENING_STATE_TEAM_LINE;
            }
            break;
        case OPENING_STATE_TEAM_LINE:
            if (*(int *)PokeathlonCourse_GetParticipantData(course, ceremony->team) > 0) {
                PokeathlonCourseMessageBox_PrintNpcLine(ceremony->messageBox, PokeathlonCourseCeremony_GetIntroMsgId(course, ceremony->team));
            } else {
                msgId = PokeathlonCourseCeremony_GetIntroMsgId(course, ceremony->team);
                PokeathlonCourseCeremony_BufferNumber(msgFormat, PokeathlonCourseCeremony_GetIntroValue(course, ceremony->team), 7, 1);
            }
            ceremony->state = OPENING_STATE_TEAM_CHEER;
            break;
        case OPENING_STATE_TEAM_CHEER: {
            BufferPlayersName(msgFormat, 0, PokeathlonCourse_GetPlayerProfileFromData(course, ceremony->team));
            int i;
            for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
                PokeathlonCourseCeremony_BufferMonName(course, ceremony->team, (u8)i, i + 1);
            }
            PokeathlonCourseCeremony_SetTrainerPose(ceremony->trainerSprites, course, ceremony->team, TRAINER_POSE_CHEERING, ceremony->heapId);
            ManagedSprite_SetAnim(ceremony->trainerSprites[ceremony->team], 1);
            u8 cheer = PokeathlonCourseCeremony_GetIntroCheer(course, ceremony->team);
            int seqNo;
            if (cheer < 5) {
                seqNo = SEQ_SE_GS_VOICE01;
            } else {
                seqNo = SEQ_SE_GS_VOICE02;
            }
            PlaySE_SetPitch(seqNo, (s16)sPokeathlonCourseCeremonyCheerPitches[cheer]);
            ceremony->cheering = TRUE;
            msgId = msg_0309_00001;
            ceremony->state = OPENING_STATE_WAIT_CHEER;
            break;
        }
        case OPENING_STATE_WAIT_CHEER:
            if (!ceremony->cheering) {
                if (ceremony->team >= POKEATHLON_PARTICIPANTS) {
                    ceremony->finished = TRUE;
                    msgId = msg_0309_00002;
                    ceremony->state = OPENING_STATE_END;
                } else {
                    ceremony->state = OPENING_STATE_TEAM_LINE;
                }
            }
            break;
        case OPENING_STATE_END:
            if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO || PokeathlonCourseCeremony_IsOpeningFinished(course)) {
                if (PokeathlonCourseCeremony_IsCryActive(ceremony)) {
                    Heap_Free(ceremony->cryData);
                    SysTask_Destroy(ceremony->cryTask);
                }
                PokeathlonCourseMessageBox_Close(ceremony->messageBox);
                PokeathlonCourse_SetNextState(course, CEREMONY_STEP_FADE_OUT);
                return FALSE;
            }
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
        if (msgId != -1) {
            PokeathlonCourseMessageBox_Print(ceremony->messageBox, msgId);
            ceremony->messageCount++;
        }
    }
    if (ceremony->cheering) {
        int index = (u8)(ceremony->team * 3);
        if (ceremony->timer++ == 0) {
            for (i = 0; i < POKEATHLON_TEAM_SIZE; i++, index++) {
                PokeathlonCourseMonObject *object = PokeathlonCourseMonObjects_Get(ceremony->objects, index);
                PokeathlonCourseMonObject_SetAnimState(object, 2);
                PokeathlonCourseMonObject_SetAnim(object, 16);
            }
        } else if (ceremony->timer++ >= 60) {
            int i;
            for (i = 0; i < POKEATHLON_TEAM_SIZE; index++, i++) {
                PokeathlonCourseMonObject *object = PokeathlonCourseMonObjects_Get(ceremony->objects, index);
                PokeathlonCourseMonObject_SetAnimState(object, 1);
                PokeathlonCourseMonObject_SetAnim(object, 0);
                Sprite_GetCellAnim(PokeathlonCourseMonGfx_GetSprite(PokeathlonCourseMonObject_GetGfx(object)))->animCtrl.currentTime = i * 3 << FX32_SHIFT;
            }
            PokeathlonCourseCeremony_SetTrainerPose(ceremony->trainerSprites, course, ceremony->team, TRAINER_POSE_STANDING, ceremony->heapId);
            ceremony->cheering = FALSE;
            ceremony->team++;
            ceremony->timer = 0;
        }
    }
    return FALSE;
}

BOOL PokeathlonCourseOpening_FadeOut(PokeathlonCourseData *course, u8 *state) {
    switch (*state) {
    case CEREMONY_FADE_START:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 90, 1, PokeathlonCourse_GetHeapID(course));
        GF_SndStartFadeOutBGM(0, 90);
        PlaySE(SEQ_SE_GS_VOICE02);
        (*state)++;
        break;
    case CEREMONY_FADE_WAIT:
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

BOOL PokeathlonCourseClosing_FadeIn(PokeathlonCourseData *course, u8 *state) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case CEREMONY_FADE_START:
        if (!PokeathlonCourse_GetNetId(course)) {
            PokeathlonCourseCeremony_ChooseAwards(course);
        }
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, ceremony->heapId);
        (*state)++;
        break;
    case CEREMONY_FADE_WAIT:
        if (IsPaletteFadeFinished()) {
            PokeathlonCourse_SetNextState(course, CEREMONY_STEP_MAIN);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

// The awards: Challenge Bonus of every team, No-Miss Bonus, points leader and prize for effort
// (each Pokemon's cry), then the event points of every round counted up, the winner (by drawing
// lots when tied) with its medals and course record.
BOOL PokeathlonCourseClosing_Awards(PokeathlonCourseData *course, u8 *state) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    BOOL waiting = FALSE;
    int msgId;
    int i;
    MessageFormat *msgFormat;
    u8 drawingLots[POKEATHLON_PARTICIPANTS];
    int rounds;
    PokeathlonCourseCeremony_UpdateScores(ceremony->scores);
    PokeathlonCourseConfetti_Update(ceremony->confetti);
    if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_LINK) {
        waiting = PokeathlonCourseCeremony_SyncClosing(course);
    }
    PokeathlonCourseMessageBox_Update(ceremony->messageBox);
    if (!PokeathlonCourseMessageBox_IsBusy(ceremony->messageBox) && !waiting) {
        msgFormat = PokeathlonCourseMessageBox_GetMsgFormat(ceremony->messageBox);
        msgId = -1;
        switch (ceremony->state) {
        case CLOSING_STATE_GREETING:
            msgId = msg_0309_00003;
            ceremony->state = CLOSING_STATE_CHALLENGE_BONUS;
            break;
        case CLOSING_STATE_CHALLENGE_BONUS:
            msgId = msg_0309_00004;
            ceremony->state = CLOSING_STATE_ADD_CHALLENGE_BONUS;
            break;
        case CLOSING_STATE_ADD_CHALLENGE_BONUS:
            for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                int points = PokeathlonCourseCeremony_GetChallengeBonus(course, i);
                PokeathlonCourseCeremony_AddPoints(ceremony->scores, (u8)i, points);
            }
            ceremony->state = CLOSING_STATE_TEAM_BONUSES;
            // fallthrough
        case CLOSING_STATE_TEAM_BONUSES:
            if (ceremony->team >= POKEATHLON_PARTICIPANTS) {
                ceremony->team = 0;
                msgId = msg_0309_00006;
                ceremony->state = CLOSING_STATE_NO_MISS_BONUS;
            } else {
                int points;
                msgId = msg_0309_00005;
                points = PokeathlonCourseCeremony_GetChallengeBonus(course, ceremony->team);
                PokeathlonCourseCeremony_BufferTeamPoints(course, ceremony->team, points);
                ceremony->team++;
            }
            break;
        case CLOSING_STATE_NO_MISS_BONUS:
            if (PokeathlonCourseCeremony_HasNoMissBonus(course)) {
                msgId = msg_0309_00007;
                ceremony->state = CLOSING_STATE_NO_MISS_MONS;
            } else {
                msgId = msg_0309_00009;
                ceremony->state = CLOSING_STATE_POINTS_LEADER;
            }
            break;
        case CLOSING_STATE_NO_MISS_MONS:
            if (!PokeathlonCourseCeremony_IsCryActive(ceremony)) {
                if (ceremony->counter >= PokeathlonCourseCeremony_CountNoMissMons(course)) {
                    ceremony->team = 0;
                    ceremony->member = 0;
                    ceremony->counter = 0;
                    msgId = msg_0309_00010;
                    ceremony->state = CLOSING_STATE_POINTS_LEADER;
                } else if (PokeathlonCourseCeremony_AwardNextMon(course, PokeathlonCourseCeremony_IsNoMissMon, PokeathlonCourseCeremony_GetNoMissPoints(ceremony))) {
                    msgId = msg_0309_00008;
                }
            }
            break;
        case CLOSING_STATE_POINTS_LEADER:
            msgId = msg_0309_00011;
            ceremony->state = CLOSING_STATE_POINTS_LEADER_MONS;
            break;
        case CLOSING_STATE_POINTS_LEADER_MONS:
            if (!PokeathlonCourseCeremony_IsCryActive(ceremony)) {
                if (ceremony->counter >= PokeathlonCourseCeremony_CountPointsLeaders(course)) {
                    ceremony->team = 0;
                    ceremony->member = 0;
                    ceremony->counter = 0;
                    msgId = msg_0309_00010;
                    ceremony->state = CLOSING_STATE_EFFORT_PRIZE;
                } else if (PokeathlonCourseCeremony_AwardNextMon(course, PokeathlonCourseCeremony_IsPointsLeader, PokeathlonCourseCeremony_GetPointsLeaderPoints(ceremony))) {
                    msgId = msg_0309_00012;
                }
            }
            break;
        case CLOSING_STATE_EFFORT_PRIZE:
            if (PokeathlonCourseCeremony_GetEffortPrizeKind(course) != EFFORT_PRIZE_NONE) {
                msgId = msg_0309_00014;
                ceremony->state = CLOSING_STATE_EFFORT_PRIZE_KIND;
            } else {
                ceremony->state = CLOSING_STATE_EVENT_POINTS;
            }
            break;
        case CLOSING_STATE_EFFORT_PRIZE_KIND:
            msgId = PokeathlonCourseCeremony_GetEffortPrizeKind(course) + 15;
            ceremony->state = CLOSING_STATE_EFFORT_PRIZE_MONS;
            break;
        case CLOSING_STATE_EFFORT_PRIZE_MONS:
            if (!PokeathlonCourseCeremony_IsCryActive(ceremony)) {
                if (ceremony->counter >= PokeathlonCourseCeremony_CountEffortPrizes(course)) {
                    ceremony->team = 0;
                    ceremony->member = 0;
                    ceremony->counter = 0;
                    msgId = msg_0309_00021;
                    ceremony->state = CLOSING_STATE_EVENT_POINTS;
                } else if (PokeathlonCourseCeremony_AwardNextMon(course, PokeathlonCourseCeremony_IsEffortPrizeMon, PokeathlonCourseCeremony_GetEffortPrizePoints(ceremony))) {
                    msgId = msg_0309_00020;
                }
            }
            break;
        case CLOSING_STATE_EVENT_POINTS:
            msgId = msg_0309_00022;
            ceremony->state = CLOSING_STATE_COUNT_EVENT_POINTS;
            StopBGM(GF_GetCurrentPlayingBGM(), 16);
            PlaySE(SEQ_SE_DP_CON_033);
            break;
        case CLOSING_STATE_COUNT_EVENT_POINTS:
            if (PokeathlonCourseCeremony_AreScoresCounted(ceremony->scores)) {
                if (ceremony->timer++ > 30) {
                    rounds = PokeathlonCourse_GetMode(course);
                    if (rounds == POKEATHLON_COURSE_MODE_SOLO) {
                        rounds = POKEATHLON_SOLO_ROUNDS;
                    } else {
                        rounds = POKEATHLON_LINK_ROUNDS;
                    }
                    ceremony->timer = 0;
                    if (ceremony->counter >= (u8)rounds) {
                        ceremony->counter = 0;
                        ceremony->state = CLOSING_STATE_RANK_TEAMS;
                    } else {
                        msgId = msg_0309_00023;
                        PokeathlonCourseCeremony_BufferNumber(msgFormat, ceremony->counter + 1, 1, 0);
                        for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                            int points = PokeathlonCourseCeremony_GetEventPoints(course, i, ceremony->counter);
                            PokeathlonCourseCeremony_AddPoints(ceremony->scores, (u8)i, (u16)points);
                        }
                        ceremony->counter++;
                    }
                }
            }
            break;
        case CLOSING_STATE_RANK_TEAMS:
            PokeathlonCourseCeremony_GetDrawingLots(course, drawingLots);
            PokeathlonCourseCeremony_RankTeams(ceremony->scores, ceremony->ranks, drawingLots);
            if (ceremony->ranks[0].place == ceremony->ranks[1].place) {
                ceremony->state = CLOSING_STATE_TIE;
            } else {
                ceremony->state = CLOSING_STATE_WINNER_POINTS;
            }
            break;
        case CLOSING_STATE_TIE:
            msgId = msg_0309_00024;
            PokeathlonCourseCeremony_BreakTie(ceremony->ranks);
            ceremony->state = CLOSING_STATE_WINNER_POINTS;
            break;
        case CLOSING_STATE_WINNER_POINTS:
            msgId = msg_0309_00025;
            PokeathlonCourseCeremony_BufferNumber(msgFormat, PokeathlonCourseCeremony_GetPoints(ceremony->scores, ceremony->ranks[0].team), 3, 0);
            PokeathlonCourseCeremony_SaveResult(course, ceremony->scores);
            ceremony->state = CLOSING_STATE_LOAD_WINNER_BG;
            break;
        case CLOSING_STATE_LOAD_WINNER_BG:
            PokeathlonCourseCeremony_LoadWinnerBg(ceremony->bgConfig, ceremony->heapId);
            ceremony->state = CLOSING_STATE_WINNER;
            // fallthrough
        case CLOSING_STATE_WINNER: {
            int winner = ceremony->ranks[0].team;
            msgId = msg_0309_00026;
            BufferPlayersName(msgFormat, 0, PokeathlonCourse_GetPlayerProfileFromData(course, winner));
            PokeathlonCourseCeremony_ShowWinnerTeam(course, (u8)winner);
            PokeathlonCourseConfetti_Start(ceremony->confetti, TRUE);
            PokeathlonCourseCeremony_SetTrainerPose(ceremony->trainerSprites, course, winner, TRAINER_POSE_CHEERING, ceremony->heapId);
            ManagedSprite_SetAnim(ceremony->trainerSprites[winner], 1);
            StopSE(SEQ_SE_DP_CON_033, 0);
            PlaySE(SEQ_SE_GS_VOICE10);
            PlaySE(SEQ_SE_GS_VOICE07);
            PlayBGM(SEQ_GS_PT_VICTORY);
            if (ceremony->course == POKEATHLON_COURSE_LINK_RANDOM) {
                ceremony->state = CLOSING_STATE_WELL_DONE;
            } else {
                ceremony->state = CLOSING_STATE_MEDALS;
            }
            break;
        }
        case CLOSING_STATE_WELL_DONE:
            msgId = msg_0309_00030;
            BufferPokeathlonCourseName(msgFormat, 0, ceremony->course);
            ceremony->state = CLOSING_STATE_FAREWELL;
            break;
        case CLOSING_STATE_MEDALS:
            msgId = msg_0309_00027;
            BufferPlayersName(msgFormat, 0, PokeathlonCourse_GetPlayerProfileFromData(course, ceremony->ranks[0].team));
            ManagedSprite_SetDrawFlag(ceremony->medalSprites[0], TRUE);
            BufferPokeathlonMedalName(msgFormat, 1, PokeathlonCourseCeremony_GetCourseMedal(ceremony->course, 0));
            if (ceremony->course >= POKEATHLON_SOLO_COURSES) {
                msgId = msg_0309_00028;
                ManagedSprite_SetDrawFlag(ceremony->medalSprites[1], TRUE);
                BufferPokeathlonMedalName(msgFormat, 2, PokeathlonCourseCeremony_GetCourseMedal(ceremony->course, 1));
            }
            ceremony->state = CLOSING_STATE_RECORD;
            break;
        case CLOSING_STATE_RECORD: {
            u32 courseId = ceremony->course;
            int points;
            PokeathlonSave *pokeathlonSave;
            if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO && ceremony->ranks[0].team == PokeathlonCourse_GetNetId(course)) {
                GF_ASSERT(ceremony->ranks[0].team == 0);
                pokeathlonSave = PokeathlonSave_dummy2(Save_Pokeathlon_Get(PokeathlonCourse_GetSaveData(course)));
                points = PokeathlonCourseCeremony_GetPoints(ceremony->scores, ceremony->ranks[0].team);
                // The best total of the course.
                if (((PokeathlonCourseBestRecord *)pokeathlonSave)[courseId].totalPoints < (u32)points) {
                    msgId = msg_0309_00029;
                    BufferPlayersName(msgFormat, 0, PokeathlonCourse_GetPlayerProfileFromData(course, ceremony->ranks[0].team));
                    BufferPokeathlonCourseName(msgFormat, 1, courseId);
                }
            } else {
                msgId = msg_0309_00030;
                BufferPokeathlonCourseName(msgFormat, 0, courseId);
            }
            ceremony->state = CLOSING_STATE_FAREWELL;
            break;
        }
        case CLOSING_STATE_FAREWELL:
            msgId = msg_0309_00031;
            StopSE(SEQ_SE_GS_VOICE10, 120);
            ceremony->finished = TRUE;
            ceremony->state = CLOSING_STATE_END;
            break;
        case CLOSING_STATE_END:
            if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO || PokeathlonCourseCeremony_IsClosingFinished(course)) {
                if (PokeathlonCourseCeremony_IsCryActive(ceremony)) {
                    Heap_Free(ceremony->cryData);
                    SysTask_Destroy(ceremony->cryTask);
                }
                PokeathlonCourseMessageBox_Close(ceremony->messageBox);
                PokeathlonCourse_SetNextState(course, CEREMONY_STEP_FADE_OUT);
                return FALSE;
            }
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
        if (msgId != -1) {
            PokeathlonCourseMessageBox_Print(ceremony->messageBox, msgId);
            ceremony->messageCount++;
        }
    }
    return FALSE;
}

BOOL PokeathlonCourseClosing_FadeOut(PokeathlonCourseData *course, u8 *state) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);

    PokeathlonCourseConfetti_Update(ceremony->confetti);
    switch (*state) {
    case CEREMONY_FADE_START:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 30, 1, PokeathlonCourse_GetHeapID(course));
        GF_SndStartFadeOutBGM(0, 30);
        (*state)++;
        break;
    case CEREMONY_FADE_WAIT:
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

// An awarded Pokemon jumps while its cry plays.
static void PokeathlonCourseCeremony_CryTask(SysTask *task, void *data) {
    PokeathlonCourseCeremonyCryTask *cry = data;
    PokeathlonCourseMonObject *object = cry->object;

    switch (cry->state) {
    case CRY_STATE_START_JUMP:
        PokeathlonCourseMonObject_SetAnimState(object, 2);
        PokeathlonCourseMonObject_SetAnim(object, 16);
        cry->state++;
        break;
    case CRY_STATE_JUMP:
        if (cry->timer++ > 60) {
            cry->state++;
        }
        break;
    case CRY_STATE_WAIT_CRY:
        if (!PokeathlonCourseMonObject_IsAnimated(object) && !IsCryPlaying()) {
            PokeathlonCourseMonObject_SetAnimState(object, 1);
            PokeathlonCourseMonObject_SetAnim(object, 0);
            *cry->active = FALSE;
            Heap_Free(cry);
            SysTask_Destroy(task);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

static void PokeathlonCourseCeremony_StartCry(PokeathlonCourseCeremony *ceremony, u8 index) {
    PokeathlonCourseCeremonyCryTask *cry = Heap_AllocAtEnd(ceremony->heapId, sizeof(PokeathlonCourseCeremonyCryTask));

    MI_CpuFill8(cry, 0, sizeof(PokeathlonCourseCeremonyCryTask));
    ceremony->cryData = cry;
    cry->object = PokeathlonCourseMonObjects_Get(ceremony->objects, index);
    ceremony->cryActive = TRUE;
    cry->active = &ceremony->cryActive;
    ceremony->cryTask = SysTask_CreateOnMainQueue(PokeathlonCourseCeremony_CryTask, cry, 1);
}

static BOOL PokeathlonCourseCeremony_IsCryActive(PokeathlonCourseCeremony *ceremony) {
    return ceremony->cryActive;
}

static void PokeathlonCourseCeremony_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes = sPokeathlonCourseCeremonyGraphicsModes;
    BgTemplate bg0;
    BgTemplate bg1;
    BgTemplate bg4;
    BgTemplate bg5;
    SetBothScreensModesAndDisable(&modes);
    bg0 = sPokeathlonCourseCeremonyBgTemplate0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &bg0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    BG_FillCharDataRange(bgConfig, GF_BG_LYR_MAIN_1, 0, 1, 0);
    bg1 = sPokeathlonCourseCeremonyBgTemplate1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    BG_FillCharDataRange(bgConfig, GF_BG_LYR_MAIN_1, 0, 1, 0);
    bg4 = sPokeathlonCourseCeremonyBgTemplate4;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &bg4, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    bg5 = sPokeathlonCourseCeremonyBgTemplate5;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &bg5, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
}

static void PokeathlonCourseCeremony_LoadBgGfx(BgConfig *bgConfig, enum HeapID heapId) {
    GfGfxLoader_LoadCharData(NARC_a_1_5_4, 3, bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_5_4, 1, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_4, 6, bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_4, 4, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_5_4, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_5_4, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, heapId);
}

static void PokeathlonCourseCeremony_LoadWinnerBg(BgConfig *bgConfig, enum HeapID heapId) {
    GfGfxLoader_LoadCharData(NARC_a_1_5_4, 3, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_4, 7, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapId);
}

static void PokeathlonCourseCeremony_InitSpriteSystem(PokeathlonCourseCeremony *ceremony) {
    SpriteResourceCountsListUnion counts = sPokeathlonCourseCeremonySpriteResourceCounts;
    OamManagerParam oamManagerParam = sPokeathlonCourseCeremonyOamManagerParam;
    OamCharTransferParam charTransferParam = sPokeathlonCourseCeremonyOamCharTransferParam;

    charTransferParam.maxTasks = 0x80;
    ceremony->spriteSystem = SpriteSystem_Alloc(ceremony->heapId);
    ceremony->spriteManager = SpriteManager_New(ceremony->spriteSystem);
    SpriteSystem_Init(ceremony->spriteSystem, &oamManagerParam, &charTransferParam, 32);
    SpriteSystem_InitSprites(ceremony->spriteSystem, ceremony->spriteManager, 0x80);
    SpriteSystem_InitManagerWithCapacities(ceremony->spriteSystem, ceremony->spriteManager, &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(ceremony->spriteSystem), 0, FX32_CONST(524));
}

static void PokeathlonCourseCeremony_FreeSprites(PokeathlonCourseCeremony *ceremony) {
    u8 i;

    for (i = 0; i < NELEMS(ceremony->sprites); i++) {
        if (ceremony->sprites[i] != NULL) {
            Sprite_DeleteAndFreeResources(ceremony->sprites[i]);
            ceremony->sprites[i] = NULL;
        }
    }
    SpriteSystem_FreeResourcesAndManager(ceremony->spriteSystem, ceremony->spriteManager);
    SpriteSystem_Free(ceremony->spriteSystem);
}

static void PokeathlonCourseCeremony_CreateTrainerSprites(PokeathlonCourseCeremony *ceremony) {
    ManagedSpriteTemplate template = { 0 };
    int i;
    int x = 32;
    PokeathlonCourseCeremony *cursor = ceremony;

    for (i = 0; i < 5;) {
        template.resIdList[GF_GFX_RES_TYPE_CHAR] = i + 100;
        template.resIdList[GF_GFX_RES_TYPE_PLTT] = i + 100;
        template.resIdList[GF_GFX_RES_TYPE_CELL] = 100;
        template.resIdList[GF_GFX_RES_TYPE_ANIM] = 100;
        template.vram = NNS_G2D_VRAM_TYPE_2DSUB;
        template.bgPriority = 1;
        template.drawPriority = 1;
        template.x = x;
        template.y = 136;
        if (i == 4) {
            template.x = 128;
            template.y = 112;
        }
        cursor->trainerSprites[0] = SpriteSystem_NewSpriteWithYOffset(ceremony->spriteSystem, ceremony->spriteManager, &template, FX32_CONST(524));
        ManagedSprite_SetAnimateFlag(cursor->trainerSprites[0], TRUE);
        i++;
        x += 64;
        cursor = (PokeathlonCourseCeremony *)((u8 *)cursor + sizeof(ManagedSprite *));
    }
}

static void PokeathlonCourseCeremony_CreateScoreSprites(PokeathlonCourseCeremony *ceremony) {
    ManagedSpriteTemplate template = { 0 };
    int i;
    int j;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        int index = i * 4 + 5;
        template.resIdList[GF_GFX_RES_TYPE_CHAR] = 105;
        template.resIdList[GF_GFX_RES_TYPE_PLTT] = 105;
        template.resIdList[GF_GFX_RES_TYPE_CELL] = 101;
        template.resIdList[GF_GFX_RES_TYPE_ANIM] = 101;
        template.vram = NNS_G2D_VRAM_TYPE_2DSUB;
        template.bgPriority = 1;
        template.drawPriority = 2;
        template.x = i * 64 + 32;
        template.y = 72;
        template.animation = 0;
        template.pal = i + 1;
        ceremony->sprites[index] = SpriteSystem_NewSpriteWithYOffset(ceremony->spriteSystem, ceremony->spriteManager, &template, FX32_CONST(524));
        ManagedSprite_SetAnimateFlag(ceremony->sprites[index], TRUE);
        template.pal = 0;
        template.bgPriority = 1;
        template.drawPriority = 1;
        template.x -= 16;
        template.animation = 1;
        for (j = 0; j < 3; j++) {
            int digit = index + 1 + j;
            ceremony->sprites[digit] = SpriteSystem_NewSpriteWithYOffset(ceremony->spriteSystem, ceremony->spriteManager, &template, FX32_CONST(524));
            ManagedSprite_SetAnimateFlag(ceremony->sprites[digit], TRUE);
            template.x += 16;
        }
    }
}

static void PokeathlonCourseCeremony_CreateMonPicSprites(PokeathlonCourseCeremony *ceremony) {
    ManagedSpriteTemplate template = { 0 };
    int i;
    int x = 48;
    int palette = 2;

    for (i = 0; i < 3; i++) {
        ManagedSprite *sprite;
        template.resIdList[GF_GFX_RES_TYPE_CHAR] = 109 + i;
        template.resIdList[GF_GFX_RES_TYPE_PLTT] = 106;
        template.resIdList[GF_GFX_RES_TYPE_CELL] = 104;
        template.resIdList[GF_GFX_RES_TYPE_ANIM] = 104;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.x = x;
        template.y = 112;
        template.bgPriority = 0;
        template.drawPriority = 1;
        {
            PokeathlonCourseCeremony *slot = (PokeathlonCourseCeremony *)((u8 *)ceremony + (21 + i) * sizeof(ManagedSprite *));
            sprite = SpriteSystem_NewSpriteWithYOffset(ceremony->spriteSystem, ceremony->spriteManager, &template, FX32_CONST(524));
            slot->sprites[0] = sprite;
            ManagedSprite_SetPaletteOverride(sprite, palette);
            ManagedSprite_SetDrawFlag(slot->sprites[0], FALSE);
        }
        palette += 3;
        x += 80;
    }
}

static void PokeathlonCourseCeremony_CreateMedalSprites(PokeathlonCourseCeremony *ceremony) {
    ManagedSpriteTemplate template = { 0 };
    int i;
    for (i = 0; i < 2; i++) {
        int index = i + 24;
        template.resIdList[GF_GFX_RES_TYPE_CHAR] = i + 107;
        template.resIdList[GF_GFX_RES_TYPE_PLTT] = i + 107;
        template.resIdList[GF_GFX_RES_TYPE_CELL] = 103;
        template.resIdList[GF_GFX_RES_TYPE_ANIM] = 103;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.bgPriority = 0;
        template.drawPriority = 2;
        template.x = i * 64 + 96;
        template.y = 56;
        if (ceremony->course < POKEATHLON_SOLO_COURSES) {
            template.x = 128;
        }
        ceremony->sprites[index] = SpriteSystem_NewSpriteWithYOffset(ceremony->spriteSystem, ceremony->spriteManager, &template, FX32_CONST(524));
        ManagedSprite_SetAnimateFlag(ceremony->sprites[index], TRUE);
        ManagedSprite_SetDrawFlag(ceremony->sprites[index], FALSE);
    }
}

// Pictures of the winning team's Pokemon, and their palettes for the overworld sprites.
static void PokeathlonCourseCeremony_LoadWinnerMonPics(PokeathlonCourseData *course, int team) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    NNSG2dPaletteData *palette;
    PokeathlonCourseMonInfo info;
    PokepicTemplate template;
    int i;
    void *file;
    PokeathlonCourse_GetParticipantMons(course, team);
    PokeathlonCourse_GetParticipantData(course, team);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        PokeathlonCourse_GetMonInfo(course, team, i, &info);
        PokeathlonCourse_LoadMonPicWithPalette(ceremony->monPicSprites[i], &info, TRUE, FALSE, ceremony->heapId, FALSE);
        GetMonSpriteCharAndPlttNarcIdsEx(&template, info.species, info.gender, 2, info.isShiny, info.form, info.personality);
        file = GfGfxLoader_GetPlttData((NarcId) template.narcID, template.palDataID, &palette, ceremony->heapId);
        PokeathlonCourseMonObjects_SetPalette(ceremony->objects, i * POKEATHLON_TEAM_SIZE + 1, NNS_G2D_VRAM_TYPE_2DMAIN, palette->pRawData);
        Heap_Free(file);
    }
}

static void PokeathlonCourseCeremony_LoadSpriteResources(PokeathlonCourseData *course) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    SpriteSystem *spriteSystem = ceremony->spriteSystem;
    SpriteManager *spriteManager = ceremony->spriteManager;
    u8 i;
    u8 courseId;

    for (i = 0; i < 5; i++) {
        SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 9, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 100 + i);
        SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 8, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 100 + i);
    }
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 10, TRUE, 100);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 11, TRUE, 100);
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 13, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 105);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 12, FALSE, 5, NNS_G2D_VRAM_TYPE_2DSUB, 105);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 14, TRUE, 101);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 15, TRUE, 101);
    PokeathlonCourseCeremony_LoadMonPicResources(ceremony);
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 16, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 106);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 12, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 106);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 17, TRUE, 102);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 18, TRUE, 102);
    courseId = ceremony->course;
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_1_5_4, PokeathlonCourseCeremony_GetCourseMedal(courseId, 0) + 23, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 107);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_1_5_4, PokeathlonCourseCeremony_GetCourseMedal(courseId, 1) + 23, FALSE, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 108);
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, PokeathlonCourseCeremony_GetCourseMedal(courseId, 0) + 28, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 107);
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, PokeathlonCourseCeremony_GetCourseMedal(courseId, 1) + 28, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 108);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 33, TRUE, 103);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 34, TRUE, 103);
}

static void PokeathlonCourseCeremony_LoadMonPicResources(PokeathlonCourseCeremony *ceremony) {
    SpriteSystem *spriteSystem = ceremony->spriteSystem;
    int i;
    SpriteManager *spriteManager = ceremony->spriteManager;
    NNS_G2D_VRAM_TYPE vram = NNS_G2D_VRAM_TYPE_2DMAIN;

    for (i = 0; i < 3; i++) {
        SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 20, TRUE, vram, 109 + i);
    }
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 21, TRUE, 104);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 22, TRUE, 104);
}

// The pictures replace the overworld sprites of the winner's Pokemon on the top screen.
static void PokeathlonCourseCeremony_ShowWinnerTeam(PokeathlonCourseData *course, int team) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    u32 i;
    PokeathlonCourseMonObject *member1;
    PokeathlonCourseMonObject *member2;
    i = 0;
    for (; (s32)i < POKEATHLON_PARTICIPANTS; i++) {
        member1 = PokeathlonCourseMonObjects_Get(ceremony->objects, POKEATHLON_TEAM_SIZE * i + 1);
        member2 = PokeathlonCourseMonObjects_Get(ceremony->objects, POKEATHLON_TEAM_SIZE * i + 2);
        PokeathlonCourseMonObject_SetDrawFlag(member1, FALSE);
        PokeathlonCourseMonObject_SetDrawFlag(member2, FALSE);
    }
    PokeathlonCourseCeremony_LoadWinnerMonPics(course, team);
}

static void PokeathlonCourseCeremony_LoadTrainerSprites(PokeathlonCourseData *course) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    ManagedSprite **sprites;
    int i = 0;
    PokeathlonCourseCeremony *cursor = ceremony;
    sprites = ceremony->trainerSprites;

    for (; i < 5; i++) {
        int count = PokeathlonCourse_GetParticipantCount(course);
        if (i == 4) {
            int fileId = PokeathlonCourse_GetTrainerPicFileId(2);
            PokeathlonCourse_LoadTrainerPic(cursor->trainerSprites[0], fileId, 11, ceremony->heapId);
        } else if (i < count) {
            PokeathlonCourse_LoadTeamTrainerPic(sprites, course, i, 0);
        } else {
            u8 npcTeam = *(u32 *)PokeathlonCourse_GetParticipantData(course, i);
            int fileId = PokeathlonCourse_GetNpcTrainerPicFileId(PokeathlonCourse_GetNpcTeamSpriteId(npcTeam));
            PokeathlonCourse_LoadTrainerPic(cursor->trainerSprites[0], fileId, 0, ceremony->heapId);
        }
        cursor = (PokeathlonCourseCeremony *)((u8 *)cursor + sizeof(ManagedSprite *));
    }
}

// pose 1: standing, 2: cheering (frame 27 for the NPC trainers).
static void PokeathlonCourseCeremony_SetTrainerPose(ManagedSprite **sprites, PokeathlonCourseData *course, int team, int pose, enum HeapID heapId) {
    BOOL isNpc;
    int frame;

    isNpc = *(int *)PokeathlonCourse_GetParticipantData(course, team) > 0;
    switch (pose) {
    case TRAINER_POSE_STANDING:
        frame = 0;
        break;
    case TRAINER_POSE_CHEERING:
        frame = isNpc ? 11 : 27;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    if (isNpc) {
        u8 npcTeam = *(u32 *)PokeathlonCourse_GetParticipantData(course, team);
        int fileId = PokeathlonCourse_GetNpcTrainerPicFileId(PokeathlonCourse_GetNpcTeamSpriteId(npcTeam));
        PokeathlonCourse_LoadTrainerPic(sprites[team], fileId, (u8)frame, heapId);
    } else {
        PokeathlonCourse_LoadTeamTrainerPic(sprites, course, team, frame);
    }
}

static PokeathlonCourseCeremonyScore *PokeathlonCourseCeremony_CreateScores(enum HeapID heapId, ManagedSprite **sprites) {
    PokeathlonCourseCeremonyScore *scores = Heap_Alloc(heapId, sizeof(PokeathlonCourseCeremonyScore) * 4);
    int i;
    int j;

    ManagedSprite **dest;
    int index;

    MI_CpuFill8(scores, 0, sizeof(PokeathlonCourseCeremonyScore) * 4);
    dest = scores->sprites;
    i = 0;
    index = 5;
    for (; i < POKEATHLON_PARTICIPANTS; i++) {
        for (j = 0; j < 4; j++) {
            dest[j] = sprites[index + j];
        }
        dest += sizeof(PokeathlonCourseCeremonyScore) / sizeof(ManagedSprite *);
        index += 4;
    }
    return scores;
}

static void PokeathlonCourseCeremony_FreeScores(PokeathlonCourseCeremonyScore *scores) {
    Heap_Free(scores);
}

static void PokeathlonCourseCeremony_UpdateScores(PokeathlonCourseCeremonyScore *scores) {
    int i;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourseCeremonyScore_Update(&scores[i]);
    }
}

static BOOL PokeathlonCourseCeremony_AreScoresCounted(PokeathlonCourseCeremonyScore *scores) {
    int i;
    BOOL result = TRUE;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (!PokeathlonCourseCeremonyScore_IsCounted(&scores[i])) {
            result = FALSE;
        }
    }
    return result;
}

static void PokeathlonCourseCeremony_AddPoints(PokeathlonCourseCeremonyScore *scores, int team, u32 points) {
    if (points != 0) {
        PokeathlonCourseCeremonyScore_Add(&scores[team], points);
    }
}

static u32 PokeathlonCourseCeremony_GetPoints(PokeathlonCourseCeremonyScore *scores, u8 team) {
    return scores[team].points;
}

static int PokeathlonCourseCeremony_CompareRanks(const void *a, const void *b) {
    u16 right = *(const u32 *)b;
    u16 left = *(const u32 *)a;

    if (left == right) {
        return 0;
    }
    if (left < right) {
        return 1;
    }
    return -1;
}

// Sorts the teams by points; equal points share the place.
static void PokeathlonCourseCeremony_RankTeams(PokeathlonCourseCeremonyScore *scores, PokeathlonCourseCeremonyRank *ranks, const u8 *drawingLots) {
    int i;
    int place = 0;

    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        ranks[i].team = i;
        ranks[i].points = PokeathlonCourseCeremony_GetPoints(scores, i);
        ranks[i].drawingLot = drawingLots[i];
    }

    MATH_QSort(ranks, POKEATHLON_PARTICIPANTS, sizeof(PokeathlonCourseCeremonyRank), PokeathlonCourseCeremony_CompareRanks, NULL);

    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        ranks[i].place = place;
        if (i != POKEATHLON_PARTICIPANTS - 1 && ranks[i].points != ranks[i + 1].points) {
            place = i + 1;
        }
    }
}

static void PokeathlonCourseCeremonyScore_Update(PokeathlonCourseCeremonyScore *score) {
    u32 shownPoints;
    u16 hundreds;
    u16 tens;
    u16 ones;
    int i;

    if (score->counting) {
        shownPoints = score->shownPoints + 1;
        if (shownPoints > POKEATHLON_POINTS_MAX) {
            shownPoints = POKEATHLON_POINTS_MAX;
        }
        score->shownPoints = shownPoints;
        if (!IsSEPlaying(SEQ_SE_GS_THLON02)) {
            PlaySE(SEQ_SE_GS_THLON02);
        }

        hundreds = PokeathlonUtil_GetDecimalDigit(score->shownPoints, 3);
        tens = PokeathlonUtil_GetDecimalDigit(score->shownPoints, 2);
        ones = PokeathlonUtil_GetDecimalDigit(score->shownPoints, 1);
        ManagedSprite_SetAnim(score->sprites[1], hundreds + 1);
        ManagedSprite_SetAnim(score->sprites[2], tens + 1);
        ManagedSprite_SetAnim(score->sprites[3], ones + 1);

        // the plate rises by a pixel every 20 points
        if (score->shownPoints % 20 == 0) {
            for (i = 0; i < 4; i++) {
                ManagedSprite_OffsetPositionXY(score->sprites[i], 0, -1);
            }
        }
        if (score->shownPoints >= score->points) {
            score->counting = FALSE;
        }
    }
}

static BOOL PokeathlonCourseCeremonyScore_IsCounted(PokeathlonCourseCeremonyScore *score) {
    return !score->counting;
}

static void PokeathlonCourseCeremonyScore_Add(PokeathlonCourseCeremonyScore *score, u32 points) {
    u32 total = score->points + points;
    if (total > POKEATHLON_POINTS_MAX) {
        total = POKEATHLON_POINTS_MAX;
    }
    score->points = total;
    score->counting = TRUE;
}

static void PokeathlonCourseConfetti_Spawn(PokeathlonCourseConfettiPiece *piece, SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    ManagedSpriteTemplate template;
    u32 value;
    s32 offset;
    float floatValue;

    GF_ASSERT(piece != NULL);
    MI_CpuFill8(piece, 0, sizeof(*piece));

    value = MTRandom() % 5;
    if (value != 0) {
        value = MTRandom() % 5;
        floatValue = (float)(value << FX32_SHIFT) + 0.5f;
    } else {
        value = MTRandom() % 5;
        floatValue = (float)(value << FX32_SHIFT) - 0.5f;
    }
    offset = floatValue;
    piece->yVelocity = (offset >> 1) + 0x1800;

    if (MTRandom() & 1) {
        value = MTRandom() & 1;
        floatValue = (float)(value << FX32_SHIFT) + 0.5f;
    } else {
        value = MTRandom() & 1;
        floatValue = (float)(value << FX32_SHIFT) - 0.5f;
    }
    piece->xVelocity = ((s32)floatValue + 0x19A) >> 1;

    if ((MTRandom() & 0xFF) != 0) {
        value = MTRandom() & 0xFF;
        floatValue = (float)(value << FX32_SHIFT) + 0.5f;
    } else {
        value = MTRandom() & 0xFF;
        floatValue = (float)(value << FX32_SHIFT) - 0.5f;
    }
    piece->x = floatValue;

    piece->state.speed = MTRandom() % 5 + 1;
    piece->state.active = TRUE;
    template = sPokeathlonCourseConfettiSpriteTemplate;
    template.x = piece->x >> FX32_SHIFT;
    if (!(MTRandom() & 1)) {
        template.animation = 12;
    }
    piece->sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, FX32_CONST(524));
    ManagedSprite_SetAnimateFlag(piece->sprite, TRUE);
}

// Returns TRUE when the piece falls off the screen for the first time (it is then put back on
// top of the screen).
static BOOL PokeathlonCourseConfetti_Fall(PokeathlonCourseConfettiPiece *piece) {
    BOOL result = FALSE;
    s64 velocity;
    s64 sine;
    fx32 xVelocity;

    GF_ASSERT(piece != NULL);
    xVelocity = piece->xVelocity;
    sine = GF_SinDeg(piece->state.angle * piece->state.speed);
    velocity = sine * xVelocity;
    piece->x += (velocity + 0x800) >> FX32_SHIFT;
    piece->y += piece->yVelocity;
    ManagedSprite_SetPositionFxXYWithSubscreenOffset(piece->sprite, piece->x, piece->y, FX32_CONST(524));
    if ((piece->y >> FX32_SHIFT) > 224) {
        if (piece->state.landed) {
            piece->state.active = FALSE;
            Sprite_DeleteAndFreeResources(piece->sprite);
            piece->sprite = NULL;
        } else {
            piece->state.landed = TRUE;
            result = TRUE;
        }
    }
    piece->state.angle += MTRandom() & 1;
    return result;
}

// Moves the piece to the top screen.
static void PokeathlonCourseConfetti_MoveToTopScreen(PokeathlonCourseConfettiPiece *piece, SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    ManagedSpriteTemplate template = sPokeathlonCourseConfettiTopSpriteTemplate;

    piece->y = 0;
    template.animation = ManagedSprite_GetActiveAnim(piece->sprite) - 11;
    template.x = piece->x >> FX32_SHIFT;
    template.y = piece->y >> FX32_SHIFT;
    Sprite_DeleteAndFreeResources(piece->sprite);
    piece->sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, FX32_CONST(524));
    ManagedSprite_SetAnimateFlag(piece->sprite, TRUE);
}

static PokeathlonCourseConfetti *PokeathlonCourseConfetti_New(enum HeapID heapId, SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    PokeathlonCourseConfetti *confetti;

    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    confetti = Heap_Alloc(heapId, sizeof(*confetti));
    MI_CpuFill8(confetti, 0, sizeof(*confetti));
    confetti->heapId = heapId;
    confetti->spriteSystem = spriteSystem;
    confetti->spriteManager = spriteManager;
    confetti->delay = PokeathlonCourseConfetti_GetRandomDelay();
    return confetti;
}

static void PokeathlonCourseConfetti_Free(PokeathlonCourseConfetti *confetti) {
    int i;

    GF_ASSERT(confetti != NULL);
    for (i = 0; i < POKEATHLON_CONFETTI_PIECES; i++) {
        if (confetti->pieces[i].sprite != NULL) {
            Sprite_DeleteAndFreeResources(confetti->pieces[i].sprite);
            confetti->pieces[i].sprite = NULL;
        }
    }
    Heap_Free(confetti);
}

static void PokeathlonCourseConfetti_Update(PokeathlonCourseConfetti *confetti) {
    int i;
    PokeathlonCourseConfettiPiece *piece;
    PokeathlonCourseConfettiFlags *flags;

    GF_ASSERT(confetti != NULL);
    if (confetti->active) {
        if (confetti->timer++ > confetti->delay) {
            PokeathlonCourseConfetti_SpawnPieces(confetti, (MTRandom() & 1) + 2);
            confetti->delay = PokeathlonCourseConfetti_GetRandomDelay();
            confetti->timer = 0;
        }
    }
    i = 0;
    flags = &confetti->pieces[0].state;
    piece = confetti->pieces;
    for (; i < POKEATHLON_CONFETTI_PIECES; i++, flags = (PokeathlonCourseConfettiFlags *)((u8 *)flags + sizeof(PokeathlonCourseConfettiPiece)), piece++) {
        if (flags->active == TRUE && PokeathlonCourseConfetti_Fall(piece)) {
            PokeathlonCourseConfetti_MoveToTopScreen(piece, confetti->spriteSystem, confetti->spriteManager);
        }
    }
}

static void PokeathlonCourseConfetti_Start(PokeathlonCourseConfetti *confetti, BOOL active) {
    confetti->active = active;
    GfGfxLoader_GXLoadPal(NARC_a_1_5_4, 12, GF_PAL_LOCATION_MAIN_OBJ, GF_PAL_SLOT_11_OFFSET, 0x20, confetti->heapId);
}

static void PokeathlonCourseConfetti_SpawnPieces(PokeathlonCourseConfetti *confetti, u8 count) {
    int spawned = 0;
    int next;
    vs32 i;
    u32 *flags;
    PokeathlonCourseConfettiPiece *piece;
    GF_ASSERT(confetti != NULL);
    i = 0;
    flags = &confetti->pieces[0].state.raw;
    piece = confetti->pieces;
    do {
        if (((*flags << 11) >> 31) == 0) {
            PokeathlonCourseConfetti_Spawn(piece, confetti->spriteSystem, confetti->spriteManager);
            if (++spawned >= count) {
                break;
            }
        }
        next = i + 1;
        flags += sizeof(PokeathlonCourseConfettiPiece) / sizeof(u32);
        piece++;
        i = next;
    } while (next < POKEATHLON_CONFETTI_PIECES);
}

static BOOL PokeathlonCourseCeremony_Init(PokeathlonCourseData *course) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    PokeathlonCourseMonInfo infos[POKEATHLON_MONS];
    int i;
    PokeathlonCourseMonObject *object;
    int mode;

    switch (PokeathlonCourse_GetEventInitState(course)) {
    case CEREMONY_INIT_CREATE:
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_135, 0x60000);
        HandleLoadOverlay(FS_OVERLAY_ID(OVY_98), OVY_LOAD_ASYNC);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonCourseCeremony_SetBanks();
        ceremony = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonCourseCeremony));
        MI_CpuFill8(ceremony, 0, sizeof(PokeathlonCourseCeremony));
        ceremony->heapId = HEAP_ID_135;
        ceremony->course = PokeathlonCourse_FindCourseId(course);
        ceremony->bgConfig = BgConfig_Alloc(ceremony->heapId);
        ceremony->messageBox = PokeathlonCourseMessageBox_New(ceremony->heapId);
        PokeathlonCourseCeremony_InitSpriteSystem(ceremony);
        ceremony->spriteResources = PokeathlonCourseSprites_CreateResources(ceremony->heapId, 6, NNS_G2D_VRAM_TYPE_2DMAIN);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case CEREMONY_INIT_LOAD_MONS: {
        PokeathlonCourseMonGfxTemplate template = { 0 };
        ceremony->objects = PokeathlonCourseMonObjects_Create(ceremony->heapId, 12, 3, ceremony->spriteResources, SpriteManager_GetSpriteList(ceremony->spriteManager));
        for (i = 0; i < POKEATHLON_MONS; i++) {
            int member = i % POKEATHLON_TEAM_SIZE;
            int team = i / POKEATHLON_TEAM_SIZE;
            PokeathlonCourse_GetMonInfo(course, team, member, &infos[i]);
            template.sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, team, member));
        }
        template.loadAtOnce = FALSE;
        template.priority = 3;
        template.vramTransfer = FALSE;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(ceremony->objects, POKEATHLON_MONS, infos, &template, 1, 0);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case CEREMONY_INIT_CREATE_SPRITES:
        if (PokeathlonCourseMonObjects_IsLoaded(ceremony->objects)) {
            PokeathlonCourseCeremony_LoadSpriteResources(course);
            PokeathlonCourseCeremony_CreateTrainerSprites(ceremony);
            PokeathlonCourseCeremony_CreateScoreSprites(ceremony);
            PokeathlonCourseCeremony_CreateMonPicSprites(ceremony);
            PokeathlonCourseCeremony_CreateMedalSprites(ceremony);
            ceremony->scores = PokeathlonCourseCeremony_CreateScores(ceremony->heapId, ceremony->sprites);
            ceremony->confetti = PokeathlonCourseConfetti_New(ceremony->heapId, ceremony->spriteSystem, ceremony->spriteManager);
            PokeathlonCourseCeremony_LoadTrainerSprites(course);
            PokeathlonCourse_AdvanceEventInitState(course);
        }
        break;
    case CEREMONY_INIT_START:
        PokeathlonCourse_SetVBlankIntrCB((PokeathlonCourseData *)ceremony->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        for (i = 0; i < POKEATHLON_MONS; i++) {
            int team;
            int member;
            object = PokeathlonCourseMonObjects_Get(ceremony->objects, i);
            PokeathlonCourseMonObject_SetDrawFlag(object, TRUE);
            Sprite_GetCellAnim(PokeathlonCourseMonGfx_GetSprite(PokeathlonCourseMonObject_GetGfx(object)))->animCtrl.currentTime = (i * 3) << FX32_SHIFT;
            PokeathlonCourseMonObject_SetAnimState(object, 1);
            team = i / POKEATHLON_TEAM_SIZE;
            member = i % POKEATHLON_TEAM_SIZE;
            PokeathlonCourseObject_SetGroundPosition(object, 32 + (team << 6), 48 * (member + 1));
        }
        PokeathlonCourseCeremony_InitBgs(ceremony->bgConfig);
        PokeathlonCourseCeremony_LoadBgGfx(ceremony->bgConfig, ceremony->heapId);
        mode = PokeathlonCourse_GetMode(course);
        PokeathlonCourseMessageBox_Init(ceremony->messageBox, ceremony->bgConfig, GF_BG_LYR_SUB_0, mode, PokeathlonCourse_GetSaveData(course));
        WirelessStatusIcon_CreateOnScreenIfConnected(2);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        ceremony->state = 0;
        return TRUE;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

static BOOL PokeathlonCourseCeremony_Main(PokeathlonCourseData *course) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    SpriteSystem_DrawSprites(ceremony->spriteManager);
    return TRUE;
}

static BOOL PokeathlonCourseCeremony_Exit(PokeathlonCourseData *course) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourseConfetti_Free(ceremony->confetti);
    PokeathlonCourseCeremony_FreeScores(ceremony->scores);
    PokeathlonCourseMessageBox_Free(ceremony->messageBox);
    FreeBgTilemapBuffer(ceremony->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(ceremony->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(ceremony->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(ceremony->bgConfig, GF_BG_LYR_SUB_1);
    Heap_Free(ceremony->bgConfig);
    PokeathlonCourseMonObjects_Free(ceremony->objects);
    PokeathlonCourseSprites_FreeResources(ceremony->spriteResources);
    WirelessStatusIcon_Destroy();
    PokeathlonCourseCeremony_FreeSprites(ceremony);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_98));
    Heap_Destroy(HEAP_ID_135);
    return TRUE;
}

// Puts the nickname of the team's member-th Pokemon into placeholder field.
static void PokeathlonCourseCeremony_BufferMonName(PokeathlonCourseData *course, int team, int member, int field) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    PokeathlonCourseMon *mons = (PokeathlonCourseMon *)PokeathlonCourse_GetParticipantMons(course, team);
    String *string = String_New(11, ceremony->heapId);
    CopyU16ArrayToString(string, mons[member].nickname);
    BufferString(PokeathlonCourseMessageBox_GetMsgFormat(ceremony->messageBox), field, string, 2, 1, 0);
    String_Delete(string);
}

static void PokeathlonCourseCeremony_BufferTeamPoints(PokeathlonCourseData *course, int team, int points) {
    MessageFormat *msgFormat = PokeathlonCourseMessageBox_GetMsgFormat(((PokeathlonCourseCeremony *)PokeathlonCourse_GetWork(course))->messageBox);
    PlayerProfile *profile = PokeathlonCourse_GetPlayerProfileFromData(course, team);
    BufferPlayersName(msgFormat, 0, profile);
    PokeathlonCourseCeremony_BufferNumber(msgFormat, points, 3, 1);
}

static void PokeathlonCourseCeremony_BufferTeamMon(PokeathlonCourseData *course, int team, int member) {
    MessageFormat *msgFormat = PokeathlonCourseMessageBox_GetMsgFormat(((PokeathlonCourseCeremony *)PokeathlonCourse_GetWork(course))->messageBox);
    PlayerProfile *profile = PokeathlonCourse_GetPlayerProfileFromData(course, team);
    BufferPlayersName(msgFormat, 0, profile);
    PokeathlonCourseCeremony_BufferMonName(course, team, member, 1);
}

static u32 PokeathlonCourseCeremony_HasNoMissBonus(PokeathlonCourseData *course) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course);
    GF_ASSERT(copyArea);
    GF_ASSERT(data);
    return MATH_CountPopulation(data->noMissMons);
}

static BOOL PokeathlonCourseCeremony_IsNoMissMon(PokeathlonCourseData *course, int team, int member) {
    int index = member + team * 3;
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course);
    GF_ASSERT(copyArea);
    GF_ASSERT(data);
    GF_ASSERT(index < POKEATHLON_MONS);
    return data->noMissMons & (1 << index);
}

static BOOL PokeathlonCourseCeremony_IsPointsLeader(PokeathlonCourseData *course, int team, int member) {
    int index = member + team * 3;
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course);
    GF_ASSERT(copyArea);
    GF_ASSERT(data);
    GF_ASSERT(index < POKEATHLON_MONS);
    return data->pointsLeaderMons & (1 << index);
}

static BOOL PokeathlonCourseCeremony_IsEffortPrizeMon(PokeathlonCourseData *course, int team, int member) {
    int index = member + team * 3;
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course);
    GF_ASSERT(copyArea);
    GF_ASSERT(data);
    return data->effortPrizeMons & (1 << index);
}

static int PokeathlonCourseConfetti_GetRandomDelay(void) {
    return (MTRandom() & 7) + 4;
}

static u8 PokeathlonCourseCeremony_GetChallengeBonus(PokeathlonCourseData *course, u8 team) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return data->challengeBonus[team];
}

static u32 PokeathlonCourseCeremony_GetEventPoints(PokeathlonCourseData *course, u8 team, u8 round) {
    u8 event = PokeathlonCourse_GetRoundEvent(course, round);
    return PokeathlonCourseScoreList_GetEventPoints(PokeathlonCourse_GetGraphicsSystem(course), event, team);
}

static int PokeathlonCourseCeremony_GetNoMissPoints(PokeathlonCourseCeremony *ceremony) {
    return 10;
}

static int PokeathlonCourseCeremony_GetPointsLeaderPoints(PokeathlonCourseCeremony *ceremony) {
    return 20;
}

static int PokeathlonCourseCeremony_GetEffortPrizePoints(PokeathlonCourseCeremony *ceremony) {
    return 10;
}

static u32 PokeathlonCourseCeremony_CountNoMissMons(PokeathlonCourseData *course) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return MATH_CountPopulation(data->noMissMons);
}

static u32 PokeathlonCourseCeremony_CountPointsLeaders(PokeathlonCourseData *course) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return MATH_CountPopulation(data->pointsLeaderMons);
}

static u32 PokeathlonCourseCeremony_CountEffortPrizes(PokeathlonCourseData *course) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return MATH_CountPopulation(data->effortPrizeMons);
}

static void PokeathlonCourseCeremony_GetDrawingLots(PokeathlonCourseData *course, u8 *drawingLots) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    s32 i;
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        drawingLots[i] = data->drawingLots[i];
    }
}

static u32 PokeathlonCourseCeremony_GetIntroMsgId(PokeathlonCourseData *course, u32 team) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyOpeningData *data = (PokeathlonCourseCeremonyOpeningData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return data->intros[team].msgId;
}

static u32 PokeathlonCourseCeremony_GetIntroValue(PokeathlonCourseData *course, u32 team) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyOpeningData *data = (PokeathlonCourseCeremonyOpeningData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return data->intros[team].value;
}

static u32 PokeathlonCourseCeremony_GetIntroCheer(PokeathlonCourseData *course, u32 team) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyOpeningData *data = (PokeathlonCourseCeremonyOpeningData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return data->intros[team].cheer;
}

// Host: the introduction line of every team (from the player's records, the other players'
// records or the NPC team's line).
static void PokeathlonCourseCeremony_ChooseIntros(PokeathlonCourseData *course) {
    PokeathlonCourseCeremonyIntro *intro = (PokeathlonCourseCeremonyIntro *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT);
    s32 i;
    if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO) {
        for (i = 0; i < POKEATHLON_PARTICIPANTS; i++, intro++) {
            if (i == PokeathlonCourse_GetNetId(course)) {
                PokeathlonCourseCeremony_ChooseOwnIntro(intro, course);
            } else {
                PokeathlonCourseCeremony_ChooseNpcIntro(intro, course, (u8)i);
            }
        }
    } else {
        for (i = 0; i < POKEATHLON_PARTICIPANTS; i++, intro++) {
            if (PokeathlonCourse_GetParticipantCount(course) > i) {
                PokeathlonCourseCeremony_ChooseLinkIntro(intro, course, (u8)i);
            } else {
                PokeathlonCourseCeremony_ChooseNpcIntro(intro, course, (u8)i);
            }
        }
    }
}

// Challenge Bonus: 75 points minus the summed performance of the team's Pokemon.
static u32 PokeathlonCourseCeremony_CalcChallengeBonus(PokeathlonCourseData *course, u8 team) {
    PokeathlonCoursePerformance performance;
    NARC *narc;
    PokeathlonCourseMon *mon;
    s32 bonus = 75;
    s32 i;
    narc = NARC_New(NARC_poketool_personal_performance, PokeathlonCourse_GetHeapID(course));
    mon = (PokeathlonCourseMon *)PokeathlonCourse_GetParticipantMons(course, team);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++, mon++) {
        NARC_ReadWholeMember(narc, PokeathlonCourse_GetPerformanceFileId(mon->species, mon->form), &performance);
        bonus -= performance.stats[0] + 1;
        bonus -= performance.stats[1] + 1;
        bonus -= performance.stats[2] + 1;
        bonus -= performance.stats[3] + 1;
        bonus -= performance.stats[4] + 1;
    }
    if (bonus > 75) {
        bonus = 75;
    } else if (bonus < 0) {
        bonus = 0;
    }
    NARC_Delete(narc);
    return bonus;
}

// The statistic of the prize for effort: the first, from a random one on, that some Pokemon has
// (EFFORT_PRIZE_NONE if none).
static u32 PokeathlonCourseCeremony_ChooseEffortPrizeKind(PokeathlonCourseData *course) {
    s32 tries;
    s32 team;
    {
        BOOL found;
        s32 kind;

        found = FALSE;
        kind = MTRandom() & 3;
        for (tries = 0; tries < EFFORT_PRIZE_KIND_COUNT; tries++) {
            for (team = 0; team < POKEATHLON_PARTICIPANTS; team++) {
                s32 member;

                for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
                    if (PokeathlonCourseCeremony_GetMonStat(course, kind, team, member)) {
                        found = TRUE;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
            kind = (kind + 1) % EFFORT_PRIZE_KIND_COUNT;
        }
        if (!found) {
            kind = EFFORT_PRIZE_NONE;
        }
        return kind;
    }
}

// Host: the bonuses and prizes of the closing ceremony.
static void PokeathlonCourseCeremony_ChooseAwards(PokeathlonCourseData *course) {
    int team;
    int i;
    int maxEffort;
    int kind;
    int effort;
    int value;
    int bit;
    PokeathlonCourseMonEventStats *stats;
    u32 maxPoints;
    PokeathlonCourseMonEventStats *teamStats;
    PokeathlonCourseCeremonyClosingData *data;
    int member;
    int index;

    stats = (PokeathlonCourseMonEventStats *)PokeathlonCourse_GetFieldData(course);
    data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT);
    data->noMissMons = 0;
    data->effortPrizeMons = 0;
    data->pointsLeaderMons = 0;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        data->challengeBonus[i] = PokeathlonCourseCeremony_CalcChallengeBonus(course, i);
    }
    data->effortPrizeKind = PokeathlonCourseCeremony_ChooseEffortPrizeKind(course);
    maxEffort = 0;
    maxPoints = 0;
    kind = data->effortPrizeKind;
    for (team = 0, teamStats = stats; team < POKEATHLON_PARTICIPANTS; team++) {
        for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
            if (kind != EFFORT_PRIZE_NONE) {
                effort = PokeathlonCourseCeremony_GetMonStat(course, kind, team, member);
                if (maxEffort < effort) {
                    maxEffort = effort;
                }
            }
            if (maxPoints < teamStats[member].points) {
                maxPoints = teamStats[member].points;
            }
        }
        teamStats += POKEATHLON_TEAM_SIZE;
    }
    for (i = 0, bit = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
            u8 mon = member + bit;
            if (stats[member].failed == 0 && stats[member].fellDown == 0 && stats[member].selfImpeded == 0) {
                data->noMissMons += 1 << mon;
            }
            if (maxPoints == stats[member].points) {
                data->pointsLeaderMons += 1 << mon;
            }
            if (kind != EFFORT_PRIZE_NONE) {
                value = PokeathlonCourseCeremony_GetMonStat(course, kind, i, member);
                GF_ASSERT(value <= maxEffort);
                if (maxEffort == value) {
                    data->effortPrizeMons += 1 << mon;
                }
            }
        }
        bit += POKEATHLON_TEAM_SIZE;
        stats += POKEATHLON_TEAM_SIZE;
    }
    data->maxEffort = maxEffort;
    index = MTRandom() & 3;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        data->drawingLots[index] = i;
        index = (index + 1) % POKEATHLON_PARTICIPANTS;
    }
}

// The which-th (0, 1) medal for winning course; course 10 has the first course's medal only.
static u32 PokeathlonCourseCeremony_GetCourseMedal(u32 course, u32 which) {
    switch (course) {
    case POKEATHLON_COURSE_LINK_RANDOM:
        return 0;
    case POKEATHLON_COURSE_LINK_SPEED_JUMP:
        return (u8)(which ? 4 : 0);
    case POKEATHLON_COURSE_LINK_SKILL_JUMP:
        return (u8)(which ? 2 : 4);
    case POKEATHLON_COURSE_LINK_POWER_SKILL:
        return (u8)(which ? 1 : 2);
    case POKEATHLON_COURSE_LINK_POWER_STAMINA:
        return (u8)(which ? 3 : 1);
    case POKEATHLON_COURSE_LINK_SPEED_STAMINA:
        return (u8)(which ? 0 : 3);
    default:
        return course;
    }
}

static u8 PokeathlonCourseCeremony_GetEffortPrizeKind(PokeathlonCourseData *course) {
    u8 *copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourseCeremonyClosingData *data = (PokeathlonCourseCeremonyClosingData *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    GF_ASSERT(course != NULL);
    GF_ASSERT(copyArea != NULL);
    GF_ASSERT(data != NULL);
    return data->effortPrizeKind;
}

// Statistic of a Pokemon by effort prize kind.
static u32 PokeathlonCourseCeremony_GetMonStat(PokeathlonCourseData *course, u8 kind, u8 team, u8 member) {
    PokeathlonCourseMonEventStats(*stats)[POKEATHLON_TEAM_SIZE] = (PokeathlonCourseMonEventStats(*)[POKEATHLON_TEAM_SIZE])PokeathlonCourse_GetFieldData(course);
    GF_ASSERT(team < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(member < POKEATHLON_TEAM_SIZE);
    switch (kind) {
    case EFFORT_PRIZE_JUMPED:
        return stats[team][member].jumped;
    case EFFORT_PRIZE_HIT:
        return stats[team][member].hit;
    case EFFORT_PRIZE_FAILED:
        return stats[team][member].failed;
    case EFFORT_PRIZE_DASHED:
        return stats[team][member].dashed;
    default:
        GF_ASSERT(FALSE);
        GF_ASSERT(FALSE);
        return 0;
    }
}

// Next Pokemon; TRUE after the last one.
static BOOL PokeathlonCourseCeremony_NextMon(PokeathlonCourseCeremony *ceremony) {
    ceremony->member++;
    if (ceremony->member >= POKEATHLON_TEAM_SIZE) {
        ceremony->member = 0;
        ceremony->team++;
    }
    return ceremony->team == POKEATHLON_PARTICIPANTS;
}

// Gives the next Pokemon that passes test its points: buffers its name, plays its cry.
static BOOL PokeathlonCourseCeremony_AwardNextMon(PokeathlonCourseData *course, PokeathlonCourseCeremonyAwardTest test, int points) {
    PokeathlonCourseCeremony *ceremony = PokeathlonCourse_GetWork(course);
    int index;
    PokeathlonCourseMonInfo *info;
    do {
        if (test(course, ceremony->team, ceremony->member)) {
            break;
        }
    } while (!PokeathlonCourseCeremony_NextMon(ceremony));
    if (ceremony->team < POKEATHLON_PARTICIPANTS) {
        index = ceremony->team * POKEATHLON_TEAM_SIZE + ceremony->member;
        ceremony->awardCounts[ceremony->team]++;
        ceremony->counter++;
        PokeathlonCourseCeremony_BufferTeamMon(course, ceremony->team, ceremony->member);
        PokeathlonCourseCeremony_AddPoints(ceremony->scores, ceremony->team, (u16)points);
        PokeathlonCourseCeremony_StartCry(ceremony, index);
        info = PokeathlonCourseMonGfx_GetInfo(PokeathlonCourseMonObject_GetGfx(PokeathlonCourseMonObjects_Get(ceremony->objects, index)));
        Chatot_SetForceDefaultCry(1);
        PlayCry(info->species, info->form);
        PokeathlonCourseCeremony_NextMon(ceremony);
        return TRUE;
    }
    return FALSE;
}

// Keeps the result of the ceremony for the course statistics.
static void PokeathlonCourseCeremony_SaveResult(PokeathlonCourseData *course, PokeathlonCourseCeremonyScore *scores) {
    int own;
    PokeathlonCourseCeremony *ceremony;
    PokeathlonCourseCeremonyResult *result;
    int i;
    int fewest;
    int place;
    own = PokeathlonCourse_GetNetId(course);
    ceremony = PokeathlonCourse_GetWork(course);
    result = (PokeathlonCourseCeremonyResult *)PokeathlonCourse_GetFieldData(course);
    if (ceremony->ranks[0].team == own) {
        result->won = TRUE;
    }
    i = 0;
    fewest = 999;
    for (; i < POKEATHLON_PARTICIPANTS; i++) {
        int points = PokeathlonCourseCeremony_GetPoints(scores, i);
        if (fewest >= points) {
            fewest = points;
        }
    }
    {
        int points = PokeathlonCourseCeremony_GetPoints(scores, own);
        if (points == fewest) {
            result->fewestPoints = TRUE;
        }
    }
    result->awards = ceremony->awardCounts[own];
    result->points = PokeathlonCourseCeremony_GetPoints(ceremony->scores, own);
    place = PokeathlonCourseCeremony_FindPlace(ceremony->ranks, own);
    GF_ASSERT(place != -1);
    result->place = place;
}

static void PokeathlonCourseCeremony_BufferNumber(MessageFormat *msgFormat, s32 value, u32 digits, u32 field) {
    BufferIntegerAsString(msgFormat, field, value, digits, PRINTING_MODE_LEFT_ALIGN, TRUE);
}

// Cheer level 0..CHEER_LEVEL_MAX of a value (thresholds sPokeathlonCourseCeremonyCheerThresholds).
static u32 PokeathlonCourseCeremony_GetCheerLevel(s32 value) {
    s32 i;
    for (i = 0; i < CHEER_LEVEL_MAX; i++) {
        if (sPokeathlonCourseCeremonyCheerThresholds[i] > value) {
            return i;
        }
    }
    return i;
}

// First of the four introduction lines (msg 309 #32 + 4 * statistic) about a statistic.
static int PokeathlonCourseCeremony_GetIntroMsgBase(int statistic) {
    return statistic * 4 + 32;
}

// The 29 statistics the introduction lines are about.
static void PokeathlonCourseCeremony_GetIntroStats(PokeathlonStatistics *dest, const PokeathlonStatistics *src) {
    int i;
    u32 sum = 0;

    for (i = 0; i < POKEATHLON_EVENT_COUNT; i++) {
        sum += src->eventFirstPlaces[i];
    }
    dest->playTime = src->coursesJoined;
    dest->coursesJoined = src->courseFirstPlaces;
    dest->courseFirstPlaces = src->courseLastPlaces;
    dest->courseLastPlaces = sum;
    dest->bonusesEarned = src->eventLastPlaces;
    dest->monInstructions = src->bonusesEarned;
    dest->monFailures = src->monInstructions;
    dest->monJumps = src->monFailures;
    dest->monPointsEarned = src->monJumps;
    dest->monTackles = src->monPointsEarned;
    dest->monFalls = src->monTackles;
    dest->monDashes = src->monFalls;
    dest->monSwitches = src->monDashes;
    dest->monSelfImpedes = src->monSwitches;
    dest->linkCoursesJoined = src->linkCoursesJoined;
    dest->linkCourseFirstPlaces = src->linkCourseFirstPlaces;
    dest->linkCourseLastPlaces = src->linkCourseLastPlaces;
    for (i = 0; i < POKEATHLON_EVENT_COUNT; i++) {
        dest->eventFirstPlaces[i] = src->eventFirstPlaces[i];
    }
    dest->eventLastPlaces = src->monSelfImpedes;
    dest->fanCount = src->fanCount;
}

// Weighs the statistics (value / sPokeathlonCourseCeremonyIntroStatWeights[i], plus 0..2 at random).
static void PokeathlonCourseCeremony_WeighIntroStats(u8 *weights, const u32 *stats) {
    int i;
    for (i = 0; i < INTRO_STATISTICS; i++) {
        GF_ASSERT(sPokeathlonCourseCeremonyIntroStatWeights[i] != 0);
        weights[i] = MTRandom() % 3;
        if (stats[i] != 0) {
            weights[i] = weights[i] + stats[i] / sPokeathlonCourseCeremonyIntroStatWeights[i];
        }
    }
}

// One of the statistics with the highest weight; *level 0..3 from the weight.
static int PokeathlonCourseCeremony_PickIntroStat(const u8 *weights, u8 *level) {
    u8 candidates[INTRO_STATISTICS] = { 0 };
    u32 max = 0;
    int count = 0;
    int i;
    u8 *candidate;

    for (i = 0; i < INTRO_STATISTICS; i++) {
        if (max < weights[i]) {
            max = weights[i];
        }
    }
    i = 0;
    candidate = candidates;
    while (i < INTRO_STATISTICS) {
        if (max == weights[i]) {
            *candidate++ = i;
            count++;
        }
        i++;
    }
    for (i = 0; i < 4; i++) {
        if ((u32)max >= sPokeathlonCourseCeremonyIntroStatThresholds[i]) {
            *level = 3 - i;
            break;
        }
    }
    return candidates[MTRandom() % count];
}

static void PokeathlonCourseCeremony_ChooseOwnIntro(PokeathlonCourseCeremonyIntro *intro, PokeathlonCourseData *course) {
    PokeathlonStatistics stats = { 0 };
    u8 weights[INTRO_STATISTICS] = { 0 };
    u8 level;
    PokeathlonStatistics *records;
    u8 statistic;

    records = PokeathlonSave_GetStatistics2(Save_Pokeathlon_Get(PokeathlonCourse_GetSaveData(course)));
    PokeathlonCourseCeremony_GetIntroStats(&stats, records);
    PokeathlonCourseCeremony_WeighIntroStats(weights, (u32 *)&stats);
    statistic = PokeathlonCourseCeremony_PickIntroStat(weights, &level);
    intro->msgId = level + PokeathlonCourseCeremony_GetIntroMsgBase(statistic);
    intro->value = ((u32 *)&stats)[statistic];
    intro->cheer = PokeathlonCourseCeremony_GetCheerLevel(records->fanCount);
}

static void PokeathlonCourseCeremony_ChooseLinkIntro(PokeathlonCourseCeremonyIntro *intro, PokeathlonCourseData *course, int team) {
    PokeathlonStatistics stats = { 0 };
    u8 weights[INTRO_STATISTICS] = { 0 };
    u8 level;
    PokeathlonStatistics *records;
    u8 statistic;

    records = PokeathlonCourse_GetRecord(course, team);
    PokeathlonCourseCeremony_GetIntroStats(&stats, records);
    PokeathlonCourseCeremony_WeighIntroStats(weights, (u32 *)&stats);
    statistic = PokeathlonCourseCeremony_PickIntroStat(weights, &level);
    intro->msgId = level + PokeathlonCourseCeremony_GetIntroMsgBase(statistic);
    intro->value = ((u32 *)&stats)[statistic];
    intro->cheer = PokeathlonCourseCeremony_GetCheerLevel(records->fanCount);
}

typedef struct NpcIntroLocals {
    volatile int team;
    PokeathlonParticipantData *volatile participant;
} NpcIntroLocals;

// NPC team: its own line (msg 311); the cheer from its Pokemon's performance.
static void PokeathlonCourseCeremony_ChooseNpcIntro(PokeathlonCourseCeremonyIntro *intro, PokeathlonCourseData *course, int team) {
    NpcIntroLocals locals;
    locals.team = team;
    int cheer;
    int i;
    u32 total = 0;
    locals.participant = PokeathlonCourse_GetParticipantData(course, locals.team);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        u8 *stats = PokeathlonCourse_GetMonStats(course, locals.team, i);
        total += stats[2] + stats[0] + stats[1] + stats[3] + stats[4] + 5;
    }
    cheer = (int)total / 3 - 8;
    if (cheer > CHEER_LEVEL_MAX) {
        cheer = CHEER_LEVEL_MAX;
    } else if (cheer < 0) {
        cheer = 0;
    }
    intro->msgId = PokeathlonCourse_GetNpcTeamMsgId(course, (u8) * (u32 *)locals.participant);
    intro->value = 0;
    intro->cheer = cheer;
}

// Place of the team, -1 if it is not ranked.
static int PokeathlonCourseCeremony_FindPlace(const PokeathlonCourseCeremonyRank *ranks, u8 team) {
    int i = 0;
    const PokeathlonCourseCeremonyRank *rank = ranks;
    while (i < POKEATHLON_PARTICIPANTS) {
        if (team == rank->team) {
            return ranks[i].place;
        }
        i++;
        rank++;
    }
    return -1;
}

// Tied first places: the team with the highest drawing lot wins.
static void PokeathlonCourseCeremony_BreakTie(PokeathlonCourseCeremonyRank *ranks) {
    s32 i;
    u32 max = 0;
    s32 winner;
    PokeathlonCourseCeremonyRank *rank;

    for (i = 0, rank = ranks; i < POKEATHLON_PARTICIPANTS; i++, rank++) {
        if (rank->place == 0) {
            rank->place++;
            if (rank->drawingLot > max) {
                max = rank->drawingLot;
                winner = i;
            }
        }
    }
    ranks[winner].place--;
    ranks[winner].points++;
    MATH_QSort(ranks, POKEATHLON_PARTICIPANTS, sizeof(PokeathlonCourseCeremonyRank), PokeathlonCourseCeremony_CompareRanks, NULL);
    ranks[0].points--;
}

// Link: the host waits until every player's text is as far as its own. Returns TRUE while the
// players have to wait.
static inline BOOL SyncMessages(PokeathlonCourseData *course, BOOL closing) {
    BOOL allFinished;
    u32 waiting;
    u8 *received;
    u8 *sent;
    u8 *copyArea;
    PokeathlonCourseCeremony *ceremony;
    PokeathlonCourseCeremonySync *sync;
    u8 messageCount;
    u8 netId;
    s32 i;

    ceremony = PokeathlonCourse_GetWork(course);
    copyArea = PokeathlonCourse_GetDataCopyArea(course);
    sent = PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_OUT);
    received = PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    netId = PokeathlonCourse_GetNetId(course);
    messageCount = ceremony->messageCount;
    waiting = 0;

    if (netId == 0) {
        allFinished = TRUE;
        if (closing) {
            ((PokeathlonCourseCeremonyClosingData *)sent)->messageCount = messageCount;
        } else {
            ((PokeathlonCourseCeremonyOpeningData *)sent)->messageCount = messageCount;
        }
        {
            u8 *dest = PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_INPUTS);
            u8 *src = PokeathlonCourse_ToBytes(copyArea);
            u32 count = 0x24;

            do {
                *dest++ = *src++;
            } while (--count != 0);
        }
        for (i = 0; i < PokeathlonCourse_GetParticipantCount(course); i++) {
            sync = (PokeathlonCourseCeremonySync *)PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_INPUTS + i * POKEATHLON_COURSE_DATA_SLOT_SIZE);
            if (sync->messageCount < messageCount || sync->printing == 1) {
                waiting = 1;
            }
            if (sync->finished == 0) {
                allFinished = FALSE;
            }
        }
        if (closing) {
            if (allFinished) {
                ((PokeathlonCourseCeremonyClosingData *)sent)->allFinished = 1;
            }
            ((PokeathlonCourseCeremonyClosingData *)sent)->waiting = waiting;
        } else {
            if (allFinished) {
                ((PokeathlonCourseCeremonyOpeningData *)sent)->allFinished = 1;
            }
            ((PokeathlonCourseCeremonyOpeningData *)sent)->waiting = waiting;
        }
    }
    sync = (PokeathlonCourseCeremonySync *)PokeathlonCourse_ToBytes(copyArea);
    sync->messageCount = messageCount;
    sync->printing = PokeathlonCourseMessageBox_IsBusy(ceremony->messageBox);
    sync->finished = ceremony->finished;
    if (closing) {
        if (((PokeathlonCourseCeremonyClosingData *)received)->waiting != 0 && messageCount >= ((PokeathlonCourseCeremonyClosingData *)received)->messageCount) {
            return TRUE;
        }
    } else {
        if (((PokeathlonCourseCeremonyOpeningData *)received)->waiting != 0 && messageCount >= ((PokeathlonCourseCeremonyOpeningData *)received)->messageCount) {
            return TRUE;
        }
    }
    return FALSE;
}

static BOOL PokeathlonCourseCeremony_SyncOpening(PokeathlonCourseData *course) {
    return SyncMessages(course, FALSE);
}

static BOOL PokeathlonCourseCeremony_SyncClosing(PokeathlonCourseData *course) {
    return SyncMessages(course, TRUE);
}
