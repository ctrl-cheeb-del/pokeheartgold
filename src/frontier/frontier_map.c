#include "frontier/frontier_map.h"

#include "global.h"

#include "frontier/frontier.h"
#include "frontier/frontier_map_params.h"
#include "frontier/frontier_particles.h"
#include "frontier/frontier_trainers.h"

#include "bg_window.h"
#include "field_bgm.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "options.h"
#include "player_data.h"
#include "render_text.h"
#include "render_window.h"
#include "sound_system.h"
#include "sprite_resource_header.h"
#include "swap_3d_buffers.h"
#include "sys_task_api.h"
#include "system.h"
#include "touchpad.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"

static void FrontierMap_VBlank(FrontierMap *map);
static void FrontierMap_VBlankTask(void);
static void FrontierMap_ObjectTask(SysTask *task, FrontierMap *map);
static void FrontierMap_EventTask(SysTask *task, FrontierMap *map);
static void FrontierMap_Update(SysTask *task, FrontierMap *map);
static void FrontierMap_Scroll(FrontierMap *map);
static void FrontierMap_ScrollToCamera(FrontierMap *map);
static void FrontierMap_ProcessEvents(FrontierMap *map);
static void FrontierMap_SetVramBank(BgConfig *bgConfig, u32 mapId);
static void FrontierMap_LoadPaletteData(FrontierMap *map);
static void FrontierMap_LoadSubScreenGfx(FrontierMap *map);
static void FrontierMap_InitMapObjects(FrontierMap *map, u32 mapId, PlayerProfile *profile);
static void FrontierMap_FreeMapObjects(FrontierMap *map);
static GF3DVramMan *FrontierMap_Create3DVramMan(enum HeapID heapID);
static void FrontierMap_Init3D(void);
static void FrontierMap_Delete3DVramMan(GF3DVramMan *vramMan);
static void FrontierMap_InitSpriteSystem(FrontierMap *map);
static void FrontierMap_FreeSpriteSystem(FrontierMap *map);
static void FrontierMap_SaveSprites(FrontierMap *map);
static void FrontierMap_RestoreSprites(FrontierMap *map);
static void FrontierMapObject_GetTemplate(FrontierMapObject *object, u16 *dest);
static void FrontierMap_SetObject(FrontierWork *frontier, u32 index, Field2DObject *object, Field2DObjectSprite *objectSprite, const FrontierMapObjectTemplate *template);

// Map effect of some frontier maps: two 2x2 tile blocks of BG3 alternate every third frame.

typedef struct FrontierMapTileBlinkTask {
    SysTask *task;
    BgConfig *bgConfig;
    u16 state;
    u16 timer;
} FrontierMapTileBlinkTask;

struct FrontierMapTileBlink {
    u32 unused;
    FrontierMapTileBlinkTask *task;
};

static FrontierMapTileBlinkTask *FrontierMapTileBlink_CreateTask(BgConfig *bgConfig);
static void FrontierMapTileBlink_Task(SysTask *task, void *data);
static void FrontierMapTileBlink_GetTiles(u16 *tiles, u8 state);
static void FrontierMapTileBlink_DestroyTask(FrontierMapTileBlinkTask *blinkTask);

typedef struct FrontierMapMainBgTemplates {
    BgTemplate bg1;
    BgTemplate bg2;
    BgTemplate bg3;
} FrontierMapMainBgTemplates;

static const Field2DBgLayerTemplate sFrontierMapLayerTemplate = {
    .screen = 0,
    .bgLayer = GF_BG_LYR_MAIN_3,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x2800,
    .charBase = GX_BG_CHARBASE_0x30000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .mosaic = 0,
    .narcId = 0,
    .fileId = 0,
    .compressed = TRUE,
};

static const GraphicsModes sFrontierMapGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_5,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_3D,
};

static const OamCharTransferParam sFrontierMapOamCharTransferParam = {
    .maxTasks = 96,
    .sizeMain = 0x10000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_128K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_32K,
};

static const SpriteResourceCountsListUnion sFrontierMapSpriteResourceCounts = {
    { 96, 32, 64, 64, 8, 8 }
};

static const BgTemplate sFrontierMapSubBgTemplate = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0x7800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = 0,
};

static const OamManagerParam sFrontierMapOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 128,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 0,
    .numOBJsub = 128,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const GraphicsBanks sFrontierMapGraphicsBanks = {
    .bg = GX_VRAM_BG_256_BC,
    .bgextpltt = GX_VRAM_BGEXTPLTT_23_G,
    .subbg = GX_VRAM_SUB_BG_32_H,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_0_A,
    .texpltt = GX_VRAM_TEXPLTT_0_F,
};

static const FrontierMapMainBgTemplates sFrontierMapMainBgTemplates = {
    .bg1 = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = 0,
            },
    .bg2 = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_512x512_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_512x512,
            .colorMode = GX_BG_COLORMODE_256,
            .screenBase = GX_BG_SCRBASE_0x0800,
            .charBase = GX_BG_CHARBASE_0x20000,
            .bgExtPltt = GX_BG_EXTPLTT_23,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = 0,
            },
    .bg3 = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_512x512_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_512x512,
            .colorMode = GX_BG_COLORMODE_256,
            .screenBase = GX_BG_SCRBASE_0x2800,
            .charBase = GX_BG_CHARBASE_0x30000,
            .bgExtPltt = GX_BG_EXTPLTT_23,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = 0,
            },
};

static const u32 sFrontierMapCells[16 * 16] = { 0 };

FrontierMapTileBlink *FrontierMapTileBlink_Create(BgConfig *bgConfig) {
    FrontierMapTileBlink *blink;

    blink = Heap_Alloc(HEAP_ID_101, sizeof(FrontierMapTileBlink));
    MI_CpuFill8(blink, 0, sizeof(FrontierMapTileBlink));
    blink->task = FrontierMapTileBlink_CreateTask(bgConfig);
    return blink;
}

static FrontierMapTileBlinkTask *FrontierMapTileBlink_CreateTask(BgConfig *bgConfig) {
    FrontierMapTileBlinkTask *blinkTask = Heap_Alloc(HEAP_ID_101, sizeof(FrontierMapTileBlinkTask));

    MI_CpuFill8(blinkTask, 0, sizeof(FrontierMapTileBlinkTask));
    blinkTask->bgConfig = bgConfig;
    blinkTask->state = 0;
    blinkTask->task = SysTask_CreateOnMainQueue(FrontierMapTileBlink_Task, blinkTask, 79500);
    return blinkTask;
}

static void FrontierMapTileBlink_Task(SysTask *task, void *data) {
    FrontierMapTileBlinkTask *blinkTask = data;
    u16 tiles[4];

    if (blinkTask->timer < 2) {
        blinkTask->timer++;
        return;
    }
    blinkTask->timer = 0;
    blinkTask->state ^= 1;
    FrontierMapTileBlink_GetTiles(tiles, blinkTask->state);
    LoadRectToBgTilemapRect(blinkTask->bgConfig, GF_BG_LYR_MAIN_3, tiles, 14, 2, 2, 2);
    ScheduleBgTilemapBufferTransfer(blinkTask->bgConfig, GF_BG_LYR_MAIN_3);
}

static void FrontierMapTileBlink_GetTiles(u16 *tiles, u8 state) {
    int base;
    int i;
    int j;
    int rowBase;

    if (state == 0) {
        base = 0xC;
    } else {
        base = 0xE;
    }
    rowBase = 0x60;
    for (i = 0; i < 2u; i++) {
        for (j = 0; j < 2u; j++) {
            tiles[i * 2 + j] = base + j + rowBase;
        }
        rowBase += 0x10;
    }
}

void FrontierMapTileBlink_Free(FrontierMapTileBlink *blink) {
    FrontierMapTileBlink_DestroyTask(blink->task);
    Heap_Free(blink);
}

static void FrontierMapTileBlink_DestroyTask(FrontierMapTileBlinkTask *blinkTask) {
    SysTask_Destroy(blinkTask->task);
    Heap_Free(blinkTask);
}

u32 FrontierLinkLobby_GetWinStreakStat(u32 value) {
    switch (value) {
    case FRONTIER_FACILITY_FACTORY_LV50:
        return 0x73;
    case FRONTIER_FACILITY_FACTORY_OPEN:
        return 0x77;
    case FRONTIER_FACILITY_CASTLE:
        return 0x87;
    case FRONTIER_FACILITY_HALL:
        return 0x7B;
    case FRONTIER_FACILITY_ARCADE:
        return 0x8F;
    case FRONTIER_FACILITY_TOWER:
        return 0x71;
    default:
        return value;
    }
}

u32 FrontierLinkLobby_GetStreakActiveStat(u32 value) {
    switch (value) {
    case FRONTIER_FACILITY_FACTORY_LV50:
        return 0x66;
    case FRONTIER_FACILITY_FACTORY_OPEN:
        return 0x68;
    case FRONTIER_FACILITY_CASTLE:
        return 0x6C;
    case FRONTIER_FACILITY_HALL:
        return 0x6A;
    case FRONTIER_FACILITY_ARCADE:
        return 0x6E;
    case FRONTIER_FACILITY_TOWER:
        return 0x64;
    default:
        return value;
    }
}

// The facility map: BGs from the map parameter table, the scrolling camera, the map objects and up to 8 extra
// sprites, plus saving/restoring that state in the frontier application's work while another app runs.

FrontierMap *FrontierMap_Init(FrontierWork *frontier) {
    FrontierLaunchArgs *args = Frontier_GetLaunchArgs(frontier);
    PlayerProfile *profile = Save_PlayerData_GetProfile(args->saveData);
    FrontierMap *map;
    u8 mapId = args->frontierMapId;
    int i;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    G2_BlendNone();
    G2S_BlendNone();
    reg_GX_POWCNT |= REG_GX_POWCNT_DSEL_MASK; // GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB)
    Heap_Create(HEAP_ID_3, HEAP_ID_101, 0x90000);
    map = Heap_Alloc(HEAP_ID_101, sizeof(FrontierMap));
    MI_CpuFill8(map, 0, sizeof(FrontierMap));
    map->frontier = frontier;
    map->mapId = mapId;
    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        map->spriteSet.loadedResourceIds[i] = FRONTIER_MAP_NO_ID;
    }
    map->vramMan = FrontierMap_Create3DVramMan(HEAP_ID_101);
    map->paletteData = PaletteData_Init(HEAP_ID_101);
    PaletteData_SetAutoTransparent(map->paletteData, TRUE);
    PaletteData_AllocBuffers(map->paletteData, PLTTBUF_MAIN_BG, 0x200, HEAP_ID_101);
    PaletteData_AllocBuffers(map->paletteData, PLTTBUF_SUB_BG, 0x200, HEAP_ID_101);
    PaletteData_AllocBuffers(map->paletteData, PLTTBUF_MAIN_OBJ, 0x1C0, HEAP_ID_101);
    PaletteData_AllocBuffers(map->paletteData, PLTTBUF_SUB_OBJ, 0x200, HEAP_ID_101);
    map->bgConfig = BgConfig_Alloc(HEAP_ID_101);
    GF_CreateVramTransferManager(64, HEAP_ID_101);
    SetKeyRepeatTimers(4, 8);
    FrontierMap_SetVramBank(map->bgConfig, mapId);
    FrontierMap_LoadPaletteData(map);
    FrontierMap_LoadSubScreenGfx(map);
    GF_TouchpadResetSampling();
    GF_TouchpadStartSampling(4);
    FrontierMap_InitSpriteSystem(map);
    map->particles = FrontierParticles_New(HEAP_ID_101);
    FrontierMap_InitMapObjects(map, mapId, profile);
    map->objectTask = SysTask_CreateOnMainQueue((SysTaskFunc)FrontierMap_ObjectTask, map, 60000);
    map->eventTask = SysTask_CreateOnMainQueue((SysTaskFunc)FrontierMap_EventTask, map, 61000);
    map->updateTask = SysTask_CreateOnMainQueue((SysTaskFunc)FrontierMap_Update, map, 80000);
    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    Sound_SetFieldBGM(FrontierMap_GetParam(mapId, MAP_PARAM_BGM));
    FieldBGM_Play(NULL, FrontierMap_GetParam(mapId, MAP_PARAM_BGM));
    TextFlags_SetAutoScrollParam(1);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    Main_SetVBlankIntrCB((GFIntrCB)FrontierMap_VBlank, map);
    map->vblankTask = SysTask_CreateOnVBlankQueue((SysTaskFunc)FrontierMap_VBlankTask, map, 10);
    FrontierMap_InitEffect(map, &map->mapEffect, map->mapId);
    WirelessStatusIcon_Create();
    return map;
}

void FrontierMap_Free(FrontierMap *map) {
    Frontier_GetLaunchArgs(map->frontier);
    FrontierMap_ExitEffect(map, &map->mapEffect, map->mapId);
    FrontierMap_FreeMapObjects(map);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    FreeBgTilemapBuffer(map->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(map->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(map->bgConfig, GF_BG_LYR_MAIN_3);
    ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_OFF);
    FreeBgTilemapBuffer(map->bgConfig, GF_BG_LYR_SUB_0);
    FrontierMap_FreeSpriteSystem(map);
    FrontierParticles_Free(map->particles);
    GF_DestroyVramTransferManager();
    PaletteData_FreeBuffers(map->paletteData, PLTTBUF_MAIN_BG);
    PaletteData_FreeBuffers(map->paletteData, PLTTBUF_SUB_BG);
    PaletteData_FreeBuffers(map->paletteData, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffers(map->paletteData, PLTTBUF_SUB_OBJ);
    PaletteData_Free(map->paletteData);
    Heap_Free(map->bgConfig);
    SysTask_Destroy(map->objectTask);
    SysTask_Destroy(map->eventTask);
    SysTask_Destroy(map->updateTask);
    SysTask_Destroy(map->vblankTask);
    FrontierMap_Delete3DVramMan(map->vramMan);
    GF_TouchpadStopSampling();
    Heap_Free(map);
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    Heap_Destroy(HEAP_ID_101);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    WirelessStatusIcon_Destroy();
    MIi_CpuClear16(0x7FFF, (void *)HW_BG_PLTT, HW_BG_PLTT_SIZE);
    MIi_CpuClear16(0x7FFF, (void *)HW_OBJ_PLTT, HW_OBJ_PLTT_SIZE);
    MIi_CpuClear16(0x7FFF, (void *)HW_DB_BG_PLTT, HW_DB_BG_PLTT_SIZE);
    MIi_CpuClear16(0x7FFF, (void *)HW_DB_OBJ_PLTT, HW_DB_OBJ_PLTT_SIZE);
    G2_BlendNone();
    G2S_BlendNone();
}

// Copies the live objects' positions and state into their saved templates (before the map is freed).
void FrontierMap_SaveObjects(FrontierMap *map) {
    s32 i;
    FrontierMapObject *object;

    for (i = 0; i < FRONTIER_MAP_OBJECT_MAX; i++) {
        object = Frontier_GetMapObject(map->frontier, i);
        if (object->object != NULL) {
            object->template.direction = Field2DObject_GetParam(object->object, FIELD2D_OBJECT_PARAM_DIRECTION);
            object->template.action = Field2DObject_GetParam(object->object, FIELD2D_OBJECT_PARAM_ACTION);
            object->template.x = Field2DObject_GetParam(object->object, FIELD2D_OBJECT_PARAM_X);
            object->template.y = Field2DObject_GetParam(object->object, FIELD2D_OBJECT_PARAM_Y);
            object->template.visible = Field2DObjectSprite_IsVisible(object->objectSprite);
        }
    }
    FrontierMap_SaveSprites(map);
}

// Recreates the object graphics, objects and sprites saved by FrontierMap_SaveObjects.
void FrontierMap_RestoreObjects(FrontierMap *map) {
    FrontierMapObjectTemplate template;
    FrontierMapObjectGfx *gfx = Frontier_GetMapObjectGfx(map->frontier);
    int i;

    for (i = 0; i < FRONTIER_MAP_OBJECT_GFX_MAX; i++) {
        if (gfx[i].id != FRONTIER_MAP_NO_ID) {
            Field2DObjectSpriteManager_LoadChar(map->objectGfx, gfx[i].id, gfx[i].animSet, HEAP_ID_101);
        }
    }
    for (i = 0; i < FRONTIER_MAP_OBJECT_MAX; i++) {
        FrontierMapObject *object = Frontier_GetMapObject(map->frontier, i);
        if (object->template.id != FRONTIER_MAP_NO_ID) {
            FrontierMapObject_GetTemplate(object, (u16 *)&template);
            FrontierMap_CreateObject(map, &template, i);
        }
    }
    FrontierMap_RestoreSprites(map);
}

static void FrontierMap_VBlank(FrontierMap *map) {
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    PaletteData_PushTransparentBuffers(map->paletteData);
    DoScheduledBgGpuUpdates(map->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void FrontierMap_VBlankTask(void) {
}

static void FrontierMap_ObjectTask(SysTask *task, FrontierMap *map) {
#pragma unused(task)
    Field2DObjectManager_Update(map->objectManager);
}

static void FrontierMap_EventTask(SysTask *task, FrontierMap *map) {
#pragma unused(task)
    FrontierMap_ProcessEvents(map);
}

static void FrontierMap_Update(SysTask *task, FrontierMap *map) {
#pragma unused(task)
    s32 i;
    u32 mask;
    FrontierMapObject *player = Frontier_GetMapObject(map->frontier, FRONTIER_MAP_OBJECT_MAX - 1);

    if (player->object != NULL) {
        Field2DCamera_CenterOnObject(&map->camera, player->object);
    }
    FrontierMap_Scroll(map);
    Field2DObjectSpriteManager_Update(map->objectGfx);
    mask = map->spriteSet.animActiveMask;
    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (map->spriteSet.sprites[i] != NULL && (mask & 1)) {
            ManagedSprite_TickFrame(map->spriteSet.sprites[i]);
        }
        mask >>= 1;
    }
    SpriteSystem_DrawSprites(map->spriteManager);
    SpriteSystem_UpdateTransfer();
    FrontierParticles_Update();
    RequestSwap3DBuffers(GX_SORTMODE_MANUAL, GX_BUFFERMODE_Z);
}

static void FrontierMap_Scroll(FrontierMap *map) {
    FrontierLaunchArgs *args = Frontier_GetLaunchArgs(map->frontier);

    switch (FrontierMap_GetParam(args->frontierMapId, MAP_PARAM_SCROLL_MODE)) {
    default:
    case 0:
        if (map->bg3Layer != NULL) {
            Field2DBgLayer_SetCamera(map->bg3Layer, &map->camera);
        }
        if (map->bg2Layer != NULL) {
            if (FrontierMap_GetParam(args->frontierMapId, MAP_PARAM_BG2_SCROLLS) == 1) {
                Field2DBgLayer_SetCamera(map->bg2Layer, &map->camera);
            }
        }
        break;
    case 1:
        FrontierMap_ScrollToCamera(map);
        break;
    }
}

// Scroll mode 1: the BGs and the sprite surface follow the camera directly.
static void FrontierMap_ScrollToCamera(FrontierMap *map) {
    FrontierLaunchArgs *args = Frontier_GetLaunchArgs(map->frontier);
    s16 y = map->shake.y + Field2DCamera_GetY(&map->camera);
    s16 x = map->shake.x + Field2DCamera_GetX(&map->camera);
    f32 fy;
    f32 fx;

    if (y > 0) {
        fy = 0.5f + (f32)(y << FX32_SHIFT);
    } else {
        fy = (f32)(y << FX32_SHIFT) - 0.5f;
    }
    if (x > 0) {
        fx = 0.5f + (f32)(x << FX32_SHIFT);
    } else {
        fx = (f32)(x << FX32_SHIFT) - 0.5f;
    }
    G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(map->spriteSystem), (fx32)fx, (fx32)fy);
    ScheduleSetBgPosText(map->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, x);
    ScheduleSetBgPosText(map->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, y);
    if (FrontierMap_GetParam(args->frontierMapId, MAP_PARAM_BG2_SCREEN) != FRONTIER_MAP_NO_ID) {
        if (FrontierMap_GetParam(args->frontierMapId, MAP_PARAM_BG2_SCROLLS) == 1) {
            ScheduleSetBgPosText(map->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, x);
            ScheduleSetBgPosText(map->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, y);
        }
    }
}

static void FrontierMap_ProcessEvents(FrontierMap *map) {
    Field2DCommand event;
    Field2DMove command;

    while (Field2DMoveQueue_Pop(map->moveQueue, &command) == 1) {
        Field2DObjectManager_StartMove(map->objectManager, &command);
    }
    while (Field2DCommandQueue_Pop(map->commandQueue, &event) == 1) {
        if (Field2DObjectManager_TryCommand(map->grid, map->objectManager, &event, &command) == 1) {
            Field2DObjectManager_StartMove(map->objectManager, &command);
        }
    }
}

static void FrontierMap_SetVramBank(BgConfig *bgConfig, u32 mapId) {
    GraphicsBanks banks;
    GraphicsModes graphicsModes;
    BgTemplate subTemplate;
    FrontierMapMainBgTemplates main;
    int bgMode = FrontierMap_GetParam(mapId, MAP_PARAM_BG_MODE);
    u16 bgSize;

    GfGfx_DisableEngineAPlanes();
    banks = sFrontierMapGraphicsBanks;
    GfGfx_SetBanks(&banks);
    MI_CpuClear32((void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);
    graphicsModes = sFrontierMapGraphicsModes;
    graphicsModes.bgMode = (GXBGMode)bgMode;
    SetBothScreensModesAndDisable(&graphicsModes);
    main = sFrontierMapMainBgTemplates;
    if (bgMode == GX_BGMODE_0) {
        main.bg2.colorMode = GX_BG_COLORMODE_16;
        main.bg3.colorMode = GX_BG_COLORMODE_16;
        main.bg2.bgExtPltt = GX_BG_EXTPLTT_01;
        main.bg3.bgExtPltt = GX_BG_EXTPLTT_01;
    }
    bgSize = FrontierMap_GetParam(mapId, MAP_PARAM_BG_SIZE);
    main.bg3.size = bgSize;
    if (FrontierMap_GetParam(mapId, MAP_PARAM_BG2_SCREEN) != FRONTIER_MAP_NO_ID) {
        main.bg2.size = bgSize;
    }
    if (bgMode == GX_BGMODE_0) {
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main.bg1, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &main.bg2, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main.bg3, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    } else {
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main.bg1, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &main.bg2, GF_BG_TYPE_256x16PLTT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &main.bg3, GF_BG_TYPE_256x16PLTT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    }
    G2_SetBG0Priority(0);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    subTemplate = sFrontierMapSubBgTemplate;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &subTemplate, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_Y, 0);
}

static void FrontierMap_LoadPaletteData(FrontierMap *map) {
    PaletteData_LoadNarc(map->paletteData, NARC_graphic_font, 7, HEAP_ID_101, PLTTBUF_MAIN_BG, 0x20, 0xE0);
    PaletteData_LoadNarc(map->paletteData, NARC_graphic_font, 8, HEAP_ID_101, PLTTBUF_MAIN_BG, 0x20, 0xD0);
    LoadUserFrameGfx2(map->bgConfig, GF_BG_LYR_MAIN_1, 0x3E2, 11, Options_GetFrame(Frontier_GetLaunchArgs(map->frontier)->options), HEAP_ID_101);
    PaletteData_LoadPaletteSlotFromHardware(map->paletteData, PLTTBUF_MAIN_BG, 0xB0, 0x20);
    LoadUserFrameGfx1(map->bgConfig, GF_BG_LYR_MAIN_1, 0x3D9, 12, 0, HEAP_ID_101);
    PaletteData_LoadPaletteSlotFromHardware(map->paletteData, PLTTBUF_MAIN_BG, 0xC0, 0x20);
}

static void FrontierMap_LoadSubScreenGfx(FrontierMap *map) {
    NARC *narc = NARC_New(NARC_a_1_8_3, HEAP_ID_101);

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 129, map->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, HEAP_ID_101);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 130, map->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, HEAP_ID_101);
    PaletteData_LoadNarc(map->paletteData, NARC_a_1_8_3, 190, HEAP_ID_101, PLTTBUF_SUB_BG, 0x20, 0);
    NARC_Delete(narc);
}

// Creates the 2D object system for the map and loads the map BGs (BG3, optional BG2).
static void FrontierMap_InitMapObjects(FrontierMap *map, u32 mapId, PlayerProfile *profile) {
    Field2DBgLayerTemplate layerTemplate;
    NNSG2dPaletteData *bg3Pltt;
    NNSG2dPaletteData *bg2Pltt;
    void *plttFile;
    NarcId narcId;
    NARC *narc;
    u32 scrollMode;
    u32 bgMode;

    map->objectManager = Field2DObjectManager_New(32, HEAP_ID_101);
    map->grid = Field2DMap_New(16, 16, HEAP_ID_101);
    Field2DCamera_Init(&map->camera);
    map->objectGfx = Field2DObjectSpriteManager_NewWithShadow(SpriteManager_GetSpriteList(map->spriteManager), map->paletteData, 32, Frontier_GetPlayerSpriteId(profile), 0, 1, HEAP_ID_101);
    layerTemplate = sFrontierMapLayerTemplate;
    layerTemplate.narcId = FrontierMap_GetParam(mapId, MAP_PARAM_NARC);
    layerTemplate.fileId = FrontierMap_GetParam(mapId, MAP_PARAM_BG3_SCREEN);
    scrollMode = FrontierMap_GetParam(mapId, MAP_PARAM_SCROLL_MODE);
    if (scrollMode == 0) {
        map->bg3Layer = Field2DBgLayer_New(SpriteSystem_GetRenderer(map->spriteSystem), map->bgConfig, &layerTemplate, HEAP_ID_101);
    }
    if (FrontierMap_GetParam(mapId, MAP_PARAM_BG2_SCREEN) != FRONTIER_MAP_NO_ID) {
        layerTemplate.fileId = FrontierMap_GetParam(mapId, MAP_PARAM_BG2_SCREEN);
        layerTemplate.bgLayer = GF_BG_LYR_MAIN_2;
        layerTemplate.screenBase = GX_BG_SCRBASE_0x0800;
        layerTemplate.charBase = GX_BG_CHARBASE_0x20000;
        layerTemplate.priority = 1;
        if (scrollMode == 0) {
            map->bg2Layer = Field2DBgLayer_New(SpriteSystem_GetRenderer(map->spriteSystem), map->bgConfig, &layerTemplate, HEAP_ID_101);
        }
    }
    map->commandQueue = Field2DCommandQueue_New(128, HEAP_ID_101);
    map->moveQueue = Field2DMoveQueue_New(128, HEAP_ID_101);
    Field2DMap_Load(map->grid, sFrontierMapCells);
    bgMode = FrontierMap_GetParam(mapId, MAP_PARAM_BG_MODE);
    narcId = (NarcId)FrontierMap_GetParam(mapId, MAP_PARAM_NARC);
    narc = NARC_New(narcId, HEAP_ID_101);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, FrontierMap_GetParam(mapId, MAP_PARAM_BG3_CHAR), map->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_101);
    if (bgMode == GX_BGMODE_0) {
        PaletteData_LoadNarc(map->paletteData, narcId, FrontierMap_GetParam(mapId, MAP_PARAM_BG3_PALETTE), HEAP_ID_101, PLTTBUF_MAIN_BG, 0x160, 0);
    } else {
        plttFile = GfGfxLoader_GetPlttDataFromOpenNarc(narc, FrontierMap_GetParam(mapId, MAP_PARAM_BG3_PALETTE), &bg3Pltt, HEAP_ID_101);
        DC_FlushRange(bg3Pltt->pRawData, bg3Pltt->szByte);
        GX_BeginLoadBGExtPltt();
        GX_LoadBGExtPltt(bg3Pltt->pRawData, 0x6000, 0x2000);
        GX_EndLoadBGExtPltt();
        Heap_Free(plttFile);
    }
    PaletteData_FillPaletteInBuffer(map->paletteData, PLTTBUF_MAIN_BG, PLTTSEL_BOTH, 0, 0, 1);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, FrontierMap_GetParam(mapId, MAP_PARAM_BG3_SCREEN), map->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_101);
    if (FrontierMap_GetParam(mapId, MAP_PARAM_BG2_SCREEN) != FRONTIER_MAP_NO_ID) {
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, FrontierMap_GetParam(mapId, MAP_PARAM_BG2_CHAR), map->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_101);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, FrontierMap_GetParam(mapId, MAP_PARAM_BG2_SCREEN), map->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_101);
        if (bgMode != GX_BGMODE_0) {
            void *bg2PlttFile = GfGfxLoader_GetPlttDataFromOpenNarc(narc, FrontierMap_GetParam(mapId, MAP_PARAM_BG2_PALETTE), &bg2Pltt, HEAP_ID_101);
            DC_FlushRange(bg2Pltt->pRawData, bg2Pltt->szByte);
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(bg2Pltt->pRawData, 0x4000, 0x2000);
            GX_EndLoadBGExtPltt();
            Heap_Free(bg2PlttFile);
        }
    }
    ScheduleBgTilemapBufferTransfer(map->bgConfig, GF_BG_LYR_MAIN_3);
    NARC_Delete(narc);
}

static void FrontierMap_FreeMapObjects(FrontierMap *map) {
    s32 i;
    FrontierMapObject *object = Frontier_GetMapObjects(map->frontier);

    for (i = 0; i < FRONTIER_MAP_OBJECT_MAX; i++) {
        if (object->object != NULL) {
            Field2DObject_Delete(object->object);
            GF_ASSERT(object->movementTask == NULL);
        }
        object++;
    }
    Field2DObjectManager_Free(map->objectManager);
    Field2DMap_Free(map->grid);
    Field2DObjectSpriteManager_Free(map->objectGfx);
    if (map->bg3Layer != NULL) {
        Field2DBgLayer_Free(map->bg3Layer);
    }
    if (map->bg2Layer != NULL) {
        Field2DBgLayer_Free(map->bg2Layer);
    }
    Field2DCommandQueue_Free(map->commandQueue);
    Field2DMoveQueue_Free(map->moveQueue);
}

static GF3DVramMan *FrontierMap_Create3DVramMan(enum HeapID heapID) {
    return GF_3DVramMan_Create(heapID, 0, 1, 0, 1, FrontierMap_Init3D);
}

static void FrontierMap_Init3D(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    G2_SetBG0Priority(1);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(GX_RGB(0, 0, 0), 0, 0x7FFF, 63, FALSE);
    G3_ViewPort(0, 0, 255, 191);
}

static void FrontierMap_Delete3DVramMan(GF3DVramMan *vramMan) {
    GF_3DVramMan_Delete(vramMan);
}

static void FrontierMap_InitSpriteSystem(FrontierMap *map) {
    map->spriteSystem = SpriteSystem_Alloc(HEAP_ID_101);
    SpriteSystem_Init(map->spriteSystem, &sFrontierMapOamManagerParam, &sFrontierMapOamCharTransferParam, 32);
    G2dRenderer_SetObjCharTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN, GX_OBJVRAMMODE_CHAR_1D_128K);
    G2dRenderer_SetPlttTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN);
    map->spriteManager = SpriteManager_New(map->spriteSystem);
    SpriteSystem_InitSprites(map->spriteSystem, map->spriteManager, 128);
    SpriteSystem_InitManagerWithCapacities(map->spriteSystem, map->spriteManager, (SpriteResourceCountsListUnion *)&sFrontierMapSpriteResourceCounts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(map->spriteSystem), 0, FX32_CONST(512));
}

typedef BOOL (*SpriteManagerUnloadFunc)(SpriteManager *spriteManager, int id);

static void FrontierMap_FreeSpriteSystem(FrontierMap *map) {
    int i;

    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (map->spriteSet.sprites[i] != NULL) {
            FrontierMapSprite_Delete(map->spriteSet.sprites[i]);
        }
    }
    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (map->spriteSet.loadedResourceIds[i] != FRONTIER_MAP_NO_ID) {
            FrontierMapSprite_UnloadResources(map->spriteManager, map->spriteSet.loadedResourceIds[i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (map->monSprites[i] != NULL) {
            Sprite_DeleteAndFreeResources(map->monSprites[i]);
            ((SpriteManagerUnloadFunc)SpriteManager_UnloadCharObjById)(map->spriteManager, 50000 + i);
            ((SpriteManagerUnloadFunc)SpriteManager_UnloadPlttObjById)(map->spriteManager, 50000 + i);
            ((SpriteManagerUnloadFunc)SpriteManager_UnloadCellObjById)(map->spriteManager, 50000 + i);
            ((SpriteManagerUnloadFunc)SpriteManager_UnloadAnimObjById)(map->spriteManager, 50000 + i);
        }
    }
    SpriteSystem_FreeResourcesAndManager(map->spriteSystem, map->spriteManager);
    SpriteSystem_Free(map->spriteSystem);
}

void FrontierMap_AddObjectGfx(FrontierMap *map, const FrontierMapObjectGfx *gfx) {
    FrontierMapObjectGfx *table = Frontier_GetMapObjectGfx(map->frontier);
    int i;
    FrontierMapObjectGfx *entry;
    int slot;
    u16 id = gfx->id;

    for (i = 0, entry = table; i < FRONTIER_MAP_OBJECT_GFX_MAX; i++, entry++) {
        if (id == entry->id) {
            return;
        }
    }
    for (slot = 0; slot < FRONTIER_MAP_OBJECT_GFX_MAX; slot++) {
        if (table[slot].id == FRONTIER_MAP_NO_ID) {
            break;
        }
    }
    GF_ASSERT(slot != FRONTIER_MAP_OBJECT_GFX_MAX);
    table[slot] = *gfx;
    Field2DObjectSpriteManager_LoadChar(map->objectGfx, gfx->id, gfx->animSet, HEAP_ID_101);
}

void FrontierMap_RemoveObjectGfx(FrontierMap *map, u16 id) {
    s32 i;
    FrontierMapObjectGfx *table = Frontier_GetMapObjectGfx(map->frontier);

    for (i = 0; i < FRONTIER_MAP_OBJECT_GFX_MAX; i++) {
        if (id == table[i].id) {
            Field2DObjectSpriteManager_UnloadChar(map->objectGfx, id);
            table[i].id = FRONTIER_MAP_NO_ID;
            return;
        }
    }
}

// index -1: first free object slot.
Field2DObject *FrontierMap_CreateObject(FrontierMap *map, const FrontierMapObjectTemplate *template, int index) {
    FrontierMapObject *slot = Frontier_GetMapObjects(map->frontier);
    Field2DObjectTemplate args;
    Field2DObject *object;
    Field2DObjectSprite *objectSprite;

    if (index == -1) {
        for (index = 0; index < FRONTIER_MAP_OBJECT_MAX; index++, slot++) {
            if (slot->object == NULL) {
                break;
            }
        }
        GF_ASSERT(index != FRONTIER_MAP_OBJECT_MAX);
    }
    args.x = template->x;
    args.y = template->y;
    args.id = template->id;
    args.action = template->action;
    args.direction = template->direction;
    args.spriteId = template->spriteId;
    object = Field2DObjectManager_AddObject(map->objectManager, &args);
    objectSprite = Field2DObjectSpriteManager_CreateSprite(map->objectGfx, object, 0, HEAP_ID_101);
    Field2DObjectSprite_SetVisible(objectSprite, template->visible);
    FrontierMap_SetObject(map->frontier, index, object, objectSprite, template);
    return object;
}

void FrontierMap_DeleteObject(FrontierMap *map, Field2DObject *object) {
    s32 i;
    FrontierMapObject *objects = Frontier_GetMapObjects(map->frontier);

    for (i = 0; i < FRONTIER_MAP_OBJECT_MAX; i++) {
        if (objects[i].object == object) {
            Field2DObject_Delete(objects[i].object);
            Field2DObjectSprite_Delete(objects[i].objectSprite);
            GF_ASSERT(objects[i].movementTask == NULL);
            MI_CpuFill8(&objects[i], 0, sizeof(FrontierMapObject));
            objects[i].template.id = FRONTIER_MAP_NO_ID;
            return;
        }
    }
}

void FrontierMap_GetObjectById(FrontierMap *map, u16 id, Field2DObject **object, Field2DObjectSprite **objectSprite) {
    s32 i;
    FrontierMapObject *objects = Frontier_GetMapObjects(map->frontier);

    for (i = 0; i < FRONTIER_MAP_OBJECT_MAX; i++) {
        if (id == objects[i].template.id) {
            if (object != NULL) {
                *object = objects[i].object;
            }
            if (objectSprite != NULL) {
                *objectSprite = objects[i].objectSprite;
            }
            return;
        }
    }
    GF_ASSERT(FALSE);
}

void FrontierMap_AddLoadedResource(FrontierMap *map, u16 resourceId) {
    s32 i;

    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (map->spriteSet.loadedResourceIds[i] == FRONTIER_MAP_NO_ID) {
            map->spriteSet.loadedResourceIds[i] = resourceId;
            return;
        }
    }
    GF_ASSERT(FALSE);
}

void FrontierMap_RemoveLoadedResource(FrontierMap *map, u16 resourceId) {
    s32 i;

    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (resourceId == map->spriteSet.loadedResourceIds[i]) {
            map->spriteSet.loadedResourceIds[i] = FRONTIER_MAP_NO_ID;
            return;
        }
    }
}

ManagedSprite *FrontierMap_CreateSprite(FrontierMap *map, u16 index, u16 resourceId) {
    ManagedSprite *sprite;

    GF_ASSERT(index < FRONTIER_MAP_SPRITE_MAX);
    GF_ASSERT(map->spriteSet.sprites[index] == NULL);
    sprite = FrontierMapSprite_Create(map->spriteSystem, map->spriteManager, resourceId);
    map->spriteSet.sprites[index] = sprite;
    map->spriteSet.resourceIds[index] = resourceId;
    FrontierMap_SetSpriteAnimActive(map, index, FALSE);
    return sprite;
}

void FrontierMap_DeleteSprite(FrontierMap *map, u32 index) {
    GF_ASSERT(index < FRONTIER_MAP_SPRITE_MAX);
    GF_ASSERT(map->spriteSet.sprites[index] != NULL);
    FrontierMapSprite_Delete(map->spriteSet.sprites[index]);
    map->spriteSet.sprites[index] = NULL;
}

ManagedSprite *FrontierMap_GetSprite(FrontierMap *map, u32 index) {
    return map->spriteSet.sprites[index];
}

void FrontierMap_SetSpriteAnimActive(FrontierMap *map, u16 index, u32 active) {
    if (active == TRUE) {
        map->spriteSet.animActiveMask = map->spriteSet.animActiveMask | (1 << index);
    } else {
        map->spriteSet.animActiveMask = ((1 << index) ^ 0xFFFFFFFF) & map->spriteSet.animActiveMask;
    }
}

u32 FrontierMap_IsSpriteAnimActive(FrontierMap *map, u16 index) {
    return (map->spriteSet.animActiveMask >> index) & 1;
}

static void FrontierMap_SaveSprites(FrontierMap *map) {
    FrontierMapSpriteState *state = Frontier_GetMapSpriteState(map->frontier);
    FrontierMapSpriteSet *spriteSet = &map->spriteSet;
    int i;

    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        u16 resourceId = spriteSet->loadedResourceIds[i];
        if (resourceId != FRONTIER_MAP_NO_ID) {
            state->resourceIds[i] = resourceId;
            i++; // skips the next slot
        }
    }
    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (spriteSet->sprites[i] != NULL) {
            state->sprites[i].anim = ManagedSprite_GetActiveAnim(spriteSet->sprites[i]);
            state->sprites[i].frame = ManagedSprite_GetAnimationFrame(spriteSet->sprites[i]);
            state->sprites[i].animActive = FrontierMap_IsSpriteAnimActive(map, i);
            state->sprites[i].draw = ManagedSprite_GetDrawFlag(spriteSet->sprites[i]);
            state->sprites[i].resourceId = spriteSet->resourceIds[i];
            ManagedSprite_GetPositionXY(spriteSet->sprites[i], &state->sprites[i].x, &state->sprites[i].y);
            state->sprites[i].active = TRUE;
        }
    }
}

static void FrontierMap_RestoreSprites(FrontierMap *map) {
    FrontierMapSpriteState *state = Frontier_GetMapSpriteState(map->frontier);
    NARC *narc = NARC_New(NARC_a_1_8_4, HEAP_ID_101);
    int i;
    ManagedSprite *sprite;

    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (state->resourceIds[i] != FRONTIER_MAP_NO_ID) {
            FrontierMapSprite_LoadResources(map->spriteSystem, map->spriteManager, narc, map->paletteData, state->resourceIds[i]);
            FrontierMap_AddLoadedResource(map, state->resourceIds[i]);
        }
    }
    for (i = 0; i < FRONTIER_MAP_SPRITE_MAX; i++) {
        if (state->sprites[i].active == TRUE) {
            sprite = FrontierMap_CreateSprite(map, i, state->sprites[i].resourceId);
            ManagedSprite_SetPositionXY(sprite, state->sprites[i].x, state->sprites[i].y);
            ManagedSprite_SetDrawFlag(sprite, state->sprites[i].draw);
            FrontierMap_SetSpriteAnimActive(map, i, state->sprites[i].animActive);
            ManagedSprite_SetAnim(sprite, state->sprites[i].anim);
            ManagedSprite_SetAnimationFrame(sprite, state->sprites[i].frame);
        }
    }
    NARC_Delete(narc);
    Frontier_ResetMapSpriteState(map->frontier);
}

void FrontierMap_GetCameraPos(FrontierMap *map, u16 *x, u16 *y) {
    *y = Field2DCamera_GetY(&map->camera);
    *x = Field2DCamera_GetX(&map->camera);
}

static void FrontierMapObject_GetTemplate(FrontierMapObject *object, u16 *dest) {
    u16 *src = (u16 *)&object->template;
    u32 i = sizeof(FrontierMapObjectTemplate) / 2;

    do {
        *dest++ = *src++;
    } while (--i != 0);
}

static void FrontierMap_SetObject(FrontierWork *frontier, u32 index, Field2DObject *object, Field2DObjectSprite *objectSprite, const FrontierMapObjectTemplate *template) {
    FrontierMapObject *slot = Frontier_GetMapObject(frontier, index);

    slot->object = object;
    slot->objectSprite = objectSprite;
    slot->template = *template;
}

FrontierMapObject *FrontierMap_FindObject(FrontierWork *frontier, u32 id) {
    s32 i;
    FrontierMapObject *object = Frontier_GetMapObjects(frontier);

    for (i = 0; i < FRONTIER_MAP_OBJECT_MAX; i++) {
        if (object->object != NULL && object->template.id == id) {
            return object;
        }
        object++;
    }
    GF_ASSERT(FALSE);
    return NULL;
}
