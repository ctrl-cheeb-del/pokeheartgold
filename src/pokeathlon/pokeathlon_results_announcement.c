#include "pokeathlon/pokeathlon_results_announcement.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_course_ui.h"

#include "bg_window.h"
#include "brightness.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "obj_pltt_transfer.h"
#include "player_data.h"
#include "pm_string.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sprite_resource.h"
#include "system.h"
#include "text.h"
#include "wireless_status_icon.h"

enum {
    SLIDE_IN,
    SLIDE_OUT,
};

enum {
    RANKING_STATE_SLIDE_IN_NEXT,
    RANKING_STATE_SLIDE_IN,
    RANKING_STATE_SLIDE_OUT,
    RANKING_STATE_WAIT,
};

enum PokeathlonResultsInitState {
    RESULTS_INIT_CREATE,
    RESULTS_INIT_CREATE_SCOREBOARD,
    RESULTS_INIT_LOAD_GRAPHICS,
    RESULTS_INIT_CHOOSE_COMMENT,
    RESULTS_INIT_FADE_IN,
    RESULTS_INIT_WAIT_FADE_IN,
};

enum PokeathlonResultsState {
    RESULTS_STATE_INTRO,
    RESULTS_STATE_RANKING,
    RESULTS_STATE_DIM,
    RESULTS_STATE_WAIT_DIM,
    RESULTS_STATE_SHOW_POINTS,
    RESULTS_STATE_WAIT_POINTS,
    RESULTS_STATE_COMMENT,
    RESULTS_STATE_FADE_OUT,
    RESULTS_STATE_WAIT_FADE_OUT,
};

static void PokeathlonResults_SetGfxBanks(void);
static void PokeathlonResults_InitBgs(BgConfig *bgConfig, enum HeapID heapId);
static void PokeathlonResults_LoadBgGfx(PokeathlonResultsAnnouncement *announcement);
static void PokeathlonResults_CreatePlates(PokeathlonResultsAnnouncementPlates **plates, enum HeapID heapId, BgConfig *bgConfig, PokeathlonCourseData *course);
static void PokeathlonResults_StartRanking(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonCourseData *course, u8 total, int unused);
static BOOL PokeathlonResults_UpdateRanking(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonCourseData *course);
static void PokeathlonResults_QueueSlide(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonResultsAnnouncementPlate *plate, int delay);
static void PokeathlonResults_SetIncomingSlide(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonResultsAnnouncementPlate *plate, int delay);
static void PokeathlonResults_ClearSlide(PokeathlonResultsAnnouncementSlide *slide);
static BOOL PokeathlonResults_HasMorePlates(PokeathlonResultsAnnouncementRanking *ranking);
static PokeathlonResultsAnnouncementPlate *PokeathlonResults_AddPlate(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonCourseData *course, int x, int y);
static void PokeathlonResults_RemoveSlide(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonResultsAnnouncementSlide *slide);
static PokeathlonResultsAnnouncementSlide *PokeathlonResults_GetLeavingSlide(PokeathlonResultsAnnouncementRanking *ranking);
static u32 PokeathlonResults_GetIntroMessage(PokeathlonCourseData *course);
static u32 PokeathlonResults_GetCommentMessage(PokeathlonCourseData *course);
static void PokeathlonResults_InitSprites(PokeathlonResultsAnnouncement *announcement);
static void PokeathlonResults_FreeSprites(PokeathlonResultsAnnouncement *announcement);
static void PokeathlonResults_LoadSpriteResources(PokeathlonResultsAnnouncement *announcement);
static void PokeathlonResults_CreateSprite(PokeathlonResultsAnnouncement *announcement);
static BOOL PokeathlonResults_WaitForPlayers(PokeathlonCourseData *course);

static const u8 sResultsAnnouncementBgLayers[6] = { GF_BG_LYR_MAIN_0, GF_BG_LYR_MAIN_1, GF_BG_LYR_SUB_0, GF_BG_LYR_SUB_1, GF_BG_LYR_SUB_2, GF_BG_LYR_SUB_3 };

static const u8 sResultsAnnouncementBgTypes[6] = { GF_BG_TYPE_TEXT, GF_BG_TYPE_TEXT, GF_BG_TYPE_TEXT, GF_BG_TYPE_TEXT, GF_BG_TYPE_256x16PLTT, GF_BG_TYPE_256x16PLTT };

static const WindowTemplate sResultsAnnouncementWindowTemplate = {
    .bgId = GF_BG_LYR_MAIN_1,
    .left = 8,
    .top = 1,
    .width = 16,
    .height = 2,
    .palette = 15,
    .baseTile = 1,
};

static const PokeathlonCourseSpritePoolTemplate sResultsAnnouncementSceneConfig = {
    .capacity = 24,
    .resourceCount = 3,
    .resCounts = { 3, 3, 3, 3 },
};

static const GraphicsModes sResultsAnnouncementGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_5,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const OamCharTransferParam sResultsAnnouncementOamCharTransferParam = {
    .maxTasks = 0,
    .sizeMain = 0x20000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_64K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_64K,
};

static const SpriteResourceCountsListUnion sResultsAnnouncementSpriteResourceCounts = { 0x3E9, 0x3E9, 0x3E9, 0x3E9, 0, 0 };

static const OamManagerParam sResultsAnnouncementOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 126,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 1,
    .numOBJsub = 126,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const GraphicsBanks sResultsAnnouncementGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_0123_H,
    .obj = GX_VRAM_OBJ_128_B,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

static const PokeathlonResultsAnnouncementBgTemplates sResultsAnnouncementBgTemplates = {
    .templates = {
                  {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
                  {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0800,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
                  {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
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
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0800,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
                  {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_256,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
                  {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_256,
            .screenBase = GX_BG_SCRBASE_0x1800,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
        },
                  },
};

// Title window of the Results Announcement.
void PokeathlonResults_InitWindow(Window *window, BgConfig *bgConfig, enum HeapID heapId) {
    GF_ASSERT(bgConfig != NULL);
    AddWindow(bgConfig, window, &sResultsAnnouncementWindowTemplate);
    BG_FillCharDataRange(bgConfig, GF_BG_LYR_MAIN_1, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, heapId);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BGEXT, (enum GFPalSlotOffset)0x4000, heapId);
}

// "Results Announcement"
void PokeathlonResults_PrintTitle(Window *window, enum HeapID heapId) {
    MsgData *msgData;
    MessageFormat *messageFormat;
    String *string;

    FillWindowPixelBuffer(window, 0);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, heapId);
    messageFormat = MessageFormat_New(heapId);
    string = ReadMsgData_ExpandPlaceholders(messageFormat, msgData, msg_0309_00303, heapId);
    AddTextPrinterParameterizedWithColor(window, 0, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    String_Delete(string);
    MessageFormat_Delete(messageFormat);
    DestroyMsgData(msgData);
    CopyWindowToVram(window);
}

BOOL PokeathlonResults_Init(PokeathlonCourseData *course) {
    PokeathlonResultsAnnouncement *announcement = PokeathlonCourse_GetWork(course);
    PokeathlonCourseSpritePoolTemplate sceneConfig;
    MtxFx22 affine;
    PokeathlonCourseScoreList *scoreList;
    int value;

    switch (PokeathlonCourse_GetEventInitState(course)) {
    case RESULTS_INIT_CREATE:
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_137, 0x40000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
        PokeathlonResults_SetGfxBanks();
        announcement = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonResultsAnnouncement));
        MI_CpuFill8(announcement, 0, sizeof(PokeathlonResultsAnnouncement));
        announcement->heapId = HEAP_ID_137;
        FontID_Alloc(4, HEAP_ID_137);
        announcement->bgConfig = BgConfig_Alloc(HEAP_ID_137);
        announcement->messageBox = PokeathlonCourseMessageBox_New(announcement->heapId);
        PokeathlonResults_CreatePlates(&announcement->ranking.plates, HEAP_ID_137, announcement->bgConfig, course);
        announcement->banner = PokeathlonEventBanner_New(PokeathlonCourse_GetCurrentEvent(course), announcement->heapId);
        PokeathlonResults_InitSprites(announcement);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RESULTS_INIT_CREATE_SCOREBOARD:
        sceneConfig = sResultsAnnouncementSceneConfig;
        announcement->scene = PokeathlonCourseSpritePool_New(announcement->heapId, &sceneConfig);
        PokeathlonCourseSpritePool_SetSurfaceCoords(announcement->scene, 0, 0, 0, FX32_CONST(300));
        scoreList = PokeathlonCourse_GetGraphicsSystem(course);
        value = PokeathlonCourseScoreList_GetCount(scoreList);
        PokeathlonResults_StartRanking(&announcement->ranking, course, value, PokeathlonCourseScoreList_GetField04(scoreList));
        announcement->scoreboard = PokeathlonResults_NewScoreboard(announcement->heapId, announcement->bgConfig, announcement->scene);
        PokeathlonResults_LoadScoreboardResources(announcement->scoreboard, 2);
        PokeathlonCourseSpritePool_TransferResources(announcement->scene);
        PokeathlonResults_InitScoreboard(announcement->scoreboard, course, 300);
        PokeathlonResults_LoadSpriteResources(announcement);
        PokeathlonResults_CreateSprite(announcement);
        PokeathlonCourse_LoadTrainerPic(announcement->sprites[0], PokeathlonCourse_GetTrainerPicFileId(2), 11, announcement->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RESULTS_INIT_LOAD_GRAPHICS:
        PokeathlonCourse_SetVBlankIntrCB(announcement->bgConfig);
        PokeathlonResults_InitBgs(announcement->bgConfig, announcement->heapId);
        PokeathlonEventBanner_AddWindows(announcement->banner, announcement->bgConfig);
        PokeathlonResults_LoadBgGfx(announcement);
        PokeathlonEventBanner_LoadGraphics(announcement->banner);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
        value = PokeathlonCourse_GetMode(course);
        PokeathlonCourseMessageBox_Init(announcement->messageBox, announcement->bgConfig, 5, value, PokeathlonCourse_GetSaveData(course));
        PokeathlonEventBanner_PrintTexts(announcement->banner);
        affine._00 = FX32_ONE;
        affine._01 = 0;
        affine._10 = 0;
        affine._11 = FX32_ONE;
        OS_WaitVBlankIntr();
        Bg_SetTextDimAndAffineParams(announcement->bgConfig, GF_BG_LYR_SUB_3, BG_POS_OP_ADD_X, 0, &affine, 128, 96);
        Bg_SetTextDimAndAffineParams(announcement->bgConfig, GF_BG_LYR_SUB_3, BG_POS_OP_SUB_Y, 16, &affine, 128, 96);
        Bg_SetTextDimAndAffineParams(announcement->bgConfig, GF_BG_LYR_SUB_2, BG_POS_OP_ADD_X, 0, &affine, 128, 96);
        Bg_SetTextDimAndAffineParams(announcement->bgConfig, GF_BG_LYR_SUB_2, BG_POS_OP_SUB_Y, 16, &affine, 128, 96);
        PokeathlonResults_InitWindow(&announcement->window, announcement->bgConfig, announcement->heapId);
        PokeathlonResults_PrintTitle(&announcement->window, announcement->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RESULTS_INIT_CHOOSE_COMMENT:
        if (PokeathlonCourse_GetNetId(course) == 0) {
            // the host picks the announcer's closing comment (one of 5) for everyone
            u8 *comment = PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT);
            *comment = MTRandom() % 5;
        }
        if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_LINK) {
            WirelessStatusIcon_CreateOnScreenIfConnected(1);
            WirelessStatusIcon_SetBackPriority();
            WirelessStatusIcon_Refresh();
        }
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RESULTS_INIT_FADE_IN:
        PlayBGM(SEQ_GS_PT_RESULT);
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, announcement->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RESULTS_INIT_WAIT_FADE_IN:
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

BOOL PokeathlonResults_Draw(PokeathlonCourseData *course) {
    PokeathlonResultsAnnouncement *announcement = PokeathlonCourse_GetWork(course);
    PokeathlonCourseSpritePool_Draw(announcement->scene);
    SpriteSystem_DrawSprites(announcement->spriteManager);
    PokeathlonResults_DrawPlates(announcement->ranking.plates);
    return TRUE;
}

BOOL PokeathlonResults_Exit(PokeathlonCourseData *course) {
    PokeathlonResultsAnnouncement *announcement = PokeathlonCourse_GetWork(course);
    int i;

    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    FontID_Release(4);
    G2_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD, 0);
    PokeathlonEventBanner_Free(announcement->banner);
    RemoveWindow(&announcement->window);
    PokeathlonCourseMessageBox_Free(announcement->messageBox);
    for (i = 0; i < 6; i++) {
        FreeBgTilemapBuffer(announcement->bgConfig, sResultsAnnouncementBgLayers[i]);
    }
    PokeathlonResults_FreeScoreboard(announcement->scoreboard);
    PokeathlonResults_FreePlates(announcement->ranking.plates);
    PokeathlonCourseSpritePool_Free(announcement->scene);
    PokeathlonResults_FreeSprites(announcement);
    Heap_Free(announcement->bgConfig);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    Heap_Destroy(HEAP_ID_137);
    WirelessStatusIcon_Destroy();
    return TRUE;
}

static void PokeathlonResults_SetGfxBanks(void) {
    GraphicsBanks banks = sResultsAnnouncementGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokeathlonResults_InitBgs(BgConfig *bgConfig, enum HeapID heapId) {
    GraphicsModes modes = sResultsAnnouncementGraphicsModes;
    PokeathlonResultsAnnouncementBgTemplates templates;
    int i;

    SetBothScreensModesAndDisable(&modes);
    templates = sResultsAnnouncementBgTemplates;
    for (i = 0; i < 6; i++) {
        InitBgFromTemplate(bgConfig, sResultsAnnouncementBgLayers[i], &templates.templates[i], sResultsAnnouncementBgTypes[i]);
        BgClearTilemapBufferAndCommit(bgConfig, sResultsAnnouncementBgLayers[i]);
        BG_ClearCharDataRange(sResultsAnnouncementBgLayers[i], 64, 0, heapId);
    }
}

static void PokeathlonResults_LoadBgGfx(PokeathlonResultsAnnouncement *announcement) {
    GfGfxLoader_LoadCharData(NARC_a_1_6_0, 3, announcement->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, announcement->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_0, 5, announcement->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, announcement->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_0, 3, announcement->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, announcement->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_0, 4, announcement->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, announcement->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_0, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, announcement->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_0, 2, announcement->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, announcement->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_0, 1, announcement->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, announcement->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_0, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, announcement->heapId);
}

// Byte 2 of the host's block: every player has seen the whole announcement.
static BOOL PokeathlonResults_AllPlayersFinished(PokeathlonCourseData *course) {
    return PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN)[2];
}

// State 0 of the screen: the announcer's lines, the ranking, the winner and the scoreboard.
BOOL PokeathlonResults_Run(PokeathlonCourseData *course, u8 *state) {
    BOOL waiting = FALSE;
    BOOL done;
    PokeathlonResultsAnnouncement *announcement = PokeathlonCourse_GetWork(course);
    MessageFormat *messageFormat;
    int msgId;
    PokeathlonCourseScore *ranked[POKEATHLON_PARTICIPANTS];
    int i;

    done = FALSE;
    IsFanfarePlaying();
    if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_LINK) {
        waiting = PokeathlonResults_WaitForPlayers(course);
    }
    PokeathlonCourseMessageBox_Update(announcement->messageBox);
    if (!(PokeathlonCourseMessageBox_IsBusy(announcement->messageBox) || waiting)) {
        messageFormat = PokeathlonCourseMessageBox_GetMsgFormat(announcement->messageBox);
        msgId = -1;
        switch (*state) {
        case RESULTS_STATE_INTRO:
            msgId = PokeathlonResults_GetIntroMessage(course);
            (*state)++;
            break;
        case RESULTS_STATE_RANKING:
            if (!PokeathlonResults_UpdateRanking(&announcement->ranking, course)) {
                break;
            }
            for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                ranked[i] = PokeathlonCourseScoreList_GetRanked(PokeathlonCourse_GetGraphicsSystem(course), i);
            }
            if (ranked[0]->rank == ranked[1]->rank) {
                msgId = msg_0309_00254; // "This... was a very close competition!"
            } else {
                PlayerProfile *profile = PokeathlonCourse_GetPlayerProfileFromData(course, ranked[0]->participant);
                BufferPlayersName(messageFormat, 0, profile);
                msgId = msg_0309_00253; // "Team {STRVAR_1}! Congratulations on First Place!"
            }
            (*state)++;
            break;
        case RESULTS_STATE_DIM:
            StartBrightnessTransition(16, -8, 0, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD), SCREEN_MASK_MAIN);
            UpdateMainScreenBrightnessSurface((GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD), (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD));
            reg_G2_BLDALPHA = 16;
            (*state)++;
            break;
        case RESULTS_STATE_WAIT_DIM:
            if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
                msgId = msg_0309_00255; // "This event's results will be determined by points!"
                (*state)++;
            }
            break;
        case RESULTS_STATE_SHOW_POINTS:
            for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                u32 field3D8 = PokeathlonCourse_GetCurrentEvent(course);
                int points = PokeathlonCourseScoreList_GetEventPoints(PokeathlonCourse_GetGraphicsSystem(course), field3D8, i);
                if (points > POKEATHLON_POINTS_MAX) {
                    points = POKEATHLON_POINTS_MAX;
                }
                PokeathlonResults_SetScore(announcement->scoreboard, points, (u8)i);
            }
            StartBrightnessTransition(16, 0, 16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG0 | GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ | GX_BLEND_PLANEMASK_BD), SCREEN_MASK_SUB);
            (*state)++;
            break;
        case RESULTS_STATE_WAIT_POINTS:
            if (IsBrightnessTransitionActive(SCREEN_MASK_SUB)) {
                (*state)++;
            }
            break;
        case RESULTS_STATE_COMMENT:
            msgId = PokeathlonResults_GetCommentMessage(course);
            announcement->finished = TRUE;
            (*state)++;
            break;
        case RESULTS_STATE_FADE_OUT:
            if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO || PokeathlonResults_AllPlayersFinished(course)) {
                BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_WHITE, 12, 1, announcement->heapId);
                GF_SndStartFadeOutBGM(0, 12);
                (*state)++;
            }
            break;
        case RESULTS_STATE_WAIT_FADE_OUT:
            if (IsPaletteFadeFinished()) {
                PokeathlonCourseMessageBox_Close(announcement->messageBox);
                done = TRUE;
            }
            break;
        }
        if (msgId != -1) {
            PokeathlonCourseMessageBox_Print(announcement->messageBox, msgId);
            announcement->messageCount++;
        }
    }
    return done;
}

static void PokeathlonResults_CreatePlates(PokeathlonResultsAnnouncementPlates **plates, enum HeapID heapId, BgConfig *bgConfig, PokeathlonCourseData *course) {
    *plates = PokeathlonResults_NewPlates(heapId, bgConfig, course);
}

static inline void PokeathlonResults_SetPlateTotal(PokeathlonResultsAnnouncementRanking *ranking, u32 total) {
    ranking->total = total;
}

// The plates come in from the last place up, the winner's a little later.
static void PokeathlonResults_StartRanking(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonCourseData *course, u8 total, int unused) {
    int delay;
    int i, x, y;

    PokeathlonResults_SetPlateTotal(ranking, total);
    PokeathlonResults_InitPlates(ranking->plates, unused);
    for (i = 0, x = 0, y = 0; i < 4; i++) {
        delay = x + 10;
        PokeathlonResultsAnnouncementPlate *plate = PokeathlonResults_AddPlate(ranking, course, 256, 156 - y);
        if (!PokeathlonResults_GetPlateRank(plate)) {
            delay += 10;
        }
        PokeathlonResults_QueueSlide(ranking, plate, delay);
        x += 10;
        y += 40;
    }
    if (total > 4) {
        PokeathlonResultsAnnouncementPlate *plate = PokeathlonResults_AddPlate(ranking, course, 256, 40);
        PokeathlonResults_SetIncomingSlide(ranking, plate, 0);
    }
    ranking->state = RANKING_STATE_SLIDE_IN;
}

static void PokeathlonResults_MoveSlide(PokeathlonResultsAnnouncementSlide *slide, int dx, int dy) {
    if (slide->active) {
        if (slide->delay == 0) {
            PokeathlonResults_MovePlate(slide->plate, dx, dy);
            if (!slide->started) {
                PokeathlonResults_GetPlateRank(slide->plate);
                PlaySE(SEQ_SE_GS_KEKKA);
                slide->started = TRUE;
            }
        } else {
            slide->delay--;
        }
    }
}

static void PokeathlonResults_MoveSlides(PokeathlonResultsAnnouncementRanking *ranking, int dx, int dy) {
    int i;
    PokeathlonResultsAnnouncementSlide *slide;

    i = 0;
    slide = ranking->slides;
    for (; i < 4; i++, slide++) {
        PokeathlonResults_MoveSlide(slide, dx, dy);
    }
}

// SLIDE_IN: in from the right (stops at x 0); SLIDE_OUT: out downwards.
static BOOL PokeathlonResults_IsSlideDone(PokeathlonResultsAnnouncementSlide *slide, int direction) {
    int x, y;
    BOOL ret = FALSE;
    PokeathlonResults_GetPlatePos(slide->plate, &x, &y);
    if (direction == SLIDE_IN) {
        if (x <= 0) {
            PokeathlonResults_SetPlatePos(slide->plate, 0, y);
            ret = TRUE;
        }
    } else if (direction == SLIDE_OUT) {
        if (y >= 192) {
            ret = TRUE;
        }
    }
    return ret;
}

static void PokeathlonResults_Wait(PokeathlonResultsAnnouncementRanking *ranking, int frames) {
    ranking->state = RANKING_STATE_WAIT;
    ranking->timer = frames;
}

static BOOL PokeathlonResults_UpdateRanking(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonCourseData *course) {
    u8 *state = &ranking->state;
    switch (*state) {
    case RANKING_STATE_SLIDE_IN_NEXT:
        PokeathlonResults_MoveSlide(&ranking->incoming, -80, 0);
        if (PokeathlonResults_IsSlideDone(&ranking->incoming, SLIDE_IN)) {
            PokeathlonResults_QueueSlide(ranking, ranking->incoming.plate, 0);
            PokeathlonResults_ClearSlide(&ranking->incoming);
            if (PokeathlonResults_HasMorePlates(ranking)) {
                PokeathlonResults_SetIncomingSlide(ranking, PokeathlonResults_AddPlate(ranking, course, 256, 40), 0);
            }
            PokeathlonResults_Wait(ranking, 10);
        }
        break;
    case RANKING_STATE_SLIDE_IN: {
        int i;
        PokeathlonResultsAnnouncementSlide *slide;
        PokeathlonResults_MoveSlides(ranking, -80, 0);
        for (i = 0, slide = ranking->slides; i < 4; i++, slide++) {
            if (!PokeathlonResults_IsSlideDone(slide, SLIDE_IN)) {
                break;
            }
            if (!ranking->fanfarePlayed && PokeathlonResults_GetPlateRank(slide->plate) == 0) {
                PlayFanfare(SEQ_ME_PT_RESULTG);
                ranking->fanfarePlayed = TRUE;
            }
        }
        if (i == 4) {
            PokeathlonResults_Wait(ranking, 10);
        }
        break;
    }
    case RANKING_STATE_SLIDE_OUT: {
        PokeathlonResultsAnnouncementSlide *slide;
        PokeathlonResults_MoveSlides(ranking, 0, 8);
        slide = PokeathlonResults_GetLeavingSlide(ranking);
        if (PokeathlonResults_IsSlideDone(slide, SLIDE_OUT)) {
            PokeathlonResults_RemoveSlide(ranking, slide);
            *state = RANKING_STATE_SLIDE_IN_NEXT;
        }
        break;
    }
    case RANKING_STATE_WAIT:
        if (ranking->timer-- <= 0) {
            if (PokeathlonResults_HasMorePlates(ranking)) {
                *state = RANKING_STATE_SLIDE_OUT;
            } else {
                return TRUE;
            }
        }
        break;
    }
    return FALSE;
}

static void PokeathlonResults_QueueSlide(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonResultsAnnouncementPlate *plate, int delay) {
    PokeathlonResultsAnnouncementSlide *slide = &ranking->slides[ranking->slide];
    GF_ASSERT(!slide->active);
    slide->active = TRUE;
    slide->plate = plate;
    slide->delay = delay;
    ranking->slide = (ranking->slide + 1) % 4;
    ranking->count++;
}

static void PokeathlonResults_SetIncomingSlide(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonResultsAnnouncementPlate *plate, int delay) {
    PokeathlonResultsAnnouncementSlide *slide = &ranking->incoming;
    GF_ASSERT(!slide->active);
    slide->active = TRUE;
    slide->plate = plate;
    slide->delay = delay;
}

static void PokeathlonResults_ClearSlide(PokeathlonResultsAnnouncementSlide *slide) {
    slide->active = FALSE;
    slide->plate = NULL;
    slide->delay = 0;
}

static BOOL PokeathlonResults_HasMorePlates(PokeathlonResultsAnnouncementRanking *ranking) {
    BOOL result = FALSE;
    if ((u32)ranking->total > (u32)ranking->count) {
        result = TRUE;
    }
    return result;
}

// The plates are created from the last place up.
static PokeathlonResultsAnnouncementPlate *PokeathlonResults_AddPlate(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonCourseData *course, int x, int y) {
    PokeathlonCourseScoreList *scoreList = PokeathlonCourse_GetGraphicsSystem(course);
    int last = PokeathlonCourseScoreList_GetCount(scoreList) - 1;
    PokeathlonCourseScore *score = PokeathlonCourseScoreList_GetRanked(scoreList, last - ranking->next);
    ranking->next++;
    return PokeathlonResults_ShowPlate(ranking->plates, x, y, score);
}

static void PokeathlonResults_RemoveSlide(PokeathlonResultsAnnouncementRanking *ranking, PokeathlonResultsAnnouncementSlide *slide) {
    PokeathlonResults_HidePlate(slide->plate);
    PokeathlonResults_ClearSlide(slide);
}

static PokeathlonResultsAnnouncementSlide *PokeathlonResults_GetLeavingSlide(PokeathlonResultsAnnouncementRanking *ranking) {
    return &ranking->slides[ranking->slide];
}

// "Results of the first event!?" etc.
static u32 PokeathlonResults_GetIntroMessage(PokeathlonCourseData *course) {
    u32 msgId = PokeathlonCourse_GetRound(course); // the round
    if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO) {
        msgId += msg_0309_00246;
    } else {
        msgId += msg_0309_00249;
    }
    return msgId;
}

// One of 5 comments per round, picked by the host.
static u32 PokeathlonResults_GetCommentMessage(PokeathlonCourseData *course) {
    u32 round = PokeathlonCourse_GetRound(course);
    u8 *comment = PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    u32 msgId;
    GF_ASSERT(*comment < 5);
    if (PokeathlonCourse_GetMode(course) == POKEATHLON_COURSE_MODE_SOLO) {
        msgId = msg_0309_00256 + round * 5 + *comment;
    } else {
        msgId = msg_0309_00271 + round * 5 + *comment;
    }
    return msgId;
}

static void PokeathlonResults_InitSprites(PokeathlonResultsAnnouncement *announcement) {
    SpriteResourceCountsListUnion counts = sResultsAnnouncementSpriteResourceCounts;
    OamManagerParam oamManagerParam = sResultsAnnouncementOamManagerParam;
    OamCharTransferParam oamTransferParam = sResultsAnnouncementOamCharTransferParam;
    oamTransferParam.maxTasks = 26;
    announcement->spriteSystem = SpriteSystem_Alloc(announcement->heapId);
    announcement->spriteManager = SpriteManager_New(announcement->spriteSystem);
    SpriteSystem_Init(announcement->spriteSystem, &oamManagerParam, &oamTransferParam, 32);
    SpriteSystem_InitSprites(announcement->spriteSystem, announcement->spriteManager, 2);
    SpriteSystem_InitManagerWithCapacities(announcement->spriteSystem, announcement->spriteManager, &counts);
}

static void PokeathlonResults_FreeSprites(PokeathlonResultsAnnouncement *announcement) {
    u8 i;
    for (i = 0; i < 2; i++) {
        ManagedSprite *sprite = announcement->sprites[i];
        if (sprite != NULL) {
            Sprite_DeleteAndFreeResources(sprite);
            announcement->sprites[i] = NULL;
        }
    }
    SpriteSystem_FreeResourcesAndManager(announcement->spriteSystem, announcement->spriteManager);
    SpriteSystem_Free(announcement->spriteSystem);
}

static void PokeathlonResults_LoadSpriteResources(PokeathlonResultsAnnouncement *announcement) {
    SpriteSystem *spriteSystem = announcement->spriteSystem;
    SpriteManager *spriteManager = announcement->spriteManager;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 9, TRUE, NNS_G2D_VRAM_TYPE_2DSUB, 1000);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 8, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 1000);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 10, TRUE, 1000);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_1_5_4, 11, TRUE, 1000);
}

static void PokeathlonResults_CreateSprite(PokeathlonResultsAnnouncement *announcement) {
    ManagedSpriteTemplate template = { 0 };
    template.resIdList[GF_GFX_RES_TYPE_CHAR] = 1000;
    template.resIdList[GF_GFX_RES_TYPE_PLTT] = 1000;
    template.resIdList[GF_GFX_RES_TYPE_CELL] = 1000;
    template.resIdList[GF_GFX_RES_TYPE_ANIM] = 1000;
    template.vram = NNS_G2D_VRAM_TYPE_2DSUB;
    template.bgPriority = 1;
    template.x = 224;
    template.y = 112;
    announcement->sprites[0] = SpriteSystem_NewSprite(announcement->spriteSystem, announcement->spriteManager, &template);
}

// Link play: every player sends how far it got; the host collects them. Returns TRUE while this player has to
// wait for the others.
static BOOL PokeathlonResults_WaitForPlayers(PokeathlonCourseData *course) {
    PokeathlonResultsAnnouncement *announcement = PokeathlonCourse_GetWork(course);
    u8 *data = PokeathlonCourse_GetDataCopyArea(course);
    u8 *out = PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_FRAME_OUT); // the host's block for the others
    u8 *host = PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_FRAME_IN);
    u8 self = PokeathlonCourse_GetNetId(course);
    u8 progress = announcement->messageCount;
    BOOL behind = FALSE;
    if (self == 0) {
        BOOL allFinished = TRUE;
        u8 *dst;
        u8 *src;
        u32 size;
        int i;
        int count;
        out[1] = progress;
        dst = PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_INPUTS);
        src = PokeathlonCourse_ToBytes(data);
        size = 0x24;
        while (size != 0) {
            *dst++ = *src++;
            size--;
        }
        i = 0;
        count = PokeathlonCourse_GetParticipantCount(course);
        if (count > 0) {
            u8 *block = data + POKEATHLON_COURSE_DATA_INPUTS;
            do {
                u8 *player = PokeathlonCourse_ToBytes(block);
                if (player[0] < progress || player[1] == TRUE) {
                    behind = TRUE;
                }
                if (!player[2]) {
                    allFinished = FALSE;
                }
                block += POKEATHLON_COURSE_DATA_SLOT_SIZE;
                i++;
            } while (i < PokeathlonCourse_GetParticipantCount(course));
        }
        if (allFinished) {
            out[2] = TRUE;
        }
        out[3] = behind;
    }
    out = PokeathlonCourse_ToBytes(data); // this player's block
    out[0] = progress;
    out[1] = PokeathlonCourseMessageBox_IsBusy(announcement->messageBox);
    out[2] = announcement->finished;
    if (host[3] != 0 && progress >= host[1]) {
        return TRUE;
    }
    return FALSE;
}
