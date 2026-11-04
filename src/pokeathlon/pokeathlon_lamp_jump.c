#include "pokeathlon/pokeathlon_lamp_jump.h"

#include "global.h"

#include "constants/sdk_extras.h"
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"
#include "pokeathlon/pokeathlon_results_announcement.h"

#include "assert.h"
#include "bg_window.h"
#include "camera.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "player_data.h"
#include "screen_fade.h"
#include "sound_playback_internal.h"
#include "sound_system_internal.h"
#include "sprite.h"
#include "string_util.h"
#include "swap_3d_buffers.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"

enum {
    LAMP_JUMP_STATE_PLAY,
    LAMP_JUMP_STATE_CALC_SCORES,
};

enum PokeathlonLampJumpPlayState {
    LAMP_JUMP_PLAY_START,
    LAMP_JUMP_PLAY_FADE_IN,
    LAMP_JUMP_PLAY_WAIT_FADE_IN,
    LAMP_JUMP_PLAY_COUNTDOWN,
    LAMP_JUMP_PLAY_RUN,
    LAMP_JUMP_PLAY_FINISH,
};

enum PokeathlonLampJumpInitState {
    LAMP_JUMP_INIT_CREATE,
    LAMP_JUMP_INIT_CREATE_LAMPS,
    LAMP_JUMP_INIT_CREATE_SPRITES,
    LAMP_JUMP_INIT_LOAD_MONS,
    LAMP_JUMP_INIT_PLACE_MONS,
    LAMP_JUMP_INIT_SET_UP,
    LAMP_JUMP_INIT_DONE,
};

static void PokeathlonLampJump_SetGfxBanks(void);
static void PokeathlonLampJump_InitBgs(BgConfig *bgConfig);
static void PokeathlonLampJump_LoadBgGfx(PokeathlonLampJump *lampJump);
static BOOL PokeathlonLampJump_Update(PokeathlonCourseData *course);
static void PokeathlonLampJump_UpdateDisplay(PokeathlonCourseData *course);
static void PokeathlonLampJump_HandleTouch(PokeathlonCourseData *course);
static void PokeathlonLampJump_UpdateMonSprites(PokeathlonCourseData *course);
static void PokeathlonLampJump_UpdatePlayerSprites(PokeathlonCourseData *course);
static void PokeathlonLampJump_GetFlick(int touchX, int touchY, const VecFx32 *start, VecFx32 *flick);
static u8 PokeathlonLampJump_FindTouchedMon(PokeathlonLampJump *lampJump, u16 touchX, u16 touchY);
static void PokeathlonLampJump_LaunchMon(PokeathlonLampJump *lampJump, s32 mon, VecFx32 *flick);
static void PokeathlonLampJump_Init3D(PokeathlonLampJump *lampJump);

static void PokeathlonLampJump_CalcLine(PokeathlonLampJumpTrampoline *trampoline, int line, u8 monA, u8 monB);
static void PokeathlonLampJump_UpdateJump(PokeathlonCourseData *course, PokeathlonLampJump *lampJump, u8 mon);
static void PokeathlonLampJump_MoveSideways(PokeathlonLampJumpMon *mon, PokeathlonLampJumpJump *jump);
static void PokeathlonLampJump_SetDent(PokeathlonLampJump *lampJump, int mon, u8 column, fx32 depth);
static void PokeathlonLampJump_PrintScore(PokeathlonLampJump *lampJump, int score);
static void PokeathlonLampJump_SlowDownSideways(PokeathlonLampJumpMon *mon);
static void PokeathlonLampJump_CreateLampSprites(PokeathlonLampJumpLamps *lamps, PokeathlonCourseSpritePool *scene, int priority);
static void PokeathlonLampJump_PlaceLamps(PokeathlonLampJumpLamps *lamps);
static void PokeathlonLampJump_PutOutLamp(PokeathlonLampJumpLamps *lamps, u8 index);
static VecFx32 *PokeathlonLampJump_GetLampPos(PokeathlonLampJumpLamps *lamps, u8 index);
static BOOL PokeathlonLampJump_IsLampLit(PokeathlonLampJumpLamps *lamps, u8 index);
static void PokeathlonLampJump_ShowLampPoints(PokeathlonLampJumpLamps *lamps, u8 index, u8 points);
static void PokeathlonLampJump_LightLamps(PokeathlonLampJumpLamps *lamps);
static void PokeathlonLampJump_UpdateCpuPlayer(PokeathlonCourseData *course, PokeathlonLampJumpCpuPlayers *cpu, u8 participant);

static int sTrampolineGreen = 10;

static int sTrampolineBlue = 20;

static const u8 sLampJumpTimerDigitAnims[2] = { 1, 1 };

static const u8 sLampJumpTimerDigitX[2] = { 192, 208 };

static const VecFx32 sLampJumpTrampolineScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static const VecFx32 sLampJumpCameraOffset = { 0, 0, FX32_ONE };

static const VecFx32 sLampJumpTimerLabelPos = { FX32_CONST(168), FX32_CONST(8), 0 };

static const VecFx32 sLampJumpFirstOtherPlayerPos = { FX32_CONST(166), FX32_CONST(40), 0 };

static const VecFx32 sLampJumpOwnPlayerPos = { FX32_CONST(22), FX32_CONST(72), 0 };

static const PokeathlonCourseSpritePoolTemplate sLampJumpSceneConfig = {
    .capacity = 209,
    .resourceCount = 1,
    .resCounts = { 1, 1, 1, 1 },
};

static const GraphicsModes sLampJumpGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_3D,
};

static const u32 sLampJumpLampSoundPitches[5] = { 0, 128, 0x100, 0x140, 0x1C0 };

static const BgTemplate sLampJumpBgTemplate_Sub0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sLampJumpBgTemplate_Sub1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sLampJumpBgTemplate_Main2 = {
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

static const BgTemplate sLampJumpBgTemplate_Main1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sLampJumpBgTemplate_Main3 = {
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

static const BgTemplate sLampJumpBgTemplate_Sub2 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd000,
    .charBase = GX_BG_CHARBASE_0x0c000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const WindowTemplate sLampJumpWindowTemplates[5] = {
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 4,
     .top = 8,
     .width = 10,
     .height = 2,
     .palette = 15,
     .baseTile = 1,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 22,
     .top = 4,
     .width = 10,
     .height = 2,
     .palette = 15,
     .baseTile = 0x15,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 22,
     .top = 6,
     .width = 10,
     .height = 2,
     .palette = 15,
     .baseTile = 0x29,
     },
    {
     .bgId = GF_BG_LYR_SUB_2,
     .left = 22,
     .top = 8,
     .width = 10,
     .height = 2,
     .palette = 15,
     .baseTile = 0x3D,
     },
    {
     .bgId = GF_BG_LYR_MAIN_3,
     .left = 0,
     .top = 20,
     .width = 32,
     .height = 2,
     .palette = 15,
     .baseTile = 0x51,
     },
};

static const GraphicsBanks sLampJumpGraphicsBanks = {
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

static const u16 sLampJumpLampPositions[LAMP_JUMP_LAMPS][2] = {
    { 16, 8  },
    { 4,  11 },
    { 12, 11 },
    { 20, 11 },
    { 28, 11 },
    { 8,  14 },
    { 16, 14 },
    { 24, 14 },
    { 4,  17 },
    { 12, 17 },
    { 20, 17 },
    { 28, 17 },
    { 8,  20 },
    { 16, 20 },
    { 24, 20 },
    { 4,  23 },
    { 12, 23 },
    { 20, 23 },
    { 28, 23 },
    { 8,  25 },
    { 16, 25 },
    { 24, 25 },
    { 4,  28 },
    { 12, 28 },
    { 20, 28 },
    { 28, 28 },
    { 8,  31 },
    { 16, 31 },
    { 24, 31 }
};

BOOL PokeathlonLampJump_Init(PokeathlonCourseData *course) {
    PokeathlonCourseMonGfxTemplate info;
    ObjCharTransferTemplate spriteConfig;
    PokeathlonCourseSpritePoolTemplate sceneConfig;
    PokeathlonCourseMonInfo views[POKEATHLON_TEAM_SIZE];
    PokeathlonCourseCollision collisions[POKEATHLON_SIZE_CLASSES];
    PokeathlonCoursePoint screenPos[POKEATHLON_TEAM_SIZE];
    PokeathlonLampJumpMonParams params;
    int screenX, screenY;
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);
    int i, mode, count, monIndex, x, jumpIndex, jumpX, column;
    u8 participant;
    PokeathlonCourseMonObject *sprite;

    switch (PokeathlonCourse_GetEventInitState(course)) {
    case LAMP_JUMP_INIT_CREATE:
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_143, 0x50000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
        PokeathlonLampJump_SetGfxBanks();
        lampJump = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonLampJump));
        MI_CpuFill8(lampJump, 0, sizeof(PokeathlonLampJump));
        lampJump->bgConfig = BgConfig_Alloc(HEAP_ID_143);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        spriteConfig.maxTasks = 213;
        spriteConfig.sizeMain = 0x40000;
        spriteConfig.sizeSub = 0x4000;
        spriteConfig.heapID = PokeathlonCourse_GetHeapID(course);
        PokeathlonCourse_InitObjTransfer(&spriteConfig, 15, HEAP_ID_143, GX_OBJVRAMMODE_CHAR_1D_256K, GX_OBJVRAMMODE_CHAR_1D_256K);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_143);
        lampJump->heapId = HEAP_ID_143;
        FontID_Alloc(4, lampJump->heapId);
        PokeathlonLampJump_InitBgs(lampJump->bgConfig);
        PokeathlonLampJump_Init3D(lampJump);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        GF_CreateVramTransferManager(12, lampJump->heapId);
        lampJump->cellTransferState = CreateCellTransferStateManager(12, lampJump->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case LAMP_JUMP_INIT_CREATE_LAMPS:
        lampJump->lamps = PokeathlonLampJump_NewLamps(lampJump->heapId);
        count = PokeathlonCourse_GetParticipantCount(course);
        mode = PokeathlonCourse_GetMode(course);
        lampJump->cpuPlayers = PokeathlonLampJump_NewCpuPlayers(lampJump->heapId, 4 - count, mode, PokeathlonCourse_GetDataCopyArea(course), course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case LAMP_JUMP_INIT_CREATE_SPRITES:
        sceneConfig = sLampJumpSceneConfig;
        lampJump->scene = PokeathlonCourseSpritePool_New(lampJump->heapId, &sceneConfig);
        PokeathlonCourseSpritePool_SetSurfaceCoords(lampJump->scene, 0, FX32_CONST(192), 0, 0);
        lampJump->monSpriteManager = PokeathlonCourseMonObjects_Create(lampJump->heapId, 3, 10, NULL, PokeathlonCourseSpritePool_GetSpriteList(lampJump->scene));
        PokeathlonCourseSpritePool_SetResourceId(lampJump->scene, 0, 101);
        PokeathlonLampJump_LoadSpriteResources(lampJump->scene);
        PokeathlonCourseSpritePool_TransferResources(lampJump->scene);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case LAMP_JUMP_INIT_LOAD_MONS:
        participant = PokeathlonCourse_GetNetId(course);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            PokeathlonCourse_GetMonInfo(course, participant, i, &views[i]);
            info.sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, participant, i));
        }
        info.loadAtOnce = FALSE;
        info.priority = 1;
        info.vramTransfer = TRUE;
        info.vram = NNS_G2D_VRAM_TYPE_2DBOTH;
        info.whichScreen = NNS_G2D_VRAM_TYPE_2DBOTH;
        PokeathlonCourseMonObjects_Load(lampJump->monSpriteManager, 3, views, &info, 0, 0);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case LAMP_JUMP_INIT_PLACE_MONS:
        if (!PokeathlonCourseMonObjects_IsLoaded(lampJump->monSpriteManager)) {
            break;
        }
        lampJump->spriteResources = PokeathlonCourseSprites_CreateResources(lampJump->heapId, 929, NNS_G2D_VRAM_TYPE_2DMAIN);
        {
            Sprite **playerSprite = PokeathlonCourse_CreateHudSpritesInPool(course, 192, lampJump->spriteResources, lampJump->scene);
            Sprite_SetDrawPriority(*playerSprite, 1);
        }
        PokeathlonCourse_SetVBlankIntrCB((PokeathlonCourseData *)lampJump->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        ReadWholeNarcMemberByIdPair(collisions, NARC_a_1_7_0, 16);
        for (monIndex = 0; monIndex < POKEATHLON_TEAM_SIZE; monIndex++) {
            PokeathlonLampJumpMon *mon = &lampJump->mons[monIndex];

            x = 64 + monIndex * 64;
            sprite = PokeathlonCourseMonObjects_Get(lampJump->monSpriteManager, monIndex);
            PokeathlonCourseMonObject_SetDrawFlag(sprite, 1);
            mon->sprite = sprite;
            count = PokeathlonCourse_GetCollisionSizeClass(PokeathlonCourse_GetPerformance(course, 0, monIndex));
            PokeathlonCourseObject_SetCollision(sprite, collisions[count - 1].offsetY, collisions[count - 1].radius);
            PokeathlonCourseMonObject_SetAnimState(sprite, 2);
            PokeathlonCourseObject_SetGroundPosition(sprite, x, 288);
            PokeathlonCourseObject_SetTouchRadius(sprite, PokeathlonCourse_GetTouchRadius());
            mon->drawX = x << FX32_SHIFT;
            mon->drawY = 288 << FX32_SHIFT;
            mon->x = x << FX32_SHIFT;
            PokeathlonCourseObject_GroundToCenter(sprite, x, 288, &screenX, &screenY);
            screenPos[monIndex].x = screenX;
            screenPos[monIndex].y = screenY;
        }
        PokeathlonCourse_CreateStartSpritesInPool(course, 0, lampJump->spriteResources, lampJump->scene, NNS_G2D_VRAM_TYPE_2DMAIN, 3, screenPos);
        lampJump->selectedMon = 3;
        PokeathlonLampJump_LoadBgGfx(lampJump);
        PokeathlonLampJump_CreateSprites(lampJump, lampJump->scene);
        PokeathlonLampJump_InitWindows(lampJump);
        PokeathlonLampJump_PlaceSprites(lampJump, PokeathlonCourse_GetNetId(course));
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case LAMP_JUMP_INIT_SET_UP:
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        ReadWholeNarcMemberByIdPair(&params, NARC_a_1_7_0, 6);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            PokeathlonLampJump_SetMonParams(course, &params, i, &lampJump->mons[i]);
        }
        PokeathlonCourse_GetNetId(course);
        lampJump->timer = 1800;
        PokeathlonLampJump_UpdateTimerDisplay(lampJump, lampJump->timer);
        PokeathlonLampJump_PrintPlayerNames(course, lampJump);
        for (column = 0; column < LAMP_JUMP_COLUMNS; column++) {
            lampJump->trampolineRows[0][column] = 0;
            lampJump->trampolineRows[1][column] = 0;
            lampJump->trampolineRows[2][column] = 0;
            lampJump->trampolineRows[3][column] = 0;
            lampJump->trampolineRows[4][column] = 0;
            lampJump->trampolineRows[5][column] = 0;
            lampJump->trampolineRows[6][column] = 0;
        }
        for (jumpIndex = 0; jumpIndex < POKEATHLON_TEAM_SIZE; jumpIndex++) {
            lampJump->jumps[jumpIndex].height = 0;
            jumpX = jumpIndex * 64 + 64;
            lampJump->monColumns[jumpIndex] = jumpX / 2;
            lampJump->jumps[jumpIndex].unk04 = 4096.0 * ((f32)jumpX / 64.0 - 2.0);
            lampJump->mons[jumpIndex].bounceReady = TRUE;
        }
        WirelessStatusIcon_CreateOnScreenIfConnected(1);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case LAMP_JUMP_INIT_DONE:
        PokeathlonLampJump_UpdateScoreDisplay(lampJump);
        return TRUE;
    }
    return FALSE;
}

BOOL PokeathlonLampJump_Draw(PokeathlonCourseData *course) {
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);

    PokeathlonCourseSpritePool_Draw(lampJump->scene);
    thunk_UpdateCellTransferStateManager();
    return TRUE;
}

BOOL PokeathlonLampJump_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx;
    int i;

    PokeathlonCourse_GetWork(course);
    gfx = PokeathlonCourse_GetGraphicsSystem(course);
    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, gfx, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00296);
    }
    PokeathlonCourseScoreList_Rank(gfx, 1);
    PokeathlonEvent_CalcPoints(gfx, 5);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 5);
    return TRUE;
}

BOOL PokeathlonLampJump_Exit(PokeathlonCourseData *course) {
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);
    int i;
    Window *window;

    WirelessStatusIcon_Destroy();
    Camera_Delete(lampJump->camera);
    PokeathlonLampJump_FreeLamps(lampJump->lamps);
    Heap_Free(lampJump->bg2ScreenFile);
    FreeBgTilemapBuffer(lampJump->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(lampJump->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(lampJump->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(lampJump->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(lampJump->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(lampJump->bgConfig, GF_BG_LYR_SUB_2);
    for (i = 0, window = lampJump->windows; i < 5; i++, window++) {
        RemoveWindow(window);
    }
    Heap_Free(lampJump->bgConfig);
    PokeathlonCourse_ClearEventDataTransfer(course);
    PokeathlonCourseSpritePool_Free(lampJump->scene);
    PokeathlonCourseMonObjects_Free(lampJump->monSpriteManager);
    PokeathlonCourseSprites_FreeResources(lampJump->spriteResources);
    PokeathlonLampJump_FreeCpuPlayers(lampJump->cpuPlayers);
    FontID_Release(4);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    DestroyCellTransferStateManager(lampJump->cellTransferState);
    GF_DestroyVramTransferManager();
    PokeathlonCourse_FreeWork(course);
    reg_G2_BLDCNT = 0;
    Heap_Destroy(HEAP_ID_143);
    return TRUE;
}

static void PokeathlonLampJump_SetGfxBanks(void) {
    GraphicsBanks banks = sLampJumpGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

BOOL PokeathlonLampJump_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case LAMP_JUMP_PLAY_START:
        PokeathlonLampJump_UpdateDisplay(course);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_LAMP_JUMP);
        (*state)++;
        break;
    case LAMP_JUMP_PLAY_FADE_IN:
        PokeathlonLampJump_UpdateDisplay(course);
        BeginNormalPaletteFade(FADE_SUB_THEN_MAIN, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, lampJump->heapId);
        (*state)++;
        break;
    case LAMP_JUMP_PLAY_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        PokeathlonLampJump_UpdateDisplay(course);
        break;
    case LAMP_JUMP_PLAY_COUNTDOWN:
        PokeathlonLampJump_UpdateDisplay(course);
        if (PokeathlonCourse_RunStartCountdown(course)) {
            (*state)++;
        }
        break;
    case LAMP_JUMP_PLAY_RUN:
        PokeathlonLampJump_HandleTouch(course);
        if (PokeathlonLampJump_Update(course)) {
            (*state)++;
        }
        break;
    case LAMP_JUMP_PLAY_FINISH:
        if (PokeathlonCourse_RunFinish(course)) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, lampJump->heapId);
            PokeathlonCourse_SetNextState(course, LAMP_JUMP_STATE_CALC_SCORES);
        }
        break;
    }
    return FALSE;
}

BOOL PokeathlonLampJump_CalcScores(PokeathlonCourseData *course, u8 *state) {
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);
    int self, i, score, participant, member, total;
    u8 participantId, random;
    u8 *stats;

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return FALSE;
    }
    self = PokeathlonCourse_GetNetId(course);
    score = 0;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        score += lampJump->mons[i].score;
    }
    if (score > POKEATHLON_SCORE_MAX) {
        score = POKEATHLON_SCORE_MAX;
    }
    PokeathlonCourse_SetEventScore(course, (u8)self, score);
    if (self == 0) {
        // the host simulates the participants without a player
        for (participant = PokeathlonCourse_GetParticipantCount(course); participant < POKEATHLON_PARTICIPANTS; participant++) {
            member = 0;
            total = member;
            participantId = participant;
            for (; member < POKEATHLON_TEAM_SIZE; member++) {
                stats = PokeathlonCourse_GetMonStats(course, participant, member);
                if (stats[2]) {
                    int bonus = LCRandom() % 21;
                    int base = stats[3] * 2 + (stats[2] * 6 + 80 + stats[4] * 2);
                    total += base + bonus;
                    LCRandom();
                }
                PokeathlonCourse_AddMonCounter(course, participantId, member, POKEATHLON_COUNTER_JUMPS, 0);
                random = LCRandom() % 21;
                PokeathlonCourse_AddMonCounter(course, participantId, member, POKEATHLON_COUNTER_TACKLES, random);
                PokeathlonCourse_AddMonCounter(course, participantId, member, POKEATHLON_COUNTER_FAILURES, random);
            }
            PokeathlonCourse_SetEventScore(course, (u8)participant, total);
        }
    }
    return TRUE;
}

static void PokeathlonLampJump_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate main2;
    BgTemplate main1;
    BgTemplate main3;
    BgTemplate sub0;
    BgTemplate sub1;
    BgTemplate sub2;

    modes = sLampJumpGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    main2 = sLampJumpBgTemplate_Main2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &main2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    main1 = sLampJumpBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    main3 = sLampJumpBgTemplate_Main3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main3, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    sub0 = sLampJumpBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &sub0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    sub1 = sLampJumpBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &sub1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    sub2 = sLampJumpBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &sub2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
}

static void PokeathlonLampJump_LoadBgGfx(PokeathlonLampJump *lampJump) {
    GfGfxLoader_LoadCharData(NARC_a_1_6_8, 7, lampJump->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_8, 5, lampJump->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_8, 10, lampJump->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_8, 12, lampJump->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_8, 8, lampJump->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_8, 6, lampJump->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_8, 11, lampJump->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_8, 13, lampJump->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, lampJump->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_8, 4, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x20, lampJump->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_8, 9, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x40, lampJump->heapId);
    lampJump->bg2ScreenFile = GfGfxLoader_GetScrnData(NARC_a_1_6_8, 14, FALSE, &lampJump->bg2Screen, lampJump->heapId);
}

static BOOL PokeathlonLampJump_Update(PokeathlonCourseData *course) {
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);
    u32 *sent = (u32 *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course));

    lampJump->hitLamp = 0;
    if (lampJump->timer) {
        lampJump->timer--;
    }
    if ((u8)(lampJump->timer <= 0)) {
        int score = 0, i;

        PokeathlonCourseSpritePool_PauseAnims(lampJump->scene, TRUE);
        PokeathlonCourseObjects_PauseAnims(lampJump->monSpriteManager, TRUE);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            score += lampJump->mons[i].score;
        }
        if (score > POKEATHLON_SCORE_MAX) {
            score = POKEATHLON_SCORE_MAX;
        }
        PokeathlonCourse_SetRecordScore(course, score);
        PokeathlonLampJump_PrintTotal(lampJump, score);
        PokeathlonLampJump_UpdateDisplay(course);
        return TRUE;
    }
    PokeathlonLampJump_UpdateJumps(course, lampJump);
    PokeathlonLampJump_CalcTrampolineSurface(&lampJump->trampoline);
    PokeathlonLampJump_SetRestingHeights(lampJump);
    PokeathlonLampJump_CollideMons(course, lampJump);
    PokeathlonLampJump_UpdateLamps(lampJump->lamps);
    PokeathlonLampJump_UpdateDisplay(course);
    *sent = lampJump->hitLamp;
    return FALSE;
}

static void PokeathlonLampJump_UpdateDisplay(PokeathlonCourseData *course) {
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);

    PokeathlonLampJump_UpdateMonSprites(course);
    PokeathlonLampJump_UpdateTimerDisplay(lampJump, lampJump->timer);
    PokeathlonLampJump_UpdateScoreDisplay(lampJump);
    PokeathlonLampJump_UpdatePlayerSprites(course);
    PokeathlonCourse_UpdateTimeUpCountdown(course, lampJump->timer);
    PokeathlonLampJump_Draw3D(lampJump);
}

static void PokeathlonLampJump_HandleTouch(PokeathlonCourseData *course) {
    u8 *data = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);
    u32 selected;

    if (System_GetTouchNew()) {
        PokeathlonCourse_AddMonCounter(course, PokeathlonCourse_GetNetId(course), 3, POKEATHLON_COUNTER_INSTRUCTIONS, 1);
        selected = PokeathlonLampJump_FindTouchedMon(lampJump, gSystem.touchX, gSystem.touchY);
        if (selected < POKEATHLON_TEAM_SIZE) {
            lampJump->selectedMon = selected;
            lampJump->touchStart.x = gSystem.touchX << FX32_SHIFT;
            lampJump->touchStart.y = (gSystem.touchY << FX32_SHIFT) + FX32_CONST(192);
            lampJump->touchStart.z = 0;
        }
    } else if (System_GetTouchHeld()) {
        if (lampJump->selectedMon < POKEATHLON_TEAM_SIZE) {
            if (lampJump->holdFrames < 7) {
                lampJump->holdFrames++;
            } else {
                VecFx32 flick = { 0, 0, 0 };
                PokeathlonLampJump_GetFlick((u8)gSystem.touchX, (u8)gSystem.touchY, &lampJump->touchStart, &flick);
                PokeathlonLampJump_LaunchMon(lampJump, lampJump->selectedMon, &flick);
                lampJump->selectedMon = 3;
                lampJump->holdFrames = 0;
            }
        }
    } else {
        if (lampJump->selectedMon < POKEATHLON_TEAM_SIZE && lampJump->holdFrames < 7) {
            VecFx32 flick = { 0, 0, 0 };
            PokeathlonLampJump_GetFlick((u8)gSystem.touchX, (u8)gSystem.touchY, &lampJump->touchStart, &flick);
            PokeathlonLampJump_LaunchMon(lampJump, lampJump->selectedMon, &flick);
        }
        lampJump->selectedMon = 3;
        lampJump->holdFrames = 0;
    }
    if (PokeathlonCourse_GetNetId(course) == 0) {
        // the host gathers the first word of every player's link block
        PokeathlonLampJumpSyncBlock *gathered = (PokeathlonLampJumpSyncBlock *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_FRAME_OUT);
        PokeathlonLampJumpSyncBlock *hostBlock = (PokeathlonLampJumpSyncBlock *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_INPUTS);
        *hostBlock = *(PokeathlonLampJumpSyncBlock *)PokeathlonCourse_ToBytes(data);
        PokeathlonLampJump_UpdateCpuPlayers(course, lampJump->cpuPlayers);
        {
            u8 values[4];
            int i;

            i = 0;
            data += POKEATHLON_COURSE_DATA_INPUTS;
            for (; i < POKEATHLON_PARTICIPANTS; i++) {
                values[i] = ((PokeathlonLampJumpSyncBlock *)PokeathlonCourse_ToBytes(data))->words[0];
                data += POKEATHLON_COURSE_DATA_SLOT_SIZE;
            }
            for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                gathered->bytes[i] = values[i];
            }
        }
    }
}

static void PokeathlonLampJump_UpdateMonSprites(PokeathlonCourseData *course) {
    int i, x, y;
    PokeathlonLampJump *lampJump = PokeathlonCourse_GetWork(course);
    PokeathlonLampJumpMon *mon;

    for (i = 0, mon = lampJump->mons; i < POKEATHLON_TEAM_SIZE; mon++, i++) {
        mon->drawY = FX32_CONST(288) - lampJump->jumps[i].height * 64;
        mon->drawX = mon->x;
        if (mon->drawX < FX32_CONST(32)) {
            mon->drawX = FX32_CONST(32);
        } else if (mon->drawX > FX32_CONST(223)) {
            mon->drawX = FX32_CONST(223);
        }
        lampJump->monColumns[i] = (u8)((mon->drawX / FX32_ONE) / 2);
        x = mon->drawX / FX32_ONE;
        y = mon->drawY / FX32_ONE;
        PokeathlonCourseObject_SetGroundPosition(mon->sprite, x, y);
        {
            VecFx32 pos = { 0, 0, 0 };
            pos.x = x << FX32_SHIFT;
            pos.y = y << FX32_SHIFT;
            if (PokeathlonCourse_GetPerformance(course, PokeathlonCourse_GetNetId(course), i)->isTall) {
                pos.y -= FX32_CONST(24);
            } else {
                pos.y -= FX32_CONST(16);
            }
            PokeathlonCourseSpritePoolSprite_SetPosition(mon->effectSprite, &pos);
        }
        if (mon->stunned) {
            PokeathlonCourseSpritePoolSprite_Show(mon->effectSprite, TRUE, TRUE);
            PokeathlonCourseMonObject_SetAnimCode(mon->sprite, 20);
            if (!GF_SndCountPlayingSeqOnPlayer(gPokeathlonLampJumpSoundPlayers[i])) {
                PlaySEOnPlayer(SEQ_SE_GS_W146, gPokeathlonLampJumpSoundPlayers[i]);
            }
        } else {
            PokeathlonCourseSpritePoolSprite_Show(mon->effectSprite, TRUE, FALSE);
            PokeathlonCourseMonObject_SetAnimCode(mon->sprite, 0);
            if (lampJump->jumps[i].jumping) {
                PokeathlonCourseMonObject_SetAnimState(mon->sprite, 1);
            } else {
                PokeathlonCourseMonObject_SetAnimState(mon->sprite, 2);
            }
        }
    }
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (lampJump->effectPending[i]) {
            lampJump->effectPending[i] = FALSE;
            PokeathlonCourseSpritePoolSprite_Show(lampJump->effectSprites[i], TRUE, TRUE);
            PokeathlonCourseSpritePoolSprite_SetPosition(lampJump->effectSprites[i], &lampJump->effectPositions[i]);
            PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->effectSprites[i], 9);
        }
    }
}

static void PokeathlonLampJump_UpdatePlayerSprites(PokeathlonCourseData *course) {
    u8 *received;
    PokeathlonLampJump *lampJump;
    int i;

    received = PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    lampJump = PokeathlonCourse_GetWork(course);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (i == PokeathlonCourse_GetNetId(course)) {
            if (lampJump->hitLamp != 0 && !PokeathlonCourseSpritePoolSprite_IsAnimated(lampJump->playerSprites[i])) {
                PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->playerSprites[i], i + 13);
            }
        } else if (received[i] != 0 && !PokeathlonCourseSpritePoolSprite_IsAnimated(lampJump->playerSprites[i])) {
            PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->playerSprites[i], i + 13);
        }
    }
}

static void PokeathlonLampJump_GetFlick(int touchX, int touchY, const VecFx32 *start, VecFx32 *flick) {
    VecFx32 touch;

    touch.x = touchX << FX32_SHIFT;
    touch.y = (touchY << FX32_SHIFT) + FX32_CONST(192);
    touch.z = 0;
    VEC_Subtract(&touch, start, flick);
    if (flick->y > FX32_CONST(112)) {
        flick->y = FX32_CONST(112);
    }
}

static u8 PokeathlonLampJump_FindTouchedMon(PokeathlonLampJump *lampJump, u16 touchX, u16 touchY) {
    fx32 minDistance = PokeathlonCourse_GetTouchRadius() << FX32_SHIFT;
    u8 i;
    u8 count = 0;
    u8 nearest;
    s32 distances[POKEATHLON_TEAM_SIZE];
    u8 inRange[POKEATHLON_TEAM_SIZE];
    int distance;
    s32 x;
    s32 y;

    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        PokeathlonLampJumpMon *mon = &lampJump->mons[i];

        if (mon->stunned != 0) {
            inRange[i] = FALSE;
            distances[i] = 0;
        } else {
            PokeathlonCourseObject_GroundToCenter(mon->sprite, mon->x / FX32_ONE, (FX32_CONST(96) - (lampJump->jumps[i].height << 6)) / FX32_ONE, &x, &y);
            if (PokeathlonCourse_IsInRange(x, y, touchX, touchY, PokeathlonCourse_GetTouchRadius(), &distance)) {
                distances[i] = distance;
                inRange[i] = TRUE;
                count++;
            } else {
                distances[i] = 0;
                inRange[i] = FALSE;
            }
        }
    }
    if (count == 0) {
        return 3;
    }
    nearest = 3;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (inRange[i] && distances[i] < minDistance) {
            nearest = i;
            minDistance = distances[i];
        }
    }
    if (nearest == POKEATHLON_TEAM_SIZE) {
        GF_ASSERT(FALSE);
        return 3;
    }
    return nearest;
}

BOOL PokeathlonLampJump_CheckCollision(const VecFx32 *a, fx32 radiusA, const VecFx32 *b, fx32 radiusB) {
    VecFx32 diff;

    VEC_Subtract(a, b, &diff);
    if (VEC_Mag(&diff) > radiusA + radiusB) {
        return FALSE;
    }
    return TRUE;
}

static void PokeathlonLampJump_LaunchMon(PokeathlonLampJump *lampJump, s32 mon, VecFx32 *flick) {
    PokeathlonLampJumpJump *jump;
    s32 velocity;
    fx32 velocityX;
    s32 *monVelocityX;

    if (flick->y > 0) {
        jump = &lampJump->jumps[mon];
        if (!jump->jumping) {
            velocity = (double)(flick->y / 64) / 2.5;
            velocityX = -flick->x / 4;
            if (velocityX >= 0) {
                if (velocityX > FX32_CONST(10)) {
                    velocityX = FX32_CONST(10);
                }
            } else if (velocityX < -FX32_CONST(10)) {
                velocityX = -FX32_CONST(10);
            }
            monVelocityX = &lampJump->mons[mon].velocityX;
            *monVelocityX = velocityX;
            *monVelocityX = *monVelocityX * lampJump->mons[mon].flickScale / 12;
            jump->velocity = -velocity;
            jump->launchVelocity = -velocity;
            jump->jumping = TRUE;
            PlaySEOnPlayer(SEQ_SE_GS_GUGU, gPokeathlonLampJumpSoundPlayers[mon]);
        }
    }
}

static void PokeathlonLampJump_Init3D(PokeathlonLampJump *lampJump) {
    NNS_G3dInit();
    G3X_InitMtxStack();
    reg_G3_SWAP_BUFFERS = 2;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(FALSE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(FALSE);
    G3X_EdgeMarking(FALSE);
    G3X_SetClearColor(RGB_BLACK, 0, GF_GX_CLEARCOLORDEPTH_MAX, 63, FALSE);
    reg_G3_VIEWPORT = 0xBFFF0000;
    lampJump->camera = Camera_New(lampJump->heapId);
    PokeathlonLampJump_InitCamera(lampJump);
}

static inline void PokeathlonLampJump_GeVtx16(u32 xy, u32 z) {
    u32 args[2];

    args[0] = xy;
    args[1] = z;
    NNS_G3dGeBufferOP_N(G3OP_VTX_16, args, 2);
}

static inline void PokeathlonLampJump_GeColor(u32 rgb) {
    NNS_G3dGeBufferOP_N(G3OP_COLOR, &rgb, 1);
}

// A quad strip from the trampoline's surface down to y -1.5, each column in the next color.
static void PokeathlonLampJump_DrawTrampoline(PokeathlonLampJump *lampJump) {
    VecFx32 scale = sLampJumpTrampolineScale;
    u32 polygonAttr;
    u32 color;
    u32 primitive;
    int i;

    NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE, (const u32 *)&scale, 3);
    polygonAttr = 0x310081;
    NNS_G3dGeBufferOP_N(G3OP_POLYGON_ATTR, &polygonAttr, 1);
    color = GX_RGB(31, 5, 0);
    NNS_G3dGeBufferOP_N(G3OP_COLOR, &color, 1);
    NNS_G3dGlbFlushP();
    primitive = GX_BEGIN_QUAD_STRIP;
    NNS_G3dGeBufferOP_N(G3OP_BEGIN, &primitive, 1);
    gPokeathlonLampJumpTrampolineRed = 0;
    sTrampolineGreen = 10;
    sTrampolineBlue = 20;
    PokeathlonLampJump_GeVtx16(0xE000, 0);
    PokeathlonLampJump_GeVtx16(0xE800E000, 0);
    for (i = 1; i <= LAMP_JUMP_COLUMNS; i++) {
        float x = ((float)i - 64.0) * 4.0 / 128.0;

        PokeathlonLampJump_GeVtx16((u16)(int)(x * 4096.0f) | ((u16)(s16)lampJump->trampoline.surface[i - 1] << 16), 0);
        PokeathlonLampJump_GeVtx16((u16)(int)(x * 4096.0f) | 0xE8000000, 0);
        PokeathlonLampJump_GeColor((u16)(gPokeathlonLampJumpTrampolineRed | (sTrampolineGreen << 5) | (sTrampolineBlue << 10)));
        gPokeathlonLampJumpTrampolineRed = (gPokeathlonLampJumpTrampolineRed + 1) % 31;
        sTrampolineGreen = (sTrampolineGreen + 1) % 31;
        sTrampolineBlue = (sTrampolineBlue + 1) % 31;
    }
    PokeathlonLampJump_GeVtx16(0xE000, 0);
    PokeathlonLampJump_GeVtx16(0xE800E000, 0);
    NNS_G3dGeBufferOP_N(G3OP_END, NULL, 0);
}

void PokeathlonLampJump_Draw3D(PokeathlonLampJump *lampJump) {
    Thunk_G3X_Reset();
    Camera_PushLookAtToNNSGlb();
    PokeathlonLampJump_DrawTrampoline(lampJump);
    RequestSwap3DBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_Z);
}

void PokeathlonLampJump_InitCamera(PokeathlonLampJump *lampJump) {
    VecFx32 up;
    CameraAngle angle;
    VecFx32 offset = sLampJumpCameraOffset;

    lampJump->cameraTarget.x = 0;
    lampJump->cameraTarget.y = 0;
    lampJump->cameraTarget.z = 0;
    angle.x = 0;
    angle.y = 0;
    angle.z = 0;
    Camera_Init_FromTargetDistanceAndAngle(&lampJump->cameraTarget, FX32_CONST(100), &angle, 164, 1, TRUE, lampJump->camera);
    Camera_OffsetLookAtPosAndTarget(&offset, lampJump->camera);
    Camera_SetPerspectiveClippingPlane(FX32_CONST(4), FX32_CONST(256), lampJump->camera);
    up.x = 0;
    up.y = FX32_ONE;
    up.z = 0;
    Camera_SetLookAtCamUp(&up, lampJump->camera);
    Camera_SetStaticPtr(lampJump->camera);
}

// The surface is the lowest of the three dents and the three lines between the Pokemon.
void PokeathlonLampJump_CalcTrampolineSurface(PokeathlonLampJumpTrampoline *trampoline) {
    int i;

    PokeathlonLampJump_CalcLine(trampoline, 0, 0, 1);
    PokeathlonLampJump_CalcLine(trampoline, 1, 1, 2);
    PokeathlonLampJump_CalcLine(trampoline, 2, 2, 0);
    for (i = 0; i < LAMP_JUMP_COLUMNS; i++) {
        trampoline->surface[i] = trampoline->dents[0][i];
        if (trampoline->surface[i] > trampoline->dents[1][i]) {
            trampoline->surface[i] = trampoline->dents[1][i];
        }
        if (trampoline->surface[i] > trampoline->dents[2][i]) {
            trampoline->surface[i] = trampoline->dents[2][i];
        }
        if (trampoline->surface[i] > trampoline->lines[0][i]) {
            trampoline->surface[i] = trampoline->lines[0][i];
        }
        if (trampoline->surface[i] > trampoline->lines[1][i]) {
            trampoline->surface[i] = trampoline->lines[1][i];
        }
        if (trampoline->surface[i] > trampoline->lines[2][i]) {
            trampoline->surface[i] = trampoline->lines[2][i];
        }
    }
}

// The surface from some of the parts only: bit 0 = dent 0 and line 0-1, bit 1 = dent 1 and line 1-2,
// bit 2 = dent 2 and line 2-0.
static void PokeathlonLampJump_CalcPartialSurface(PokeathlonLampJumpTrampoline *trampoline, int parts, s32 *heights) {
    int i = 0;
    int part0 = 1, part1 = 2, part2 = 4;
    part0 &= parts;
    part1 &= parts;
    part2 &= parts;
    for (; i < LAMP_JUMP_COLUMNS; i++) {
        heights[i] = 0;
        if (part0) {
            if (heights[i] > trampoline->dents[0][i]) {
                heights[i] = trampoline->dents[0][i];
            }
            if (heights[i] > trampoline->lines[0][i]) {
                heights[i] = trampoline->lines[0][i];
            }
        }
        if (part1) {
            if (heights[i] > trampoline->dents[1][i]) {
                heights[i] = trampoline->dents[1][i];
            }
            if (heights[i] > trampoline->lines[1][i]) {
                heights[i] = trampoline->lines[1][i];
            }
        }
        if (part2) {
            if (heights[i] > trampoline->dents[2][i]) {
                heights[i] = trampoline->dents[2][i];
            }
            if (heights[i] > trampoline->lines[2][i]) {
                heights[i] = trampoline->lines[2][i];
            }
        }
    }
}

// The cloth between two Pokemon: a straight line between the bottoms of their dents.
static void PokeathlonLampJump_CalcLine(PokeathlonLampJumpTrampoline *trampoline, int line, u8 monA, u8 monB) {
    s32 *left;
    s32 *right;
    u8 *leftMon;
    u8 *rightMon;
    int i;
    s32 start;
    s32 delta;
    s32 span;

    if (trampoline->monColumns[monA] <= trampoline->monColumns[monB]) {
        left = &trampoline->monColumns[monA];
        right = &trampoline->monColumns[monB];
        leftMon = &monA;
        rightMon = &monB;
    } else {
        left = &trampoline->monColumns[monB];
        right = &trampoline->monColumns[monA];
        leftMon = &monB;
        rightMon = &monA;
    }
    for (i = 0; i < LAMP_JUMP_COLUMNS; i++) {
        trampoline->lines[line][i] = 0;
    }
    start = trampoline->dents[*leftMon][*left];
    delta = trampoline->dents[*rightMon][*right] - start;
    span = *right - *left;
    for (i = 0; i < span - 1; i++) {
        trampoline->lines[line][*left + i + 1] = start + delta * (i + 1) / span;
    }
}

// A lamp hit: one more point than the previous lamp of the same jump (up to 5). Returns the points.
static u8 PokeathlonLampJump_ScoreLamp(PokeathlonLampJumpMon *mon) {
    if (mon->combo < 5) {
        mon->combo++;
    }
    mon->score = mon->score + mon->combo;
    if (mon->score > POKEATHLON_SCORE_MAX) {
        mon->score = POKEATHLON_SCORE_MAX;
    }
    return mon->combo;
}

void PokeathlonLampJump_UpdateJumps(PokeathlonCourseData *course, PokeathlonLampJump *lampJump) {
    PokeathlonLampJump *monRow;
    PokeathlonLampJump *jumpRow;
    PokeathlonLampJumpMon *mon;
    u8 participant;
    int i;
    int lamp;
    const u8 *soundPlayer;

    struct {
        s32 screenY;
        s32 screenX;
        s32 radius;
        VecFx32 pos;
    } hit;

    participant = PokeathlonCourse_GetNetId(course);
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        PokeathlonLampJump_UpdateJump(course, lampJump, i);
    }
    i = 0;
    monRow = lampJump;
    jumpRow = lampJump;
    mon = lampJump->mons;
    soundPlayer = gPokeathlonLampJumpSoundPlayers;
    while (i < POKEATHLON_TEAM_SIZE) {
        PokeathlonCourseMonObject *sprite = monRow->mons[0].sprite;
        PokeathlonCourseObject_GroundToCenter(sprite, monRow->mons[0].x / FX32_ONE, (FX32_CONST(288) - (jumpRow->jumps[0].height << 6)) / FX32_ONE, &hit.screenX, &hit.screenY);
        PokeathlonCourseObject_GetCollisionCircle(sprite, hit.screenX << FX32_SHIFT, hit.screenY << FX32_SHIFT, &hit.pos.x, &hit.pos.y, &hit.radius);
        hit.pos.z = 0;
        for (lamp = 0; lamp < LAMP_JUMP_LAMPS; lamp++) {
            if (PokeathlonLampJump_IsLampLit(lampJump->lamps, lamp)) {
                VecFx32 *lampPos = PokeathlonLampJump_GetLampPos(lampJump->lamps, lamp);
                if (PokeathlonLampJump_CheckCollision(&hit.pos, hit.radius << FX32_SHIFT, lampPos, FX32_CONST(8))) {
                    u8 points;
                    PokeathlonLampJump_PutOutLamp(lampJump->lamps, lamp);
                    points = PokeathlonLampJump_ScoreLamp(mon);
                    PokeathlonLampJump_ShowLampPoints(lampJump->lamps, lamp, points);
                    lampJump->hitLamp = TRUE;
                    PlaySEOnPlayer(SEQ_SE_GS_POINT1, *soundPlayer);
                    GF_SndSetTrackPitchByPlayerNo(*soundPlayer, 0xFFFF, sLampJumpLampSoundPitches[points - 1]);
                    PokeathlonCourse_AddMonCounter(course, participant, i, POKEATHLON_COUNTER_POINTS, 1);
                }
            }
        }
        monRow = (PokeathlonLampJump *)((u8 *)monRow + sizeof(PokeathlonLampJumpMon));
        soundPlayer++;
        jumpRow = (PokeathlonLampJump *)((u8 *)jumpRow + sizeof(PokeathlonLampJumpJump));
        mon++;
        i++;
    }
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (lampJump->mons[i].stunned) {
            lampJump->mons[i].stunTimer--;
            if (lampJump->mons[i].stunTimer == 0) {
                lampJump->mons[i].stunTimer = 0;
                lampJump->mons[i].stunned = FALSE;
            }
        }
    }
}

// One Pokemon on the trampoline: pressing it down, being thrown up, flying, landing.
static void PokeathlonLampJump_UpdateJump(PokeathlonCourseData *course, PokeathlonLampJump *lampJump, u8 mon) {
    int heights[128];
    PokeathlonLampJumpJump *jump = &lampJump->jumps[mon];
    int column;
    u8 participant;
    int parts;

    if (!jump->jumping) {
        return;
    }
    participant = PokeathlonCourse_GetNetId(course);
    column = lampJump->monColumns[mon];
    switch (mon) {
    case 0:
        parts = 6;
        break;
    case 1:
        parts = 5;
        break;
    case 2:
        parts = 3;
        break;
    default:
        GF_ASSERT(FALSE);
        return;
    }
    // the trampoline without this Pokemon's own dent and the line that starts at it
    PokeathlonLampJump_CalcPartialSurface(&lampJump->trampoline, parts, heights);
    if (jump->airborne) {
        if (jump->launchVelocity <= 0) {
            GF_ASSERT(FALSE);
            jump->airborne = FALSE;
            jump->height = heights[column];
            jump->launchVelocity = 0;
            jump->jumping = FALSE;
            jump->velocity = 0;
            lampJump->mons[mon].bounceReady = TRUE;
            PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
            return;
        }
        jump->height += jump->velocity;
        if (lampJump->mons[mon].velocityX) {
            PokeathlonLampJump_MoveSideways(&lampJump->mons[mon], jump);
        }
        if (jump->height > heights[column]) {
            jump->velocity = jump->velocity - 128.0;
            if (-jump->velocity > jump->launchVelocity) {
                jump->velocity = -jump->launchVelocity;
            }
        } else if (jump->height <= heights[column]) {
            if (jump->velocity == 0) {
                jump->airborne = FALSE;
                jump->height = heights[column];
                jump->launchVelocity = 0;
                jump->jumping = FALSE;
                PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
            } else if (jump->velocity < 0) {
                jump->airborne = FALSE;
                PokeathlonLampJump_SlowDownSideways(&lampJump->mons[mon]);
                if ((double)jump->velocity > -128.0) {
                    jump->velocity = -128;
                }
                jump->launchVelocity = jump->velocity;
            } else {
                jump->airborne = FALSE;
                jump->height = heights[column];
                jump->launchVelocity = 0;
                jump->jumping = FALSE;
                jump->velocity = 0;
                PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
            }
        }
    } else {
        GF_ASSERT(jump->launchVelocity <= 0);
        jump->height += jump->velocity;
        if ((double)jump->height < -6144.0) {
            jump->height = -6144;
            jump->velocity = 0;
        }
        if (jump->height >= heights[column]) {
            // back at the surface: bounce off
            PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
            if (lampJump->mons[mon].bounceReady) {
                jump->velocity = lampJump->mons[mon].bounce * jump->velocity / 12;
            }
            if (jump->velocity > 2200) {
                jump->velocity = 2200;
            }
            jump->velocity = jump->velocity * 9 / 10;
            if (jump->velocity == 0) {
                if (lampJump->mons[mon].bounceReady) {
                    PlaySEOnPlayer(SEQ_SE_DP_BOX03, gPokeathlonLampJumpSoundPlayers[3]);
                }
                jump->airborne = FALSE;
                jump->height = heights[column];
                jump->launchVelocity = 0;
                jump->jumping = FALSE;
                PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
            } else if (jump->velocity > 0) {
                if ((double)jump->velocity <= 1408.0 && !lampJump->mons[mon].bounceReady) {
                    jump->airborne = FALSE;
                    jump->height = heights[column];
                    jump->launchVelocity = 0;
                    jump->velocity = 0;
                    jump->jumping = FALSE;
                    PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
                } else {
                    jump->airborne = TRUE;
                    jump->launchVelocity = jump->velocity;
                    lampJump->mons[mon].bounceReady = FALSE;
                    PlaySEOnPlayer(SEQ_SE_DP_DANSA5, gPokeathlonLampJumpSoundPlayers[3]);
                    PokeathlonCourse_AddMonCounter(course, participant, mon, POKEATHLON_COUNTER_JUMPS, 1);
                }
            }
        } else if (jump->height < heights[column]) {
            if (jump->velocity < 0) {
                jump->velocity += 819.2;
                if (jump->velocity >= 0) {
                    jump->velocity = 0;
                }
            } else if (jump->velocity >= 0) {
                jump->velocity += 341.3333333333333;
                if (jump->launchVelocity >= 0) {
                    GF_ASSERT(FALSE);
                    jump->airborne = FALSE;
                    jump->height = heights[column];
                    jump->launchVelocity = 0;
                    jump->jumping = FALSE;
                    jump->velocity = 0;
                    PokeathlonLampJump_SetDent(lampJump, mon, column, 0);
                    return;
                }
                if (jump->velocity > -jump->launchVelocity) {
                    jump->velocity = -jump->launchVelocity;
                }
            }
        }
    }
    if (!jump->airborne || !jump->jumping || !jump->velocity) {
        lampJump->mons[mon].combo = 0;
    }
    if (!jump->airborne && jump->jumping) {
        PokeathlonLampJump_SetDent(lampJump, mon, column, jump->height);
    }
    if (!jump->jumping) {
        lampJump->mons[mon].bounceReady = TRUE;
    }
}

static void PokeathlonLampJump_MoveSideways(PokeathlonLampJumpMon *mon, PokeathlonLampJumpJump *jump) {
    fx32 x;
    if (jump->height > 0) {
        x = mon->drawX + mon->velocityX;
        mon->x = x;
        if (x < FX32_CONST(32)) {
            mon->x = FX32_CONST(32);
        } else if (x > FX32_CONST(223)) {
            mon->x = FX32_CONST(223);
        }
    }
}

// The dent a Pokemon makes at a column: straight lines from both edges down to `depth`.
static void PokeathlonLampJump_CalcDent(int column, int depth, s32 *dent) {
    int negDepth = -depth, right = 127 - column, i;
    s32 *dest;
    i = 0;
    if (column > 0) {
        dest = dent;
        do {
            int x = (u8)(i + 1);
            *dest++ = -(negDepth * x / (column + 1));
            i++;
        } while (i < column);
    }
    for (i = 0; i < right; i++) {
        dent[(u8)(column + 1 + i)] = -((u8)(right - i) * negDepth / (right + 1));
    }
}

// A Pokemon that is not jumping rests on the surface.
void PokeathlonLampJump_SetRestingHeights(PokeathlonLampJump *lampJump) {
    int i;
    PokeathlonLampJumpTrampoline *trampoline;
    PokeathlonLampJumpJump *jumps;
    trampoline = &lampJump->trampoline;
    jumps = lampJump->jumps;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (!jumps[i].jumping) {
            jumps[i].height = trampoline->surface[trampoline->monColumns[i]];
        }
    }
}

static void PokeathlonLampJump_SetDent(PokeathlonLampJump *lampJump, int mon, u8 column, fx32 depth) {
    int i;
    for (i = 0; i < LAMP_JUMP_COLUMNS; i++) {
        lampJump->trampoline.dents[mon][i] = 0;
    }
    lampJump->trampoline.dents[mon][column] = depth;
    PokeathlonLampJump_CalcDent(column, lampJump->trampoline.dents[mon][column], lampJump->trampoline.dents[mon]);
}

void PokeathlonLampJump_LoadSpriteResources(PokeathlonCourseSpritePool *scene) {
    PokeathlonCourseSpritePool_LoadChar(scene, NARC_a_1_6_8, 3, 101, NNS_G2D_VRAM_TYPE_2DBOTH);
    PokeathlonCourseSpritePool_LoadPltt(scene, NARC_a_1_6_8, 0, 101, NNS_G2D_VRAM_TYPE_2DBOTH, 4);
    PokeathlonCourseSpritePool_LoadCell(scene, NARC_a_1_6_8, 2, 101);
    PokeathlonCourseSpritePool_LoadAnim(scene, NARC_a_1_6_8, 1, 101);
}

void PokeathlonLampJump_CreateSprites(PokeathlonLampJump *lampJump, PokeathlonCourseSpritePool *scene) {
    int i;
    int j;
    VecFx32 pos;

    PokeathlonLampJump_CreateLampSprites(lampJump->lamps, scene, 2);
    lampJump->timerLabel = PokeathlonCourseSpritePool_CreateAndTake(scene, 1, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 3);
    PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->timerLabel, 12);
    PokeathlonCourseSpritePoolSprite_Show(lampJump->timerLabel, TRUE, TRUE);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        lampJump->playerSprites[i] = PokeathlonCourseSpritePool_CreateAndTake(scene, 1, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 4);
        PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->playerSprites[i], 13 + i);
        PokeathlonCourseSpritePoolSprite_Show(lampJump->playerSprites[i], TRUE, TRUE);
    }
    for (i = 0; i < 4; i++) {
        lampJump->mons[i].effectSprite = PokeathlonCourseSpritePool_CreateAndTake(scene, 1, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 7);
        PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->mons[i].effectSprite, 11);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(lampJump->mons[i].effectSprite, 9);
    }
    for (i = 0; i < 4; i++) {
        lampJump->effectSprites[i] = PokeathlonCourseSpritePool_CreateAndTake(scene, 1, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 8);
        PokeathlonCourseSpritePoolSprite_SetAnim(lampJump->effectSprites[i], 9);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(lampJump->effectSprites[i], 6);
    }
    for (j = 0; j < 2; j++) {
        SpriteList *spriteList = PokeathlonCourseSpritePool_GetSpriteList(scene);
        lampJump->timerDigits[j] = PokeathlonCourse_CreateTimerDigitSpriteAlt(lampJump->spriteResources, spriteList, 1, lampJump->heapId);
        Sprite_SetDrawFlag(lampJump->timerDigits[j], TRUE);
        pos.x = sLampJumpTimerDigitX[j] * FX32_ONE;
        pos.y = FX32_CONST(8);
        pos.z = 0;
        Sprite_SetMatrix(lampJump->timerDigits[j], &pos);
        Sprite_SetAnimCtrlSeq(lampJump->timerDigits[j], sLampJumpTimerDigitAnims[j]);
    }
}

// The lamps, and the player markers: this player's first, the others below each other.
void PokeathlonLampJump_PlaceSprites(PokeathlonLampJump *lampJump, u8 self) {
    VecFx32 pos;
    VecFx32 ownPos;
    VecFx32 otherPos;
    VecFx32 firstOtherPos;
    int i;
    u8 otherCount;

    PokeathlonLampJump_PlaceLamps(lampJump->lamps);
    pos = sLampJumpTimerLabelPos;
    PokeathlonCourseSpritePoolSprite_SetPosition(lampJump->timerLabel, &pos);
    ownPos = sLampJumpOwnPlayerPos;
    PokeathlonCourseSpritePoolSprite_SetPosition(lampJump->playerSprites[self], &ownPos);
    firstOtherPos = sLampJumpFirstOtherPlayerPos;
    otherCount = 0;
    for (i = 0; i < 4; i++) {
        otherPos = firstOtherPos;
        if (i != self) {
            otherPos.y += otherCount << 16;
            PokeathlonCourseSpritePoolSprite_SetPosition(lampJump->playerSprites[i], &otherPos);
            otherCount++;
        }
    }
}

void PokeathlonLampJump_UpdateScoreDisplay(PokeathlonLampJump *lampJump) {
    u16 total = 0;
    int i;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        total = total + lampJump->mons[i].score;
    }
    if (total > POKEATHLON_SCORE_MAX) {
        total = POKEATHLON_SCORE_MAX;
    }
    PokeathlonLampJump_PrintScore(lampJump, total);
}

// Three digits of 4x8 tiles from the digit sheet in the BG2 screen (5 digits per row).
static void PokeathlonLampJump_PrintScore(PokeathlonLampJump *lampJump, int score) {
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
        CopyRectToBgTilemapRect(lampJump->bgConfig, GF_BG_LYR_SUB_0, 1 + i * 4, 0, 4, 8, lampJump->bg2Screen->rawData, x[i], y[i], 20, 16);
    }
    ScheduleBgTilemapBufferTransfer(lampJump->bgConfig, GF_BG_LYR_SUB_0);
}

// Seconds left, two digit sprites.
void PokeathlonLampJump_UpdateTimerDisplay(PokeathlonLampJump *lampJump, u16 frames) {
    u8 seconds = frames / 30;
    Sprite_SetAnimCtrlSeq(lampJump->timerDigits[0], (u8)(seconds / 10) + 1);
    Sprite_SetAnimCtrlSeq(lampJump->timerDigits[1], (u8)(seconds % 10) + 1);
}

// Window 0: this player's name; windows 1-3: the others.
void PokeathlonLampJump_PrintPlayerNames(PokeathlonCourseData *course, PokeathlonLampJump *lampJump) {
    u8 i;
    Window *window;
    u8 self;
    String *name;
    u8 line;
    u8 participant;

    for (i = 0; i < 5; i++) {
        FillWindowPixelBuffer(&lampJump->windows[i], 0);
    }
    self = PokeathlonCourse_GetNetId(course);
    name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(course, self), lampJump->heapId);
    AddTextPrinterParameterizedWithColor(&lampJump->windows[0], 0, name, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(name);
    line = 1;
    participant = 0;
    window = &lampJump->windows[0];
    for (; participant < POKEATHLON_PARTICIPANTS; participant++) {
        if (participant != self) {
            name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(course, participant), lampJump->heapId);
            AddTextPrinterParameterizedWithColor(window + line, 0, name, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
            String_Delete(name);
            line++;
        }
    }
    for (i = 0; i < 5; i++) {
        CopyWindowToVram(&lampJump->windows[i]);
    }
}

void PokeathlonLampJump_InitWindows(PokeathlonLampJump *lampJump) {
    u8 i;
    for (i = 0; i < 5; i++) {
        AddWindow(lampJump->bgConfig, &lampJump->windows[i], &sLampJumpWindowTemplates[i]);
    }
    BG_FillCharDataRange(lampJump->bgConfig, GF_BG_LYR_SUB_2, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_15_OFFSET, lampJump->heapId);
    BG_FillCharDataRange(lampJump->bgConfig, GF_BG_LYR_MAIN_3, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, lampJump->heapId);
}

// Window 4: "Pokemon Total: {X} Points".
void PokeathlonLampJump_PrintTotal(PokeathlonLampJump *lampJump, u16 score) {
    MsgData *msgData;
    MessageFormat *messageFormat;
    String *string;
    FillWindowPixelBuffer(&lampJump->windows[4], 0);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, lampJump->heapId);
    messageFormat = MessageFormat_New(lampJump->heapId);
    BufferIntegerAsString(messageFormat, 0, score, 3, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(messageFormat, msgData, msg_0309_00161, lampJump->heapId);
    AddTextPrinterParameterizedWithColor(&lampJump->windows[4], 4, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    MessageFormat_Delete(messageFormat);
    DestroyMsgData(msgData);
    CopyWindowToVram(&lampJump->windows[4]);
}

static void PokeathlonLampJump_SlowDownSideways(PokeathlonLampJumpMon *mon) {
    fx32 velocityX = mon->velocityX;
    if (velocityX == 0) {
        return;
    }
    if (velocityX > 0) {
        velocityX -= FX32_CONST(2);
        mon->velocityX = velocityX;
        if (velocityX < 0) {
            mon->velocityX = 0;
        }
    } else if (velocityX < 0) {
        velocityX += FX32_CONST(2);
        mon->velocityX = velocityX;
        if (velocityX > 0) {
            mon->velocityX = 0;
        }
    }
}

// Bounce, stun time and flick scale from the Pokemon's Skill, Stamina and Jump.
void PokeathlonLampJump_SetMonParams(PokeathlonCourseData *course, PokeathlonLampJumpMonParams *params, u8 member, PokeathlonLampJumpMon *mon) {
    u8 self = PokeathlonCourse_GetNetId(course);
    u8 *stats = PokeathlonCourse_GetMonStats(course, self, member);
    mon->bounce = params->acceleration[stats[2]];
    mon->stunFrames = params->velocity[stats[3]];
    mon->flickScale = params->scale[stats[4]];
}

// Two Pokemon that touch: both are stunned; in the air they swap their speeds, else they are pushed apart.
BOOL PokeathlonLampJump_CollideMons(PokeathlonCourseData *course, PokeathlonLampJump *lampJump) {
    VecFx32 posA;
    VecFx32 posB;
    int radiusA, radiusB, x, y;
    int i, j;
    PokeathlonCourseMonObject *spriteA, *spriteB;
    u8 participant;
    PokeathlonLampJumpJump *jumpA;
    PokeathlonLampJumpMon *monA = &lampJump->mons[0];

    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++, monA++) {
        jumpA = &lampJump->jumps[i];
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            PokeathlonLampJumpMon *monB = &lampJump->mons[j];
            PokeathlonLampJumpJump *jumpB = &lampJump->jumps[j];
            if (i == j) {
                continue;
            }
            participant = PokeathlonCourse_GetNetId(course);
            spriteA = monA->sprite;
            spriteB = monB->sprite;
            PokeathlonCourseObject_GroundToCenter(spriteA, monA->x / FX32_ONE, (FX32_CONST(288) - (jumpA->height << 6)) / FX32_ONE, &x, &y);
            PokeathlonCourseObject_GetCollisionCircle(spriteA, x << FX32_SHIFT, y << FX32_SHIFT, &posA.x, &posA.y, &radiusA);
            posA.z = 0;
            PokeathlonCourseObject_GroundToCenter(spriteB, monB->x / FX32_ONE, (FX32_CONST(288) - (jumpB->height << 6)) / FX32_ONE, &x, &y);
            PokeathlonCourseObject_GetCollisionCircle(spriteB, x << FX32_SHIFT, y << FX32_SHIFT, &posB.x, &posB.y, &radiusB);
            posB.z = 0;
            if (!PokeathlonLampJump_CheckCollision(&posA, radiusA << FX32_SHIFT, &posB, radiusB << FX32_SHIFT)) {
                monA->colliding[j] = FALSE;
                monB->colliding[i] = FALSE;
                continue;
            }
            if (monB->colliding[i]) {
                continue;
            }
            monA->stunned = TRUE;
            monB->stunned = TRUE;
            monA->stunTimer = (30 * monA->stunFrames) / 30;
            monB->stunTimer = (30 * monB->stunFrames) / 30;
            {
                VecFx32 effectPos = { 0, 0, 0 };
                VEC_Subtract(&posB, &posA, &effectPos);
                VEC_Normalize(&effectPos, &effectPos);
                VEC_MultAdd(radiusA << FX32_SHIFT, &effectPos, &posA, &effectPos);
                lampJump->effectPositions[lampJump->nextEffect] = effectPos;
            }
            lampJump->effectPending[lampJump->nextEffect] = TRUE;
            lampJump->nextEffect = (lampJump->nextEffect + 1) % 3;
            PlaySEOnPlayer(SEQ_SE_GS_THLON06, gPokeathlonLampJumpSoundPlayers[3]);
            PokeathlonCourse_AddMonCounter(course, participant, i, POKEATHLON_COUNTER_TACKLES, 1);
            PokeathlonCourse_AddMonCounter(course, participant, j, POKEATHLON_COUNTER_TACKLES, 1);
            PokeathlonCourse_AddMonCounter(course, participant, i, POKEATHLON_COUNTER_FAILURES, 1);
            PokeathlonCourse_AddMonCounter(course, participant, j, POKEATHLON_COUNTER_FAILURES, 1);
            if (jumpA->airborne && jumpB->airborne && jumpA->height > 0 && jumpB->height > 0) {
                int tmp;
                if (monA->colliding[j] || monB->colliding[i]) {
                    continue;
                }
                monA->colliding[j] = TRUE;
                monB->colliding[i] = TRUE;
                tmp = jumpB->velocity;
                jumpB->velocity = jumpA->velocity;
                jumpA->velocity = tmp;
                tmp = monB->velocityX;
                monB->velocityX = monA->velocityX;
                monA->velocityX = tmp;
                if (jumpA->velocity < 0) {
                    jumpA->velocity = 0;
                }
                if (jumpB->velocity < 0) {
                    jumpB->velocity = 0;
                }
            } else {
                if (monA->x <= monB->x) {
                    monA->x -= FX32_CONST(16);
                    monB->x += FX32_CONST(16);
                } else {
                    monA->x += FX32_CONST(16);
                    monB->x -= FX32_CONST(16);
                }
                if (monA->x < FX32_CONST(32)) {
                    monA->x = FX32_CONST(32);
                } else if (monA->x > FX32_CONST(223)) {
                    monA->x = FX32_CONST(223);
                }
                if (monB->x < FX32_CONST(32)) {
                    monB->x = FX32_CONST(32);
                } else if (monB->x > FX32_CONST(223)) {
                    monB->x = FX32_CONST(223);
                }
            }
        }
    }
    return FALSE;
}

PokeathlonLampJumpLamps *PokeathlonLampJump_NewLamps(enum HeapID heapId) {
    PokeathlonLampJumpLamps *lamps = Heap_Alloc(heapId, sizeof(PokeathlonLampJumpLamps));
    MI_CpuFill8(lamps, 0, sizeof(PokeathlonLampJumpLamps));
    lamps->relightTimer = 0;
    return lamps;
}

void PokeathlonLampJump_FreeLamps(PokeathlonLampJumpLamps *lamps) {
    Heap_Free(lamps);
}

static void PokeathlonLampJump_CreateLampSprites(PokeathlonLampJumpLamps *lamps, PokeathlonCourseSpritePool *scene, int priority) {
    int i;
    PokeathlonLampJumpLamp *lamp = lamps->lamps;
    for (i = 0; i < LAMP_JUMP_LAMPS; i++, lamp++) {
        lamp->sprite = PokeathlonCourseSpritePool_CreateAndTake(scene, priority, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 2);
        PokeathlonCourseSpritePoolSprite_Show(lamp->sprite, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_SetAnim(lamp->sprite, 8);
        lamp->pointsSprite = PokeathlonCourseSpritePool_CreateAndTake(scene, priority, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 5);
        lamp->hitSprite = PokeathlonCourseSpritePool_CreateAndTake(scene, priority, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 6);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(lamp->sprite, 20);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(lamp->pointsSprite, 7);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(lamp->hitSprite, 8);
    }
}

static void PokeathlonLampJump_PlaceLamps(PokeathlonLampJumpLamps *lamps) {
    int i;
    VecFx32 pos;
    const u16 *xy = sLampJumpLampPositions[0];
    PokeathlonLampJumpLamp *lamp = lamps->lamps;
    for (i = 0; i < LAMP_JUMP_LAMPS; i++, xy += 2, lamp++) {
        pos.x = xy[0] << 15;
        pos.y = xy[1] << 15;
        pos.z = 0;
        PokeathlonCourseSpritePoolSprite_SetPosition(lamp->sprite, &pos);
        PokeathlonCourseSpritePoolSprite_SetPosition(lamp->pointsSprite, &pos);
        PokeathlonCourseSpritePoolSprite_SetPosition(lamp->hitSprite, &pos);
        lamp->pos = pos;
    }
}

// Every 240 frames the lamps that are out are lit again.
void PokeathlonLampJump_UpdateLamps(PokeathlonLampJumpLamps *lamps) {
    int timer = lamps->relightTimer;
    if (timer == 0) {
        PokeathlonLampJump_LightLamps(lamps);
        lamps->relightTimer = 240;
    } else {
        lamps->relightTimer = timer - 1;
    }
}

static void PokeathlonLampJump_PutOutLamp(PokeathlonLampJumpLamps *lamps, u8 index) {
    lamps->lamps[index].lit = FALSE;
    PokeathlonCourseSpritePoolSprite_SetAnim(lamps->lamps[index].sprite, 8);
}

static VecFx32 *PokeathlonLampJump_GetLampPos(PokeathlonLampJumpLamps *lamps, u8 index) {
    return &lamps->lamps[index].pos;
}

static BOOL PokeathlonLampJump_IsLampLit(PokeathlonLampJumpLamps *lamps, u8 index) {
    return lamps->lamps[index].lit;
}

static void PokeathlonLampJump_ShowLampPoints(PokeathlonLampJumpLamps *lamps, u8 index, u8 points) {
    PokeathlonCourseSpritePoolSprite_SetAnim(lamps->lamps[index].hitSprite, 10);
    PokeathlonCourseSpritePoolSprite_Show(lamps->lamps[index].hitSprite, TRUE, TRUE);
    PokeathlonCourseSpritePoolSprite_SetAnim(lamps->lamps[index].pointsSprite, points);
    PokeathlonCourseSpritePoolSprite_Show(lamps->lamps[index].pointsSprite, TRUE, TRUE);
}

// Lights up to 25 of the lamps that are out, picked at random.
static void PokeathlonLampJump_LightLamps(PokeathlonLampJumpLamps *lamps) {
    struct {
        PokeathlonLampJumpLamp *lamps[LAMP_JUMP_LAMPS];
    } unlit;

    struct {
        int count;
        PokeathlonLampJumpLamp **end;
    } list;

    int i;
    PokeathlonLampJumpLamp *lamp = lamps->lamps;

    list.count = 0;
    for (i = 0; i < LAMP_JUMP_LAMPS; i++, lamp++) {
        if (!lamp->lit) {
            unlit.lamps[list.count++] = lamp;
        }
    }
    i = 0;
    list.end = unlit.lamps + list.count;
    for (; i < 25; i++) {
        u8 index;
        if (list.count <= 0) {
            break;
        }
        index = LCRandom() % list.count;
        unlit.lamps[index]->lit = TRUE;
        PokeathlonCourseSpritePoolSprite_SetAnim(unlit.lamps[index]->sprite, 7);
        unlit.lamps[index] = list.end[-1];
        list.end--;
        list.count--;
    }
}

PokeathlonLampJumpCpuPlayers *PokeathlonLampJump_NewCpuPlayers(enum HeapID heapId, int count, int unused, u8 *dataCopy, PokeathlonCourseData *course) {
    int i;
    int j;
    PokeathlonLampJumpCpuPlayers *cpu = Heap_Alloc(heapId, sizeof(PokeathlonLampJumpCpuPlayers));
    MI_CpuFill8(cpu, 0, sizeof(PokeathlonLampJumpCpuPlayers));
    cpu->count = count;
    cpu->unk21 = 4 - count;
    cpu->first = cpu->unk21;
    cpu->interval = 3;
    cpu->dataCopy = dataCopy;
    for (i = 0; i < cpu->count; i++) {
        u8 participant = cpu->first + i;
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            u8 *stats = PokeathlonCourse_GetMonStats(course, participant, j);
            cpu->skill[participant] += stats[2];
            cpu->jump[participant] += stats[4];
            cpu->skillUpTo[participant][j] = cpu->skill[participant];
        }
    }
    return cpu;
}

void PokeathlonLampJump_FreeCpuPlayers(PokeathlonLampJumpCpuPlayers *cpu) {
    Heap_Free(cpu);
}

// Every `interval` frames the participants without a player get a turn, one per frame.
int PokeathlonLampJump_UpdateCpuPlayers(PokeathlonCourseData *course, PokeathlonLampJumpCpuPlayers *cpu) {
    int participant;
    int result = 4;

    if (cpu->unk21 == 4) {
        return 0;
    }
    cpu->tick++;
    for (participant = cpu->first; participant < POKEATHLON_PARTICIPANTS; participant++) {
        *(u32 *)PokeathlonCourse_ToBytes(cpu->dataCopy + POKEATHLON_COURSE_DATA_INPUTS + participant * POKEATHLON_COURSE_DATA_SLOT_SIZE) = FALSE;
    }
    if (cpu->tick >= cpu->interval) {
        cpu->active = TRUE;
        cpu->tick = 0;
    }
    if (cpu->active) {
        participant = cpu->first + cpu->current;
        GF_ASSERT(participant >= cpu->first);
        if (participant < cpu->first) {
            return 4;
        }
        PokeathlonLampJump_UpdateCpuPlayer(course, cpu, participant);
        result = (u8)participant;
        cpu->current++;
        if (cpu->current >= cpu->count) {
            cpu->current = 0;
            cpu->active = FALSE;
        }
    }
    return result;
}

// Hits a lamp if Jump + 2 * Skill + a random 0-100 reaches 100; the Pokemon is picked by Skill.
static void PokeathlonLampJump_UpdateCpuPlayer(PokeathlonCourseData *course, PokeathlonLampJumpCpuPlayers *cpu, u8 participant) {
    int value;
    u8 roll;
    u8 i;
    u32 *lampHit = (u32 *)PokeathlonCourse_ToBytes(cpu->dataCopy + POKEATHLON_COURSE_DATA_INPUTS + participant * POKEATHLON_COURSE_DATA_SLOT_SIZE);

    if (cpu->skill[participant] == 0) {
        value = 0;
    } else {
        value = cpu->jump[participant] + cpu->skill[participant] * 2 + LCRandom() % 101;
    }
    if (value >= 100) {
        *lampHit = TRUE;
        roll = LCRandom() % cpu->skill[participant];
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            if (roll < cpu->skillUpTo[participant][i]) {
                PokeathlonCourse_AddMonCounter(course, participant, i, POKEATHLON_COUNTER_POINTS, 1);
                break;
            }
        }
        GF_ASSERT(i < POKEATHLON_TEAM_SIZE);
    }
}
