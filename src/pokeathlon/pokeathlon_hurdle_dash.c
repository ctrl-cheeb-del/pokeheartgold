#include "pokeathlon/pokeathlon_hurdle_dash.h"

#include "global.h"

#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"
#include "pokeathlon/pokeathlon_hurdle_dash_race.h"

#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "screen_fade.h"
#include "sprite.h"
#include "system.h"
#include "wireless_status_icon.h"

enum {
    HURDLE_DASH_STATE_START,
    HURDLE_DASH_STATE_PLAY,
    HURDLE_DASH_STATE_CALC_SCORES,
};

enum PokeathlonHurdleDashPlayState {
    HURDLE_DASH_PLAY_COUNTDOWN,
    HURDLE_DASH_PLAY_RACE,
    HURDLE_DASH_PLAY_FINISH,
    HURDLE_DASH_PLAY_WAIT_PLAYERS,
    HURDLE_DASH_PLAY_END,
};

static void PokeathlonHurdleDash_SetGfxBanks(void);
static void PokeathlonHurdleDash_InitBgs(BgConfig *bgConfig);
static void PokeathlonHurdleDash_LoadBgTiles(BgConfig *bgConfig, enum HeapID heapId);
static void PokeathlonHurdleDash_LoadBgScreens(BgConfig *bgConfig, enum HeapID heapId);

BOOL PokeathlonHurdleDash_Start(PokeathlonCourseData *course) {
    PokeathlonCourse_SetNextState(course, HURDLE_DASH_STATE_PLAY);
    return FALSE;
}

BOOL PokeathlonHurdleDash_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonHurdleDash *hurdleDash = PokeathlonCourse_GetWork(course);
    switch (*state) {
    case HURDLE_DASH_PLAY_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            hurdleDash->started = TRUE;
            (*state)++;
        }
        break;
    case HURDLE_DASH_PLAY_RACE: {
        BOOL finished;
        u8 i;
        u32 total;
        PokeathlonHurdleDash_CountFrame(hurdleDash);
        finished = PokeathlonHurdleDash_UpdateRunners(course, hurdleDash);
        PokeathlonHurdleDash_UpdateCpuParticipants(course);
        if (finished) {
            total = 0;
            for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
                total += hurdleDash->runners[i].time;
            }
            PokeathlonCourse_SetRecordScore(course, total);
            PokeathlonHurdleDash_PrintTime(hurdleDash, total);
            (*state)++;
        }
        break;
    }
    case HURDLE_DASH_PLAY_FINISH: {
        u8 ready = PokeathlonCourse_RunFinish(course);
        if (PokeathlonHurdleDash_HaveAllStopped(hurdleDash) && ready) {
            (*state)++;
        }
        PokeathlonHurdleDash_CountFrame(hurdleDash);
        PokeathlonHurdleDash_UpdateRunners(course, hurdleDash);
        PokeathlonHurdleDash_UpdateCpuParticipants(course);
        break;
    }
    case HURDLE_DASH_PLAY_WAIT_PLAYERS: {
        u8 *block;
        PokeathlonHurdleDash_CountFrame(hurdleDash);
        PokeathlonHurdleDash_UpdateCpuParticipants(course);
        block = PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course));
        block[9] = TRUE;
        block = PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
        if (*(u32 *)block != 0) {
            (*state)++;
            hurdleDash->endTimer = 0;
        }
        break;
    }
    case HURDLE_DASH_PLAY_END:
        if (++hurdleDash->endTimer > 90) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, hurdleDash->heapId);
            PokeathlonCourse_SetNextState(course, HURDLE_DASH_STATE_CALC_SCORES);
        }
        break;
    }
    PokeathlonHurdleDash_SyncRace(course);
    return FALSE;
}

BOOL PokeathlonHurdleDash_CalcScores(PokeathlonCourseData *course, u8 *state) {
    PokeathlonHurdleDash *hurdleDash = PokeathlonCourse_GetWork(course);
    float frames;
    int participant;
    int member;
    int count;
    int sum;
    int self;
    int i;
    int total;

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return FALSE;
    }
    self = PokeathlonCourse_GetNetId(course);
    total = 0;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        total += hurdleDash->runners[i].time;
    }
    PokeathlonCourse_SetEventScore(course, (u8)self, PokeathlonHurdleDash_RoundTime(total));
    if (self == 0) {
        // the host simulates the races of the participants without a player
        count = PokeathlonCourse_GetParticipantCount(course);
        for (participant = count; participant < POKEATHLON_PARTICIPANTS; participant++) {
            sum = 0;
            for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
                float speed;
                int framesLeft;
                int index = (participant - count) * 3 + member;
                if (!hurdleDash->cpuRunners[index].finished) {
                    speed = hurdleDash->cpuRunners[index].speed;
                    if (speed < hurdleDash->cpuRunners[index].topSpeed) {
                        speed = hurdleDash->cpuRunners[index].topSpeed;
                    }
                    frames = (float)(HURDLE_DASH_FINISH - hurdleDash->cpuRunners[index].distance) / speed;
                    framesLeft = frames;
                    if (frames - (float)framesLeft > 0.0f) {
                        framesLeft++;
                    }
                    hurdleDash->cpuRunners[index].time = hurdleDash->frame + framesLeft;
                }
                sum += hurdleDash->cpuRunners[index].time;
            }
            PokeathlonCourse_SetEventScore(course, (u8)participant, PokeathlonHurdleDash_RoundTime(sum));
        }
    }
    return TRUE;
}

enum PokeathlonHurdleDashInitState {
    HURDLE_DASH_INIT_CREATE,
    HURDLE_DASH_INIT_CREATE_SCENE,
    HURDLE_DASH_INIT_CREATE_SPRITES,
    HURDLE_DASH_INIT_WAIT_MONS,
    HURDLE_DASH_INIT_LOAD_BG_SCREENS,
    HURDLE_DASH_INIT_SHOW,
    HURDLE_DASH_INIT_CHOOSE_LAYOUT,
    HURDLE_DASH_INIT_CREATE_HURDLES,
    HURDLE_DASH_INIT_WAIT_FADE_IN,
};

BOOL PokeathlonHurdleDash_Init(PokeathlonCourseData *course) {
    PokeathlonCourseMonGfxTemplate template;
    PokeathlonHurdleDashTable table;
    ObjCharTransferTemplate charTransfer;
    PokeathlonCourseSpritePoolTemplate sceneConfig;
    VecFx32 mainPos;
    VecFx32 spritePos;
    PokeathlonHurdleDashStandingsMonId mons[POKEATHLON_MONS];
    PokeathlonCourseMonInfo views[POKEATHLON_TEAM_SIZE];
    PokeathlonHurdleDashNumberX numberX;
    PokeathlonCoursePoint numberPos[POKEATHLON_TEAM_SIZE];
    PokeathlonHurdleDashParams params;
    PokeathlonHurdleDash *hurdleDash = PokeathlonCourse_GetWork(course);
    int i, j;
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case HURDLE_DASH_INIT_CREATE: {
        void *layoutToSend, *layout;
        int layoutSize;
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_138, 0x48000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
        PokeathlonHurdleDash_SetGfxBanks();
        hurdleDash = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonHurdleDash));
        MI_CpuFill8(hurdleDash, 0, sizeof(PokeathlonHurdleDash));
        hurdleDash->bgConfig = BgConfig_Alloc(HEAP_ID_138);
        hurdleDash->track = PokeathlonHurdleDashTrack_New(hurdleDash->heapId);
        hurdleDash->dust = PokeathlonHurdleDashDust_New(hurdleDash->heapId);
        layoutToSend = PokeathlonHurdleDashTrack_GetLayoutToSend(hurdleDash->track);
        layout = PokeathlonHurdleDashTrack_GetLayout(hurdleDash->track);
        layoutSize = PokeathlonHurdleDashTrack_GetLayoutSize(hurdleDash->track);
        PokeathlonCourse_SetEventDataTransfer(course, layoutToSend, layout, layoutSize);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        charTransfer.maxTasks = 107;
        charTransfer.sizeMain = 0x40000;
        charTransfer.sizeSub = 0x4000;
        charTransfer.heapID = HEAP_ID_138;
        PokeathlonCourse_InitObjTransfer(&charTransfer, 18, HEAP_ID_138, GX_OBJVRAMMODE_CHAR_1D_256K, GX_OBJVRAMMODE_CHAR_1D_256K);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_138);
        hurdleDash->heapId = HEAP_ID_138;
        FontID_Alloc(4, HEAP_ID_138);
        PokeathlonHurdleDash_InitBgs(hurdleDash->bgConfig);
        PokeathlonHurdleDash_InitTimeWindow(hurdleDash);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case HURDLE_DASH_INIT_CREATE_SCENE:
        sceneConfig = gHurdleDashSceneConfig;
        hurdleDash->scene = PokeathlonCourseSpritePool_New(hurdleDash->heapId, &sceneConfig);
        PokeathlonCourseSpritePool_SetSurfaceCoords(hurdleDash->scene, 0, FX32_CONST(272), 0, 0);
        PokeathlonCourseSpritePool_SetResourceId(hurdleDash->scene, 0, 101);
        PokeathlonCourseSpritePool_SetResourceId(hurdleDash->scene, 1, 102);
        PokeathlonCourseSpritePool_SetResourceId(hurdleDash->scene, 2, 103);
        PokeathlonCourseSpritePool_SetResourceId(hurdleDash->scene, 3, 104);
        PokeathlonCourseSpritePool_SetResourceId(hurdleDash->scene, 4, 105);
        PokeathlonCourseSpritePool_SetResourceId(hurdleDash->scene, 5, 106);
        PokeathlonCourseSpritePool_LoadChar(hurdleDash->scene, NARC_a_1_5_6, 9, 101, NNS_G2D_VRAM_TYPE_2DBOTH);
        PokeathlonCourseSpritePool_LoadPltt(hurdleDash->scene, NARC_a_1_5_6, 6, 101, NNS_G2D_VRAM_TYPE_2DBOTH, 1);
        PokeathlonCourseSpritePool_LoadCell(hurdleDash->scene, NARC_a_1_5_6, 8, 101);
        PokeathlonCourseSpritePool_LoadAnim(hurdleDash->scene, NARC_a_1_5_6, 7, 101);
        PokeathlonCourseSpritePool_LoadChar(hurdleDash->scene, NARC_a_1_5_6, 16, 102, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(hurdleDash->scene, NARC_a_1_5_6, 13, 102, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(hurdleDash->scene, NARC_a_1_5_6, 15, 102);
        PokeathlonCourseSpritePool_LoadAnim(hurdleDash->scene, NARC_a_1_5_6, 14, 102);
        PokeathlonCourseSpritePool_LoadChar(hurdleDash->scene, NARC_a_1_5_6, 12, 103, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(hurdleDash->scene, NARC_a_1_5_6, 6, 103, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(hurdleDash->scene, NARC_a_1_5_6, 11, 103);
        PokeathlonCourseSpritePool_LoadAnim(hurdleDash->scene, NARC_a_1_5_6, 10, 103);
        PokeathlonCourseSpritePool_LoadChar(hurdleDash->scene, NARC_a_1_5_6, 20, 105, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(hurdleDash->scene, NARC_a_1_5_6, 17, 105, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(hurdleDash->scene, NARC_a_1_5_6, 19, 105);
        PokeathlonCourseSpritePool_LoadAnim(hurdleDash->scene, NARC_a_1_5_6, 18, 105);
        PokeathlonCourseSpritePool_LoadChar(hurdleDash->scene, NARC_a_1_5_6, 28, 104, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(hurdleDash->scene, NARC_a_1_5_6, 25, 104, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(hurdleDash->scene, NARC_a_1_5_6, 27, 104);
        PokeathlonCourseSpritePool_LoadAnim(hurdleDash->scene, NARC_a_1_5_6, 26, 104);
        PokeathlonCourseSpritePool_LoadChar(hurdleDash->scene, NARC_a_1_5_6, 32, 106, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(hurdleDash->scene, NARC_a_1_5_6, 29, 106, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(hurdleDash->scene, NARC_a_1_5_6, 31, 106);
        PokeathlonCourseSpritePool_LoadAnim(hurdleDash->scene, NARC_a_1_5_6, 30, 106);
        PokeathlonCourseSpritePool_TransferResources(hurdleDash->scene);
        hurdleDash->spriteResources = PokeathlonCourseSprites_CreateResources(hurdleDash->heapId, 743, NNS_G2D_VRAM_TYPE_2DMAIN);
        hurdleDash->monSpriteManager = PokeathlonCourseMonObjects_Create(hurdleDash->heapId, 3, 4, hurdleDash->spriteResources, PokeathlonCourseSpritePool_GetSpriteList(hurdleDash->scene));
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case HURDLE_DASH_INIT_CREATE_SPRITES:
        for (i = 0; i < POKEATHLON_MONS; i++) {
            Sprite_SetDrawPriority(PokeathlonCourseSpritePool_CreateSprite(hurdleDash->scene, 1, NNS_G2D_VRAM_TYPE_2DBOTH, 101, 2), 27);
            Sprite_SetDrawPriority(PokeathlonCourseSpritePool_CreateSprite(hurdleDash->scene, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 103, 6), 27);
        }
        for (i = 0; i < 3; i++) {
            PokeathlonCourseSpritePool_CreateSprite(hurdleDash->scene, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 102, 5);
            PokeathlonCourseSpritePool_CreateSprite(hurdleDash->scene, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 7);
            PokeathlonCourseSpritePool_CreateSprite(hurdleDash->scene, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 105, 8);
        }
        hurdleDash->timerLabel = PokeathlonCourseSpritePool_CreateAndTake(hurdleDash->scene, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 106, 9);
        PokeathlonCourseSpritePoolSprite_SetAnim(hurdleDash->timerLabel, 0);
        mainPos.z = 0;
        mainPos.x = FX32_CONST(160);
        mainPos.y = FX32_CONST(456);
        PokeathlonCourseSpritePoolSprite_SetPosition(hurdleDash->timerLabel, &mainPos);
        PokeathlonCourseSpritePoolSprite_Show(hurdleDash->timerLabel, TRUE, TRUE);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(hurdleDash->timerLabel, 1);
        for (i = 0; i < 6; i++) {
            hurdleDash->sprites[i] = PokeathlonCourse_CreateTimerDigitSprite(hurdleDash->spriteResources, PokeathlonCourseSpritePool_GetSpriteList(hurdleDash->scene), 0, hurdleDash->heapId);
            Sprite_SetDrawFlag(hurdleDash->sprites[i], TRUE);
            spritePos.x = gHurdleDashTimerDigitX[i] << FX32_SHIFT;
            spritePos.y = FX32_CONST(456);
            spritePos.z = 0;
            Sprite_SetMatrix(hurdleDash->sprites[i], &spritePos);
            Sprite_SetAnimCtrlSeq(hurdleDash->sprites[i], gHurdleDashTimerDigitAnims[i]);
        }
        PokeathlonHurdleDashDust_CreateSprites(hurdleDash->dust, hurdleDash->scene, 1);
        hurdleDash->standings = PokeathlonHurdleDashStandings_New(hurdleDash->heapId);
        {
            PokeathlonHurdleDashStandingsMonId *out;
            i = 0;
            out = mons;
            for (; i < POKEATHLON_PARTICIPANTS; i++) {
                PokeathlonCourseMon *mon = PokeathlonCourse_GetParticipantMons(course, i);
                for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                    out->species = mon->species;
                    out->form = mon->form;
                    mon++;
                    out++;
                }
            }
        }
        PokeathlonHurdleDashStandings_Init(hurdleDash->standings, mons);
        PokeathlonHurdleDashStandings_SetDrawFlag(hurdleDash->standings, FALSE);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            PokeathlonCourse_GetMonInfo(course, PokeathlonCourse_GetNetId(course), i, &views[i]);
            template.sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, PokeathlonCourse_GetNetId(course), i));
        }
        template.loadAtOnce = FALSE;
        template.priority = 1;
        template.vramTransfer = FALSE;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(hurdleDash->monSpriteManager, 3, views, &template, 0, 0);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case HURDLE_DASH_INIT_WAIT_MONS:
        if (PokeathlonCourseMonObjects_IsLoaded(hurdleDash->monSpriteManager)) {
            PokeathlonCourse_SetVBlankIntrCB(hurdleDash->bgConfig);
            PokeathlonHurdleDash_LoadBgTiles(hurdleDash->bgConfig, hurdleDash->heapId);
            PokeathlonCourse_AdvanceEventInitState(course);
        }
        break;
    case HURDLE_DASH_INIT_LOAD_BG_SCREENS:
        PokeathlonHurdleDash_LoadBgScreens(hurdleDash->bgConfig, hurdleDash->heapId);
        {
            reg_G2_BG0OFS = 0x1400000;
            reg_G2_BG1OFS = 0x1400000;
            reg_G2_BG2OFS = 0x1400000;
            reg_G2S_DB_BG0OFS = 0x300000;
            reg_G2S_DB_BG1OFS = 0x300000;
            reg_G2S_DB_BG2OFS = 0x300000;
        }
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case HURDLE_DASH_INIT_SHOW:
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            PokeathlonCourseMonObject_SetDrawFlag(PokeathlonCourseMonObjects_Get(hurdleDash->monSpriteManager, i), 1);
        }
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case HURDLE_DASH_INIT_CHOOSE_LAYOUT:
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonHurdleDashTrack_LoadRandomLayout(hurdleDash->track);
        }
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case HURDLE_DASH_INIT_CREATE_HURDLES: {
        u8 *dataCopy;
        PokeathlonHurdleDashTrack_CreateHurdleSprites(hurdleDash->track, hurdleDash->scene);
        Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSpritesInPool(course, 272, hurdleDash->spriteResources, hurdleDash->scene), 1);
        numberX = gHurdleDashNumberX;
        ReadWholeNarcMemberByIdPair(&params, NARC_a_1_7_0, 10);
        ReadWholeNarcMemberByIdPair(&table, NARC_a_1_7_0, 0);
        {
            int k;
            for (k = 0; k < POKEATHLON_TEAM_SIZE; k++) {
                PokeathlonHurdleDashRunner_Init(course, &table, &params, hurdleDash->track, hurdleDash->scene, hurdleDash->monSpriteManager, k, &hurdleDash->runners[k]);
                numberPos[k].x = numberX.x[k];
                numberPos[k].y = 392;
            }
        }
        PokeathlonCourse_CreateStartSpritesInPool(course, 0, hurdleDash->spriteResources, hurdleDash->scene, NNS_G2D_VRAM_TYPE_2DMAIN, 3, numberPos);
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonHurdleDash_InitCpuRunners(course, &table);
        }
        dataCopy = PokeathlonCourse_GetDataCopyArea(course);
        {
            u8 *block = PokeathlonCourse_ToBytes(dataCopy + POKEATHLON_COURSE_DATA_FRAME_IN);
            u8 k;
            for (k = 0; k < 6; k++) {
                block[28 + k] = 17;
            }
        }
        if (PokeathlonCourse_GetNetId(course) == 0) {
            u8 *block = PokeathlonCourse_ToBytes(dataCopy + POKEATHLON_COURSE_DATA_FRAME_OUT);
            u8 k;
            for (k = 0; k < 6; k++) {
                block[28 + k] = 17;
            }
        }
        WirelessStatusIcon_CreateOnScreenIfConnected(1);
        BeginNormalPaletteFade(FADE_SUB_THEN_MAIN, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, hurdleDash->heapId);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case HURDLE_DASH_INIT_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL PokeathlonHurdleDash_Draw(PokeathlonCourseData *course) {
    PokeathlonHurdleDash *hurdleDash = PokeathlonCourse_GetWork(course);
    PokeathlonHurdleDashStandings_Draw(hurdleDash->standings);
    PokeathlonCourseSpritePool_Draw(hurdleDash->scene);
    return TRUE;
}

// Shows every team's total time ("Total Time: X.Y Seconds").
BOOL PokeathlonHurdleDash_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx;
    PokeathlonHurdleDash *hurdleDash;
    int i;
    int frames;
    int seconds;

    hurdleDash = PokeathlonCourse_GetWork(course);
    gfx = PokeathlonCourse_GetGraphicsSystem(course);
    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        frames = PokeathlonCourse_GetReceivedScore(course, (u8)i);
        seconds = frames / 30;
        PokeathlonCourse_AddScoreEntry2(course, gfx, i, (u16)frames, seconds, (frames % 30) * 10 / 30, 0, 1, 3, 1, msg_0309_00291);
    }
    PokeathlonCourseScoreList_Rank(gfx, 2);
    PokeathlonEvent_CalcPoints(gfx, 0);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 0);
    return TRUE;
}

BOOL PokeathlonHurdleDash_Exit(PokeathlonCourseData *course) {
    PokeathlonHurdleDash *hurdleDash = PokeathlonCourse_GetWork(course);

    WirelessStatusIcon_Destroy();
    PokeathlonCourseLink_SetCheckSize(PokeathlonCourse_GetSystem(course), 0);
    PokeathlonHurdleDashStandings_Free(hurdleDash->standings);
    PokeathlonCourse_ClearEventDataTransfer(course);
    PokeathlonHurdleDashDust_Free(hurdleDash->dust);
    PokeathlonHurdleDashTrack_Free(hurdleDash->track);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(hurdleDash->bgConfig, GF_BG_LYR_SUB_3);
    RemoveWindow(&hurdleDash->window);
    Heap_Free(hurdleDash->bgConfig);
    PokeathlonCourseMonObjects_Free(hurdleDash->monSpriteManager);
    PokeathlonCourseSprites_FreeResources(hurdleDash->spriteResources);
    PokeathlonCourseSpritePool_Free(hurdleDash->scene);
    PokeathlonCourse_FreeObjTransfer();
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    Heap_Destroy(HEAP_ID_138);
    return TRUE;
}

static void PokeathlonHurdleDash_SetGfxBanks(void) {
    GraphicsBanks banks = gHurdleDashGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokeathlonHurdleDash_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes = gHurdleDashGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    {
        BgTemplate bg = gHurdleDashBgTemplate_Main0;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Main1;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Main2;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Main3;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Sub0;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Sub1;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Sub2;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    }
    {
        BgTemplate bg = gHurdleDashBgTemplate_Sub3;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_3, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_3);
    }
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
}

static void PokeathlonHurdleDash_LoadBgTiles(BgConfig *bgConfig, enum HeapID heapId) {
    GfGfxLoader_LoadCharData(NARC_a_1_5_6, 1, bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_5_6, 1, bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapId);
}

static void PokeathlonHurdleDash_LoadBgScreens(BgConfig *bgConfig, enum HeapID heapId) {
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 2, bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 3, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 4, bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 2, bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 3, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 4, bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 5, bgConfig, GF_BG_LYR_SUB_3, 0, 0, FALSE, heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_5_6, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x20, heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_5_6, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x20, heapId);
}
