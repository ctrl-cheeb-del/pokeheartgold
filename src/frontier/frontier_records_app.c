#include "global.h"

#include "constants/sndseq.h"

#include "frontier/frontier_records.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0019.h"

#include "bg_window.h"
#include "dex_mon_measures.h"
#include "filesystem.h"
#include "font.h"
#include "frontier_data.h"
#include "frontier_data_access.h"
#include "frontier_save_access.h"
#include "frontier_stat_ids_legacy.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "grid_input_handler.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "overlay_86.h"
#include "overlay_manager.h"
#include "palette.h"
#include "palette_blink.h"
#include "player_avatar.h"
#include "player_data.h"
#include "pm_string.h"
#include "render_window.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite_system.h"
#include "system.h"
#include "touchscreen.h"

// Main loop states
#define RECORDS_STATE_FADE_IN  0
#define RECORDS_STATE_RUN      1
#define RECORDS_STATE_FADE_OUT 2

// Text alignment: x is the left edge, the right edge or the center of the text
#define RECORDS_ALIGN_LEFT   0
#define RECORDS_ALIGN_RIGHT  1
#define RECORDS_ALIGN_CENTER 2

// Page arrow tilemaps (FrontierRecordsApp.pageArrowTiles)
#define RECORDS_ARROW_LEFT     0
#define RECORDS_ARROW_RIGHT    1
#define RECORDS_ARROW_DISABLED 2

// Sub-states of FrontierRecordsApp_Run
#define RUN_STATE_START             0
#define RUN_STATE_RECORDS           1
#define RUN_STATE_SHOW_LETTERS      2
#define RUN_STATE_LETTERS           3
#define RUN_STATE_SHOW_SPECIES      4
#define RUN_STATE_SPECIES           5
#define RUN_STATE_FLIP_PAGE         6
#define RUN_STATE_SHOW_HALL_RECORDS 7
#define RUN_STATE_HALL_RECORDS      8
#define RUN_STATE_BUTTON_FLASH      9
#define RUN_STATE_EXIT              10

// Pages of the Battle Hall species picker
#define HALL_PAGE_RECORDS 0
#define HALL_PAGE_LETTERS 1
#define HALL_PAGE_SPECIES 2

#define NUM_LETTERS         26
#define SPECIES_PER_PAGE    8
#define LETTER_GRID_RETURN  26
#define SPECIES_GRID_RETURN 8

// Text colors (foreground, shadow, background packed as in MAKE_TEXT_COLOR)
#define COLOR_HEADER 0x0F0200
#define COLOR_TEXT   0x010200
#define COLOR_BUTTON 0x0F0100
#define COLOR_PROMPT 0x01020F

typedef struct FrontierRecordsSpeciesGroup {
    u16 *species;
    u32 count;
} FrontierRecordsSpeciesGroup;

// Palette flash of a pressed button: either a sprite or a rectangle of a background tilemap
typedef struct FrontierRecordsButtonFlash {
    u8 isBg : 1;
    u8 index : 7;
    u8 paletteOn : 4;
    u8 paletteOff : 4;
    u8 state;
    u8 timer;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} FrontierRecordsButtonFlash;

typedef struct FrontierRecordsApp {
    OverlayManager *manager;
    u8 state;
    u8 nextState;
    u8 mode;
    u8 facility;
    u16 species;
    u16 unk_00A;
    BgConfig *bgConfig;
    Window windows[32];
    MsgData *msgData;
    MessageFormat *msgFormat;
    String *string;
    PaletteData *paletteData;
    Options *options;
    SaveData *saveData;
    FrontierSave *frontierSave;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    ManagedSprite *sprites[2];
    Window returnButtonWindow;
    FrontierRecordsButtonFlash flash;
    GridInputHandler *gridInput;
    u16 letter;
    u16 speciesIndex;
    s8 page;
    s8 lastPage;
    u16 speciesWindowBank;
    FrontierRecordsSpeciesGroup groups[NUM_LETTERS];
    PaletteBlink *scrollArrows;
    u16 pageArrowTiles[3][16];
} FrontierRecordsApp;

u32 BattleFactory_GetBestStreakStat(u8 levelMode, u8 type);
u32 BattleFactory_GetBestTradeCountStat(u8 levelMode, u8 type);
u32 BattleCastle_GetBestStreakStat(u8 type);
u32 BattleCastle_GetBestStreakPointsStat(u8 type);
u8 AddTextPrinterParameterizedWithColor(Window *window, u32 fontId, String *string, u32 x, u32 y, u32 textSpeed, u32 color, void *callback);

static BOOL FrontierRecordsApp_FadeIn(FrontierRecordsApp *app);
static BOOL FrontierRecordsApp_Run(FrontierRecordsApp *app);
static BOOL FrontierRecordsApp_FadeOut(FrontierRecordsApp *app);
static void FrontierRecordsApp_VBlankCallback(void *cbArg);
static void FrontierRecordsApp_SetGraphicsBanks(FrontierRecordsApp *app);
static void FrontierRecordsApp_InitBgLayers(BgConfig *bgConfig);
static void FrontierRecordsApp_InitGraphics(FrontierRecordsApp *app);
static void FrontierRecordsApp_FreeBgLayers(BgConfig *bgConfig);
static void FrontierRecordsApp_SetMainState(FrontierRecordsApp *app, int *state, int nextState);
static u32 FrontierRecordsApp_GetWindowSet(u32 facility);
static void FrontierRecordsApp_LoadMainBgGraphics(FrontierRecordsApp *app, GFBgLayer layer);
static void FrontierRecordsApp_LoadSubBgGraphics(FrontierRecordsApp *app, GFBgLayer layer);
static void FrontierRecordsApp_BufferNumber(FrontierRecordsApp *app, u32 field, u32 value);
static void FrontierRecordsApp_PrintStringAligned(Window *window, String *string, u32 x, u32 y, u32 fontId, u32 color, u32 align);
static void FrontierRecordsApp_PrintMessage(FrontierRecordsApp *app, u32 windowId, u32 msgId, u32 x, u32 y, u32 fontId, u32 color, u32 align);
static void FrontierRecordsApp_PrintFormattedMessage(FrontierRecordsApp *app, u32 windowId, u32 msgId, u32 x, u32 y, u32 fontId, u32 color, u32 align);
static void FrontierRecordsApp_PrintRecords(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintFactoryLevel50Records(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintFactoryOpenLevelRecords(FrontierRecordsApp *app);
static u32 FrontierRecordsApp_GetFactoryStreakLabel(FrontierRecordsApp *app, u32 level);
static void FrontierRecordsApp_PrintHallRecords(FrontierRecordsApp *app);
static void FrontierRecordsApp_BufferSpeciesName(FrontierRecordsApp *app, int species);
static void FrontierRecordsApp_PrintCastleRecords(FrontierRecordsApp *app);
static u32 FrontierRecordsApp_GetCastleStreakLabel(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintArcadeRecords(FrontierRecordsApp *app);
static u32 FrontierRecordsApp_GetArcadeStreakLabel(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintTowerRecords(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintTowerMultiRecords(FrontierRecordsApp *app);
static u32 FrontierRecordsApp_GetTowerStreakLabel(FrontierRecordsApp *app, u32 mode);
static void FrontierRecordsApp_PrintReturnButton(FrontierRecordsApp *app);
static void FrontierRecordsApp_CreateSprites(FrontierRecordsApp *app);
static void FrontierRecordsApp_FreeSprites(FrontierRecordsApp *app);
static void FrontierRecordsApp_TickSprites(FrontierRecordsApp *app);
static void FrontierRecordsApp_SetSpriteAnim(FrontierRecordsApp *app, int index, int anim);
static void FrontierRecordsApp_SetSpritePosition(FrontierRecordsApp *app, int index, s16 x, s16 y);
static int FrontierRecordsApp_RunButtonFlash(FrontierRecordsApp *app);
static void FrontierRecordsApp_StartReturnButtonFlash(FrontierRecordsApp *app);
static BOOL FrontierRecordsApp_IsHall(FrontierRecordsApp *app);
static void FrontierRecordsApp_InitHallPicker(FrontierRecordsApp *app);
static void FrontierRecordsApp_FreeHallPicker(FrontierRecordsApp *app);
static void FrontierRecordsApp_ShowHallPage(FrontierRecordsApp *app, int page);
static void FrontierRecordsApp_DrawPageArrows(FrontierRecordsApp *app);
static void FrontierRecordsApp_FreeGridInput(FrontierRecordsApp *app);
static void FrontierRecordsApp_GridCallback_Nop(void *data, int input, int prevInput);
static u16 *FrontierRecordsApp_LoadSortedSpecies(int letter, u32 *count);
static void FrontierRecordsApp_InitSpeciesGroups(FrontierRecordsApp *app);
static void FrontierRecordsApp_FreeSpeciesGroups(FrontierRecordsApp *app);
static void FrontierRecordsApp_LoadWindowFrame(FrontierRecordsApp *app);
static void FrontierRecordsApp_ShowPrompt(FrontierRecordsApp *app);
static void FrontierRecordsApp_ClearPrompt(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintLetters(FrontierRecordsApp *app);
static void FrontierRecordsApp_MoveLetterCursor(FrontierRecordsApp *app, int selection);
static void FrontierRecordsApp_CreateLetterGrid(FrontierRecordsApp *app);
static void FrontierRecordsApp_LetterGrid_OnKeyMove(void *data, int input, int prevInput);
static void FrontierRecordsApp_LetterGrid_OnTouch(void *data, int input, int prevInput);
static void FrontierRecordsApp_StartLetterFlash(FrontierRecordsApp *app, u32 letter);
static u8 FrontierRecordsApp_HandleLetterInput(FrontierRecordsApp *app);
static void FrontierRecordsApp_GrayOutEmptyLetters(FrontierRecordsApp *app);
static void FrontierRecordsApp_MoveSpeciesCursor(FrontierRecordsApp *app, int selection);
static void FrontierRecordsApp_CreateSpeciesGrid(FrontierRecordsApp *app);
static void FrontierRecordsApp_SpeciesGrid_OnKeyMove(void *data, int input, int prevInput);
static void FrontierRecordsApp_SpeciesGrid_OnTouch(void *data, int input, int prevInput);
static void FrontierRecordsApp_StartSpeciesFlash(FrontierRecordsApp *app, int slot);
static void FrontierRecordsApp_StartArrowFlash(FrontierRecordsApp *app, u8 x, u8 y);
static int FrontierRecordsApp_HandleSpeciesInput(FrontierRecordsApp *app);
static int FrontierRecordsApp_FlipSpeciesPage(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintSpeciesPage(FrontierRecordsApp *app);
static void FrontierRecordsApp_ClearSpeciesWindows(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintLetterTitle(FrontierRecordsApp *app);
static void FrontierRecordsApp_PrintPageNumber(FrontierRecordsApp *app);
static void FrontierRecordsApp_ResetCursor(FrontierRecordsApp *app);
static void FrontierRecordsApp_SelectSpecies(FrontierRecordsApp *app);
static void FrontierRecordsApp_ClearRecordWindows(FrontierRecordsApp *app);

// Grid slot of each letter on the letter picker
static const u8 sFrontierRecordsLetterPositions[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

static const TouchscreenHitbox sFrontierRecordsExitHitbox = {
    .rect = { 164, 187, 193, 254 }
};

static const TouchscreenHitbox sFrontierRecordsSpeciesHitboxes[] = {
    { .rect = { 162, 189, 18, 45 } },
    { .rect = { 162, 189, 50, 77 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const GridCallbacks sFrontierRecordsLetterGridCallbacks = {
    .onButton = FrontierRecordsApp_GridCallback_Nop,
    .onSwitchToTouchMode = FrontierRecordsApp_GridCallback_Nop,
    .onKeyMove = FrontierRecordsApp_LetterGrid_OnKeyMove,
    .onTouch = FrontierRecordsApp_LetterGrid_OnTouch,
};

static const GridCallbacks sFrontierRecordsSpeciesGridCallbacks = {
    .onButton = FrontierRecordsApp_GridCallback_Nop,
    .onSwitchToTouchMode = FrontierRecordsApp_GridCallback_Nop,
    .onKeyMove = FrontierRecordsApp_SpeciesGrid_OnKeyMove,
    .onTouch = FrontierRecordsApp_SpeciesGrid_OnTouch,
};

static const GraphicsModes sFrontierRecordsAppGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const SpriteResourceCountsListUnion sFrontierRecordsAppSpriteResourceCounts = {
    .numChar = 1,
    .numPltt = 1,
    .numCell = 1,
    .numAnim = 1,
    .numMcel = 0,
    .numManm = 0,
};

static const BgTemplate sFrontierRecordsBgTemplate_MainText = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = FALSE,
};

static const OamCharTransferParam sFrontierRecordsAppOamCharTransferParam = {
    .maxTasks = 0x400,
    .sizeMain = 0x20000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_32K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_32K,
};

static const BgTemplate sFrontierRecordsBgTemplate_MainRecords = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_512x512_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_512x512,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xd800,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = FALSE,
};

static const BgTemplate sFrontierRecordsBgTemplate_SubText = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = FALSE,
};

static const BgTemplate sFrontierRecordsBgTemplate_SubBackground = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .dummy = 0,
    .mosaic = FALSE,
};

static const OamManagerParam sFrontierRecordsAppOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 128,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 0,
    .numOBJsub = 128,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const TouchscreenHitbox sFrontierRecordsSpeciesGridHitboxes[] = {
    { .rect = { 32, 63, 40, 127 } },
    { .rect = { 32, 63, 144, 231 } },
    { .rect = { 64, 95, 40, 127 } },
    { .rect = { 64, 95, 144, 231 } },
    { .rect = { 96, 127, 40, 127 } },
    { .rect = { 96, 127, 144, 231 } },
    { .rect = { 128, 159, 40, 127 } },
    { .rect = { 128, 159, 144, 231 } },
    { .rect = { 164, 187, 193, 254 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const GraphicsBanks sFrontierRecordsAppGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_128_B,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

static const DpadMenuBox sFrontierRecordsSpeciesGridBoxes[] = {
    { 84,  48,  0, 0, 0,   2, 0, 1 },
    { 188, 48,  0, 0, 1,   3, 0, 1 },
    { 84,  80,  0, 0, 0,   4, 2, 3 },
    { 188, 80,  0, 0, 1,   5, 2, 3 },
    { 84,  112, 0, 0, 2,   6, 4, 5 },
    { 188, 112, 0, 0, 3,   7, 4, 5 },
    { 84,  144, 0, 0, 4,   8, 6, 7 },
    { 188, 144, 0, 0, 5,   8, 6, 7 },
    { 224, 176, 0, 0, 135, 8, 8, 8 },
};

static const ManagedSpriteTemplate sFrontierRecordsSpriteTemplates[] = {
    { 224, 176, 0, 0, 10, 0, NNS_G2D_VRAM_TYPE_2DMAIN, { 0xD8CC, 0xD8CC, 0xD8CC, 0xD8CC, -1, -1 }, 1, 0 },
    { 224, 176, 0, 1, 0,  0, NNS_G2D_VRAM_TYPE_2DMAIN, { 0xD8CC, 0xD8CC, 0xD8CC, 0xD8CC, -1, -1 }, 0, 0 },
};

static const TouchscreenHitbox sFrontierRecordsLetterGridHitboxes[] = {
    { .rect = { 40, 55, 24, 39 } },
    { .rect = { 40, 55, 56, 71 } },
    { .rect = { 40, 55, 88, 103 } },
    { .rect = { 40, 55, 120, 135 } },
    { .rect = { 40, 55, 152, 167 } },
    { .rect = { 40, 55, 184, 199 } },
    { .rect = { 40, 55, 216, 231 } },
    { .rect = { 72, 87, 24, 39 } },
    { .rect = { 72, 87, 56, 71 } },
    { .rect = { 72, 87, 88, 103 } },
    { .rect = { 72, 87, 120, 135 } },
    { .rect = { 72, 87, 152, 167 } },
    { .rect = { 72, 87, 184, 199 } },
    { .rect = { 72, 87, 216, 231 } },
    { .rect = { 104, 119, 24, 39 } },
    { .rect = { 104, 119, 56, 71 } },
    { .rect = { 104, 119, 88, 103 } },
    { .rect = { 104, 119, 120, 135 } },
    { .rect = { 104, 119, 152, 167 } },
    { .rect = { 104, 119, 184, 199 } },
    { .rect = { 104, 119, 216, 231 } },
    { .rect = { 136, 151, 24, 39 } },
    { .rect = { 136, 151, 56, 71 } },
    { .rect = { 136, 151, 88, 103 } },
    { .rect = { 136, 151, 120, 135 } },
    { .rect = { 136, 151, 152, 167 } },
    { .rect = { 164, 187, 193, 254 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const DpadMenuBox sFrontierRecordsLetterGridBoxes[] = {
    { 32,  48,  0, 0, 0,   7,  0,  1  },
    { 64,  48,  0, 0, 1,   8,  0,  2  },
    { 96,  48,  0, 0, 2,   9,  1,  3  },
    { 128, 48,  0, 0, 3,   10, 2,  4  },
    { 160, 48,  0, 0, 4,   11, 3,  5  },
    { 192, 48,  0, 0, 5,   12, 4,  6  },
    { 224, 48,  0, 0, 6,   13, 5,  6  },
    { 32,  80,  0, 0, 0,   14, 7,  8  },
    { 64,  80,  0, 0, 1,   15, 7,  9  },
    { 96,  80,  0, 0, 2,   16, 8,  10 },
    { 128, 80,  0, 0, 3,   17, 9,  11 },
    { 160, 80,  0, 0, 4,   18, 10, 12 },
    { 192, 80,  0, 0, 5,   19, 11, 13 },
    { 224, 80,  0, 0, 6,   20, 12, 13 },
    { 32,  112, 0, 0, 7,   21, 14, 15 },
    { 64,  112, 0, 0, 8,   22, 14, 16 },
    { 96,  112, 0, 0, 9,   23, 15, 17 },
    { 128, 112, 0, 0, 10,  24, 16, 18 },
    { 160, 112, 0, 0, 11,  25, 17, 19 },
    { 192, 112, 0, 0, 12,  26, 18, 20 },
    { 224, 112, 0, 0, 13,  26, 19, 20 },
    { 32,  144, 0, 0, 14,  26, 21, 22 },
    { 64,  144, 0, 0, 15,  26, 21, 23 },
    { 96,  144, 0, 0, 16,  26, 22, 24 },
    { 128, 144, 0, 0, 17,  26, 23, 25 },
    { 160, 144, 0, 0, 18,  26, 24, 25 },
    { 224, 176, 0, 0, 132, 26, 26, 26 },
};

BOOL FrontierRecordsApp_Init(OverlayManager *man, int *state) {
    FrontierRecordsApp *app;
    FrontierRecordsAppArgs *args;

    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    Heap_Create(HEAP_ID_3, HEAP_ID_121, 0x30000);
    app = OverlayManager_CreateAndGetData(man, sizeof(FrontierRecordsApp), HEAP_ID_121);
    memset(app, 0, sizeof(FrontierRecordsApp));
    app->manager = man;
    app->bgConfig = BgConfig_Alloc(HEAP_ID_121);
    args = OverlayManager_GetArgs(man);
    app->saveData = args->saveData;
    app->frontierSave = Save_Frontier_GetStatic(app->saveData);
    app->mode = args->mode;
    app->facility = args->facility;
    app->species = args->species;
    app->options = Save_PlayerData_GetOptionsAddr(app->saveData);
    FontID_Alloc(4, HEAP_ID_121);
    FrontierRecordsApp_InitGraphics(app);
    app->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0019_bin, HEAP_ID_121);
    app->msgFormat = MessageFormat_New(HEAP_ID_121);
    app->string = String_New(800, HEAP_ID_121);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_121);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_12_OFFSET, HEAP_ID_121);
    FrontierRecordsApp_AddWindows(app->bgConfig, app->windows, FrontierRecordsApp_GetWindowSet(app->facility));
    FrontierRecordsApp_AddReturnButtonWindow(app->bgConfig, &app->returnButtonWindow);
    FrontierRecordsApp_PrintReturnButton(app);
    FrontierRecordsApp_CreateSprites(app);
    Main_SetVBlankIntrCB(FrontierRecordsApp_VBlankCallback, app);
    *state = RECORDS_STATE_FADE_IN;
    return TRUE;
}

BOOL FrontierRecordsApp_Main(OverlayManager *man, int *state) {
    FrontierRecordsApp *app = OverlayManager_GetData(man);

    switch (*state) {
    case RECORDS_STATE_FADE_IN:
        if (FrontierRecordsApp_FadeIn(app) == TRUE) {
            FrontierRecordsApp_SetMainState(app, state, RECORDS_STATE_RUN);
        }
        break;
    case RECORDS_STATE_RUN:
        if (FrontierRecordsApp_Run(app) == TRUE) {
            FrontierRecordsApp_SetMainState(app, state, RECORDS_STATE_FADE_OUT);
        }
        break;
    case RECORDS_STATE_FADE_OUT:
        if (FrontierRecordsApp_FadeOut(app) == TRUE) {
            return TRUE;
        }
        break;
    }
    FrontierRecordsApp_TickSprites(app);
    SpriteSystem_DrawSprites(app->spriteManager);
    return FALSE;
}

BOOL FrontierRecordsApp_Exit(OverlayManager *man, int *state) {
#pragma unused(state)
    FrontierRecordsApp *app = OverlayManager_GetData(man);

    FrontierRecordsApp_FreeSprites(app);
    PaletteData_FreeBuffers(app->paletteData, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffers(app->paletteData, PLTTBUF_MAIN_BG);
    PaletteData_Free(app->paletteData);
    app->paletteData = NULL;
    DestroyMsgData(app->msgData);
    MessageFormat_Delete(app->msgFormat);
    String_Delete(app->string);
    FrontierRecordsApp_RemoveReturnButtonWindow(&app->returnButtonWindow);
    FrontierRecordsApp_RemoveWindows(app->windows, FrontierRecordsApp_GetWindowSet(app->facility));
    FrontierRecordsApp_FreeBgLayers(app->bgConfig);
    FontID_Release(4);
    OverlayManager_FreeData(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(HEAP_ID_121);
    return TRUE;
}

enum {
    RECORDS_FADE_IN_PRINT,
    RECORDS_FADE_IN_START,
    RECORDS_FADE_IN_WAIT,
};

static BOOL FrontierRecordsApp_FadeIn(FrontierRecordsApp *app) {
    switch (app->state) {
    case RECORDS_FADE_IN_PRINT:
        if (FrontierRecordsApp_IsHall(app) == TRUE) {
            FrontierRecordsApp_InitHallPicker(app);
        } else {
            FrontierRecordsApp_PrintRecords(app);
        }
        app->state++;
        break;
    case RECORDS_FADE_IN_START:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 3, HEAP_ID_121);
        app->state++;
        break;
    case RECORDS_FADE_IN_WAIT:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static BOOL FrontierRecordsApp_Run(FrontierRecordsApp *app) {
    switch (app->state) {
    case RUN_STATE_START:
        if (FrontierRecordsApp_IsHall(app) == TRUE) {
            app->state = RUN_STATE_LETTERS;
        } else {
            app->state = RUN_STATE_RECORDS;
        }
        break;
    case RUN_STATE_RECORDS:
        if (TouchscreenHitbox_TouchNewIsIn(&sFrontierRecordsExitHitbox) == TRUE || (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
            PlaySE(SEQ_SE_DP_DECIDE);
            FrontierRecordsApp_StartReturnButtonFlash(app);
            app->nextState = RUN_STATE_EXIT;
            app->state = RUN_STATE_BUTTON_FLASH;
        }
        break;
    case RUN_STATE_SHOW_LETTERS:
        FrontierRecordsApp_ShowHallPage(app, HALL_PAGE_LETTERS);
        app->state = RUN_STATE_LETTERS;
        break;
    case RUN_STATE_LETTERS:
        app->state = FrontierRecordsApp_HandleLetterInput(app);
        break;
    case RUN_STATE_SHOW_SPECIES:
        FrontierRecordsApp_ShowHallPage(app, HALL_PAGE_SPECIES);
        app->state = RUN_STATE_SPECIES;
        break;
    case RUN_STATE_SPECIES:
        app->state = FrontierRecordsApp_HandleSpeciesInput(app);
        break;
    case RUN_STATE_FLIP_PAGE:
        app->state = FrontierRecordsApp_FlipSpeciesPage(app);
        break;
    case RUN_STATE_SHOW_HALL_RECORDS:
        FrontierRecordsApp_ShowHallPage(app, HALL_PAGE_RECORDS);
        app->state = RUN_STATE_HALL_RECORDS;
        break;
    case RUN_STATE_HALL_RECORDS:
        if (TouchscreenHitbox_TouchNewIsIn(&sFrontierRecordsExitHitbox) == TRUE || (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
            PlaySE(SEQ_SE_DP_DECIDE);
            FrontierRecordsApp_StartReturnButtonFlash(app);
            app->nextState = RUN_STATE_SHOW_SPECIES;
            app->state = RUN_STATE_BUTTON_FLASH;
        }
        break;
    case RUN_STATE_BUTTON_FLASH:
        if (FrontierRecordsApp_RunButtonFlash(app) == 0) {
            app->state = app->nextState;
        }
        break;
    case RUN_STATE_EXIT:
        return TRUE;
    }
    return FALSE;
}

enum {
    RECORDS_FADE_OUT_START,
    RECORDS_FADE_OUT_WAIT,
};

static BOOL FrontierRecordsApp_FadeOut(FrontierRecordsApp *app) {
    switch (app->state) {
    case RECORDS_FADE_OUT_START:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_121);
        app->state++;
        break;
    case RECORDS_FADE_OUT_WAIT:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void FrontierRecordsApp_VBlankCallback(void *cbArg) {
    FrontierRecordsApp *app = cbArg;

    if (app->paletteData != NULL) {
        PaletteData_PushTransparentBuffers(app->paletteData);
    }
    DoScheduledBgGpuUpdates(app->bgConfig);
    SpriteSystem_TransferOam();
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void FrontierRecordsApp_SetGraphicsBanks(FrontierRecordsApp *app) {
    GraphicsBanks banks = sFrontierRecordsAppGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void FrontierRecordsApp_InitBgLayers(BgConfig *bgConfig) {
    GraphicsModes modes = sFrontierRecordsAppGraphicsModes;
    BgTemplate mainText;
    BgTemplate mainRecords;
    BgTemplate subText;
    BgTemplate subBackground;

    SetBothScreensModesAndDisable(&modes);
    mainText = sFrontierRecordsBgTemplate_MainText;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &mainText, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_121);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    mainRecords = sFrontierRecordsBgTemplate_MainRecords;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &mainRecords, GF_BG_TYPE_TEXT);
    subText = sFrontierRecordsBgTemplate_SubText;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &subText, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_121);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    subBackground = sFrontierRecordsBgTemplate_SubBackground;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &subBackground, GF_BG_TYPE_TEXT);
}

static void FrontierRecordsApp_InitGraphics(FrontierRecordsApp *app) {
    FrontierRecordsApp_SetGraphicsBanks(app);
    FrontierRecordsApp_InitBgLayers(app->bgConfig);
    app->paletteData = PaletteData_Init(HEAP_ID_121);
    PaletteData_AllocBuffers(app->paletteData, PLTTBUF_MAIN_OBJ, 0x200, HEAP_ID_121);
    PaletteData_AllocBuffers(app->paletteData, PLTTBUF_MAIN_BG, 0x200, HEAP_ID_121);
    FrontierRecordsApp_LoadMainBgGraphics(app, GF_BG_LYR_MAIN_2);
    FrontierRecordsApp_LoadSubBgGraphics(app, GF_BG_LYR_SUB_2);
}

static void FrontierRecordsApp_FreeBgLayers(BgConfig *bgConfig) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_ALL, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_ALL, GF_PLANE_TOGGLE_OFF);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_2);
    Heap_Free(bgConfig);
}

static void FrontierRecordsApp_SetMainState(FrontierRecordsApp *app, int *state, int nextState) {
    app->state = 0;
    *state = nextState;
}

static u32 FrontierRecordsApp_GetWindowSet(u32 facility) {
    u32 set = 0;

    switch (facility) {
    case FRONTIER_FACILITY_FACTORY_LV50:
    case FRONTIER_FACILITY_FACTORY_OPEN:
        set = 0;
        break;
    case FRONTIER_FACILITY_HALL:
        set = 1;
        break;
    case FRONTIER_FACILITY_CASTLE:
        set = 2;
        break;
    case FRONTIER_FACILITY_ARCADE:
        set = 3;
        break;
    case FRONTIER_FACILITY_TOWER:
        set = 4;
        break;
    }
    return set;
}

static void FrontierRecordsApp_LoadMainBgGraphics(FrontierRecordsApp *app, GFBgLayer layer) {
    NNSG2dScreenData *screenData;
    NARC *narc = NARC_New(NARC_a_1_8_3, HEAP_ID_121);

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x8C, app->bgConfig, layer, 0, 0, TRUE, HEAP_ID_121);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0xC3, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x60, HEAP_ID_121);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x8B, app->bgConfig, layer, 0, 0, TRUE, HEAP_ID_121);
    void *arrowsFile = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 0x8F, TRUE, &screenData, HEAP_ID_121);
    MIi_CpuCopy16((const u16 *)screenData->rawData, (u16 *)app->pageArrowTiles, sizeof(app->pageArrowTiles));
    Heap_Free(arrowsFile);
    NARC_Delete(narc);
}

static void FrontierRecordsApp_LoadSubBgGraphics(FrontierRecordsApp *app, GFBgLayer layer) {
    NARC *narc = NARC_New(NARC_a_1_8_3, HEAP_ID_121);

    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x8E, app->bgConfig, layer, 0, 0, TRUE, HEAP_ID_121);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x8D, app->bgConfig, layer, 0, 0, TRUE, HEAP_ID_121);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0xC4, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x20, HEAP_ID_121);
    NARC_Delete(narc);
}

static void FrontierRecordsApp_BufferNumber(FrontierRecordsApp *app, u32 field, u32 value) {
    BufferIntegerAsString(app->msgFormat, field, value, 4, PRINTING_MODE_RIGHT_ALIGN, TRUE);
}

static void FrontierRecordsApp_PrintStringAligned(Window *window, String *string, u32 x, u32 y, u32 fontId, u32 color, u32 align) {
    if (align == RECORDS_ALIGN_RIGHT) {
        x -= FontID_String_GetWidth(fontId, string, 0);
    } else if (align == RECORDS_ALIGN_CENTER) {
        x -= FontID_String_GetWidth(fontId, string, 0) / 2;
    }
    AddTextPrinterParameterizedWithColor(window, fontId, string, x, y, 0xFF, color, NULL);
}

static void FrontierRecordsApp_PrintMessage(FrontierRecordsApp *app, u32 windowId, u32 msgId, u32 x, u32 y, u32 fontId, u32 color, u32 align) {
    String *string = NewString_ReadMsgData(app->msgData, msgId);
    FrontierRecordsApp_PrintStringAligned(&app->windows[windowId], string, x, y, fontId, color, align);
    String_Delete(string);
}

static void FrontierRecordsApp_PrintFormattedMessage(FrontierRecordsApp *app, u32 windowId, u32 msgId, u32 x, u32 y, u32 fontId, u32 color, u32 align) {
    String *string = NewString_ReadMsgData(app->msgData, msgId);
    StringExpandPlaceholders(app->msgFormat, app->string, string);
    FrontierRecordsApp_PrintStringAligned(&app->windows[windowId], app->string, x, y, fontId, color, align);
    String_Delete(string);
}

static void FrontierRecordsApp_PrintRecords(FrontierRecordsApp *app) {
    switch (app->facility) {
    case FRONTIER_FACILITY_FACTORY_LV50:
    case FRONTIER_FACILITY_FACTORY_OPEN:
        FrontierRecordsApp_PrintFactoryLevel50Records(app);
        FrontierRecordsApp_PrintFactoryOpenLevelRecords(app);
        break;
    case FRONTIER_FACILITY_HALL:
        FrontierRecordsApp_PrintHallRecords(app);
        break;
    case FRONTIER_FACILITY_CASTLE:
        FrontierRecordsApp_PrintCastleRecords(app);
        break;
    case FRONTIER_FACILITY_ARCADE:
        FrontierRecordsApp_PrintArcadeRecords(app);
        break;
    case FRONTIER_FACILITY_TOWER:
        if (app->mode <= TOWER_MODE_DOUBLE) {
            FrontierRecordsApp_PrintTowerRecords(app);
        } else {
            FrontierRecordsApp_PrintTowerMultiRecords(app);
        }
        break;
    default:
        FrontierRecordsApp_PrintArcadeRecords(app);
        break;
    }
}

static void FrontierRecordsApp_PrintFactoryLevel50Records(FrontierRecordsApp *app) {
    u32 msgOrValue;

    FillWindowPixelBuffer(&app->windows[0], 0);
    FillWindowPixelBuffer(&app->windows[1], 0);
    FillWindowPixelBuffer(&app->windows[2], 0);
    FillWindowPixelBuffer(&app->windows[3], 0);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00022, 0, 0, 0, COLOR_HEADER, RECORDS_ALIGN_LEFT);
    if (app->mode == FRONTIER_CHALLENGE_SINGLE) {
        msgOrValue = msg_0019_00026;
    } else if (app->mode == FRONTIER_CHALLENGE_DOUBLE) {
        msgOrValue = msg_0019_00027;
    } else {
        msgOrValue = msg_0019_00028;
    }
    FrontierRecordsApp_PrintMessage(app, 0, msgOrValue, 224, 0, 0, COLOR_HEADER, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 1, msg_0019_00046, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintMessage(app, 1, msg_0019_00048, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 2, FrontierRecordsApp_GetFactoryStreakLabel(app, 0), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    msgOrValue = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetWinStreakStat(0, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, msgOrValue);
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    msgOrValue = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetTradeCountStat(0, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, msgOrValue);
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00052, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 3, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    msgOrValue = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetBestStreakStat(0, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, msgOrValue);
    FrontierRecordsApp_PrintFormattedMessage(app, 3, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    msgOrValue = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetBestTradeCountStat(0, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, msgOrValue);
    FrontierRecordsApp_PrintFormattedMessage(app, 3, msg_0019_00052, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    ScheduleWindowCopyToVram(&app->windows[0]);
    ScheduleWindowCopyToVram(&app->windows[1]);
    ScheduleWindowCopyToVram(&app->windows[2]);
    ScheduleWindowCopyToVram(&app->windows[3]);
}

static void FrontierRecordsApp_PrintFactoryOpenLevelRecords(FrontierRecordsApp *app) {
    u32 value;

    FillWindowPixelBuffer(&app->windows[4], 0);
    FillWindowPixelBuffer(&app->windows[5], 0);
    FillWindowPixelBuffer(&app->windows[6], 0);
    FrontierRecordsApp_PrintMessage(app, 4, msg_0019_00047, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintMessage(app, 4, msg_0019_00048, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 5, FrontierRecordsApp_GetFactoryStreakLabel(app, 1), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    value = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetWinStreakStat(1, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, value);
    FrontierRecordsApp_PrintFormattedMessage(app, 5, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    value = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetTradeCountStat(1, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, value);
    FrontierRecordsApp_PrintFormattedMessage(app, 5, msg_0019_00052, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 6, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    value = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetBestStreakStat(1, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, value);
    FrontierRecordsApp_PrintFormattedMessage(app, 6, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    value = FrontierSave_GetStat(app->frontierSave, BattleFactory_GetBestTradeCountStat(1, app->mode), FRONTIER_STAT_NO_FRIEND);
    FrontierRecordsApp_BufferNumber(app, 0, value);
    FrontierRecordsApp_PrintFormattedMessage(app, 6, msg_0019_00052, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    ScheduleWindowCopyToVram(&app->windows[4]);
    ScheduleWindowCopyToVram(&app->windows[5]);
    ScheduleWindowCopyToVram(&app->windows[6]);
}

// Returns CURRENT if the streak is still running, PREV otherwise
static u32 FrontierRecordsApp_GetFactoryStreakLabel(FrontierRecordsApp *app, u32 level) {
    u32 stat;
    u32 result;

    if (level == 0) {
        stat = 0x66;
    } else {
        stat = 0x68;
    }
    u8 mode = app->mode;
    if (mode == FRONTIER_CHALLENGE_LINK_MULTI) {
        FrontierSave *frontierSave = Save_Frontier_GetStatic(app->saveData);
        result = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(stat));
    } else {
        int factory = Save_Frontier_GetFactoryFlags(app->saveData);
        result = FactoryFlags_GetField(factory, FACTORY_FLAGS_HAS_STREAK, mode + level * 4, 0);
    }
    return (u8)result == 1 ? msg_0019_00030 : msg_0019_00029;
}

static void FrontierRecordsApp_PrintHallRecords(FrontierRecordsApp *app) {
    FrontierSave *frontierSave;
    u32 stat;
    u32 value;
    u32 flag;
    u32 *records;

    FillWindowPixelBuffer(&app->windows[0], 0);
    FillWindowPixelBuffer(&app->windows[1], 0);
    FillWindowPixelBuffer(&app->windows[2], 0);
    FillWindowPixelBuffer(&app->windows[3], 0);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00024, 0, 0, 0, COLOR_HEADER, RECORDS_ALIGN_LEFT);
    if (app->mode == FRONTIER_CHALLENGE_SINGLE) {
        value = msg_0019_00026;
    } else if (app->mode == FRONTIER_CHALLENGE_DOUBLE) {
        value = msg_0019_00027;
    } else {
        value = msg_0019_00028;
    }
    FrontierRecordsApp_PrintMessage(app, 0, value, 224, 0, 0, COLOR_HEADER, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_BufferSpeciesName(app, app->species);
    FrontierRecordsApp_PrintFormattedMessage(app, 1, msg_0019_00051, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintMessage(app, 2, msg_0019_00029, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    frontierSave = Save_Frontier_GetStatic(app->saveData);
    stat = BattleHall_GetSpeciesStat(app->mode);
    value = FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleHall_GetSpeciesStat(app->mode)));
    if (app->species != value) {
        value = 0;
    } else {
        value = FrontierSave_GetStat(app->frontierSave, BattleHall_GetWinStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND);
    }
    FrontierRecordsApp_BufferNumber(app, 0, value);
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    FrontierRecordsApp_PrintMessage(app, 3, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    records = FrontierSpeciesRecords_Load(app->saveData, HEAP_ID_FIELD2, &flag);
    if (flag != 1) {
        value = 0;
    } else {
        value = FrontierSpeciesRecords_Get(app->saveData, records, BattleHall_GetSpeciesRecordsType(app->mode), app->species);
    }
    if (records != NULL) {
        Heap_Free(records);
    }
    FrontierRecordsApp_BufferNumber(app, 0, value);
    FrontierRecordsApp_PrintFormattedMessage(app, 3, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&app->windows[0]);
    ScheduleWindowCopyToVram(&app->windows[1]);
    ScheduleWindowCopyToVram(&app->windows[2]);
    ScheduleWindowCopyToVram(&app->windows[3]);
}

static void FrontierRecordsApp_BufferSpeciesName(FrontierRecordsApp *app, int species) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0237_bin, HEAP_ID_121);
    String *name = NewString_ReadMsgData(msgData, species);
    DestroyMsgData(msgData);
    BufferString(app->msgFormat, 0, name, 0, 0, 2);
    String_Delete(name);
}

static void FrontierRecordsApp_PrintCastleRecords(FrontierRecordsApp *app) {
    u32 msg, stat;
    FrontierSave *frontierSave;

    FillWindowPixelBuffer(&app->windows[0], 0);
    FillWindowPixelBuffer(&app->windows[1], 0);
    FillWindowPixelBuffer(&app->windows[2], 0);
    FillWindowPixelBuffer(&app->windows[3], 0);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00023, 0, 0, 0, COLOR_HEADER, RECORDS_ALIGN_LEFT);
    if (app->mode == FRONTIER_CHALLENGE_SINGLE) {
        msg = msg_0019_00026;
    } else if (app->mode == FRONTIER_CHALLENGE_DOUBLE) {
        msg = msg_0019_00027;
    } else {
        msg = msg_0019_00028;
    }
    FrontierRecordsApp_PrintMessage(app, 0, msg, 224, 0, 0, COLOR_HEADER, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 1, msg_0019_00049, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 2, FrontierRecordsApp_GetCastleStreakLabel(app), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, BattleCastle_GetWinStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00054, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    frontierSave = Save_Frontier_GetStatic(app->saveData);
    stat = BattleCastle_GetPointsStat(app->mode);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetPointsStat(app->mode))));
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00053, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 3, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, BattleCastle_GetBestStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, 3, msg_0019_00054, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    frontierSave = Save_Frontier_GetStatic(app->saveData);
    stat = BattleCastle_GetBestStreakPointsStat(app->mode);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(frontierSave, stat, FrontierStat_GetFriendIndex(BattleCastle_GetBestStreakPointsStat(app->mode))));
    FrontierRecordsApp_PrintFormattedMessage(app, 3, msg_0019_00053, 224, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    ScheduleWindowCopyToVram(&app->windows[0]);
    ScheduleWindowCopyToVram(&app->windows[1]);
    ScheduleWindowCopyToVram(&app->windows[2]);
    ScheduleWindowCopyToVram(&app->windows[3]);
}

static u32 FrontierRecordsApp_GetCastleStreakLabel(FrontierRecordsApp *app) {
    u32 result;
    u8 mode = app->mode;

    if (mode == FRONTIER_CHALLENGE_LINK_MULTI) {
        FrontierSave *frontierSave = Save_Frontier_GetStatic(app->saveData);
        result = FrontierSave_GetStat(frontierSave, 0x6C, FrontierStat_GetFriendIndex(0x6C));
    } else {
        result = CastleFlags_GetField(Save_Frontier_GetCastleFlags(app->saveData), CASTLE_FLAGS_HAS_STREAK, mode, 0, 0);
    }
    return (u8)result == 1 ? msg_0019_00030 : msg_0019_00029;
}

static void FrontierRecordsApp_PrintArcadeRecords(FrontierRecordsApp *app) {
    u32 msg;

    FillWindowPixelBuffer(&app->windows[0], 0);
    FillWindowPixelBuffer(&app->windows[1], 0);
    FillWindowPixelBuffer(&app->windows[2], 0);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00025, 0, 0, 0, COLOR_HEADER, RECORDS_ALIGN_LEFT);
    if (app->mode == FRONTIER_CHALLENGE_SINGLE) {
        msg = msg_0019_00026;
    } else if (app->mode == FRONTIER_CHALLENGE_DOUBLE) {
        msg = msg_0019_00027;
    } else {
        msg = msg_0019_00028;
    }
    FrontierRecordsApp_PrintMessage(app, 0, msg, 224, 0, 0, COLOR_HEADER, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 1, FrontierRecordsApp_GetArcadeStreakLabel(app), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, BattleArcade_GetWinStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, 1, msg_0019_00055, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    FrontierRecordsApp_PrintMessage(app, 2, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, BattleArcade_GetBestStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00055, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&app->windows[0]);
    ScheduleWindowCopyToVram(&app->windows[1]);
    ScheduleWindowCopyToVram(&app->windows[2]);
}

static u32 FrontierRecordsApp_GetArcadeStreakLabel(FrontierRecordsApp *app) {
    u32 result;
    u8 mode = app->mode;

    if (mode == FRONTIER_CHALLENGE_LINK_MULTI) {
        FrontierSave *frontierSave = Save_Frontier_GetStatic(app->saveData);
        result = FrontierSave_GetStat(frontierSave, 0x6E, FrontierStat_GetFriendIndex(0x6E));
    } else {
        result = ArcadeFlags_GetField(Save_Frontier_GetArcadeFlags(app->saveData), ARCADE_FLAGS_HAS_STREAK, mode, 0, 0);
    }
    return (u8)result == 1 ? msg_0019_00030 : msg_0019_00029;
}

static void FrontierRecordsApp_PrintTowerRecords(FrontierRecordsApp *app) {
    u32 msg;

    FillWindowPixelBuffer(&app->windows[0], 0);
    FillWindowPixelBuffer(&app->windows[2], 0);
    FillWindowPixelBuffer(&app->windows[3], 0);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00021, 0, 0, 0, COLOR_HEADER, RECORDS_ALIGN_LEFT);
    msg = app->mode == TOWER_MODE_SINGLE ? msg_0019_00026 : msg_0019_00027;
    FrontierRecordsApp_PrintMessage(app, 0, msg, 224, 0, 0, COLOR_HEADER, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 2, FrontierRecordsApp_GetTowerStreakLabel(app, app->mode), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, BattleTower_GetWinStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, 2, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    FrontierRecordsApp_PrintMessage(app, 3, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, BattleTower_GetBestStreakStat(app->mode), FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, 3, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&app->windows[0]);
    ScheduleWindowCopyToVram(&app->windows[2]);
    ScheduleWindowCopyToVram(&app->windows[3]);
}

static inline void FrontierRecordsApp_PrintTowerStreak(FrontierRecordsApp *app, u32 windowId, u32 stat) {
    FrontierRecordsApp_BufferNumber(app, 0, FrontierSave_GetStat(app->frontierSave, stat, FRONTIER_STAT_NO_FRIEND));
    FrontierRecordsApp_PrintFormattedMessage(app, windowId, msg_0019_00050, 112, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
}

static void FrontierRecordsApp_PrintTowerMultiRecords(FrontierRecordsApp *app) {
    FillWindowPixelBuffer(&app->windows[0], 0);
    FillWindowPixelBuffer(&app->windows[1], 0);
    FillWindowPixelBuffer(&app->windows[4], 0);
    FillWindowPixelBuffer(&app->windows[5], 0);
    FillWindowPixelBuffer(&app->windows[6], 0);
    FillWindowPixelBuffer(&app->windows[7], 0);
    FillWindowPixelBuffer(&app->windows[8], 0);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00021, 0, 0, 0, COLOR_HEADER, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintMessage(app, 0, msg_0019_00028, 224, 0, 0, COLOR_HEADER, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 1, msg_0019_00044, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintMessage(app, 4, FrontierRecordsApp_GetTowerStreakLabel(app, app->mode), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintTowerStreak(app, 4, BattleTower_GetWinStreakStat(app->mode));
    FrontierRecordsApp_PrintMessage(app, 5, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintTowerStreak(app, 5, BattleTower_GetBestStreakStat(app->mode));
    FrontierRecordsApp_PrintMessage(app, 6, msg_0019_00045, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintMessage(app, 7, FrontierRecordsApp_GetTowerStreakLabel(app, 3), 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintTowerStreak(app, 7, BattleTower_GetWinStreakStat(3));
    FrontierRecordsApp_PrintMessage(app, 8, msg_0019_00043, 0, 0, 0, COLOR_TEXT, RECORDS_ALIGN_LEFT);
    FrontierRecordsApp_PrintTowerStreak(app, 8, BattleTower_GetBestStreakStat(3));
    ScheduleWindowCopyToVram(&app->windows[0]);
    ScheduleWindowCopyToVram(&app->windows[1]);
    ScheduleWindowCopyToVram(&app->windows[4]);
    ScheduleWindowCopyToVram(&app->windows[5]);
    ScheduleWindowCopyToVram(&app->windows[6]);
    ScheduleWindowCopyToVram(&app->windows[7]);
    ScheduleWindowCopyToVram(&app->windows[8]);
}

static u32 FrontierRecordsApp_GetTowerStreakLabel(FrontierRecordsApp *app, u32 mode) {
    FrontierData *frontierData = Save_FrontierData_Get(app->saveData);
    u16 index;

    switch (mode) {
    case 0:
        index = 8;
        break;
    case 1:
        index = 9;
        break;
    case 2:
        index = 10;
        break;
    case 3:
        index = 11;
        break;
    case 4:
        index = 12;
        break;
    case 6:
        index = 15;
        break;
    default:
        index = 8;
        break;
    }
    return FrontierData_FlagAction(frontierData, index, FRONTIER_DATA_GET) == 1 ? msg_0019_00030 : msg_0019_00029;
}

static void FrontierRecordsApp_PrintReturnButton(FrontierRecordsApp *app) {
    String *string = NewString_ReadMsgData(app->msgData, msg_0019_00039);
    FillWindowPixelBuffer(&app->returnButtonWindow, 0);
    FrontierRecordsApp_PrintStringAligned(&app->returnButtonWindow, string, GetWindowWidth(&app->returnButtonWindow) * 8 / 2, 0, 4, COLOR_BUTTON, RECORDS_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&app->returnButtonWindow);
    String_Delete(string);
}

static void FrontierRecordsApp_CreateSprites(FrontierRecordsApp *app) {
    OamManagerParam oamParam;
    OamCharTransferParam transferParam;
    SpriteResourceCountsListUnion capacities;
    NARC *narc;
    u32 i;

    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    app->spriteSystem = SpriteSystem_Alloc(HEAP_ID_121);
    app->spriteManager = SpriteManager_New(app->spriteSystem);
    oamParam = sFrontierRecordsAppOamManagerParam;
    transferParam = sFrontierRecordsAppOamCharTransferParam;
    SpriteSystem_Init(app->spriteSystem, &oamParam, &transferParam, 32);
    capacities = sFrontierRecordsAppSpriteResourceCounts;
    SpriteSystem_InitSprites(app->spriteSystem, app->spriteManager, 2);
    SpriteSystem_InitManagerWithCapacities(app->spriteSystem, app->spriteManager, &capacities);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(app->spriteSystem), 0, FX32_CONST(512));
    narc = NARC_New(NARC_a_1_8_4, HEAP_ID_121);
    SpriteSystem_LoadCharResObjFromOpenNarc(app->spriteSystem, app->spriteManager, narc, 51, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 55500);
    SpriteSystem_LoadPlttResObjFromOpenNarc(app->spriteSystem, app->spriteManager, narc, 64, FALSE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 55500);
    SpriteSystem_LoadCellResObjFromOpenNarc(app->spriteSystem, app->spriteManager, narc, 49, TRUE, 55500);
    SpriteSystem_LoadAnimResObjFromOpenNarc(app->spriteSystem, app->spriteManager, narc, 50, TRUE, 55500);
    NARC_Delete(narc);
    for (i = 0; i < 2; i++) {
        app->sprites[i] = SpriteSystem_NewSprite(app->spriteSystem, app->spriteManager, &sFrontierRecordsSpriteTemplates[i]);
    }
}

static void FrontierRecordsApp_FreeSprites(FrontierRecordsApp *app) {
    u32 i;

    for (i = 0; i < 2; i++) {
        if (app->sprites[i] != NULL) {
            Sprite_DeleteAndFreeResources(app->sprites[i]);
            app->sprites[i] = NULL;
        }
    }
    SpriteSystem_FreeResourcesAndManager(app->spriteSystem, app->spriteManager);
    SpriteSystem_Free(app->spriteSystem);
}

static void FrontierRecordsApp_TickSprites(FrontierRecordsApp *app) {
    u32 i;

    for (i = 0; i < 2; i++) {
        if (app->sprites[i] != NULL) {
            ManagedSprite_TickFrame(app->sprites[i]);
        }
    }
}

static void FrontierRecordsApp_SetSpriteAnim(FrontierRecordsApp *app, int index, int anim) {
    ManagedSprite_SetAnimationFrame(app->sprites[index], 0);
    ManagedSprite_SetAnim(app->sprites[index], anim);
}

static void FrontierRecordsApp_SetSpritePosition(FrontierRecordsApp *app, int index, s16 x, s16 y) {
    ManagedSprite_SetPositionXY(app->sprites[index], x, y);
}

enum {
    BUTTON_FLASH_ON,
    BUTTON_FLASH_OFF,
    BUTTON_FLASH_WAIT,
};

// Returns 0 once the flash has finished
static int FrontierRecordsApp_RunButtonFlash(FrontierRecordsApp *app) {
    switch (app->flash.state) {
    case BUTTON_FLASH_ON:
        if (!app->flash.isBg) {
            ManagedSprite_SetPaletteOverride(app->sprites[app->flash.index], app->flash.paletteOn);
        } else {
            BgTilemapRectChangePalette(app->bgConfig, app->flash.index, app->flash.x, app->flash.y, app->flash.width, app->flash.height, app->flash.paletteOn);
            ScheduleBgTilemapBufferTransfer(app->bgConfig, app->flash.index);
        }
        app->flash.state++;
        break;
    case BUTTON_FLASH_OFF:
        app->flash.timer++;
        if (app->flash.timer != 4) {
            break;
        }
        if (!app->flash.isBg) {
            ManagedSprite_SetPaletteOverride(app->sprites[app->flash.index], app->flash.paletteOff);
        } else {
            BgTilemapRectChangePalette(app->bgConfig, app->flash.index, app->flash.x, app->flash.y, app->flash.width, app->flash.height, app->flash.paletteOff);
            ScheduleBgTilemapBufferTransfer(app->bgConfig, app->flash.index);
        }
        app->flash.timer = 0;
        app->flash.state++;
        break;
    case BUTTON_FLASH_WAIT:
        app->flash.timer++;
        if (app->flash.timer == 2) {
            return 0;
        }
        break;
    }
    return 1;
}

static void FrontierRecordsApp_StartReturnButtonFlash(FrontierRecordsApp *app) {
    app->flash.isBg = FALSE;
    app->flash.index = 0;
    app->flash.paletteOn = 1;
    app->flash.paletteOff = 0;
    app->flash.state = BUTTON_FLASH_ON;
    app->flash.timer = 0;
}

static BOOL FrontierRecordsApp_IsHall(FrontierRecordsApp *app) {
    return app->facility == FRONTIER_FACILITY_HALL;
}

static void FrontierRecordsApp_InitHallPicker(FrontierRecordsApp *app) {
    FrontierRecordsApp_LoadWindowFrame(app);
    FrontierRecordsApp_InitSpeciesGroups(app);
    FrontierRecordsApp_PrintLetters(app);
    FrontierRecordsApp_ShowHallPage(app, HALL_PAGE_LETTERS);
    app->scrollArrows = PaletteBlink_New(NULL, PM_LCD_BOTTOM, 13, HEAP_ID_121);
}

static void FrontierRecordsApp_FreeHallPicker(FrontierRecordsApp *app) {
    PaletteBlink_Delete(app->scrollArrows);
    FrontierRecordsApp_FreeSpeciesGroups(app);
    FrontierRecordsApp_FreeGridInput(app);
}

static void FrontierRecordsApp_ShowHallPage(FrontierRecordsApp *app, int page) {
    switch (page) {
    case HALL_PAGE_RECORDS:
        ScheduleSetBgPosText(app->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(app->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
        FrontierRecordsApp_ClearSpeciesWindows(app);
        FrontierRecordsApp_FreeGridInput(app);
        FrontierRecordsApp_ResetCursor(app);
        FrontierRecordsApp_SelectSpecies(app);
        FrontierRecordsApp_ClearPrompt(app);
        break;
    case HALL_PAGE_LETTERS:
        ScheduleSetBgPosText(app->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(app->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 256);
        FrontierRecordsApp_ClearSpeciesWindows(app);
        ScheduleWindowCopyToVram(&app->windows[4]);
        FrontierRecordsApp_FreeGridInput(app);
        FrontierRecordsApp_CreateLetterGrid(app);
        FrontierRecordsApp_GrayOutEmptyLetters(app);
        FrontierRecordsApp_ShowPrompt(app);
        break;
    case HALL_PAGE_SPECIES:
        ScheduleSetBgPosText(app->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 256);
        ScheduleSetBgPosText(app->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 256);
        ClearWindowTilemapAndScheduleTransfer(&app->windows[4]);
        FrontierRecordsApp_ClearRecordWindows(app);
        FrontierRecordsApp_PrintSpeciesPage(app);
        FrontierRecordsApp_PrintPageNumber(app);
        FrontierRecordsApp_DrawPageArrows(app);
        FrontierRecordsApp_PrintLetterTitle(app);
        FrontierRecordsApp_FreeGridInput(app);
        FrontierRecordsApp_CreateSpeciesGrid(app);
        FrontierRecordsApp_ShowPrompt(app);
        break;
    }
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_2);
}

static void FrontierRecordsApp_DrawPageArrows(FrontierRecordsApp *app) {
    if (app->lastPage == 0) {
        LoadRectToBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, app->pageArrowTiles[RECORDS_ARROW_DISABLED], 34, 52, 4, 4);
        LoadRectToBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, app->pageArrowTiles[RECORDS_ARROW_DISABLED], 38, 52, 4, 4);
    } else {
        LoadRectToBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, app->pageArrowTiles[RECORDS_ARROW_LEFT], 34, 52, 4, 4);
        LoadRectToBgTilemapRect(app->bgConfig, GF_BG_LYR_MAIN_2, app->pageArrowTiles[RECORDS_ARROW_RIGHT], 38, 52, 4, 4);
    }
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_2);
}

static void FrontierRecordsApp_FreeGridInput(FrontierRecordsApp *app) {
    if (app->gridInput != NULL) {
        GridInputHandler_Free(app->gridInput);
        app->gridInput = NULL;
    }
}

static void FrontierRecordsApp_GridCallback_Nop(void *data, int input, int prevInput) {
}

// Species of one letter in alphabetical order (members 18-43 of the Pokedex sort data)
static u16 *FrontierRecordsApp_LoadSortedSpecies(int letter, u32 *count) {
    u32 size;
    u16 *species = GfGfxLoader_LoadFromNarc_GetSizeOut(GetPokedexDataNarcID(), letter + 18, FALSE, HEAP_ID_121, TRUE, &size);
    *count = size / 2;
    return species;
}

// Keeps the species that have a Battle Hall record
static void FrontierRecordsApp_InitSpeciesGroups(FrontierRecordsApp *app) {
    u32 enabled;
    u32 count;
    u32 *records = FrontierSpeciesRecords_Load(app->saveData, HEAP_ID_FIELD2, &enabled);
    u16 letter;

    if (enabled == 1) {
        for (letter = 0; letter < NUM_LETTERS; letter++) {
            u16 *species = FrontierRecordsApp_LoadSortedSpecies(letter, &count);
            u16 i;
            app->groups[letter].species = Heap_Alloc(HEAP_ID_121, count * 2);
            for (i = 0; i < count; i++) {
                if (FrontierSpeciesRecords_Get(app->saveData, records, BattleHall_GetSpeciesRecordsType(app->mode), species[i])) {
                    app->groups[letter].species[app->groups[letter].count] = species[i];
                    app->groups[letter].count++;
                }
            }
            Heap_Free(species);
        }
    }
    if (records != NULL) {
        Heap_Free(records);
    }
}

static void FrontierRecordsApp_FreeSpeciesGroups(FrontierRecordsApp *app) {
    u32 i;

    for (i = 0; i < NUM_LETTERS; i++) {
        if (app->groups[i].species != NULL) {
            Heap_Free(app->groups[i].species);
        }
    }
}

static void FrontierRecordsApp_LoadWindowFrame(FrontierRecordsApp *app) {
    u8 frame = Options_GetFrame(app->options);
    LoadUserFrameGfx2(app->bgConfig, GF_BG_LYR_SUB_0, 0x3E2, 14, frame, HEAP_ID_121);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_121);
}

static void FrontierRecordsApp_ShowPrompt(FrontierRecordsApp *app) {
    DrawFrameAndWindow2(&app->windows[23], TRUE, 0x3E2, 14);
    FillWindowPixelBuffer(&app->windows[23], 15);
    FrontierRecordsApp_PrintMessage(app, 23, msg_0019_00042, 0, 0, 1, COLOR_PROMPT, RECORDS_ALIGN_LEFT);
    ScheduleWindowCopyToVram(&app->windows[23]);
}

static void FrontierRecordsApp_ClearPrompt(FrontierRecordsApp *app) {
    ClearFrameAndWindow2(&app->windows[23], TRUE);
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_SUB_0);
}

// Letter buttons are laid out 7 per row, 32 pixels apart
static void FrontierRecordsApp_PrintLetters(FrontierRecordsApp *app) {
    u16 i;
    int position, column;

    for (i = 0; i < NUM_LETTERS; i++) {
        position = sFrontierRecordsLetterPositions[i];
        column = position % 7;
        FrontierRecordsApp_PrintMessage(app, 4, i + msg_0019_00056, (column << 5) + 24, (position / 7) << 5, 4, COLOR_BUTTON, RECORDS_ALIGN_CENTER);
    }
}

static void FrontierRecordsApp_MoveLetterCursor(FrontierRecordsApp *app, int selection) {
    u8 x;
    u8 y;
    const DpadMenuBox *box = GridInputHandler_GetDpadBox(app->gridInput, selection);

    DpadMenuBox_GetPosition(box, &x, &y);
    FrontierRecordsApp_SetSpritePosition(app, 1, x, y);
    if (selection == LETTER_GRID_RETURN) {
        FrontierRecordsApp_SetSpriteAnim(app, 1, 1);
    } else {
        FrontierRecordsApp_SetSpriteAnim(app, 1, 2);
    }
}

static void FrontierRecordsApp_CreateLetterGrid(FrontierRecordsApp *app) {
    app->gridInput = GridInputHandler_Create(sFrontierRecordsLetterGridHitboxes, sFrontierRecordsLetterGridBoxes, &sFrontierRecordsLetterGridCallbacks, app, TRUE, app->letter, HEAP_ID_121);
    FrontierRecordsApp_MoveLetterCursor(app, app->letter);
}

static void FrontierRecordsApp_LetterGrid_OnKeyMove(void *data, int input, int prevInput) {
    FrontierRecordsApp_MoveLetterCursor(data, input);
}

static void FrontierRecordsApp_LetterGrid_OnTouch(void *data, int input, int prevInput) {
    FrontierRecordsApp_MoveLetterCursor(data, input);
}

static inline void FrontierRecordsApp_InitLetterFlash(FrontierRecordsApp *app) {
    app->flash.isBg = TRUE;
    app->flash.index = GF_BG_LYR_MAIN_2;
    app->flash.paletteOn = 2;
    app->flash.paletteOff = 0;
}

static void FrontierRecordsApp_StartLetterFlash(FrontierRecordsApp *app, u32 letter) {
    FrontierRecordsApp_InitLetterFlash(app);
    letter = sFrontierRecordsLetterPositions[letter];
    app->flash.x = ((letter % 7) * 32 + 24) / 8;
    app->flash.y = ((letter / 7) * 32 + 40) / 8 + 32;
    app->flash.width = 2;
    app->flash.height = 2;
    app->flash.state = BUTTON_FLASH_ON;
    app->flash.timer = 0;
}

static u8 FrontierRecordsApp_HandleLetterInput(FrontierRecordsApp *app) {
    u32 input;
    FrontierRecordsSpeciesGroup *groups;

    input = GridInputHandler_HandleInput_NoHold(app->gridInput);
    switch (input) {
    case LETTER_GRID_RETURN:
    case GRID_MENU_CANCEL:
        PlaySE(SEQ_SE_DP_DECIDE);
        FrontierRecordsApp_StartReturnButtonFlash(app);
        FrontierRecordsApp_FreeHallPicker(app);
        app->nextState = RUN_STATE_EXIT;
        return RUN_STATE_BUTTON_FLASH;
    case GRID_MENU_CURSOR_MOVE:
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    case GRID_MENU_BUTTON_MODE:
    case GRID_MENU_NOTHING_CHOSEN:
        break;
    default:
        groups = app->groups;
        if (groups[input].count == 0) {
            PlaySE(SEQ_SE_DP_CUSTOM06);
            break;
        }
        PlaySE(SEQ_SE_DP_DECIDE);
        app->letter = input;
        app->speciesIndex = 0;
        app->page = 0;
        app->lastPage = (groups[input].count - 1) / SPECIES_PER_PAGE;
        FrontierRecordsApp_StartLetterFlash(app, app->letter);
        app->nextState = RUN_STATE_SHOW_SPECIES;
        return RUN_STATE_BUTTON_FLASH;
    }
    return RUN_STATE_LETTERS;
}

static void FrontierRecordsApp_GrayOutEmptyLetters(FrontierRecordsApp *app) {
    u32 i;

    for (i = 0; i < NUM_LETTERS; i++) {
        if (app->groups[i].count == 0) {
            FrontierRecordsApp_StartLetterFlash(app, i);
            BgTilemapRectChangePalette(app->bgConfig, GF_BG_LYR_MAIN_2, app->flash.x, app->flash.y, app->flash.width, app->flash.height, 1);
        }
    }
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_2);
}

static void FrontierRecordsApp_MoveSpeciesCursor(FrontierRecordsApp *app, int selection) {
    u8 x;
    u8 y;
    const DpadMenuBox *box = GridInputHandler_GetDpadBox(app->gridInput, selection);

    DpadMenuBox_GetPosition(box, &x, &y);
    FrontierRecordsApp_SetSpritePosition(app, 1, x, y);
    if (selection == SPECIES_GRID_RETURN) {
        FrontierRecordsApp_SetSpriteAnim(app, 1, 1);
    } else {
        FrontierRecordsApp_SetSpriteAnim(app, 1, 3);
    }
}

static void FrontierRecordsApp_CreateSpeciesGrid(FrontierRecordsApp *app) {
    int selection = app->speciesIndex;
    app->gridInput = GridInputHandler_Create(sFrontierRecordsSpeciesGridHitboxes, sFrontierRecordsSpeciesGridBoxes, &sFrontierRecordsSpeciesGridCallbacks, app, TRUE, selection, HEAP_ID_121);
    FrontierRecordsApp_MoveSpeciesCursor(app, selection);
}

static void FrontierRecordsApp_SpeciesGrid_OnKeyMove(void *data, int input, int prevInput) {
    FrontierRecordsApp_MoveSpeciesCursor(data, input);
}

static void FrontierRecordsApp_SpeciesGrid_OnTouch(void *data, int input, int prevInput) {
    FrontierRecordsApp_MoveSpeciesCursor(data, input);
}

// Species buttons: two columns, 13 tiles apart
static void FrontierRecordsApp_StartSpeciesFlash(FrontierRecordsApp *app, int slot) {
    unsigned int position;

    app->flash.isBg = TRUE;
    app->flash.index = GF_BG_LYR_MAIN_2;
    app->flash.paletteOn = 2;
    app->flash.paletteOff = 0;
    position = sFrontierRecordsLetterPositions[slot];
    app->flash.x = (position & 1) * 13 + 38;
    app->flash.y = (position / 2) * 4 + 37;
    app->flash.width = 9;
    app->flash.height = 2;
    app->flash.state = BUTTON_FLASH_ON;
    app->flash.timer = 0;
}

static void FrontierRecordsApp_StartArrowFlash(FrontierRecordsApp *app, u8 x, u8 y) {
    app->flash.isBg = TRUE;
    app->flash.index = GF_BG_LYR_MAIN_2;
    app->flash.paletteOn = 2;
    app->flash.paletteOff = 0;
    app->flash.x = x;
    app->flash.y = y;
    app->flash.width = 4;
    app->flash.height = 4;
    app->flash.state = BUTTON_FLASH_ON;
    app->flash.timer = 0;
}

static inline void FrontierRecordsApp_PrevPage(FrontierRecordsApp *app) {
    app->page--;
    if (app->page < 0) {
        app->page = app->lastPage;
    }
}

static inline void FrontierRecordsApp_NextPage(FrontierRecordsApp *app) {
    app->page++;
    if (app->page > app->lastPage) {
        app->page = 0;
    }
}

static int FrontierRecordsApp_HandleSpeciesInput(FrontierRecordsApp *app) {
    int input = GridInputHandler_HandleInput_NoHold(app->gridInput);

    switch ((u32)input) {
    case SPECIES_GRID_RETURN:
    case GRID_MENU_CANCEL:
        PlaySE(SEQ_SE_DP_DECIDE);
        FrontierRecordsApp_StartReturnButtonFlash(app);
        app->nextState = RUN_STATE_SHOW_LETTERS;
        return RUN_STATE_BUTTON_FLASH;
    case GRID_MENU_CURSOR_MOVE:
        PlaySE(SEQ_SE_DP_SELECT);
        break;
    case GRID_MENU_BUTTON_MODE:
        break;
    case GRID_MENU_NOTHING_CHOSEN:
        // Left/right at the edge of the grid flips the page
        switch (GridInputHandler_GetNextInput(app->gridInput)) {
        case 0:
        case 2:
        case 4:
        case 6:
            if ((gSystem.newKeys & PAD_KEY_LEFT) && app->lastPage != 0) {
                FrontierRecordsApp_PrevPage(app);
                PlaySE(SEQ_SE_DP_SELECT);
                FrontierRecordsApp_PrintSpeciesPage(app);
                FrontierRecordsApp_PrintPageNumber(app);
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            if ((gSystem.newKeys & PAD_KEY_RIGHT) && app->lastPage != 0) {
                FrontierRecordsApp_NextPage(app);
                PlaySE(SEQ_SE_DP_SELECT);
                FrontierRecordsApp_PrintSpeciesPage(app);
                FrontierRecordsApp_PrintPageNumber(app);
            }
            break;
        }
        break;
    default:
        if ((u32)(input + app->page * SPECIES_PER_PAGE) >= app->groups[app->letter].count) {
            PlaySE(SEQ_SE_DP_CUSTOM06);
            break;
        }
        app->speciesIndex = input;
        PlaySE(SEQ_SE_DP_DECIDE);
        FrontierRecordsApp_StartSpeciesFlash(app, input);
        app->nextState = RUN_STATE_SHOW_HALL_RECORDS;
        return RUN_STATE_BUTTON_FLASH;
    }
    switch (TouchscreenHitbox_FindRectAtTouchNew(sFrontierRecordsSpeciesHitboxes)) {
    case 0:
        if (app->lastPage != 0) {
            FrontierRecordsApp_PrevPage(app);
            PlaySE(SEQ_SE_DP_SELECT78);
            FrontierRecordsApp_StartArrowFlash(app, 34, 52);
            app->nextState = RUN_STATE_FLIP_PAGE;
            return RUN_STATE_BUTTON_FLASH;
        }
        break;
    case 1:
        if (app->lastPage != 0) {
            FrontierRecordsApp_NextPage(app);
            PlaySE(SEQ_SE_DP_SELECT78);
            FrontierRecordsApp_StartArrowFlash(app, 38, 52);
            app->nextState = RUN_STATE_FLIP_PAGE;
            return RUN_STATE_BUTTON_FLASH;
        }
        break;
    }
    return RUN_STATE_SPECIES;
}

static int FrontierRecordsApp_FlipSpeciesPage(FrontierRecordsApp *app) {
    FrontierRecordsApp_PrintSpeciesPage(app);
    FrontierRecordsApp_PrintPageNumber(app);
    return RUN_STATE_SPECIES;
}

// The species page alternates between two sets of eight windows (5-12 and 13-20)
static void FrontierRecordsApp_PrintSpeciesPage(FrontierRecordsApp *app) {
    int windowId;
    u16 start;
    u8 i;
    u8 palette;

    if (app->speciesWindowBank == 0) {
        windowId = 5;
    } else {
        windowId = 13;
    }
    start = app->page * SPECIES_PER_PAGE;
    for (i = 0; i < SPECIES_PER_PAGE; i++) {
        FillWindowPixelBuffer(&app->windows[windowId + i], 0);
        if (app->groups[app->letter].count > start + i) {
            FrontierRecordsApp_BufferSpeciesName(app, app->groups[app->letter].species[start + i]);
            FrontierRecordsApp_PrintFormattedMessage(app, windowId + i, msg_0019_00019, GetWindowWidth(&app->windows[windowId + i]) * 8 / 2, 0, 4, COLOR_BUTTON, RECORDS_ALIGN_CENTER);
            palette = 0;
        } else {
            palette = 1;
        }
        ScheduleWindowCopyToVram(&app->windows[windowId + i]);
        FrontierRecordsApp_StartSpeciesFlash(app, i);
        BgTilemapRectChangePalette(app->bgConfig, GF_BG_LYR_MAIN_2, app->flash.x, app->flash.y, app->flash.width, app->flash.height, palette);
    }
    ScheduleBgTilemapBufferTransfer(app->bgConfig, GF_BG_LYR_MAIN_2);
    app->speciesWindowBank ^= 1;
}

static void FrontierRecordsApp_ClearSpeciesWindows(FrontierRecordsApp *app) {
    u32 i = 5;
    Window *window = &app->windows[5];

    do {
        ClearWindowTilemapAndScheduleTransfer(window);
        i++;
        window++;
    } while (i <= 13);
    ClearWindowTilemapAndScheduleTransfer(&app->windows[21]);
    ClearWindowTilemapAndScheduleTransfer(&app->windows[22]);
}

static void FrontierRecordsApp_PrintLetterTitle(FrontierRecordsApp *app) {
    int width;

    FillWindowPixelBuffer(&app->windows[21], 0);
    width = GetWindowWidth(&app->windows[21]);
    FrontierRecordsApp_PrintMessage(app, 21, app->letter + msg_0019_00056, (width * 8) / 2, 0, 4, COLOR_BUTTON, RECORDS_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&app->windows[21]);
}

static void FrontierRecordsApp_PrintPageNumber(FrontierRecordsApp *app) {
    FillWindowPixelBuffer(&app->windows[22], 0);
    FrontierRecordsApp_BufferNumber(app, 0, app->page + 1);
    FrontierRecordsApp_PrintFormattedMessage(app, 22, msg_0019_00040, 8, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    FrontierRecordsApp_PrintMessage(app, 22, msg_0019_00041, 16, 0, 0, COLOR_TEXT, RECORDS_ALIGN_CENTER);
    FrontierRecordsApp_BufferNumber(app, 0, app->lastPage + 1);
    FrontierRecordsApp_PrintFormattedMessage(app, 22, msg_0019_00040, 32, 0, 0, COLOR_TEXT, RECORDS_ALIGN_RIGHT);
    ScheduleWindowCopyToVram(&app->windows[22]);
}

static void FrontierRecordsApp_ResetCursor(FrontierRecordsApp *app) {
    FrontierRecordsApp_SetSpritePosition(app, 1, 224, 176);
    FrontierRecordsApp_SetSpriteAnim(app, 1, 1);
}

static void FrontierRecordsApp_SelectSpecies(FrontierRecordsApp *app) {
    u16 *species = app->groups[app->letter].species;
    app->species = species[app->speciesIndex + app->page * SPECIES_PER_PAGE];
    FrontierRecordsApp_PrintHallRecords(app);
}

static void FrontierRecordsApp_ClearRecordWindows(FrontierRecordsApp *app) {
    ClearWindowTilemapAndScheduleTransfer(&app->windows[0]);
    ClearWindowTilemapAndScheduleTransfer(&app->windows[1]);
    ClearWindowTilemapAndScheduleTransfer(&app->windows[2]);
    ClearWindowTilemapAndScheduleTransfer(&app->windows[3]);
}
