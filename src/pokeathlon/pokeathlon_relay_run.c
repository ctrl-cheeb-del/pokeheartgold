#include "pokeathlon/pokeathlon_relay_run.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"

#include "assert.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "geometry_math.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "pm_string.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sound_playback_internal.h"
#include "sprite.h"
#include "string_util.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"

enum {
    RELAY_RUN_STATE_START,
    RELAY_RUN_STATE_PLAY,
    RELAY_RUN_STATE_SAVE_SCORES,
};

enum PokeathlonRelayRunStartState {
    RELAY_RUN_START_PLACE_OBSTACLES,
    RELAY_RUN_START_FADE_IN,
    RELAY_RUN_START_WAIT_FADE_IN,
};

enum PokeathlonRelayRunInitState {
    RELAY_RUN_INIT_CREATE,
    RELAY_RUN_INIT_CREATE_HUD,
    RELAY_RUN_INIT_CREATE_SPRITES,
    RELAY_RUN_INIT_LOAD_MONS,
    RELAY_RUN_INIT_PLACE_TEAMS,
    RELAY_RUN_INIT_CHOOSE_LAYOUT,
    RELAY_RUN_INIT_DONE,
};

f32 _fflt(int value);

static void PokeathlonRelayRun_SetGfxBanks(void);
static void PokeathlonRelayRun_InitBgs(BgConfig *bgConfig);
static void PokeathlonRelayRun_LoadBgGraphics(PokeathlonRelayRun *relayRun);
static void PokeathlonRelayRun_LoadSpriteGraphics(PokeathlonCourseSpritePool *spritePool);
static void PokeathlonRelayRun_CreateSprites(PokeathlonRelayRun *relayRun, PokeathlonCourseSpritePool *spritePool);
static void PokeathlonRelayRun_UpdateHost(PokeathlonCourseData *course);
static void PokeathlonRelayRun_PackPacket(PokeathlonRelayRun *relayRun, PokeathlonRelayRunPacket *packet);
static BOOL PokeathlonRelayRun_Update(PokeathlonCourseData *course);
static void PokeathlonRelayRun_DrawPacket(PokeathlonCourseData *course);
static BOOL PokeathlonRelayRun_IsTouchingRunner(PokeathlonRelayRun *relayRun, int teamId, int x, int y);
static BOOL PokeathlonRelayRun_IsTouchingSwapButton(PokeathlonRelayRun *relayRun, u32 x, u32 y);
static void PokeathlonRelayRun_MoveTeams(PokeathlonCourseData *course);
static void PokeathlonRelayRunTeam_UpdateStun(PokeathlonCourseData *course, PokeathlonRelayRun *relayRun, PokeathlonRelayRunTeam *team);
static void PokeathlonRelayRunTeam_DrawSwap(PokeathlonRelayRunHud *hud, PokeathlonRelayRunTeam *team, VecFx32 *ground, PokeathlonRelayRunPacket *packet, u8 teamId, u8 member, PokeathlonRelayRunTouch *touch, BOOL isHost, BOOL isOwn, BOOL isCpu);
static fx32 PokeathlonRelayRun_CalcCircleEntry(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c, fx32 r);
static void PokeathlonRelayRun_PlaceAboveMon(PokeathlonCoursePerformance *performance, const VecFx32 *position, PokeathlonCourseSpritePoolSprite *sprite);

static const WindowTemplate sRelayRunResultWindowTemplate = {
    .bgId = GF_BG_LYR_MAIN_3,
    .left = 0,
    .top = 20,
    .width = 32,
    .height = 2,
    .palette = 15,
    .baseTile = 1,
};

static const PokeathlonCourseSpritePoolTemplate sRelayRunSpritePoolTemplate = {
    .capacity = 139,
    .resourceCount = 4,
    .resCounts = { 4, 4, 4, 4 },
};

static const VecFx32 sRelayRunLapCounterPlatePos = { 0, FX32_CONST(96), 0 };

static const VecFx32 sRelayRunLapCounterFirstDigitPos = { 0, FX32_CONST(96), 0 };

static const VecFx32 sRelayRunLapCounterSecondDigitPos = { 0, FX32_CONST(96), 0 };

static const PokeathlonRelayRunHitTable sRelayRunEdgeHits = {
    .hits = { 2, 3, 4, 5 },
};

static const PokeathlonRelayRunHitTable sRelayRunCornerHits = {
    .hits = { 6, 7, 8, 9 },
};

static const GraphicsModes sRelayRunGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const BgTemplate sRelayRunBgTemplate_Main3 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd000,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRelayRunBgTemplate_Sub2 = {
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

static const BgTemplate sRelayRunBgTemplate_Main0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x1000,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_512x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRelayRunBgTemplate_Main2 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x1000,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_512x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRelayRunBgTemplate_Sub0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x0c000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRelayRunBgTemplate_Main1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sRelayRunBgTemplate_Sub1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const GraphicsBanks sRelayRunGraphicsBanks = {
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

#pragma push
#pragma opt_common_subs off

BOOL PokeathlonRelayRun_Init(PokeathlonCourseData *course) {
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case RELAY_RUN_INIT_CREATE: {
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_144, 0x68000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonRelayRun_SetGfxBanks();
        PokeathlonRelayRun *data = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonRelayRun));
        MI_CpuFill8(data, 0, sizeof(PokeathlonRelayRun));
        data->bgConfig = BgConfig_Alloc(HEAP_ID_144);
        PokeathlonCourse_SetEventDataTransfer(course, data->layoutToSend, data->layout, sizeof(data->layout));
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        ObjCharTransferTemplate charTransfer;
        charTransfer.maxTasks = 151;
        charTransfer.sizeMain = 0x40000;
        charTransfer.sizeSub = 0x4000;
        charTransfer.heapID = HEAP_ID_144;
        PokeathlonCourse_InitObjTransfer(&charTransfer, 22, HEAP_ID_144, GX_OBJVRAMMODE_CHAR_1D_256K, GX_OBJVRAMMODE_CHAR_1D_32K);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_144);
        data->heapId = HEAP_ID_144;
        FontID_Alloc(4, HEAP_ID_144);
        PokeathlonRelayRun_InitBgs(data->bgConfig);
        PokeathlonRelayRun_AddResultWindow(data);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case RELAY_RUN_INIT_CREATE_HUD: {
        relayRun->hud = PokeathlonRelayRunHud_New(relayRun->heapId, relayRun->bgConfig, course);
        int count = PokeathlonCourse_GetParticipantCount(course);
        int mode = PokeathlonCourse_GetMode(course);
        relayRun->cpu = PokeathlonRelayRunCpu_New(relayRun->heapId, POKEATHLON_PARTICIPANTS - count, mode);
        relayRun->monResources = PokeathlonCourseSprites_CreateResources(relayRun->heapId, 0x2BF, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case RELAY_RUN_INIT_CREATE_SPRITES: {
        PokeathlonCourseSpritePoolTemplate template = sRelayRunSpritePoolTemplate;
        relayRun->spritePool = PokeathlonCourseSpritePool_New(relayRun->heapId, &template);
        PokeathlonCourseSpritePool_SetSurfaceCoords(relayRun->spritePool, 0, 0, 0, FX32_CONST(512));
        relayRun->monObjects = PokeathlonCourseMonObjects_Create(relayRun->heapId, 12, 4, relayRun->monResources, PokeathlonCourseSpritePool_GetSpriteList(relayRun->spritePool));
        PokeathlonCourseSpritePool_SetResourceId(relayRun->spritePool, 0, 101);
        PokeathlonCourseSpritePool_SetResourceId(relayRun->spritePool, 1, 102);
        PokeathlonCourseSpritePool_SetResourceId(relayRun->spritePool, 2, 103);
        PokeathlonCourseSpritePool_SetResourceId(relayRun->spritePool, 3, 104);
        PokeathlonRelayRunHud_LoadSpriteGraphics(relayRun->hud, relayRun->spritePool);
        PokeathlonRelayRun_LoadSpriteGraphics(relayRun->spritePool);
        PokeathlonCourseSpritePool_TransferResources(relayRun->spritePool);
        Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSpritesInPool(course, 0, relayRun->monResources, relayRun->spritePool), 1);
        PokeathlonRelayRun_CreateSprites(relayRun, relayRun->spritePool);
        PokeathlonRelayRunHud_CreateSprites(relayRun->hud, relayRun->spritePool, relayRun->monResources);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case RELAY_RUN_INIT_LOAD_MONS: {
        PokeathlonCourseMonInfo infos[POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE];
        PokeathlonCoursePoint mons[POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE];
        PokeathlonCourseMonGfxTemplate template;
        int i;
        u8 own;
        for (i = 0; i < POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE; i++) {
            int member = i % POKEATHLON_TEAM_SIZE;
            int team = i / POKEATHLON_TEAM_SIZE;
            PokeathlonCourse_GetMonInfo(course, team, member, &infos[i]);
            template.sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, team, member));
            mons[i].x = infos[i].species;
            mons[i].y = infos[i].form;
        }
        PokeathlonRelayRunHud_LoadMonIcons(relayRun->hud, mons);
        own = PokeathlonCourse_GetNetId(course);
        PokeathlonRelayRunHud_LoadMonPics(relayRun->hud, &infos[own * POKEATHLON_TEAM_SIZE]);
        PokeathlonRelayRunHud_ShowMonPic(relayRun->hud, 0, 1);
        PokeathlonRelayRunHud_ShowMonPic(relayRun->hud, 1, 2);
        template.loadAtOnce = FALSE;
        template.priority = 2;
        template.vramTransfer = FALSE;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(relayRun->monObjects, POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE, infos, &template, 0, 0);
        PokeathlonRelayRunHud_SetDrawPriorities(relayRun->hud, PokeathlonCourse_GetNetId(course));
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case RELAY_RUN_INIT_PLACE_TEAMS: {
        int own;
        PokeathlonCourseCollision collisions[POKEATHLON_SIZE_CLASSES];
        PokeathlonCoursePoint ownPosition;
        int centerX, centerY;
        PokeathlonRelayRunSetup setup;
        PokeathlonRelayRunTeam *team;
        int teamIndex;
        int i, j;
        if (!PokeathlonCourseMonObjects_IsLoaded(relayRun->monObjects)) {
            break;
        }
        own = PokeathlonCourse_GetNetId(course);
        PokeathlonCourse_SetVBlankIntrCB(relayRun->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        ReadWholeNarcMemberByIdPair(collisions, NARC_a_1_7_0, 12);
        for (i = 0; i < POKEATHLON_PARTICIPANTS * POKEATHLON_TEAM_SIZE; i++) {
            PokeathlonCourseMonObject *object = PokeathlonCourseMonObjects_Get(relayRun->monObjects, i);
            int member = i % POKEATHLON_TEAM_SIZE;
            int teamId;
            int y;
            if (member == 0) {
                PokeathlonCourseMonObject_SetDrawFlag(object, TRUE);
            }
            {
                PokeathlonCourseCollision *collision = &collisions[PokeathlonCourse_GetCollisionSizeClass(PokeathlonCourse_GetPerformance(course, i / POKEATHLON_TEAM_SIZE, i % POKEATHLON_TEAM_SIZE))];
                PokeathlonCourseObject_SetCollision(object, collision[-1].offsetY, collision[-1].radius);
            }
            object = PokeathlonCourseMonObjects_Get(relayRun->monObjects, i);
            teamId = i / POKEATHLON_TEAM_SIZE;
            team = &relayRun->teams[teamId];
            team->monObjects[member] = object;
            y = (teamId + 1) * 27 + 40;
            team->animState = 4;
            PokeathlonCourseMonObject_SetAnimState(object, 4);
            PokeathlonCourseObject_SetGroundPosition(object, RELAY_RUN_RUNNER_X, y);
            PokeathlonCourseObject_SetTouchRadius(object, PokeathlonCourse_GetTouchRadius());
            team->position.x = 0;
            team->position.y = y << FX32_SHIFT;
            if (teamId == own && member == 0) {
                PokeathlonCourseObject_GroundToCenter(object, RELAY_RUN_RUNNER_X, y, &centerX, &centerY);
                ownPosition.x = centerX;
                ownPosition.y = centerY;
            }
        }
        for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
            PokeathlonRelayRunTeam *team = &relayRun->teams[i];
            PokeathlonRelayRunTeam_SetDrawPriority(team, team->position.y / FX32_ONE, i == PokeathlonCourse_GetNetId(course));
        }
        ReadWholeNarcMemberByIdPair(&setup, NARC_a_1_7_0, 2);
        relayRun->timer = RELAY_RUN_DURATION;
        PokeathlonRelayRunHud_SetTimer(relayRun->hud, relayRun->timer);
        for (teamIndex = 0; teamIndex < POKEATHLON_PARTICIPANTS; teamIndex++) {
            relayRun->dragging[teamIndex] = FALSE;
            for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                PokeathlonRelayRun_InitMember(course, &setup, teamIndex, j, &relayRun->teams[teamIndex]);
            }
            if (PokeathlonCourse_GetNetId(course) == 0) {
                PokeathlonRelayRunCpu_SetTeam(relayRun->cpu, teamIndex, &relayRun->teams[teamIndex]);
            }
            relayRun->teams[teamIndex].owner = teamIndex;
        }
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonRelayRun_PackPacket(relayRun, (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + offsetof(PokeathlonRelayRunLink, packetToSend)));
        }
        PokeathlonCourse_CreateStartSpritesInPool(course, 0, relayRun->monResources, relayRun->spritePool, NNS_G2D_VRAM_TYPE_2DMAIN, 1, &ownPosition);
        PokeathlonRelayRun_LoadBgGraphics(relayRun);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        WirelessStatusIcon_CreateOnScreenIfConnected(1);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case RELAY_RUN_INIT_CHOOSE_LAYOUT:
        if (PokeathlonCourse_GetNetId(course) == 0) {
            s32 *layout = relayRun->layoutToSend;
            u8 index = LCRandom() % 10;
            ReadWholeNarcMemberByIdPair(layout, NARC_a_2_2_7, index);
            PokeathlonRelayRunCpu_SetObstacles(relayRun->cpu, layout);
        }
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RELAY_RUN_INIT_DONE:
        GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));
        return TRUE;
    }
    return FALSE;
}

#pragma pop

BOOL PokeathlonRelayRun_Draw(PokeathlonCourseData *course) {
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    PokeathlonCourseSpritePool_Draw(relayRun->spritePool);
    return TRUE;
}

// Results: the laps each team ran, with tenths of a lap.

BOOL PokeathlonRelayRun_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        int distance = (u16)((int (*)(PokeathlonCourseData *, int))PokeathlonCourse_GetReceivedScore)(course, (u8)i);
        PokeathlonCourse_AddScoreEntry2(course, gfx, i, distance, (u32)distance >> 10, (distance % RELAY_RUN_TRACK_LENGTH) * 10 / RELAY_RUN_TRACK_LENGTH, 0, 1, 2, 1, msg_0309_00297);
    }
    PokeathlonCourseScoreList_Rank(gfx, 1);
    PokeathlonEvent_CalcPoints(gfx, 6);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 6);
    return TRUE;
}

BOOL PokeathlonRelayRun_Exit(PokeathlonCourseData *course) {
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    WirelessStatusIcon_Destroy();
    PokeathlonCourse_ClearEventDataTransfer(course);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(relayRun->bgConfig, GF_BG_LYR_SUB_2);
    RemoveWindow(&relayRun->window);
    Heap_Free(relayRun->bgConfig);
    PokeathlonCourseSpritePool_Free(relayRun->spritePool);
    PokeathlonCourseMonObjects_Free(relayRun->monObjects);
    PokeathlonCourseSprites_FreeResources(relayRun->monResources);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    PokeathlonRelayRunCpu_Delete(relayRun->cpu);
    PokeathlonRelayRunHud_Free(relayRun->hud);
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    reg_G2_BLDCNT = 0;
    Heap_Destroy(HEAP_ID_144);
    return TRUE;
}

static void PokeathlonRelayRun_SetGfxBanks(void) {
    GraphicsBanks banks = sRelayRunGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokeathlonRelayRun_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate main0, main1, main2, main3, sub0, sub1, sub2;
    modes = sRelayRunGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    main0 = sRelayRunBgTemplate_Main0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &main0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    main1 = sRelayRunBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    main2 = sRelayRunBgTemplate_Main2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &main2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    main3 = sRelayRunBgTemplate_Main3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main3, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    sub0 = sRelayRunBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &sub0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    sub1 = sRelayRunBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &sub1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    sub2 = sRelayRunBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &sub2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
}

static void PokeathlonRelayRun_LoadBgGraphics(PokeathlonRelayRun *relayRun) {
    GfGfxLoader_LoadCharData(NARC_a_1_7_8, 1, relayRun->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, relayRun->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_7_8, 2, relayRun->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, relayRun->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_7_8, 3, relayRun->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, relayRun->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_7_8, 4, relayRun->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, relayRun->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_7_8, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x40, relayRun->heapId);
    PokeathlonRelayRunHud_LoadBgGraphics(relayRun->hud);
}

static void PokeathlonRelayRun_LoadSpriteGraphics(PokeathlonCourseSpritePool *spritePool) {
    PokeathlonCourseSpritePool_LoadChar(spritePool, NARC_a_1_7_8, 17, 104, NNS_G2D_VRAM_TYPE_2DMAIN);
    PokeathlonCourseSpritePool_LoadPltt(spritePool, NARC_a_1_7_8, 14, 104, NNS_G2D_VRAM_TYPE_2DMAIN, 2);
    PokeathlonCourseSpritePool_LoadCell(spritePool, NARC_a_1_7_8, 16, 104);
    PokeathlonCourseSpritePool_LoadAnim(spritePool, NARC_a_1_7_8, 15, 104);
}

static void PokeathlonRelayRun_CreateSprites(PokeathlonRelayRun *relayRun, PokeathlonCourseSpritePool *spritePool) {
    int i;
    VecFx32 position;
    for (i = 0; i < RELAY_RUN_OBSTACLES; i++) {
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 6);
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 7);
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 9);
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 11);
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 13);
    }
    for (i = 0; i < 4; i++) {
        PokeathlonCourseSpritePool_CreateSprite(spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 14);
    }
    PokeathlonCourseSpritePool_CreateSprite(spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 12);
    PokeathlonCourseSpritePool_CreateSprite(spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 15);
    for (i = 0; i < RELAY_RUN_OBSTACLES; i++) {
        relayRun->obstacles[i].sprite = PokeathlonCourseSpritePool_Take(spritePool, 104, 6);
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        relayRun->teams[i].swapSprite = PokeathlonCourseSpritePool_Take(spritePool, 104, 7);
        relayRun->teams[i].conditionSprite = PokeathlonCourseSpritePool_Take(spritePool, 104, 9);
        relayRun->teams[i].speedSprite = PokeathlonCourseSpritePool_Take(spritePool, 104, 11);
        relayRun->teams[i].shadowSprite = PokeathlonCourseSpritePool_Take(spritePool, 104, 13);
        PokeathlonCourseSpritePoolSprite_SetAnim(relayRun->teams[i].swapSprite, 3);
        PokeathlonCourseSpritePoolSprite_SetAnim(relayRun->teams[i].shadowSprite, 8);
    }
    for (i = 0; i < 4; i++) {
        relayRun->bumpMarks[i] = PokeathlonCourseSpritePool_Take(spritePool, 104, 14);
    }
    relayRun->signSprite = PokeathlonCourseSpritePool_Take(spritePool, 104, 12);
    PokeathlonCourseSpritePoolSprite_SetAnim(relayRun->signSprite, 11);
    PokeathlonCourseSpritePoolSprite_Show(relayRun->signSprite, TRUE, TRUE);
    position.x = FX32_CONST(32);
    position.y = FX32_CONST(16);
    position.z = 0;
    PokeathlonCourseSpritePoolSprite_SetPosition(relayRun->signSprite, &position);
    relayRun->lapCounter.plate = PokeathlonCourseSpritePool_Take(spritePool, 104, 15);
    PokeathlonCourseSpritePoolSprite_SetAnim(relayRun->lapCounter.plate, 10);
    relayRun->lapCounter.digits[0] = PokeathlonCourseSprites_CreateLapCounterDigit(relayRun->monResources, PokeathlonCourseSpritePool_GetSpriteList(relayRun->spritePool), 0, relayRun->heapId);
    relayRun->lapCounter.digits[1] = PokeathlonCourseSprites_CreateLapCounterDigit(relayRun->monResources, PokeathlonCourseSpritePool_GetSpriteList(relayRun->spritePool), 0, relayRun->heapId);
}

// State 0: place the obstacles of the layout the host sent, then fade in.

BOOL PokeathlonRelayRun_Start(PokeathlonCourseData *course, u8 *state) {
    int i;
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    VecFx32 position;
    switch (*state) {
    case RELAY_RUN_START_PLACE_OBSTACLES:
        for (i = 0; i < RELAY_RUN_OBSTACLES; i++) {
            u8 kind = relayRun->layout[i];
            u8 y = relayRun->layout[i] >> 8;
            u16 x = relayRun->layout[i] >> 16;
            if (kind != 0) {
                relayRun->obstacles[i].active = TRUE;
                relayRun->obstacles[i].kind = kind;
                relayRun->obstacles[i].x = x;
                relayRun->obstacles[i].y = y;
                PokeathlonCourseSpritePoolSprite_SetAnim(relayRun->obstacles[i].sprite, kind - 1);
                PokeathlonCourseSpritePoolSprite_Show(relayRun->obstacles[i].sprite, TRUE, TRUE);
                position.z = 0;
                position.x = (x + RELAY_RUN_RUNNER_X) << FX32_SHIFT;
                position.y = (y + 32) << FX32_SHIFT;
                PokeathlonCourseSpritePoolSprite_SetPosition(relayRun->obstacles[i].sprite, &position);
                PokeathlonRelayRunObstacle_SetDrawPriority(&relayRun->obstacles[i]);
            }
        }
        PokeathlonRelayRun_ScrollObstacles(relayRun, 0);
        (*state)++;
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_RELAY_RUN);
        break;
    case RELAY_RUN_START_FADE_IN:
        BeginNormalPaletteFade(FADE_SUB_THEN_MAIN, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, relayRun->heapId);
        (*state)++;
        break;
    case RELAY_RUN_START_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            PokeathlonCourse_SetNextState(course, RELAY_RUN_STATE_PLAY);
        }
        break;
    }
    return FALSE;
}

// State 1: countdown, the race, then the finish.
BOOL PokeathlonRelayRun_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    switch (*state) {
    case EVENT_PLAY_STATE_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_RUN:
        PokeathlonRelayRun_UpdateHost(course);
        if (PokeathlonRelayRun_Update(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_FINISH:
        PokeathlonRelayRun_UpdateHost(course);
        if (PokeathlonCourse_RunFinish(course)) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, relayRun->heapId);
            PokeathlonCourse_SetNextState(course, RELAY_RUN_STATE_SAVE_SCORES);
        }
        break;
    }
    return FALSE;
}

// State 2: after the fade, the host stores each team's distance (laps << 10 | pixels into the lap) as its score.
BOOL PokeathlonRelayRun_SaveScores(PokeathlonCourseData *course, u8 *state) {
    int i;
    PokeathlonCourseData *savedCourse = course;
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    PokeathlonRelayRunTeam *team;

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return FALSE;
    }
    if (PokeathlonCourse_GetNetId(savedCourse)) {
        return TRUE;
    }
    for (i = 0, team = relayRun->teams; i < POKEATHLON_PARTICIPANTS; i++, team++) {
        PokeathlonCourse_SetEventScore(savedCourse, (u8)i, team->position.x / FX32_ONE + (team->laps << 10));
    }
    return TRUE;
}

static inline void PokeathlonRelayRun_ClearDrag(PokeathlonRelayRun *teamCursor, PokeathlonRelayRun *dragCursor) {
    dragCursor->dragging[0] = FALSE;
    teamCursor->teams[0].heldFrames = 0;
    teamCursor->teams[0].dragStart.x = 0;
    teamCursor->teams[0].dragStart.y = 0;
    teamCursor->teams[0].dragStart.z = 0;
    teamCursor->teams[0].dragEnd = teamCursor->teams[0].dragStart;
}

// Host, every frame: reads everyone's stylus and moves the teams. Touching the swap button (or dragging backwards)
// hands over to the next member; a short drag released flicks the runner forward, faster the longer the drag
// and the stronger the Pokemon, up to its top speed.

static void PokeathlonRelayRun_UpdateHost(PokeathlonCourseData *course) {
    int i;
    PokeathlonRelayRun *relayRun;
    u8 *link;
    BOOL clear;
    f32 acceleration, maxSpeed;
    PokeathlonRelayRun *pressCursor;
    PokeathlonRelayRun *teamCursor;
    PokeathlonRelayRun *dragCursor;
    u8 *cursor;
    PokeathlonRelayRunTeam *runner;
    VecFx32 *dragStart, *dragEnd, *velocity, *velocity2;

    struct {
        VecFx32 limitBase, base, flick, combined;
    } work;

    link = PokeathlonCourse_GetDataCopyArea(course);
    relayRun = PokeathlonCourse_GetWork(course);
    if (PokeathlonCourse_GetNetId(course)) {
        return;
    }
    if (relayRun->finished) {
        link += offsetof(PokeathlonRelayRunLink, packetToSend);
        PokeathlonRelayRun_PackPacket(relayRun, (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes(link));
        return;
    }
    {
        PokeathlonRelayRunTouch *hostTouch = (PokeathlonRelayRunTouch *)PokeathlonCourse_ToBytes(link + offsetof(PokeathlonRelayRunLink, touches)); // the host's own stylus is block 0
        *hostTouch = *(PokeathlonRelayRunTouch *)PokeathlonCourse_ToBytes(link);
    }
    if (relayRun->timer) {
        relayRun->timer--;
    }
    PokeathlonCourse_ToBytes(link + offsetof(PokeathlonRelayRunLink, packetToSend));
    i = 0;
    pressCursor = relayRun;
    teamCursor = relayRun;
    dragCursor = relayRun;
    cursor = link + offsetof(PokeathlonRelayRunLink, touches);
    runner = relayRun->teams;
    dragStart = &relayRun->teams[0].dragStart;
    dragEnd = &relayRun->teams[0].dragEnd;
    velocity = &relayRun->teams[0].velocity;
    velocity2 = &relayRun->teams[0].velocity;
    for (; i < POKEATHLON_PARTICIPANTS; pressCursor = (PokeathlonRelayRun *)((u8 *)pressCursor + sizeof(PokeathlonCourseTouch)), cursor += sizeof(PokeathlonRelayRunTouchBlock), teamCursor = (PokeathlonRelayRun *)((u8 *)teamCursor + sizeof(PokeathlonRelayRunTeam)), runner++, dragCursor = (PokeathlonRelayRun *)((u8 *)dragCursor + sizeof(BOOL)), dragStart = (VecFx32 *)((u8 *)dragStart + sizeof(PokeathlonRelayRunTeam)), dragEnd = (VecFx32 *)((u8 *)dragEnd + sizeof(PokeathlonRelayRunTeam)), velocity = (VecFx32 *)((u8 *)velocity + sizeof(PokeathlonRelayRunTeam)), velocity2 = (VecFx32 *)((u8 *)velocity2 + sizeof(PokeathlonRelayRunTeam)), i++) {
        PokeathlonRelayRunTouch *touch = (PokeathlonRelayRunTouch *)PokeathlonCourse_ToBytes(cursor);
        if (touch->held) {
            if (pressCursor->presses[0].pressed && pressCursor->presses[0].held) {
                pressCursor->presses[0].pressed = FALSE;
            } else if (!pressCursor->presses[0].pressed && !pressCursor->presses[0].held) {
                pressCursor->presses[0].pressed = TRUE;
                pressCursor->presses[0].held = TRUE;
            }
        } else {
            pressCursor->presses[0].pressed = FALSE;
            pressCursor->presses[0].held = FALSE;
        }
        PokeathlonRelayRun_UpdateSwapSign(relayRun, i, PokeathlonRelayRun_IsTouchingSwapButton(relayRun, touch->x, touch->y));
        if (teamCursor->teams[0].swapping) {
            if (teamCursor->teams[0].swapPhase == RELAY_RUN_SWAP_LEAVE && touch->displayPhase == RELAY_RUN_SWAP_LEAVE) {
                teamCursor->teams[0].current = (teamCursor->teams[0].current + 1) % POKEATHLON_TEAM_SIZE;
                teamCursor->teams[0].swapPhase = RELAY_RUN_SWAP_ARRIVE;
            } else if (teamCursor->teams[0].swapPhase == RELAY_RUN_SWAP_ARRIVE && touch->displayPhase == RELAY_RUN_SWAP_ARRIVE) {
                teamCursor->teams[0].swapPhase = RELAY_RUN_SWAP_DONE;
                teamCursor->teams[0].swapping = FALSE;
                teamCursor->teams[0].tired = FALSE;
            }
            PokeathlonRelayRun_ClearDrag(teamCursor, dragCursor);
            continue;
        }
        if (teamCursor->teams[0].members[teamCursor->teams[0].current].condition == RELAY_RUN_EXHAUSTED) {
            PokeathlonRelayRun_ClearDrag(teamCursor, dragCursor);
            continue;
        }
        if (teamCursor->teams[0].stunTimer) {
            PokeathlonRelayRun_ClearDrag(teamCursor, dragCursor);
            continue;
        }
        clear = FALSE;
        if (pressCursor->presses[0].pressed) {
            if (PokeathlonRelayRun_IsTouchingSwapButton(relayRun, touch->x, touch->y)) {
                teamCursor->teams[0].swapping = TRUE;
                teamCursor->teams[0].swapPhase = RELAY_RUN_SWAP_LEAVE;
                PokeathlonCourse_AddMonCounter(course, teamCursor->teams[0].owner, teamCursor->teams[0].current, POKEATHLON_COUNTER_SWITCHES, 1);
            } else if (PokeathlonRelayRun_IsTouchingRunner(relayRun, (u8)i, touch->x, touch->y)) {
                dragCursor->dragging[0] = TRUE;
                teamCursor->teams[0].dragStart.x = touch->x << FX32_SHIFT;
                teamCursor->teams[0].dragStart.y = touch->y << FX32_SHIFT;
                teamCursor->teams[0].dragStart.z = 0;
                teamCursor->teams[0].dragEnd = teamCursor->teams[0].dragStart;
            }
        } else if (pressCursor->presses[0].held) {
            if (teamCursor->teams[0].heldFrames < 255) {
                teamCursor->teams[0].heldFrames++;
            } else {
                relayRun->heldTooLong = TRUE;
            }
            if (!dragCursor->dragging[0]) {
                continue;
            }
            teamCursor->teams[0].dragEnd.x = touch->x << FX32_SHIFT;
            teamCursor->teams[0].dragEnd.y = touch->y << FX32_SHIFT;
        } else {
            if (dragCursor->dragging[0]) {
                if (teamCursor->teams[0].heldFrames <= 30) {
                    teamCursor->teams[0].flicked = TRUE;
                }
                dragCursor->dragging[0] = FALSE;
                relayRun->heldTooLong = FALSE;
            }
            clear = TRUE;
        }
        if (teamCursor->teams[0].flicked) {
            f32 weight, speed;
            fx32 scale;
            {
                fx32 *zero = (fx32 *)&work.base;
                *zero++ = 0;
                *zero++ = 0;
                *zero = 0;
            }
            acceleration = teamCursor->teams[0].members[teamCursor->teams[0].current].acceleration;
            weight = teamCursor->teams[0].members[teamCursor->teams[0].current].weight;
            maxSpeed = PokeathlonRelayRunTeam_GetMaxSpeed(runner, teamCursor->teams[0].current);
            scale = 4096.0 * ((double)(acceleration * weight) / 8.0);
            VEC_Subtract(dragEnd, dragStart, &work.flick);
            if (work.flick.x < 0) {
                if (work.flick.x < FX32_CONST(-16)) {
                    teamCursor->teams[0].swapping = TRUE;
                    teamCursor->teams[0].swapPhase = RELAY_RUN_SWAP_LEAVE;
                    PokeathlonCourse_AddMonCounter(course, teamCursor->teams[0].owner, teamCursor->teams[0].current, POKEATHLON_COUNTER_SWITCHES, 1);
                }
                work.flick.x = 0;
                work.flick.y = 0;
                work.flick.z = 0;
            }
            VEC_MultAdd(scale, &work.flick, &work.base, &work.flick);
            _fflt(VEC_Mag(&work.flick) / FX32_ONE);
            work.combined = teamCursor->teams[0].velocity;
            PokeathlonRelayRun_AddFlick(&work.combined, &work.flick, &work.combined);
            speed = VEC_Mag(&work.combined);
            if (speed > 4096.0f * maxSpeed) {
                {
                    fx32 *zero = (fx32 *)&work.limitBase;
                    *zero++ = 0;
                    *zero++ = 0;
                    *zero = 0;
                }
                VEC_Normalize(&work.combined, &work.combined);
                VEC_MultAdd(4096.0f * maxSpeed, &work.combined, &work.limitBase, velocity);
            } else {
                PokeathlonRelayRun_AddFlick(velocity2, &work.flick, velocity);
            }
            {
                fx32 magnitude = VEC_Mag(&runner->velocity);
                if (magnitude >= (runner->members[runner->current].speedLimit - 3) * FX32_ONE) {
                    PokeathlonCourse_AddMonCounter(course, runner->owner, runner->current, POKEATHLON_COUNTER_DASHES, 1);
                }
            }
            teamCursor->teams[0].flicked = FALSE;
        }
        if (clear) {
            teamCursor->teams[0].heldFrames = 0;
            teamCursor->teams[0].dragStart.x = 0;
            teamCursor->teams[0].dragStart.y = 0;
            teamCursor->teams[0].dragStart.z = 0;
            teamCursor->teams[0].dragEnd = teamCursor->teams[0].dragStart;
        }
    }
    PokeathlonRelayRunCpu_Update(course, relayRun->cpu, relayRun->timer);
    PokeathlonRelayRun_MoveTeams(course);
    if (relayRun->timer == 0) {
        relayRun->finished = TRUE;
    } else {
        relayRun->finished = FALSE;
    }
    link += offsetof(PokeathlonRelayRunLink, packetToSend);
    PokeathlonRelayRun_PackPacket(relayRun, (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes(link));
}

static void PokeathlonRelayRun_PackPacket(PokeathlonRelayRun *relayRun, PokeathlonRelayRunPacket *packet) {
    int i;
    int j;
    u32 flags;
    u8 swapPhases;
    u8 behindStart;
    swapPhases = 0;
    flags = 0;
    behindStart = 0;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonRelayRunTeam *team = &relayRun->teams[i];
        u8 runner = 0;
        int laps;
        runner += team->current;
        runner += team->speedGrade * 4;
        swapPhases += team->swapPhase << (i * 2);
        laps = team->swapping * 128;
        laps += team->laps;
        packet->y[i] = team->position.y / FX32_ONE;
        packet->x[i] = team->position.x / FX32_ONE;
        packet->runner[i] = runner;
        packet->laps[i] = laps;
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            flags += team->members[j].condition << ((j + i * POKEATHLON_TEAM_SIZE) * 2);
        }
        packet->swapSigns[i] = relayRun->swapSigns[i];
        behindStart += team->behindStart << i;
    }
    packet->swapPhases = swapPhases;
    packet->flags = flags;
    packet->flags += relayRun->finished << 24;
    packet->flags += relayRun->bumped << 25;
    packet->flags += behindStart << 26;
    packet->bumpX = relayRun->bumpX;
    packet->bumpY = relayRun->bumpY;
    packet->timer = relayRun->timer;
}

// Every player, every frame: sends the stylus to the host and draws the packet it received. TRUE once the
// host says the time is up (then stops the animations and, on the host, counts each member's distance).
static BOOL PokeathlonRelayRun_Update(PokeathlonCourseData *course) {
    PokeathlonRelayRun *relayRun;
    PokeathlonRelayRunPacket *packet;
    PokeathlonRelayRunTouch *touch;
    u8 j;
    u8 i;

    relayRun = PokeathlonCourse_GetWork(course);
    packet = (PokeathlonRelayRunPacket *)PokeathlonCourse_GetDataCopyArea(course);
    touch = (PokeathlonRelayRunTouch *)PokeathlonCourse_ToBytes(packet);
    touch->held = FALSE;
    packet = (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes((u8 *)packet + offsetof(PokeathlonRelayRunLink, packet));
    {
        u8 finished = (packet->flags >> 24) & 1;
        if (finished) {
            PokeathlonCourseSpritePoolSprite_Show(relayRun->lapCounter.plate, TRUE, FALSE);
            Sprite_SetDrawFlag(relayRun->lapCounter.digits[0], FALSE);
            Sprite_SetDrawFlag(relayRun->lapCounter.digits[1], FALSE);
            PokeathlonCourseSpritePool_PauseAnims(relayRun->spritePool, TRUE);
            PokeathlonCourseObjects_PauseAnims(relayRun->monObjects, TRUE);
            PokeathlonCourse_SetFinishCallback(course, PokeathlonRelayRun_SaveResult);
            if (!PokeathlonCourse_GetNetId(course)) {
                for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                    for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                        s32 distance = relayRun->teams[i].distance[j] / RELAY_RUN_TRACK_LENGTH;
                        PokeathlonCourse_AddMonCounter(course, i, j, POKEATHLON_COUNTER_POINTS, (u8)(distance / FX32_ONE));
                    }
                }
            }
            return TRUE;
        }
    }
    if (System_GetTouchNew()) {
        PokeathlonCourse_AddMonCounter(course, PokeathlonCourse_GetNetId(course), 3, POKEATHLON_COUNTER_INSTRUCTIONS, 1);
    }
    if (System_GetTouchHeld()) {
        touch->x = gSystem.touchX;
        touch->y = gSystem.touchY;
        touch->held = TRUE;
    }
    PokeathlonRelayRun_DrawPacket(course);
    return FALSE;
}

// Draws the packet from the host: the teams and the track scrolled to the player's own runner, the lap counter,
// the timer and the sign at the top of the screen.

static void PokeathlonRelayRun_DrawPacket(PokeathlonCourseData *course) {
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    u8 *link = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonRelayRunPacket *packet = (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes(link + offsetof(PokeathlonRelayRunLink, packet));
    u8 own = PokeathlonCourse_GetNetId(course);
    int i;
    u8 laps;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonRelayRunHud_SetMapPosition(relayRun->hud, i, packet->x[i]);
    }
    ScheduleSetBgPosText(relayRun->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, packet->x[own]);
    ScheduleSetBgPosText(relayRun->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, packet->x[own] / 2);
    ScheduleSetBgPosText(relayRun->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, packet->x[own] * 2);
    PokeathlonRelayRun_DrawTeams(course, own, relayRun->teams, (PokeathlonRelayRunLink *)link);
    PokeathlonRelayRun_ScrollObstacles(relayRun, packet->x[own]);
    laps = packet->laps[own] & 0x7F;
    PokeathlonRelayRunHud_PrintDistance(relayRun->hud, laps, (u8)(((u8)((packet->flags >> 26) & 0xF) >> own) & 1) ? 0 : packet->x[own]);
    if (!(u8)((packet->flags >> 24) & 1)) {
        PokeathlonRelayRun_UpdateLapCounter(&relayRun->lapCounter, laps);
    }
    PokeathlonRelayRunHud_SetTimer(relayRun->hud, packet->timer);
    switch (packet->swapSigns[own]) {
    case 0:
        relayRun->signSoundPlayed = FALSE;
        PokeathlonCourseSpritePoolSprite_TryChangeAnim(relayRun->signSprite, 11);
        break;
    case 3:
        relayRun->signSoundPlayed = FALSE;
        PokeathlonCourseSpritePoolSprite_TryChangeAnim(relayRun->signSprite, 13);
        break;
    case 2:
        if (!relayRun->signSoundPlayed) {
            relayRun->signSoundPlayed = TRUE;
            PlaySE(SEQ_SE_GS_CHANGE1);
        }
        PokeathlonCourseSpritePoolSprite_TryChangeAnim(relayRun->signSprite, 12);
        break;
    case 4:
        if (!relayRun->signSoundPlayed) {
            relayRun->signSoundPlayed = TRUE;
            PlaySE(SEQ_SE_GS_CHANGE2);
        }
        PokeathlonCourseSpritePoolSprite_TryChangeAnim(relayRun->signSprite, 14);
        break;
    case 1:
        relayRun->signSoundPlayed = FALSE;
        PokeathlonCourseSpritePoolSprite_TryChangeAnim(relayRun->signSprite, 15);
        break;
    }
    PokeathlonRelayRun_UpdateStartLine(relayRun->bgConfig, packet->x[own]);
    PokeathlonCourse_UpdateTimeUpCountdown(course, packet->timer);
}

static BOOL PokeathlonRelayRun_IsTouchingRunner(PokeathlonRelayRun *relayRun, int teamId, int x, int y) {
    s32 centerX;
    s32 centerY;
    PokeathlonRelayRunTeam *team = &relayRun->teams[teamId];
    PokeathlonCourseMonObject *object;
    GF_ASSERT(team->current < POKEATHLON_TEAM_SIZE);
    object = team->monObjects[team->current];
    PokeathlonCourseObject_GroundToCenter(object, RELAY_RUN_RUNNER_X, team->position.y / FX32_ONE, &centerX, &centerY);
    if (PokeathlonCourseObject_IsInTouchRange(object, centerX << FX32_SHIFT, centerY << FX32_SHIFT, x, y)) {
        return TRUE;
    }
    return FALSE;
}

// The swap button: the top-left 64x32 corner of the touch screen.
static BOOL PokeathlonRelayRun_IsTouchingSwapButton(PokeathlonRelayRun *relayRun, u32 x, u32 y) {
    if (x < 64 && y < 32) {
        return TRUE;
    }
    return FALSE;
}

// Host: moves every team by its velocity, bounces it off the walls and the obstacles, counts the laps, applies
// the friction, grades the speed and spends / restores the members' energy.

static void PokeathlonRelayRun_MoveTeams(PokeathlonCourseData *course) {
    VecFx32 bump;
    VecFx32 from;
    VecFx32 direction;
    u8 skip[POKEATHLON_PARTICIPANTS];
    PokeathlonRelayRun *relayRun;
    int i;
    int j;
    PokeathlonRelayRunTeam *team;
    int result;
    int hit;
    int x;
    fx32 speed;
    fx32 limit;
    fx32 friction;
    f32 coefficient;
    f32 energy;
    u8 speedLimit;
    relayRun = PokeathlonCourse_GetWork(course);
    relayRun->bumped = FALSE;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        skip[i] = FALSE;
        if (relayRun->teams[i].stunTimer) {
            PokeathlonRelayRunTeam_UpdateStun(course, relayRun, &relayRun->teams[i]);
            skip[i] = TRUE;
        }
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (skip[i]) {
            continue;
        }
        team = &relayRun->teams[i];
        from = team->position;
        VEC_Add(&team->position, &team->velocity, &team->position);
        team->distance[team->current] += team->velocity.x;
        if (team->position.y < FX32_CONST(32)) {
            team->position.y = FX32_CONST(32);
        } else if (team->position.y > FX32_CONST(168)) {
            team->position.y = FX32_CONST(168);
        }
        result = PokeathlonRelayRun_CollideWithObstacles(relayRun, team->wallState, PokeathlonCourseObject_GetCollisionRadius(team->monObjects[team->current]), &from, &team->position, &team->position);
        hit = (u8)(result >> 8);
        result = (u8)result;
        if (hit == 1) {
            team->onPatch = TRUE;
        } else {
            team->onPatch = FALSE;
        }
        team->wallState = result;
        switch (result) {
        case RELAY_RUN_HIT_TOP:
            if (team->velocity.y > 0) {
                team->velocity.y *= -1;
            }
            break;
        case RELAY_RUN_HIT_RIGHT:
            if (team->velocity.x < 0) {
                team->velocity.x *= -1;
            }
            break;
        case RELAY_RUN_HIT_BOTTOM:
            if (team->velocity.y < 0) {
                team->velocity.y *= -1;
            }
            break;
        case RELAY_RUN_HIT_LEFT:
            if (team->velocity.x > 0) {
                team->velocity.x *= -1;
            }
            break;
        case RELAY_RUN_HIT_TOP_LEFT:
            if (team->velocity.x > 0) {
                team->velocity.x *= -1;
            }
            if (team->velocity.y > 0) {
                team->velocity.y *= -1;
            }
            break;
        case RELAY_RUN_HIT_TOP_RIGHT:
            if (team->velocity.x < 0) {
                team->velocity.x *= -1;
            }
            if (team->velocity.y > 0) {
                team->velocity.y *= -1;
            }
            break;
        case RELAY_RUN_HIT_BOTTOM_RIGHT:
            if (team->velocity.x < 0) {
                team->velocity.x *= -1;
            }
            if (team->velocity.y < 0) {
                team->velocity.y *= -1;
            }
            break;
        case RELAY_RUN_HIT_BOTTOM_LEFT:
            if (team->velocity.x > 0) {
                team->velocity.x *= -1;
            }
            if (team->velocity.y < 0) {
                team->velocity.y *= -1;
            }
            break;
        }
        result = PokeathlonRelayRun_CollideRunners(course, relayRun->teams, &bump);
        if (!relayRun->bumped && result) {
            relayRun->bumped = TRUE;
            relayRun->bumpX = bump.x / FX32_ONE;
            relayRun->bumpY = bump.y / FX32_ONE;
        }
        x = team->position.x;
        // 4194304.0 = FX32_CONST(RELAY_RUN_TRACK_LENGTH): one lap
        if (x >= 4194304.0) {
            team->position.x = x - 4194304.0;
            if (!team->behindStart && team->laps < RELAY_RUN_MAX_LAPS) {
                team->laps++;
            }
            if (team->bestLaps < team->laps) {
                team->bestLaps = team->laps;
            }
            team->behindStart = FALSE;
        } else if (x < 0) {
            team->position.x = 4194304.0 + x;
            if (team->laps != 0) {
                team->laps--;
            } else if (team->laps == 0) {
                team->behindStart = TRUE;
            }
        }
        direction = team->velocity;
        speed = VEC_Mag(&direction);
        if (!team->swapping && team->onPatch) {
            limit = team->members[team->current].patchSpeed << FX32_SHIFT;
            if (speed > limit) {
                VecFx32 zero = { 0, 0, 0 };
                VecFx32 slowed;
                slowed = team->velocity;
                VEC_Normalize(&slowed, &slowed);
                VEC_MultAdd(limit, &slowed, &zero, &slowed);
                team->velocity = slowed;
                direction = team->velocity;
                speed = VEC_Mag(&direction);
            }
        }
        if (speed > 0) {
            coefficient = 1.0f;
            friction = 4096.0 * (0.4 * coefficient);
            if (relayRun->heldTooLong) {
                friction += FX32_CONST(3);
            }
            VEC_Normalize(&direction, &direction);
            direction.x = FX_Mul(direction.x, friction);
            direction.y = FX_Mul(direction.y, friction);
            limit = VEC_Mag(&direction);
            if (VEC_Mag(&team->velocity) >= limit) {
                VEC_Subtract(&team->velocity, &direction, &team->velocity);
            } else {
                team->velocity.x = 0;
                team->velocity.y = 0;
            }
        }
        speed = VEC_Mag(&team->velocity);
        speedLimit = team->members[team->current].speedLimit;
        if (speed >= (speedLimit - 1) << FX32_SHIFT) {
            team->speedGrade = RELAY_RUN_SPEED_TOP;
        } else if (speed >= (speedLimit - 3) << FX32_SHIFT) {
            team->speedGrade = RELAY_RUN_SPEED_FAST;
        } else if (speed == 0) {
            team->speedGrade = RELAY_RUN_SPEED_STANDING;
        } else {
            team->speedGrade = RELAY_RUN_SPEED_SLOW;
        }
        if (team->swapping) {
            continue;
        }
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            energy = team->members[j].energy;
            if (j == team->current) {
                if (team->members[j].condition != RELAY_RUN_EXHAUSTED) {
                    switch (team->speedGrade) {
                    case RELAY_RUN_SPEED_STANDING:
                        energy += 0.5;
                        break;
                    case RELAY_RUN_SPEED_SLOW:
                    case RELAY_RUN_SPEED_FAST:
                    case RELAY_RUN_SPEED_TOP:
                        energy = energy - 0.5;
                        break;
                    }
                    if (team->tired) {
                        if (energy > 40.0) {
                            energy = 40.0f;
                        }
                    } else if (energy > team->members[j].maxEnergy) {
                        energy = team->members[j].maxEnergy;
                    }
                } else if (team->members[j].condition == RELAY_RUN_EXHAUSTED) {
                    team->recoveryTimer--;
                    if (team->recoveryTimer == 0) {
                        team->members[j].condition = RELAY_RUN_TIRED;
                        energy = 40.0f;
                    }
                }
            } else {
                energy += 0.5;
                if (energy > team->members[j].maxEnergy) {
                    energy = team->members[j].maxEnergy;
                }
            }
            if (energy <= 0.0f) {
                GF_ASSERT(j == team->current);
                team->members[j].energy = 0.0f;
                if (team->members[j].condition != RELAY_RUN_EXHAUSTED) {
                    team->members[j].condition = RELAY_RUN_EXHAUSTED;
                    team->tired = TRUE;
                    team->recoveryTimer = team->members[j].recoveryTime;
                    PokeathlonCourse_AddMonCounter(course, team->owner, team->current, POKEATHLON_COUNTER_FAILURES, 1);
                }
            } else if (energy <= 40.0) {
                team->members[j].energy = energy;
                team->members[j].condition = RELAY_RUN_TIRED;
            } else {
                team->members[j].energy = energy;
                team->members[j].condition = RELAY_RUN_FINE;
            }
        }
    }
}

static void PokeathlonRelayRunTeam_UpdateStun(PokeathlonCourseData *course, PokeathlonRelayRun *relayRun, PokeathlonRelayRunTeam *team) {
    if (team->stunTimer != 0) {
        team->stunTimer--;
    }
}

// Draws every team from the packet the host sent, scrolled so the player's own runner (team own) stands at
// RELAY_RUN_RUNNER_X: positions, member swaps, dash lines, tired / exhausted marks and the bump mark.
void PokeathlonRelayRun_DrawTeams(PokeathlonCourseData *course, int own, PokeathlonRelayRunTeam *team, PokeathlonRelayRunLink *link) {
    int x;
    int dx;
    int screenX;
    PokeathlonRelayRun *relayRun;
    PokeathlonRelayRunPacket *packet;
    PokeathlonCourseMonObject *monObject;
    u8 swapping;
    u8 speedGrade;
    int condition;
    u8 runner;
    u8 member;
    int i;
    BOOL isHost;
    BOOL isOwn;
    int bumpX;
    u32 teamX;
    PokeathlonRelayRunTouch *touch;
    BOOL isCpu;
    BOOL running;
    BOOL exhausted;
    u8 bench0;
    u8 bench1;
    s32 flags;

    packet = (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes(&link->packet);
    relayRun = PokeathlonCourse_GetWork(course);
    x = packet->x[own];
    {
        VecFx32 position = { 0, 0, 0 };
        if ((u8)((packet->flags >> 25) & 1)) {
            bumpX = x - packet->bumpX;
            if (bumpX >= 768.0) {
                bumpX = 80.0 + (1024.0 - bumpX);
            } else {
                bumpX = RELAY_RUN_RUNNER_X - bumpX;
            }
            position.x = bumpX << FX32_SHIFT;
            position.y = packet->bumpY << FX32_SHIFT;
            PokeathlonCourseSpritePoolSprite_SetPosition(relayRun->bumpMarks[relayRun->nextBumpMark], &position);
            PokeathlonCourseSpritePoolSprite_Show(relayRun->bumpMarks[relayRun->nextBumpMark], TRUE, TRUE);
            PokeathlonCourseSpritePoolSprite_SetAnim(relayRun->bumpMarks[relayRun->nextBumpMark], 9);
            relayRun->nextBumpMark = (relayRun->nextBumpMark + 1) % 4;
            if (bumpX >= 0 && bumpX < 256) {
                PlaySEOnPlayer(SEQ_SE_GS_THLON06, PLAYER_SE_3);
            }
        }
    }
    isHost = own == 0;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        VecFx32 position;
        VecFx32 above;

        isOwn = own == i;
        runner = packet->runner[i];
        member = runner & 3;
        teamX = packet->x[i];
        dx = (int)teamX - x;
        // the track wraps: a runner just past the start line is just ahead of one about to cross it
        if (x > 724.0) {
            if (teamX < 300) {
                dx = (1024.0 - x) + teamX;
            }
        } else if (x < 100 && teamX > 924.0) {
            dx = 0.0 - (x + (1024.0 - teamX));
        }
        screenX = dx + RELAY_RUN_RUNNER_X;
        swapping = (packet->laps[i] >> 7) & 1;
        condition = (packet->flags >> ((u8)((u32)member + i * POKEATHLON_TEAM_SIZE) * 2)) & 3;
        speedGrade = (runner >> 2) & 3;
        monObject = team->monObjects[member];
        position.x = screenX << FX32_SHIFT;
        position.y = packet->y[i] << FX32_SHIFT;
        position.z = 0;
        if (PokeathlonCourse_GetParticipantCount(course) <= i) {
            isCpu = TRUE;
            touch = (PokeathlonRelayRunTouch *)PokeathlonCourse_ToBytes(&link->touches[i]);
        } else {
            isCpu = FALSE;
            touch = (PokeathlonRelayRunTouch *)PokeathlonCourse_ToBytes(link);
        }
        if (own == i) {
            PokeathlonRelayRunTeam_DrawSwap(relayRun->hud, team, &position, packet, i, (u8)member, touch, isHost, TRUE, FALSE);
        } else {
            PokeathlonRelayRunTeam_DrawSwap(relayRun->hud, team, &position, packet, i, (u8)member, touch, isHost, FALSE, isCpu);
        }
        PokeathlonRelayRunHud_UpdateTeam(relayRun->hud, i, (u8)member, swapping, condition);
        if (!team->runnerHidden && screenX >= -32 && screenX <= 288) {
            PokeathlonCourseMonObject_SetDrawFlag(monObject, TRUE);
        } else {
            PokeathlonCourseMonObject_SetDrawFlag(monObject, FALSE);
        }
        for (int j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            PokeathlonCourseObject_SetGroundPosition(team->monObjects[j], screenX, packet->y[i]);
        }
        PokeathlonRelayRunTeam_SetDrawPriority(team, packet->y[i], i == PokeathlonCourse_GetNetId(course));
        PokeathlonRelayRun_PlaceAboveMon(PokeathlonCourse_GetPerformance(course, i, member), &position, team->conditionSprite);
        above = position;
        above.y -= FX32_CONST(24);
        PokeathlonCourseSpritePoolSprite_SetPosition(team->speedSprite, &above);
        if (!swapping) {
            running = FALSE;
            exhausted = FALSE;
            switch (speedGrade) {
            case RELAY_RUN_SPEED_FAST:
                if (speedGrade != team->lastSpeedGrade) {
                    PokeathlonCourseSpritePoolSprite_Show(team->speedSprite, TRUE, TRUE);
                    PokeathlonCourseSpritePoolSprite_SetAnim(team->speedSprite, 4);
                }
                PokeathlonCourseMonObject_SetAnim(monObject, 8);
                running = TRUE;
                if (team->speedSoundGrade <= RELAY_RUN_SPEED_SLOW && !team->speedSoundPlayed) {
                    PokeathlonRelayRun_PlaySEIfOnScreen(screenX, SEQ_SE_GS_FW015_2, isOwn);
                    team->speedSoundGrade = RELAY_RUN_SPEED_FAST;
                    team->speedSoundPlayed = TRUE;
                }
                break;
            case RELAY_RUN_SPEED_TOP:
                if (speedGrade != team->lastSpeedGrade) {
                    PokeathlonCourseSpritePoolSprite_Show(team->speedSprite, TRUE, TRUE);
                    PokeathlonCourseSpritePoolSprite_SetAnim(team->speedSprite, 5);
                }
                PokeathlonCourseMonObject_SetAnim(monObject, 8);
                running = TRUE;
                if (team->speedSoundGrade <= RELAY_RUN_SPEED_SLOW && !team->speedSoundPlayed) {
                    PokeathlonRelayRun_PlaySEIfOnScreen(screenX, SEQ_SE_GS_FW015_2, isOwn);
                    team->speedSoundGrade = RELAY_RUN_SPEED_TOP;
                    team->speedSoundPlayed = TRUE;
                }
                break;
            default:
                PokeathlonCourseSpritePoolSprite_Show(team->speedSprite, TRUE, FALSE);
                team->speedSoundGrade = speedGrade;
                team->speedSoundPlayed = FALSE;
                break;
            }
            switch (condition) {
            case RELAY_RUN_TIRED:
                PokeathlonCourseSpritePoolSprite_Show(team->conditionSprite, TRUE, TRUE);
                PokeathlonCourseSpritePoolSprite_TryChangeAnim(team->conditionSprite, 6);
                break;
            case RELAY_RUN_EXHAUSTED:
                if (condition != team->lastCondition) {
                    PokeathlonCourseSpritePoolSprite_Show(team->conditionSprite, TRUE, TRUE);
                    PokeathlonCourseSpritePoolSprite_SetAnim(team->conditionSprite, 7);
                }
                PokeathlonCourseMonObject_SetAnim(monObject, 21);
                exhausted = TRUE;
                if (isOwn) {
                    if (!GF_SndCountPlayingSeqOnPlayer(PLAYER_SE_1)) {
                        PokeathlonRelayRun_PlaySEIfOnScreen(screenX, SEQ_SE_GS_W146, isOwn);
                    }
                } else {
                    if (!GF_SndCountPlayingSeqOnPlayer(PLAYER_SE_2)) {
                        PokeathlonRelayRun_PlaySEIfOnScreen(screenX, SEQ_SE_GS_W146, isOwn);
                    }
                }
                break;
            default:
                PokeathlonCourseSpritePoolSprite_Show(team->conditionSprite, TRUE, FALSE);
                break;
            }
            if (!running && !exhausted) {
                PokeathlonCourseMonObject_SetAnim(monObject, 0);
            }
        } else {
            PokeathlonCourseSpritePoolSprite_Show(team->speedSprite, TRUE, FALSE);
            PokeathlonCourseSpritePoolSprite_Show(team->conditionSprite, TRUE, FALSE);
        }
        team->lastSpeedGrade = speedGrade;
        team->lastCondition = condition;
        team++;
    }
    bench0 = PokeathlonRelayRunHud_GetBenchMember(relayRun->hud, 0);
    bench1 = PokeathlonRelayRunHud_GetBenchMember(relayRun->hud, 1);
    flags = packet->flags;
    PokeathlonRelayRunHud_ShowTiredMarks(relayRun->hud, (flags >> ((u8)(bench0 + own * POKEATHLON_TEAM_SIZE) * 2)) & 3, (flags >> ((u8)(bench1 + own * POKEATHLON_TEAM_SIZE) * 2)) & 3);
}

// Places the obstacle sprites for the track scrolled to x (the player's own runner).
void PokeathlonRelayRun_ScrollObstacles(PokeathlonRelayRun *relayRun, int x) {
    u8 i;

    for (i = 0; i < RELAY_RUN_OBSTACLES; i++) {
        PokeathlonRelayRun *shifted = (PokeathlonRelayRun *)((u8 *)relayRun + i * sizeof(PokeathlonRelayRunObstacle));
        VecFx32 position;
        int screenX;
        u8 y;

        if (!shifted->obstacles[0].active) {
            break;
        }
        y = shifted->obstacles[0].y;
        screenX = x - shifted->obstacles[0].x;
        if ((double)screenX >= 768.0) {
            screenX = 80.0 + (1024.0 - (double)screenX);
        } else if ((double)screenX <= -768.0) {
            screenX = 80.0 - (1024.0 + (double)screenX);
        } else {
            screenX = RELAY_RUN_RUNNER_X - screenX;
        }
        position.z = 0;
        position.x = screenX << FX32_SHIFT;
        position.y = (y + 32) << FX32_SHIFT;
        PokeathlonCourseSpritePoolSprite_SetPosition(shifted->obstacles[0].sprite, &position);
        if (screenX >= -32 && screenX <= 288) {
            PokeathlonCourseSpritePoolSprite_Show(shifted->obstacles[0].sprite, TRUE, TRUE);
        } else {
            PokeathlonCourseSpritePoolSprite_Show(shifted->obstacles[0].sprite, TRUE, FALSE);
        }
    }
}

// Member swap, first half: the runner leaves (the swap sprite flies up 20 px a frame), then the next member is waited for:
// the player's own team waits for the touch screen to bring up its picture, the host waits a while for the
// teams without a player. Then the swap reaches phase 1 on this screen.
static void PokeathlonRelayRunTeam_AnimateLeave(PokeathlonRelayRunHud *hud, PokeathlonRelayRunTeam *team, VecFx32 *position, u8 teamId, u8 member, PokeathlonRelayRunTouch *touch, BOOL isHostForCpu, BOOL isOwn) {
    VecFx32 swapPosition;

    switch (team->swapStep) {
    case 0:
        PokeathlonCourseSpritePoolSprite_SetPosition(team->swapSprite, position);
        PokeathlonCourseSpritePoolSprite_SetPosition(team->shadowSprite, position);
        PokeathlonCourseSpritePoolSprite_Show(team->shadowSprite, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_SetAnim(team->shadowSprite, 8);
        PokeathlonCourseSpritePoolSprite_Show(team->swapSprite, TRUE, TRUE);
        PokeathlonCourseMonObject_SetDrawFlag(team->monObjects[member], FALSE);
        team->runnerHidden = TRUE;
        team->swapTimer = 0;
        PokeathlonRelayRun_PlaySEIfOnScreen(position->x / FX32_ONE, SEQ_SE_GS_W100, isOwn);
        team->swapStep++;
        break;
    case 1:
        swapPosition = *PokeathlonCourseSpritePoolSprite_GetPosition(team->swapSprite);
        swapPosition.y -= FX32_CONST(20);
        swapPosition.x = position->x;
        PokeathlonCourseSpritePoolSprite_SetPosition(team->swapSprite, &swapPosition);
        PokeathlonCourseSpritePoolSprite_SetPosition(team->shadowSprite, position);
        team->swapTimer++;
        if (team->swapTimer >= 20) {
            team->swapStep++;
        }
        break;
    case 2:
        if (isOwn) {
            if (PokeathlonRelayRunHud_RotateMonPics(hud, member)) {
                touch->displayPhase = RELAY_RUN_SWAP_LEAVE;
                team->swapStep++;
            }
        } else if (isHostForCpu) {
            if (PokeathlonRelayRunHud_RotateCpuMonPics(hud, teamId)) {
                touch->displayPhase = RELAY_RUN_SWAP_LEAVE;
                team->swapStep++;
            }
        } else {
            team->swapStep++;
        }
        break;
    case 3:
        break;
    }
}

// Member swap, second half: the swap sprite drops 400 px onto the track and the next member appears; the swap
// reaches phase 2 on this screen.
static void PokeathlonRelayRunTeam_AnimateArrive(PokeathlonRelayRunTeam *team, VecFx32 *position, u8 unused, u8 member, PokeathlonRelayRunTouch *touch, BOOL reportPhase, BOOL isOwn) {
    switch (team->swapStep) {
    case 0: {
        VecFx32 swapPosition;
        swapPosition = *position;
        swapPosition.y -= FX32_CONST(400);
        PokeathlonCourseSpritePoolSprite_SetPosition(team->swapSprite, &swapPosition);
        PokeathlonCourseSpritePoolSprite_Show(team->swapSprite, TRUE, TRUE);
        PokeathlonCourseMonObject_SetDrawFlag(team->monObjects[member], FALSE);
        team->swapTimer = 0;
        PokeathlonRelayRun_PlaySEIfOnScreen(position->x / FX32_ONE, SEQ_SE_GS_NAGERU, isOwn);
        team->swapStep++;
        break;
    }
    case 1: {
        VecFx32 swapPosition;
        swapPosition = *PokeathlonCourseSpritePoolSprite_GetPosition(team->swapSprite);
        swapPosition.y += FX32_CONST(20);
        swapPosition.x = position->x;
        PokeathlonCourseSpritePoolSprite_SetPosition(team->swapSprite, &swapPosition);
        team->swapTimer++;
        if (team->swapTimer >= 20) {
            PokeathlonCourseSpritePoolSprite_SetPosition(team->shadowSprite, position);
            team->swapStep++;
        }
        break;
    }
    case 2:
        if (reportPhase) {
            touch->displayPhase = RELAY_RUN_SWAP_ARRIVE;
        }
        PokeathlonCourseSpritePoolSprite_SetPosition(team->swapSprite, position);
        PokeathlonCourseSpritePoolSprite_SetPosition(team->shadowSprite, position);
        team->swapStep++;
        // fallthrough
    case 3:
        PokeathlonCourseSpritePoolSprite_SetPosition(team->swapSprite, position);
        PokeathlonCourseSpritePoolSprite_SetPosition(team->shadowSprite, position);
        break;
    }
}

// The swap is over: the new member runs.
static void PokeathlonRelayRunTeam_EndSwap(PokeathlonRelayRunTeam *team, u8 unused, u8 member, PokeathlonRelayRunTouch *touch, BOOL reportPhase, BOOL isOwn) {
    VecFx32 position;
    PokeathlonCourseMonObject_SetDrawFlag(team->monObjects[member], TRUE);
    team->runnerHidden = FALSE;
    PokeathlonCourseSpritePoolSprite_Show(team->shadowSprite, TRUE, TRUE);
    PokeathlonCourseSpritePoolSprite_SetAnim(team->shadowSprite, 8);
    PokeathlonCourseSpritePoolSprite_Show(team->swapSprite, TRUE, FALSE);
    if (reportPhase) {
        touch->displayPhase = RELAY_RUN_SWAP_DONE;
    }
    position = *PokeathlonCourseSpritePoolSprite_GetPosition(team->shadowSprite);
    PokeathlonRelayRun_PlaySEIfOnScreen(position.x / FX32_ONE, SEQ_SE_GS_BOWA2, isOwn);
}

// Plays the member swap of a team as far as the host's packet says it has got (2 bits of swapPhases each).

static void PokeathlonRelayRunTeam_DrawSwap(PokeathlonRelayRunHud *hud, PokeathlonRelayRunTeam *team, VecFx32 *ground, PokeathlonRelayRunPacket *packet, u8 teamId, u8 member, PokeathlonRelayRunTouch *touch, BOOL isHost, BOOL isOwn, BOOL isCpu) {
    u16 changed = FALSE;
    u8 phase = (packet->swapPhases >> (teamId * 2)) & 3;
    s32 x, y;
    VecFx32 position;
    BOOL reportPhase;

    if (team->shownSwapPhase != phase) {
        team->shownSwapPhase = phase;
        team->swapStep = 0;
        changed = TRUE;
    }
    PokeathlonCourseObject_GroundToCenter(team->monObjects[member], ground->x / FX32_ONE, ground->y / FX32_ONE, &x, &y);
    position.x = x << FX32_SHIFT;
    position.y = y << FX32_SHIFT;
    position.z = 0;
    switch (team->shownSwapPhase) {
    case RELAY_RUN_SWAP_LEAVE:
        PokeathlonRelayRunTeam_AnimateLeave(hud, team, &position, teamId, member, touch, isHost && isCpu, isOwn);
        break;
    case RELAY_RUN_SWAP_ARRIVE:
        reportPhase = isHost && isCpu;
        PokeathlonRelayRunTeam_AnimateArrive(team, &position, teamId, member, touch, reportPhase | isOwn, isOwn);
        break;
    case RELAY_RUN_SWAP_DONE:
        if (changed) {
            PokeathlonRelayRunTeam_EndSwap(team, teamId, member, touch, (isHost && isCpu) | isOwn, isOwn);
        }
        PokeathlonCourseSpritePoolSprite_SetPosition(team->shadowSprite, &position);
        break;
    }
}

// Sets up a member of a team from its Pokemon's stats and the event's stat tables (setup->tables[n][stat]).

void PokeathlonRelayRun_InitMember(PokeathlonCourseData *course, const PokeathlonRelayRunSetup *setup, u8 participant, u8 member, PokeathlonRelayRunTeam *team) {
    u8 *stats = PokeathlonCourse_GetMonStats(course, participant, member);
    team->members[member].pushPower = (f32)setup->tables[0][stats[0]] / 10.0;
    team->members[member].maxEnergy = setup->tables[1][stats[3]];
    team->members[member].energy = setup->tables[1][stats[3]];
    team->members[member].speedLimit = setup->tables[5][stats[1]];
    team->members[member].patchSpeed = setup->tables[7][stats[1]];
    team->members[member].tiredSpeed = setup->tables[6][stats[1]];
    team->members[member].acceleration = (f32)setup->tables[2][stats[4]] / 10.0;
    team->members[member].weight = (f32)setup->tables[3][stats[1]] / 10.0;
    team->members[member].recoveryTime = setup->tables[4][stats[3]];
}

// Collects the obstacles within a screen of x: walls (kinds 1 and 2) and slow patches separately.

static void PokeathlonRelayRun_FindNearbyObstacles(PokeathlonRelayRun *relayRun, fx32 x, s32 **walls, s32 **patches, u8 *wallCount, u8 *patchCount) {
    int i;
    int wholeX;
    for (i = 0; i < RELAY_RUN_OBSTACLES; i++) {
        walls[i] = NULL;
        patches[i] = NULL;
    }
    *wallCount = 0;
    *patchCount = 0;
    wholeX = x / FX32_ONE;
    for (i = 0; i < RELAY_RUN_OBSTACLES; i++) {
        u8 kind;
        int distance;
        int screenX;
        if (!relayRun->obstacles[i].active) {
            return;
        }
        kind = relayRun->layout[i];
        distance = wholeX - relayRun->obstacles[i].x;
        if (distance >= 768.0) {
            screenX = 80.0 + (1024.0 - distance);
        } else if (distance <= -768.0) {
            screenX = 80.0 - (1024.0 + distance);
        } else {
            screenX = RELAY_RUN_RUNNER_X - distance;
        }
        if (screenX >= -32 && screenX <= 288) {
            if (kind == RELAY_RUN_OBSTACLE_SLOW_PATCH) {
                patches[(*patchCount)++] = &relayRun->layout[i];
            } else {
                walls[(*wallCount)++] = &relayRun->layout[i];
            }
        }
    }
}

// The outline of an obstacle from its layout entry: a 48x48 (kind 1) or 32x32 box centred on it, with its edges
// moved out by inset (the runner's radius); a slow patch is the 64x64 square around it.

void PokeathlonRelayRun_GetObstacleShape(int inset, const s32 *entry, PokeathlonRelayRunObstacleShape *shape) {
    s32 word = *entry;
    u32 kind = (u8)word;
    int y = (u8)(word >> 8);
    int x = (u16)(word >> 16);
    u32 size;
    y += 32;
    shape->kind = kind;
    if (kind == RELAY_RUN_OBSTACLE_SLOW_PATCH) {
        shape->corners[0].x = x - 32;
        shape->corners[0].y = y - 32;
        return;
    }
    size = kind == 1 ? 48 : 32;
    x -= size / 2;
    y -= size / 2;
    shape->corners[0].x = x;
    shape->corners[0].y = y;
    shape->corners[1].x = x + size;
    shape->corners[1].y = y;
    shape->corners[2].x = x + size;
    shape->corners[2].y = y + size;
    shape->corners[3].x = x;
    shape->corners[3].y = y + size;
    shape->edges[0][0] = shape->corners[0];
    shape->edges[0][1] = shape->corners[1];
    shape->edges[1][0] = shape->corners[1];
    shape->edges[1][1] = shape->corners[2];
    shape->edges[2][0] = shape->corners[2];
    shape->edges[2][1] = shape->corners[3];
    shape->edges[3][0] = shape->corners[3];
    shape->edges[3][1] = shape->corners[0];
    shape->edges[0][0].y -= inset;
    shape->edges[0][1].y -= inset;
    shape->edges[1][0].x += inset;
    shape->edges[1][1].x += inset;
    shape->edges[2][0].y += inset;
    shape->edges[2][1].y += inset;
    shape->edges[3][0].x -= inset;
    shape->edges[3][1].x -= inset;
}

// Moves a runner from start to end past a box obstacle: returns which edge (RELAY_RUN_HIT_TOP ..) or corner
// (RELAY_RUN_HIT_TOP_LEFT ..) it ran into and where it stops, or the side it is pushed out of when it ended up
// inside (RELAY_RUN_HIT_INSIDE_TOP ..). 0 if it missed.

static int PokeathlonRelayRun_CollideWithObstacle(VecFx32 *start, VecFx32 *end, int radius, PokeathlonRelayRunObstacleShape *shape, VecFx32 *out) {
    PokeathlonRelayRunHitTable edgeHits;
    PokeathlonRelayRunHitTable cornerHits;
    VecFx32 corner;
    VecFx32 diff;
    VecFx32 delta;
    VecFx32 result;
    Point2D hit;
    Point2D from;
    Point2D to;
    int i;
    BOOL onEdge;
    int lo, hi;
    if (shape->kind == RELAY_RUN_OBSTACLE_SLOW_PATCH) {
        return RELAY_RUN_HIT_NONE;
    }
    from.x = start->x / FX32_ONE;
    from.y = start->y / FX32_ONE;
    to.x = end->x / FX32_ONE;
    to.y = end->y / FX32_ONE;
    for (i = 0; i < 4; i++) {
        edgeHits = sRelayRunEdgeHits;
        if (Point2D_CalcSegmentIntersection(&shape->edges[i][0], &shape->edges[i][1], &from, &to, &hit)) {
            out->x = hit.x << FX32_SHIFT;
            out->y = hit.y << FX32_SHIFT;
            out->z = 0;
            return edgeHits.hits[i];
        }
        onEdge = FALSE;
        // BUG: i is never both 0 and 2, so every edge takes the second test (the one meant for the vertical edges).
        if (i == 0 && i == 2) {
            if (from.y == shape->edges[i][0].y) {
                if (shape->edges[i][0].x < shape->edges[i][1].x) {
                    lo = shape->edges[i][0].x;
                    hi = shape->edges[i][1].x;
                } else {
                    lo = shape->edges[i][1].x;
                    hi = shape->edges[i][0].x;
                }
                if (lo <= from.x && from.x <= hi) {
                    onEdge = TRUE;
                }
            }
        } else {
            if (from.x == shape->edges[i][0].x) {
                if (shape->edges[i][0].y < shape->edges[i][1].y) {
                    lo = shape->edges[i][0].y;
                    hi = shape->edges[i][1].y;
                } else {
                    lo = shape->edges[i][1].y;
                    hi = shape->edges[i][0].y;
                }
                if (lo <= from.y && from.y <= hi) {
                    onEdge = TRUE;
                }
            }
        }
        if (onEdge) {
            *out = *start;
            return edgeHits.hits[i];
        }
    }
    for (i = 0; i < 4; i++) {
        cornerHits = sRelayRunCornerHits;
        corner.x = shape->corners[i].x << FX32_SHIFT;
        corner.y = shape->corners[i].y << FX32_SHIFT;
        corner.z = 0;
        VEC_Subtract(end, &corner, &diff);
        if (VEC_Mag(&diff) <= radius * FX32_ONE) {
            fx32 entry = PokeathlonRelayRun_CalcCircleEntry(start, end, &corner, radius << FX32_SHIFT);
            VEC_Subtract(end, start, &delta);
            VEC_MultAdd(entry, &delta, start, &result);
            out->x = result.x;
            out->y = result.y;
            out->z = 0;
            return cornerHits.hits[i];
        }
    }
    if (shape->corners[0].x << FX32_SHIFT <= end->x && end->x <= shape->corners[2].x << FX32_SHIFT
        && shape->corners[0].y << FX32_SHIFT <= end->y && end->y <= shape->corners[2].y << FX32_SHIFT) {
        int dxRight;
        BOOL pushX;
        int left;
        int dxLeft;
        BOOL pushY;
        int bottom;
        int sideX;
        int top;
        int dyTop;
        int dyBottom;
        int sideY;
        int side;
        *out = *end;
        pushY = FALSE;
        pushX = FALSE;
        left = shape->corners[0].x;
        dxLeft = (left << FX32_SHIFT) - end->x;
        dxRight = (shape->corners[2].x << FX32_SHIFT) - end->x;
        if (dxLeft < 0) {
            dxLeft *= -1;
        }
        if (dxRight < 0) {
            dxRight *= -1;
        }
        if (dxLeft < dxRight) {
            sideX = RELAY_RUN_HIT_INSIDE_LEFT;
        } else {
            dxLeft = dxRight;
            sideX = RELAY_RUN_HIT_INSIDE_RIGHT;
        }
        top = shape->corners[0].y;
        dyTop = (top << FX32_SHIFT) - end->y;
        bottom = shape->corners[2].y;
        dyBottom = (bottom << FX32_SHIFT) - end->y;
        if (dyTop < 0) {
            dyTop *= -1;
        }
        if (dyBottom < 0) {
            dyBottom *= -1;
        }
        if (dyTop < dyBottom) {
            sideY = RELAY_RUN_HIT_INSIDE_TOP;
        } else {
            dyTop = dyBottom;
            sideY = RELAY_RUN_HIT_INSIDE_BOTTOM;
        }
        if (dxLeft <= dyTop) {
            pushX = TRUE;
            side = sideX;
        } else {
            pushY = TRUE;
            side = sideY;
        }
        if (pushX) {
            if (sideX == RELAY_RUN_HIT_INSIDE_LEFT) {
                out->x = (left - radius) << FX32_SHIFT;
            } else {
                out->x = (shape->corners[2].x + radius) << FX32_SHIFT;
            }
        } else if (pushY) {
            if (sideY == RELAY_RUN_HIT_INSIDE_TOP) {
                out->y = (top - radius) << FX32_SHIFT;
            } else {
                out->y = (bottom + radius) << FX32_SHIFT;
            }
        }
        return side;
    }
    return RELAY_RUN_HIT_NONE;
}

// Whether position is on a slow patch (the 64x64 square at its shape's first corner).
static BOOL PokeathlonRelayRun_IsOnSlowPatch(const VecFx32 *position, const PokeathlonRelayRunObstacleShape *shape) {
    fx32 px = position->x;
    fx32 py = position->y;
    s32 x = shape->corners[0].x << FX32_SHIFT;
    s32 y = shape->corners[0].y << FX32_SHIFT;
    if (x < px && px < x + FX32_CONST(64) && y < py && py < y + FX32_CONST(64)) {
        return TRUE;
    }
    return FALSE;
}

// Moves a runner (radius) from from to to among the obstacles near it. Returns whether it is on a slow patch
// << 8 | the wall it ran into (RELAY_RUN_HIT_*, 0: none); out gets where it stops, unless it is still touching
// the same wall as last frame (wallState).

u16 PokeathlonRelayRun_CollideWithObstacles(PokeathlonRelayRun *relayRun, int wallState, int radius, VecFx32 *from, VecFx32 *to, VecFx32 *out) {
    s32 *walls[RELAY_RUN_OBSTACLES];
    s32 *patches[RELAY_RUN_OBSTACLES];
    PokeathlonRelayRunObstacleShape patchShape;
    PokeathlonRelayRunObstacleShape wallShape;
    VecFx32 stop;
    u8 counts[2];
    int i;
    u8 onPatch;
    u8 result;
    PokeathlonRelayRun_FindNearbyObstacles(relayRun, from->x, walls, patches, &counts[1], &counts[0]);
    onPatch = FALSE;
    for (i = 0; i < counts[0]; i++) {
        PokeathlonRelayRun_GetObstacleShape(radius, patches[i], &patchShape);
        if (PokeathlonRelayRun_IsOnSlowPatch(from, &patchShape)) {
            onPatch = TRUE;
            break;
        }
    }
    result = RELAY_RUN_HIT_NONE;
    for (i = 0; i < counts[1]; i++) {
        int hit;
        PokeathlonRelayRun_GetObstacleShape(radius, walls[i], &wallShape);
        hit = PokeathlonRelayRun_CollideWithObstacle(from, to, radius, &wallShape, &stop);
        if (hit != RELAY_RUN_HIT_NONE) {
            if (hit >= RELAY_RUN_HIT_INSIDE_TOP) {
                out->x = stop.x;
                out->y = stop.y;
                out->z = 0;
            } else if (hit != wallState) {
                out->x = stop.x;
                out->y = stop.y;
                out->z = 0;
            }
            result = hit;
            break;
        }
    }
    return (onPatch << 8) + result;
}

// Where along the segment a -> b (0: a, 1: b) it first comes within r of c.
static fx32 PokeathlonRelayRun_CalcCircleEntry(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c, fx32 r) {
    VecFx32 segment;
    fx32 root, entry, lenSq, dot, centerDistance, leave;
    VEC_Subtract(b, a, &segment);
    lenSq = VEC_Mag(&segment);
    lenSq = lenSq * lenSq;
    dot = VEC_DotProduct(&segment, c);
    centerDistance = VEC_Mag((VecFx32 *)c);
    root = FX_Sqrt(dot - (centerDistance * centerDistance - r * r) * lenSq);
    entry = FX_Div(root - dot, lenSq);
    leave = FX_Div(-(dot + root), lenSq);
    return entry > leave ? leave : entry;
}

// The fastest a flick can make the member run: its speed on a slow patch, when tired, or its speed limit.
f32 PokeathlonRelayRunTeam_GetMaxSpeed(PokeathlonRelayRunTeam *team, int member) {
    if (team->onPatch) {
        return team->members[member].patchSpeed;
    }
    if (team->members[member].energy <= 40.0) {
        return team->members[member].tiredSpeed;
    }
    return team->members[member].speedLimit;
}

// Adds a flick to a velocity: x always adds up, y only when it goes the same way (else the flick's y wins).
void PokeathlonRelayRun_AddFlick(const VecFx32 *velocity, const VecFx32 *flick, VecFx32 *out) {
    out->x = velocity->x + flick->x;
    if (FX_Mul(velocity->y, flick->y) >= 0) {
        out->y = velocity->y + flick->y;
    } else {
        out->y = flick->y;
    }
}

// Runners bumping into each other: the one running into another stops and passes its speed (times its push
// power, at most 11 pixels per frame) on; a tired member that is hit is exhausted; both are stunned. Returns
// whether any two bumped, where the first two did in where.

BOOL PokeathlonRelayRun_CollideRunners(PokeathlonCourseData *course, PokeathlonRelayRunTeam *teams, VecFx32 *where) {
    VecFx32 posP;
    VecFx32 posQ;
    VecFx32 delta;
    int radP, radQ;
    int px, py, qx, qy;
    PokeathlonCourseMonObject *objectP, *objectQ;
    BOOL result;
    u8 pushMember;
    fx32 pX;
    int wrappedPx;
    s32 i;
    u8 memberP;
    int j;
    PokeathlonRelayRunTeam *runner, *other;
    result = FALSE;
    posP.z = 0;
    posQ.z = 0;
    for (i = 0, runner = teams; i < POKEATHLON_PARTICIPANTS; i++, runner++) {
        memberP = runner->current;
        if (runner->swapping || runner->stunTimer != 0) {
            continue;
        }
        objectP = runner->monObjects[memberP];
        PokeathlonCourseObject_GroundToCenter(objectP, runner->position.x / FX32_ONE, runner->position.y / FX32_ONE, &px, &py);
        for (j = 0, other = teams; j < POKEATHLON_PARTICIPANTS; j++, other++) {
            if (i == j) {
                continue;
            }
            if (other->swapping) {
                continue;
            }
            wrappedPx = px;
            objectQ = other->monObjects[other->current];
            PokeathlonCourseObject_GroundToCenter(objectQ, other->position.x / FX32_ONE, other->position.y / FX32_ONE, &qx, &qy);
            {
                // across the start line: compare them on the same lap
                pX = runner->position.x;
                if (pX > 768.0 * FX32_ONE && other->position.x < 256 * FX32_ONE) {
                    {
                        double shifted = qx;
                        shifted += 1024.0;
                        qx = shifted;
                    }
                } else if (other->position.x > 768.0 * FX32_ONE && pX < 256 * FX32_ONE) {
                    {
                        double shifted = wrappedPx;
                        shifted += 1024.0;
                        wrappedPx = shifted;
                    }
                }
            }
            PokeathlonCourseObject_GetCollisionCircle(objectQ, qx << FX32_SHIFT, qy << FX32_SHIFT, &posQ.x, &posQ.y, &radQ);
            PokeathlonCourseObject_GetCollisionCircle(objectP, wrappedPx << FX32_SHIFT, py << FX32_SHIFT, &posP.x, &posP.y, &radP);
            VEC_Subtract(&posQ, &posP, &delta);
            if (VEC_Mag(&delta) < (radQ + radP) << FX32_SHIFT) {
                if (runner->bumpedInto[j] != 0) {
                    continue;
                }
                VecFx32 zero = { 0, 0, 0 };
                if (VEC_DotProduct(&delta, &runner->velocity) <= 0) {
                    continue;
                }
                if (VEC_Mag(&runner->velocity) != 0) {
                    pushMember = runner->current;
                    VEC_MultAdd(4096.0f * runner->members[pushMember].pushPower, &runner->velocity, &zero, &other->velocity);
                    if (VEC_Mag(&other->velocity) > FX32_CONST(11)) {
                        VecFx32 zero2 = { 0, 0, 0 };
                        VEC_Normalize(&other->velocity, &other->velocity);
                        VEC_MultAdd(FX32_CONST(11), &other->velocity, &zero2, &other->velocity);
                    }
                }
                // BUG: memberP is p's running member, so this checks (and exhausts) that member of q's team.
                if (other->members[memberP].condition == RELAY_RUN_TIRED) {
                    other->members[memberP].energy = 0;
                    other->members[memberP].condition = RELAY_RUN_EXHAUSTED;
                    other->recoveryTimer = other->members[memberP].recoveryTime;
                    PokeathlonCourse_AddMonCounter(course, other->owner, other->current, POKEATHLON_COUNTER_FAILURES, 1);
                }
                {
                    VecFx32 stop = { 0, 0, 0 };
                    runner->velocity = stop;
                }
                // BUG: pushMember is only set when p was moving; otherwise it keeps an older value.
                if (runner->members[pushMember].condition == RELAY_RUN_TIRED) {
                    runner->members[pushMember].energy = 0;
                    runner->members[pushMember].condition = RELAY_RUN_EXHAUSTED;
                    runner->recoveryTimer = runner->members[pushMember].recoveryTime;
                    PokeathlonCourse_AddMonCounter(course, runner->owner, runner->current, POKEATHLON_COUNTER_FAILURES, 1);
                }
                GF_ASSERT(runner->bumpedInto[j] == 0);
                GF_ASSERT(other->bumpedInto[i] == 0);
                // BUG: the asserts above and the reset below use p->bumpedInto[j] and q->bumpedInto[i]; these marks
                // go to the other two entries.
                other->bumpedInto[j] = 1;
                runner->bumpedInto[i] = 1;
                if (!result) {
                    VecFx32 contact = { 0, 0, 0 };
                    result = TRUE;
                    VEC_Subtract(&posQ, &posP, &contact);
                    VEC_Normalize(&contact, &contact);
                    VEC_MultAdd(radP << FX32_SHIFT, &contact, &posP, &contact);
                    if (contact.x >= 1024.0 * FX32_ONE) {
                        contact.x = contact.x - 1024.0 * FX32_ONE;
                    }
                    *where = contact;
                }
                other->stunTimer = 6;
                runner->stunTimer = 18;
                PokeathlonCourse_AddMonCounter(course, other->owner, other->current, POKEATHLON_COUNTER_TACKLES, 1);
                PokeathlonCourse_AddMonCounter(course, runner->owner, runner->current, POKEATHLON_COUNTER_TACKLES, 1);
                break;
            } else {
                runner->bumpedInto[j] = 0;
                other->bumpedInto[i] = 0;
            }
        }
    }
    return result;
}

// Places a mark (sprite) above a Pokemon standing at position, higher for bigger Pokemon (size class 1-3 in
// its performance data).
static void PokeathlonRelayRun_PlaceAboveMon(PokeathlonCoursePerformance *performance, const VecFx32 *position, PokeathlonCourseSpritePoolSprite *sprite) {
    VecFx32 above = *position;
    switch (performance->spriteSizeType) {
    case 1:
        above.y -= FX32_CONST(20);
        break;
    case 2:
        above.y -= FX32_CONST(32);
        break;
    case 3:
        above.y -= FX32_CONST(40);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    PokeathlonCourseSpritePoolSprite_SetPosition(sprite, &above);
}

// Obstacles further down the track are drawn in front; slow patches lie under everything.
void PokeathlonRelayRunObstacle_SetDrawPriority(PokeathlonRelayRunObstacle *obstacle) {
    int row;
    if (obstacle->kind == RELAY_RUN_OBSTACLE_SLOW_PATCH) {
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(obstacle->sprite, 600);
        return;
    }
    row = 160 - (obstacle->y + 32);
    if (row < 0) {
        row = 0;
    }
    PokeathlonCourseSpritePoolSprite_SetDrawPriority(obstacle->sprite, 30 * (row / 8 + 1) + 3);
}

// Draw priorities of a team at y: in front of the obstacles above it, the player's own team before the others.
void PokeathlonRelayRunTeam_SetDrawPriority(PokeathlonRelayRunTeam *team, u8 y, BOOL isOwn) {
    int row = 168 - y;
    int priority;
    if (row < 0) {
        row = 0;
    }
    row = row / 8;
    if (isOwn) {
        priority = 30 * row + 4;
    } else {
        priority = 30 * row + 7;
    }
    PokeathlonCourseSpritePoolSprite_SetDrawPriority(team->shadowSprite, priority);
    PokeathlonCourseSpritePoolSprite_SetDrawPriority(team->speedSprite, priority + 1);
    PokeathlonCourseSpritePoolSprite_SetDrawPriority(team->conditionSprite, priority + 1);
    PokeathlonCourseSpritePoolSprite_SetDrawPriority(team->swapSprite, priority + 2);
    {
        int i;
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            PokeathlonCourseMonObject_SetDrawPriority(team->monObjects[i], priority + 2);
        }
    }
}

// The start line (BG 0, tile 32 in columns 10-11) while the track around it is on screen; tile 1 when the
// player's runner is between x 272 and 768.
void PokeathlonRelayRun_UpdateStartLine(BgConfig *bgConfig, int x) {
    if (x > 272 && x < 768) {
        FillBgTilemapRect(bgConfig, GF_BG_LYR_MAIN_0, 1, 10, 3, 2, 21, TILEMAP_FILL_KEEP_PAL);
    } else {
        FillBgTilemapRect(bgConfig, GF_BG_LYR_MAIN_0, 32, 10, 3, 2, 21, TILEMAP_FILL_KEEP_PAL);
    }
    ScheduleBgTilemapBufferTransfer(bgConfig, GF_BG_LYR_MAIN_0);
}

// Shows the lap count for a second (60 frames) each time it goes up.
void PokeathlonRelayRun_UpdateLapCounter(PokeathlonRelayRunLapCounter *counter, u8 laps) {
    VecFx32 platePosition = sRelayRunLapCounterPlatePos, firstPosition = sRelayRunLapCounterFirstDigitPos, secondPosition = sRelayRunLapCounterSecondDigitPos;
    BOOL changed;
    if (counter->laps < laps) {
        counter->laps = laps;
        changed = TRUE;
    } else {
        changed = FALSE;
    }
    if (changed) {
        u8 tens = laps / 10;
        u8 ones = laps % 10;
        if (tens) {
            platePosition.x = FX32_CONST(96);
            firstPosition.x = FX32_CONST(144);
            secondPosition.x = FX32_CONST(176);
            Sprite_SetAnimCtrlSeq(counter->digits[0], tens + 1);
            Sprite_SetAnimCtrlSeq(counter->digits[1], ones + 1);
        } else {
            platePosition.x = FX32_CONST(112);
            firstPosition.x = FX32_CONST(160);
            Sprite_SetAnimCtrlSeq(counter->digits[0], ones + 1);
            Sprite_SetAnimCtrlSeq(counter->digits[1], 0);
        }
        PokeathlonCourseSpritePoolSprite_SetPosition(counter->plate, &platePosition);
        Sprite_SetMatrix(counter->digits[0], &firstPosition);
        Sprite_SetMatrix(counter->digits[1], &secondPosition);
        PokeathlonCourseSpritePoolSprite_Show(counter->plate, TRUE, TRUE);
        Sprite_SetDrawFlag(counter->digits[0], TRUE);
        Sprite_SetDrawFlag(counter->digits[1], TRUE);
        counter->timer = 60;
        PlaySE(SEQ_SE_GS_POINT3);
    } else {
        counter->timer--;
        if (counter->timer == 0) {
            counter->timer = 0;
            PokeathlonCourseSpritePoolSprite_Show(counter->plate, TRUE, FALSE);
            Sprite_SetDrawFlag(counter->digits[0], FALSE);
            Sprite_SetDrawFlag(counter->digits[1], FALSE);
        }
    }
}

void PokeathlonRelayRun_AddResultWindow(PokeathlonRelayRun *relayRun) {
    AddWindow(relayRun->bgConfig, &relayRun->window, &sRelayRunResultWindowTemplate);
    BG_FillCharDataRange(relayRun->bgConfig, GF_BG_LYR_MAIN_3, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, relayRun->heapId);
}

// "Pokemon Total: laps.tenths Laps" (x: distance into the last lap).
static void PokeathlonRelayRun_PrintResult(PokeathlonRelayRun *relayRun, int laps, int x) {
    MsgData *msgData;
    MessageFormat *msgFormat;
    String *string;
    int tenths;
    FillWindowPixelBuffer(&relayRun->window, 0);
    tenths = x * 10 / 1024.0;
    GF_ASSERT(tenths <= 9);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, relayRun->heapId);
    msgFormat = MessageFormat_New(relayRun->heapId);
    BufferIntegerAsString(msgFormat, 0, laps, 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BufferIntegerAsString(msgFormat, 1, tenths, 1, PRINTING_MODE_LEADING_ZEROS, TRUE);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msg_0309_00162, relayRun->heapId);
    AddTextPrinterParameterizedWithColor(&relayRun->window, 4, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    MessageFormat_Delete(msgFormat);
    DestroyMsgData(msgData);
    CopyWindowToVram(&relayRun->window);
}

// Plays a sound effect for something at screen x if it is on screen, on the player's own channel (3) when it
// belongs to the player's own team.
void PokeathlonRelayRun_PlaySEIfOnScreen(int x, int seqNo, BOOL isOwn) {
    if (x >= 0 && x < 256) {
        PlaySEOnPlayer(seqNo, isOwn ? 3 : 4);
    }
}

// The sign at the top of a player's screen (swapSigns): 1 the runner is tired, 2 the swap button is pressed,
// 3 a swap is not possible now (swapping, stunned or exhausted), 4 pressed while it is not possible.
void PokeathlonRelayRun_UpdateSwapSign(PokeathlonRelayRun *relayRun, u8 teamId, BOOL touchingSwapButton) {
    u8 *signs = relayRun->swapSigns;
    u8 sign = 0;
    u8 condition = relayRun->teams[teamId].members[relayRun->teams[teamId].current].condition;
    if (relayRun->teams[teamId].swapping) {
        sign = 3;
    } else if (relayRun->teams[teamId].stunTimer != 0) {
        sign = 3;
    } else if (condition == RELAY_RUN_EXHAUSTED) {
        sign = 3;
    } else if (condition == RELAY_RUN_TIRED) {
        sign = 1;
    }
    if (!touchingSwapButton) {
        signs[teamId] = sign;
        return;
    }
    if (relayRun->presses[teamId].pressed) {
        if (sign <= 1) {
            signs[teamId] = 2;
            return;
        }
        if (sign == 3) {
            signs[teamId] = 4;
            return;
        }
        GF_ASSERT(FALSE);
        return;
    }
    if (!relayRun->presses[teamId].held) {
        signs[teamId] = sign;
    }
}

// Finish callback: the player's record (laps << 10 | x) and the result window.
void PokeathlonRelayRun_SaveResult(PokeathlonCourseData *course) {
    PokeathlonRelayRunPacket *packet = (PokeathlonRelayRunPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + offsetof(PokeathlonRelayRunLink, packet));
    PokeathlonRelayRun *relayRun = PokeathlonCourse_GetWork(course);
    u8 own = PokeathlonCourse_GetNetId(course);
    u8 laps = packet->laps[own] & 0x7F;
    u16 x = packet->x[own];
    if (laps > RELAY_RUN_MAX_LAPS) {
        laps = RELAY_RUN_MAX_LAPS;
    }
    PokeathlonCourse_SetRecordScore(course, x + (laps << 10));
    PokeathlonRelayRun_PrintResult(relayRun, laps, x);
}
