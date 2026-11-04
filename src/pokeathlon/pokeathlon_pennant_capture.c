#include "pokeathlon/pokeathlon_pennant_capture.h"

#include "global.h"

#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"
#include "pokeathlon/pokeathlon_pennant_capture_play.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "system.h"
#include "wireless_status_icon.h"

enum PokeathlonPennantCaptureInitState {
    PENNANT_CAPTURE_INIT_CREATE,
    PENNANT_CAPTURE_INIT_CREATE_DISPLAY,
    PENNANT_CAPTURE_INIT_CREATE_SPRITES,
    PENNANT_CAPTURE_INIT_LOAD_MONS,
    PENNANT_CAPTURE_INIT_PLACE_MONS,
    PENNANT_CAPTURE_INIT_CHOOSE_LAYOUT,
    PENNANT_CAPTURE_INIT_DONE,
};


static void PokeathlonPennantCapture_SetGfxBanks(void);

// The performance of Pokemon i (team i / 3, member i % 3).
static inline PokeathlonCoursePerformance *PokeathlonPennantCapture_GetPerformance(PokeathlonCourseData *course, int i) {
    return PokeathlonCourse_GetPerformance(course, i / POKEATHLON_TEAM_SIZE, i % POKEATHLON_TEAM_SIZE);
}

// Puts a Pokemon at its team's start: the four teams start side by side, 32 units apart, facing down; on the touch
// screen x is offset 128 (fieldX by 208 on the field). The own first Pokemon's spot is where the screen is centred.
static inline void PokeathlonPennantCapture_PlaceAtStart(PokeathlonPennantCapturePlayer *player, PokeathlonCourseMonObject *object, int fieldX, u32 x, int participant, int own, int member, PokeathlonCoursePoint *ownPosition, int *centerX, int *centerY) {
    player->direction = 1;
    PokeathlonCourseMonObject_SetAnimState(object, 1);
    x += 128;
    PokeathlonCourseObject_SetGroundPosition(object, x, 96);
    PokeathlonCourseObject_SetTouchRadius(object, PokeathlonCourse_GetTouchRadius());
    fieldX += 208;
    player->position.x = (u32)fieldX << FX32_SHIFT;
    player->position.y = FX32_CONST(416);
    PokeathlonCourseMonObject_SetDrawPriorityStep(object, 3000);
    if (participant == own && member == 0) {
        PokeathlonCourseObject_GroundToCenter(object, x, 96, centerX, centerY);
        ownPosition->x = 128;
        ownPosition->y = *centerY;
    }
}

// Set-up, a step per frame (PokeathlonCourse_GetEventInitState): heaps and screens, the top screen and the CPU,
// sprites, the Pokemon graphics, then the field once they are loaded. The host also picks the field layout.
BOOL PokeathlonPennantCapture_Init(PokeathlonCourseData *course) {
    PokeathlonCourseMonInfo infos[POKEATHLON_MONS];
    PokeathlonCourseMonGfxTemplate template;
    PokeathlonPennantCaptureMoveTables moveTables;
    ObjCharTransferTemplate charTransfer;
    PokeathlonCourseSpritePoolTemplate poolTemplate;
    PokeathlonPennantCaptureIconMon icons[POKEATHLON_MONS];
    PokeathlonCourseCollision collisions[POKEATHLON_SIZE_CLASSES];
    PokeathlonCoursePoint ownPosition;
    int centerX, centerY;
    int participant;
    int member;
    PokeathlonPennantCapture *work;
    int own;
    s32 team;
    int memberOnField;
    int teamId;

    work = PokeathlonCourse_GetWork(course);
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case PENNANT_CAPTURE_INIT_CREATE: {
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_139, 0x68000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonPennantCapture_SetGfxBanks();
        PokeathlonPennantCapture *data = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonPennantCapture));
        MI_CpuFill8(data, 0, sizeof(PokeathlonPennantCapture));
        data->bgConfig = BgConfig_Alloc(HEAP_ID_139);
        PokeathlonCourse_SetEventDataTransfer(course, &data->layoutChoice, &data->layoutFileId, sizeof(data->layoutFileId));
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        charTransfer.maxTasks = 202;
        charTransfer.sizeMain = 0x40000;
        charTransfer.sizeSub = 0x4000;
        charTransfer.heapID = HEAP_ID_139;
        PokeathlonCourse_InitObjTransfer(&charTransfer, 22, HEAP_ID_139, GX_OBJVRAMMODE_CHAR_1D_256K, GX_OBJVRAMMODE_CHAR_1D_32K);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_139);
        data->heapId = HEAP_ID_139;
        FontID_Alloc(4, HEAP_ID_139);
        PokeathlonPennantCapture_InitBgs(data->bgConfig);
        PokeathlonPennantCapture_InitScoreWindow(data);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case PENNANT_CAPTURE_INIT_CREATE_DISPLAY: {
        work->display = PokeathlonPennantCaptureDisplay_New(work->heapId, work->bgConfig, course);
        int count = PokeathlonCourse_GetParticipantCount(course);
        int mode = PokeathlonCourse_GetMode(course);
        work->cpu = PokeathlonPennantCaptureCpu_New(work->heapId, 4 - count, mode);
        work->monResources = PokeathlonCourseSprites_CreateResources(work->heapId, 0x2BF, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case PENNANT_CAPTURE_INIT_CREATE_SPRITES:
        poolTemplate = gPennantCaptureSpritePoolTemplate;
        work->spritePool = PokeathlonCourseSpritePool_New(work->heapId, &poolTemplate);
        PokeathlonCourseSpritePool_SetSurfaceCoords(work->spritePool, 0, 0, 0, FX32_CONST(700));
        work->monObjects = PokeathlonCourseMonObjects_Create(work->heapId, 12, 2, work->monResources, PokeathlonCourseSpritePool_GetSpriteList(work->spritePool));
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 0, 101);
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 1, 102);
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 2, 103);
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 3, 104);
        PokeathlonPennantCaptureDisplay_LoadSpriteResources(work->display, work->spritePool);
        PokeathlonPennantCapture_LoadSpriteResources(work->spritePool);
        PokeathlonCourseSpritePool_TransferResources(work->spritePool);
        Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSpritesInPool(course, 0, work->monResources, work->spritePool), 1);
        PokeathlonPennantCapture_CreateSprites(work, work->spritePool);
        PokeathlonPennantCaptureDisplay_CreateSprites(work->display, work->spritePool, work->monResources);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case PENNANT_CAPTURE_INIT_LOAD_MONS: {
        int i;
        for (i = 0; i < POKEATHLON_MONS; i++) {
            member = i % POKEATHLON_TEAM_SIZE;
            participant = i / POKEATHLON_TEAM_SIZE;
            PokeathlonCourse_GetMonInfo(course, participant, member, &infos[i]);
            template.sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, participant, member));
            icons[i].species = infos[i].species;
            icons[i].form = infos[i].form;
        }
        PokeathlonPennantCaptureDisplay_LoadIcons(work->display, icons);
        u8 ownTeam = PokeathlonCourse_GetNetId(course);
        PokeathlonPennantCaptureDisplay_LoadMonPics(work->display, (PokeathlonPennantCapturePicMon *)&infos[ownTeam * 3]);
        PokeathlonPennantCaptureDisplay_LoadMonPicToVram(work->display, 0, 1);
        PokeathlonPennantCaptureDisplay_LoadMonPicToVram(work->display, 1, 2);
        template.loadAtOnce = FALSE;
        template.priority = 2;
        template.vramTransfer = FALSE;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(work->monObjects, POKEATHLON_MONS, infos, &template, 0, 0);
        PokeathlonPennantCaptureDisplay_BringToFront(work->display, PokeathlonCourse_GetNetId(course));
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case PENNANT_CAPTURE_INIT_PLACE_MONS: {
        if (!PokeathlonCourseMonObjects_IsLoaded(work->monObjects)) {
            break;
        }
        own = PokeathlonCourse_GetNetId(course);
        PokeathlonCourse_SetVBlankIntrCB(work->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        ReadWholeNarcMemberByIdPair(collisions, NARC_a_1_7_0, 14);
        s32 i;
        int j;
        for (i = 0; i < POKEATHLON_MONS; i++) {
            PokeathlonCourseMonObject *object = PokeathlonCourseMonObjects_Get(work->monObjects, i);
            memberOnField = i % POKEATHLON_TEAM_SIZE;
            if (memberOnField == 0) {
                PokeathlonCourseMonObject_SetDrawFlag(object, TRUE);
            }
            {
                PokeathlonCourseCollision *collision = &collisions[PokeathlonCourse_GetCollisionSizeClass(PokeathlonPennantCapture_GetPerformance(course, i))]; // size 1-3
                PokeathlonCourseObject_SetCollision(object, collision[-1].offsetY, collision[-1].radius);
            }
            object = PokeathlonCourseMonObjects_Get(work->monObjects, i & 0xFF);
            teamId = i / POKEATHLON_TEAM_SIZE;
            PokeathlonPennantCapturePlayer *player = &work->players[teamId];
            player->monObjects[memberOnField] = object;
            PokeathlonPennantCapture_PlaceAtStart(player, object, teamId * 32, teamId * 32, teamId, own, memberOnField, &ownPosition, &centerX, &centerY);
        }
        ReadWholeNarcMemberByIdPair(&moveTables, NARC_a_1_7_0, 4);
        work->timeLeft = 1800;
        PokeathlonPennantCaptureDisplay_SetTimer(work->display, work->timeLeft);
        PokeathlonPennantCapture_ResetPennantSpots(work);
        for (team = 0; team < POKEATHLON_PARTICIPANTS; team++) {
            work->dragging[team] = FALSE;
            PokeathlonPennantCapturePlayer *player = &work->players[team];
            for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                PokeathlonPennantCapture_SetMoveParams(course, &moveTables, (u8)team, j, player);
            }
            if (PokeathlonCourse_GetNetId(course) == 0) {
                PokeathlonPennantCaptureCpu_SetPlayer(work->cpu, team, player);
            }
            work->players[team].participant = team;
        }
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonPennantCapture_PackFrame(work, (PokeathlonPennantCaptureFrame *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT));
        }
        PokeathlonCourse_CreateStartSpritesInPool(course, 0, work->monResources, work->spritePool, NNS_G2D_VRAM_TYPE_2DMAIN, 1, &ownPosition);
        PokeathlonPennantCapture_LoadBgGfx(work);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        // centre the field on the own Pokemon
        PokeathlonPennantCapturePlayer *ownPlayer = &work->players[own];
        int y = ownPlayer->position.y / FX32_ONE;
        int x = ownPlayer->position.x / FX32_ONE;
        ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, x - 128);
        ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, y - 96);
        WirelessStatusIcon_CreateOnScreenIfConnected(1);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case PENNANT_CAPTURE_INIT_CHOOSE_LAYOUT:
        if (PokeathlonCourse_GetNetId(course) == 0) {
            work->layoutChoice = LCRandom() % 20;
        }
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case PENNANT_CAPTURE_INIT_DONE:
        return TRUE;
    }
    return FALSE;
}

BOOL PokeathlonPennantCapture_Draw(PokeathlonCourseData *course) {
    PokeathlonPennantCapture *work = PokeathlonCourse_GetWork(course);
    PokeathlonCourseSpritePool_Draw(work->spritePool);
    return TRUE;
}

// Results: the points each team scored.
BOOL PokeathlonPennantCapture_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, gfx, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00292);
    }
    PokeathlonCourseScoreList_Rank(gfx, 1);
    PokeathlonEvent_CalcPoints(gfx, 1);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 1);
    return TRUE;
}

BOOL PokeathlonPennantCapture_Exit(PokeathlonCourseData *course) {
    PokeathlonPennantCapture *work = PokeathlonCourse_GetWork(course);
    WirelessStatusIcon_Destroy();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_ClearEventDataTransfer(course);
    Heap_Free(work->bgCharsFile);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_2);
    RemoveWindow(&work->scoreWindow);
    Heap_Free(work->bgConfig);
    PokeathlonCourseSpritePool_Free(work->spritePool);
    PokeathlonCourseMonObjects_Free(work->monObjects);
    PokeathlonCourseSprites_FreeResources(work->monResources);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    PokeathlonPennantCaptureCpu_Delete(work->cpu);
    PokeathlonPennantCaptureDisplay_Delete(work->display);
    FontID_Release(4);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    reg_G2_BLDCNT = 0;
    Heap_Destroy(HEAP_ID_139);
    return TRUE;
}

static void PokeathlonPennantCapture_SetGfxBanks(void) {
    GraphicsBanks banks = gPennantCaptureGraphicsBanks;
    GfGfx_SetBanks(&banks);
}
