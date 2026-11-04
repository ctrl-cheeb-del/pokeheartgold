#include "constants/maps.h"

#include "application/pokedex/pokedex_internal.h"
#include "application/pokedex/pokedex_internal_constants.h"
#include "application/zukanlist/zkn_data/zukan_data.naix"
#include "application/zukanlist/zkn_data/zukan_enc.naix"
#include "application/zukanlist/zkn_data/zukan_hw_data.naix"
#include "graphic/zukan_gra.naix"
#include "msgdata/msg.naix"

#include "dex_mon_measures.h"
#include "gf_gfx_loader.h"
#include "pokedex_util.h"
#include "sprite_system.h"
#include "sound_playback.h"
#include "pokedex_language.h"
#include "pokedex_language_order.h"

static void PokedexApp_SetListBgPriorities(void);
static void PokedexApp_SetSearchBgPriorities(void);
static void PokedexApp_SetFormsBgPriorities(void);
static void PokedexApp_SetAreaBgPriorities(void);
static void PokedexApp_SetSizeCheckBgPriorities(void);
static void PokedexApp_SetEntryMenuBgPriorities(void);
static void PokedexApp_LoadListGraphics(PokedexAppData *pokedexApp);
static void PokedexApp_3DigitNumToTiles(u16 *a0, u16 a1, u16 a2);
static void PokedexApp_LoadSearchGraphics(PokedexAppData *pokedexApp);
static void PokedexApp_HighlightSearchOption(PokedexAppData *pokedexApp, const PokedexBgRect *rect, BOOL highlight);
static void PokedexApp_MoveSearchOptionHighlight(PokedexAppData *pokedexApp, const PokedexBgRect *rects, u32 *selection, int newIndex);
static void PokedexApp_DisableSearchAreaOption1(PokedexAppData *pokedexApp);
static void PokedexApp_HighlightBodyTypeOption(PokedexAppData *pokedexApp, u32 index, BOOL highlight);
static void PokedexApp_HighlightLetterOption(PokedexAppData *pokedexApp, u32 index, BOOL highlight);
static void PokedexApp_ApplyPendingSubBgPriority(PokedexAppData *pokedexApp);
static void PokedexApp_LoadAreaGraphics(PokedexAppData *pokedexApp);
static void PokedexApp_LoadSizeCheckGraphics(PokedexAppData *pokedexApp);
static void PokedexApp_LoadEntryMenuGraphics(PokedexAppData *pokedexApp);
static u8 PokedexApp_GetSeenGenderForm(PokedexAppData *pokedexApp, u8 idx);
static void PokedexApp_LoadEncounterMaps(PokedexMapList *mapList, u16 species, int table);
static void PokedexApp_AddOverworldAreas(PokedexAppData *pokedexApp, PokedexMapList *mapList, int region, int sourceBit);
static void PokedexApp_AddDungeonAreas(PokedexAppData *pokedexApp, PokedexMapList *mapList, int region, int startIndex, int sourceBit);
static u32 PokedexApp_GetAlphabeticalMapIndex(u32 mapId);
static void PokedexApp_SortAreaList(PokedexAppData *pokedexApp);
static u32 PokedexApp_GetRoute2AreaIndex(void);
static u32 PokedexApp_GetRoute16AreaIndex(void);

static const u16 sOverworldMapIDs[70] = {
    0xFFFF,
    MAP_NEW_BARK,
    MAP_ROUTE_29,
    MAP_CHERRYGROVE,
    MAP_ROUTE_30,
    MAP_ROUTE_31,
    MAP_VIOLET,
    MAP_ROUTE_32,
    MAP_ROUTE_33,
    MAP_ROUTE_34,
    MAP_ROUTE_35,
    MAP_ROUTE_36,
    MAP_ROUTE_37,
    MAP_ECRUTEAK,
    MAP_ROUTE_38,
    MAP_ROUTE_39,
    MAP_OLIVINE,
    MAP_ROUTE_40,
    MAP_ROUTE_41,
    MAP_CIANWOOD,
    MAP_ROUTE_42,
    MAP_ROUTE_43,
    MAP_LAKE_OF_RAGE,
    MAP_ROUTE_44,
    MAP_BLACKTHORN,
    MAP_ROUTE_45,
    MAP_ROUTE_46,
    MAP_ROUTE_47,
    MAP_MOUNT_SILVER,
    MAP_ROUTE_12,
    MAP_ROUTE_19,
    MAP_ROUTE_20,
    MAP_PALLET,
    MAP_VIRIDIAN,
    MAP_CERULEAN,
    MAP_VERMILION,
    MAP_CELADON,
    MAP_FUCHSIA,
    MAP_CINNABAR_ISLAND,
    MAP_ROUTE_48,
    MAP_ROUTE_26,
    MAP_ROUTE_27,
    MAP_ROUTE_28,
    MAP_ROUTE_1,
    MAP_ROUTE_2,
    MAP_ROUTE_3,
    MAP_ROUTE_4,
    MAP_ROUTE_5,
    MAP_ROUTE_6,
    MAP_ROUTE_7,
    MAP_ROUTE_8,
    MAP_ROUTE_9,
    MAP_ROUTE_10,
    MAP_ROUTE_11,
    MAP_ROUTE_13,
    MAP_ROUTE_14,
    MAP_ROUTE_15,
    MAP_ROUTE_16_EAST,
    MAP_ROUTE_17,
    MAP_ROUTE_18,
    MAP_ROUTE_21,
    MAP_ROUTE_22,
    MAP_ROUTE_24,
    MAP_ROUTE_25,
    MAP_ROUTE_2_EAST,
    MAP_PEWTER,
    MAP_AZALEA,
    MAP_SAFARI_ZONE_GATE,
    MAP_ROUTE_16,
    0xFFFF,
};

static const u16 sDungeonMapIDs[] = {
    0xFFFF,
    MAP_SPROUT_TOWER_2F,
    MAP_RUINS_OF_ALPH,
    MAP_UNION_CAVE_1F,
    MAP_SLOWPOKE_WELL_B1F,
    MAP_ILEX_FOREST,
    MAP_NATIONAL_PARK,
    MAP_BURNED_TOWER_1F,
    MAP_BELL_TOWER_2F,
    MAP_WHIRL_ISLANDS_1F,
    MAP_MOUNT_MORTAR_1F_ENTRANCE,
    MAP_ICE_PATH_1F,
    MAP_DRAGONS_DEN,
    MAP_DARK_CAVE_ROUTE_31_SIDE,
    MAP_MOUNT_MOON_SQUARE,
    MAP_SEAFOAM_ISLANDS_1F,
    MAP_MOUNT_SILVER_CAVE_MOLTRES_CHAMBER,
    MAP_CLIFF_EDGE_GATE,
    MAP_CLIFF_CAVE,
    MAP_SS_AQUA_OLIVINE_PORT_INTERIOR,
    MAP_ROCK_TUNNEL_1F,
    MAP_VICTORY_ROAD_1F,
    MAP_TOHJO_FALLS,
    MAP_DIGLETT_CAVE,
    MAP_VIRIDIAN_FOREST,
    MAP_CERULEAN_CAVE_1F,
};

static const int sMapIDs_Alphabetical[142] = {
    MAP_ROUTE_1,
    MAP_ROUTE_2,
    MAP_ROUTE_2_EAST,
    MAP_ROUTE_3,
    MAP_ROUTE_4,
    MAP_ROUTE_5,
    MAP_ROUTE_6,
    MAP_ROUTE_7,
    MAP_ROUTE_8,
    MAP_ROUTE_9,
    MAP_ROUTE_10,
    MAP_ROUTE_11,
    MAP_ROUTE_12,
    MAP_ROUTE_13,
    MAP_ROUTE_14,
    MAP_ROUTE_15,
    MAP_ROUTE_16_EAST,
    MAP_ROUTE_16,
    MAP_ROUTE_17,
    MAP_ROUTE_18,
    MAP_ROUTE_19,
    MAP_ROUTE_20,
    MAP_ROUTE_21,
    MAP_ROUTE_22,
    MAP_ROUTE_24,
    MAP_ROUTE_25,
    MAP_ROUTE_26,
    MAP_ROUTE_27,
    MAP_ROUTE_28,
    MAP_ROUTE_29,
    MAP_ROUTE_30,
    MAP_ROUTE_31,
    MAP_ROUTE_32,
    MAP_ROUTE_33,
    MAP_ROUTE_34,
    MAP_ROUTE_35,
    MAP_ROUTE_36,
    MAP_ROUTE_37,
    MAP_ROUTE_38,
    MAP_ROUTE_39,
    MAP_ROUTE_40,
    MAP_ROUTE_41,
    MAP_ROUTE_42,
    MAP_ROUTE_43,
    MAP_ROUTE_44,
    MAP_ROUTE_45,
    MAP_ROUTE_46,
    MAP_ROUTE_47,
    MAP_ROUTE_48,
    MAP_AZALEA,
    MAP_BELL_TOWER_2F,
    MAP_BELL_TOWER_3F,
    MAP_BELL_TOWER_4F,
    MAP_BELL_TOWER_5F,
    MAP_BELL_TOWER_6F,
    MAP_BELL_TOWER_7F,
    MAP_BELL_TOWER_8F,
    MAP_BELL_TOWER_9F,
    MAP_BELL_TOWER_10F,
    MAP_BLACKTHORN,
    MAP_BURNED_TOWER_1F,
    MAP_BURNED_TOWER_B1F,
    MAP_CELADON,
    MAP_CERULEAN_CAVE_1F,
    MAP_CERULEAN_CAVE_2F,
    MAP_CERULEAN_CAVE_B1F,
    MAP_CERULEAN,
    MAP_CHERRYGROVE,
    MAP_CIANWOOD,
    MAP_CINNABAR_ISLAND,
    MAP_CLIFF_CAVE,
    MAP_CLIFF_EDGE_GATE,
    MAP_DIGLETT_CAVE,
    MAP_DARK_CAVE_ROUTE_45_SIDE,
    MAP_DARK_CAVE_ROUTE_31_SIDE,
    MAP_DRAGONS_DEN,
    MAP_ECRUTEAK,
    MAP_FUCHSIA,
    MAP_ICE_PATH_1F,
    MAP_ICE_PATH_B1F,
    MAP_ICE_PATH_B2F,
    MAP_ICE_PATH_B3F,
    MAP_ILEX_FOREST,
    MAP_LAKE_OF_RAGE,
    MAP_MOUNT_MOON,
    MAP_MOUNT_MOON_SQUARE_ENTRANCE,
    MAP_MOUNT_MOON_SQUARE,
    MAP_MOUNT_MOON_SQUARE_CLEFAIRY_EVENT,
    MAP_MOUNT_MORTAR_1F_ENTRANCE,
    MAP_MOUNT_MORTAR_1F_BACK,
    MAP_MOUNT_MORTAR_2F,
    MAP_MOUNT_MORTAR_B1F,
    MAP_MOUNT_SILVER,
    MAP_MOUNT_SILVER_CAVE_1F,
    MAP_MOUNT_SILVER_CAVE_UPPER_MOUNTAINSIDE,
    MAP_MOUNT_SILVER_CAVE_LOWER_MOUNTAINSIDE,
    MAP_MOUNT_SILVER_CAVE_EXPERT_BELT_CHAMBER,
    MAP_MOUNT_SILVER_CAVE_MOLTRES_CHAMBER,
    MAP_MOUNT_SILVER_CAVE_2F,
    MAP_MOUNT_SILVER_CAVE_3F,
    MAP_NATIONAL_PARK,
    MAP_NATIONAL_PARK_BUG_CATCHING_CONTEST,
    MAP_NEW_BARK,
    MAP_SS_AQUA_OLIVINE_PORT_INTERIOR,
    MAP_OLIVINE,
    MAP_PALLET,
    MAP_PEWTER,
    MAP_ROCK_TUNNEL_1F,
    MAP_ROCK_TUNNEL_B1F,
    MAP_RUINS_OF_ALPH,
    MAP_RUINS_OF_ALPH_UNDERGROUND_HALL,
    MAP_RUINS_OF_ALPH_UNDERGROUND_HALL_SINJOH_EVENT,
    MAP_RUINS_OF_ALPH_HALL_ENTRANCE_SINJOH_EVENT,
    MAP_RUINS_OF_ALPH_UNDERGROUND_HALL_SINJOH_EVENT_2,
    MAP_SLOWPOKE_WELL_B1F,
    MAP_SLOWPOKE_WELL_B2F,
    MAP_SAFARI_ZONE_ENTRANCE_EXTERIOR,
    MAP_SAFARI_ZONE_GATE,
    MAP_SEAFOAM_ISLANDS_1F,
    MAP_SEAFOAM_ISLANDS_B1F,
    MAP_SEAFOAM_ISLANDS_B2F,
    MAP_SEAFOAM_ISLANDS_B3F,
    MAP_SEAFOAM_ISLANDS_B4F,
    MAP_SPROUT_TOWER_2F,
    MAP_SPROUT_TOWER_3F,
    MAP_TOHJO_FALLS,
    MAP_TOHJO_FALLS_HIDDEN_ROOM,
    MAP_UNION_CAVE_1F,
    MAP_UNION_CAVE_B1F,
    MAP_UNION_CAVE_B2F,
    MAP_VERMILION,
    MAP_VICTORY_ROAD_1F,
    MAP_VICTORY_ROAD_2F,
    MAP_VICTORY_ROAD_3F,
    MAP_VIOLET,
    MAP_VIRIDIAN,
    MAP_VIRIDIAN_FOREST,
    MAP_WHIRL_ISLANDS_1F,
    MAP_WHIRL_ISLANDS_B1F,
    MAP_WHIRL_ISLANDS_B2F,
    MAP_WHIRL_ISLANDS_B3F,
    MAP_WHIRL_ISLANDS_B3F_LUGIA_CAVE,
};

static const GraphicsBanks sGraphicsBanks = {
    .bg = GX_VRAM_BG_128_B,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_0_A,
    .texpltt = GX_VRAM_TEXPLTT_01_FG,
};

static const u8 sLanguages[6] = {
    LANGUAGE_JAPANESE,
    LANGUAGE_ENGLISH,
    LANGUAGE_FRENCH,
    LANGUAGE_ITALIAN,
    LANGUAGE_GERMAN,
    LANGUAGE_SPANISH,
};

static const PokedexBgRect sSearchOrderOptionRects[] = {
    { 3,  6,  11, 2 },
    { 18, 6,  11, 2 },
    { 3,  10, 11, 2 },
    { 18, 10, 11, 2 },
    { 3,  14, 11, 2 },
    { 18, 14, 11, 2 },
};

static const PokedexBgRect sSearchTypeOptionRects[18] = {
    { 0,  5,  8, 2 },
    { 8,  5,  8, 2 },
    { 16, 5,  8, 2 },
    { 24, 5,  8, 2 },
    { 0,  8,  8, 2 },
    { 8,  8,  8, 2 },
    { 16, 8,  8, 2 },
    { 24, 8,  8, 2 },
    { 0,  11, 8, 2 },
    { 8,  11, 8, 2 },
    { 16, 11, 8, 2 },
    { 24, 11, 8, 2 },
    { 0,  14, 8, 2 },
    { 8,  14, 8, 2 },
    { 16, 14, 8, 2 },
    { 24, 14, 8, 2 },
    { 0,  17, 8, 2 },
    { 8,  17, 8, 2 },
};

static const PokedexBgRect sSearchAreaOptionRects[] = {
    { 6,  8,  7, 2 },
    { 19, 8,  7, 2 },
    { 6,  15, 7, 2 },
    { 19, 15, 7, 2 },
};

static const u8 sLetterGridCells[] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    27,
};

void PokedexApp_VBlankCallback(void *cb_arg) {
    PokedexAppData *pokedexApp = cb_arg;

    PaletteData_PushTransparentBuffers(pokedexApp->paletteData);
    PokedexApp_ApplyPendingSubBgPriority(pokedexApp);
    DoScheduledBgGpuUpdates(pokedexApp->bgConfig);
    SpriteSystem_TransferOam();
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

void PokedexApp_SetGraphicsBanks(void) {
    GfGfx_SetBanks(&sGraphicsBanks);
}

void PokedexApp_InitBgs(PokedexAppData *pokedexApp) {
    pokedexApp->bgConfig = BgConfig_Alloc(HEAP_ID_POKEDEX_APP);

    {
        GraphicsModes graphicsModes = {
            GX_DISPMODE_GRAPHICS,
            GX_BGMODE_0,
            GX_BGMODE_0,
            GX_BG0_AS_2D,
        };

        SetBothScreensModesAndDisable(&graphicsModes);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_512x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_512x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe800,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_1);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe000,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_2, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xd800,
            .charBase = GX_BG_CHARBASE_0x18000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_3);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_3, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_512x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_512x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_SUB_0, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_0);
        BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe800,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_SUB_1, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);
        BG_ClearCharDataRange(GF_BG_LYR_SUB_1, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe000,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_SUB_2, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_2);
        BG_ClearCharDataRange(GF_BG_LYR_SUB_2, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }

    {
        BgTemplate bgTemplate = {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xd800,
            .charBase = GX_BG_CHARBASE_0x18000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = 0,
        };

        InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, &bgTemplate, GF_BG_TYPE_TEXT);
        PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_3);
        BG_ClearCharDataRange(GF_BG_LYR_SUB_3, 0x20, 0, HEAP_ID_POKEDEX_APP);
    }
}

void PokedexApp_SetSubBg3Mode(PokedexAppData *pokedexApp, BOOL useAffine) {
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
    if (!useAffine) {
        {
            GraphicsModes graphicsModes = {
                GX_DISPMODE_GRAPHICS,
                GX_BGMODE_0,
                GX_BGMODE_0,
                GX_BG0_AS_2D,
            };

            SetScreenModeAndDisable(&graphicsModes, SCREEN_SUB);
        }

        {
            BgTemplate bgTemplate = {
                .x = 0,
                .y = 0,
                .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
                .baseTile = 0,
                .size = GF_BG_SCR_SIZE_256x256,
                .colorMode = GX_BG_COLORMODE_16,
                .screenBase = GX_BG_SCRBASE_0xd800,
                .charBase = GX_BG_CHARBASE_0x18000,
                .bgExtPltt = GX_BG_EXTPLTT_01,
                .priority = 3,
                .areaOver = GX_BG_AREAOVER_XLU,
                .dummy = 0,
                .mosaic = 0,
            };

            InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, &bgTemplate, GF_BG_TYPE_TEXT);
            PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_3);
            BG_ClearCharDataRange(GF_BG_LYR_SUB_3, 0x20, 0, HEAP_ID_POKEDEX_APP);
        }
    } else {
        {
            GraphicsModes graphicsModes = {
                GX_DISPMODE_GRAPHICS,
                GX_BGMODE_0,
                GX_BGMODE_1,
                GX_BG0_AS_2D,
            };

            SetScreenModeAndDisable(&graphicsModes, SCREEN_SUB);
        }

        {
            BgTemplate bgTemplate = {
                .x = 0,
                .y = 0,
                .bufferSize = GF_BG_BUF_SIZE_256x256_8BPP,
                .baseTile = 0,
                .size = GF_BG_SCR_SIZE_256x256,
                .colorMode = GX_BG_COLORMODE_256,
                .screenBase = GX_BG_SCRBASE_0xd800,
                .charBase = GX_BG_CHARBASE_0x18000,
                .bgExtPltt = GX_BG_EXTPLTT_01,
                .priority = 2,
                .areaOver = GX_BG_AREAOVER_XLU,
                .dummy = 0,
                .mosaic = 0,
            };

            InitBgFromTemplate(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, &bgTemplate, GF_BG_TYPE_AFFINE);
            PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_3);
            BG_ClearCharDataRange(GF_BG_LYR_SUB_3, 0x40, 0, HEAP_ID_POKEDEX_APP);
        }
    }

    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

void PokedexApp_FreeBgs(PokedexAppData *pokedexApp) {
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    Heap_Free(pokedexApp->bgConfig);
}

static void PokedexApp_SetListBgPriorities(void) {
    // main bg
    SetBgPriority(GF_BG_LYR_MAIN_0, 2);
    SetBgPriority(GF_BG_LYR_MAIN_1, 0);
    SetBgPriority(GF_BG_LYR_MAIN_2, 1);
    SetBgPriority(GF_BG_LYR_MAIN_3, 3);

    // sub bg
    SetBgPriority(GF_BG_LYR_SUB_0, 0);
    SetBgPriority(GF_BG_LYR_SUB_1, 1);
    SetBgPriority(GF_BG_LYR_SUB_2, 2);
    SetBgPriority(GF_BG_LYR_SUB_3, 3);
}

static void PokedexApp_SetSearchBgPriorities(void) {
    // main bg
    SetBgPriority(GF_BG_LYR_MAIN_0, 1);
    SetBgPriority(GF_BG_LYR_MAIN_1, 0);
    SetBgPriority(GF_BG_LYR_MAIN_2, 2);
    SetBgPriority(GF_BG_LYR_MAIN_3, 3);

    // sub bg
    SetBgPriority(GF_BG_LYR_SUB_0, 0);
    SetBgPriority(GF_BG_LYR_SUB_1, 1);
    SetBgPriority(GF_BG_LYR_SUB_2, 2);
    SetBgPriority(GF_BG_LYR_SUB_3, 3);
}

static void PokedexApp_SetFormsBgPriorities(void) {
    // main bg
    SetBgPriority(GF_BG_LYR_MAIN_0, 1);
    SetBgPriority(GF_BG_LYR_MAIN_1, 0);
    SetBgPriority(GF_BG_LYR_MAIN_2, 2);
    SetBgPriority(GF_BG_LYR_MAIN_3, 3);

    // sub bg
    SetBgPriority(GF_BG_LYR_SUB_0, 0);
    SetBgPriority(GF_BG_LYR_SUB_1, 1);
    SetBgPriority(GF_BG_LYR_SUB_2, 2);
    SetBgPriority(GF_BG_LYR_SUB_3, 3);
}

static void PokedexApp_SetAreaBgPriorities(void) {
    // main bg
    SetBgPriority(GF_BG_LYR_MAIN_0, 1);
    SetBgPriority(GF_BG_LYR_MAIN_1, 0);
    SetBgPriority(GF_BG_LYR_MAIN_2, 2);
    SetBgPriority(GF_BG_LYR_MAIN_3, 3);

    // sub bg
    SetBgPriority(GF_BG_LYR_SUB_0, 3);
    SetBgPriority(GF_BG_LYR_SUB_1, 0);
    SetBgPriority(GF_BG_LYR_SUB_2, 1);
    SetBgPriority(GF_BG_LYR_SUB_3, 2);
}

static void PokedexApp_SetSizeCheckBgPriorities(void) {
    // main bg
    SetBgPriority(GF_BG_LYR_MAIN_0, 1);
    SetBgPriority(GF_BG_LYR_MAIN_1, 0);
    SetBgPriority(GF_BG_LYR_MAIN_2, 2);
    SetBgPriority(GF_BG_LYR_MAIN_3, 3);

    // sub bg
    SetBgPriority(GF_BG_LYR_SUB_0, 0);
    SetBgPriority(GF_BG_LYR_SUB_1, 1);
    SetBgPriority(GF_BG_LYR_SUB_2, 3);
    SetBgPriority(GF_BG_LYR_SUB_3, 2);
}

static void PokedexApp_SetEntryMenuBgPriorities(void) {
    // main bg
    SetBgPriority(GF_BG_LYR_MAIN_0, 1);
    SetBgPriority(GF_BG_LYR_MAIN_1, 0);
    SetBgPriority(GF_BG_LYR_MAIN_2, 2);
    SetBgPriority(GF_BG_LYR_MAIN_3, 3);

    // sub bg
    SetBgPriority(GF_BG_LYR_SUB_0, 0);
    SetBgPriority(GF_BG_LYR_SUB_1, 1);
    SetBgPriority(GF_BG_LYR_SUB_2, 3);
    SetBgPriority(GF_BG_LYR_SUB_3, 2);
}

void PokedexApp_ClearBgTilemap(PokedexAppData *pokedexApp, u8 bgId) {
    u8 width;

    if (bgId == GF_BG_LYR_MAIN_0 || bgId == GF_BG_LYR_SUB_0) {
        width = 0x40;
    } else {
        width = 0x20;
    }

    FillBgTilemapRect(pokedexApp->bgConfig, bgId, 0, 0, 0, width, 0x20, 0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, bgId);
}

void PokedexApp_InitBlend(void) {
    G2_SetBlendAlpha(0, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3, 6, 10);
}

void PokedexApp_SetBg2Bg3Blend(u8 ev1, u8 ev2) {
    G2_SetBlendAlpha(GX_PLANEMASK_BG2, GX_PLANEMASK_BG3, ev1, ev2);
}

void PokedexApp_InitPaletteData(PokedexAppData *pokedexApp) {
    pokedexApp->paletteData = PaletteData_Init(HEAP_ID_POKEDEX_APP);
    ZeroPalettesByBitmask(PLTTBUF_MAIN_BG_F | PLTTBUF_SUB_BG_F | PLTTBUF_MAIN_OBJ_F | PLTTBUF_SUB_OBJ_F, HEAP_ID_POKEDEX_APP);
    PaletteData_AllocBuffers(pokedexApp->paletteData, PLTTBUF_MAIN_BG, 0x200, HEAP_ID_POKEDEX_APP);
    PaletteData_AllocBuffers(pokedexApp->paletteData, PLTTBUF_SUB_BG, 0x200, HEAP_ID_POKEDEX_APP);
    PaletteData_AllocBuffers(pokedexApp->paletteData, PLTTBUF_MAIN_OBJ, 0x200, HEAP_ID_POKEDEX_APP);
    PaletteData_AllocBuffers(pokedexApp->paletteData, PLTTBUF_SUB_OBJ, 0x200, HEAP_ID_POKEDEX_APP);
}

void PokedexApp_FreePaletteData(PokedexAppData *pokedexApp) {
    PaletteData_FreeBuffers(pokedexApp->paletteData, PLTTBUF_SUB_OBJ);
    PaletteData_FreeBuffers(pokedexApp->paletteData, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffers(pokedexApp->paletteData, PLTTBUF_SUB_BG);
    PaletteData_FreeBuffers(pokedexApp->paletteData, PLTTBUF_MAIN_BG);
    PaletteData_Free(pokedexApp->paletteData);
}

void PokedexApp_InitMsgData(PokedexAppData *pokedexApp) {
    pokedexApp->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0802_bin, HEAP_ID_POKEDEX_APP);
    pokedexApp->msgFormat = MessageFormat_New(HEAP_ID_POKEDEX_APP);
    pokedexApp->strBufFormatted = String_New(0x400, HEAP_ID_POKEDEX_APP);
}

void PokedexApp_FreeMsgData(PokedexAppData *pokedexApp) {
    String_Delete(pokedexApp->strBufFormatted);
    MessageFormat_Delete(pokedexApp->msgFormat);
    DestroyMsgData(pokedexApp->msgData);
}

void PokedexApp_LoadSearchTables(PokedexAppData *pokedexApp) {
    NARC *narc = NARC_New(NARC_application_zukanlist_zkn_data_zukan_hw_data, HEAP_ID_POKEDEX_APP);
    pokedexApp->sliderValues = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_hw_data_zukan_hw_data_0_bin, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
    pokedexApp->speciesAreaMasks = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_hw_data_zukan_hw_data_1_bin, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
    NARC_Delete(narc);
}

void PokedexApp_FreeSearchTables(PokedexAppData *pokedexApp) {
    Heap_Free(pokedexApp->speciesAreaMasks);
    Heap_Free(pokedexApp->sliderValues);
}

void PokedexApp_InitBgCells(PokedexAppData *pokedexApp) {
    pokedexApp->bgCellManager = BgCellManager_New(pokedexApp->bgConfig, 2, 24, HEAP_ID_POKEDEX_APP);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 0, 2, 32, 5);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 1, 2, 32, 5);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 2, 0, 22, 4);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 3, 0, 22, 4);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 4, 2, 32, 4);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 5, 3, 32, 5);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 6, 1, 32, 4);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 7, 1, 32, 4);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 8, 2, 32, 5);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 9, 0, 32, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 10, 2, 32, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 11, 5, 32, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 12, 6, 32, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 13, 4, 32, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 15, 0, 32, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 14, 0, 3, 24);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 16, 1, 32, 4);
    BgCellManager_InitCell(pokedexApp->bgCellManager, 23, 7, 20, 4);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 0, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000005_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 1, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000006_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 2, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000007_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 3, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000008_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 4, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000009_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 5, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000010_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 6, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000069_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 7, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000070_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 8, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000071_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 13, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000016_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 16, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000011_NSCR_lz, 1);
    BgCellManager_LoadCellTilemapFromOpenNarc(pokedexApp->bgCellManager, 23, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000088_NSCR_lz, 1);
    BgCellManager_SetCellClipRect(pokedexApp->bgCellManager, 11, 0, 32, 0, 19);
    BgCellManager_SetCellClipRect(pokedexApp->bgCellManager, 12, 0, 32, 0, 19);
    PokedexApp_InitAreaListCells(pokedexApp);
}

void PokedexApp_FreeBgCells(PokedexAppData *pokedexApp) {
    BgCellManager_Delete(pokedexApp->bgCellManager);
}

void PokedexApp_SlideInListButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 0, 0, 24);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 0, 0, -1, 5);
}

void PokedexApp_SlideOutListButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 0, 0, 19);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 0, 0, 1, 5);
}

void PokedexApp_DrawEntryNameBar(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 4, 0, 15);
}

void PokedexApp_SlideInEntryButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 1, 0, 24);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 1, 0, -1, 5);
}

void PokedexApp_SlideOutEntryButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 1, 0, 19);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 1, 0, 1, 5);
}

void PokedexApp_SlideInSearchMenuButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 6, 0, 24);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 6, 0, -1, 4);
}

void PokedexApp_SlideOutSearchMenuButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 6, 0, 20);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 6, 0, 1, 4);
}

void PokedexApp_SlideInSearchPageButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 7, 0, 24);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 7, 0, -1, 4);
}

void PokedexApp_SlideOutSearchPageButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 7, 0, 20);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 7, 0, 1, 4);
}

void PokedexApp_SlideInSearchResultButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 8, 0, 24);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 8, 0, -1, 5);
}

void PokedexApp_SlideOutSearchResultButtons(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 8, 0, 19);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 8, 0, 1, 5);
}

void PokedexApp_SlideInEntryTabs(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 16, 0, 24);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 16, 0, -1, 4);
}

void PokedexApp_SlideOutEntryTabs(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 16, 0, 20);
    BgCellManager_StartCellMove(pokedexApp->bgCellManager, 16, 0, 1, 4);
}

void PokedexApp_DimEntryTabsIfNotCaught(PokedexAppData *pokedexApp) {
    u16 *tilemap = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 16);
    u16 paletteBits;

    if (Pokedex_CheckMonCaughtFlag(pokedexApp->args->pokedex, pokedexApp->curSpecies)) {
        paletteBits = 0;
    } else {
        paletteBits = 0xB000;
    }
    for (u32 i = 0; i < 4; ++i) {
        for (u32 j = 8; j < 16; ++j) {
            tilemap[32 * i + j] = (tilemap[32 * i + j] & 0xFFF) | paletteBits;
        }
    }
}

void PokedexApp_ShowAreaUnknownBanner(PokedexAppData *pokedexApp) {
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 23, 10, 11);
    ScheduleWindowCopyToVram(&pokedexApp->windows[3]);
}

void PokedexApp_HideAreaUnknownBanner(PokedexAppData *pokedexApp) {
    BgCellManager_EraseCell(pokedexApp->bgCellManager, 23);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[3]);
}

void PokedexApp_SetupScreen(PokedexAppData *pokedexApp, int screen) {
    switch (screen) {
    case 0:
        PokedexApp_LoadListGraphics(pokedexApp);
        PokedexApp_SetListBgPriorities();
        PokedexApp_SetupListWindows(pokedexApp);
        PokedexApp_SetupListSprites(pokedexApp);
        break;
    case 1:
        PokedexApp_LoadAreaGraphics(pokedexApp);
        PokedexApp_SetAreaBgPriorities();
        PokedexApp_SetupAreaWindows(pokedexApp);
        PokedexApp_SetupAreaSprites(pokedexApp);
        break;
    case 2:
        PokedexApp_LoadSizeCheckGraphics(pokedexApp);
        PokedexApp_SetSizeCheckBgPriorities();
        PokedexApp_SetupSizeCheckWindows(pokedexApp);
        PokedexApp_SetupSizeCheckSprites(pokedexApp);
        break;
    case 3:
        PokedexApp_LoadFormsGraphics(pokedexApp);
        PokedexApp_SetFormsBgPriorities();
        PokedexApp_SetupFormsWindows(pokedexApp);
        PokedexApp_SetupFormsSprites(pokedexApp);
        break;
    case 4:
        PokedexApp_LoadEntryMenuGraphics(pokedexApp);
        PokedexApp_SetEntryMenuBgPriorities();
        PokedexApp_SetupEntryMenuWindows(pokedexApp);
        break;
    case 5:
        PokedexApp_LoadSearchGraphics(pokedexApp);
        PokedexApp_SetSearchBgPriorities();
        PokedexApp_SetupSearchWindows(pokedexApp);
        PokedexApp_SetupSearchSprites(pokedexApp);
        break;
    }
}

static void PokedexApp_LoadListGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_3);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_2);

    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000001_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    {
        NNSG2dScreenData *scrnData;
        void *scrnDataRaw = GfGfxLoader_GetScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000000_NSCR_lz, TRUE, &scrnData, HEAP_ID_POKEDEX_APP);
        BG_LoadScreenTilemapData(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, scrnData->rawData, 0x1000);
        Heap_Free(scrnDataRaw);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000003_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000002_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_MAIN_BG, 0, 0);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000017_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000016_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000019_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    if (pokedexApp->language == 2) {
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000020_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    } else {
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000021_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    }
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_BG, 0, 0);
    if (!pokedexApp->nationalDex) {
        FillBgTilemapRect(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0x16, 3, 15, 26, 2, TILEMAP_FILL_KEEP_PAL);
    }
    PokedexApp_DrawDexModeLabel(pokedexApp);
    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 0, 0, 19);
    PokedexApp_DrawListNumbers(pokedexApp);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

void PokedexApp_DrawDexModeLabel(PokedexAppData *pokedexApp) {
    if (pokedexApp->dexMode == 0) {
        BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 2, 5, 3);
    } else {
        BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 3, 5, 3);
    }
}

static void PokedexApp_3DigitNumToTiles(u16 *dest, u16 num, u16 baseTile) {
    u8 pow10s[3] = { 100, 10, 1 };

#ifdef BUGFIX
    GF_ASSERT(num <= 999);
#endif // BUGFIX

    for (u8 i = 0; i < 3; ++i) {
        dest[i] = (baseTile + (num / pow10s[i])) | 0x1000;
        num %= pow10s[i];
    }
}

u16 *PokedexApp_BuildListNumberTilemap(PokedexAppData *pokedexApp, u32 firstIndex) {
    u16 *ret = Heap_AllocAtEnd(HEAP_ID_POKEDEX_APP, 160 * 10 * sizeof(u16));
    u16 *cellTilemap = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 5);
    u32 listLength = PokedexApp_GetListLength(pokedexApp, TRUE);

    for (u16 i = 0; i < 10; ++i) {
        MI_CpuCopy16(cellTilemap, &ret[160 * i], 160 * sizeof(u16));
        for (u16 j = 0; j < 5; ++j) {
            u32 entryIndex = firstIndex + 5 * i + j;
            if (entryIndex >= listLength) {
                break;
            }
            if (pokedexApp->listEntries[entryIndex].caughtState == POKEDEXAPP_ENTRY_CAUGHT) {
                ret[160 * i + 36 + 5 * j] = 0x1002;
                PokedexApp_3DigitNumToTiles(&ret[160 * i + 37 + 5 * j], entryIndex + 1, 3);
            } else {
                PokedexApp_3DigitNumToTiles(&ret[160 * i + 37 + 5 * j], entryIndex + 1, 14);
            }
        }
    }

    return ret;
}

u16 *PokedexApp_BuildSearchResultNumberTilemap(PokedexAppData *pokedexApp, u32 firstIndex) {
    u16 *ret = Heap_AllocAtEnd(HEAP_ID_POKEDEX_APP, 160 * 10 * sizeof(u16));
    u16 *cellTilemap = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 5);

    for (u16 i = 0; i < 10; ++i) {
        MI_CpuCopy16(cellTilemap, &ret[160 * i], 160 * sizeof(u16));
        for (u16 j = 0; j < 5; ++j) {
            u32 entryIndex = firstIndex + 5 * i + j;
            if (pokedexApp->listEntries[entryIndex].species == SPECIES_NONE) {
                continue;
            }
            u32 dexNo = Pokedex_ConvertToCurrentDexNo(pokedexApp->dexMode, pokedexApp->listEntries[entryIndex].species);
            if (pokedexApp->listEntries[entryIndex].caughtState == POKEDEXAPP_ENTRY_CAUGHT) {
                ret[160 * i + 36 + 5 * j] = 0x1002;
                PokedexApp_3DigitNumToTiles(&ret[160 * i + 37 + 5 * j], dexNo, 3);
            } else {
                PokedexApp_3DigitNumToTiles(&ret[160 * i + 37 + 5 * j], dexNo, 14);
            }
        }
    }

    return ret;
}

void PokedexApp_FreeNumberTilemap(u16 *tilemap) {
    Heap_Free(tilemap);
}

void PokedexApp_DrawListNumbers(PokedexAppData *pokedexApp) {
    u16 *tilemap = PokedexApp_BuildListNumberTilemap(pokedexApp, 15 * pokedexApp->listPage);
    PokedexApp_LoadNumberTilemap(pokedexApp, tilemap);
    PokedexApp_FreeNumberTilemap(tilemap);
}

void PokedexApp_DrawSearchResultNumbers(PokedexAppData *pokedexApp) {
    u16 *tilemap = PokedexApp_BuildSearchResultNumberTilemap(pokedexApp, 15 * pokedexApp->listPage);
    PokedexApp_LoadNumberTilemap(pokedexApp, tilemap);
    PokedexApp_FreeNumberTilemap(tilemap);
}

void PokedexApp_LoadNumberTilemap(PokedexAppData *pokedexApp, u16 *tilemap) {
    LoadRectToBgTilemapRect(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, tilemap, 0, 0, 32, 24);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
}

BOOL PokedexApp_HasCaughtInLanguage(PokedexAppData *pokedexApp, u16 species, u16 language) {
    // explicit comparison to FALSE required to match
    if (Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex) == FALSE) {
        return FALSE;
    }

    return Pokedex_HasCaughtMonWithLanguage(pokedexApp->args->pokedex, species, language);
}

BOOL PokedexApp_HasForeignEntries(PokedexAppData *pokedexApp, u16 species) {
    for (int i = 0; i < NELEMS(sLanguages); ++i) {
        if (sLanguages[i] != GAME_LANGUAGE && PokedexApp_HasCaughtInLanguage(pokedexApp, species, sLanguages[i]) == TRUE) {
            return TRUE;
        }
    }

    return FALSE;
}

void PokedexApp_CycleListEntryLanguage(PokedexAppData *pokedexApp, u16 species, s16 delta) {
    if (Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex) == FALSE) {
        return;
    }

    s16 dexFlag = LanguageToDexFlag(pokedexApp->language);
    for (u32 i = 0; i < 6; ++i) {
        dexFlag = CycleDexLanguageFlag(dexFlag, delta);
        s16 language = DexFlagToLanguage(dexFlag);
        if (language == pokedexApp->language) {
            return;
        }
        if (PokedexApp_HasCaughtInLanguage(pokedexApp, species, language) == TRUE || language == GAME_LANGUAGE) {
            int cursorIndex = PokedexApp_GetListCursorIndex(pokedexApp);
            pokedexApp->language = language;
            PokedexApp_DrawCenteredSpeciesName(pokedexApp, species, 6);
            PokedexApp_LoadEntryDetailsBg(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, pokedexApp->language, pokedexApp->gfxNarc, HEAP_ID_POKEDEX_APP);
            PokedexApp_DrawListEntryDetails(pokedexApp, species, cursorIndex);
            PokedexApp_UpdateCurrentLanguageIcon(pokedexApp, species, 8);
            PokedexApp_UpdateLanguageIcons(pokedexApp, species, 18);
            PokedexApp_UpdateTypeIcons(pokedexApp, species, cursorIndex, 14);
            PokedexApp_UpdateFootprintSprite(pokedexApp, species, cursorIndex, 13);
            PokedexApp_UpdateCaughtMarkSprite(pokedexApp, cursorIndex, 9);
            PlaySE(SEQ_SE_GS_ZKN03);
            return;
        }
    }
}

void PokedexApp_UpdateListEntry(PokedexAppData *pokedexApp) {
    u32 cursorIndex = PokedexApp_GetListCursorIndex(pokedexApp);
    u16 species = PokedexApp_GetCursorSpecies(pokedexApp);

    if (species == 0) {
        PokedexApp_SetIntlSpritePairVisible(pokedexApp, 6, 0);
        PokedexApp_SetIntlSpriteVisible(pokedexApp, 8, 0);
    } else {
        if (PokedexApp_HasForeignEntries(pokedexApp, species) == TRUE) {
            PokedexApp_SetIntlSpritePairVisible(pokedexApp, 6, 1);
        } else {
            PokedexApp_SetIntlSpritePairVisible(pokedexApp, 6, 0);
        }
        PokedexApp_SetIntlSpriteVisible(pokedexApp, 8, 1);
    }
    if (!PokedexApp_HasCaughtInLanguage(pokedexApp, species, pokedexApp->language)) {
        pokedexApp->language = GAME_LANGUAGE;
    }
    PokedexApp_DrawCenteredSpeciesName(pokedexApp, species, 6);
    PokedexApp_DrawListEntryHeader(pokedexApp, species, cursorIndex);
    PokedexApp_DrawListEntryDetails(pokedexApp, species, cursorIndex);
    PokedexApp_ShowMonPic(pokedexApp, species, 11, 10);
    PokedexApp_UpdateCurrentLanguageIcon(pokedexApp, species, 8);
    PokedexApp_UpdateLanguageIcons(pokedexApp, species, 18);
    PokedexApp_UpdateTypeIcons(pokedexApp, species, cursorIndex, 14);
    PokedexApp_UpdateFootprintSprite(pokedexApp, species, cursorIndex, 13);
    PokedexApp_UpdateCaughtMarkSprite(pokedexApp, cursorIndex, 9);
    if (cursorIndex >= PokedexApp_GetListLength(pokedexApp, TRUE)) {
        PokedexApp_LoadEmptyEntryDetailsBg(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, pokedexApp->gfxNarc, HEAP_ID_POKEDEX_APP);
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[7]);
        PokedexApp_SetSpriteVisible(pokedexApp, 10, 0);
    } else {
        PokedexApp_LoadEntryDetailsBg(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, pokedexApp->language, pokedexApp->gfxNarc, HEAP_ID_POKEDEX_APP);
        ScheduleWindowCopyToVram(&pokedexApp->windows[7]);
    }
}

void PokedexApp_LoadEntryDetailsBg(BgConfig *bgConfig, u8 bgId, u8 language, NARC *narc, enum HeapID heapId) {
    NNSG2dScreenData *scrnData;

    void *scrnDataRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, language == GAME_LANGUAGE ? NARC_zukan_gra_zukan_gra_00000020_NSCR_lz : NARC_zukan_gra_zukan_gra_00000021_NSCR_lz, TRUE, &scrnData, heapId);
    LoadRectToBgTilemapRect(bgConfig, bgId, scrnData->rawData, 0, 0, 32, 24);
    ScheduleBgTilemapBufferTransfer(bgConfig, bgId);
    Heap_Free(scrnDataRaw);
}

void PokedexApp_LoadEmptyEntryDetailsBg(BgConfig *bgConfig, u8 bgId, NARC *narc, enum HeapID heapId) {
    NNSG2dScreenData *screenData;

    void *scrnDataRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, NARC_zukan_gra_zukan_gra_00000022_NSCR_lz, TRUE, &screenData, heapId);
    LoadRectToBgTilemapRect(bgConfig, bgId, screenData->rawData, 0, 0, 32, 24);
    ScheduleBgTilemapBufferTransfer(bgConfig, bgId);
    Heap_Free(scrnDataRaw);
}

void PokedexApp_ResetSearchCriteria(PokedexAppData *pokedexApp) {
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_SORT_ORDER] = DEX_ORDER_NATIONAL;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_LETTER] = DEX_SEARCH_LETTERS_ALL;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE1] = DEX_SEARCH_TYPE_ALL;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE2] = DEX_SEARCH_TYPE_ALL;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MIN] = 0;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MAX] = 152;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MIN] = 0;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MAX] = 152;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_AREA] = DEX_SEARCH_AREA_ALL;
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE] = DEX_SEARCH_BODYTYPE_ALL;
}

static void PokedexApp_LoadSearchGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_3);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);

    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000003_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000058_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000057_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000002_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_MAIN_BG, 0, 0);

    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000058_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000058_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000059_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000060_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_BG, 0, 0);

    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

void PokedexApp_SetupSearchPage(PokedexAppData *pokedexApp, int searchPage, int initialPos) {
    switch (searchPage) {
    case 0:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000057_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_CreateSearchMenuGrid(pokedexApp, initialPos);
        PokedexApp_DrawSearchMessage(pokedexApp, 0);
        PokedexApp_DrawSearchMenuPage(pokedexApp);
        PokedexApp_DrawSearchCriteria(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 0);
        break;
    case 1:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000062_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_HighlightSearchOption(pokedexApp, &sSearchOrderOptionRects[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_SORT_ORDER]], TRUE);
        PokedexApp_CreateSearchOrderGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 2);
        PokedexApp_DrawSearchOrderPage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 4);
        break;
    case 2:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000063_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_HighlightLetterOption(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_LETTER], 1);
        PokedexApp_CreateSearchNameGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 3);
        PokedexApp_DrawSearchNamePage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 4);
        break;
    case 3:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000064_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_HighlightSearchTypes(pokedexApp);
        PokedexApp_CreateSearchTypeGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 4);
        PokedexApp_DrawSearchTypePage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 4);
        break;
    case 4:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000065_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_CreateSearchHeightGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 5);
        PokedexApp_DrawSearchHeightPage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 2);
        break;
    case 5:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000066_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_CreateSearchWeightGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 6);
        PokedexApp_DrawSearchWeightPage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 3);
        break;
    case 6:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000067_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_HighlightSearchOption(pokedexApp, &sSearchAreaOptionRects[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_AREA]], TRUE);
        PokedexApp_CreateSearchAreaGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 7);
        PokedexApp_DrawSearchAreaPage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 4);
        PokedexApp_DisableSearchAreaOption1(pokedexApp);
        break;
    case 7:
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000068_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
        PokedexApp_HighlightBodyTypeOption(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE], TRUE);
        PokedexApp_CreateSearchFormGrid(pokedexApp);
        PokedexApp_DrawSearchMessage(pokedexApp, 8);
        PokedexApp_DrawSearchFormPage(pokedexApp);
        PokedexApp_UpdateSearchSprites(pokedexApp, 1);
        break;
    }
}

static void PokedexApp_HighlightSearchOption(PokedexAppData *pokedexApp, const PokedexBgRect *rect, BOOL highlight) {
    if (highlight == TRUE) {
        BgTilemapRectChangePalette(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, rect->x, rect->y, rect->width, rect->height, 3);
    } else {
        BgTilemapRectChangePalette(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2, rect->x, rect->y, rect->width, rect->height, 2);
    }
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
}

static void PokedexApp_MoveSearchOptionHighlight(PokedexAppData *pokedexApp, const PokedexBgRect *rects, u32 *selection, int newIndex) {
    PokedexApp_HighlightSearchOption(pokedexApp, &rects[*selection], FALSE);
    *selection = newIndex;
    PokedexApp_HighlightSearchOption(pokedexApp, &rects[newIndex], TRUE);
}

void PokedexApp_SelectSearchOrder(PokedexAppData *pokedexApp, int index) {
    PokedexApp_MoveSearchOptionHighlight(pokedexApp, sSearchOrderOptionRects, pokedexApp->dexSearchCriteria, index);
    PokedexApp_DrawSearchOrderValue(pokedexApp, 37);
    ScheduleWindowCopyToVram(&pokedexApp->windows[37]);
}

void PokedexApp_HighlightSearchTypes(PokedexAppData *pokedexApp) {
    for (int i = 0; i < NELEMS(sSearchTypeOptionRects); ++i) {
        PokedexApp_HighlightSearchOption(pokedexApp, &sSearchTypeOptionRects[i], FALSE);
    }
    PokedexApp_HighlightSearchOption(pokedexApp, &sSearchTypeOptionRects[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE1]], TRUE);
    PokedexApp_HighlightSearchOption(pokedexApp, &sSearchTypeOptionRects[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE2]], TRUE);
}

void PokedexApp_SelectSearchArea(PokedexAppData *pokedexApp, int index) {
    PokedexApp_MoveSearchOptionHighlight(pokedexApp, sSearchAreaOptionRects, &pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_AREA], index);
    PokedexApp_DrawSearchAreaValue(pokedexApp, 75);
    ScheduleWindowCopyToVram(&pokedexApp->windows[75]);
}

static void PokedexApp_DisableSearchAreaOption1(PokedexAppData *pokedexApp) {
    if (pokedexApp->nationalDex == 1) {
        return;
    }
    GridInputHandler_ClearEnabledFlag(pokedexApp->gridInput, 1);

    const PokedexBgRect *rect = &sSearchAreaOptionRects[1];
    u16 *tilemap = GetBgTilemapBuffer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    MI_CpuCopy16(
        &tilemap[32 * (rect->y - 2) + (rect->x - 1)],
        &tilemap[32 * (rect->y - 1) + (rect->x - 1)],
        sizeof(u16) * (rect->width + 2));
    MI_CpuCopy16(
        &tilemap[32 * (rect->y - 2) + (rect->x - 1)],
        &tilemap[32 * (rect->y) + (rect->x - 1)],
        sizeof(u16) * (rect->width + 2));
    MI_CpuCopy16(
        &tilemap[32 * (rect->y - 2) + (rect->x - 1)],
        &tilemap[32 * (rect->y + 1) + (rect->x - 1)],
        sizeof(u16) * (rect->width + 2));
    MI_CpuCopy16(
        &tilemap[32 * (rect->y - 3) + (rect->x - 1)],
        &tilemap[32 * (rect->y + 2) + (rect->x - 1)],
        sizeof(u16) * (rect->width + 2));
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
}

static void PokedexApp_HighlightBodyTypeOption(PokedexAppData *pokedexApp, u32 index, BOOL highlight) {
    PokedexBgRect rect;

    rect.width = 4;
    rect.height = 4;
    rect.x = 6 * (index % 5) + 2;
    rect.y = 5 * (index / 5 + 1);

    PokedexApp_HighlightSearchOption(pokedexApp, &rect, highlight);
}

void PokedexApp_SelectSearchBodyType(PokedexAppData *pokedexApp, u32 bodyType) {
    PokedexApp_HighlightBodyTypeOption(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE], FALSE);
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE] = bodyType;
    PokedexApp_HighlightBodyTypeOption(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_BODY_TYPE], TRUE);
    PokedexApp_UpdateBodyTypeSprite(pokedexApp);
}

u8 PokedexApp_GetLetterGridCell(int index) {
    return sLetterGridCells[index];
}

static void PokedexApp_HighlightLetterOption(PokedexAppData *pokedexApp, u32 index, BOOL highlight) {
    PokedexBgRect rect;

    rect.width = 2;
    rect.height = 2;
    rect.x = 4 * (sLetterGridCells[index] % 7) + 3;
    rect.y = 4 * (sLetterGridCells[index] / 7) + 5;

    PokedexApp_HighlightSearchOption(pokedexApp, &rect, highlight);
}

void PokedexApp_SelectSearchLetter(PokedexAppData *pokedexApp, u32 letter) {
    PokedexApp_HighlightLetterOption(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_LETTER], FALSE);
    pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_LETTER] = letter;
    PokedexApp_HighlightLetterOption(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_LETTER], TRUE);
    PokedexApp_DrawSearchNameValue(pokedexApp, 66);
    ScheduleWindowCopyToVram(&pokedexApp->windows[66]);
}

void PokedexApp_BuildListReturnCells(PokedexAppData *pokedexApp) {
    NNSG2dScreenData *scrnData;
    void *scrnDataRaw;
    u16 *screenCell;
    u16 *cell;
    u16 *tiles;
    u16 cellWidth;
    u16 cellHeight;
    u32 i;
    u32 j;

    screenCell = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 15);
    cell = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 14);

    scrnDataRaw = GfGfxLoader_GetScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000000_NSCR_lz, TRUE, &scrnData, HEAP_ID_POKEDEX_APP);
    tiles = (u16 *)scrnData->rawData;
    for (i = 0; i < 24; ++i) {
        memcpy(&screenCell[32 * i], &tiles[32 * i], 32 * sizeof(u16));
        memcpy(&cell[3 * i], &tiles[32 * i + 0x400], 3 * sizeof(u16));
    }
    Heap_Free(scrnDataRaw);

    if (pokedexApp->nationalDex == 0) {
        for (i = 0; i < 2; ++i) {
            for (j = 0; j < 26; ++j) {
                tiles = &screenCell[(i + 15) * 32 + 3 + j];
                *tiles = (*tiles & 0xF000) | 0x16;
            }
        }
    }

    if (pokedexApp->dexMode == 0) {
        cell = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 2);
        BgCellManager_GetCellSize(pokedexApp->bgCellManager, 2, &cellWidth, &cellHeight);
        for (i = 0; i < cellHeight; ++i) {
            for (j = 0; j < cellWidth; ++j) {
                screenCell[32 * (i + 3) + j + 5] = cell[i * cellWidth + j];
            }
        }
    } else {
        cell = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 3);
        BgCellManager_GetCellSize(pokedexApp->bgCellManager, 2, &cellWidth, &cellHeight); // typo? should be 3 not 2
        for (i = 0; i < cellHeight; ++i) {
            for (j = 0; j < cellWidth; ++j) {
                screenCell[32 * (i + 3) + j + 5] = cell[i * cellWidth + j];
            }
        }
    }

    PokedexApp_DrawSearchResultCounts(pokedexApp);
}

void PokedexApp_UpdateSearchResultEntry(PokedexAppData *pokedexApp) {
    int cursorIndex = PokedexApp_GetListCursorIndex(pokedexApp);
    if (cursorIndex == 0) {
        PokedexApp_SetIntlSpritePairVisible(pokedexApp, 22, 0);
        PokedexApp_SetIntlSpriteVisible(pokedexApp, 24, 0);
        PokedexApp_SetSearchEntrySpritesVisible(pokedexApp, 0);
        PokedexApp_DrawCenteredSpeciesName(pokedexApp, SPECIES_NONE, 94);
        PokedexApp_ClearSearchEntryWindows(pokedexApp);
        PokedexApp_SetSearchSummaryVisible(pokedexApp, 1);
        ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
        pokedexApp->subBgPriorityRequest = 1;
    } else {
        PokedexApp_SetSearchSummaryVisible(pokedexApp, 0);
        u16 species = PokedexApp_GetCursorSpecies(pokedexApp);
        if (!PokedexApp_HasCaughtInLanguage(pokedexApp, species, pokedexApp->language)) {
            pokedexApp->language = GAME_LANGUAGE;
        }
        PokedexApp_DrawCenteredSpeciesName(pokedexApp, species, 94);
        PokedexApp_DrawSearchEntryHeader(pokedexApp, species, cursorIndex);
        PokedexApp_DrawSearchEntryDetails(pokedexApp, species, cursorIndex);
        ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
        ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
        pokedexApp->subBgPriorityRequest = 2;
        PokedexApp_SetSearchEntrySpritesVisible(pokedexApp, 1);
        PokedexApp_ShowMonPic(pokedexApp, species, 46, 45);
        PokedexApp_UpdateCurrentLanguageIcon(pokedexApp, species, 24);
        PokedexApp_UpdateLanguageIcons(pokedexApp, species, 53);
        PokedexApp_UpdateTypeIcons(pokedexApp, species, cursorIndex, 49);
        PokedexApp_UpdateFootprintSprite(pokedexApp, species, cursorIndex, 48);
        PokedexApp_UpdateCaughtMarkSprite(pokedexApp, cursorIndex, 44);
        if (species == SPECIES_NONE) {
            PokedexApp_SetIntlSpritePairVisible(pokedexApp, 22, 0);
            PokedexApp_SetIntlSpriteVisible(pokedexApp, 24, 0);
            PokedexApp_LoadEmptyEntryDetailsBg(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, pokedexApp->gfxNarc, HEAP_ID_POKEDEX_APP);
            ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[81]);

            PokedexApp_SetSpriteVisible(pokedexApp, 45, 0);
        } else {
            if (PokedexApp_HasForeignEntries(pokedexApp, species) == TRUE) {
                PokedexApp_SetIntlSpritePairVisible(pokedexApp, 22, 1);
            } else {
                PokedexApp_SetIntlSpritePairVisible(pokedexApp, 22, 0);
            }
            PokedexApp_SetIntlSpriteVisible(pokedexApp, 24, 1);
            PokedexApp_LoadEntryDetailsBg(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, pokedexApp->language, pokedexApp->gfxNarc, HEAP_ID_POKEDEX_APP);
            ScheduleWindowCopyToVram(&pokedexApp->windows[81]);
        }
    }
}

static void PokedexApp_ApplyPendingSubBgPriority(PokedexAppData *pokedexApp) {
    switch (pokedexApp->subBgPriorityRequest) {
    case 0:
        return;
    case 1:
        SetBgPriority(GF_BG_LYR_SUB_2, 2);
        SetBgPriority(GF_BG_LYR_SUB_3, 3);
        break;
    case 2:
        SetBgPriority(GF_BG_LYR_SUB_2, 3);
        SetBgPriority(GF_BG_LYR_SUB_3, 2);
        break;
    }
    pokedexApp->subBgPriorityRequest = 0;
}

void PokedexApp_CycleSearchEntryLanguage(PokedexAppData *pokedexApp, u16 species, s16 delta) {
    if (!Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex)) {
        return;
    }

    int cursorIndex = PokedexApp_GetListCursorIndex(pokedexApp);
    if (cursorIndex == 0) {
        return;
    }

    s16 dexLangFlag = LanguageToDexFlag(pokedexApp->language);
    for (int i = 0; i < 6u; ++i) {
        dexLangFlag += delta;
        if (dexLangFlag < 0) {
            dexLangFlag = 5;
        } else if (dexLangFlag >= 6) {
            dexLangFlag = 0;
        }
        s16 language = DexFlagToLanguage(dexLangFlag);
        if (language == pokedexApp->language) {
            break;
        }
        if (PokedexApp_HasCaughtInLanguage(pokedexApp, species, language) == TRUE || language == GAME_LANGUAGE) {
            pokedexApp->language = language;
            PokedexApp_DrawCenteredSpeciesName(pokedexApp, species, 94);
            PokedexApp_LoadEntryDetailsBg(pokedexApp->bgConfig, GF_BG_LYR_SUB_3, pokedexApp->language, pokedexApp->gfxNarc, HEAP_ID_POKEDEX_APP);
            PokedexApp_DrawSearchEntryDetails(pokedexApp, species, cursorIndex);
            PokedexApp_UpdateCurrentLanguageIcon(pokedexApp, species, 24);
            PokedexApp_UpdateLanguageIcons(pokedexApp, species, 53);
            PokedexApp_UpdateTypeIcons(pokedexApp, species, cursorIndex, 49);
            PokedexApp_UpdateFootprintSprite(pokedexApp, species, cursorIndex, 48);
            PokedexApp_UpdateCaughtMarkSprite(pokedexApp, cursorIndex, 44);
            PlaySE(SEQ_SE_GS_ZKN03);
            break;
        }
    }
}

void PokedexApp_SetSubScreenClipWindow(BOOL enable) {
    if (enable == TRUE) {
        GXS_SetVisibleWnd(GX_WNDMASK_W0);
        G2S_SetWnd0InsidePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3, TRUE);
        G2S_SetWndOutsidePlane(GX_PLANEMASK_ALL, TRUE);
        G2S_SetWnd0Position(0, 0x98, 0xFF, 0xC0);
    } else {
        GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    }
}

static void PokedexApp_LoadAreaGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_2);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000082_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    if (pokedexApp->nationalDex == 1) {
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000081_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    } else {
        GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000080_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000083_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000083_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000002_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_MAIN_BG, 0, 0);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000084_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000085_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000086_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000087_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_BG, 0, 0);

    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

static void PokedexApp_LoadSizeCheckGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_3);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000089_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000090_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000002_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_MAIN_BG, 0, 0);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000091_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000092_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_BG, 0, 0);

    BgCellManager_DrawCellAt(pokedexApp->bgCellManager, 16, 0, 20);

    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

static void PokedexApp_LoadEntryMenuGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_3);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000101_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000102_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000002_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_MAIN_BG, 0, 0);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000103_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000104_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_BG, 0, 0);

    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

void PokedexApp_LoadFormsGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_1);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_SUB_2);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000096_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000093_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000095_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000093_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000002_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_MAIN_BG, 0, 0);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000097_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000094_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    PaletteData_LoadOpenNarc(pokedexApp->paletteData, pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, HEAP_ID_POKEDEX_APP, PLTTBUF_SUB_BG, 0, 0);

    if (pokedexApp->numSeenForms == 1) {
        void *scrnDataRaw;
        NNSG2dScreenData *scrnData;

        scrnDataRaw = GfGfxLoader_GetScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000100_NSCR_lz, TRUE, &scrnData, HEAP_ID_POKEDEX_APP);
        LoadRectToBgTilemapRect(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0, scrnData->rawData, 16, 16, 16, 4);
        Heap_Free(scrnDataRaw);
    }

    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_1);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

void PokedexApp_LoadFormCompareGraphics(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_2);

    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000098_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000093_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadScrnDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000099_NSCR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);
    GfGfxLoader_LoadCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000094_NCGR_lz, pokedexApp->bgConfig, GF_BG_LYR_SUB_3, 0, 0, TRUE, HEAP_ID_POKEDEX_APP);

    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_0);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_2);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_MAIN_3);
    ScheduleBgTilemapBufferTransfer(pokedexApp->bgConfig, GF_BG_LYR_SUB_3);
}

void PokedexApp_CollectSeenForms(PokedexAppData *pokedexApp) {
    memset(pokedexApp->seenForms, 0, sizeof(pokedexApp->seenForms));

    switch (pokedexApp->curSpecies) {
    case SPECIES_UNOWN:
    case SPECIES_PICHU:
    case SPECIES_DEOXYS:
    case SPECIES_BURMY:
    case SPECIES_WORMADAM:
    case SPECIES_SHELLOS:
    case SPECIES_GASTRODON:
    case SPECIES_ROTOM:
    case SPECIES_GIRATINA:
    case SPECIES_SHAYMIN:
        pokedexApp->numSeenForms = Pokedex_GetSeenFormNum(pokedexApp->args->pokedex, pokedexApp->curSpecies);
        for (u32 i = 0; i < pokedexApp->numSeenForms; ++i) {
            pokedexApp->seenForms[i] = Pokedex_GetSeenFormByIdx(pokedexApp->args->pokedex, pokedexApp->curSpecies, i) | 0x80;
        }
        break;
    case SPECIES_CASTFORM:
        pokedexApp->numSeenForms = 4;
        for (u32 i = 0; i < pokedexApp->numSeenForms; ++i) {
            pokedexApp->seenForms[i] = i | 0x80;
        }
        break;
    case SPECIES_CHERRIM:
        pokedexApp->numSeenForms = 2;
        for (u32 i = 0; i < pokedexApp->numSeenForms; ++i) {
            pokedexApp->seenForms[i] = i | 0x80;
        }
        break;
    default:
        pokedexApp->seenForms[0] = PokedexApp_GetSeenGenderForm(pokedexApp, 0);
        pokedexApp->seenForms[1] = PokedexApp_GetSeenGenderForm(pokedexApp, 1);
        if (pokedexApp->seenForms[1] == 0) {
            pokedexApp->numSeenForms = 1;
        } else {
            pokedexApp->numSeenForms = 2;
        }
        break;
    }
}

static u8 PokedexApp_GetSeenGenderForm(PokedexAppData *pokedexApp, u8 idx) {
    switch (Pokedex_SpeciesGetLastSeenGender(pokedexApp->args->pokedex, pokedexApp->curSpecies, idx)) {
    case MON_MALE:
        return 1;
    case MON_FEMALE:
        return 2;
    case MON_GENDERLESS:
        return 3;
    default:
        if (idx == 0) {
            return 3;
        } else {
            return 0;
        }
    }
}

void PokedexApp_LoadSizeData(PokedexAppData *pokedexApp) {
    NARC *narc; // forward decl fixes regswap
    PokedexSizeCheckData *sizeData = &pokedexApp->sizeCheckData;
    narc = NARC_New(GetPokedexDataNarcID(), HEAP_ID_POKEDEX_APP);
    if (PlayerProfile_GetTrainerGender(pokedexApp->args->playerProfile) == TRAINER_MALE) {
        sizeData->player_ypos = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_player_ypos_m, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
        sizeData->player_scale = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_player_scale_m, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
        sizeData->mon_ypos = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_mon_ypos_m, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
        sizeData->mon_scale = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_mon_scale_m, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
    } else {
        sizeData->player_ypos = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_player_ypos_f, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
        sizeData->player_scale = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_player_scale_f, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
        sizeData->mon_ypos = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_mon_ypos_f, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
        sizeData->mon_scale = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_mon_scale_f, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
    }
    pokedexApp->heights = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_height, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
    pokedexApp->weights = GfGfxLoader_LoadFromOpenNarc(narc, NARC_zukan_data_mon_stats_weight, FALSE, HEAP_ID_POKEDEX_APP, FALSE);
    NARC_Delete(narc);
}

void PokedexApp_FreeSizeData(PokedexAppData *pokedexApp) {
    PokedexSizeCheckData *sizeData = &pokedexApp->sizeCheckData;

    Heap_Free(pokedexApp->heights);
    Heap_Free(pokedexApp->weights);
    Heap_Free(sizeData->player_ypos);
    Heap_Free(sizeData->player_scale);
    Heap_Free(sizeData->mon_ypos);
    Heap_Free(sizeData->mon_scale);
}

void PokedexApp_BuildAreaList(PokedexAppData *pokedexApp, int timeOfDay, int region) {
    PokedexApp_LoadEncounterMaps(&pokedexApp->areaList.overworldByTime, pokedexApp->curSpecies, timeOfDay + 4);
    PokedexApp_LoadEncounterMaps(&pokedexApp->areaList.overworldOther, pokedexApp->curSpecies, 7);
    PokedexApp_LoadEncounterMaps(&pokedexApp->areaList.dungeonByTime, pokedexApp->curSpecies, timeOfDay);
    PokedexApp_LoadEncounterMaps(&pokedexApp->areaList.dungeonOther, pokedexApp->curSpecies, 3);

    u32 nMaps = 1;
    nMaps += pokedexApp->areaList.overworldByTime.nMaps - 1;
    nMaps += pokedexApp->areaList.overworldOther.nMaps - 1;
    nMaps += pokedexApp->areaList.dungeonByTime.nMaps - 1;
    nMaps += pokedexApp->areaList.dungeonOther.nMaps - 1;

    pokedexApp->areaList.areas.maps = Heap_Alloc(HEAP_ID_POKEDEX_APP, sizeof(u32) * nMaps);
    pokedexApp->areaList.areaSources = Heap_Alloc(HEAP_ID_POKEDEX_APP, sizeof(u32) * nMaps);
    MI_CpuClear32(pokedexApp->areaList.areas.maps, sizeof(u32) * nMaps);
    MI_CpuClear32(pokedexApp->areaList.areaSources, sizeof(u32) * nMaps);
    pokedexApp->areaList.areas.maps[0] = -2;
    pokedexApp->areaList.areas.nMaps = 1;
    pokedexApp->areaList.areaSources[0] = 0;

    PokedexApp_AddOverworldAreas(pokedexApp, &pokedexApp->areaList.overworldByTime, region, 0);
    PokedexApp_AddOverworldAreas(pokedexApp, &pokedexApp->areaList.overworldOther, region, 1);
    u32 nOverworldAreas = pokedexApp->areaList.areas.nMaps;
    PokedexApp_AddDungeonAreas(pokedexApp, &pokedexApp->areaList.dungeonByTime, region, nOverworldAreas, 0);
    PokedexApp_AddDungeonAreas(pokedexApp, &pokedexApp->areaList.dungeonOther, region, nOverworldAreas, 1);
    PokedexApp_SortAreaList(pokedexApp);
}

void PokedexApp_FreeAreaList(PokedexAppData *pokedexApp) {
    Heap_Free(pokedexApp->areaList.overworldByTime.maps);
    Heap_Free(pokedexApp->areaList.overworldOther.maps);
    Heap_Free(pokedexApp->areaList.dungeonByTime.maps);
    Heap_Free(pokedexApp->areaList.dungeonOther.maps);
    Heap_Free(pokedexApp->areaList.areas.maps);
    Heap_Free(pokedexApp->areaList.areaSources);
}

static void PokedexApp_LoadEncounterMaps(PokedexMapList *mapList, u16 species, int table) {
    int base;
    u32 size;

    switch (table) {
    case 0:
        base = NARC_zukan_enc_zukan_enc_00000002; // 0 * 495 + 2
        break;
    case 1:
        base = NARC_zukan_enc_zukan_enc_00000497; // 1 * 495 + 2
        break;
    case 2:
        base = NARC_zukan_enc_zukan_enc_00000992; // 2 * 495 + 2
        break;
    case 3:
        base = NARC_zukan_enc_zukan_enc_00002972; // 6 * 495 + 2
        break;
    case 4:
        base = NARC_zukan_enc_zukan_enc_00001487; // 3 * 495 + 2
        break;
    case 5:
        base = NARC_zukan_enc_zukan_enc_00001982; // 4 * 495 + 2
        break;
    case 6:
        base = NARC_zukan_enc_zukan_enc_00002477; // 5 * 495 + 2
        break;
    case 7:
        base = NARC_zukan_enc_zukan_enc_00003467; // 7 * 495 + 2
        break;
    }
    // UB: if unexpected a2, r3 is uninitialized
    mapList->maps = GfGfxLoader_LoadFromNarc_GetSizeOut(NARC_application_zukanlist_zkn_data_zukan_enc, base + species, FALSE, HEAP_ID_POKEDEX_APP, FALSE, &size);
    mapList->nMaps = size / sizeof(u32);
}

static void PokedexApp_AddOverworldAreas(PokedexAppData *pokedexApp, PokedexMapList *mapList, int region, int sourceBit) {
    u16 i;
    u16 j;

    if (region == 0) {
        for (i = 0; i < mapList->nMaps - 1; ++i) {
            if (pokedexApp->overworldAreaTable[mapList->maps[i]].x >= 22) {
                continue;
            }
            for (j = 0; j < pokedexApp->areaList.areas.nMaps; ++j) {
                if (pokedexApp->areaList.areas.maps[j] == mapList->maps[i]) {
                    pokedexApp->areaList.areaSources[j] |= 1 << sourceBit;
                    break;
                }
            }
            if (j == pokedexApp->areaList.areas.nMaps) {
                pokedexApp->areaList.areas.maps[pokedexApp->areaList.areas.nMaps] = mapList->maps[i];
                pokedexApp->areaList.areaSources[pokedexApp->areaList.areas.nMaps] = 1 << sourceBit;
                ++pokedexApp->areaList.areas.nMaps;
            }
        }
    } else {
        u32 mapId;
        for (i = 0; i < mapList->nMaps - 1; ++i) {
            mapId = mapList->maps[i];
            if (pokedexApp->overworldAreaTable[mapList->maps[i]].x < 22) {
                continue;
            }
            if (PokedexApp_IsRoute2Area(mapId) == TRUE) {
                mapId = PokedexApp_GetRoute2AreaIndex();
            } else if (PokedexApp_IsRoute16Area(mapId) == TRUE) {
                mapId = PokedexApp_GetRoute16AreaIndex();
            }
            for (j = 0; j < pokedexApp->areaList.areas.nMaps; ++j) {
                if (pokedexApp->areaList.areas.maps[j] == mapId) {
                    pokedexApp->areaList.areaSources[j] |= 1 << sourceBit;
                    break;
                }
            }
            if (j == pokedexApp->areaList.areas.nMaps) {
                pokedexApp->areaList.areas.maps[pokedexApp->areaList.areas.nMaps] = mapId;
                pokedexApp->areaList.areaSources[pokedexApp->areaList.areas.nMaps] = 1 << sourceBit;
                ++pokedexApp->areaList.areas.nMaps;
            }
        }
    }
}

static void PokedexApp_AddDungeonAreas(PokedexAppData *pokedexApp, PokedexMapList *mapList, int region, int startIndex, int sourceBit) {
    u16 i;
    u16 j;

    if (region == 0) {
        for (i = 0; i < mapList->nMaps - 1; ++i) {
            if (pokedexApp->dungeonAreaTable[mapList->maps[i]].x >= 22) {
                continue;
            }
            for (j = startIndex; j < pokedexApp->areaList.areas.nMaps; ++j) {
                if (pokedexApp->areaList.areas.maps[j] == mapList->maps[i]) {
                    pokedexApp->areaList.areaSources[j] |= 1 << sourceBit;
                    break;
                }
            }
            if (j == pokedexApp->areaList.areas.nMaps) {
                pokedexApp->areaList.areas.maps[pokedexApp->areaList.areas.nMaps] = mapList->maps[i];
                pokedexApp->areaList.areaSources[pokedexApp->areaList.areas.nMaps] = 0x80000000 + (1 << sourceBit);
                ++pokedexApp->areaList.areas.nMaps;
            }
        }
    } else {
        for (i = 0; i < mapList->nMaps - 1; ++i) {
            if (pokedexApp->dungeonAreaTable[mapList->maps[i]].x < 22) {
                continue;
            }
            for (j = startIndex; j < pokedexApp->areaList.areas.nMaps; ++j) {
                if (pokedexApp->areaList.areas.maps[j] == mapList->maps[i]) {
                    pokedexApp->areaList.areaSources[j] |= 1 << sourceBit;
                    break;
                }
            }
            if (j == pokedexApp->areaList.areas.nMaps) {
                pokedexApp->areaList.areas.maps[pokedexApp->areaList.areas.nMaps] = mapList->maps[i];
                pokedexApp->areaList.areaSources[pokedexApp->areaList.areas.nMaps] = 0x80000000 + (1 << sourceBit);
                ++pokedexApp->areaList.areas.nMaps;
            }
        }
    }
}

static u32 PokedexApp_GetAlphabeticalMapIndex(u32 mapId) {
    for (u32 i = 0; i < NELEMS(sMapIDs_Alphabetical); ++i) {
        if (mapId == sMapIDs_Alphabetical[i]) {
            return i;
        }
    }

    GF_ASSERT(FALSE);
    return 0;
}

static void PokedexApp_SortAreaList(PokedexAppData *pokedexApp) {
    u32 mapId;
    u32 otherMapId;
    u16 i;
    u16 j;

    for (i = 1; i < pokedexApp->areaList.areas.nMaps - 1; ++i) {
        mapId = PokedexApp_GetAreaMapId(pokedexApp, i);
        for (j = i + 1; j < pokedexApp->areaList.areas.nMaps; ++j) {
            otherMapId = PokedexApp_GetAreaMapId(pokedexApp, j);
            if (PokedexApp_GetAlphabeticalMapIndex(mapId) > PokedexApp_GetAlphabeticalMapIndex(otherMapId)) {
                s32 swapMap;
                u32 swapSource;

                swapMap = pokedexApp->areaList.areas.maps[i];
                pokedexApp->areaList.areas.maps[i] = pokedexApp->areaList.areas.maps[j];
                pokedexApp->areaList.areas.maps[j] = swapMap;

                swapSource = pokedexApp->areaList.areaSources[i];
                pokedexApp->areaList.areaSources[i] = pokedexApp->areaList.areaSources[j];
                pokedexApp->areaList.areaSources[j] = swapSource;

                mapId = otherMapId;
            }
        }
    }
}

BOOL PokedexApp_IsDungeonArea(PokedexAppData *pokedexApp, u32 areaIndex) {
    if (pokedexApp->areaList.areaSources[areaIndex] & 0x80000000) {
        return TRUE;
    }
    return FALSE;
}

u32 PokedexApp_GetAreaEncounterFlag(PokedexAppData *pokedexApp, u32 areaIndex, u32 sourceBit) {
    return pokedexApp->areaList.areaSources[areaIndex] & (1 << sourceBit);
}

u32 PokedexApp_GetAreaMapId(PokedexAppData *pokedexApp, u32 areaIndex) {
    if (PokedexApp_IsDungeonArea(pokedexApp, areaIndex) == FALSE) { // explicit comparison required to match
        return PokedexApp_GetOverworldMapId(pokedexApp->areaList.areas.maps[areaIndex]);
    } else {
        return PokedexApp_GetDungeonMapId(pokedexApp->areaList.areas.maps[areaIndex]);
    }
}

u32 PokedexApp_GetOverworldMapId(u32 idx) {
    return sOverworldMapIDs[idx];
}

u32 PokedexApp_GetDungeonMapId(u32 index) {
    return sDungeonMapIDs[index];
}

BOOL PokedexApp_IsRoute2Area(u32 idx) {
    u32 mapId = PokedexApp_GetOverworldMapId(idx);
    return mapId == MAP_ROUTE_2 || mapId == MAP_ROUTE_2_EAST;
}

static u32 PokedexApp_GetRoute2AreaIndex(void) {
    for (u32 i = 0; i < NELEMS(sOverworldMapIDs); ++i) {
        if (sOverworldMapIDs[i] == MAP_ROUTE_2) {
            return i;
        }
    }
    return 1;
}

BOOL PokedexApp_IsRoute16Area(u32 idx) {
    u32 mapId = PokedexApp_GetOverworldMapId(idx);
    return mapId == MAP_ROUTE_16_EAST || mapId == MAP_ROUTE_16;
}

static u32 PokedexApp_GetRoute16AreaIndex(void) {
    for (u32 i = 0; i < NELEMS(sOverworldMapIDs); ++i) {
        if (sOverworldMapIDs[i] == MAP_ROUTE_16) {
            return i;
        }
    }
    return 1;
}

void PokedexApp_LoadAreaTables(PokedexAppData *pokedexApp) {
    u32 size;

    pokedexApp->overworldAreaTable = GfGfxLoader_LoadFromNarc_GetSizeOut(NARC_application_zukanlist_zkn_data_zukan_enc, NARC_zukan_enc_zukan_enc_00000001, FALSE, HEAP_ID_POKEDEX_APP, FALSE, &size);
    pokedexApp->dungeonAreaTable = GfGfxLoader_LoadFromNarc_GetSizeOut(NARC_application_zukanlist_zkn_data_zukan_enc, NARC_zukan_enc_zukan_enc_00000000, FALSE, HEAP_ID_POKEDEX_APP, FALSE, &size);
}

void PokedexApp_FreeAreaTables(PokedexAppData *pokedexApp) {
    Heap_Free(pokedexApp->overworldAreaTable);
    Heap_Free(pokedexApp->dungeonAreaTable);
}
