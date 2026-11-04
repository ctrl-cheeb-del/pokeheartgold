#include "pokeathlon/pokeathlon_circle_push.h"

#include <string.h>

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_circle_push_display.h"
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
#include "palette.h"
#include "pm_string.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"

enum {
    CIRCLE_PUSH_STATE_FADE_IN,
    CIRCLE_PUSH_STATE_PLAY,
    CIRCLE_PUSH_STATE_END,
};

enum {
    FALL_STATE_NONE,
    FALL_STATE_FALLING,
    FALL_STATE_FALLEN,
};

enum {
    LAYOUT_CHANGE_WAIT_SLIDE,
    LAYOUT_CHANGE_WAIT_SHAKE,
};

enum {
    LAYOUT_FADE_OUT,
    LAYOUT_FADE_SWAP,
    LAYOUT_FADE_IN,
};

enum {
    RING_SLIDE_OUT,
    RING_SLIDE_WAIT,
    RING_SLIDE_IN,
};

enum PokeathlonCirclePushInitState {
    CIRCLE_PUSH_INIT_CREATE,
    CIRCLE_PUSH_INIT_CREATE_DISPLAY,
    CIRCLE_PUSH_INIT_CREATE_SPRITES,
    CIRCLE_PUSH_INIT_LOAD_MONS,
    CIRCLE_PUSH_INIT_PLACE_MONS,
    CIRCLE_PUSH_INIT_DONE,
};

void MATH_QSort(void *head, u32 num, u32 width, int (*compare)(const void *, const void *), void *stackBuffer);

typedef struct CirclePushTimerTiles {
    u16 tiles[8];
} CirclePushTimerTiles;

typedef struct CirclePushFallScales {
    float scales[6];
} CirclePushFallScales;

typedef struct CirclePushFallOffsets {
    int offsets[6];
} CirclePushFallOffsets;

typedef struct CirclePushHostFrame {
    int count;
    u8 *copyArea;

    union {
        PokeathlonCirclePushInput *input;
        PokeathlonCirclePushMon *mon;
    } ptr;
} CirclePushHostFrame;

typedef struct CirclePushPushNode {
    VecFx32 *push;

    struct {
        u8 mons[POKEATHLON_MONS];
        u16 count;
        u16 index;
    } next;

    VecFx32 delta[POKEATHLON_MONS];
} CirclePushPushNode;

typedef struct CirclePushDepth {
    u16 mon;
    u16 y;
} CirclePushDepth;

static void PokeathlonCirclePush_SetBanks(void);
static void PokeathlonCirclePush_InitBgs(BgConfig *bgConfig);
static void PokeathlonCirclePush_LoadBgGfx(PokeathlonCirclePush *circlePush);
static void PokeathlonCirclePush_MakePacket(PokeathlonCirclePush *circlePush, PokeathlonCirclePushPacket *packet);
static BOOL PokeathlonCirclePush_Update(PokeathlonCourseData *course);
static void PokeathlonCirclePush_RunHost(PokeathlonCourseData *course);
static void PokeathlonCirclePush_UpdateScreen(PokeathlonCourseData *course);
static void PokeathlonCirclePush_MoveMons(PokeathlonCourseData *course);
static void PokeathlonCirclePush_SetTarget(int x, int y, const VecFx32 *position, fx32 range, VecFx32 *target);
static u8 PokeathlonCirclePush_FindTouchedMon(PokeathlonCirclePush *circlePush, u8 team, u16 x, u16 y);
static BOOL PokeathlonCirclePush_MonsCollide(PokeathlonCirclePushMon *a, PokeathlonCirclePushMon *b);
static void PokeathlonCirclePush_UpdateContacts(PokeathlonCirclePush *circlePush);
static BOOL PokeathlonCirclePush_CanMove(PokeathlonCirclePush *circlePush, PokeathlonCirclePushMon *mon, u32 index, const VecFx32 *delta);
static void PokeathlonCirclePush_PushMons(PokeathlonCirclePush *circlePush);
static u8 PokeathlonCirclePushStack_Push(PokeathlonCirclePushStack *stack, u8 mon);
static u8 PokeathlonCirclePushStack_Pop(PokeathlonCirclePushStack *stack);
static void PokeathlonCirclePush_Project(VecFx32 *a, VecFx32 *b, VecFx32 *out);
static fx32 PokeathlonCirclePush_Cosine(const VecFx32 *a, const VecFx32 *b);
static void PokeathlonCirclePush_ScoreZones(PokeathlonCirclePush *circlePush);
static void PokeathlonCirclePush_DrawTimer(int time, BgConfig *bgConfig);
static void PokeathlonCirclePush_DrawTimerTile(u32 index, BgConfig *bgConfig);
static void PokeathlonCirclePush_RespawnMons(PokeathlonCirclePush *circlePush);
static BOOL PokeathlonCirclePush_IsTeamOut(PokeathlonCirclePush *circlePush, int team);
static void PokeathlonCirclePush_RecoverStamina(PokeathlonCirclePushMon *mon);
static void PokeathlonCirclePush_SetMonStats(PokeathlonCourseData *course, PokeathlonCirclePushRingData *ringData, u8 team, u8 member, PokeathlonCirclePushMon *mon);
static void PokeathlonCirclePush_StartLayoutChange(PokeathlonCirclePushEffects *effects, u8 oldLayout, u8 newLayout, PokeathlonCourseData *course);
static void PokeathlonCirclePush_LayoutChangeTask(SysTask *task, void *data);
static void PokeathlonCirclePush_LayoutFadeTask(SysTask *task, void *data);
static void PokeathlonCirclePush_RingSlideTask(SysTask *task, void *data);
static void PokeathlonCirclePush_ShakeTask(SysTask *task, void *data);
static void PokeathlonCirclePush_StopEffects(PokeathlonCirclePushEffects *effects);
static void PokeathlonCirclePush_StartBounce(PokeathlonCirclePushEffects *effects, u8 mon);
static void PokeathlonCirclePush_BounceTask(SysTask *task, void *data);
static void PokeathlonCirclePush_ApplyBounce(PokeathlonCourseData *course, PokeathlonCirclePushEffects *effects, PokeathlonCourseMonObject *object, u8 mon, int anim);
static void PokeathlonCirclePush_AddScoreWindow(PokeathlonCirclePush *circlePush);
static void PokeathlonCirclePush_PrintScore(PokeathlonCirclePush *circlePush, s32 score);
static BOOL PokeathlonCirclePush_IsOutOfRing(PokeathlonCourseMonObject *object, fx32 x, fx32 y);
static void PokeathlonCirclePush_SortByDepth(PokeathlonCirclePush *circlePush, PokeathlonCirclePushPacket *packet);

static const WindowTemplate sPokeathlonCirclePushScoreWindowTemplate = {
    .bgId = GF_BG_LYR_MAIN_3,
    .left = 0,
    .top = 20,
    .width = 32,
    .height = 2,
    .palette = 15,
    .baseTile = 1,
};

static const VecFx32 sPokeathlonCirclePushDirectionReference = { 0, 0, FX32_ONE };

static const PokeathlonCourseSpritePoolTemplate sPokeathlonCirclePushSpritePoolTemplate = {
    .capacity = 92,
    .resourceCount = 5,
    .resCounts = { 5, 5, 5, 5 },
};

static const GraphicsModes sPokeathlonCirclePushGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_1,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const CirclePushTimerTiles sPokeathlonCirclePushTimerTiles = {
    .tiles = { 0x122, 0x123, 0x124, 0x125, 0x142, 0x143, 0x144, 0x145 },
};

static const CirclePushFallOffsets sPokeathlonCirclePushFallOffsets = {
    .offsets = { 0, 2, 6, 10, 14, 16 },
};

static const CirclePushFallScales sPokeathlonCirclePushFallScales = {
    .scales = { 1.0f, 0.8999999761581421f, 0.800000011920929f, 0.699999988079071f, 0.6000000238418579f, 0.5f },
};

static const BgTemplate sPokeathlonCirclePushBgTemplate_Main0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCirclePushBgTemplate_Main1 = {
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

static const BgTemplate sPokeathlonCirclePushBgTemplate_Main2 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCirclePushBgTemplate_Main3 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCirclePushBgTemplate_Sub0 = {
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

static const BgTemplate sPokeathlonCirclePushBgTemplate_Sub1 = {
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

static const BgTemplate sPokeathlonCirclePushBgTemplate_Sub3 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x400,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_256,
    .screenBase = GX_BG_SCRBASE_0xe800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sPokeathlonCirclePushBgTemplate_Sub2 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const GraphicsBanks sPokeathlonCirclePushGraphicsBanks = {
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

// Where each Pokemon of each team starts.
static const PokeathlonCoursePoint sPokeathlonCirclePushMonStartPositions[POKEATHLON_PARTICIPANTS][POKEATHLON_TEAM_SIZE] = {
    {
     { 0x28, 0x28 },
     { 0x28, 0x48 },
     { 0x58, 0x28 },
     },
    {
     { 0xD8, 0x28 },
     { 0xA8, 0x28 },
     { 0xD8, 0x48 },
     },
    {
     { 0x28, 0xA8 },
     { 0x58, 0xA8 },
     { 0x28, 0x92 },
     },
    {
     { 0xD8, 0xA8 },
     { 0xD8, 0x92 },
     { 0xA8, 0xA8 },
     },
};

PokeathlonCourseStepFunc gPokeathlonCirclePushStates[3] = {
    PokeathlonCirclePush_FadeIn,
    PokeathlonCirclePush_Play,
    PokeathlonCirclePush_End,
};

static s32 sPokeathlonCirclePushBounceOffsets[5] = { -4, -2, 0, 2, 4 };

static s32 sPokeathlonCirclePushShakeOffsets[18] = { -3, -2, -1, 1, 2, 3, -3, -2, -1, 1, 2, 3, -3, -2, -1, 1, 2, 3 };

static inline u32 GetMonSizeType(PokeathlonCourseData *course, int mon) {
    return PokeathlonCourse_GetCollisionSizeClass(PokeathlonCourse_GetPerformance(course, mon / POKEATHLON_TEAM_SIZE, mon % POKEATHLON_TEAM_SIZE));
}

static inline u32 LoadMonInfo(PokeathlonCourseData *course, int mon, PokeathlonCourseMonInfo *infos) {
    int member = mon % POKEATHLON_TEAM_SIZE;
    int team = mon / POKEATHLON_TEAM_SIZE;
    PokeathlonCourse_GetMonInfo(course, team, member, &infos[mon]);
    return PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, team, member));
}

BOOL PokeathlonCirclePush_Init(PokeathlonCourseData *course) {
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case CIRCLE_PUSH_INIT_CREATE: {
        ObjCharTransferTemplate charTemplate;
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_140, 0x50000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonCirclePush_SetBanks();
        circlePush = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonCirclePush));
        MI_CpuFill8(circlePush, 0, sizeof(PokeathlonCirclePush));
        circlePush->sortBuffer = Heap_Alloc(HEAP_ID_140, 40);
        MI_CpuFill8(circlePush->sortBuffer, 0, 40);
        circlePush->bgConfig = BgConfig_Alloc(HEAP_ID_140);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        charTemplate.maxTasks = 104;
        charTemplate.sizeMain = 0x40000;
        charTemplate.sizeSub = 0x4000;
        charTemplate.heapID = HEAP_ID_140;
        PokeathlonCourse_InitObjTransfer(&charTemplate, 22, HEAP_ID_140, GX_OBJVRAMMODE_CHAR_1D_256K, GX_OBJVRAMMODE_CHAR_1D_32K);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_140);
        circlePush->heapId = HEAP_ID_140;
        FontID_Alloc(4, HEAP_ID_140);
        PokeathlonCirclePush_InitBgs(circlePush->bgConfig);
        PokeathlonCirclePush_AddScoreWindow(circlePush);
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case CIRCLE_PUSH_INIT_CREATE_DISPLAY: {
        int participants;
        circlePush->display = PokeathlonCirclePushDisplay_New(circlePush->heapId, circlePush->bgConfig, course);
        participants = PokeathlonCourse_GetParticipantCount(course);
        circlePush->ai = PokeathlonCirclePushAi_New(circlePush->heapId, 4 - participants, PokeathlonCourse_GetMode(course));
        circlePush->spriteResources = PokeathlonCourseSprites_CreateResources(circlePush->heapId, 2727, NNS_G2D_VRAM_TYPE_2DMAIN);
        circlePush->zoneMarkers = PokeathlonCirclePushZoneMarkers_New(circlePush->heapId);
        circlePush->effects.markers = circlePush->zoneMarkers;
        PokeathlonCirclePushDisplay_LoadPics(circlePush->display);
        PokeathlonCourse_InitMarkers(course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case CIRCLE_PUSH_INIT_CREATE_SPRITES: {
        int i;
        PokeathlonCourseSpritePoolTemplate template = sPokeathlonCirclePushSpritePoolTemplate;
        circlePush->spritePool = PokeathlonCourseSpritePool_New(circlePush->heapId, &template);
        PokeathlonCourseSpritePool_SetSurfaceCoords(circlePush->spritePool, 0, 0, 0, FX32_CONST(512));
        circlePush->objects = PokeathlonCourseMonObjects_Create(circlePush->heapId, POKEATHLON_MONS, 5, circlePush->spriteResources, PokeathlonCourseSpritePool_GetSpriteList(circlePush->spritePool));
        PokeathlonCourseSpritePool_SetResourceId(circlePush->spritePool, 0, 101);
        PokeathlonCourseSpritePool_SetResourceId(circlePush->spritePool, 1, 104);
        PokeathlonCourseSpritePool_SetResourceId(circlePush->spritePool, 2, 102);
        PokeathlonCourseSpritePool_SetResourceId(circlePush->spritePool, 3, 103);
        PokeathlonCourseSpritePool_SetResourceId(circlePush->spritePool, 4, 105);
        PokeathlonCourseSpritePool_LoadChar(circlePush->spritePool, NARC_a_1_6_7, 3, 101, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(circlePush->spritePool, NARC_a_1_6_7, 0, 101, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(circlePush->spritePool, NARC_a_1_6_7, 2, 101);
        PokeathlonCourseSpritePool_LoadAnim(circlePush->spritePool, NARC_a_1_6_7, 1, 101);
        PokeathlonCourseSpritePool_LoadChar(circlePush->spritePool, NARC_a_1_6_7, 28, 104, NNS_G2D_VRAM_TYPE_2DMAIN);
        PokeathlonCourseSpritePool_LoadPltt(circlePush->spritePool, NARC_a_1_6_7, 25, 104, NNS_G2D_VRAM_TYPE_2DMAIN, 1);
        PokeathlonCourseSpritePool_LoadCell(circlePush->spritePool, NARC_a_1_6_7, 27, 104);
        PokeathlonCourseSpritePool_LoadAnim(circlePush->spritePool, NARC_a_1_6_7, 26, 104);
        PokeathlonCourseSpritePool_LoadChar(circlePush->spritePool, NARC_a_1_6_7, 32, 105, NNS_G2D_VRAM_TYPE_2DSUB);
        PokeathlonCourseSpritePool_LoadPltt(circlePush->spritePool, NARC_a_1_6_7, 29, 105, NNS_G2D_VRAM_TYPE_2DSUB, 5);
        PokeathlonCourseSpritePool_LoadCell(circlePush->spritePool, NARC_a_1_6_7, 31, 105);
        PokeathlonCourseSpritePool_LoadAnim(circlePush->spritePool, NARC_a_1_6_7, 30, 105);
        PokeathlonCirclePushDisplay_LoadSpriteResources(circlePush->spritePool, circlePush->display);
        PokeathlonCourseSpritePool_TransferResources(circlePush->spritePool);
        for (i = 0; i < CIRCLE_PUSH_ZONE_MARKERS; i++) {
            PokeathlonCourseSpritePool_CreateSprite(circlePush->spritePool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 101, 2);
        }
        for (i = 0; i < POKEATHLON_MONS; i++) {
            PokeathlonCourseSpritePool_CreateSprite(circlePush->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 4);
            PokeathlonCourseSpritePool_CreateSprite(circlePush->spritePool, 1, NNS_G2D_VRAM_TYPE_2DMAIN, 104, 7);
        }
        PokeathlonCirclePushZoneMarkers_CreateSprites(circlePush->zoneMarkers, circlePush->spritePool);
        for (i = 0; i < POKEATHLON_MONS; i++) {
            PokeathlonCirclePush *view = (PokeathlonCirclePush *)&((PokeathlonCirclePushMon(*)[3])circlePush)[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
            view->mons[0][0].effectSprite = PokeathlonCourseSpritePool_Take(circlePush->spritePool, 104, 4);
            Sprite_SetDrawPriority(PokeathlonCourseSpritePoolSprite_GetSprite(view->mons[0][0].effectSprite), 2);
            view->mons[0][0].tiredSprite = PokeathlonCourseSpritePool_Take(circlePush->spritePool, 104, 7);
            Sprite_SetDrawPriority(PokeathlonCourseSpritePoolSprite_GetSprite(view->mons[0][0].tiredSprite), 4);
        }
        circlePush->markerSprite = *PokeathlonCourse_CreateHudSpritesInPool(course, 0, circlePush->spriteResources, circlePush->spritePool);
        Sprite_SetDrawPriority(circlePush->markerSprite, 1);
        PokeathlonCirclePushDisplay_CreatePicSprites(circlePush->spritePool, circlePush->display);
        PokeathlonCirclePushDisplay_CreateSprites(circlePush->spritePool, circlePush->display);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case CIRCLE_PUSH_INIT_LOAD_MONS: {
        PokeathlonCourseMonInfo infos[POKEATHLON_MONS];
        PokeathlonCourseMonGfxTemplate template;
        s32 i;
        for (i = 0; i < POKEATHLON_MONS; i++) {
            PokeathlonCirclePushMon *mon;
            template.sizeTypes[i] = LoadMonInfo(course, i, infos);
            mon = &circlePush->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
            PokeathlonCourseMonGfx_LoadPalette(&infos[i], circlePush->heapId, mon->palette);
            MI_CpuCopy8(mon->palette, mon->grayPalette, 32);
            TintPalette_GrayScale(mon->grayPalette, 16);
        }
        template.loadAtOnce = FALSE;
        template.priority = 1;
        template.vramTransfer = FALSE;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(circlePush->objects, POKEATHLON_MONS, infos, &template, FALSE, FALSE);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case CIRCLE_PUSH_INIT_PLACE_MONS: {
        s32 i;
        int own;

        PokeathlonCoursePoint ownPositions[3];

        PokeathlonCourseCollision collision[POKEATHLON_SIZE_CLASSES];
        VecFx32 scale;
        VecFx32 *scalePtr = &scale;
        u8 ringData[60];
        int x;
        int y;
        if (!PokeathlonCourseMonObjects_IsLoaded(circlePush->objects)) {
            break;
        }
        own = PokeathlonCourse_GetNetId(course);
        PokeathlonCourse_SetVBlankIntrCB(circlePush->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        ReadWholeNarcMemberByIdPair(collision, NARC_a_1_7_0, 11);
        for (i = 0; i < POKEATHLON_MONS; i++) {
            PokeathlonCourseMonObject *object = PokeathlonCourseMonObjects_Get(circlePush->objects, i);
            PokeathlonCourseMonGfx *gfx;
            int team;
            int member;
            PokeathlonCirclePushMon *mon;
            int topRow;
            int startX;
            int startY;
            PokeathlonCourseMonObject_SetDrawFlag(object, 1);
            {
                // collision circle by size type 1..3
                PokeathlonCourseCollision *entry = &collision[GetMonSizeType(course, i)];
                PokeathlonCourseObject_SetCollision(object, entry[-1].offsetY, entry[-1].radius);
            }
            object = PokeathlonCourseMonObjects_Get(circlePush->objects, i);
            gfx = PokeathlonCourseMonObject_GetGfx(object);
            scalePtr->x = 0;
            scalePtr->y = 0;
            scalePtr->z = 0;
            team = i / POKEATHLON_TEAM_SIZE;
            member = i % POKEATHLON_TEAM_SIZE;
            mon = &circlePush->mons[team][member];
            mon->object = object;
            mon->state = CIRCLE_PUSH_MON_IN_RING;
            topRow = PokeathlonCourseMonGfx_GetTopRow(gfx);
            if (((u16 *)PokeathlonCourseMonGfx_GetInfo(gfx))[2]) {
                scale.x = 0x20000;
                scale.y = (topRow + (64 - topRow) / 2) << FX32_SHIFT;
            } else {
                scale.x = 0x10000;
                scale.y = (topRow + (32 - topRow) / 2) << FX32_SHIFT;
            }
            startX = sPokeathlonCirclePushMonStartPositions[team][member].x;
            startY = sPokeathlonCirclePushMonStartPositions[team][member].y;
            mon->direction = 2;
            PokeathlonCourseMonObject_SetAnimState(object, 2);
            PokeathlonCourseObject_SetGroundPosition(object, startX, startY);
            PokeathlonCourseObject_SetTouchRadius(object, PokeathlonCourse_GetTouchRadius());
            PokeathlonCourseObject_GroundToCenter(object, startX, startY, &x, &y);
            mon->x = x << FX32_SHIFT;
            mon->y = y << FX32_SHIFT;
            mon->position.x = x << FX32_SHIFT;
            mon->position.y = y << FX32_SHIFT;
            mon->target.x = x << FX32_SHIFT;
            mon->target.y = y << FX32_SHIFT;
            if (team == PokeathlonCourse_GetNetId(course)) {
                PokeathlonCourseMonObject_SetDrawPriority(object, 5);
            } else {
                PokeathlonCourseMonObject_SetDrawPriority(object, 6);
            }
            PokeathlonCourseMonObject_SetAffineMatrix(object, &scale);
            if (PokeathlonCourse_GetNetId(course) == 0) {
                PokeathlonCirclePush_MakePacket(circlePush, (PokeathlonCirclePushPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT));
            }
            if (team == own) {
                ownPositions[member].x = x;
                ownPositions[member].y = y;
                Sprite_SetDrawPriority(PokeathlonCourse_AddMarker(course, object, circlePush->spriteResources, PokeathlonCourseSpritePool_GetSpriteList(circlePush->spritePool), 1), 3);
            }
        }
        PokeathlonCourse_CreateStartSpritesInPool(course, 0, circlePush->spriteResources, circlePush->spritePool, NNS_G2D_VRAM_TYPE_2DMAIN, 3, ownPositions);
        ReadWholeNarcMemberByIdPair(ringData, NARC_a_1_7_0, 1);
        {
            int team;
            int member;
            for (team = 0; team < POKEATHLON_PARTICIPANTS; team++) {
                circlePush->heldMons[team] = POKEATHLON_NO_MON;
                for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
                    PokeathlonCirclePushMon *mon = &circlePush->mons[team][member];
                    PokeathlonCirclePush_SetMonStats(course, (PokeathlonCirclePushRingData *)ringData, team, member, mon);
                    PokeathlonCirclePushAi_SetMon(circlePush->ai, member + team * 3, mon->pushSpeed, &mon->stamina, &mon->position, &mon->state, &mon->target, mon->object);
                }
            }
        }
        circlePush->layout = 0;
        circlePush->nextLayout = 0;
        circlePush->effects.bounceMon = POKEATHLON_NO_MON;
        PokeathlonCirclePushZoneMarkers_Show(circlePush->zoneMarkers, circlePush->layout);
        G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0, 12, 4);
        circlePush->scoringMon = POKEATHLON_NO_MON;
        PokeathlonCirclePush_LoadBgGfx(circlePush);
        PokeathlonCirclePushDisplay_PrintPlayerNames(circlePush->display);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        WirelessStatusIcon_CreateOnScreenIfConnected(1);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case CIRCLE_PUSH_INIT_DONE:
        return TRUE;
    }
    return FALSE;
}

BOOL PokeathlonCirclePush_Main(PokeathlonCourseData *course) {
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);
    PokeathlonCourseSpritePool_Draw(circlePush->spritePool);
    return TRUE;
}

// The event's points: the points the teams collected.
BOOL PokeathlonCirclePush_CalcResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *scoreList;
    int i;
    PokeathlonCourse_GetWork(course);
    scoreList = PokeathlonCourse_GetGraphicsSystem(course);
    PokeathlonCourseScoreList_Init(scoreList);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, scoreList, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00293);
    }
    PokeathlonCourseScoreList_Rank(scoreList, 1);
    PokeathlonEvent_CalcPoints(scoreList, 2);
    PokeathlonCourseScoreList_AddPointsToTotals(scoreList);
    PokeathlonCourseScoreList_SaveEventPoints(scoreList, 2);
    return TRUE;
}

BOOL PokeathlonCirclePush_Exit(PokeathlonCourseData *course) {
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);
    WirelessStatusIcon_Destroy();
    PokeathlonCourse_FreeMarkers(course);
    PokeathlonCirclePushZoneMarkers_Free(circlePush->zoneMarkers);
    Heap_Free(circlePush->ringScreenFile);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(circlePush->bgConfig, GF_BG_LYR_SUB_3);
    RemoveWindow(&circlePush->scoreWindow);
    Heap_Free(circlePush->bgConfig);
    PokeathlonCourseSpritePool_Free(circlePush->spritePool);
    PokeathlonCourseMonObjects_Free(circlePush->objects);
    PokeathlonCourseSprites_FreeResources(circlePush->spriteResources);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    PokeathlonCirclePushAi_Free(circlePush->ai);
    PokeathlonCirclePushDisplay_Free(circlePush->display);
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    Heap_Free(circlePush->sortBuffer);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    reg_G2_BLDCNT = 0;
    Heap_Destroy(HEAP_ID_140);
    return TRUE;
}

static void PokeathlonCirclePush_SetBanks(void) {
    GraphicsBanks banks = sPokeathlonCirclePushGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

enum PokeathlonCirclePushFadeInState {
    CIRCLE_PUSH_FADE_IN_START,
    CIRCLE_PUSH_FADE_IN_FADE,
    CIRCLE_PUSH_FADE_IN_WAIT,
};

BOOL PokeathlonCirclePush_FadeIn(PokeathlonCourseData *course, u8 *state) {
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);
    switch (*state) {
    case CIRCLE_PUSH_FADE_IN_START:
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_CIRCLE_PUSH);
        (*state)++;
        break;
    case CIRCLE_PUSH_FADE_IN_FADE:
        BeginNormalPaletteFade(FADE_SUB_THEN_MAIN, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, circlePush->heapId);
        (*state)++;
        break;
    case CIRCLE_PUSH_FADE_IN_WAIT:
        if (IsPaletteFadeFinished()) {
            PokeathlonCourse_SetNextState(course, CIRCLE_PUSH_STATE_PLAY);
        }
        break;
    }
    return FALSE;
}

BOOL PokeathlonCirclePush_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case EVENT_PLAY_STATE_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_RUN:
        PokeathlonCirclePush_RunHost(course);
        if (PokeathlonCirclePush_Update(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_FINISH:
        if (PokeathlonCourse_RunFinish(course)) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, circlePush->heapId);
            PokeathlonCourse_SetNextState(course, CIRCLE_PUSH_STATE_END);
        }
        break;
    }
    return FALSE;
}

// The host keeps the teams' points of the event (the points of their Pokemon).
BOOL PokeathlonCirclePush_End(PokeathlonCourseData *course, u8 *state) {
    int team;
    PokeathlonCirclePush *circlePush;
    circlePush = PokeathlonCourse_GetWork(course);
    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return FALSE;
    }
    if (PokeathlonCourse_GetNetId(course)) {
        return TRUE;
    }
    for (team = 0; team < POKEATHLON_PARTICIPANTS; team++) {
        int points = 0;
        int member = points;
        for (; member < POKEATHLON_TEAM_SIZE; member++) {
            points += circlePush->mons[team][member].points;
            PokeathlonCourse_SetEventScore(course, (u8)team, points);
        }
    }
    return TRUE;
}

static void PokeathlonCirclePush_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate main0;
    BgTemplate main1;
    BgTemplate main2;
    BgTemplate main3;
    BgTemplate sub0;
    BgTemplate sub1;
    BgTemplate sub3;
    BgTemplate sub2;

    modes = sPokeathlonCirclePushGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    main0 = sPokeathlonCirclePushBgTemplate_Main0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &main0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    main1 = sPokeathlonCirclePushBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    main2 = sPokeathlonCirclePushBgTemplate_Main2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &main2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    main3 = sPokeathlonCirclePushBgTemplate_Main3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main3, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    sub0 = sPokeathlonCirclePushBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &sub0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    sub1 = sPokeathlonCirclePushBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &sub1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    sub3 = sPokeathlonCirclePushBgTemplate_Sub3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_3, &sub3, GF_BG_TYPE_AFFINE);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_3);
    sub2 = sPokeathlonCirclePushBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &sub2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
}

static void PokeathlonCirclePush_LoadBgGfx(PokeathlonCirclePush *circlePush) {
    void *file;
    NNSG2dScreenData *screen;

    GfGfxLoader_LoadCharData(NARC_a_1_6_7, 5, circlePush->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, circlePush->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_7, 9, circlePush->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, FALSE, circlePush->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_7, 12, circlePush->bgConfig, GF_BG_LYR_SUB_1, 0, 0x1000, FALSE, circlePush->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_7, 22, circlePush->bgConfig, GF_BG_LYR_SUB_3, 0, 0, FALSE, circlePush->heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_6_7, 15, circlePush->bgConfig, GF_BG_LYR_SUB_2, 0x80, 0, FALSE, circlePush->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_6_7, 6, circlePush->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, circlePush->heapId);
    file = GfGfxLoader_GetScrnData(NARC_a_1_6_7, 10, FALSE, &screen, circlePush->heapId);
    BG_LoadScreenTilemapData(circlePush->bgConfig, GF_BG_LYR_MAIN_2, screen->rawData, screen->szByte);
    BgTilemapRectChangePalette(circlePush->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 32, 24, 1);
    ScheduleBgTilemapBufferTransfer(circlePush->bgConfig, GF_BG_LYR_MAIN_2);
    Heap_Free(file);
    circlePush->ringScreenFile = GfGfxLoader_GetScrnData(NARC_a_1_6_7, 7, FALSE, &circlePush->ringScreen, circlePush->heapId);
    BG_LoadScreenTilemapData(circlePush->bgConfig, GF_BG_LYR_MAIN_1, circlePush->ringScreen->rawData, circlePush->ringScreen->szByte);
    BgCopyOrUncompressTilemapBufferRangeToVram(circlePush->bgConfig, GF_BG_LYR_MAIN_1, circlePush->ringScreen->rawData, circlePush->ringScreen->szByte, 0);
    PokeathlonCirclePushDisplay_LoadScreens(circlePush->display);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_7, 4, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x20, circlePush->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_7, 8, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_1_OFFSET, 0x20, circlePush->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_7, 21, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x40, circlePush->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_7, 11, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_2_OFFSET, 0x20, circlePush->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_6_7, 14, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_3_OFFSET, 0x20, circlePush->heapId);
    reg_G2_BG2OFS = 0x00800000;
}

// The host's state of the twelve Pokemon for the players (the packet).

static void PokeathlonCirclePush_MakePacket(PokeathlonCirclePush *circlePush, PokeathlonCirclePushPacket *packet) {
    u8 i;
    int x;
    int y;
    u32 points;
    int team;
    PokeathlonCirclePushMon(*mons)[3];
    u32 shapeBits;
    u32 stateBits;
    u32 heldBits;

    shapeBits = 0;
    stateBits = 0;
    heldBits = 0;
    i = 0;
    mons = circlePush->mons;
    for (; i < POKEATHLON_MONS; i++) {
        PokeathlonCirclePushMon *mon = &mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];

        x = mon->position.x / FX32_ONE;
        y = mon->position.y / FX32_ONE;
        if (x < 0) {
            x = 0;
        } else if (x > 255) {
            x = 255;
        }
        if (y < 0) {
            y = 0;
        } else if (y > 255) {
            y = 255;
        }
        {
            u8 state = mon->state;
            u8 direction = mon->direction;

            packet->x[i] = x;
            packet->y[i] = y;
            shapeBits += (direction - 1) << (2 * i);
            stateBits += state << (2 * i);
        }
        heldBits += mon->exhausted << i;
    }

    packet->shapeBits = shapeBits;
    packet->shapeBits += circlePush->timer << 24;
    packet->stateBits = 0;
    packet->stateBits += stateBits;
    packet->stateBits += circlePush->nextLayout << 24;
    packet->stateBits += circlePush->scoringMon << 28;

    team = circlePush->packetTeam;
    points = circlePush->scores[team];
    circlePush->packetTeam = (team + 1) % 4;

    packet->flagBits = 0;
    packet->flagBits += heldBits;
    packet->flagBits += circlePush->over << 12;
    packet->flagBits += circlePush->roundStart << 13;
    packet->flagBits += circlePush->scoring << 14;
    packet->flagBits += circlePush->scoringEffect << 15;
    packet->flagBits += (u8)points << 18;
    packet->flagBits += team << 26;
    packet->flagBits += circlePush->round << 28;

    circlePush->roundStart = 0;
    circlePush->scoringMon = POKEATHLON_NO_MON;
    circlePush->scoringEffect = 0;
}

// Every player: sends the touch, follows the host's packet. Returns TRUE when the event is over.
static BOOL PokeathlonCirclePush_Update(PokeathlonCourseData *course) {
    PokeathlonCirclePush *circlePush;
    u8 *copyArea;
    PokeathlonCirclePushInput *input;

    circlePush = PokeathlonCourse_GetWork(course);
    copyArea = PokeathlonCourse_GetDataCopyArea(course);
    input = (PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(copyArea);
    input->touching = FALSE;
    copyArea = PokeathlonCourse_ToBytes(copyArea + POKEATHLON_COURSE_DATA_FRAME_IN);
    {
        s32 flagBits = ((PokeathlonCirclePushPacket *)copyArea)->flagBits;
        u8 over = (flagBits >> 12) & 1;
        if (over) {
            PokeathlonCourseSpritePool_PauseAnims(circlePush->spritePool, TRUE);
            PokeathlonCourseObjects_PauseAnims(circlePush->objects, TRUE);
            PokeathlonCourse_StopMarkerAnims(course);
            u16 score = PokeathlonCirclePushDisplay_GetScore(circlePush->display);
            PokeathlonCourse_SetRecordScore(course, score);
            PokeathlonCirclePush_PrintScore(circlePush, score);
            return TRUE;
        }
    }
    if (circlePush->changeLayout != 0) {
        int kind;
        u8 round = circlePush->round;
        if (round < 1) {
            kind = 0;
        } else if (round < 3) {
            kind = 1;
        } else if (round < 4) {
            kind = 2;
        } else {
            kind = 3;
        }
        circlePush->nextLayout = PokeathlonCirclePush_ChooseLayout(circlePush->nextLayout, kind);
        circlePush->changeLayout = 0;
    }
    if (System_GetTouchNew()) {
        PokeathlonCourse_AddMonCounter(course, PokeathlonCourse_GetNetId(course), 3, POKEATHLON_COUNTER_INSTRUCTIONS, 1);
    }
    if (System_GetTouchHeld()) {
        input->x = gSystem.touchX;
        input->y = gSystem.touchY;
        input->touching = TRUE;
    }
    PokeathlonCirclePush_UpdateScreen(course);
    return FALSE;
}

// Host: the round timer, the scoring at its end, the players' touches and the CPU teams; then
// moves the Pokemon and makes the packet.

static void PokeathlonCirclePush_RunHost(PokeathlonCourseData *course) {
    CirclePushHostFrame frame;
    frame.copyArea = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);
    if (PokeathlonCourse_GetNetId(course)) {
        return;
    }
    PokeathlonCirclePushPacket *packet = (PokeathlonCirclePushPacket *)PokeathlonCourse_ToBytes(frame.copyArea + POKEATHLON_COURSE_DATA_FRAME_OUT);
    if (circlePush->waitingForReady == TRUE) {
        u8 ready = 0;
        int i;
        frame.count = PokeathlonCourse_GetParticipantCount(course);
        i = ready;
        if (frame.count > 0) {
            u8 *entry = frame.copyArea + POKEATHLON_COURSE_DATA_INPUTS;
            do {
                frame.ptr.input = (PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(entry);
                if (frame.ptr.input->ready) {
                    ready++;
                }
                entry += POKEATHLON_COURSE_DATA_SLOT_SIZE;
                i++;
            } while (i < frame.count);
        }
        if (ready == frame.count) {
            circlePush->timer = 0;
            circlePush->scoring = 0;
            circlePush->waitingForReady = FALSE;
        }
    } else if (circlePush->roundDelay) {
        circlePush->roundDelay--;
        if (circlePush->roundDelay == 0) {
            circlePush->waitingForReady = TRUE;
        } else if (circlePush->roundDelay == 60) {
            circlePush->changeLayout = 1;
            circlePush->round++;
        }
    } else if (circlePush->scoring) {
        circlePush->timer = 44;
        if (circlePush->scoringDelay == 0) {
            if (circlePush->scoringTimer == 0) {
                if (circlePush->scoringIndex >= circlePush->scoringCount) {
                    PokeathlonCirclePush_RespawnMons(circlePush);
                    circlePush->roundDelay = 90;
                } else {
                    circlePush->scoringMon = circlePush->scoringMons[circlePush->scoringIndex];
                    circlePush->scoringEffect = PokeathlonCirclePush_GetPointsEffect(circlePush->scoringPoints[circlePush->scoringIndex]);
                    u8 team = circlePush->scoringMon / POKEATHLON_TEAM_SIZE;
                    int *scores = circlePush->scores;
                    scores[team] += circlePush->scoringPoints[circlePush->scoringIndex];
                    circlePush->scoringIndex++;
                    circlePush->scoringTimer = 6;
                    PokeathlonCourse_AddMonCounter(course, team, circlePush->scoringMon % POKEATHLON_TEAM_SIZE, POKEATHLON_COUNTER_POINTS, 1);
                }
            } else {
                circlePush->scoringTimer--;
            }
        } else {
            circlePush->scoringDelay--;
        }
    } else {
        int interval;
        if (circlePush->round < 1) {
            interval = 8;
        } else if (circlePush->round < 3) {
            interval = 6;
        } else {
            interval = 4;
        }
        circlePush->timerTick++;
        if (circlePush->timerTick >= interval) {
            circlePush->timerTick = 0;
            circlePush->timer++;
            if (circlePush->timer >= 43) {
                circlePush->scoreZones = 1;
                circlePush->roundStart = 1;
                circlePush->scoring = 1;
                circlePush->scoringDelay = 20;
                int i;
                for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                    circlePush->heldMons[i] = POKEATHLON_NO_MON;
                }
                for (i = 0; i < POKEATHLON_MONS; i++) {
                    PokeathlonCirclePushMon *mon = &circlePush->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
                    mon->target = mon->position;
                    mon->velocity.x = 0;
                    mon->velocity.y = 0;
                    mon->stamina = mon->maxStamina;
                    mon->exhausted = 0;
                    mon->exhaustTimer = 0;
                    mon->boost = 0;
                    mon->boostTimer = 0;
                }
            }
        }
    }
    if (circlePush->round >= 6) {
        circlePush->over = 1;
    } else {
        circlePush->over = 0;
    }
    PokeathlonCirclePushInput *hostInput = (PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(frame.copyArea + POKEATHLON_COURSE_DATA_INPUTS);
    PokeathlonCirclePushInput *ownInput = (PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(frame.copyArea);
    *hostInput = *ownInput;
    if (!circlePush->scoring) {
        int player = 0;
        u8 *inputs = frame.copyArea + POKEATHLON_COURSE_DATA_INPUTS;
        PokeathlonCirclePush *view = circlePush;
        PokeathlonCirclePushMon *teamMons = circlePush->mons[0];
        for (; player < POKEATHLON_PARTICIPANTS; player++, inputs += POKEATHLON_COURSE_DATA_SLOT_SIZE, view = (PokeathlonCirclePush *)((u8 *)view + sizeof(PokeathlonCourseTouch)), teamMons += 3) {
            PokeathlonCirclePushInput *input = (PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(inputs);
            if (input->touching) {
                if (view->touches[0].pressed && view->touches[0].held) {
                    view->touches[0].pressed = FALSE;
                } else if (!view->touches[0].pressed && !view->touches[0].held) {
                    view->touches[0].pressed = TRUE;
                    view->touches[0].held = TRUE;
                }
            } else {
                view->touches[0].pressed = FALSE;
                view->touches[0].held = FALSE;
            }
            if (view->touches[0].pressed) {
                if (!PokeathlonCirclePush_IsTeamOut(circlePush, player)) {
                    int mon = PokeathlonCirclePush_FindTouchedMon(circlePush, player, input->x, input->y);
                    if (mon != POKEATHLON_NO_MON) {
                        PokeathlonCirclePushMon *touched = &teamMons[mon % POKEATHLON_TEAM_SIZE];
                        circlePush->heldMons[player] = mon;
                        touched->boost = 2;
                        touched->boostTimer = 3;
                    }
                }
            } else if (view->touches[0].held) {
                if (circlePush->heldMons[player] != POKEATHLON_NO_MON) {
                    u8 member = circlePush->heldMons[player] % POKEATHLON_TEAM_SIZE;
                    frame.ptr.mon = &teamMons[member];
                    PokeathlonCirclePush_SetTarget(input->x, input->y, &frame.ptr.mon->position, 0, &frame.ptr.mon->target);
                    if (PokeathlonCirclePush_IsOutOfRing(frame.ptr.mon->object, frame.ptr.mon->target.x, frame.ptr.mon->target.y)) {
                        circlePush->targetOutOfRing[circlePush->heldMons[player]] = 1;
                    } else {
                        circlePush->targetOutOfRing[circlePush->heldMons[player]] = 0;
                    }
                }
            } else if (circlePush->heldMons[player] != POKEATHLON_NO_MON) {
                circlePush->heldMons[player] = POKEATHLON_NO_MON;
            }
        }
        int mon = PokeathlonCirclePushAi_Update(circlePush->ai, circlePush->nextLayout);
        if (mon != POKEATHLON_NO_MON) {
            u8 team = mon / POKEATHLON_TEAM_SIZE;
            if (team >= PokeathlonCourse_GetParticipantCount(course)) {
                PokeathlonCirclePushMon *cpuMon = &circlePush->mons[team][mon % POKEATHLON_TEAM_SIZE];
                cpuMon->boost = 2;
                cpuMon->boostTimer = 3;
            } else {
                GF_ASSERT(FALSE);
            }
        }
    }
    PokeathlonCirclePush_MoveMons(course);
    PokeathlonCirclePush_UpdateContacts(circlePush);
    PokeathlonCirclePush_ScoreZones(circlePush);
    PokeathlonCirclePush_MakePacket(circlePush, packet);
}

static inline void SetMonAnim(PokeathlonCourseData *course, PokeathlonCirclePush *circlePush, PokeathlonCirclePushMon *mon, int index, int team, u8 own, int anim, int x, int y, VecFx32 *pos, u8 scoring, Sprite *sprite) {
    PokeathlonCourseMonObject *object;

    switch (PokeathlonCourse_GetPerformance(course, index / POKEATHLON_TEAM_SIZE, index % POKEATHLON_TEAM_SIZE)->heightClass) {
    case 1:
        pos->y -= FX32_CONST(8);
        break;
    case 2:
        pos->y -= FX32_CONST(8);
        break;
    case 3:
        pos->y -= FX32_CONST(16);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    Sprite_SetMatrix(PokeathlonCourseSpritePoolSprite_GetSprite(mon->tiredSprite), pos);
    object = PokeathlonCourseMonObjects_Get(circlePush->objects, index);
    PokeathlonCourseMonObject_SetAnimState(object, anim);
    PokeathlonCourseObject_SetCenterPosition(object, x, y, TRUE);
    if (team == own && PokeathlonCourse_GetMonStats(course, own, index % POKEATHLON_TEAM_SIZE)[2]) {
        PokeathlonCourseMonObject_Move(object, 0, circlePush->effects.shakeOffset, anim, FALSE);
    }
    if (scoring) {
        PokeathlonCourseMonObject *bounced = PokeathlonCourseMonObjects_Get(circlePush->objects, index);
        Sprite_SetAnimActiveFlag(sprite, FALSE);
        circlePush->effects.bounceActive = TRUE;
        PokeathlonCirclePush_ApplyBounce(course, &circlePush->effects, bounced, index, anim);
    } else {
        Sprite_SetAnimActiveFlag(sprite, TRUE);
    }
}

// Every player: draws the Pokemon, the timer and the effects from the host's packet.

static void PokeathlonCirclePush_UpdateScreen(PokeathlonCourseData *course) {
    s32 scoringMon;
    u8 roundStart;
    u8 scoring;
    u8 packetTeam;
    u8 teamPoints;
    u8 round;
    PokeathlonCirclePushPacket *packet;
    u8 direction;
    u8 state;
    u8 exhausted;
    Sprite *sprite;
    int offset;
    u8 own;
    u8 effect;
    s32 y;
    s32 x;
    int member;
    s32 i;
    int layout;
    u8 timer;
    PokeathlonCirclePush *circlePush;
    u8 outOfRing[POKEATHLON_MONS];

    circlePush = PokeathlonCourse_GetWork(course);
    packet = (PokeathlonCirclePushPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    own = PokeathlonCourse_GetNetId(course);
    scoringMon = (packet->stateBits >> 28) & 0xF;
    layout = (packet->stateBits >> 24) & 0xF;
    timer = packet->shapeBits >> 24;
    roundStart = (packet->flagBits >> 13) & 1;
    scoring = (packet->flagBits >> 14) & 1;
    effect = (packet->flagBits >> 15) & 7;
    packetTeam = (packet->flagBits >> 26) & 3;
    teamPoints = packet->flagBits >> 18;
    round = (u8)((packet->flagBits >> 28) & 0xF) + 1;

    if (!scoring) {
        ((PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course)))->ready = 0;
    }
    {
        u8 oldLayout = circlePush->layout;
        u8 newLayout = layout;
        if (oldLayout != newLayout) {
            circlePush->layout = newLayout;
            for (i = 0; i < POKEATHLON_MONS; i++) {
                circlePush->grayed[i] = 0;
            }
            PokeathlonCirclePush_StartLayoutChange(&circlePush->effects, oldLayout, newLayout, course);
        }
    }
    if (timer == 0) {
        BG_LoadScreenTilemapData(circlePush->bgConfig, GF_BG_LYR_MAIN_1, circlePush->ringScreen->rawData, circlePush->ringScreen->szByte);
        ScheduleBgTilemapBufferTransfer(circlePush->bgConfig, GF_BG_LYR_MAIN_1);
        circlePush->alarm = FALSE;
    } else if (timer < 43) {
        if (!circlePush->alarm) {
            if (round <= 1 && timer >= 32) {
                PlaySE(SEQ_SE_DP_TRAIN04);
                circlePush->alarm = TRUE;
            } else if (round > 1 && timer >= 28) {
                PlaySE(SEQ_SE_DP_TRAIN04);
                circlePush->alarm = TRUE;
            } else if (round > 3 && timer >= 21) {
                PlaySE(SEQ_SE_DP_TRAIN04);
                circlePush->alarm = TRUE;
            }
        }
        PokeathlonCirclePush_DrawTimer(timer, circlePush->bgConfig);
    } else {
        CirclePushTimerTiles tiles = sPokeathlonCirclePushTimerTiles;
        LoadRectToBgTilemapRect(circlePush->bgConfig, GF_BG_LYR_MAIN_1, &tiles, 14, 2, 4, 2);
        PokeathlonCirclePush_DrawTimer(42, circlePush->bgConfig);
    }
    if (roundStart) {
        PlaySE(SEQ_SE_GS_TIMERZERO);
    }
    PokeathlonCirclePushDisplay_SetRound(circlePush->display, round);

    for (i = 0; i < POKEATHLON_MONS; i++) {
        PokeathlonCirclePushMon *mon;
        member = i % POKEATHLON_TEAM_SIZE;
        mon = &circlePush->mons[(i / POKEATHLON_TEAM_SIZE)][member];
        sprite = PokeathlonCourseMonGfx_GetSprite(PokeathlonCourseMonObject_GetGfx(mon->object));
        state = (packet->stateBits >> (i * 2)) & 3;
        exhausted = (packet->flagBits >> i) & 1;
        if (state == CIRCLE_PUSH_MON_OUT) {
            offset = 0;
            if (circlePush->falls[i].state == FALL_STATE_NONE) {
                circlePush->falls[i].state = FALL_STATE_FALLING;
            } else if (circlePush->falls[i].state == FALL_STATE_FALLING) {
                VecFx32 scale;
                CirclePushFallScales scales = sPokeathlonCirclePushFallScales;
                CirclePushFallOffsets offsets = sPokeathlonCirclePushFallOffsets;
                int groundX;
                int groundY;
                scale.x = 4096.0f * scales.scales[circlePush->falls[i].timer / 2];
                scale.y = 4096.0f * scales.scales[circlePush->falls[i].timer / 2];
                scale.z = 4096.0f * scales.scales[circlePush->falls[i].timer / 2];
                PokeathlonCourseObject_CenterToGround(mon->object, packet->x[i], packet->y[i], &groundX, &groundY);
                if (groundY >= 176) {
                    offset = offsets.offsets[circlePush->falls[i].timer / 2];
                }
                circlePush->falls[i].timer++;
                PokeathlonCourseMonObject_SetAffineOverwriteMode(mon->object, NNS_G2D_RND_AFFINE_OVERWRITE_NORMAL);
                Sprite_SetAffineScale(sprite, &scale);
                if (circlePush->falls[i].timer >= 12) {
                    circlePush->falls[i].state = FALL_STATE_FALLEN;
                }
            } else {
                PokeathlonCourseMonObject_SetDrawFlag(mon->object, 0);
            }
            PokeathlonCourseSpritePoolSprite_Show(mon->tiredSprite, TRUE, FALSE);
            PokeathlonCourseMonObject_SetShadowDrawFlag(mon->object, FALSE);
            PokeathlonCourseObject_SetCenterPosition(mon->object, packet->x[i], packet->y[i] + offset, TRUE);
            outOfRing[i] = 1;
        } else {
            VecFx32 scale;
            circlePush->falls[i].state = FALL_STATE_NONE;
            circlePush->falls[i].timer = 0;
            scale.x = FX32_ONE;
            scale.y = FX32_ONE;
            scale.z = FX32_ONE;
            PokeathlonCourseMonObject_SetAffineOverwriteMode(mon->object, NNS_G2D_RND_AFFINE_OVERWRITE_NONE);
            if (exhausted) {
                PokeathlonCourseSpritePoolSprite_Show(mon->tiredSprite, TRUE, TRUE);
                if ((i / POKEATHLON_TEAM_SIZE) == own && !IsSEPlaying(SEQ_SE_GS_W146)) {
                    PlaySE(SEQ_SE_GS_W146);
                }
            } else {
                PokeathlonCourseSpritePoolSprite_Show(mon->tiredSprite, TRUE, FALSE);
            }
            Sprite_SetAffineScale(sprite, &scale);
            PokeathlonCourseMonObject_SetDrawFlag(mon->object, 1);
            if (state == CIRCLE_PUSH_MON_AT_START && circlePush->grayed[i] == 0) {
                circlePush->grayed[i] = 1;
                PokeathlonCourseMonObjects_SetPalette(circlePush->objects, i, NNS_G2D_VRAM_TYPE_2DMAIN, mon->grayPalette);
            } else if (state == CIRCLE_PUSH_MON_IN_RING && circlePush->grayed[i] == 1) {
                circlePush->grayed[i] = 0;
                PokeathlonCourseMonObjects_SetPalette(circlePush->objects, i, NNS_G2D_VRAM_TYPE_2DMAIN, mon->palette);
            }
            outOfRing[i] = 0;
            x = packet->x[i];
            y = packet->y[i];
            direction = (packet->shapeBits >> (i * 2)) & 3;
            mon->x = x << FX32_SHIFT;
            mon->y = y << FX32_SHIFT;
            VecFx32 effectPos = { 0, 0, 0 };
            effectPos.x = mon->x;
            effectPos.y = mon->y;
            Sprite_SetMatrix(PokeathlonCourseSpritePoolSprite_GetSprite(mon->effectSprite), &effectPos);
            VecFx32 tiredPos = { 0, 0, 0 };
            tiredPos.x = mon->x;
            tiredPos.y = mon->y;
            SetMonAnim(course, circlePush, mon, i, (i / POKEATHLON_TEAM_SIZE), own, (u8)(direction + 1), x, y, &tiredPos, scoring, sprite);
            if (scoringMon == i) {
                if (effect >= 1 && effect <= 4) {
                    Sprite *effectSprite = PokeathlonCourseSpritePoolSprite_GetSprite(mon->effectSprite);
                    PokeathlonCourseSpritePoolSprite_Show(mon->effectSprite, TRUE, TRUE);
                    Sprite_SetAnimCtrlSeq(effectSprite, effect + 2);
                    if (effect <= 2) {
                        PlaySE(SEQ_SE_GS_POINT1);
                    } else if (effect == 3) {
                        PlaySE(SEQ_SE_GS_POINT2);
                    } else {
                        PlaySE(SEQ_SE_GS_POINT3);
                    }
                    PokeathlonCirclePushDisplay_ShowPlayerEvent(circlePush->display, (u8)(i / POKEATHLON_TEAM_SIZE), effect);
                    PokeathlonCirclePush_StartBounce(&circlePush->effects, i);
                } else {
                    GF_ASSERT(FALSE);
                }
            }
            if ((i / POKEATHLON_TEAM_SIZE) == own) {
                int groundX;
                int groundY;
                u8 zone;
                PokeathlonCourseObject_CenterToGround(mon->object, x, y, &groundX, &groundY);
                if (state == CIRCLE_PUSH_MON_IN_RING && PokeathlonCirclePush_GetZonePoints(circlePush->layout, groundX, groundY, &zone)) {
                    PokeathlonCourse_SetMarkerAnim(course, member, 1);
                } else {
                    PokeathlonCourse_SetMarkerAnim(course, member, 0);
                }
            }
        }
    }
    PokeathlonCirclePush_SortByDepth(circlePush, packet);
    if (circlePush->effects.bounceActive && !scoring) {
        PokeathlonCirclePush_StopEffects(&circlePush->effects);
    }
    PokeathlonCirclePushDisplay_SetScore(circlePush->display, teamPoints, packetTeam);
    PokeathlonCirclePushDisplay_Update(circlePush->display, scoring, outOfRing);
}

// Host: moves every Pokemon in the ring towards its target; a Pokemon that touches another one
// pushes it (PokeathlonCirclePush_PushMons).
static void PokeathlonCirclePush_MoveMons(PokeathlonCourseData *course) {
    PokeathlonCirclePush *circlePush = PokeathlonCourse_GetWork(course);
    int i;

    for (i = 0; i < POKEATHLON_MONS; i++) {
        int member = i % POKEATHLON_TEAM_SIZE;
        int team = i / POKEATHLON_TEAM_SIZE;
        PokeathlonCirclePushMon *mon = &circlePush->mons[team][member];

        if (mon->boost != 0) {
            mon->boostTimer--;
            if (mon->boostTimer <= 0) {
                mon->boost = 0;
            }
        }
        if (mon->state != CIRCLE_PUSH_MON_OUT && PokeathlonCirclePush_IsOutOfRing(mon->object, mon->position.x, mon->position.y)) {
            mon->state = CIRCLE_PUSH_MON_OUT;
            mon->exhaustTimer = 0;
            mon->exhausted = 0;
            PokeathlonCourse_AddMonCounter(course, team, member, POKEATHLON_COUNTER_FALLS, 1);
            PokeathlonCourse_AddMonCounter(course, team, member, POKEATHLON_COUNTER_FAILURES, 1);
            if (circlePush->targetOutOfRing[i] != 0) {
                PokeathlonCourse_AddMonCounter(course, team, member, POKEATHLON_COUNTER_SELF_IMPEDES, 1);
            }
            circlePush->targetOutOfRing[i] = 0;
        }
    }

    for (i = 0; i < POKEATHLON_MONS; i++) {
        int team = i / POKEATHLON_TEAM_SIZE;
        int member = i % POKEATHLON_TEAM_SIZE;
        PokeathlonCirclePushMon *mon = &circlePush->mons[team][member];

        if (mon->state == CIRCLE_PUSH_MON_AT_START) {
            BOOL clear = TRUE;
            int j;
            for (j = 0; j < POKEATHLON_MONS; j++) {
                int otherTeam;
                int otherMember;
                PokeathlonCirclePushMon *other;
                if (i == j) {
                    continue;
                }
                otherTeam = j / POKEATHLON_TEAM_SIZE;
                otherMember = j % POKEATHLON_TEAM_SIZE;
                other = &circlePush->mons[otherTeam][otherMember];
                if (other->state != CIRCLE_PUSH_MON_OUT && PokeathlonCirclePush_MonsCollide(mon, other)) {
                    clear = FALSE;
                    break;
                }
            }
            if (clear) {
                mon->state = CIRCLE_PUSH_MON_IN_RING;
            }
        }
    }

    for (i = 0; i < POKEATHLON_MONS; i++) {
        int team = i / POKEATHLON_TEAM_SIZE;
        int member = i % POKEATHLON_TEAM_SIZE;
        PokeathlonCirclePushMon *mon = &circlePush->mons[team][member];
        VecFx32 delta;
        VecFx32 direction;
        VecFx32 position;
        fx32 distance;

        if (mon->state == CIRCLE_PUSH_MON_OUT) {
            continue;
        }
        mon->pushing = 0;
        mon->velocity.x = 0;
        mon->velocity.y = 0;
        mon->velocity.z = 0;
        position = mon->position;
        VEC_Subtract(&mon->target, &position, &delta);
        distance = VEC_Mag(&delta);
        if (distance <= 0) {
            PokeathlonCirclePush_RecoverStamina(mon);
            continue;
        }
        VEC_Normalize(&delta, &direction);
        {
            float speed;
            if (mon->exhausted != 0) {
                speed = 0.5f;
            } else {
                speed = (float)mon->runSpeed / 10.0;
            }
            if ((float)distance <= 4096.0f * speed) {
                position = mon->target;
            } else {
                VecFx32 zero = { 0, 0, 0 };
                VEC_MultAdd(4096.0f * speed, &direction, &zero, &delta);
                VEC_Add(&delta, &position, &position);
            }
        }
        if (distance != 0) {
            VecFx32 reference = sPokeathlonCirclePushDirectionReference;
            VecFx32 facing;
            u16 angle;
            facing.x = direction.y;
            facing.z = direction.x;
            facing.y = 0;
            angle = CalcAngleBetweenVecs(&reference, &facing);
            if (angle <= 0x2000 || angle >= 0xE000) {
                mon->direction = 4;
            } else if (angle > 0x2000 && angle < 0x6000) {
                mon->direction = 2;
            } else if (angle >= 0x6000 && angle <= 0xA000) {
                mon->direction = 3;
            } else {
                mon->direction = 1;
            }
        }
        if (mon->state == CIRCLE_PUSH_MON_IN_RING) {
            if (!PokeathlonCirclePush_CanMove(circlePush, mon, (u8)i, &delta)) {
                VecFx32 zero = { 0, 0, 0 };
                float speed;
                if (mon->exhausted != 0) {
                    continue;
                }
                mon->pushing = 1;
                speed = (float)((float)mon->pushSpeed / 10.0) + (float)mon->boost;
                VEC_MultAdd(4096.0f * speed, &direction, &zero, &mon->velocity);
                if (mon->stamina != 0) {
                    mon->stamina--;
                } else {
                    GF_ASSERT(FALSE);
                }
            } else {
                PokeathlonCirclePush_RecoverStamina(mon);
                mon->position = position;
            }
        } else {
            mon->stamina = 0;
            mon->position = position;
        }
    }
    PokeathlonCirclePush_PushMons(circlePush);
}

// The target follows the stylus once it is more than range away.
static void PokeathlonCirclePush_SetTarget(int x, int y, const VecFx32 *position, fx32 range, VecFx32 *target) {
    VecFx32 delta;
    delta.x = x << FX32_SHIFT;
    delta.y = y << FX32_SHIFT;
    delta.z = 0;
    VEC_Subtract(&delta, position, &delta);
    if (VEC_Mag(&delta) > range) {
        target->x = x << FX32_SHIFT;
        target->y = y << FX32_SHIFT;
        target->z = 0;
    }
}

// The team's Pokemon nearest to the touch (POKEATHLON_NO_MON: none in reach).

static u8 PokeathlonCirclePush_FindTouchedMon(PokeathlonCirclePush *circlePush, u8 team, u16 x, u16 y) {
    int range = PokeathlonCourse_GetTouchRadius();
    fx32 nearest = range << FX32_SHIFT;
    u8 i;
    u8 count = 0;
    u8 found;
    s32 distances[POKEATHLON_TEAM_SIZE];
    u8 inReach[POKEATHLON_TEAM_SIZE];
    int distance;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        PokeathlonCirclePushMon *mon = &circlePush->mons[team][i];
        if (PokeathlonCourse_IsInRange(mon->position.x / FX32_ONE, mon->position.y / FX32_ONE, x, y, range, &distance)) {
            distances[i] = distance;
            inReach[i] = TRUE;
            count++;
        } else {
            distances[i] = 0;
            inReach[i] = FALSE;
        }
    }
    if (count == 0) {
        return POKEATHLON_NO_MON;
    }
    found = 3;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (inReach[i] && distances[i] < nearest) {
            found = i;
            nearest = distances[i];
        }
    }
    if (found == 3) {
        GF_ASSERT(FALSE);
        return POKEATHLON_NO_MON;
    }
    return team * POKEATHLON_TEAM_SIZE + found;
}

static BOOL PokeathlonCirclePush_MonsCollide(PokeathlonCirclePushMon *a, PokeathlonCirclePushMon *b) {
    VecFx32 delta;
    VecFx32 centerA;
    VecFx32 centerB;
    s32 radiusA;
    s32 radiusB;
    fx32 reach;
    PokeathlonCourseObject_GetCollisionCircle(a->object, a->position.x, a->position.y, &centerA.x, &centerA.y, &radiusA);
    PokeathlonCourseObject_GetCollisionCircle(b->object, b->position.x, b->position.y, &centerB.x, &centerB.y, &radiusB);
    reach = (radiusA + radiusB) << FX32_SHIFT;
    centerA.z = 0;
    centerB.z = 0;
    VEC_Subtract(&centerA, &centerB, &delta);
    if (VEC_Mag(&delta) > reach) {
        return FALSE;
    }
    return TRUE;
}

static void PokeathlonCirclePush_UpdateContacts(PokeathlonCirclePush *circlePush) {
    u8 i;
    u8 j;
    for (i = 0; i < POKEATHLON_MONS; i++) {
        for (j = 0; j < POKEATHLON_MONS; j++) {
            if (i == j) {
                gPokeathlonCirclePushContacts[i][j].touching = FALSE;
                gPokeathlonCirclePushContacts[i][j].other = NULL;
            } else if (j >= i) {
                PokeathlonCirclePushMon *mon = &circlePush->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
                PokeathlonCirclePushMon *other = &circlePush->mons[j / POKEATHLON_TEAM_SIZE][j % POKEATHLON_TEAM_SIZE];
                if (mon->state != CIRCLE_PUSH_MON_IN_RING || other->state != CIRCLE_PUSH_MON_IN_RING) {
                    gPokeathlonCirclePushContacts[i][j].touching = FALSE;
                    gPokeathlonCirclePushContacts[j][i].touching = FALSE;
                    gPokeathlonCirclePushContacts[i][j].other = NULL;
                    gPokeathlonCirclePushContacts[j][i].other = NULL;
                } else if (PokeathlonCirclePush_MonsCollide(mon, other)) {
                    gPokeathlonCirclePushContacts[i][j].touching = TRUE;
                    gPokeathlonCirclePushContacts[j][i].touching = TRUE;
                    gPokeathlonCirclePushContacts[i][j].other = other;
                    gPokeathlonCirclePushContacts[j][i].other = mon;
                } else {
                    gPokeathlonCirclePushContacts[i][j].touching = FALSE;
                    gPokeathlonCirclePushContacts[j][i].touching = FALSE;
                    gPokeathlonCirclePushContacts[i][j].other = NULL;
                    gPokeathlonCirclePushContacts[j][i].other = NULL;
                }
            }
        }
    }
}

// Whether no Pokemon touching mon is in the way of a move by delta.
static BOOL PokeathlonCirclePush_CanMove(PokeathlonCirclePush *circlePush, PokeathlonCirclePushMon *mon, u32 index, const VecFx32 *delta) {
    VecFx32 toOther;
    u8 i = 0;
    PokeathlonCirclePushContact *contacts = gPokeathlonCirclePushContacts[index];
#pragma unused(circlePush)
    for (; i < POKEATHLON_MONS; i++) {
        if (contacts[i].touching) {
            VEC_Subtract(&contacts[i].other->position, &mon->position, &toOther);
            if (VEC_DotProduct(delta, &toOther) > 0) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// Pushing Pokemon move the Pokemon they touch, and those the ones they touch, along the push
// (a depth-first walk over the contacts); a pushing Pokemon that ran out of stamina is
// exhausted for 60 frames.

static void PokeathlonCirclePush_PushMons(PokeathlonCirclePush *circlePush) {
    CirclePushPushNode nodes[POKEATHLON_MONS];
    VecFx32 pushes[POKEATHLON_MONS][POKEATHLON_MONS];
    VecFx32 moved[POKEATHLON_MONS];
    u8 pushers[POKEATHLON_MONS];
    u8 visited[POKEATHLON_MONS];
    PokeathlonCirclePushStack stack;
    VecFx32 push;
    VecFx32 delta;
    VecFx32 last;
    PokeathlonCirclePushMon *mon;
    u8 count = 0;
    u8 pusher;
    u8 i;
    u8 j;
    u8 k;
    u8 current;
    BOOL entered;
    CirclePushPushNode *node;
    for (i = 0; i < POKEATHLON_MONS; i++) {
        mon = &circlePush->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
        if (mon->pushing && mon->state == CIRCLE_PUSH_MON_IN_RING) {
            pushers[count++] = i;
        }
        VEC_Subtract(&mon->target, &mon->position, &moved[i]);
    }
    if (count == 0) {
        return;
    }
    MI_CpuClear32(pushes, sizeof(pushes));
    for (pusher = 0; pusher < count; pusher++) {
        current = pushers[pusher];
        stack.count = 0;
        MI_CpuFill8(nodes, 0, sizeof(nodes));
        for (i = 0; i < POKEATHLON_MONS; i++) {
            nodes[i].push = &pushes[pusher][i];
        }
        MI_CpuFill8(visited, 0, sizeof(visited));
        push = circlePush->mons[current / POKEATHLON_TEAM_SIZE][current % POKEATHLON_TEAM_SIZE].velocity;
        entered = TRUE;
        do {
            int team = current / POKEATHLON_TEAM_SIZE;
            int member = current % POKEATHLON_TEAM_SIZE;
            VecFx32 *position = &circlePush->mons[team][member].position;
            visited[current] = 1;
            if (entered) {
                node = &nodes[current];
                node->next.count = 0;
                node->next.index = 0;
                for (i = 0; i < POKEATHLON_MONS; i++) {
                    if (gPokeathlonCirclePushContacts[current][i].touching) {
                        VEC_Subtract(&gPokeathlonCirclePushContacts[current][i].other->position, position, &delta);
                        if (VEC_DotProduct(&push, &delta) > 0) {
                            node->next.mons[node->next.count] = i;
                            node->delta[node->next.count] = delta;
                            node->next.count++;
                        }
                    }
                }
                VEC_Add(nodes[current].push, &push, nodes[current].push);
            }
            node = &nodes[current];
            entered = FALSE;
            if (node->next.index >= node->next.count) {
                visited[current] = 0;
                current = PokeathlonCirclePushStack_Pop(&stack);
            } else if (visited[node->next.mons[node->next.index]]) {
                node->next.index++;
            } else {
                if (PokeathlonCirclePushStack_Push(&stack, current) == 255) {
                    break;
                }
                // The push goes on in its own direction when it hits nearly head-on (cos >= 1/sqrt(2)), else
                // only its share towards the next Pokemon.
                if (PokeathlonCirclePush_Cosine(node->push, &node->delta[node->next.index]) >= FX_CosIdx(0x2000)) {
                    push = *node->push;
                } else {
                    PokeathlonCirclePush_Project(node->push, &node->delta[node->next.index], &push);
                }
                current = node->next.mons[node->next.index++];
                entered = TRUE;
            }
        } while (current != 255);
    }
    for (pusher = 0; pusher < count; pusher++) {
        for (j = 0; j < POKEATHLON_MONS; j++) {
            int offset = j * sizeof(VecFx32);
            mon = &circlePush->mons[j / POKEATHLON_TEAM_SIZE][j % POKEATHLON_TEAM_SIZE];
            VEC_Add(&mon->position, (VecFx32 *)((u8 *)pushes[pusher] + offset), &mon->position);
            if (VEC_Mag((VecFx32 *)((u8 *)pushes[pusher] + offset)) != 0 && !mon->pushing) {
                mon->target = mon->position;
            }
        }
        current = pushers[pusher];
        mon = &circlePush->mons[current / POKEATHLON_TEAM_SIZE][current % POKEATHLON_TEAM_SIZE];
        if (mon->stamina == 0) {
            int team;
            for (team = 0; team < POKEATHLON_PARTICIPANTS; team++) {
                if (circlePush->heldMons[team] == current) {
                    circlePush->heldMons[team] = POKEATHLON_NO_MON;
                    break;
                }
            }
            GF_ASSERT(mon->state == CIRCLE_PUSH_MON_IN_RING);
            mon->exhausted = 1;
            mon->exhaustTimer = 60;
            mon->target = mon->position;
            mon->velocity.x = 0;
            mon->velocity.y = 0;
            mon->pushing = 0;
        }
    }
    for (k = 0; k < POKEATHLON_MONS; k++) {
        mon = &circlePush->mons[k / POKEATHLON_TEAM_SIZE][k % POKEATHLON_TEAM_SIZE];
        VEC_Subtract(&mon->target, &mon->position, &last);
        if (VEC_DotProduct(&moved[k], &last) < 0) {
            mon->target = mon->position;
        }
    }
}

static u8 PokeathlonCirclePushStack_Push(PokeathlonCirclePushStack *stack, u8 mon) {
    s32 count;
    GF_ASSERT(stack->count < POKEATHLON_MONS);
    count = stack->count;
    if (count >= POKEATHLON_MONS) {
        return 0xFF;
    }
    stack->count = count + 1;
    stack->mons[(u8)count] = mon;
    return count;
}

static u8 PokeathlonCirclePushStack_Pop(PokeathlonCirclePushStack *stack) {
    int i = stack->count - 1;
    if (i < 0) {
        return 0xFF;
    }
    stack->count = i;
    return stack->mons[i];
}

// The part of a in the direction of b.

static void PokeathlonCirclePush_Project(VecFx32 *a, VecFx32 *b, VecFx32 *out) {
    VecFx32 normA;
    VecFx32 normB;
    VecFx32 zero;
    fx32 dot;
    fx32 length;
    VEC_Normalize(a, &normA);
    VEC_Normalize(b, &normB);
    dot = VEC_DotProduct(&normA, &normB);
    length = VEC_Mag(a);
    memset(&zero, 0, sizeof(zero));
    VEC_MultAdd(((s64)dot * length + 2048) >> FX32_SHIFT, &normB, &zero, out);
}

static fx32 PokeathlonCirclePush_Cosine(const VecFx32 *a, const VecFx32 *b) {
    VecFx32 normA;
    VecFx32 normB;
    VEC_Normalize(a, &normA);
    VEC_Normalize(b, &normB);
    return VEC_DotProduct(&normA, &normB);
}

// Host, end of a round: the Pokemon standing in bonus zones score their points.

static void PokeathlonCirclePush_ScoreZones(PokeathlonCirclePush *circlePush) {
    u8 zoneMons[4][POKEATHLON_MONS];
    u8 zonePoints[4];
    u8 counts[4];
    u8 zone;
    int groundX;
    int groundY;
    int i;
    int j;
    int points;
    if (!circlePush->scoreZones) {
        return;
    }
    for (i = 0; i < 4; i++) {
        counts[i] = 0;
    }
    circlePush->scoreZones = 0;
    circlePush->scoringCount = 0;
    circlePush->scoringIndex = 0;
    for (i = 0; i < POKEATHLON_MONS; i++) {
        PokeathlonCirclePushMon *mon = &circlePush->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE];
        if (mon->state == CIRCLE_PUSH_MON_IN_RING) {
            PokeathlonCourseObject_CenterToGround(mon->object, mon->position.x / FX32_ONE, mon->position.y / FX32_ONE, &groundX, &groundY);
            points = PokeathlonCirclePush_GetZonePoints(circlePush->layout, groundX, groundY, &zone);
            if (points) {
                mon->points += points;
                zoneMons[zone][counts[zone]++] = i;
                zonePoints[zone] = points;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < counts[i]; j++) {
            circlePush->scoringMons[circlePush->scoringCount] = zoneMons[i][j];
            circlePush->scoringPoints[circlePush->scoringCount] = zonePoints[i];
            circlePush->scoringCount++;
        }
    }
}

static void PokeathlonCirclePush_DrawTimer(int time, BgConfig *bgConfig) {
    int i;

    for (i = 1; i <= time; i++) {
        PokeathlonCirclePush_DrawTimerTile((u8)i, bgConfig);
    }
    ScheduleBgTilemapBufferTransfer(bgConfig, GF_BG_LYR_MAIN_1);
}

// The timer runs around the ring: 42 tiles of 2x2.
static void PokeathlonCirclePush_DrawTimerTile(u32 index, BgConfig *bgConfig) {
    int y;
    int x;

    if (index >= 1 && index <= 6) {
        x = (index - 1) * 2 + 18;
        y = 2;
    } else if (index >= 16 && index <= 28) {
        x = 26 - (index - 16) * 2;
        y = 20;
    } else if (index >= 38 && index < 43) {
        x = (index - 38) * 2 + 4;
        y = 2;
    } else if (index >= 7 && index <= 15) {
        x = 28;
        y = (index - 7) * 2 + 4;
    } else {
        x = 2;
        y = 18 - (index - 29) * 2;
    }
    FillBgTilemapRect(bgConfig, GF_BG_LYR_MAIN_1, 0, x, y, 2, 2, TILEMAP_FILL_KEEP_PAL);
}

// Host: the Pokemon that fell out of the ring come back at their start.

static void PokeathlonCirclePush_RespawnMons(PokeathlonCirclePush *circlePush) {
    int team;
    int member;
    s32 x;
    s32 y;
    for (team = 0; team < POKEATHLON_PARTICIPANTS; team++) {
        for (member = 0; member < POKEATHLON_TEAM_SIZE; member++) {
            PokeathlonCirclePushMon *mon = &circlePush->mons[team][member];
            if (mon->state == CIRCLE_PUSH_MON_OUT) {
                mon->state = CIRCLE_PUSH_MON_AT_START;
                PokeathlonCourseObject_GroundToCenter(mon->object, sPokeathlonCirclePushMonStartPositions[team][member].x, sPokeathlonCirclePushMonStartPositions[team][member].y, &x, &y);
                mon->position.x = x << FX32_SHIFT;
                mon->position.y = y << FX32_SHIFT;
                mon->target = mon->position;
                mon->direction = 2;
            }
        }
    }
}

// Whether none of the team's Pokemon is in the game (all fell out of the ring).
static BOOL PokeathlonCirclePush_IsTeamOut(PokeathlonCirclePush *circlePush, int team) {
    int i;

    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (circlePush->mons[team][i].state != CIRCLE_PUSH_MON_OUT) {
            return FALSE;
        }
    }
    return TRUE;
}

static void PokeathlonCirclePush_RecoverStamina(PokeathlonCirclePushMon *mon) {
    if (mon->exhausted) {
        mon->exhaustTimer--;
        if (mon->exhaustTimer == 0) {
            mon->exhaustTimer = 0;
            mon->exhausted = 0;
            mon->stamina = mon->maxStamina;
        }
    } else {
        mon->stamina += 2;
        if (mon->stamina > mon->maxStamina) {
            mon->stamina = mon->maxStamina;
        }
        if (mon->stamina == mon->maxStamina) {
            mon->exhaustTimer = 0;
            mon->exhausted = 0;
        }
    }
}

// Speeds and stamina from the Pokemon's performance (ring data NARC a/1/7/0 #1).
static void PokeathlonCirclePush_SetMonStats(PokeathlonCourseData *course, PokeathlonCirclePushRingData *ringData, u8 team, u8 member, PokeathlonCirclePushMon *mon) {
    u8 *stats = PokeathlonCourse_GetMonStats(course, team, member);

    mon->pushSpeed = ringData->pushSpeeds[stats[0]];
    mon->maxStamina = ringData->staminas[stats[3]];
    mon->stamina = ringData->staminas[stats[3]];
    mon->runSpeed = ringData->runSpeeds[stats[1]];
}

static void PokeathlonCirclePush_StartLayoutChange(PokeathlonCirclePushEffects *effects, u8 oldLayout, u8 newLayout, PokeathlonCourseData *course) {
    effects->oldLayout = oldLayout;
    effects->newLayout = newLayout;
    effects->state = LAYOUT_CHANGE_WAIT_SLIDE;
    effects->changeTask = SysTask_CreateOnMainQueue(PokeathlonCirclePush_LayoutChangeTask, effects, 0);
    effects->fadeTask = SysTask_CreateOnMainQueue(PokeathlonCirclePush_LayoutFadeTask, effects, 1);
    effects->course = course;
    reg_G2_BG2OFS = 2 << 22;
    effects->slideTask = SysTask_CreateOnMainQueue(PokeathlonCirclePush_RingSlideTask, effects, 2);
}

static void PokeathlonCirclePush_LayoutChangeTask(SysTask *task, void *data) {
    PokeathlonCirclePushEffects *effects = data;
    switch (effects->state) {
    case LAYOUT_CHANGE_WAIT_SLIDE:
        if (effects->slideTask == NULL) {
            effects->shakeTask = SysTask_CreateOnMainQueue(PokeathlonCirclePush_ShakeTask, effects, 3);
            effects->state++;
        }
        break;
    case LAYOUT_CHANGE_WAIT_SHAKE:
        if (effects->shakeTask == NULL) {
            PokeathlonCirclePushInput *input;
            effects->changeTask = NULL;
            effects->state = LAYOUT_CHANGE_WAIT_SLIDE;
            input = (PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(effects->course));
            input->ready = 1;
            SysTask_Destroy(task);
        }
        break;
    }
}

// The zone markers of the old layout fade out, those of the new one in.
static void PokeathlonCirclePush_LayoutFadeTask(SysTask *task, void *data) {
    PokeathlonCirclePushEffects *effects = data;
    u16 value;

    switch (effects->fadeState) {
    case LAYOUT_FADE_OUT:
        effects->fadeTimer++;
        if (effects->fadeTimer <= 5) {
            value = (u8)effects->fadeTimer * 12 / 5;
            G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0, 12 - value, value + 4);
        } else {
            effects->fadeState++;
        }
        break;
    case LAYOUT_FADE_SWAP:
        PokeathlonCirclePushZoneMarkers_Show(effects->markers, effects->newLayout);
        PokeathlonCirclePushZoneMarkers_Hide(effects->markers, effects->oldLayout);
        effects->fadeTimer = 0;
        effects->fadeState++;
        PlaySE(SEQ_SE_GS_PUSH03);
        break;
    case LAYOUT_FADE_IN:
        effects->fadeTimer++;
        if (effects->fadeTimer <= 5) {
            value = (u8)effects->fadeTimer * 12 / 5;
            G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0, value, 16 - value);
        } else {
            effects->fadeTask = NULL;
            effects->fadeTimer = 0;
            effects->fadeState = LAYOUT_FADE_OUT;
            SysTask_Destroy(task);
        }
        break;
    }
}

// The ring's floor (main BG 2) slides out to the left and back in.
static void PokeathlonCirclePush_RingSlideTask(SysTask *task, void *data) {
    PokeathlonCirclePushEffects *effects = data;
    s32 value;

    switch (effects->slideState) {
    case RING_SLIDE_OUT:
        effects->slideTimer++;
        value = (effects->slideTimer << 7) / 5;
        reg_G2_BG2OFS = ((0x80 - value) << 16) & 0x01FF0000;
        if (effects->slideTimer >= 5) {
            effects->slideTimer = 0;
            effects->slideState++;
        }
        break;
    case RING_SLIDE_WAIT:
        effects->slideTimer++;
        if (effects->slideTimer >= 20) {
            effects->slideTimer = 0;
            effects->slideState++;
        }
        break;
    case RING_SLIDE_IN:
        effects->slideTimer++;
        value = -(effects->slideTimer << 7) / 5;
        reg_G2_BG2OFS = (value << 16) & 0x01FF0000;
        if (effects->slideTimer >= 5) {
            effects->slideTimer = 0;
            effects->slideTask = NULL;
            effects->slideState = RING_SLIDE_OUT;
            SysTask_Destroy(task);
        }
        break;
    }
}

static void PokeathlonCirclePush_ShakeTask(SysTask *task, void *data) {
    PokeathlonCirclePushEffects *effects = data;
    s16 offset = effects->shakeOffset;
    u16 step = effects->shakeStep;
    effects->shakeOffset = offset + sPokeathlonCirclePushShakeOffsets[step];
    effects->shakeStep++;
    if (effects->shakeStep >= 18) {
        effects->shakeOffset = 0;
        effects->shakeTask = NULL;
        effects->shakeStep = 0;
        SysTask_Destroy(task);
    }
}

static void PokeathlonCirclePush_StopEffects(PokeathlonCirclePushEffects *effects) {
    effects->bounceActive = 0;
    if (effects->changeTask) {
        ((PokeathlonCirclePushInput *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(effects->course)))->ready = 1;
        SysTask_Destroy(effects->changeTask);
        effects->changeTask = NULL;
    }
    if (effects->slideTask) {
        SysTask_Destroy(effects->slideTask);
        effects->slideTask = NULL;
    }
    if (effects->fadeTask) {
        SysTask_Destroy(effects->fadeTask);
        effects->fadeTask = NULL;
    }
    if (effects->shakeTask) {
        SysTask_Destroy(effects->shakeTask);
        effects->shakeTask = NULL;
    }
    if (effects->bounceTask) {
        SysTask_Destroy(effects->bounceTask);
        effects->bounceTask = NULL;
    }
    reg_G2_BG2OFS = 0x800000;
    effects->state = LAYOUT_CHANGE_WAIT_SLIDE;
    effects->fadeState = LAYOUT_FADE_OUT;
    effects->slideState = RING_SLIDE_OUT;
    effects->fadeTimer = 0;
    effects->slideTimer = 0;
    effects->shakeStep = 0;
    effects->bounceStep = 0;
    effects->shakeOffset = 0;
    effects->bounceOffset = 0;
    effects->bounceMon = POKEATHLON_NO_MON;
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0, 12, 4);
}

static void PokeathlonCirclePush_StartBounce(PokeathlonCirclePushEffects *effects, u8 mon) {
    if (effects->bounceTask == NULL) {
        effects->bounceMon = mon;
        effects->bounceTask = SysTask_CreateOnMainQueue(PokeathlonCirclePush_BounceTask, effects, 0);
    }
}

static void PokeathlonCirclePush_BounceTask(SysTask *task, void *data) {
    PokeathlonCirclePushEffects *effects = data;
    s16 offset = effects->bounceOffset;
    u16 step = effects->bounceStep;
    effects->bounceOffset = offset + sPokeathlonCirclePushBounceOffsets[step];
    effects->bounceStep++;
    if (effects->bounceStep >= 5) {
        effects->bounceOffset = 0;
        effects->bounceTask = NULL;
        effects->bounceStep = 0;
        effects->bounceMon = POKEATHLON_NO_MON;
        SysTask_Destroy(task);
    }
}

static void PokeathlonCirclePush_ApplyBounce(PokeathlonCourseData *course, PokeathlonCirclePushEffects *effects, PokeathlonCourseMonObject *object, u8 mon, int anim) {
    if (effects->bounceMon == mon) {
        s32 team = mon / POKEATHLON_TEAM_SIZE;
        s32 member = mon % POKEATHLON_TEAM_SIZE;

        if (PokeathlonCourse_GetMonStats(course, team, member)[2] != 0) {
            PokeathlonCourseMonObject_Move(object, 0, effects->bounceOffset, anim, FALSE);
        }
    }
}

static void PokeathlonCirclePush_AddScoreWindow(PokeathlonCirclePush *circlePush) {
    AddWindow(circlePush->bgConfig, &circlePush->scoreWindow, &sPokeathlonCirclePushScoreWindowTemplate);
    BG_FillCharDataRange(circlePush->bgConfig, GF_BG_LYR_MAIN_3, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, circlePush->heapId);
}

static void PokeathlonCirclePush_PrintScore(PokeathlonCirclePush *circlePush, s32 score) {
    MsgData *msgData;
    MessageFormat *msgFormat;
    String *string;

    FillWindowPixelBuffer(&circlePush->scoreWindow, 0);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, circlePush->heapId);
    msgFormat = MessageFormat_New(circlePush->heapId);
    BufferIntegerAsString(msgFormat, 0, score, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msg_0309_00158, circlePush->heapId);
    AddTextPrinterParameterizedWithColor(&circlePush->scoreWindow, 4, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    MessageFormat_Delete(msgFormat);
    DestroyMsgData(msgData);
    CopyWindowToVram(&circlePush->scoreWindow);
}

static BOOL PokeathlonCirclePush_IsOutOfRing(PokeathlonCourseMonObject *object, fx32 x, fx32 y) {
    int groundX;
    int groundY;

    PokeathlonCourseObject_CenterToGround(object, x / FX32_ONE, y / FX32_ONE, &groundX, &groundY);
    if (groundX < 16 || groundX >= 240 || groundY < 16 || groundY >= 176) {
        return TRUE;
    }
    return FALSE;
}

// Lower on the screen first; then by Pokemon.
static int PokeathlonCirclePush_CompareDepth(const void *a, const void *b) {
    const CirclePushDepth *depthA = a;
    const CirclePushDepth *depthB = b;
    if (depthA->y > depthB->y) {
        return -1;
    }
    if (depthA->y < depthB->y) {
        return 1;
    }
    if (depthA->mon < depthB->mon) {
        return -1;
    }
    if (depthA->mon > depthB->mon) {
        return 1;
    }
    return 0;
}

// Pokemon lower on the screen are drawn in front.

static void PokeathlonCirclePush_SortByDepth(PokeathlonCirclePush *circlePush, PokeathlonCirclePushPacket *packet) {
    CirclePushDepth depths[POKEATHLON_MONS];
    int groundX;
    int groundY;
    u8 i;
    for (i = 0; i < POKEATHLON_MONS; i++) {
        depths[i].mon = i;
        PokeathlonCourseObject_CenterToGround(circlePush->mons[i / POKEATHLON_TEAM_SIZE][i % POKEATHLON_TEAM_SIZE].object, packet->x[i], packet->y[i], &groundX, &groundY);
        depths[i].y = groundY;
    }
    MATH_QSort(depths, NELEMS(depths), sizeof(CirclePushDepth), PokeathlonCirclePush_CompareDepth, circlePush->sortBuffer);
    for (i = 0; i < POKEATHLON_MONS; i++) {
        u8 mon = depths[i].mon;
        int team = mon / POKEATHLON_TEAM_SIZE;
        int member = mon % POKEATHLON_TEAM_SIZE;
        PokeathlonCourseMonObject_SetDrawPriority(circlePush->mons[team][member].object, i + 6);
    }
}
