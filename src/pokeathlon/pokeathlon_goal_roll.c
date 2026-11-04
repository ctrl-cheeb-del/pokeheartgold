#include "pokeathlon/pokeathlon_goal_roll.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"

#include "assert.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "system.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"

enum {
    GOAL_ROLL_STATE_PLAY,
    GOAL_ROLL_STATE_FINISH,
};

enum PokeathlonGoalRollInitState {
    GOAL_ROLL_INIT_CREATE,
    GOAL_ROLL_INIT_CREATE_DISPLAY,
    GOAL_ROLL_INIT_CREATE_SPRITES,
    GOAL_ROLL_INIT_LOAD_MONS,
    GOAL_ROLL_INIT_PLACE_MONS,
    GOAL_ROLL_INIT_WAIT_FADE_IN,
};

extern const PokeathlonGoalRollPaletteData gPokeathlonGoalRollPaletteData;

typedef struct PokeathlonGoalRollVec4 {
    VecFx32 positions[POKEATHLON_PARTICIPANTS];
} PokeathlonGoalRollVec4;

typedef struct PokeathlonGoalRollInitWork {
    PokeathlonCoursePoint ownCoords[POKEATHLON_TEAM_SIZE];
    VecFx32 goalPositions[POKEATHLON_PARTICIPANTS];
    VecFx32 ballPosition;
    PokeathlonCourseSpritePoolTemplate poolConfig;
    ObjCharTransferTemplate charTransfer;
    PokeathlonGoalRollMonParams monParams; // NARC a/1/7/0 member 8
    PokeathlonCourseMonGfxTemplate objectsInfo;
    PokeathlonCourseMonInfo views[POKEATHLON_MONS];
} PokeathlonGoalRollInitWork;

#define GOAL_CURSOR_NEXT(cursor) ((PokeathlonGoalRoll *)((u32 *)(cursor) + 1))

static void PokeathlonGoalRoll_SetGfxBanks(void);
static void PokeathlonGoalRoll_InitBgs(BgConfig *bgConfig);
static void PokeathlonGoalRoll_LoadBgGfx(PokeathlonGoalRoll *goalRoll);
static BOOL PokeathlonGoalRoll_HandleInput(PokeathlonCourseData *course);
static void PokeathlonGoalRoll_HostUpdate(PokeathlonCourseData *course);
static void PokeathlonGoalRoll_PackFrame(PokeathlonGoalRoll *goalRoll, PokeathlonGoalRollFramePacket *out);
static void PokeathlonGoalRoll_ApplyFrame(PokeathlonCourseData *course);
static void PokeathlonGoalRoll_ApplyFrameScore(PokeathlonCourseData *course);

static inline void PokeathlonGoalRoll_SetMonCollision(PokeathlonCourseData *course, PokeathlonCourseMonObjects *monObjects, s32 index, const PokeathlonCourseCollision *collisions) {
    PokeathlonCourseMonObject *object;
    int participant;
    int member;
    int size;
    object = PokeathlonCourseMonObjects_Get(monObjects, index);
    PokeathlonCourseMonObject_SetDrawFlag(object, 1);
    participant = index / POKEATHLON_TEAM_SIZE;
    member = index % POKEATHLON_TEAM_SIZE;
    size = PokeathlonCourse_GetCollisionSizeClass(PokeathlonCourse_GetPerformance(course, participant, member));
    PokeathlonCourseObject_SetCollision(object, collisions[size - 1].offsetY, collisions[size - 1].radius);
}

typedef PokeathlonGoalRollCpu *(*PokeathlonGoalRollCpuNewFunc)(u32 heapId, int cpuCount, int mode);

BOOL PokeathlonGoalRoll_Init(PokeathlonCourseData *course) {
    PokeathlonCourseCollision collisions[POKEATHLON_SIZE_CLASSES];
    PokeathlonCourseSpritePoolSprite *sprite;
    int j;
    PokeathlonCourseMonGfx *image;
    int member;
    int i;
    u16 goalPalettes[POKEATHLON_PARTICIPANTS];

    struct {
        int y;
        int x;
    } screen;

    struct {
        VecFx32 post;
        VecFx32 corner;
        VecFx32 normal;
    } wall;

    int own;
    int x;
    u32 y;
    int participant;
    PokeathlonGoalRollMon(*team)[POKEATHLON_TEAM_SIZE];
    PokeathlonGoalRollInitWork work;
    PokeathlonGoalRoll *goal;
    const VecFx32 *goalPosition;
    s32 flip;
    u16 *goalPalette;
    int mode;
    u32 markAnim;
    const VecFx32 *markPosition;
    const VecFx32 *labelPosition;
    int row;
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);

    switch (PokeathlonCourse_GetEventInitState(course)) {
    case GOAL_ROLL_INIT_CREATE: {
        u8 participant;
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_147, 0x50000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
        PokeathlonGoalRoll_SetGfxBanks();
        goalRoll = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonGoalRoll));
        MI_CpuFill8(goalRoll, 0, sizeof(PokeathlonGoalRoll));
        goalRoll->sortWork = Heap_Alloc(HEAP_ID_147, 40);
        MI_CpuFill8(goalRoll->sortWork, 0, 40);
        goalRoll->bgConfig = BgConfig_Alloc(HEAP_ID_147);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        work.charTransfer.maxTasks = 133;
        work.charTransfer.sizeMain = 0x40000;
        work.charTransfer.sizeSub = 0x4000;
        work.charTransfer.heapID = HEAP_ID_147;
        PokeathlonCourse_InitObjTransfer(&work.charTransfer, 16, HEAP_ID_147, (GXOBJVRamModeChar)0x300010, (GXOBJVRamModeChar)16);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 1, 126, 0, 32, HEAP_ID_147);
        goalRoll->heapId = HEAP_ID_147;
        FontID_Alloc(4, HEAP_ID_147);
        PokeathlonGoalRoll_InitBgs(goalRoll->bgConfig);
        PokeathlonGoalRoll_InitWindows(goalRoll);
        PokeathlonGoalRoll_LoadStrings(course);
        for (participant = 0; participant < POKEATHLON_PARTICIPANTS; participant++) {
            PokeathlonGoalRoll_PrintPlate(goalRoll, participant, 0);
        }
        PokeathlonGoalRoll_CreatePlateTasks(goalRoll);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case GOAL_ROLL_INIT_CREATE_DISPLAY: {
        int count;
        goalRoll->display = PokeathlonGoalRollDisplay_New(goalRoll->heapId, goalRoll->bgConfig, course);
        count = PokeathlonCourse_GetParticipantCount(course);
        mode = PokeathlonCourse_GetMode(course);
        goalRoll->cpu = ((PokeathlonGoalRollCpuNewFunc)PokeathlonGoalRollCpu_New)(goalRoll->heapId, 4 - count, mode);
        goalRoll->resources = PokeathlonCourseSprites_CreateResources(goalRoll->heapId, 2735, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourse_InitMarkers(course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case GOAL_ROLL_INIT_CREATE_SPRITES: {
        work.poolConfig = gPokeathlonGoalRollSpritePoolConfig;
        goalRoll->spritePool = PokeathlonCourseSpritePool_New(goalRoll->heapId, &work.poolConfig);
        PokeathlonCourseSpritePool_SetSurfaceCoords(goalRoll->spritePool, 0, 0, 0, FX32_CONST(512));
        goalRoll->monObjects = PokeathlonCourseMonObjects_Create(goalRoll->heapId, 12, 8, goalRoll->resources, PokeathlonCourseSpritePool_GetSpriteList(goalRoll->spritePool));
        PokeathlonCourseSpritePool_SetResourceId(goalRoll->spritePool, 0, 101);
        PokeathlonCourseSpritePool_SetResourceId(goalRoll->spritePool, 1, 102);
        PokeathlonCourseSpritePool_LoadChar(goalRoll->spritePool, NARC_a_2_3_4, 18, 101, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(goalRoll->spritePool, NARC_a_2_3_4, 15, 101, NNS_G2D_VRAM_TYPE_2DMAIN, 2);
        PokeathlonCourseSpritePool_LoadCell(goalRoll->spritePool, NARC_a_2_3_4, 17, 101);
        PokeathlonCourseSpritePool_LoadAnim(goalRoll->spritePool, NARC_a_2_3_4, 16, 101);
        PokeathlonCourseSpritePool_LoadChar(goalRoll->spritePool, NARC_a_2_3_4, 14, 102, NNS_G2D_VRAM_TYPE_2DSUB);
        PokeathlonCourseSpritePool_LoadPltt(goalRoll->spritePool, NARC_a_2_3_4, 11, 102, NNS_G2D_VRAM_TYPE_2DSUB, 1);
        PokeathlonCourseSpritePool_LoadCell(goalRoll->spritePool, NARC_a_2_3_4, 13, 102);
        PokeathlonCourseSpritePool_LoadAnim(goalRoll->spritePool, NARC_a_2_3_4, 12, 102);
        PokeathlonCourseSpritePool_TransferResources(goalRoll->spritePool);
        for (i = 0; i < POKEATHLON_MONS; i++) {
            goalRoll->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE].dashSprite = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 2);
            PokeathlonCourseSpritePoolSprite_SetDrawPriority(goalRoll->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE].dashSprite, 5);
            for (j = 0; j < 3; j++) {
                goalRoll->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE].trailSprites[j] = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 7);
                PokeathlonCourseSpritePoolSprite_SetDrawPriority(goalRoll->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE].trailSprites[j], 47);
            }
        }
        for (i = 0; i < 2; i++) {
            PokeathlonGoalRollBall *ball = &goalRoll->balls[i];
            memset(&work.ballPosition, 0, sizeof(VecFx32));
            ball->sprite = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 3);
            ball->effectSprite = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 8);
            PokeathlonCourseSpritePoolSprite_SetAnim(ball->sprite, 10);
            PokeathlonCourseSpritePoolSprite_SetAnim(ball->effectSprite, 13);
            PokeathlonCourseSpritePoolSprite_SetDrawPriority(ball->sprite, 46);
            PokeathlonCourseSpritePoolSprite_SetDrawPriority(ball->effectSprite, 45);
            PokeathlonGoalRoll_ResetBall(ball);
            ball->state = GOAL_ROLL_BALL_ROLLING;
            work.ballPosition.x = 0x80000;
            work.ballPosition.y = FX32_CONST(104);
            PokeathlonCourseSpritePoolSprite_SetPosition(ball->sprite, &work.ballPosition);
            PokeathlonCourseSpritePoolSprite_SetPosition(ball->effectSprite, &work.ballPosition);
            ball->position = work.ballPosition;
            ball->spawnPoint = 7;
            if (i == 0) {
                PokeathlonCourseSpritePoolSprite_Show(ball->sprite, TRUE, TRUE);
                ball->kind = GOAL_ROLL_BALL_SMALL;
            }
        }
        goalPalettes[0] = gPokeathlonGoalRollPaletteData.data.goalPalettes[0];
        goalPalettes[1] = gPokeathlonGoalRollPaletteData.data.goalPalettes[1];
        goalPalettes[2] = gPokeathlonGoalRollPaletteData.data.goalPalettes[2];
        goalPalettes[3] = gPokeathlonGoalRollPaletteData.data.goalPalettes[3];
        *(PokeathlonGoalRollVec4 *)work.goalPositions = *(const PokeathlonGoalRollVec4 *)gPokeathlonGoalRollGoalPositions;
        {
            int goalIndex;
            for (goalIndex = 0, goal = goalRoll, goalPosition = work.goalPositions, goalPalette = goalPalettes, markAnim = 2, markPosition = gPokeathlonGoalRollGoalPosts[0], labelPosition = gPokeathlonGoalRollLabelPositions; goalIndex < POKEATHLON_PARTICIPANTS; goal = GOAL_CURSOR_NEXT(goal), goalPosition++, goalPalette++, markAnim += 2, markPosition += 2, labelPosition++, goalIndex++) {
                goal->goalSprites[0] = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 5);
                PokeathlonCourseSpritePoolSprite_Show(goal->goalSprites[0], TRUE, TRUE);
                PokeathlonCourseSpritePoolSprite_SetAnim(goal->goalSprites[0], 1);
                PokeathlonCourseSpritePoolSprite_SetPosition(goal->goalSprites[0], goalPosition);
                PokeathlonCourseSpritePoolSprite_SetRotation(goal->goalSprites[0], *goalPalette, 1);
                PokeathlonCourseSpritePoolSprite_SetDrawPriority(goal->goalSprites[0], 3);
                for (j = 0; j < 2; j++) {
                    sprite = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 6);
                    PokeathlonCourseSpritePoolSprite_Show(sprite, TRUE, TRUE);
                    PokeathlonCourseSpritePoolSprite_SetAnim(sprite, j + markAnim);
                    PokeathlonCourseSpritePoolSprite_SetPosition(sprite, markPosition + j);
                    PokeathlonCourseSpritePoolSprite_SetDrawPriority(sprite, 103);
                }
                goal->goalFlashSprites[0] = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 11);
                PokeathlonCourseSpritePoolSprite_SetPosition(goal->goalFlashSprites[0], labelPosition);
                PokeathlonCourseSpritePoolSprite_SetDrawPriority(goal->goalFlashSprites[0], 2);
                goal->goalLabelSprites[0] = PokeathlonCourseSpritePool_CreateAndTake(goalRoll->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 12);
                PokeathlonCourseSpritePoolSprite_SetPosition(goal->goalLabelSprites[0], goalPosition);
                PokeathlonCourseSpritePoolSprite_SetDrawPriority(goal->goalLabelSprites[0], 102);
            }
        }
        Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSpritesInPool(course, 0, goalRoll->resources, goalRoll->spritePool), 1);
        PokeathlonGoalRollDisplay_CreateSprites(goalRoll->spritePool, goalRoll->display, goalRoll->resources);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case GOAL_ROLL_INIT_LOAD_MONS: {
        int col;
        u32 participantIndex;
        PokeathlonCourseMonGfxTemplate *info;
        info = &work.objectsInfo;
        for (i = 0; i < POKEATHLON_MONS; i++) {
            col = i % POKEATHLON_TEAM_SIZE;
            participantIndex = i / POKEATHLON_TEAM_SIZE;
            PokeathlonCourse_GetMonInfo(course, participantIndex, col, &work.views[i]);
            info->sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, participantIndex, col));
        }
        work.objectsInfo.loadAtOnce = FALSE;
        work.objectsInfo.priority = 1;
        work.objectsInfo.vramTransfer = FALSE;
        work.objectsInfo.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        work.objectsInfo.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(goalRoll->monObjects, POKEATHLON_MONS, work.views, &work.objectsInfo, 0, 0);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case GOAL_ROLL_INIT_PLACE_MONS: {
        PokeathlonCourseMonObject *object;
        PokeathlonGoalRollMon *mon;
        if (!PokeathlonCourseMonObjects_IsLoaded(goalRoll->monObjects)) {
            break;
        }
        own = PokeathlonCourse_GetNetId(course);
        PokeathlonCourse_SetVBlankIntrCB(goalRoll->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        ReadWholeNarcMemberByIdPair(collisions, NARC_a_1_7_0, 11);
        for (i = 0; i < POKEATHLON_MONS; i++) {
            PokeathlonGoalRoll_SetMonCollision(course, goalRoll->monObjects, i, collisions);
            object = PokeathlonCourseMonObjects_Get(goalRoll->monObjects, i);
            image = PokeathlonCourseMonObject_GetGfx(object);
            member = i % POKEATHLON_TEAM_SIZE;
            row = i / POKEATHLON_TEAM_SIZE;
            mon = &goalRoll->mons[row][member];
            mon->object = object;
            mon->radius = PokeathlonCourseObject_GetCollisionRadius(object);
            mon->mode = GOAL_ROLL_MODE_WALK;
            PokeathlonCourseMonGfx_GetTopRow(image);
            x = gPokeathlonGoalRollMonStartPositions[row][member][0];
            y = gPokeathlonGoalRollMonStartPositions[row][member][1];
            mon->facing = 2;
            PokeathlonCourseMonObject_SetAnimState(object, 2);
            PokeathlonCourseObject_SetGroundPosition(object, x, y);
            PokeathlonCourseObject_SetTouchRadius(object, PokeathlonCourse_GetTouchRadius());
            PokeathlonCourseObject_GroundToCenter(object, x, y, &screen.x, &screen.y);
            mon->startX = screen.x << FX32_SHIFT;
            mon->startY = screen.y << FX32_SHIFT;
            mon->position.x = screen.x << FX32_SHIFT;
            mon->position.y = screen.y << FX32_SHIFT;
            mon->target.x = screen.x << FX32_SHIFT;
            mon->target.y = screen.y << FX32_SHIFT;
            if (row == PokeathlonCourse_GetNetId(course)) {
                PokeathlonCourseMonObject_SetDrawPriority(object, 8);
            } else {
                PokeathlonCourseMonObject_SetDrawPriority(object, 16);
            }
            PokeathlonCourseMonObject_SetDrawPriorityStep(object, 20);
            if (row == own) {
                work.ownCoords[member].x = screen.x;
                work.ownCoords[member].y = screen.y;
                PokeathlonCourse_AddMarker(course, object, goalRoll->resources, PokeathlonCourseSpritePool_GetSpriteList(goalRoll->spritePool), 1);
            }
        }
        PokeathlonCourse_CreateStartSpritesInPool(course, 0, goalRoll->resources, goalRoll->spritePool, NNS_G2D_VRAM_TYPE_2DMAIN, 3, work.ownCoords);
        if (PokeathlonCourse_GetNetId(course) == 0) {
            ReadWholeNarcMemberByIdPair(&work.monParams, NARC_a_1_7_0, 8);
            for (participant = 0, team = goalRoll->mons; participant < POKEATHLON_PARTICIPANTS; team++, participant++) {
                goalRoll->heldMon[participant] = POKEATHLON_NO_MON;
                for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                    PokeathlonGoalRollMon *mon = &(*team)[j];
                    PokeathlonGoalRoll_InitMonStats(course, &work.monParams, participant, j, mon);
                    PokeathlonGoalRollCpu_SetMon(goalRoll->cpu->teams, (u8)(j + participant * 3), mon);
                }
            }
            PokeathlonGoalRollCpu_SetBalls(goalRoll->cpu, goalRoll->balls);
            PokeathlonGoalRollCpu_ChooseAllRoles(goalRoll->cpu->teams);
            flip = -1;
            wall.normal = gPokeathlonGoalRollWallNormal;
            VEC_Normalize(&wall.normal, &wall.normal);
            wall.corner = gPokeathlonGoalRollWallCorner;
            goalRoll->walls[0] = wall.corner;
            goalRoll->walls[1] = wall.corner;
            goalRoll->walls[1].x *= flip;
            wall.post = gPokeathlonGoalRollWallPost;
            goalRoll->walls[2] = wall.post;
            goalRoll->walls[3] = wall.post;
            goalRoll->walls[3].y *= flip;
            goalRoll->walls[4] = wall.normal;
            goalRoll->walls[5] = wall.normal;
            goalRoll->walls[5].x *= flip;
            goalRoll->walls[6] = wall.normal;
            goalRoll->walls[6].y *= flip;
            goalRoll->walls[7] = wall.normal;
            goalRoll->walls[7].x *= flip;
            goalRoll->walls[7].y *= flip;
        }
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonGoalRoll_PackFrame(goalRoll, (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT));
        }
        PokeathlonGoalRoll_LoadBgGfx(goalRoll);
        PokeathlonGoalRollDisplay_PrintName(goalRoll->display);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        goalRoll->timer = 2700;
        PokeathlonGoalRollDisplay_UpdateTimer(goalRoll->display, goalRoll->timer);
        WirelessStatusIcon_CreateOnScreenIfConnected(2);
        BeginNormalPaletteFade(FADE_SUB_THEN_MAIN, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, goalRoll->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case GOAL_ROLL_INIT_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL PokeathlonGoalRoll_Draw(PokeathlonCourseData *course) {
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);
    PokeathlonCourseSpritePool_Draw(goalRoll->spritePool);
    return TRUE;
}

BOOL PokeathlonGoalRoll_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx;
    int i;

    PokeathlonCourse_GetWork(course);
    gfx = PokeathlonCourse_GetGraphicsSystem(course);
    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, gfx, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00300);
    }
    PokeathlonCourseScoreList_Rank(gfx, 1);
    PokeathlonEvent_CalcPoints(gfx, 9);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 9);
    return TRUE;
}

BOOL PokeathlonGoalRoll_Exit(PokeathlonCourseData *course) {
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);
    Window *window;
    int i;

    WirelessStatusIcon_Destroy();
    PokeathlonCourse_FreeMarkers(course);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(goalRoll->bgConfig, GF_BG_LYR_SUB_2);
    PokeathlonGoalRoll_DestroyPlateTasks(goalRoll);
    PokeathlonGoalRoll_FreeStrings(course);
    RemoveWindow(&goalRoll->scoreWindow);
    i = 0;
    window = goalRoll->nameWindows;
    while (i < POKEATHLON_PARTICIPANTS) {
        RemoveWindow(window);
        i++;
        window++;
    }
    Heap_Free(goalRoll->bgConfig);
    PokeathlonCourseSpritePool_Free(goalRoll->spritePool);
    PokeathlonCourseMonObjects_Free(goalRoll->monObjects);
    PokeathlonCourseSprites_FreeResources(goalRoll->resources);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    PokeathlonGoalRollCpu_Free(goalRoll->cpu);
    PokeathlonGoalRollDisplay_Free(goalRoll->display);
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    Heap_Free(goalRoll->sortWork);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    G2_BlendNone();
    Heap_Destroy(HEAP_ID_147);
    return TRUE;
}

static void PokeathlonGoalRoll_SetGfxBanks(void) {
    GraphicsBanks banks = gPokeathlonGoalRollGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

BOOL PokeathlonGoalRoll_State_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case EVENT_PLAY_STATE_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_RUN:
        PokeathlonGoalRoll_HostUpdate(course);
        if (PokeathlonGoalRoll_HandleInput(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_FINISH:
        PokeathlonGoalRoll_HostUpdate(course);
        PokeathlonGoalRoll_ApplyFrameScore(course);
        if (PokeathlonCourse_RunFinish(course)) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, goalRoll->heapId);
            PokeathlonCourse_SetNextState(course, GOAL_ROLL_STATE_FINISH);
        }
        break;
    }
    return FALSE;
}

BOOL PokeathlonGoalRoll_State_Finish(PokeathlonCourseData *course, u8 *state) {
    int i;
    PokeathlonCourseData *savedCourse = course;
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return FALSE;
    }
    if (PokeathlonCourse_GetNetId(savedCourse)) {
        return TRUE;
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_SetEventScore(savedCourse, (u8)i, goalRoll->scores[0]);
        goalRoll = GOAL_CURSOR_NEXT(goalRoll);
    }
    return TRUE;
}

static void PokeathlonGoalRoll_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate main0;
    BgTemplate main1;
    BgTemplate main2;
    BgTemplate main3;
    BgTemplate sub0;
    BgTemplate sub1;
    BgTemplate sub2;

    modes = gPokeathlonGoalRollGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    main0 = gPokeathlonGoalRollBgTemplate_Main0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &main0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    main1 = gPokeathlonGoalRollBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    main2 = gPokeathlonGoalRollBgTemplate_Main2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &main2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    main3 = gPokeathlonGoalRollBgTemplate_Main3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main3, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    sub0 = gPokeathlonGoalRollBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &sub0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    sub1 = gPokeathlonGoalRollBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &sub1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    sub2 = gPokeathlonGoalRollBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &sub2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
}

static void PokeathlonGoalRoll_LoadBgGfx(PokeathlonGoalRoll *goalRoll) {
    GfGfxLoader_LoadCharData(NARC_a_2_3_4, 1, goalRoll->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, goalRoll->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_4, 3, goalRoll->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, goalRoll->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_4, 6, goalRoll->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, goalRoll->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_4, 7, goalRoll->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, goalRoll->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_4, 2, goalRoll->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, goalRoll->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_4, 4, goalRoll->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, goalRoll->heapId);
    PokeathlonGoalRollDisplay_LoadBgGfx(goalRoll->display);
    GfGfxLoader_GXLoadPal(NARC_a_2_3_4, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x80, goalRoll->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_3_4, 5, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x40, goalRoll->heapId);
}

// Every participant: reads the received frame; TRUE once the host reports the time is up.
static BOOL PokeathlonGoalRoll_HandleInput(PokeathlonCourseData *course) {
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);
    u8 *area = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonGoalRollInput *input = (PokeathlonGoalRollInput *)PokeathlonCourse_ToBytes(area);
    PokeathlonGoalRollFramePacket *frame;

    input->touching = FALSE;
    frame = (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(area + POKEATHLON_COURSE_DATA_FRAME_IN);
    u8 timeUp = 1;
    timeUp &= frame->flags >> 24;
    if (timeUp) {
        PokeathlonCourseSpritePool_PauseAnims(goalRoll->spritePool, TRUE);
        PokeathlonCourseObjects_PauseAnims(goalRoll->monObjects, TRUE);
        PokeathlonCourse_StopMarkerAnims(course);
        PokeathlonCourse_SetFinishCallback(course, PokeathlonGoalRoll_OnTimeUp);
        return TRUE;
    }
    if (System_GetTouchNew()) {
        PokeathlonCourse_AddMonCounter(course, PokeathlonCourse_GetNetId(course), 3, POKEATHLON_COUNTER_INSTRUCTIONS, 1);
    }
    if (System_GetTouchHeld()) {
        input->x = gSystem.touchX;
        input->y = gSystem.touchY;
        input->touching = TRUE;
    }
    PokeathlonGoalRoll_ApplyFrame(course);
    return FALSE;
}

// The host: applies all participants' inputs, runs the field and sends the frame.
static void PokeathlonGoalRoll_HostUpdate(PokeathlonCourseData *course) {
    struct {
        PokeathlonCourseData *course;
        PokeathlonGoalRollMon *team;
    } frame;

    PokeathlonGoalRollFramePacket *out;
    u8 *area;
    PokeathlonGoalRoll *goalRoll;
    PokeathlonGoalRollInput *input;
    PokeathlonGoalRollFramePacket *ownInput;
    int i;
    int monIndex;
    u8 member;

    frame.course = course;
    area = PokeathlonCourse_GetDataCopyArea(frame.course);
    goalRoll = PokeathlonCourse_GetWork(frame.course);
    if (goalRoll->timer > 0) {
        goalRoll->timer--;
    }
    if (PokeathlonCourse_GetNetId(frame.course)) {
        return;
    }
    if (goalRoll->timeUp) {
        area += POKEATHLON_COURSE_DATA_FRAME_OUT;
        PokeathlonGoalRoll_PackFrame(goalRoll, (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(area));
        return;
    }
    out = (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(area + POKEATHLON_COURSE_DATA_FRAME_OUT);
    ownInput = (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(area + POKEATHLON_COURSE_DATA_INPUTS);
    *ownInput = *(PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(area);
    area += POKEATHLON_COURSE_DATA_INPUTS;
    frame.team = goalRoll->mons[0];
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++, area += POKEATHLON_COURSE_DATA_SLOT_SIZE, frame.team += POKEATHLON_TEAM_SIZE) {
        input = (PokeathlonGoalRollInput *)PokeathlonCourse_ToBytes(area);
        if (input->touching) {
            if (goalRoll->touch[i].pressed && goalRoll->touch[i].held) {
                goalRoll->touch[i].pressed = FALSE;
            } else if (!goalRoll->touch[i].pressed && !goalRoll->touch[i].held) {
                goalRoll->touch[i].pressed = TRUE;
                goalRoll->touch[i].held = TRUE;
            }
        } else {
            goalRoll->touch[i].pressed = FALSE;
            goalRoll->touch[i].held = FALSE;
        }
        if (goalRoll->touch[i].pressed) {
            monIndex = PokeathlonGoalRoll_GetTouchedMon(goalRoll, i, input->x, input->y);
            if (monIndex != POKEATHLON_NO_MON) {
                PokeathlonGoalRollMon *mon = &frame.team[monIndex % POKEATHLON_TEAM_SIZE];
                if (mon->mode != GOAL_ROLL_MODE_STUNNED && mon->mode != GOAL_ROLL_MODE_DASH && mon->motion == GOAL_ROLL_MOTION_NONE) {
                    goalRoll->heldMon[i] = monIndex;
                    goalRoll->holdFrames = 0;
                }
            }
        } else if (goalRoll->touch[i].held) {
            if (goalRoll->heldMon[i] != POKEATHLON_NO_MON) {
                if (goalRoll->holdFrames < 20) {
                    goalRoll->holdFrames++;
                }
                member = goalRoll->heldMon[i] % POKEATHLON_TEAM_SIZE;
                PokeathlonGoalRoll_SetTouchTarget(input->x, input->y, &frame.team[member].target);
            }
        } else if (goalRoll->heldMon[i] != POKEATHLON_NO_MON) {
            member = goalRoll->heldMon[i] % POKEATHLON_TEAM_SIZE;
            {
                PokeathlonGoalRollMon *mon = &frame.team[member];
                if (mon->mode != GOAL_ROLL_MODE_TIRED && mon->mode != GOAL_ROLL_MODE_STUNNED) {
                    // a short touch makes the Pokemon dash to where it was released
                    if (goalRoll->holdFrames <= 8) {
                        if (mon->target.x != mon->position.x || mon->target.y != mon->position.y) {
                            mon->mode = GOAL_ROLL_MODE_DASH;
                            PokeathlonCourse_AddMonCounter(frame.course, i, goalRoll->heldMon[i] % POKEATHLON_TEAM_SIZE, POKEATHLON_COUNTER_DASHES, 1);
                        }
                    } else {
                        mon->mode = GOAL_ROLL_MODE_WALK;
                    }
                }
            }
            goalRoll->holdFrames = 0;
            goalRoll->heldMon[i] = POKEATHLON_NO_MON;
        }
    }
    PokeathlonGoalRollCpu_Update(frame.course, goalRoll->cpu);
    PokeathlonGoalRoll_MoveMons(frame.course);
    PokeathlonGoalRoll_MoveBalls(frame.course);
    PokeathlonGoalRoll_CollideBalls(frame.course);
    PokeathlonGoalRoll_CheckGoals(frame.course);
    PokeathlonGoalRoll_UpdateTiredMons(frame.course);
    if (goalRoll->timer <= 0) {
        goalRoll->timeUp = TRUE;
    } else {
        goalRoll->timeUp = FALSE;
    }
    PokeathlonGoalRoll_PackFrame(goalRoll, out);
}

static void PokeathlonGoalRoll_PackFrame(PokeathlonGoalRoll *goalRoll, PokeathlonGoalRollFramePacket *out) {
    PokeathlonGoalRoll *work = goalRoll;
    PokeathlonGoalRollBall *ball;
    u8 ballY;
    int ballX;
    u8 score;
    int i;
    PokeathlonGoalRollMon(*team)[POKEATHLON_TEAM_SIZE];
    int shift;
    u32 facings;
    u32 modes;
    u8 slot;
    u32 ballStates;

    facings = 0;
    modes = 0;
    ballStates = 0;
    for (i = 0, shift = 0, team = work->mons; i < POKEATHLON_MONS; i++, shift += 2) {
        PokeathlonGoalRollMon *mon = &team[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
        int y = mon->position.y / FX32_ONE;
        int x = mon->position.x / FX32_ONE;
        u8 mode = mon->mode;
        u8 facing = mon->facing - 1;
        out->monX[i] = x;
        out->monY[i] = y;
        facings += facing << shift;
        modes += mode << shift;
    }
    ball = work->balls;
    for (i = 0; i < 2; i++) {
        ballX = ball->position.x / FX32_ONE;
        ballY = PokeathlonGoalRoll_EncodeBallY(ball);
        out->ballX[i] = ballX;
        out->ballY[i] = ballY;
        ballStates += ball->state << (i * 2);
        ball++;
    }
    slot = work->packetScoreSlot;
    score = work->scores[slot];
    work->packetScoreSlot = (slot + 1) % 4;
    out->states = facings;
    out->states += ballStates << 24;
    out->states += slot << 28;
    {
        s32 *states = &out->states;
        if (work->balls[0].kind == GOAL_ROLL_BALL_BIG) {
            *states += 1 << 30;
        }
    }
    if (work->balls[1].kind != GOAL_ROLL_BALL_NONE) {
        out->states = out->states - (2 << 30);
    }
    out->flags = 0;
    out->flags += modes;
    out->flags += work->timeUp << 24;
    out->flags += score << 25;
}

static inline u8 PokeathlonGoalRoll_GetMonSize(PokeathlonCourseData *course, int index) {
    return PokeathlonCourse_GetPerformance(course, index / POKEATHLON_TEAM_SIZE, index % POKEATHLON_TEAM_SIZE)->heightClass;
}

static inline void PokeathlonGoalRoll_ClearVec(VecFx32 *vec) {
    vec->x = 0;
    vec->y = 0;
    vec->z = 0;
}

typedef void (*PokeathlonGoalRollDrawScoreFunc)(PokeathlonGoalRollDisplay *display, u8 score);

typedef void (*PokeathlonGoalRollPlayGoalAreaSEFunc)(PokeathlonGoalRoll *goalRoll, u8 ballIndex, u8 bigBall, u8 code);

// Every participant: shows the frame the host sent.
static void PokeathlonGoalRoll_ApplyFrame(PokeathlonCourseData *course) {
    u8 secondBall;
    PokeathlonGoalRoll *goalRoll;
    int x, y;
    u8 state, mode;
    int trail;
    int shift;
    u8 bigBall;
    int participant;
    u8 own;
    PokeathlonGoalRollFramePacket *frame;
    s32 i;
    PokeathlonGoalRollMon *mon;
    PokeathlonGoalRollBall *ball;
    PokeathlonCourseMonObject *object;

    goalRoll = PokeathlonCourse_GetWork(course);
    own = PokeathlonCourse_GetNetId(course);
    frame = (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    PokeathlonGoalRoll_UpdateLeaders(goalRoll);
    for (i = 0; i < POKEATHLON_MONS; i++) {
        participant = i / POKEATHLON_TEAM_SIZE;
        mon = &goalRoll->mons[participant][i % POKEATHLON_TEAM_SIZE];
        PokeathlonCourseMonGfx_GetSprite(PokeathlonCourseMonObject_GetGfx(mon->object));
        mode = (frame->flags >> (i * 2)) & 3;
        if (mode == GOAL_ROLL_MODE_TIRED) {
            PokeathlonCourseSpritePoolSprite_Show(mon->dashSprite, TRUE, TRUE);
            PokeathlonCourseSpritePoolSprite_TryChangeAnim(mon->dashSprite, 12);
        } else if (mode == GOAL_ROLL_MODE_STUNNED) {
            PokeathlonCourseSpritePoolSprite_Show(mon->dashSprite, TRUE, TRUE);
            PokeathlonCourseSpritePoolSprite_TryChangeAnim(mon->dashSprite, 16);
            if (!IsSEPlaying(SEQ_SE_GS_W146)) {
                PlaySE(SEQ_SE_GS_W146);
            }
        } else {
            PokeathlonCourseSpritePoolSprite_Show(mon->dashSprite, TRUE, FALSE);
        }
        x = frame->monX[i];
        y = frame->monY[i];
        state = (frame->states >> (i * 2)) & 3;
        {
            VecFx32 position = { 0, 0, 0 };
            position.x = x << FX32_SHIFT;
            position.y = y << FX32_SHIFT;
            switch (PokeathlonGoalRoll_GetMonSize(course, i)) {
            case 1:
                position.y -= FX32_CONST(8);
                break;
            case 2:
                position.y -= FX32_CONST(8);
                break;
            case 3:
                position.y -= FX32_CONST(16);
                break;
            default:
                GF_ASSERT(FALSE);
                break;
            }
            PokeathlonCourseSpritePoolSprite_SetPosition(mon->dashSprite, &position);
        }
        if (mode == GOAL_ROLL_MODE_DASH) {
            if (mon->trailCooldown == 0) {
                VecFx32 trailPosition = { 0, 0, 0 };
                s32 screenX, screenY;

                object = PokeathlonCourseMonObjects_Get(goalRoll->monObjects, i);
                trail = mon->trailIndex;
                PokeathlonCourseObject_CenterToGround(object, frame->monX[i], frame->monY[i], &screenX, &screenY);
                trailPosition.x = screenX << FX32_SHIFT;
                trailPosition.y = screenY << FX32_SHIFT;
                PokeathlonCourseSpritePoolSprite_SetPosition(mon->trailSprites[trail], &trailPosition);
                PokeathlonCourseSpritePoolSprite_Show(mon->trailSprites[trail], TRUE, TRUE);
                PokeathlonCourseSpritePoolSprite_SetAnim(mon->trailSprites[trail], 14);
                mon->trailIndex = (mon->trailIndex + 1) % 3;
                mon->trailCooldown = 5;
                if (participant == own) {
                    PlaySE(SEQ_SE_GS_DASH);
                }
            } else {
                mon->trailCooldown--;
            }
        }
        object = PokeathlonCourseMonObjects_Get(goalRoll->monObjects, i);
        if (mode == GOAL_ROLL_MODE_STUNNED) {
            PokeathlonCourseMonObject_SetAnim(object, 20);
        } else {
            PokeathlonCourseMonObject_SetAnimState(object, (u8)(state + 1));
        }
        PokeathlonCourseObject_SetCenterPosition(object, x, y, TRUE);
    }
    PokeathlonGoalRoll_SortOwnTeamOrder(goalRoll->mons[own], &frame->monY[own * 3]);
    PokeathlonGoalRoll_SortOtherMonsOrder(goalRoll, frame, own);
    bigBall = (frame->states >> 30) & 1;
    secondBall = (frame->states >> 31) & 1;
    for (i = 0, shift = 0; i < 2; i++, shift += 2) {
        VecFx32 ballPosition = { 0, 0, 0 };
        ball = &goalRoll->balls[i];
        state = ((u8)(frame->states >> 24) >> shift) & 3;
        if (state == GOAL_ROLL_BALL_SCORED) {
            PokeathlonCourseSpritePoolSprite_Show(ball->sprite, TRUE, FALSE);
            PokeathlonCourseSpritePoolSprite_Show(ball->effectSprite, TRUE, FALSE);
            PokeathlonGoalRoll_ShowGoal(goalRoll, i, (i == 0 && bigBall) ? 1 : 0, frame->ballX[i], frame->ballY[i], own);
        } else {
            ball->scored = 0;
            if (i == 1) {
                if (secondBall) {
                    PokeathlonCourseSpritePoolSprite_Show(ball->sprite, TRUE, TRUE);
                } else {
                    PokeathlonCourseSpritePoolSprite_Show(ball->sprite, TRUE, FALSE);
                }
            } else {
                PokeathlonCourseSpritePoolSprite_Show(ball->sprite, TRUE, TRUE);
            }
            if (state == GOAL_ROLL_BALL_KICKED) {
                PokeathlonCourseSpritePoolSprite_Show(ball->effectSprite, TRUE, TRUE);
                if (ball->shownState != GOAL_ROLL_BALL_KICKED) {
                    PlaySE(SEQ_SE_GS_SHOT);
                }
            } else {
                PokeathlonCourseSpritePoolSprite_Show(ball->effectSprite, TRUE, FALSE);
            }
            if (i == 0 && bigBall) {
                PokeathlonCourseSpritePoolSprite_TryChangeAnim(ball->sprite, 11);
            } else {
                PokeathlonCourseSpritePoolSprite_TryChangeAnim(ball->sprite, 10);
            }
        }
        ball->shownState = state;
        ballPosition.x = frame->ballX[i] << FX32_SHIFT;
        ballPosition.y = PokeathlonGoalRoll_DecodeBallY(frame->ballY[i]);
        ((PokeathlonGoalRollPlayGoalAreaSEFunc)PokeathlonGoalRoll_PlayGoalAreaSE)(goalRoll, i, bigBall, frame->ballY[i]);
        PokeathlonCourseSpritePoolSprite_SetPosition(ball->sprite, &ballPosition);
        PokeathlonCourseSpritePoolSprite_SetPosition(ball->effectSprite, &ballPosition);
        if (frame->ballY[i] < 192) {
            PokeathlonCourseSpritePoolSprite_SetDrawPriority(ball->sprite, 46);
        } else {
            PokeathlonCourseSpritePoolSprite_SetDrawPriority(ball->sprite, 4);
        }
    }

    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        if (!PokeathlonCourseSpritePoolSprite_IsAnimated(goalRoll->goalFlashSprites[i])) {
            PokeathlonCourseSpritePoolSprite_Show(goalRoll->goalLabelSprites[i], TRUE, FALSE);
        }
    }
    PokeathlonGoalRoll_ApplyFrameScore(course);
    ((PokeathlonGoalRollDrawScoreFunc)PokeathlonGoalRollDisplay_DrawScore)(goalRoll->display, PokeathlonGoalRollDisplay_GetScore(goalRoll->display));
    PokeathlonGoalRollDisplay_UpdateTimer(goalRoll->display, goalRoll->timer);
    PokeathlonGoalRoll_RefreshPlates(goalRoll);
}

typedef void (*PokeathlonGoalRollSetScoreFunc)(PokeathlonGoalRollDisplay *display, u8 score, u8 participant);

static void PokeathlonGoalRoll_ApplyFrameScore(PokeathlonCourseData *course) {
    PokeathlonGoalRoll *goalRoll = PokeathlonCourse_GetWork(course);
    PokeathlonGoalRollFramePacket *frame = (PokeathlonGoalRollFramePacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    u8 slot = (frame->states >> 28) & 3;
    u8 score = (frame->flags >> 25) & 0x7F;

    goalRoll->shownScores[slot] = score;
    ((PokeathlonGoalRollSetScoreFunc)PokeathlonGoalRollDisplay_SetScore)(goalRoll->display, score, slot);
}
