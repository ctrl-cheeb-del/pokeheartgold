#include "pokeathlon/pokeathlon_snow_throw.h"

#include "global.h"

#include "constants/sdk_extras.h"
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"

#include "assert.h"
#include "bg_window.h"
#include "char_tiles.h"
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
#include "pm_string.h"
#include "pokemon.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"

enum {
    SNOW_THROW_STATE_PLAY,
    SNOW_THROW_STATE_SAVE_SCORES,
};

enum PokeathlonSnowThrowInitState {
    SNOW_THROW_INIT_CREATE,
    SNOW_THROW_INIT_CREATE_DISPLAY,
    SNOW_THROW_INIT_CREATE_SPRITES,
    SNOW_THROW_INIT_LOAD_MONS,
    SNOW_THROW_INIT_PLACE_MONS,
    SNOW_THROW_INIT_WAIT_FADE_IN,
};

void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *mtx, VecFx32 *result);

// The animation state (facing) of each other team's Pokemon, by its place in the view.
typedef struct PokeathlonSnowThrowViewAnims {
    u32 animStates[POKEATHLON_PARTICIPANTS - 1];
} PokeathlonSnowThrowViewAnims;

// Where the marks of the other teams' colours are on the field screen.
typedef struct PokeathlonSnowThrowTeamMarkPositions {
    VecFx32 positions[POKEATHLON_PARTICIPANTS - 1];
} PokeathlonSnowThrowTeamMarkPositions;

void MATH_QSort(void *base, u32 count, u32 width, int (*compare)(const void *, const void *), void *context);

// A snowball as sorted for drawing.
typedef struct PokeathlonSnowThrowDrawOrder {
    u16 own;
    u16 index;
    s32 y;
} PokeathlonSnowThrowDrawOrder;

static void PokeathlonSnowThrow_SetGfxBanks(void);
static void PokeathlonSnowThrow_InitBgs(BgConfig *bgConfig);
static void PokeathlonSnowThrow_LoadBgGraphics(PokeathlonSnowThrow *work, u8 own);
static void PokeathlonSnowThrow_LoadSpriteGraphics(PokeathlonCourseSpritePool *pool);
static void PokeathlonSnowThrow_CreateSprites(PokeathlonSnowThrow *work, PokeathlonCourseSpritePool *pool, u8 own);
static void PokeathlonSnowThrow_UpdateHost(PokeathlonCourseData *course);
static void PokeathlonSnowThrow_PackPacket(PokeathlonSnowThrow *work, PokeathlonSnowThrowPacket *packet);
static BOOL PokeathlonSnowThrow_Update(PokeathlonCourseData *course);
static void PokeathlonSnowThrow_DrawPacket(PokeathlonCourseData *course);
static u8 PokeathlonSnowThrow_FindOwnMonAt(PokeathlonSnowThrow *work, u8 team, u32 x, u32 y, VecFx32 *out);
static void PokeathlonSnowThrow_InitMon(PokeathlonCourseData *course, s32 stats[][5], u8 team, u8 member, PokeathlonSnowThrowMon *mon);
static void PokeathlonSnowThrow_InitWindows(PokeathlonSnowThrow *work);
static void PokeathlonSnowThrow_UpdateMons(PokeathlonCourseData *course);
static void PokeathlonSnowThrow_MoveBalls(PokeathlonCourseData *course);
static void PokeathlonSnowThrow_HitMons(PokeathlonCourseData *course, PokeathlonSnowThrow *work);
static void PokeathlonSnowThrow_CollideBalls(PokeathlonSnowThrow *work);
static void PokeathlonSnowThrow_PrintNames(PokeathlonSnowThrow *work, PokeathlonCourseData *course);
static void PokeathlonSnowThrow_SetTimerDigits(PokeathlonSnowThrow *work, u32 seconds);
static void PokeathlonSnowThrow_ShowOwnScore(PokeathlonCourseData *course);
static void PokeathlonSnowThrow_SortSprites(PokeathlonSnowThrow *work, u16 own);

static const WindowTemplate sSnowThrowScoreWindowTemplate = {
    .bgId = GF_BG_LYR_MAIN_3,
    .left = 0,
    .top = 20,
    .width = 32,
    .height = 2,
    .palette = 15,
    .baseTile = 1,
};

static const VecFx32 sSnowThrowPacketScale = { FX32_ONE, FX32_ONE, FX32_ONE };

static const PokeathlonCourseSpritePoolTemplate sSnowThrowSpritePoolTemplate = {
    .capacity = 115,
    .resourceCount = 3,
    .resCounts = { 3, 3, 3, 3 },
};

static const PokeathlonSnowThrowViewAnims sSnowThrowViewAnims = {
    .animStates = { 3, 2, 4 },
};

static const GraphicsModes sSnowThrowGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const WindowTemplate sSnowThrowNameWindowTemplates[POKEATHLON_PARTICIPANTS - 1] = {
    {
        .bgId = GF_BG_LYR_MAIN_0,
        .left = 24,
        .top = 2,
        .width = 8,
        .height = 2,
        .palette = 15,
        .baseTile = 1,
    },
    {
        .bgId = GF_BG_LYR_MAIN_0,
        .left = 13,
        .top = 2,
        .width = 8,
        .height = 2,
        .palette = 15,
        .baseTile = 0x11,
    },
    {
        .bgId = GF_BG_LYR_MAIN_0,
        .left = 2,
        .top = 2,
        .width = 8,
        .height = 2,
        .palette = 15,
        .baseTile = 0x21,
    },
};

static const BgTemplate sSnowThrowBgTemplate_Sub1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSnowThrowBgTemplate_Sub2 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe800,
    .charBase = GX_BG_CHARBASE_0x04000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSnowThrowBgTemplate_Main0 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe000,
    .charBase = GX_BG_CHARBASE_0x08000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSnowThrowBgTemplate_Main1 = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sSnowThrowBgTemplate_Sub3 = {
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

static const BgTemplate sSnowThrowBgTemplate_Main3 = {
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

static const BgTemplate sSnowThrowBgTemplate_Sub0 = {
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

static const s32 sSnowThrowOtherMonX[POKEATHLON_MONS - POKEATHLON_TEAM_SIZE] = { 246, 248, 249, 199, 175, 150, 82, 63, 37 };

static const s32 sSnowThrowOtherMonY[POKEATHLON_MONS - POKEATHLON_TEAM_SIZE] = { 170, 130, 100, 70, 70, 70, 100, 130, 170 };

static const PokeathlonSnowThrowTeamMarkPositions sSnowThrowTeamMarkPositions = {
    .positions = {
        { FX32_CONST(184), FX32_CONST(24), 0 },
        { FX32_CONST(96), FX32_CONST(24), 0 },
        { FX32_CONST(8), FX32_CONST(24), 0 },
    },
};

static const GraphicsBanks sSnowThrowGraphicsBanks = {
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

// Which of two Pokemon at the same depth is drawn in front, by view (own team) and Pokemon.
static const u8 sSnowThrowDrawOrder[POKEATHLON_PARTICIPANTS][POKEATHLON_MONS] = {
    { 11, 10, 9, 8, 7, 6, 3, 4, 5, 2, 1, 0 },
    { 2, 1, 0, 11, 10, 9, 8, 7, 6, 3, 4, 5 },
    { 3, 4, 5, 2, 1, 0, 11, 10, 9, 8, 7, 6 },
    { 8, 7, 6, 3, 4, 5, 2, 1, 0, 11, 10, 9 },
};

// Where each Pokemon stands on the field (fx32 field units, unturned).
static const VecFx32 sSnowThrowMonPositions[POKEATHLON_MONS] = {
    { FX32_CONST(25), 0, FX32_CONST(61) },
    { FX32_CONST(33), 0, FX32_CONST(61) },
    { FX32_CONST(41), 0, FX32_CONST(61) },
    { FX32_CONST(61), 0, FX32_CONST(41) },
    { FX32_CONST(61), 0, FX32_CONST(33) },
    { FX32_CONST(61), 0, FX32_CONST(25) },
    { FX32_CONST(41), 0, FX32_CONST(5) },
    { FX32_CONST(33), 0, FX32_CONST(5) },
    { FX32_CONST(25), 0, FX32_CONST(5) },
    { FX32_CONST(5), 0, FX32_CONST(25) },
    { FX32_CONST(5), 0, FX32_CONST(33) },
    { FX32_CONST(5), 0, FX32_CONST(41) },
};

// Draw priorities of the other teams' Pokemon, by their place in the view.
static const u8 sSnowThrowOtherMonDrawPriorities[POKEATHLON_MONS - POKEATHLON_TEAM_SIZE] = { 0, 2, 4, 6, 7, 8, 5, 3, 1 };

// The Pokemon the k-th of the other teams' nine is (they are listed from the team after the own one on).
static inline u8 PokeathlonSnowThrow_OtherMon(int own, int k) {
    return ((u8)(((own + 1) * POKEATHLON_TEAM_SIZE) % POKEATHLON_MONS) + k) % POKEATHLON_MONS;
}

// Set-up, a step per frame (PokeathlonCourse_GetEventInitState): heaps and screens, the top screen and the CPU,
// sprites, the Pokemon graphics, then the field once they are loaded.

BOOL PokeathlonSnowThrow_Init(PokeathlonCourseData *course) {
    PokeathlonCourseMonInfo infos[POKEATHLON_MONS];
    PokeathlonCourseMonGfxTemplate template;
    s32 stats[4][5];
    PokeathlonSnowThrow *work;
    PokeathlonSnowThrow *data;
    int participant;
    int i;
    int k;
    PokeathlonCourseMonObject *object;
    u8 mon;
    int x;
    int team;
    PokeathlonSnowThrowMon *teamMon;
    int first;
    int count;
    int own;
    int member;
    int y, j;

    work = PokeathlonCourse_GetWork(course);
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case SNOW_THROW_INIT_CREATE: {
        ObjCharTransferTemplate charTransfer;

        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_146, 0x40000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonSnowThrow_SetGfxBanks();
        data = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonSnowThrow));
        MI_CpuFill8(data, 0, sizeof(PokeathlonSnowThrow));
        data->sortBuffer = Heap_Alloc(HEAP_ID_146, 40);
        MI_CpuFill8(data->sortBuffer, 0, 40);
        data->bgConfig = BgConfig_Alloc(HEAP_ID_146);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        charTransfer.maxTasks = 115;
        charTransfer.sizeMain = 0x40000;
        charTransfer.sizeSub = 0x4000;
        charTransfer.heapID = PokeathlonCourse_GetHeapID(course);
        PokeathlonCourse_InitObjTransfer(&charTransfer, 22, HEAP_ID_146, GX_OBJVRAMMODE_CHAR_1D_256K, GX_OBJVRAMMODE_CHAR_1D_256K);
        NNS_G2dInitOamManagerModule();
        OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_146);
        data->heapId = HEAP_ID_146;
        FontID_Alloc(4, HEAP_ID_146);
        PokeathlonSnowThrow_InitBgs(data->bgConfig);
        PokeathlonSnowThrow_InitWindows(data);
        PokeathlonSnowThrow_PrintNames(data, course);
        gSystem.screensFlipped = FALSE;
        GfGfx_SwapDisplay();
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case SNOW_THROW_INIT_CREATE_DISPLAY:
        work->display = PokeathlonSnowThrowDisplay_New(work->heapId, work->bgConfig, course);
        count = PokeathlonCourse_GetParticipantCount(course);
        work->cpu = PokeathlonSnowThrowCpu_New(work->heapId, POKEATHLON_PARTICIPANTS - count, PokeathlonCourse_GetMode(course));
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case SNOW_THROW_INIT_CREATE_SPRITES: {
        PokeathlonCourseSpritePoolTemplate poolTemplate = sSnowThrowSpritePoolTemplate;

        work->spritePool = PokeathlonCourseSpritePool_New(work->heapId, &poolTemplate);
        PokeathlonCourseSpritePool_SetSurfaceCoords(work->spritePool, 0, 0, 0, FX32_CONST(288));
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 0, 106);
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 1, 101);
        PokeathlonCourseSpritePool_SetResourceId(work->spritePool, 2, 105);
        PokeathlonSnowThrow_LoadSpriteGraphics(work->spritePool);
        PokeathlonSnowThrowDisplay_LoadSpriteGraphics(work->display, work->spritePool);
        PokeathlonCourseSpritePool_TransferResources(work->spritePool);
        work->monResources = PokeathlonCourseSprites_CreateResources(work->heapId, 1255, NNS_G2D_VRAM_TYPE_2DMAIN);
        work->monObjectList = PokeathlonCourseMonObjects_Create(work->heapId, 9, 32, work->monResources, PokeathlonCourseSpritePool_GetSpriteList(work->spritePool));
        Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSpritesInPool(course, 0, work->monResources, work->spritePool), 1);
        own = PokeathlonCourse_GetNetId(course);
        PokeathlonSnowThrow_CreateSprites(work, work->spritePool, own);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case SNOW_THROW_INIT_LOAD_MONS:
        // the other teams' Pokemon first, the own three last
        own = (u8)PokeathlonCourse_GetNetId(course);
        for (i = 0; i < POKEATHLON_MONS; i++) {
            count = PokeathlonSnowThrow_OtherMon(own, i);
            member = count % POKEATHLON_TEAM_SIZE;
            participant = count / POKEATHLON_TEAM_SIZE;
            PokeathlonCourse_GetMonInfo(course, participant, member, &infos[i]);
            template.sizeTypes[i] = PokeathlonCourse_GetSpriteSizeType(PokeathlonCourse_GetPerformance(course, participant, member));
        }
        PokeathlonSnowThrowDisplay_CreateSprites(work->display, work->spritePool, &infos[9]);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            VecFx32 position = { 0, 0, 0 };
            PokeathlonCourseMonInfo *info = &infos[9 + i];
            u8 height = GetMonPicHeightBySpeciesGenderForm(info->species, info->gender, 0, info->form, info->personality);
            position.x = (16 + i * 50) << FX32_SHIFT;
            position.y = (height + 376) << FX32_SHIFT;
            position.y -= FX32_ONE * 16;
            PokeathlonCourseSpritePoolSprite_SetPosition(work->mons[own * POKEATHLON_TEAM_SIZE + i].stunSprite, &position);
        }
        template.loadAtOnce = FALSE;
        template.priority = 3;
        template.vramTransfer = FALSE;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
        PokeathlonCourseMonObjects_Load(work->monObjectList, 9, infos, &template, 0, 0);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case SNOW_THROW_INIT_PLACE_MONS:
        if (!PokeathlonCourseMonObjects_IsLoaded(work->monObjectList)) {
            break;
        } else {
            PokeathlonSnowThrowViewAnims anims = sSnowThrowViewAnims;

            PokeathlonCourse_SetVBlankIntrCB(work->bgConfig);
            PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
            own = PokeathlonCourse_GetNetId(course);
            for (k = 0; k < POKEATHLON_MONS - POKEATHLON_TEAM_SIZE; k++) {
                work->monObjects[k] = PokeathlonCourseMonObjects_Get(work->monObjectList, k);
                object = work->monObjects[k];
                PokeathlonCourseMonObject_SetDrawFlag(object, TRUE);
                mon = ((u8)(((own + 1) * POKEATHLON_TEAM_SIZE) % POKEATHLON_MONS) + k) % POKEATHLON_MONS;
                x = sSnowThrowOtherMonX[k];
                y = sSnowThrowOtherMonY[k];
                PokeathlonCourseMonObject_SetAnimState(object, anims.animStates[k / POKEATHLON_TEAM_SIZE]);
                PokeathlonCourseObject_SetGroundPosition(object, x, y);
                {
                    VecFx32 markPosition = { 0, 0, 0 };
                    if (PokeathlonCourseMonGfx_GetInfo(PokeathlonCourseMonObject_GetGfx(object))->isLarge) {
                        markPosition.x = x << FX32_SHIFT;
                        markPosition.y = (y - 40) << FX32_SHIFT;
                    } else {
                        markPosition.x = x << FX32_SHIFT;
                        markPosition.y = (y - 25) << FX32_SHIFT;
                    }
                    PokeathlonCourseSpritePoolSprite_SetPosition(work->mons[mon].stunSprite, &markPosition);
                    PokeathlonCourseSpritePoolSprite_SetPosition(work->tiredMarks[k], &markPosition);
                }
                PokeathlonCourseMonObject_SetDrawPriority(object, sSnowThrowOtherMonDrawPriorities[k] + 32);
            }
            ReadWholeNarcMemberByIdPair(stats, NARC_a_1_7_0, 3);
            work->timer = SNOW_THROW_DURATION;
            for (team = 0, first = 0; team < POKEATHLON_PARTICIPANTS; first += POKEATHLON_TEAM_SIZE, team++) {
                work->heldBall[team] = SNOW_THROW_NONE;
                for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
                    teamMon = &work->mons[j + first];
                    PokeathlonSnowThrow_InitMon(course, stats, team, j, teamMon);
                    if (PokeathlonCourse_GetNetId(course) == 0) {
                        PokeathlonSnowThrowCpu_SetMon(work->cpu, j + first, teamMon, &work->balls[j + first]);
                    }
                }
            }
            if (PokeathlonCourse_GetNetId(course) == 0) {
                PokeathlonSnowThrow_PackPacket(work, (PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + offsetof(PokeathlonSnowThrowLink, packetToSend)));
            }
            PokeathlonSnowThrowDisplay_SetMonShadows(work->display, work->spritePool, work->monResources);
            PokeathlonSnowThrow_LoadBgGraphics(work, PokeathlonCourse_GetNetId(course));
            GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
            GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
            WirelessStatusIcon_CreateOnScreenIfConnected(1);
            BeginNormalPaletteFade(FADE_SUB_THEN_MAIN, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, RGB_BLACK, 6, 1, work->heapId);
            PokeathlonCourse_AdvanceEventInitState(course);
        }
        break;
    case SNOW_THROW_INIT_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL PokeathlonSnowThrow_Draw(PokeathlonCourseData *course) {
    PokeathlonSnowThrow *work = PokeathlonCourse_GetWork(course);
    PokeathlonSnowThrowDisplay_UpdateShake(work->display);
    PokeathlonCourseSpritePool_Draw(work->spritePool);
    return TRUE;
}

// Results: the hits each team scored.
BOOL PokeathlonSnowThrow_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, gfx, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00299);
    }
    PokeathlonCourseScoreList_Rank(gfx, 1);
    PokeathlonEvent_CalcPoints(gfx, 8);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 8);
    return TRUE;
}

BOOL PokeathlonSnowThrow_Exit(PokeathlonCourseData *course) {
    PokeathlonSnowThrow *work = PokeathlonCourse_GetWork(course);
    int i;
    Window *window;

    WirelessStatusIcon_Destroy();
    PokeathlonCourse_ClearEventDataTransfer(course);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(work->bgConfig, GF_BG_LYR_SUB_3);
    RemoveWindow(&work->scoreWindow);
    for (i = 0, window = work->nameWindows; i < POKEATHLON_PARTICIPANTS - 1; i++, window++) {
        RemoveWindow(window);
    }
    Heap_Free(work->bgConfig);
    PokeathlonCourseSpritePool_Free(work->spritePool);
    PokeathlonCourseMonObjects_Free(work->monObjectList);
    PokeathlonCourseSprites_FreeResources(work->monResources);
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    PokeathlonSnowThrowCpu_Delete(work->cpu);
    PokeathlonSnowThrowDisplay_Delete(work->display);
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    Heap_Free(work->sortBuffer);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    reg_G2_BLDCNT = 0;
    Heap_Destroy(HEAP_ID_146);
    return TRUE;
}

static void PokeathlonSnowThrow_SetGfxBanks(void) {
    GraphicsBanks banks = sSnowThrowGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokeathlonSnowThrow_InitBgs(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate main0, main1, main3, sub0, sub1, sub2, sub3;

    modes = sSnowThrowGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    main0 = sSnowThrowBgTemplate_Main0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &main0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    main1 = sSnowThrowBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    main3 = sSnowThrowBgTemplate_Main3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main3, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    sub0 = sSnowThrowBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &sub0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    sub1 = sSnowThrowBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &sub1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    sub2 = sSnowThrowBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &sub2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    sub3 = sSnowThrowBgTemplate_Sub3;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_3, &sub3, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_3);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
}

// The field (turned for the own team) and the top screen.
static void PokeathlonSnowThrow_LoadBgGraphics(PokeathlonSnowThrow *work, u8 own) {
    GfGfxLoader_LoadCharData(NARC_a_2_1_7, 1, work->bgConfig, GF_BG_LYR_MAIN_1, 0, 0x4000, FALSE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_1_7, 2, work->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, work->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_1_7, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x20, work->heapId);
    PokeathlonSnowThrowDisplay_LoadBgGraphics(work->display, own);
}

static void PokeathlonSnowThrow_LoadSpriteGraphics(PokeathlonCourseSpritePool *pool) {
    PokeathlonCourseSpritePool_LoadChar(pool, NARC_a_2_1_7, 21, 106, NNS_G2D_VRAM_TYPE_2DBOTH);
    PokeathlonCourseSpritePool_LoadPltt(pool, NARC_a_2_1_7, 18, 106, NNS_G2D_VRAM_TYPE_2DBOTH, 2);
    PokeathlonCourseSpritePool_LoadCell(pool, NARC_a_2_1_7, 20, 106);
    PokeathlonCourseSpritePool_LoadAnim(pool, NARC_a_2_1_7, 19, 106);
    PokeathlonCourseSpritePool_LoadChar(pool, NARC_a_2_1_7, 17, 105, NNS_G2D_VRAM_TYPE_2DMAIN);
    PokeathlonCourseSpritePool_LoadPltt(pool, NARC_a_2_1_7, 14, 105, NNS_G2D_VRAM_TYPE_2DMAIN, 3);
    PokeathlonCourseSpritePool_LoadCell(pool, NARC_a_2_1_7, 16, 105);
    PokeathlonCourseSpritePool_LoadAnim(pool, NARC_a_2_1_7, 15, 105);
}

#pragma push
#pragma opt_common_subs off

static void PokeathlonSnowThrow_CreateSprites(PokeathlonSnowThrow *work, PokeathlonCourseSpritePool *pool, u8 own) {
    int i;
    u8 anim;
    VecFx32 position;
    VecFx32 scale;
    VecFx32 framePosition;
    PokeathlonSnowThrowTeamMarkPositions teamMarkPositions;

    for (i = 0; i < 2; i++) {
        work->timerDigits[i] = PokeathlonCourse_CreateTimerDigitSprite(work->monResources, PokeathlonCourseSpritePool_GetSpriteList(pool), 3, work->heapId);
        Sprite_SetDrawFlag(work->timerDigits[i], TRUE);
        position.x = (i * 16) * FX32_ONE + 24 * FX32_ONE;
        position.y = 8 * FX32_ONE;
        position.z = 0;
        Sprite_SetMatrix(work->timerDigits[i], &position);
        Sprite_SetDrawPriority(work->timerDigits[i], 2);
    }
    PokeathlonSnowThrow_SetTimerDigits(work, SNOW_THROW_DURATION / 30);
    for (i = 0; i < POKEATHLON_MONS; i++) {
        work->balls[i].index = i;
        work->balls[i].sprite = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DBOTH, 106, 3);
        work->balls[i].shadowSprite = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DBOTH, 106, 4);
        work->balls[i].splashSprite = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DBOTH, 106, 6);
        PokeathlonCourseSpritePoolSprite_SetAnim(work->balls[i].shadowSprite, 1);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->balls[i].sprite, 20);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->balls[i].shadowSprite, 1000);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->balls[i].splashSprite, 5);
    }
    for (i = 0; i < POKEATHLON_MONS; i++) {
        work->mons[i].stunSprite = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DBOTH, 106, 9);
        PokeathlonCourseSpritePoolSprite_SetAnim(work->mons[i].stunSprite, 2);
        scale.x = FX32_ONE;
        scale.y = FX32_ONE;
        scale.z = 0;
        PokeathlonCourseSpritePoolSprite_SetPosition(work->mons[i].stunSprite, &scale);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->mons[i].stunSprite, 4);
    }
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        work->hitMarks[i] = PokeathlonCourseSpritePool_CreateAndTake(pool, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 105, 11);
        PokeathlonCourseSpritePoolSprite_SetAnim(work->hitMarks[i], 6);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->hitMarks[i], 2);
    }
    work->frameSprite = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DMAIN, 105, 7);
    framePosition.x = 8 * FX32_ONE;
    framePosition.y = 8 * FX32_ONE;
    framePosition.z = 0;
    PokeathlonCourseSpritePoolSprite_SetPosition(work->frameSprite, &framePosition);
    PokeathlonCourseSpritePoolSprite_SetAnim(work->frameSprite, 5);
    PokeathlonCourseSpritePoolSprite_Show(work->frameSprite, TRUE, TRUE);
    PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->frameSprite, 2);
    teamMarkPositions = sSnowThrowTeamMarkPositions;
    anim = (own + 1) % POKEATHLON_PARTICIPANTS;
    for (i = 0; i < POKEATHLON_PARTICIPANTS - 1; i++) {
        work->teamMarks[i] = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DMAIN, 105, 8);
        PokeathlonCourseSpritePoolSprite_SetPosition(work->teamMarks[i], &teamMarkPositions.positions[i]);
        PokeathlonCourseSpritePoolSprite_SetAnim(work->teamMarks[i], anim + 1);
        PokeathlonCourseSpritePoolSprite_Show(work->teamMarks[i], TRUE, TRUE);
        anim = (anim + 1) % POKEATHLON_PARTICIPANTS;
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->teamMarks[i], 3);
    }
    for (i = 0; i < POKEATHLON_MONS - POKEATHLON_TEAM_SIZE; i++) {
        work->tiredMarks[i] = PokeathlonCourseSpritePool_CreateAndTake(pool, 3, NNS_G2D_VRAM_TYPE_2DMAIN, 105, 10);
        PokeathlonCourseSpritePoolSprite_SetAnim(work->tiredMarks[i], 0);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->tiredMarks[i], 4);
    }
}

#pragma pop

BOOL PokeathlonSnowThrow_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonSnowThrow *work = PokeathlonCourse_GetWork(course);
    switch (*state) {
    case EVENT_PLAY_STATE_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_RUN:
        PokeathlonSnowThrow_UpdateHost(course);
        if (PokeathlonSnowThrow_Update(course)) {
            (*state)++;
        }
        break;
    case EVENT_PLAY_STATE_FINISH:
        PokeathlonSnowThrow_UpdateHost(course);
        if (PokeathlonCourse_RunFinish(course)) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, work->heapId);
            PokeathlonCourse_SetNextState(course, SNOW_THROW_STATE_SAVE_SCORES);
        }
        break;
    }
    return FALSE;
}

// The host stores everyone's score (the hits of the team) for the results.
BOOL PokeathlonSnowThrow_SaveScores(PokeathlonCourseData *course, u8 *state) {
    PokeathlonSnowThrowLink *link = (PokeathlonSnowThrowLink *)PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonSnowThrowPacket *packet;
    int i;
    PokeathlonCourse_GetWork(course);
    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        return FALSE;
    }
    if (PokeathlonCourse_GetNetId(course)) {
        return TRUE;
    }
    packet = (PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(&link->packetToSend);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_SetEventScore(course, (u8)i, packet->teams[i] & 0x3FF);
    }
    return TRUE;
}

// Host: takes everyone's stylus (a touch on an own Pokemon starts a snowball, more taps on it make it bigger, a
// flick away from it throws it), steps the snowballs, the Pokemon and the CPU, and sends the packet.

static void PokeathlonSnowThrow_UpdateHost(PokeathlonCourseData *course) {
    VecFx32 touched;
    VecFx32 touchStart;
    VecFx32 released;
    int i;
    PokeathlonSnowThrow *work;
    PokeathlonSnowThrowTouchBlock *block;
    PokeathlonSnowThrowTouch *touch;
    int ball;
    f32 energyFactor;
    f32 speed;
    f32 hold;
    f32 strength;

    block = (PokeathlonSnowThrowTouchBlock *)PokeathlonCourse_GetDataCopyArea(course);
    work = PokeathlonCourse_GetWork(course);
    if (PokeathlonCourse_GetNetId(course) != 0) {
        return;
    }
    if (work->finished) {
        block++;
        PokeathlonSnowThrow_PackPacket(work, (PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(block));
        return;
    }
    // the host's own stylus goes into its slot of everyone's
    *(PokeathlonSnowThrowTouch *)PokeathlonCourse_ToBytes(&block[2]) = *(PokeathlonSnowThrowTouch *)PokeathlonCourse_ToBytes(block);
    if (work->timer != 0) {
        work->timer--;
    }
    PokeathlonCourse_ToBytes(&block[1]);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        touch = (PokeathlonSnowThrowTouch *)PokeathlonCourse_ToBytes(&(block + 2)[i]);
        if (touch->held) {
            if (work->presses[i].pressed && work->presses[i].held) {
                work->presses[i].pressed = FALSE;
            } else if (!work->presses[i].pressed && !work->presses[i].held) {
                work->presses[i].pressed = TRUE;
                work->presses[i].held = TRUE;
            }
        } else {
            work->presses[i].pressed = FALSE;
            work->presses[i].held = FALSE;
        }
        if (work->presses[i].pressed) {
            ball = PokeathlonSnowThrow_FindOwnMonAt(work, i, touch->x, touch->y, &touched);
            if (ball != SNOW_THROW_NONE) {
                if (work->mons[ball].stunTimer != 0) {
                    continue;
                }
                if (work->balls[ball].state == SNOW_THROW_BALL_NONE || work->balls[ball].state == SNOW_THROW_BALL_HELD) {
                    work->heldBall[i] = ball;
                    work->balls[ball].dragStart = touched;
                    touchStart.x = touch->x << FX32_SHIFT;
                    touchStart.z = touch->y << FX32_SHIFT;
                    touchStart.y = 0;
                    work->balls[ball].touchStart = touchStart;
                    if (work->balls[ball].state == SNOW_THROW_BALL_NONE) {
                        work->balls[ball].position = sSnowThrowMonPositions[ball];
                        work->balls[ball].state = SNOW_THROW_BALL_HELD;
                        work->balls[ball].taps = 0;
                        work->balls[ball].size = 0;
                    }
                }
            }
            work->holdFrames = 0;
        } else if (work->presses[i].held) {
            if (work->heldBall[i] != SNOW_THROW_NONE && work->holdFrames < 30.0) {
                work->holdFrames++;
            }
        } else {
            if (work->heldBall[i] != SNOW_THROW_NONE) {
                ball = PokeathlonSnowThrow_FindOwnMonAt(work, i, touch->x, touch->y, &released);
                if (ball != SNOW_THROW_NONE && ball == work->heldBall[i]) {
                    // released on the Pokemon: one more tap
                    if (work->balls[ball].taps < 4) {
                        work->balls[ball].taps++;
                        if (work->balls[ball].taps <= 1) {
                            work->balls[ball].size = 0;
                        } else if (work->balls[ball].taps <= 2) {
                            work->balls[ball].size = 1;
                        } else if (work->balls[ball].taps <= 3) {
                            work->balls[ball].size = 2;
                        } else {
                            work->balls[ball].size = 3;
                        }
                    }
                } else {
                    // released away from it: a throw, if the stylus went up the screen
                    VecFx32 zero = { 0, 0, 0 };
                    VecFx32 drag;
                    VecFx32 touchDrag;
                    VecFx32 touchEnd;
                    int held = work->heldBall[i];

                    VEC_Subtract(&released, &work->balls[held].dragStart, &drag);
                    touchEnd.x = touch->x << FX32_SHIFT;
                    touchEnd.z = touch->y << FX32_SHIFT;
                    touchEnd.y = 0;
                    VEC_Subtract(&touchEnd, &work->balls[held].touchStart, &touchDrag);
                    if (touchDrag.z <= 0) {
                        work->balls[held].velocity = drag;
                        if (work->mons[held].energy <= 60) {
                            energyFactor = 0.5f;
                        } else if (work->mons[held].energy <= 70) {
                            energyFactor = 0.6f;
                        } else if (work->mons[held].energy <= 80) {
                            energyFactor = 0.7f;
                        } else if (work->mons[held].energy <= 90) {
                            energyFactor = 0.8f;
                        } else {
                            energyFactor = 1.0f;
                        }
                        speed = VEC_Mag(&work->balls[held].velocity) / FX32_ONE;
                        if (speed > 2.0) {
                            speed = 2.0f;
                        } else if (speed < 1.0) {
                            speed = 1.0f;
                        }
                        hold = 1.0 + (f32)work->holdFrames / 30.0;
                        strength = energyFactor * (speed * (2.0 - work->mons[held].throwWeight)) / hold;
                        if (strength > 3.0) {
                            strength = 3.0f;
                        } else if (strength < 1.0) {
                            strength = 1.0f;
                        }
                        VEC_Normalize(&work->balls[held].velocity, &work->balls[held].velocity);
                        VEC_MultAdd(4096.0f * strength, &work->balls[held].velocity, &zero, &work->balls[held].velocity);
                        PokeathlonSnowThrow_AddAimSpread((u8)work->mons[held].aimSpread, &work->balls[held].velocity);
                        work->balls[held].state = SNOW_THROW_BALL_FLYING;
                    }
                }
                work->heldBall[i] = SNOW_THROW_NONE;
            }
            work->holdFrames = 0;
        }
    }
    PokeathlonSnowThrowCpu_Update(work->cpu, SNOW_THROW_DURATION - work->timer);
    PokeathlonSnowThrow_UpdateMons(course);
    PokeathlonSnowThrow_MoveBalls(course);
    PokeathlonSnowThrow_CollideBalls(work);
    PokeathlonSnowThrow_HitMons(course, work);
    if (work->timer == 0) {
        work->finished = TRUE;
    } else {
        work->finished = FALSE;
    }
    block++;
    PokeathlonSnowThrow_PackPacket(work, (PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(block));
}

// Host: packs what everyone draws (see PokeathlonSnowThrowPacket).

static void PokeathlonSnowThrow_PackPacket(PokeathlonSnowThrow *work, PokeathlonSnowThrowPacket *packet) {
    u8 sizes[POKEATHLON_PARTICIPANTS] = { 0, 0, 0, 0 };
    u16 hits[POKEATHLON_PARTICIPANTS] = { 0, 0, 0, 0 };
    int i;
    u32 states = 0;
    u8 hit, wasHit;
    int shift;
    int x, z, team;
    u8 *ballBytes, *monBytes, *packetBytes;

#define BALL ((PokeathlonSnowThrowBall *)(ballBytes + offsetof(PokeathlonSnowThrow, balls)))
#define MON  ((PokeathlonSnowThrowMon *)(monBytes + offsetof(PokeathlonSnowThrow, mons)))
    for (i = 0, shift = 0, ballBytes = (u8 *)work, monBytes = (u8 *)work, packetBytes = (u8 *)packet; i < POKEATHLON_MONS; shift += 2, ballBytes += sizeof(PokeathlonSnowThrowBall), packetBytes += sizeof(u16), monBytes += sizeof(PokeathlonSnowThrowMon), i++) {
        states |= BALL->state << shift;
        wasHit = MON->wasHit;
        hit = BALL->hit != 0 ? 1 : 0;
        BALL->hit = FALSE;
        x = BALL->position.x / FX32_ONE;
        z = BALL->position.z / FX32_ONE;
        if (x < 1) {
            x = 1;
        } else if (x > 64) {
            x = 64;
        }
        if (z < 1) {
            z = 1;
        } else if (z > 64) {
            z = 64;
        }
        team = i / POKEATHLON_TEAM_SIZE;
        sizes[team] += BALL->size << ((i % POKEATHLON_TEAM_SIZE) * 2);
        {
            int value = (x - 1) + ((z - 1) << 6) + (wasHit << 12) + (hit << 13);
            value += MON->condition << 14;
            *(u16 *)(packetBytes + offsetof(PokeathlonSnowThrowPacket, mons)) = value;
        }
        hits[team] += MON->hits;
        if (hits[team] > POKEATHLON_SCORE_MAX) {
            hits[team] = POKEATHLON_SCORE_MAX;
        }
    }
#undef BALL
#undef MON
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        packet->teams[i] = (sizes[i] << 10) + hits[i];
    }
    packet->flags = states;
    packet->flags = states + (work->finished << 24);
    packet->flags += ((work->timer + 30) / 30) << 25;
}

// Sends the own stylus to the host. TRUE when the host says the event is over.

static BOOL PokeathlonSnowThrow_Update(PokeathlonCourseData *course) {
    PokeathlonSnowThrow *work;
    PokeathlonSnowThrowLink *link;
    PokeathlonSnowThrowTouch *touch;

    work = PokeathlonCourse_GetWork(course);
    link = (PokeathlonSnowThrowLink *)PokeathlonCourse_GetDataCopyArea(course);
    touch = (PokeathlonSnowThrowTouch *)PokeathlonCourse_ToBytes(link);
    touch->held = FALSE;
    {
        PokeathlonSnowThrowPacket *packet = (PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(&link->packet);
        u8 finished = (packet->flags >> 24) & 1;
        if (finished) {
            PokeathlonCourseSpritePool_PauseAnims(work->spritePool, TRUE);
            PokeathlonCourseObjects_PauseAnims(work->monObjectList, TRUE);
            PokeathlonCourse_SetFinishCallback(course, PokeathlonSnowThrow_ShowOwnScore);
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
    PokeathlonSnowThrow_DrawPacket(course);
    return FALSE;
}

// Every player: draws the received packet, the field turned so that the own team is at the bottom.

static void PokeathlonSnowThrow_DrawPacket(PokeathlonCourseData *course) {
    VecFx32 hitPosition;
    MtxFx43 hitRotation;
    VecFx32 hitFrom;
    VecFx32 hitTurned;
    VecFx32 ballPosition;
    MtxFx43 ballRotation;
    VecFx32 ballFrom;
    VecFx32 ballTurned;
    VecFx32 scale;
    int hitX;
    int hitY;
    int screenX;
    int screenY;
    int cellX;
    int cellZ;
    PokeathlonSnowThrow *work;
    PokeathlonSnowThrowPacket *packet;
    u8 seconds;
    u8 condition;
    u8 wasHit;
    u8 ballState;
    int ballX;
    int ballZ;
    u8 own;
    int team;
    int turns;
    const fx16 *sinCos;
    int y;
    int member;
    int k;
    u8 mon;
    u8 state;
    u8 size;
    int fieldX;
    int fieldZ;
    int i;
    BOOL done;
    f32 factor;

    work = PokeathlonCourse_GetWork(course);
    packet = (PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + offsetof(PokeathlonSnowThrowLink, packet));
    own = PokeathlonCourse_GetNetId(course);
    seconds = (packet->flags >> 25) & 0x7F;
    PokeathlonSnowThrow_SetTimerDigits(work, seconds == 0 ? 0 : (u8)(seconds - 1));
    PokeathlonSnowThrowDisplay_SetScore(work->display, packet->teams[own] & 0x3FF);
    // where the own snowballs hit someone
    for (i = 0; i < POKEATHLON_MONS; i++) {
        if ((u8)((packet->mons[i] >> 13) & 1) && own == i / POKEATHLON_TEAM_SIZE) {
            PokeathlonCourseSpritePoolSprite_Show(work->hitMarks[(u8)(i % POKEATHLON_TEAM_SIZE)], TRUE, TRUE);
            PokeathlonCourseSpritePoolSprite_SetAnim(work->hitMarks[(u8)(i % POKEATHLON_TEAM_SIZE)], 6);
            fieldX = packet->mons[i] & 0x3F;
            fieldZ = (packet->mons[i] >> 6) & 0x3F;
            fieldX++;
            fieldZ++;
            if (own != 0) {
                turns = POKEATHLON_PARTICIPANTS - own;
                hitFrom.x = fieldX << FX32_SHIFT;
                hitFrom.z = fieldZ << FX32_SHIFT;
                hitFrom.y = 0;
                hitFrom.x -= FX32_CONST(SNOW_THROW_FIELD_CENTER);
                hitFrom.z -= FX32_CONST(SNOW_THROW_FIELD_CENTER);
                sinCos = &FX_SinCosTable_[(((u8)turns * 0x4000) >> 4) << 1];
                MTX_RotY43_(&hitRotation, sinCos[0], sinCos[1]);
                MTX_MultVec43(&hitFrom, &hitRotation, &hitTurned);
                hitTurned.x += FX32_CONST(SNOW_THROW_FIELD_CENTER);
                hitTurned.z += FX32_CONST(SNOW_THROW_FIELD_CENTER);
                fieldX = hitTurned.x / FX32_ONE;
                fieldZ = hitTurned.z / FX32_ONE;
            }
            PokeathlonSnowThrow_FieldToScreen(fieldX, fieldZ, &hitX, &hitY);
            hitPosition.x = hitX << FX32_SHIFT;
            hitPosition.y = hitY << FX32_SHIFT;
            hitPosition.z = 0;
            hitPosition.y = (hitY - 8 - hitY / 20) << FX32_SHIFT;
            PokeathlonCourseSpritePoolSprite_SetPosition(work->hitMarks[(u8)(i % POKEATHLON_TEAM_SIZE)], &hitPosition);
            PlaySE(SEQ_SE_GS_POINT3);
        }
    }
    // the own team, on the top screen
    for (k = 0; k < POKEATHLON_TEAM_SIZE; k++) {
        mon = own * POKEATHLON_TEAM_SIZE + k;
        condition = (packet->mons[mon] >> 14) & 3;
        if (condition == SNOW_THROW_STUNNED) {
            PokeathlonCourseSpritePoolSprite_Show(work->mons[mon].stunSprite, TRUE, TRUE);
            PokeathlonSnowThrowDisplay_ShowTired(work->display, k, FALSE);
        } else if (condition == SNOW_THROW_TIRED) {
            PokeathlonCourseSpritePoolSprite_Show(work->mons[mon].stunSprite, TRUE, FALSE);
            PokeathlonSnowThrowDisplay_ShowTired(work->display, k, TRUE);
        } else {
            PokeathlonCourseSpritePoolSprite_Show(work->mons[mon].stunSprite, TRUE, FALSE);
            PokeathlonSnowThrowDisplay_ShowTired(work->display, k, FALSE);
        }
        wasHit = (packet->mons[mon] >> 12) & 1;
        ballState = (packet->flags >> (mon * 2)) & 3;
        if (condition == SNOW_THROW_STUNNED) {
            PokeathlonSnowThrowDisplay_SetPicAnim(work->display, k, 10);
            work->mons[mon].animTimer = 10;
            if (!IsSEPlaying(SEQ_SE_GS_W146)) {
                PlaySE(SEQ_SE_GS_W146);
            }
            if (wasHit) {
                PlaySE(SEQ_SE_GS_TAMA);
            }
        } else if (wasHit) {
            PokeathlonSnowThrowDisplay_SetPicAnim(work->display, k, 7);
            work->mons[mon].animTimer = 7;
            PlaySE(SEQ_SE_GS_TAMA);
            PokeathlonSnowThrowDisplay_Shake(work->display);
        } else if (ballState == SNOW_THROW_BALL_FLYING && work->mons[mon].throwShown == 0) {
            GF_ASSERT(condition != SNOW_THROW_STUNNED);
            PokeathlonSnowThrowDisplay_SetPicAnim(work->display, k, 4);
            work->mons[mon].animTimer = 4;
            work->mons[mon].throwShown = 1;
            if (work->unk5EF[k] == 0) {
                PlaySE(SEQ_SE_GS_FW104);
            }
        } else {
            done = FALSE;
            if (work->mons[mon].animTimer == 10) {
                done = TRUE;
            } else if (!PokeathlonSnowThrowDisplay_IsPicAnimated(work->display, k)) {
                done = TRUE;
            }
            if (done) {
                PokeathlonSnowThrowDisplay_SetPicAnim(work->display, k, 1);
                work->mons[mon].animTimer = 1;
            }
        }
        if (ballState != SNOW_THROW_BALL_FLYING) {
            work->mons[mon].throwShown = 0;
        }
    }
    // the other teams' Pokemon on the field
    for (k = 0; k < POKEATHLON_MONS - POKEATHLON_TEAM_SIZE; k++) {
        mon = PokeathlonSnowThrow_OtherMon(own, k);
        condition = (packet->mons[mon] >> 14) & 3;
        if (condition == SNOW_THROW_STUNNED) {
            PokeathlonCourseSpritePoolSprite_Show(work->mons[mon].stunSprite, TRUE, TRUE);
            PokeathlonCourseSpritePoolSprite_Show(work->tiredMarks[k], TRUE, FALSE);
        } else if (condition == SNOW_THROW_TIRED) {
            PokeathlonCourseSpritePoolSprite_Show(work->mons[mon].stunSprite, TRUE, FALSE);
            PokeathlonCourseSpritePoolSprite_Show(work->tiredMarks[k], TRUE, TRUE);
        } else {
            PokeathlonCourseSpritePoolSprite_Show(work->mons[mon].stunSprite, TRUE, FALSE);
            PokeathlonCourseSpritePoolSprite_Show(work->tiredMarks[k], TRUE, FALSE);
        }
        wasHit = (packet->mons[mon] >> 12) & 1;
        ballState = (packet->flags >> (mon * 2)) & 3;
        cellX = packet->mons[mon] & 0x3F;
        cellZ = (packet->mons[mon] >> 6) & 0x3F;
        if (condition == SNOW_THROW_STUNNED) {
            PokeathlonCourseMonObject_SetAnim(work->monObjects[k], 20);
            work->mons[mon].animTimer = 20;
            if (!IsSEPlaying(SEQ_SE_GS_W146)) {
                PlaySE(SEQ_SE_GS_W146);
            }
        } else if (wasHit) {
            PokeathlonCourseMonObject_SetAnim(work->monObjects[k], 22);
            work->mons[mon].animTimer = 22;
        } else if (ballState == SNOW_THROW_BALL_FLYING && cellX + 1 == sSnowThrowMonPositions[mon].x / FX32_ONE && cellZ + 1 == sSnowThrowMonPositions[mon].z / FX32_ONE) {
            // just thrown
            GF_ASSERT(condition != SNOW_THROW_STUNNED);
            PokeathlonCourseMonObject_SetAnim(work->monObjects[k], 16);
            work->mons[mon].animTimer = 16;
        } else {
            done = FALSE;
            if (work->mons[mon].animTimer == 20) {
                done = TRUE;
            } else if (!PokeathlonCourseMonObject_IsAnimated(work->monObjects[k])) {
                done = TRUE;
            }
            if (done) {
                PokeathlonCourseMonObject_SetAnim(work->monObjects[k], 0);
                work->mons[mon].animTimer = 0;
            }
        }
    }
    // the snowballs
    for (i = 0; i < POKEATHLON_MONS; i++) {
        state = (packet->flags >> (i * 2)) & 3;
        if (state == SNOW_THROW_BALL_FLYING || state == SNOW_THROW_BALL_HELD) {
            work->balls[i].splashShown = FALSE;
            if (state != SNOW_THROW_BALL_HELD) {
                PokeathlonCourseSpritePoolSprite_Show(work->balls[i].shadowSprite, TRUE, TRUE);
            } else {
                PokeathlonCourseSpritePoolSprite_Show(work->balls[i].shadowSprite, TRUE, FALSE);
            }
            PokeathlonCourseSpritePoolSprite_Show(work->balls[i].sprite, TRUE, TRUE);
            team = i / POKEATHLON_TEAM_SIZE;
            member = i % POKEATHLON_TEAM_SIZE;
            size = ((u8)((packet->teams[i / POKEATHLON_TEAM_SIZE] >> 10) & 0x3F) >> (member * 2)) & 3;
            ballX = (packet->mons[i] & 0x3F) + 1;
            ballZ = ((packet->mons[i] >> 6) & 0x3F) + 1;
            if (own != 0) {
                turns = POKEATHLON_PARTICIPANTS - own;
                ballFrom.x = ballX << FX32_SHIFT;
                ballFrom.z = ballZ << FX32_SHIFT;
                ballFrom.y = 0;
                ballFrom.x -= FX32_CONST(SNOW_THROW_FIELD_CENTER);
                ballFrom.z -= FX32_CONST(SNOW_THROW_FIELD_CENTER);
                sinCos = &FX_SinCosTable_[(((u8)turns * 0x4000) >> 4) << 1];
                MTX_RotY43_(&ballRotation, sinCos[0], sinCos[1]);
                MTX_MultVec43(&ballFrom, &ballRotation, &ballTurned);
                ballTurned.x += FX32_CONST(SNOW_THROW_FIELD_CENTER);
                ballTurned.z += FX32_CONST(SNOW_THROW_FIELD_CENTER);
                ballX = ballTurned.x / FX32_ONE;
                ballZ = ballTurned.z / FX32_ONE;
            }
            PokeathlonSnowThrow_FieldToScreen(ballX, ballZ, &screenX, &screenY);
            ballPosition.x = screenX << FX32_SHIFT;
            ballPosition.y = screenY << FX32_SHIFT;
            ballPosition.z = 0;
            PokeathlonCourseSpritePoolSprite_SetPosition(work->balls[i].shadowSprite, &ballPosition);
            y = screenY;
            ballPosition.y = (y - 8 - y / 20) << FX32_SHIFT;
            PokeathlonCourseSpritePoolSprite_SetPosition(work->balls[i].sprite, &ballPosition);
            // farther away is smaller; bigger snowballs are bigger
            scale = sSnowThrowPacketScale;
            factor = ((f32)screenY + 312.0) / 752.0 * (1.0 + (f32)size / 3.0);
            scale.x = 4096.0f * factor;
            scale.y = 4096.0f * factor;
            PokeathlonCourseSpritePoolSprite_SetScale(work->balls[i].shadowSprite, &scale, 2);
            PokeathlonCourseSpritePoolSprite_SetScale(work->balls[i].sprite, &scale, 2);
            PokeathlonCourseSpritePoolSprite_SetScale(work->balls[i].splashSprite, &scale, 2);
            if (team == own && size != work->shownSizes[member]) {
                PlaySE(SEQ_SE_GS_166);
                work->shownSizes[member] = size;
            }
        } else {
            PokeathlonCourseSpritePoolSprite_Show(work->balls[i].shadowSprite, TRUE, FALSE);
            PokeathlonCourseSpritePoolSprite_Show(work->balls[i].sprite, TRUE, FALSE);
            if (state == SNOW_THROW_BALL_SPLASHED && !work->balls[i].splashShown) {
                work->balls[i].splashShown = TRUE;
                PokeathlonCourseSpritePoolSprite_SetPosition(work->balls[i].splashSprite, PokeathlonCourseSpritePoolSprite_GetPosition(work->balls[i].sprite));
                PokeathlonCourseSpritePoolSprite_SetAnim(work->balls[i].splashSprite, 3);
                PokeathlonCourseSpritePoolSprite_Show(work->balls[i].splashSprite, TRUE, TRUE);
                if (i / POKEATHLON_TEAM_SIZE == own) {
                    PlaySE(SEQ_SE_GS_TAMA3);
                    work->unk5EF[i % POKEATHLON_TEAM_SIZE] = 0;
                    work->shownSizes[i % POKEATHLON_TEAM_SIZE] = 0;
                }
            }
        }
    }
    PokeathlonSnowThrow_SortSprites(work, own);
    PokeathlonCourse_UpdateTimeUpCountdown(course, seconds * 30);
}

// The own Pokemon (of `team`) at touch screen x, y: returns its index (SNOW_THROW_NONE if none) and the field point.
static u8 PokeathlonSnowThrow_FindOwnMonAt(PokeathlonSnowThrow *work, u8 team, u32 x, u32 y, VecFx32 *out) {
    f32 fieldX;
    f32 fieldZ;
    VecFx32 position;
    MtxFx43 rotation;
    VecFx32 relative;
    VecFx32 turned;
    VecFx32 diff;
    int i;

#pragma unused(work)
    PokeathlonSnowThrow_ScreenToField(x, y + 288, &fieldX, &fieldZ);
    position.x = fieldX * FX32_ONE;
    position.z = fieldZ * FX32_ONE;
    position.y = 0;
    if (team != 0) {
        // turn the view back
        relative = position;
        relative.x -= SNOW_THROW_FIELD_CENTER * FX32_ONE;
        relative.z -= SNOW_THROW_FIELD_CENTER * FX32_ONE;
        MTX_RotY43(&rotation, FX_SinIdx(team << 14), FX_CosIdx(team << 14));
        MTX_MultVec43(&relative, &rotation, &turned);
        turned.x += SNOW_THROW_FIELD_CENTER * FX32_ONE;
        turned.z += SNOW_THROW_FIELD_CENTER * FX32_ONE;
        position = turned;
    }
    *out = position;
    for (i = team * POKEATHLON_TEAM_SIZE; i < (team + 1) * POKEATHLON_TEAM_SIZE; i++) {
        VEC_Subtract(&sSnowThrowMonPositions[i], &position, &diff);
        if (VEC_Mag(&diff) <= 4 * FX32_ONE) {
            return i;
        }
    }
    return SNOW_THROW_NONE;
}

// The throw parameters of a Pokemon from its Pokeathlon stats (tables in tenths, NARC a/1/7/0 member 3).
static void PokeathlonSnowThrow_InitMon(PokeathlonCourseData *course, s32 stats[][5], u8 team, u8 member, PokeathlonSnowThrowMon *mon) {
    u8 *levels = PokeathlonCourse_GetMonStats(course, team, member);
    mon->throwWeight = (double)(float)stats[0][levels[4]] / 10.0;
    mon->throwPower = (double)(float)stats[1][levels[0]] / 10.0;
    mon->aimSpread = stats[2][levels[4]];
    mon->hitDamage = stats[3][levels[3]];
    mon->hits = 0;
    mon->stunTimer = 0;
    mon->condition = SNOW_THROW_FINE;
    mon->energy = SNOW_THROW_MAX_ENERGY;
}

static void PokeathlonSnowThrow_InitWindows(PokeathlonSnowThrow *work) {
    int i;

    AddWindow(work->bgConfig, &work->scoreWindow, &sSnowThrowScoreWindowTemplate);
    BG_FillCharDataRange(work->bgConfig, GF_BG_LYR_MAIN_3, 0, 1, 0);
    FillWindowPixelBuffer(&work->scoreWindow, 0);
    for (i = 0; i < POKEATHLON_PARTICIPANTS - 1; i++) {
        AddWindow(work->bgConfig, &work->nameWindows[i], &sSnowThrowNameWindowTemplates[i]);
        FillWindowPixelBuffer(&work->nameWindows[i], 0);
    }
    BG_FillCharDataRange(work->bgConfig, GF_BG_LYR_MAIN_0, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, work->heapId);
}

static void PokeathlonSnowThrow_PrintScore(PokeathlonSnowThrow *work, u16 score) {
    MsgData *msgData;
    MessageFormat *format;
    String *string;

    FillWindowPixelBuffer(&work->scoreWindow, 0);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, work->heapId);
    format = MessageFormat_New(work->heapId);
    BufferIntegerAsString(format, 0, score, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(format, msgData, msg_0309_00164, work->heapId);
    AddTextPrinterParameterizedWithColor(&work->scoreWindow, 4, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    MessageFormat_Delete(format);
    DestroyMsgData(msgData);
    CopyWindowToVram(&work->scoreWindow);
}

// Host: stun and energy recovery of every Pokemon.
static void PokeathlonSnowThrow_UpdateMons(PokeathlonCourseData *course) {
    PokeathlonSnowThrow *work = PokeathlonCourse_GetWork(course);
    int i;

    for (i = 0; i < POKEATHLON_MONS; i++) {
        if (work->mons[i].stunTimer != 0) {
            work->mons[i].stunTimer--;
        }
        if (work->mons[i].energy < SNOW_THROW_MAX_ENERGY) {
            work->mons[i].energy++;
        }
        if (work->mons[i].stunTimer != 0) {
            work->mons[i].condition = SNOW_THROW_STUNNED;
        } else if (work->mons[i].energy <= SNOW_THROW_TIRED_ENERGY) {
            work->mons[i].condition = SNOW_THROW_TIRED;
        } else {
            work->mons[i].condition = SNOW_THROW_FINE;
        }
    }
}

// Host: moves the flying snowballs; a snowball that leaves the field is gone, a splash lasts 8 frames.

static void PokeathlonSnowThrow_MoveBalls(PokeathlonCourseData *course) {
    PokeathlonSnowThrow *work = PokeathlonCourse_GetWork(course);
    int i;
    BOOL gone;

    for (i = 0; i < POKEATHLON_MONS; i++) {
        gone = FALSE;
        if (work->balls[i].state == SNOW_THROW_BALL_FLYING) {
            VEC_MultAdd(FX32_ONE, &work->balls[i].velocity, &work->balls[i].position, &work->balls[i].position);
        } else if (work->balls[i].state == SNOW_THROW_BALL_SPLASHED) {
            work->balls[i].splashTimer++;
            if (work->balls[i].splashTimer >= 8) {
                work->balls[i].splashTimer = 0;
                work->balls[i].state = SNOW_THROW_BALL_NONE;
            }
        }
        if (work->balls[i].position.x < FX32_ONE || work->balls[i].position.x > 64 * FX32_ONE || work->balls[i].position.z < FX32_ONE || work->balls[i].position.z > 64 * FX32_ONE) {
            gone = TRUE;
        }
        if (gone) {
            work->balls[i].state = SNOW_THROW_BALL_NONE;
            work->balls[i].velocity.x = 0;
            work->balls[i].velocity.z = 0;
            work->balls[i].velocity.y = 0;
            work->balls[i].dragStart.x = 0;
            work->balls[i].dragStart.z = 0;
            work->balls[i].dragStart.y = 0;
        }
    }
}

// Host: a flying snowball within 3 units of another team's Pokemon hits it: a hit for the thrower, energy off the
// Pokemon hit (by speed, size, the thrower's power and the target's damage factor), and a stun if that was a lot.

static void PokeathlonSnowThrow_HitMons(PokeathlonCourseData *course, PokeathlonSnowThrow *work) {
    int j, i;
    int team;
    f32 sizeFactor;
    int damage;
    int speed;
    u8 lost;
    VecFx32 diff;

    for (j = 0; j < POKEATHLON_MONS; j++) {
        work->mons[j].wasHit = FALSE;
        for (i = 0; i < POKEATHLON_MONS; i++) {
            if (work->balls[i].state != SNOW_THROW_BALL_FLYING) {
                continue;
            }
            team = i / POKEATHLON_TEAM_SIZE;
            if (team == j / POKEATHLON_TEAM_SIZE) {
                continue;
            }
            VEC_Subtract(&sSnowThrowMonPositions[j], &work->balls[i].position, &diff);
            if (VEC_Mag(&diff) >= 3 * FX32_ONE) {
                continue;
            }
            work->balls[i].state = SNOW_THROW_BALL_SPLASHED;
            PokeathlonCourse_AddMonCounter(course, team, i % POKEATHLON_TEAM_SIZE, POKEATHLON_COUNTER_POINTS, 1);
            work->mons[i].hits++;
            if (work->mons[i].hits > POKEATHLON_SCORE_MAX) {
                work->mons[i].hits = POKEATHLON_SCORE_MAX;
            }
            work->balls[i].hit = TRUE;
            work->mons[j].wasHit = TRUE;
            switch (work->balls[i].size) {
            case 0:
                sizeFactor = 1.0f;
                break;
            case 1:
                sizeFactor = 20.0f;
                break;
            case 2:
                sizeFactor = 50.0f;
                break;
            case 3:
                sizeFactor = 100.0f;
                break;
            default:
                GF_ASSERT(FALSE);
                sizeFactor = 1.0f;
                break;
            }
            work->balls[i].size = 0;
            work->balls[i].taps = 0;
            speed = VEC_Mag(&work->balls[i].velocity) / FX32_ONE;
            damage = speed * sizeFactor * work->mons[i].throwPower * work->mons[j].hitDamage;
            GF_ASSERT(damage >= 0);
            work->mons[j].energy = work->mons[j].energy - damage - 30;
            if (work->mons[j].energy < 0) {
                work->mons[j].energy = 0;
            }
            lost = SNOW_THROW_MAX_ENERGY - work->mons[j].energy;
            if (work->mons[j].stunTimer == 0) {
                if (lost > 40) {
                    work->mons[j].stunTimer = lost;
                    PokeathlonCourse_AddMonCounter(course, j / POKEATHLON_TEAM_SIZE, j % POKEATHLON_TEAM_SIZE, POKEATHLON_COUNTER_FAILURES, 1);
                }
            } else {
                work->mons[j].stunTimer += lost;
                PokeathlonCourse_AddMonCounter(course, j / POKEATHLON_TEAM_SIZE, j % POKEATHLON_TEAM_SIZE, POKEATHLON_COUNTER_FAILURES, 1);
            }
        }
    }
}

// Host: two flying (or held) snowballs closer than 4 units both splash.
static void PokeathlonSnowThrow_CollideBalls(PokeathlonSnowThrow *work) {
    u8 splash[POKEATHLON_MONS];
    VecFx32 diff;
    int i;
    int j;

    for (i = 0; i < POKEATHLON_MONS; i++) {
        splash[i] = FALSE;
    }
    for (i = 0; i < POKEATHLON_MONS; i++) {
        switch (work->balls[i].state) {
        case SNOW_THROW_BALL_FLYING:
        case SNOW_THROW_BALL_HELD:
            for (j = 0; j < POKEATHLON_MONS; j++) {
                if (i == j) {
                    continue;
                }
                switch (work->balls[j].state) {
                case SNOW_THROW_BALL_FLYING:
                case SNOW_THROW_BALL_HELD:
                    VEC_Subtract(&work->balls[i].position, &work->balls[j].position, &diff);
                    if (VEC_Mag(&diff) < 4 * FX32_ONE) {
                        splash[i] = TRUE;
                        splash[j] = TRUE;
                    }
                    break;
                }
            }
            break;
        }
    }
    for (i = 0; i < POKEATHLON_MONS; i++) {
        if (splash[i]) {
            work->balls[i].state = SNOW_THROW_BALL_SPLASHED;
            work->balls[i].size = 0;
            work->balls[i].taps = 0;
        }
    }
}

// The other players' names, in the order of the teams after the own one.
static void PokeathlonSnowThrow_PrintNames(PokeathlonSnowThrow *work, PokeathlonCourseData *course) {
    int i;
    int participant;
    Window *window;
    String *name;
    u8 own;

    own = PokeathlonCourse_GetNetId(course);
    i = 0;
    participant = own + 1;
    window = work->nameWindows;
    for (; i < POKEATHLON_PARTICIPANTS - 1; i++) {
        name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(course, (u8)(participant % POKEATHLON_PARTICIPANTS)), work->heapId);
        AddTextPrinterParameterizedWithColor(window, 0, name, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
        String_Delete(name);
        CopyWindowToVram(window);
        participant++;
        window++;
    }
}

static void PokeathlonSnowThrow_SetTimerDigits(PokeathlonSnowThrow *work, u32 seconds) {
    u8 value = seconds;

    Sprite_SetAnimCtrlSeq(work->timerDigits[0], (u8)(value / 10) + 1);
    Sprite_SetAnimCtrlSeq(work->timerDigits[1], (u8)(value % 10) + 1);
}

// Finish callback: the own team's hits.
static void PokeathlonSnowThrow_ShowOwnScore(PokeathlonCourseData *course) {
    u16 *teams;
    PokeathlonSnowThrow *work;
    u16 score;

    teams = ((PokeathlonSnowThrowPacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + offsetof(PokeathlonSnowThrowLink, packet)))->teams;
    work = PokeathlonCourse_GetWork(course);
    score = teams[(u8)PokeathlonCourse_GetNetId(course)] & 0x3FF;
    if (score > POKEATHLON_SCORE_MAX) {
        score = POKEATHLON_SCORE_MAX;
    }
    PokeathlonCourse_SetRecordScore(course, score);
    PokeathlonSnowThrow_PrintScore(work, score);
}

// MATH_QSort: lower on the screen first, else by the view's order of the Pokemon.
static int PokeathlonSnowThrow_CompareDrawOrder(const void *a, const void *b) {
    const PokeathlonSnowThrowDrawOrder *orderA = a;
    const PokeathlonSnowThrowDrawOrder *orderB = b;
    u8 own = orderA->own;
    s32 result;

    if (orderA->y > orderB->y) {
        result = -1;
    } else if (orderA->y < orderB->y) {
        result = 1;
    } else if (sSnowThrowDrawOrder[own][orderA->index] < sSnowThrowDrawOrder[own][orderB->index]) {
        result = -1;
    } else if (sSnowThrowDrawOrder[own][orderA->index] > sSnowThrowDrawOrder[own][orderB->index]) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

// The snowballs and their shadows overlap in the order of their y on the screen.
static void PokeathlonSnowThrow_SortSprites(PokeathlonSnowThrow *work, u16 own) {
    PokeathlonSnowThrowDrawOrder orders[POKEATHLON_MONS];
    u8 i;
    u8 ball;
    VecFx32 *position;

    for (i = 0; i < POKEATHLON_MONS; i++) {
        position = PokeathlonCourseSpritePoolSprite_GetPosition(work->balls[i].shadowSprite);
        orders[i].index = work->balls[i].index;
        orders[i].y = position->y;
        orders[i].own = own;
    }
    MATH_QSort(orders, POKEATHLON_MONS, sizeof(PokeathlonSnowThrowDrawOrder), PokeathlonSnowThrow_CompareDrawOrder, work->sortBuffer);
    for (i = 0; i < POKEATHLON_MONS; i++) {
        ball = orders[i].index;
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->balls[ball].sprite, i + 20);
        PokeathlonCourseSpritePoolSprite_SetDrawPriority(work->balls[ball].splashSprite, i + 5);
    }
}
