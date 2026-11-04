#include "battle_room_results.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0028.h"

#include "bg_window.h"
#include "font.h"
#include "frontier_data.h"
#include "frontier_data_access.h"
#include "frontier_save_access.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "grid_input_handler.h"
#include "heap.h"
#include "mail_message.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite_resource_header.h"
#include "sprite_system.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"

#define BATTLE_ROOM_RESULTS_NUM_LEADERS        30
#define BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE   12
#define BATTLE_ROOM_RESULTS_NUM_PAGES          3
#define BATTLE_ROOM_RESULTS_NUM_RESULT_WINDOWS 10
#define BATTLE_ROOM_RESULTS_NUM_LEADER_WINDOWS 35
#define BATTLE_ROOM_RESULTS_CANCEL             12

enum BattleRoomResultsSetupState {
    BATTLE_ROOM_RESULTS_SETUP_INIT_BGS,
    BATTLE_ROOM_RESULTS_SETUP_LOAD_BG_GFX,
    BATTLE_ROOM_RESULTS_SETUP_INIT_SPRITES,
    BATTLE_ROOM_RESULTS_SETUP_CREATE_SCREENS,
    BATTLE_ROOM_RESULTS_SETUP_START_VBLANK,
};

enum BattleRoomResultsTeardownState {
    BATTLE_ROOM_RESULTS_TEARDOWN_FREE,
    BATTLE_ROOM_RESULTS_TEARDOWN_RESET_DISPLAY,
};

enum BattleRoomResultsFlashState {
    BATTLE_ROOM_RESULTS_FLASH_PRESS,
    BATTLE_ROOM_RESULTS_FLASH_RELEASE,
    BATTLE_ROOM_RESULTS_FLASH_WAIT,
};

// One downloaded Battle Room leader, as shown.
typedef struct BattleRoomResultsLeader {
    String *name;
    u8 gender;
    u8 country;
    u8 region;
    u8 useDefaultName;
    MailMessage greeting;
} BattleRoomResultsLeader;

// Brief palette flash of a pressed button: a sprite, or a rectangle of a bg layer.
typedef struct BattleRoomResultsFlash {
    u8 isBgRect : 1;
    u8 target : 7; // sprite index or bg layer
    u8 pressedPltt : 4;
    u8 normalPltt : 4;
    u8 state;
    u8 timer;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} BattleRoomResultsFlash;

typedef struct BattleRoomResults {
    enum HeapID heapID;
    u32 subState;
    u16 showLeaders;
    u8 unk_0A;
    u8 padding_0B[5];
    BgConfig *bgConfig;
    u8 padding_14[4];
    Options *options;
    FrontierSave *frontierSave;
    FrontierData *frontierData;
    BattleRoomDownload *downloadData;
    MsgData *msgData;
    MessageFormat *msgFormat;
    String *string;
    u8 padding_34[0x30];
    String *defaultNames[2];
    Window windows[BATTLE_ROOM_RESULTS_NUM_LEADER_WINDOWS];
    BattleRoomResultsLeader leaders[BATTLE_ROOM_RESULTS_NUM_LEADERS];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    ManagedSprite *sprites[4];
    BattleRoomResultsFlash flash;
    int nextState;
    u16 page;
    u8 nameWindowSet;
    u8 infoWindowSet;
    GridInputHandler *gridInput;
    int pageChange;
} BattleRoomResults;

static BOOL BattleRoomResults_SetupScreens(BattleRoomResults *results);
static BOOL BattleRoomResults_TeardownScreens(BattleRoomResults *results);
static void BattleRoomResults_SetGfxBanks(void);
static void BattleRoomResults_VBlankCB(BattleRoomResults *results);
static int BattleRoomResults_HandleResultsInput(BattleRoomResults *results);
static int BattleRoomResults_HandleLeadersInput(BattleRoomResults *results);
static void BattleRoomResults_InitBgs(BattleRoomResults *results);
static void BattleRoomResults_FreeBgs(BattleRoomResults *results);
static void BattleRoomResults_LoadBgGraphics(BattleRoomResults *results);
static void BattleRoomResults_AddWindows(BattleRoomResults *results);
static void BattleRoomResults_RemoveWindows(BattleRoomResults *results);
static void BattleRoomResults_InitStrings(BattleRoomResults *results);
static void BattleRoomResults_FreeStrings(BattleRoomResults *results);
static void BattleRoomResults_PrintString(Window *window, String *string, u32 x, int y, int fontId, u32 color, int alignment);
static void BattleRoomResults_PrintMessage(BattleRoomResults *results, int windowIndex, int msgId, u32 x, int y, int fontId, u32 color, int alignment);
static void BattleRoomResults_PrintFormattedMessage(BattleRoomResults *results, int windowIndex, int msgId, u32 x, int y, int fontId, u32 color, int alignment);
static void BattleRoomResults_PrintTitle(BattleRoomResults *results);
static void BattleRoomResults_PrintResults(BattleRoomResults *results);
static void BattleRoomResults_LoadLeaders(BattleRoomResults *results);
static void BattleRoomResults_FreeLeaderNames(BattleRoomResults *results);
static void BattleRoomResults_PrintLeaderNames(BattleRoomResults *results);
static void BattleRoomResults_PrintPageNumber(BattleRoomResults *results);
static void BattleRoomResults_PrintLeadersScreen(BattleRoomResults *results);
static void BattleRoomResults_PrintLeaderInfo(BattleRoomResults *results, int leader);
static void BattleRoomResults_LeadersDummy(BattleRoomResults *results);
static void BattleRoomResults_InitSprites(BattleRoomResults *results);
static void BattleRoomResults_FreeSprites(BattleRoomResults *results);
static void BattleRoomResults_UpdateSprites(BattleRoomResults *results);
static void BattleRoomResults_TransferOam(void);
static void BattleRoomResults_SetSpriteAnim(BattleRoomResults *results, int index, int anim);
static void BattleRoomResults_SetSpritePosition(BattleRoomResults *results, int index, s16 x, s16 y);
static BOOL BattleRoomResults_UpdateButtonFlash(BattleRoomResults *results);
static void BattleRoomResults_StartSpriteFlash(BattleRoomResults *results, int sprite);
static void BattleRoomResults_StartExitButtonFlash(BattleRoomResults *results);
static void BattleRoomResults_CreateGridInput(BattleRoomResults *results);
static void BattleRoomResults_FreeGridInput(BattleRoomResults *results);
static void BattleRoomResults_MoveCursor(BattleRoomResults *results, int input);
static void BattleRoomResults_GridNoop(void *data, int newInput, int prevInput);
static void BattleRoomResults_GridOnKeyMove(void *data, int newInput, int prevInput);
static void BattleRoomResults_GridOnTouch(void *data, int input, int prevInput);

static const TouchscreenHitbox sBattleRoomResultsHitbox[] = {
    { .rect = { 164, 187, 193, 254 } },
};

static const TouchscreenHitbox sBattleRoomResultsPageHitboxes[] = {
    { .rect = { 162, 189, 18, 45 } },
    { .rect = { 162, 189, 50, 77 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const GraphicsModes sBattleRoomResultsGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const GridCallbacks sBattleRoomResultsGridCallbacks = {
    .onButton = BattleRoomResults_GridNoop,
    .onSwitchToTouchMode = BattleRoomResults_GridNoop,
    .onKeyMove = BattleRoomResults_GridOnKeyMove,
    .onTouch = BattleRoomResults_GridOnTouch,
};

static const OamCharTransferParam sBattleRoomResultsOamCharTransferParam = {
    .maxTasks = 1,
    .sizeMain = 0x10000,
    .sizeSub = 0x4000,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_32K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_32K,
};

static const SpriteResourceCountsListUnion sBattleRoomResultsSpriteResourceCounts = {
    .numChar = 1,
    .numPltt = 1,
    .numCell = 1,
    .numAnim = 1,
    .numMcel = 0,
    .numManm = 0,
};

static const BgTemplate sBattleRoomResultsBgTemplate_Main1 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sBattleRoomResultsBgTemplate_Main0 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sBattleRoomResultsBgTemplate_Sub0 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 0,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sBattleRoomResultsBgTemplate_Sub1 = {
    .x = 0,
    .y = 0,
    .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const OamManagerParam sBattleRoomResultsOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 128,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 0,
    .numOBJsub = 128,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const GraphicsBanks sBattleRoomResultsGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

static const TouchscreenHitbox sBattleRoomResultsGridHitboxes[] = {
    { .rect = { 56, 71, 21, 90 } },
    { .rect = { 56, 71, 93, 162 } },
    { .rect = { 56, 71, 165, 234 } },
    { .rect = { 80, 95, 21, 90 } },
    { .rect = { 80, 95, 93, 162 } },
    { .rect = { 80, 95, 165, 234 } },
    { .rect = { 104, 119, 21, 90 } },
    { .rect = { 104, 119, 93, 162 } },
    { .rect = { 104, 119, 165, 234 } },
    { .rect = { 128, 143, 21, 90 } },
    { .rect = { 128, 143, 93, 162 } },
    { .rect = { 128, 143, 165, 234 } },
    { .rect = { 164, 187, 193, 254 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const WindowTemplate sBattleRoomResultsWindowTemplates[] = {
    { GF_BG_LYR_MAIN_0, 24, 21, 8,  2, 15, 1    },
    { GF_BG_LYR_MAIN_0, 5,  1,  22, 2, 15, 0x11 },
    { GF_BG_LYR_MAIN_0, 1,  6,  9,  4, 15, 0x3D },
    { GF_BG_LYR_MAIN_0, 1,  13, 9,  4, 15, 0x61 },
    { GF_BG_LYR_MAIN_0, 11, 7,  6,  2, 15, 0x85 },
    { GF_BG_LYR_MAIN_0, 20, 7,  2,  2, 15, 0x91 },
    { GF_BG_LYR_MAIN_0, 11, 13, 7,  2, 15, 0x95 },
    { GF_BG_LYR_MAIN_0, 18, 13, 12, 2, 15, 0xA3 },
    { GF_BG_LYR_MAIN_0, 11, 16, 6,  2, 15, 0xBB },
    { GF_BG_LYR_MAIN_0, 18, 16, 12, 2, 15, 0xC7 },
};

static const DpadMenuBox sBattleRoomResultsGridDpadBoxes[] = {
    { 56,  64,  0, 0, 0,   3,  2,  1  },
    { 128, 64,  0, 0, 1,   4,  0,  2  },
    { 200, 64,  0, 0, 2,   5,  1,  0  },
    { 56,  88,  0, 0, 0,   6,  5,  4  },
    { 128, 88,  0, 0, 1,   7,  3,  5  },
    { 200, 88,  0, 0, 2,   8,  4,  3  },
    { 56,  112, 0, 0, 3,   9,  8,  7  },
    { 128, 112, 0, 0, 4,   10, 6,  8  },
    { 200, 112, 0, 0, 5,   11, 7,  6  },
    { 56,  136, 0, 0, 6,   12, 11, 10 },
    { 128, 136, 0, 0, 7,   12, 9,  11 },
    { 200, 136, 0, 0, 8,   12, 10, 9  },
    { 224, 176, 0, 0, 139, 12, 12, 12 },
};

static const ManagedSpriteTemplate sBattleRoomResultsSpriteTemplates[] = {
    { 224, 176, 0, 2, 0,  0, NNS_G2D_VRAM_TYPE_2DMAIN, { 0xD158, 0xD158, 0xD158, 0xD158, -1, -1 }, 0, 0 },
    { 224, 176, 0, 0, 10, 0, NNS_G2D_VRAM_TYPE_2DMAIN, { 0xD158, 0xD158, 0xD158, 0xD158, -1, -1 }, 1, 0 },
    { 40,  176, 0, 3, 0,  0, NNS_G2D_VRAM_TYPE_2DMAIN, { 0xD158, 0xD158, 0xD158, 0xD158, -1, -1 }, 0, 0 },
    { 72,  176, 0, 5, 10, 0, NNS_G2D_VRAM_TYPE_2DMAIN, { 0xD158, 0xD158, 0xD158, 0xD158, -1, -1 }, 0, 0 },
};

static const WindowTemplate sBattleRoomResultsLeaderWindowTemplates[] = {
    { GF_BG_LYR_MAIN_0, 24, 21, 8,  2, 15, 1     },
    { GF_BG_LYR_MAIN_0, 5,  1,  8,  2, 15, 0x11  },
    { GF_BG_LYR_MAIN_0, 13, 1,  15, 2, 15, 0x21  },
    { GF_BG_LYR_MAIN_0, 5,  3,  22, 2, 15, 0x3F  },
    { GF_BG_LYR_MAIN_0, 15, 21, 4,  2, 15, 0x6B  },
    { GF_BG_LYR_SUB_0,  2,  7,  28, 2, 15, 1     },
    { GF_BG_LYR_SUB_0,  2,  10, 28, 6, 15, 0x71  },
    { GF_BG_LYR_SUB_0,  2,  17, 28, 6, 15, 0x1C1 },
    { GF_BG_LYR_SUB_0,  2,  7,  28, 2, 15, 0x39  },
    { GF_BG_LYR_SUB_0,  2,  10, 28, 6, 15, 0x119 },
    { GF_BG_LYR_SUB_0,  2,  17, 28, 6, 15, 0x269 },
    { GF_BG_LYR_MAIN_0, 3,  7,  8,  2, 15, 0x73  },
    { GF_BG_LYR_MAIN_0, 12, 7,  8,  2, 15, 0x83  },
    { GF_BG_LYR_MAIN_0, 21, 7,  8,  2, 15, 0x93  },
    { GF_BG_LYR_MAIN_0, 3,  10, 8,  2, 15, 0xA3  },
    { GF_BG_LYR_MAIN_0, 12, 10, 8,  2, 15, 0xB3  },
    { GF_BG_LYR_MAIN_0, 21, 10, 8,  2, 15, 0xC3  },
    { GF_BG_LYR_MAIN_0, 3,  13, 8,  2, 15, 0xD3  },
    { GF_BG_LYR_MAIN_0, 12, 13, 8,  2, 15, 0xE3  },
    { GF_BG_LYR_MAIN_0, 21, 13, 8,  2, 15, 0xF3  },
    { GF_BG_LYR_MAIN_0, 3,  16, 8,  2, 15, 0x103 },
    { GF_BG_LYR_MAIN_0, 12, 16, 8,  2, 15, 0x113 },
    { GF_BG_LYR_MAIN_0, 21, 16, 8,  2, 15, 0x123 },
    { GF_BG_LYR_MAIN_0, 3,  7,  8,  2, 15, 0x133 },
    { GF_BG_LYR_MAIN_0, 12, 7,  8,  2, 15, 0x143 },
    { GF_BG_LYR_MAIN_0, 21, 7,  8,  2, 15, 0x153 },
    { GF_BG_LYR_MAIN_0, 3,  10, 8,  2, 15, 0x163 },
    { GF_BG_LYR_MAIN_0, 12, 10, 8,  2, 15, 0x173 },
    { GF_BG_LYR_MAIN_0, 21, 10, 8,  2, 15, 0x183 },
    { GF_BG_LYR_MAIN_0, 3,  13, 8,  2, 15, 0x193 },
    { GF_BG_LYR_MAIN_0, 12, 13, 8,  2, 15, 0x1A3 },
    { GF_BG_LYR_MAIN_0, 21, 13, 8,  2, 15, 0x1B3 },
    { GF_BG_LYR_MAIN_0, 3,  16, 8,  2, 15, 0x1C3 },
    { GF_BG_LYR_MAIN_0, 12, 16, 8,  2, 15, 0x1D3 },
    { GF_BG_LYR_MAIN_0, 21, 16, 8,  2, 15, 0x1E3 },
};

BOOL BattleRoomResults_Init(OverlayManager *man, int *state) {
    BattleRoomResultsArgs *args = OverlayManager_GetArgs(man);
    BattleRoomResults *results;

    Heap_Create(HEAP_ID_3, HEAP_ID_72, 0x20000);
    results = OverlayManager_CreateAndGetData(man, sizeof(BattleRoomResults), HEAP_ID_72);
    memset(results, 0, sizeof(BattleRoomResults));
    results->showLeaders = args->showLeaders;
    results->unk_0A = args->unk_6;
    results->options = Save_PlayerData_GetOptionsAddr(args->saveData);
    results->frontierSave = Save_Frontier_GetStatic(args->saveData);
    results->frontierData = Save_FrontierData_Get(args->saveData);
    results->downloadData = Save_BattleRoomDownload_Get(args->saveData);
    results->heapID = HEAP_ID_72;
    SetKeyRepeatTimers(4, 8);
    return TRUE;
}

BOOL BattleRoomResults_Exit(OverlayManager *man, int *state) {
    BattleRoomResults *results = OverlayManager_GetData(man);

    OverlayManager_FreeData(man);
    Heap_Destroy(results->heapID);
    return TRUE;
}

enum {
    BATTLE_ROOM_RESULTS_STATE_SETUP,
    BATTLE_ROOM_RESULTS_STATE_FADE_IN,
    BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_IN,
    BATTLE_ROOM_RESULTS_STATE_RESULTS_INPUT,
    BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT,
    BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH,
    BATTLE_ROOM_RESULTS_STATE_FADE_OUT,
    BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_OUT,
    BATTLE_ROOM_RESULTS_STATE_TEARDOWN,
};

BOOL BattleRoomResults_Main(OverlayManager *man, int *state) {
    BattleRoomResults *results = OverlayManager_GetData(man);

    switch (*state) {
    case BATTLE_ROOM_RESULTS_STATE_SETUP:
        if (BattleRoomResults_SetupScreens(results)) {
            *state = BATTLE_ROOM_RESULTS_STATE_FADE_IN;
        }
        break;
    case BATTLE_ROOM_RESULTS_STATE_FADE_IN:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, results->heapID);
        *state = BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_IN;
        break;
    case BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            if (!results->showLeaders) {
                *state = BATTLE_ROOM_RESULTS_STATE_RESULTS_INPUT;
            } else {
                *state = BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT;
            }
        }
        break;
    case BATTLE_ROOM_RESULTS_STATE_RESULTS_INPUT:
        *state = BattleRoomResults_HandleResultsInput(results);
        break;
    case BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT:
        *state = BattleRoomResults_HandleLeadersInput(results);
        break;
    case BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH:
        if (!BattleRoomResults_UpdateButtonFlash(results)) {
            *state = results->nextState;
        }
        break;
    case BATTLE_ROOM_RESULTS_STATE_FADE_OUT:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, results->heapID);
        *state = BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_OUT;
        break;
    case BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            *state = BATTLE_ROOM_RESULTS_STATE_TEARDOWN;
        }
        break;
    case BATTLE_ROOM_RESULTS_STATE_TEARDOWN:
        if (BattleRoomResults_TeardownScreens(results)) {
            return TRUE;
        }
        break;
    }

    if (*state >= BATTLE_ROOM_RESULTS_STATE_FADE_IN && *state <= BATTLE_ROOM_RESULTS_STATE_WAIT_FADE_OUT) {
        BattleRoomResults_UpdateSprites(results);
    }
    return FALSE;
}

static BOOL BattleRoomResults_SetupScreens(BattleRoomResults *results) {
    switch (results->subState) {
    case BATTLE_ROOM_RESULTS_SETUP_INIT_BGS:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        reg_GXS_DB_DISPCNT = ~REG_GXS_DB_DISPCNT_DISPLAY_MASK & reg_GXS_DB_DISPCNT;
        reg_GX_POWCNT = ~REG_GX_POWCNT_DSEL_MASK & reg_GX_POWCNT;
        BattleRoomResults_SetGfxBanks();
        ResetVisibleHardwareWindows(PM_LCD_TOP);
        ResetVisibleHardwareWindows(PM_LCD_BOTTOM);
        BattleRoomResults_InitBgs(results);
        break;
    case BATTLE_ROOM_RESULTS_SETUP_LOAD_BG_GFX:
        BattleRoomResults_LoadBgGraphics(results);
        BattleRoomResults_InitStrings(results);
        break;
    case BATTLE_ROOM_RESULTS_SETUP_INIT_SPRITES:
        BattleRoomResults_InitSprites(results);
        break;
    case BATTLE_ROOM_RESULTS_SETUP_CREATE_SCREENS:
        BattleRoomResults_AddWindows(results);
        if (!results->showLeaders) {
            BattleRoomResults_PrintResults(results);
        } else {
            BattleRoomResults_LoadLeaders(results);
            BattleRoomResults_PrintLeadersScreen(results);
            BattleRoomResults_LeadersDummy(results);
            BattleRoomResults_CreateGridInput(results);
        }
        break;
    case BATTLE_ROOM_RESULTS_SETUP_START_VBLANK:
        Main_SetVBlankIntrCB((GFIntrCB)BattleRoomResults_VBlankCB, results);
        results->subState = BATTLE_ROOM_RESULTS_SETUP_INIT_BGS;
        return TRUE;
    }
    results->subState++;
    return FALSE;
}

static BOOL BattleRoomResults_TeardownScreens(BattleRoomResults *results) {
    switch (results->subState) {
    case BATTLE_ROOM_RESULTS_TEARDOWN_FREE:
        if (results->showLeaders) {
            BattleRoomResults_FreeGridInput(results);
            BattleRoomResults_FreeLeaderNames(results);
        }
        BattleRoomResults_FreeSprites(results);
        BattleRoomResults_RemoveWindows(results);
        BattleRoomResults_FreeStrings(results);
        BattleRoomResults_FreeBgs(results);
        break;
    case BATTLE_ROOM_RESULTS_TEARDOWN_RESET_DISPLAY:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
        results->subState = BATTLE_ROOM_RESULTS_TEARDOWN_FREE;
        return TRUE;
    }
    results->subState++;
    return FALSE;
}

static void BattleRoomResults_SetGfxBanks(void) {
    GraphicsBanks banks = sBattleRoomResultsGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void BattleRoomResults_VBlankCB(BattleRoomResults *results) {
    BattleRoomResults_TransferOam();
    DoScheduledBgGpuUpdates(results->bgConfig);
    ((u32 *)0x027E0000)[(HW_INTR_CHECK_BUF - HW_DTCM) / 4] |= OS_IE_V_BLANK; // OS_SetIrqCheckFlag
}

static int BattleRoomResults_HandleResultsInput(BattleRoomResults *results) {
    if (TouchscreenHitbox_TouchNewIsIn(sBattleRoomResultsHitbox) == TRUE || (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B))) {
        PlaySE(SEQ_SE_DP_DECIDE);
        BattleRoomResults_StartExitButtonFlash(results);
        results->nextState = BATTLE_ROOM_RESULTS_STATE_FADE_OUT;
        return BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH;
    }
    return BATTLE_ROOM_RESULTS_STATE_RESULTS_INPUT;
}

static int BattleRoomResults_HandleLeadersInput(BattleRoomResults *results) {
    switch ((u32)GridInputHandler_HandleInput_NoHold(results->gridInput)) {
    case BATTLE_ROOM_RESULTS_CANCEL:
    case GRID_MENU_CANCEL:
        PlaySE(SEQ_SE_DP_DECIDE);
        BattleRoomResults_StartExitButtonFlash(results);
        results->nextState = BATTLE_ROOM_RESULTS_STATE_FADE_OUT;
        return BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH;
    case GRID_MENU_CURSOR_MOVE:
        PlaySE(SEQ_SE_DP_SELECT);
        if (results->pageChange == 1) {
            BattleRoomResults_StartSpriteFlash(results, 2);
            results->nextState = BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT;
            return BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH;
        } else if (results->pageChange == 2) {
            BattleRoomResults_StartSpriteFlash(results, 3);
            results->nextState = BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT;
            return BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH;
        }
        break;
    case GRID_MENU_BUTTON_MODE:
    case GRID_MENU_NOTHING_CHOSEN:
        break;
    default:
        if (System_GetTouchNew() == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        break;
    }
    switch (TouchscreenHitbox_FindRectAtTouchNew(sBattleRoomResultsPageHitboxes)) {
    case 0:
        if (results->page) {
            results->page--;
        } else {
            results->page = BATTLE_ROOM_RESULTS_NUM_PAGES - 1;
        }
        PlaySE(SEQ_SE_DP_SELECT78);
        BattleRoomResults_PrintLeaderNames(results);
        BattleRoomResults_PrintLeaderInfo(results, results->page * BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE + GridInputHandler_GetNextInput(results->gridInput));
        BattleRoomResults_PrintPageNumber(results);
        BattleRoomResults_StartSpriteFlash(results, 2);
        results->nextState = BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT;
        return BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH;
    case 1:
        if (results->page < BATTLE_ROOM_RESULTS_NUM_PAGES - 1) {
            results->page++;
        } else {
            results->page = 0;
        }
        PlaySE(SEQ_SE_DP_SELECT78);
        BattleRoomResults_PrintLeaderNames(results);
        BattleRoomResults_PrintLeaderInfo(results, results->page * BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE + GridInputHandler_GetNextInput(results->gridInput));
        BattleRoomResults_PrintPageNumber(results);
        BattleRoomResults_StartSpriteFlash(results, 3);
        results->nextState = BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT;
        return BATTLE_ROOM_RESULTS_STATE_BUTTON_FLASH;
    }
    return BATTLE_ROOM_RESULTS_STATE_LEADERS_INPUT;
}

static void BattleRoomResults_InitBgs(BattleRoomResults *results) {
    GraphicsModes modes;
    BgTemplate bg0;
    BgTemplate bg1;
    BgTemplate bg4;
    BgTemplate bg5;

    results->bgConfig = BgConfig_Alloc(results->heapID);
    modes = sBattleRoomResultsGraphicsModes;
    SetBothScreensModesAndDisable(&modes);
    bg0 = sBattleRoomResultsBgTemplate_Main0;
    InitBgFromTemplate(results->bgConfig, GF_BG_LYR_MAIN_0, &bg0, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, results->heapID);
    BgClearTilemapBufferAndCommit(results->bgConfig, GF_BG_LYR_MAIN_0);
    bg1 = sBattleRoomResultsBgTemplate_Main1;
    InitBgFromTemplate(results->bgConfig, GF_BG_LYR_MAIN_1, &bg1, GF_BG_TYPE_TEXT);
    bg4 = sBattleRoomResultsBgTemplate_Sub0;
    InitBgFromTemplate(results->bgConfig, GF_BG_LYR_SUB_0, &bg4, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, results->heapID);
    BgClearTilemapBufferAndCommit(results->bgConfig, GF_BG_LYR_SUB_0);
    bg5 = sBattleRoomResultsBgTemplate_Sub1;
    InitBgFromTemplate(results->bgConfig, GF_BG_LYR_SUB_1, &bg5, GF_BG_TYPE_TEXT);
}

static void BattleRoomResults_FreeBgs(BattleRoomResults *results) {
    FreeBgTilemapBuffer(results->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(results->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(results->bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(results->bgConfig, GF_BG_LYR_MAIN_0);
    Heap_Free(results->bgConfig);
}

static void BattleRoomResults_LoadBgGraphics(BattleRoomResults *results) {
    NARC *narc;

    if (!results->showLeaders) {
        narc = NARC_New(NARC_a_1_1_8, results->heapID);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 4, results->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, results->heapID);
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 7, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x20, results->heapID);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, results->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, results->heapID);
        NARC_Delete(narc);
        narc = NARC_New(NARC_a_1_8_3, results->heapID);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 142, results->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, results->heapID);
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 196, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x20, results->heapID);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 141, results->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, results->heapID);
        NARC_Delete(narc);
    } else {
        narc = NARC_New(NARC_a_1_1_8, results->heapID);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 4, results->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, results->heapID);
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 7, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x20, results->heapID);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 5, results->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, results->heapID);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 8, results->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, results->heapID);
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 10, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x20, results->heapID);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 9, results->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, results->heapID);
        NARC_Delete(narc);
    }
}

static void BattleRoomResults_AddWindows(BattleRoomResults *results) {
    if (!results->showLeaders) {
        const WindowTemplate *template = sBattleRoomResultsWindowTemplates;
        Window *window;
        int i = 0;
        window = results->windows;
        do {
            AddWindow(results->bgConfig, window, template);
            i++;
            template ++;
            window++;
        } while (i < BATTLE_ROOM_RESULTS_NUM_RESULT_WINDOWS);
    } else {
        const WindowTemplate *template = sBattleRoomResultsLeaderWindowTemplates;
        Window *window;
        int i = 0;
        window = results->windows;
        do {
            AddWindow(results->bgConfig, window, template);
            FillWindowPixelBuffer(window, 0);
            i++;
            template ++;
            window++;
        } while (i < BATTLE_ROOM_RESULTS_NUM_LEADER_WINDOWS);
    }
    FontID_Alloc(4, results->heapID);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, results->heapID);
    LoadFontPal0(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_15_OFFSET, results->heapID);
}

static void BattleRoomResults_RemoveWindows(BattleRoomResults *results) {
    int i;
    int numWindows;
    Window *window;

    FontID_Release(4);
    if (results->showLeaders == FALSE) {
        numWindows = BATTLE_ROOM_RESULTS_NUM_RESULT_WINDOWS;
    } else {
        numWindows = BATTLE_ROOM_RESULTS_NUM_LEADER_WINDOWS;
    }
    i = 0;
    if (numWindows > 0) {
        window = results->windows;
        do {
            ClearWindowTilemapAndCopyToVram(window);
            RemoveWindow(window);
            i++;
            window++;
        } while (i < numWindows);
    }
}

static void BattleRoomResults_InitStrings(BattleRoomResults *results) {
    results->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0028_bin, results->heapID);
    results->msgFormat = MessageFormat_New_Custom(2, 64, results->heapID);
    results->string = String_New(512, results->heapID);
    results->defaultNames[0] = NewString_ReadMsgData(results->msgData, msg_0028_00033);
    results->defaultNames[1] = NewString_ReadMsgData(results->msgData, msg_0028_00034);
}

static void BattleRoomResults_FreeStrings(BattleRoomResults *results) {
    String_Delete(results->defaultNames[1]);
    String_Delete(results->defaultNames[0]);
    String_Delete(results->string);
    MessageFormat_Delete(results->msgFormat);
    DestroyMsgData(results->msgData);
}

static void BattleRoomResults_PrintString(Window *window, String *string, u32 x, int y, int fontId, u32 color, int alignment) {
    if (alignment == 1) {
        x -= FontID_String_GetWidth(fontId, string, 0);
    } else if (alignment == 2) {
        x -= FontID_String_GetWidth(fontId, string, 0) >> 1;
    }
    ((u8(*)(Window *, u32, String *, u32, u32, u32, u32, PrinterCallback_t))AddTextPrinterParameterizedWithColor)(window, fontId, string, x, y, TEXT_SPEED_NOTRANSFER, color, NULL);
}

static void BattleRoomResults_PrintMessage(BattleRoomResults *results, int windowIndex, int msgId, u32 x, int y, int fontId, u32 color, int alignment) {
    String *string = NewString_ReadMsgData(results->msgData, msgId);

    BattleRoomResults_PrintString(&results->windows[windowIndex], string, x, y, fontId, color, alignment);
    String_Delete(string);
}

static void BattleRoomResults_PrintFormattedMessage(BattleRoomResults *results, int windowIndex, int msgId, u32 x, int y, int fontId, u32 color, int alignment) {
    String *string = NewString_ReadMsgData(results->msgData, msgId);

    StringExpandPlaceholders(results->msgFormat, results->string, string);
    BattleRoomResults_PrintString(&results->windows[windowIndex], results->string, x, y, fontId, color, alignment);
    String_Delete(string);
}

static void BattleRoomResults_PrintTitle(BattleRoomResults *results) {
    int width = GetWindowWidth(&results->windows[0]);
    BattleRoomResults_PrintMessage(results, 0, msg_0028_00024, (width * 8) / 2, 0, 4, MAKE_TEXT_COLOR(15, 1, 0), 2);
}

static void BattleRoomResults_PrintResults(BattleRoomResults *results) {
    u32 i;
    u32 j;
    u8 width;

    for (i = 0; i < BATTLE_ROOM_RESULTS_NUM_RESULT_WINDOWS; i++) {
        FillWindowPixelBuffer(&results->windows[i], 0);
    }
    BattleRoomResults_PrintTitle(results);
    width = GetWindowWidth(&results->windows[1]);
    BattleRoomResults_PrintMessage(results, 1, msg_0028_00002, (width * 8) / 2, 0, 0, MAKE_TEXT_COLOR(15, 2, 0), 2);
    BattleRoomResults_PrintMessage(results, 2, msg_0028_00005, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    BattleRoomResults_PrintMessage(results, 3, msg_0028_00008, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    BattleRoomResults_PrintMessage(results, 4, msg_0028_00012, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    if (FrontierData_FlagAction(results->frontierData, 12, FRONTIER_DATA_GET) == 0) {
        BattleRoomResults_PrintMessage(results, 6, msg_0028_00009, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    } else {
        BattleRoomResults_PrintMessage(results, 6, msg_0028_00010, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    }
    BattleRoomResults_PrintMessage(results, 8, msg_0028_00011, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    BufferIntegerAsString(results->msgFormat, 0, FrontierData_WifiRankAction(results->frontierData, FRONTIER_DATA_GET), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BattleRoomResults_PrintFormattedMessage(results, 5, msg_0028_00014, GetWindowWidth(&results->windows[5]) * 8, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 1);
    BufferIntegerAsString(results->msgFormat, 0, FrontierSave_GetStat(results->frontierSave, 9, FRONTIER_STAT_NO_FRIEND), 4, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    width = GetWindowWidth(&results->windows[7]);
    BattleRoomResults_PrintFormattedMessage(results, 7, msg_0028_00015, (width * 8) / 2, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 2);
    BufferIntegerAsString(results->msgFormat, 0, FrontierSave_GetStat(results->frontierSave, 8, FRONTIER_STAT_NO_FRIEND), 4, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    width = GetWindowWidth(&results->windows[9]);
    BattleRoomResults_PrintFormattedMessage(results, 9, msg_0028_00015, (width * 8) / 2, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 2);
    for (j = 0; j < BATTLE_ROOM_RESULTS_NUM_RESULT_WINDOWS; j++) {
        ScheduleWindowCopyToVram(&results->windows[j]);
    }
}

static void BattleRoomResults_LoadLeaders(BattleRoomResults *results) {
    struct {
        int index;
        BattleRoomLeader *records;
    } query;

    BattleRoomResultsLeader *leader;
    BattleRoomLeader *record;
    u8 *nameRecord;

    query.records = BattleRoomDownload_CopyLeaders(results->downloadData, results->heapID);
    query.index = 0;
    leader = results->leaders;
    record = query.records;
    nameRecord = (u8 *)query.records;
    for (; query.index < BATTLE_ROOM_RESULTS_NUM_LEADERS; leader++, record++, nameRecord += sizeof(BattleRoomLeader), query.index++) {
        leader->gender = record->gender;
        leader->country = record->country;
        leader->region = record->region;
        leader->useDefaultName = record->useDefaultName;
        MI_CpuCopy8(record->greeting, &leader->greeting, sizeof(MailMessage));
        leader->name = String_New(PLAYER_NAME_LENGTH + 1, results->heapID);
        if (leader->useDefaultName) {
            String_Copy(leader->name, results->defaultNames[leader->gender]);
        } else {
            CopyU16ArrayToString(leader->name, (const u16 *)nameRecord);
        }
    }
    Heap_Free(query.records);
}

static void BattleRoomResults_FreeLeaderNames(BattleRoomResults *results) {
    int i;

    for (i = 0; i < BATTLE_ROOM_RESULTS_NUM_LEADERS; i++) {
        String_Delete(results->leaders[i].name);
    }
}

static void BattleRoomResults_PrintLeaderNames(BattleRoomResults *results) {
    u16 leader;
    Window *windows;
    u16 i;

    if (results->nameWindowSet == 0) {
        windows = &results->windows[11];
    } else {
        windows = &results->windows[23];
    }
    leader = results->page * BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE;
    for (i = 0; i < BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE; leader++, i++) {
        FillWindowPixelBuffer(&windows[i], 0);
        if (leader < BATTLE_ROOM_RESULTS_NUM_LEADERS) {
            u32 color;
            if (results->leaders[leader].gender == 0) {
                color = MAKE_TEXT_COLOR(7, 8, 0);
            } else {
                color = MAKE_TEXT_COLOR(3, 4, 0);
            }
            BattleRoomResults_PrintString(&windows[i], results->leaders[leader].name, 0, 0, 0, color, 0);
        }
        ScheduleWindowCopyToVram(&windows[i]);
    }
    results->nameWindowSet ^= 1;
}

static void BattleRoomResults_PrintPageNumber(BattleRoomResults *results) {
    FillWindowPixelBuffer(&results->windows[4], 0);
    BufferIntegerAsString(results->msgFormat, 0, results->page + 1, 1, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BattleRoomResults_PrintFormattedMessage(results, 4, msg_0028_00020, 8, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 1);
    BattleRoomResults_PrintMessage(results, 4, msg_0028_00021, 16, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 2);
    BufferIntegerAsString(results->msgFormat, 0, BATTLE_ROOM_RESULTS_NUM_PAGES, 1, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BattleRoomResults_PrintFormattedMessage(results, 4, msg_0028_00020, 24, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
    ScheduleWindowCopyToVram(&results->windows[4]);
}

static void BattleRoomResults_PrintLeadersScreen(BattleRoomResults *results) {
    u32 i;
    Window *window;
    Window *window2;
    u32 j;
    u8 values[4];

    for (i = 0, window = results->windows; i <= 3; i++, window++) {
        FillWindowPixelBuffer(window, 0);
    }
    BattleRoomResults_PrintTitle(results);
    BattleRoomDownload_GetLeadersRoom(results->downloadData, values);
    BufferIntegerAsString(results->msgFormat, 0, values[0], 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BattleRoomResults_PrintFormattedMessage(results, 1, msg_0028_00017, 0, 0, 0, MAKE_TEXT_COLOR(15, 2, 0), 0);
    BufferIntegerAsString(results->msgFormat, 1, values[1], 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BattleRoomResults_PrintFormattedMessage(results, 2, msg_0028_00018, 60, 0, 0, MAKE_TEXT_COLOR(15, 2, 0), 2);
    BattleRoomResults_PrintMessage(results, 3, msg_0028_00019, 0, 0, 0, MAKE_TEXT_COLOR(15, 2, 0), 0);
    for (j = 0, window2 = results->windows; j <= 3; j++, window2++) {
        ScheduleWindowCopyToVram(window2);
    }
    BattleRoomResults_PrintLeaderNames(results);
    BattleRoomResults_PrintLeaderInfo(results, 0);
    BattleRoomResults_PrintPageNumber(results);
}

// Shows the selected leader's name, home country and region and greeting in the free set of info windows.
static void BattleRoomResults_PrintLeaderInfo(BattleRoomResults *results, int leader) {
    u32 windowIndex;
    Window *windows;
    u16 i;

    if (results->infoWindowSet == 0) {
        windowIndex = 5;
    } else {
        windowIndex = 8;
    }
    windows = &results->windows[windowIndex];
    for (i = 0; i < 3; i++) {
        FillWindowPixelBuffer(&windows[i], 0);
    }
    if ((u32)leader < BATTLE_ROOM_RESULTS_NUM_LEADERS) {
        String *string;

        BufferString(results->msgFormat, 0, results->leaders[leader].name, results->leaders[leader].gender, 1, 2);
        if (results->leaders[leader].gender == 0) {
            BattleRoomResults_PrintFormattedMessage(results, windowIndex, msg_0028_00022, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        } else {
            BattleRoomResults_PrintFormattedMessage(results, windowIndex, msg_0028_00023, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        }
        BattleRoomResults_PrintMessage(results, windowIndex + 1, msg_0028_00028, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        if (results->leaders[leader].country == 0) {
            BattleRoomResults_PrintMessage(results, windowIndex + 1, msg_0028_00031, 0, 16, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        } else {
            BufferCountryName(results->msgFormat, 0, results->leaders[leader].country);
            BattleRoomResults_PrintFormattedMessage(results, windowIndex + 1, msg_0028_00029, 0, 16, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        }
        if (results->leaders[leader].region != 0) {
            BufferCityName(results->msgFormat, 0, results->leaders[leader].country, results->leaders[leader].region);
            BattleRoomResults_PrintFormattedMessage(results, windowIndex + 1, msg_0028_00030, 0, 32, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        }
        BattleRoomResults_PrintMessage(results, windowIndex + 2, msg_0028_00032, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        string = MailMsg_GetExpandedString(&results->leaders[leader].greeting, results->heapID);
        BattleRoomResults_PrintString(&windows[2], string, 0, 16, 0, MAKE_TEXT_COLOR(1, 2, 0), 0);
        String_Delete(string);
    }
    for (i = 0; i < 3; i++) {
        ScheduleWindowCopyToVram(&windows[i]);
    }
    results->infoWindowSet ^= 1;
}

static void BattleRoomResults_LeadersDummy(BattleRoomResults *results) {
}

static void BattleRoomResults_InitSprites(BattleRoomResults *results) {
    OamManagerParam oamParam;
    OamCharTransferParam charTransferParam;
    SpriteResourceCountsListUnion resourceCounts;
    NARC *narc;
    u32 i;

    results->spriteSystem = SpriteSystem_Alloc(results->heapID);
    results->spriteManager = SpriteManager_New(results->spriteSystem);
    oamParam = sBattleRoomResultsOamManagerParam;
    charTransferParam = sBattleRoomResultsOamCharTransferParam;
    SpriteSystem_Init(results->spriteSystem, &oamParam, &charTransferParam, 32);
    SpriteSystem_InitSprites(results->spriteSystem, results->spriteManager, 4);
    resourceCounts = sBattleRoomResultsSpriteResourceCounts;
    SpriteSystem_InitManagerWithCapacities(results->spriteSystem, results->spriteManager, &resourceCounts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(results->spriteSystem), 0, FX32_CONST(512));
    narc = NARC_New(NARC_a_1_1_8, results->heapID);
    SpriteSystem_LoadCharResObjFromOpenNarc(results->spriteSystem, results->spriteManager, narc, 0, TRUE, NNS_G2D_VRAM_TYPE_2DMAIN, 0xD158);
    SpriteSystem_LoadPlttResObjFromOpenNarc(results->spriteSystem, results->spriteManager, narc, 3, FALSE, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 0xD158);
    SpriteSystem_LoadCellResObjFromOpenNarc(results->spriteSystem, results->spriteManager, narc, 1, TRUE, 0xD158);
    SpriteSystem_LoadAnimResObjFromOpenNarc(results->spriteSystem, results->spriteManager, narc, 2, TRUE, 0xD158);
    NARC_Delete(narc);
    for (i = 0; i < 4; i++) {
        results->sprites[i] = SpriteSystem_NewSprite(results->spriteSystem, results->spriteManager, &sBattleRoomResultsSpriteTemplates[i]);
    }
    if (!results->showLeaders) {
        ManagedSprite_SetDrawFlag(results->sprites[2], FALSE);
        ManagedSprite_SetDrawFlag(results->sprites[3], FALSE);
    }
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

static void BattleRoomResults_FreeSprites(BattleRoomResults *results) {
    u32 i;

    for (i = 0; i < 4; i++) {
        if (results->sprites[i]) {
            Sprite_DeleteAndFreeResources(results->sprites[i]);
            results->sprites[i] = NULL;
        }
    }
    SpriteSystem_FreeResourcesAndManager(results->spriteSystem, results->spriteManager);
    SpriteSystem_Free(results->spriteSystem);
}

static void BattleRoomResults_UpdateSprites(BattleRoomResults *results) {
    u32 i;

    for (i = 0; i < 4; i++) {
        ManagedSprite_TickFrame(results->sprites[i]);
    }
    SpriteSystem_DrawSprites(results->spriteManager);
}

static void BattleRoomResults_TransferOam(void) {
    SpriteSystem_TransferOam();
}

static void BattleRoomResults_SetSpriteAnim(BattleRoomResults *results, int index, int anim) {
    ManagedSprite_SetAnimationFrame(results->sprites[index], 0);
    ManagedSprite_SetAnim(results->sprites[index], anim);
}

static void BattleRoomResults_SetSpritePosition(BattleRoomResults *results, int index, s16 x, s16 y) {
    ManagedSprite_SetPositionXY(results->sprites[index], x, y);
}

static BOOL BattleRoomResults_UpdateButtonFlash(BattleRoomResults *results) {
    switch (results->flash.state) {
    case BATTLE_ROOM_RESULTS_FLASH_PRESS:
        if (!results->flash.isBgRect) {
            ManagedSprite_SetPaletteOverride(results->sprites[results->flash.target], results->flash.pressedPltt);
        } else {
            BgTilemapRectChangePalette(results->bgConfig, results->flash.target, results->flash.x, results->flash.y, results->flash.width, results->flash.height, results->flash.pressedPltt);
            ScheduleBgTilemapBufferTransfer(results->bgConfig, results->flash.target);
        }
        results->flash.state++;
        break;
    case BATTLE_ROOM_RESULTS_FLASH_RELEASE:
        results->flash.timer++;
        if (results->flash.timer == 4) {
            if (!results->flash.isBgRect) {
                ManagedSprite_SetPaletteOverride(results->sprites[results->flash.target], results->flash.normalPltt);
            } else {
                BgTilemapRectChangePalette(results->bgConfig, results->flash.target, results->flash.x, results->flash.y, results->flash.width, results->flash.height, results->flash.normalPltt);
                ScheduleBgTilemapBufferTransfer(results->bgConfig, results->flash.target);
            }
            results->flash.timer = 0;
            results->flash.state++;
        }
        break;
    case BATTLE_ROOM_RESULTS_FLASH_WAIT:
        results->flash.timer++;
        if (results->flash.timer == 2) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

static void BattleRoomResults_StartSpriteFlash(BattleRoomResults *results, int sprite) {
    results->flash.isBgRect = FALSE;
    results->flash.target = sprite;
    results->flash.pressedPltt = 1;
    results->flash.normalPltt = 0;
    results->flash.state = BATTLE_ROOM_RESULTS_FLASH_PRESS;
    results->flash.timer = 0;
}

static void BattleRoomResults_StartExitButtonFlash(BattleRoomResults *results) {
    BattleRoomResults_StartSpriteFlash(results, 1);
}

static void BattleRoomResults_CreateGridInput(BattleRoomResults *results) {
    results->gridInput = GridInputHandler_Create(sBattleRoomResultsGridHitboxes, sBattleRoomResultsGridDpadBoxes, &sBattleRoomResultsGridCallbacks, results, TRUE, 0, results->heapID);
    BattleRoomResults_MoveCursor(results, 0);
}

static void BattleRoomResults_FreeGridInput(BattleRoomResults *results) {
    GridInputHandler_Free(results->gridInput);
}

static void BattleRoomResults_MoveCursor(BattleRoomResults *results, int input) {
    u8 position[2];
    const DpadMenuBox *box = GridInputHandler_GetDpadBox(results->gridInput, input);

    DpadMenuBox_GetPosition(box, &position[1], &position[0]);
    BattleRoomResults_SetSpritePosition(results, 0, position[1], position[0]);
    if (input == BATTLE_ROOM_RESULTS_CANCEL) {
        BattleRoomResults_SetSpriteAnim(results, 0, 2);
    } else {
        BattleRoomResults_SetSpriteAnim(results, 0, 7);
    }
}

static void BattleRoomResults_GridNoop(void *data, int newInput, int prevInput) {
}

// Grid key move: moving off the left/right edge of the 3x4 name grid turns the page.
static void BattleRoomResults_GridOnKeyMove(void *data, int newInput, int prevInput) {
    BattleRoomResults *results = data;

    results->pageChange = 0;
    if ((newInput == 2 && prevInput == 0) || (newInput == 5 && prevInput == 3) || (newInput == 8 && prevInput == 6) || (newInput == 11 && prevInput == 9)) {
        if (results->page != 0) {
            results->page--;
        } else {
            results->page = BATTLE_ROOM_RESULTS_NUM_PAGES - 1;
        }
        BattleRoomResults_PrintLeaderNames(results);
        BattleRoomResults_PrintPageNumber(results);
        results->pageChange = 1;
    }
    if ((newInput == 0 && prevInput == 2) || (newInput == 3 && prevInput == 5) || (newInput == 6 && prevInput == 8) || (newInput == 9 && prevInput == 11)) {
        if (results->page < BATTLE_ROOM_RESULTS_NUM_PAGES - 1) {
            results->page++;
        } else {
            results->page = 0;
        }
        BattleRoomResults_PrintLeaderNames(results);
        BattleRoomResults_PrintPageNumber(results);
        results->pageChange = 2;
    }
    BattleRoomResults_PrintLeaderInfo(results, newInput == BATTLE_ROOM_RESULTS_CANCEL ? BATTLE_ROOM_RESULTS_NUM_LEADERS : newInput + BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE * results->page);
    BattleRoomResults_MoveCursor(results, newInput);
}

static void BattleRoomResults_GridOnTouch(void *data, int input, int prevInput) {
    BattleRoomResults *results = data;
    int leader;

    if (input == BATTLE_ROOM_RESULTS_CANCEL) {
        leader = BATTLE_ROOM_RESULTS_NUM_LEADERS;
    } else {
        leader = input + BATTLE_ROOM_RESULTS_LEADERS_PER_PAGE * results->page;
    }
    BattleRoomResults_PrintLeaderInfo(results, leader);
    BattleRoomResults_MoveCursor(results, input);
}
