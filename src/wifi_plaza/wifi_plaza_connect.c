#include "wifi_plaza/wifi_plaza_connect.h"

#include "global.h"

#include "constants/game_stats.h"
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0778.h"
#include "msgdata/msg/msg_0800.h"
#include "wifi_plaza/wifi_plaza_internal.h"

#include "bg_window.h"
#include "comm_state.h"
#include "filesystem.h"
#include "font.h"
#include "game_stats.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "gf_rtc.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "overlay_manager.h"
#include "palette.h"
#include "player_data.h"
#include "pm_string.h"
#include "render_window.h"
#include "save.h"
#include "screen_fade.h"
#include "sound_system.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"
#include "yes_no_prompt.h"

// Wi-Fi Plaza connect / disconnect screens: "Connect to Nintendo Wi-Fi Connection?" with login, error handling and
// reconnect, and "Disconnecting from Nintendo Wi-Fi Connection." with logout.

#define WIFI_PLAZA_CONNECT_NUM_BG_LAYERS     3
#define WIFI_PLAZA_CONNECT_NUM_PALETTES      21
#define WIFI_PLAZA_CONNECT_MSG_STRING_LENGTH 0x100

typedef struct WiFiPlazaConnectMessageBox {
    MessageFormat *format;
    MsgData *msgData;
    Window window;
    String *expanded;
    String *raw;
    int frameType; // 0: standard frame, 1: frame 2 with a waiting icon
    WaitingIcon *waitingIcon;
    int textSpeed;
    int printerId;
} WiFiPlazaConnectMessageBox;

// Block handed to the VBlank palette-cycle task.
typedef struct WiFiPlazaConnectPaletteCycle {
    SysTask *task;
    BOOL active;
    u16 baseColors[4][16];
    u16 blendedPalettes[WIFI_PLAZA_CONNECT_NUM_PALETTES][16];
    s16 index; // ping-pongs 0..20
    s8 direction;
    u8 frameParity; // the palette is loaded on every second frame
    u32 mode;       // 0: both screens, 1: main screen, 2: sub screen
} WiFiPlazaConnectPaletteCycle;

typedef struct WiFiPlazaConnectWork {
    SaveData *saveData;
    u32 unk_04;
    u32 timer;
    BgConfig *bgConfig;
    WiFiPlazaConnectMessageBox titleBox;  // msg_0778
    WiFiPlazaConnectMessageBox msgBox;    // msg_0778 when connecting, msg_0800 when disconnecting
    WiFiPlazaConnectMessageBox statusBox; // msg_0800
    WiFiPlazaConnectMessageBox errorBox;  // msg_0800
    YesNoPrompt *yesNoPrompt;
    WiFiPlazaConnectPaletteCycle paletteCycle;
} WiFiPlazaConnectWork;

extern void CommState_StartWifiPlaza(SaveData *saveData, const WiFiPlazaPlayer *player);
extern void CommState_LeaveWifiPlaza(void);
extern int CommState_HasPlazaLobbyStarted(void);
extern BOOL CommState_HasPlazaLobbyFailed(void);

enum WiFiPlazaConnectState {
    WIFI_PLAZA_CONNECT_FADE_IN,
    WIFI_PLAZA_CONNECT_WAIT_FADE_IN,
    WIFI_PLAZA_CONNECT_ASK_CONNECT,
    WIFI_PLAZA_CONNECT_HANDLE_CONNECT_PROMPT,
    WIFI_PLAZA_CONNECT_CONNECT,
    WIFI_PLAZA_CONNECT_WAIT_LOBBY_START,
    WIFI_PLAZA_CONNECT_WAIT_JOIN_LOBBY,
    WIFI_PLAZA_CONNECT_FADE_OUT,
    WIFI_PLAZA_CONNECT_WAIT_FADE_OUT,
    WIFI_PLAZA_CONNECT_SHOW_ERROR,
    WIFI_PLAZA_CONNECT_WAIT_ERROR_BUTTON,
    WIFI_PLAZA_CONNECT_ASK_RECONNECT,
    WIFI_PLAZA_CONNECT_HANDLE_RECONNECT_PROMPT,
    WIFI_PLAZA_CONNECT_WAIT_RECONNECT,
    WIFI_PLAZA_CONNECT_DISCONNECT,
    WIFI_PLAZA_CONNECT_WAIT_DISCONNECT,
};

enum WiFiPlazaDisconnectState {
    WIFI_PLAZA_DISCONNECT_FADE_IN,
    WIFI_PLAZA_DISCONNECT_WAIT_FADE_IN,
    WIFI_PLAZA_DISCONNECT_PRINT_DISCONNECTING,
    WIFI_PLAZA_DISCONNECT_ADD_OWN_LOCATION,
    WIFI_PLAZA_DISCONNECT_WAIT_OWN_LOCATION,
    WIFI_PLAZA_DISCONNECT_LEAVE,
    WIFI_PLAZA_DISCONNECT_WAIT_LEAVE,
    WIFI_PLAZA_DISCONNECT_PRINT_DISCONNECTED,
    WIFI_PLAZA_DISCONNECT_WAIT,
    WIFI_PLAZA_DISCONNECT_FADE_OUT,
    WIFI_PLAZA_DISCONNECT_WAIT_FADE_OUT,
};

static void WiFiPlazaConnect_VBlankCB(void *data);
static void WiFiPlazaConnect_InitGraphics(WiFiPlazaConnectWork *work, enum HeapID heapID);
static void WiFiPlazaConnect_PaletteCycleTask(SysTask *task, void *data);
static void WiFiPlazaConnect_FreeBgs(WiFiPlazaConnectWork *work);
static void WiFiPlazaConnect_DoBgUpdates(WiFiPlazaConnectWork *work);
static void WiFiPlazaConnect_InitMessageBox(WiFiPlazaConnectMessageBox *box, BgConfig *bgConfig, int frameType, int msgBank, int x, int y, int width, int height, int baseTile, SaveData *saveData, enum HeapID heapID);
static void WiFiPlazaConnect_PrintMessage(WiFiPlazaConnectMessageBox *box, int msgId);
static void WiFiPlazaConnect_ClearMessageBox(WiFiPlazaConnectMessageBox *box);
static void WiFiPlazaConnect_StartWaitingIcon(WiFiPlazaConnectMessageBox *box);
static void WiFiPlazaConnect_StopWaitingIcon(WiFiPlazaConnectMessageBox *box);
static void WiFiPlazaConnect_FreeMessageBox(WiFiPlazaConnectMessageBox *box);
static void WiFiPlazaConnect_PrintCenteredTitle(WiFiPlazaConnectMessageBox *box, int msgId);
static void WiFiPlazaConnect_BufferErrorCode(WiFiPlazaConnectMessageBox *box, int errorCode);
static YesNoPrompt *WiFiPlazaConnect_CreateYesNoPrompt(BgConfig *bgConfig, int tileStart);


static const u32 sWiFiPlazaConnectBgLayers[WIFI_PLAZA_CONNECT_NUM_BG_LAYERS] = { GF_BG_LYR_MAIN_0, GF_BG_LYR_MAIN_1, GF_BG_LYR_SUB_0 };

static const GraphicsModes sWiFiPlazaConnectGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const GraphicsBanks sWiFiPlazaConnectGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_128_B,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_NONE,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

static const BgTemplate sWiFiPlazaConnectBgTemplates[WIFI_PLAZA_CONNECT_NUM_BG_LAYERS] = {
    {
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
     .mosaic = FALSE,
     },
    {
     .x = 0,
     .y = 0,
     .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
     .baseTile = 0,
     .size = GF_BG_SCR_SIZE_256x256,
     .colorMode = GX_BG_COLORMODE_16,
     .screenBase = GX_BG_SCRBASE_0xe000,
     .charBase = GX_BG_CHARBASE_0x10000,
     .bgExtPltt = GX_BG_EXTPLTT_01,
     .priority = 0,
     .areaOver = GX_BG_AREAOVER_XLU,
     .dummy = 0,
     .mosaic = FALSE,
     },
    {
     .x = 0,
     .y = 0,
     .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
     .baseTile = 0,
     .size = GF_BG_SCR_SIZE_256x256,
     .colorMode = GX_BG_COLORMODE_16,
     .screenBase = GX_BG_SCRBASE_0xe800,
     .charBase = GX_BG_CHARBASE_0x00000,
     .bgExtPltt = GX_BG_EXTPLTT_01,
     .priority = 0,
     .areaOver = GX_BG_AREAOVER_XLU,
     .dummy = 0,
     .mosaic = FALSE,
     },
};

BOOL WiFiPlazaConnect_Init(OverlayManager *man, int *state) {
    WiFiPlazaConnectArgs *args;
    WiFiPlazaConnectWork *work;

    Heap_Create(HEAP_ID_3, HEAP_ID_119, 0x20000);
    work = OverlayManager_CreateAndGetData(man, sizeof(WiFiPlazaConnectWork), HEAP_ID_119);
    memset(work, 0, sizeof(WiFiPlazaConnectWork));
    args = OverlayManager_GetArgs(man);
    work->saveData = args->saveData;
    Sound_SetSceneAndPlayBGM(11, SEQ_GS_WIFI_ACCESS, 0);
    args->connected = FALSE;
    WiFiPlazaConnect_InitGraphics(work, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->msgBox, work->bgConfig, 1, NARC_msg_msg_0778_bin, 2, 19, 27, 4, 0x28, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->statusBox, work->bgConfig, 1, NARC_msg_msg_0800_bin, 2, 19, 27, 4, 0x28, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->errorBox, work->bgConfig, 0, NARC_msg_msg_0800_bin, 4, 4, 23, 16, 0x94, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->titleBox, work->bgConfig, 1, NARC_msg_msg_0778_bin, 5, 1, 22, 2, 0x204, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_PrintCenteredTitle(&work->titleBox, msg_0778_00021);
    Main_SetVBlankIntrCB(WiFiPlazaConnect_VBlankCB, work);
    HBlankInterruptDisable();
    gSystem.screensFlipped = TRUE;
    GfGfx_SwapDisplay();
    return TRUE;
}

BOOL WiFiPlazaConnect_Main(OverlayManager *man, int *state) {
    WiFiPlazaConnectWork *work;
    WiFiPlazaConnectArgs *args;

    work = OverlayManager_GetData(man);
    args = OverlayManager_GetArgs(man);
    switch (*state) {
    case WIFI_PLAZA_CONNECT_FADE_IN:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0xFFFF, 6, 1, HEAP_ID_119);
        (*state)++;
        break;
    case WIFI_PLAZA_CONNECT_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case WIFI_PLAZA_CONNECT_ASK_CONNECT:
        if (!args->skipPrompt) {
            WiFiPlazaConnect_PrintMessage(&work->statusBox, msg_0800_00017);
            work->yesNoPrompt = WiFiPlazaConnect_CreateYesNoPrompt(work->bgConfig, 0x230);
            (*state)++;
        } else {
            *state = WIFI_PLAZA_CONNECT_CONNECT;
        }
        break;
    case WIFI_PLAZA_CONNECT_HANDLE_CONNECT_PROMPT: {
        YesNoResponse result = YesNoPrompt_HandleInput(work->yesNoPrompt);
        if (result == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(work->yesNoPrompt);
            *state = WIFI_PLAZA_CONNECT_CONNECT;
        } else if (result == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(work->yesNoPrompt);
            WiFiPlazaConnect_ClearMessageBox(&work->msgBox);
            *state = WIFI_PLAZA_CONNECT_FADE_OUT;
        }
        break;
    }
    case WIFI_PLAZA_CONNECT_CONNECT:
        CommState_StartWifiPlaza(work->saveData, WiFiPlazaWork_GetMyPlayer(args->work));
        WiFiPlazaConnect_PrintMessage(&work->statusBox, msg_0800_00023);
        WiFiPlazaConnect_StartWaitingIcon(&work->statusBox);
        (*state)++;
        break;
    case WIFI_PLAZA_CONNECT_WAIT_LOBBY_START:
        if (CommState_HasWifiFailed() || CommState_HasPlazaLobbyFailed()) {
            WiFiPlazaConnect_StopWaitingIcon(&work->statusBox);
            *state = WIFI_PLAZA_CONNECT_SHOW_ERROR;
        }
        if (CommState_HasPlazaLobbyStarted() == 1) {
            WiFiPlazaWork_NewPlayerInfo(args->work);
            (*state)++;
        }
        break;
    case WIFI_PLAZA_CONNECT_WAIT_JOIN_LOBBY:
        if (CommState_HasWifiFailed() || CommState_HasPlazaLobbyFailed()) {
            WiFiPlazaConnect_StopWaitingIcon(&work->statusBox);
            *state = WIFI_PLAZA_CONNECT_SHOW_ERROR;
        }
        if (CommState_IsWifiJoiningLobby()) {
            s64 seconds;
            WiFiPlazaConnect_StopWaitingIcon(&work->statusBox);
            GameStats_AddScore(Save_GameStats_Get(work->saveData), SCORE_EVENT_WIFI_PLAZA_ACCESSED);
            seconds = GF_RTC_DateTimeToSec();
            *args->loginTime = seconds;
            args->connected = TRUE;
            (*state)++;
        }
        break;
    case WIFI_PLAZA_CONNECT_SHOW_ERROR: {
        u32 errorCode;
        int msgId;
        if (CommState_HasWifiFailed()) {
            u32 *error = CommState_GetWifiError();
            msgId = WiFiPlaza_GetErrorMessageClass(error[0], error[1]);
            errorCode = error[0];
        } else {
            errorCode = WiFiPlazaLobbyClient_ToErrorCode(WiFiPlazaLobbyClient_GetLastError());
            msgId = msg_0800_00032;
        }
        WiFiPlazaWork_FreePlayerInfo(args->work);
        WiFiPlazaConnect_ClearMessageBox(&work->msgBox);
        WiFiPlazaConnect_ClearMessageBox(&work->statusBox);
        WiFiPlazaConnect_BufferErrorCode(&work->errorBox, errorCode);
        WiFiPlazaConnect_PrintMessage(&work->errorBox, msgId);
        (*state)++;
        break;
    }
    case WIFI_PLAZA_CONNECT_WAIT_ERROR_BUTTON:
        if ((gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) || System_GetTouchNew() == TRUE) {
            if (CommState_HasWifiFailed()) {
                u32 *error = CommState_GetWifiError();
                if (!WiFiPlaza_IsErrorRecoverable(error[0], error[1])) {
                    *state = WIFI_PLAZA_CONNECT_ASK_RECONNECT;
                } else {
                    *state = WIFI_PLAZA_CONNECT_DISCONNECT;
                }
            } else {
                *state = WIFI_PLAZA_CONNECT_ASK_RECONNECT;
            }
        }
        break;
    case WIFI_PLAZA_CONNECT_ASK_RECONNECT:
        WiFiPlazaConnect_ClearMessageBox(&work->errorBox);
        WiFiPlazaConnect_PrintMessage(&work->msgBox, msg_0778_00088);
        work->yesNoPrompt = WiFiPlazaConnect_CreateYesNoPrompt(work->bgConfig, 0x230);
        (*state)++;
        break;
    case WIFI_PLAZA_CONNECT_HANDLE_RECONNECT_PROMPT: {
        YesNoResponse result = YesNoPrompt_HandleInput(work->yesNoPrompt);
        if (result == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(work->yesNoPrompt);
            CommState_LeaveWifiPlaza();
            *state = WIFI_PLAZA_CONNECT_WAIT_RECONNECT;
        } else if (result == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(work->yesNoPrompt);
            *state = WIFI_PLAZA_CONNECT_DISCONNECT;
        }
        break;
    }
    case WIFI_PLAZA_CONNECT_WAIT_RECONNECT:
        if (!CommState_Exists()) {
            *state = WIFI_PLAZA_CONNECT_CONNECT;
        }
        break;
    case WIFI_PLAZA_CONNECT_DISCONNECT:
        WiFiPlazaConnect_ClearMessageBox(&work->msgBox);
        WiFiPlazaConnect_ClearMessageBox(&work->statusBox);
        WiFiPlazaConnect_ClearMessageBox(&work->errorBox);
        CommState_LeaveWifiPlaza();
        (*state)++;
        break;
    case WIFI_PLAZA_CONNECT_WAIT_DISCONNECT:
        if (!CommState_Exists()) {
            WiFiPlazaConnect_ClearMessageBox(&work->msgBox);
            WiFiPlazaConnect_ClearMessageBox(&work->statusBox);
            *state = WIFI_PLAZA_CONNECT_FADE_OUT;
        }
        break;
    case WIFI_PLAZA_CONNECT_FADE_OUT:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_119);
        (*state)++;
        break;
    case WIFI_PLAZA_CONNECT_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

BOOL WiFiPlazaConnect_Exit(OverlayManager *man, int *state) {
    WiFiPlazaConnectWork *work = OverlayManager_GetData(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    if (work->paletteCycle.task != NULL) {
        SysTask_Destroy(work->paletteCycle.task);
        work->paletteCycle.task = NULL;
        work->paletteCycle.active = FALSE;
    }
    WiFiPlazaConnect_FreeMessageBox(&work->msgBox);
    WiFiPlazaConnect_FreeMessageBox(&work->statusBox);
    WiFiPlazaConnect_FreeMessageBox(&work->errorBox);
    WiFiPlazaConnect_FreeMessageBox(&work->titleBox);
    WiFiPlazaConnect_FreeBgs(work);
    work->paletteCycle.active = FALSE;
    Heap_Free(work);
    Heap_Destroy(HEAP_ID_119);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    return TRUE;
}

BOOL WiFiPlazaConnect_DisconnectInit(OverlayManager *man, int *state) {
    WiFiPlazaConnectWork *work;
    WiFiPlazaDisconnectArgs *args;

    Heap_Create(HEAP_ID_3, HEAP_ID_119, 0x20000);
    work = OverlayManager_CreateAndGetData(man, sizeof(WiFiPlazaConnectWork), HEAP_ID_119);
    memset(work, 0, sizeof(WiFiPlazaConnectWork));
    args = OverlayManager_GetArgs(man);
    work->saveData = args->saveData;
    WiFiPlazaConnect_InitGraphics(work, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->msgBox, work->bgConfig, 1, NARC_msg_msg_0800_bin, 2, 19, 27, 4, 0x28, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->errorBox, work->bgConfig, 0, NARC_msg_msg_0800_bin, 4, 4, 23, 16, 0x94, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_InitMessageBox(&work->titleBox, work->bgConfig, 1, NARC_msg_msg_0778_bin, 5, 1, 22, 2, 0x204, work->saveData, HEAP_ID_119);
    WiFiPlazaConnect_PrintCenteredTitle(&work->titleBox, msg_0778_00021);
    WirelessStatusIcon_Create();
    Main_SetVBlankIntrCB(WiFiPlazaConnect_VBlankCB, work);
    HBlankInterruptDisable();
    gSystem.screensFlipped = TRUE;
    GfGfx_SwapDisplay();
    return TRUE;
}

BOOL WiFiPlazaConnect_DisconnectMain(OverlayManager *man, int *state) {
    WiFiPlazaConnectWork *work;
    WiFiPlazaDisconnectArgs *args;

    work = OverlayManager_GetData(man);
    args = OverlayManager_GetArgs(man);
    switch (*state) {
    case WIFI_PLAZA_DISCONNECT_FADE_IN:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0xFFFF, 6, 1, HEAP_ID_119);
        (*state)++;
        break;
    case WIFI_PLAZA_DISCONNECT_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            *state = WIFI_PLAZA_DISCONNECT_PRINT_DISCONNECTING;
        }
        break;
    case WIFI_PLAZA_DISCONNECT_PRINT_DISCONNECTING:
        WiFiPlazaConnect_PrintMessage(&work->msgBox, msg_0800_00026);
        if (CommState_HasWifiFailed() || CommState_HasPlazaLobbyFailed()) {
            *state = WIFI_PLAZA_DISCONNECT_LEAVE;
            WiFiPlazaConnect_StartWaitingIcon(&work->msgBox);
        } else {
            *state = WIFI_PLAZA_DISCONNECT_ADD_OWN_LOCATION;
            WiFiPlazaConnect_StartWaitingIcon(&work->msgBox);
        }
        break;
    case WIFI_PLAZA_DISCONNECT_ADD_OWN_LOCATION:
        WiFiPlazaLobbyClient_StartAddOwnLocation();
        work->timer = 900;
        *state = WIFI_PLAZA_DISCONNECT_WAIT_OWN_LOCATION;
        break;
    case WIFI_PLAZA_DISCONNECT_WAIT_OWN_LOCATION:
        --work->timer;
        if (WiFiPlazaLobbyClient_IsOwnLocationAdded() || work->timer == 0) {
            *state = WIFI_PLAZA_DISCONNECT_LEAVE;
        }
        break;
    case WIFI_PLAZA_DISCONNECT_LEAVE:
        CommState_LeaveWifiPlaza();
        *state = WIFI_PLAZA_DISCONNECT_WAIT_LEAVE;
        break;
    case WIFI_PLAZA_DISCONNECT_WAIT_LEAVE:
        if (!CommState_Exists()) {
            // the status box is not set up on this screen (frame type 0): this does nothing
            WiFiPlazaConnect_StopWaitingIcon(&work->statusBox);
            WiFiPlazaWork_FreePlayerInfo(args->work);
            *state = WIFI_PLAZA_DISCONNECT_PRINT_DISCONNECTED;
        }
        break;
    case WIFI_PLAZA_DISCONNECT_PRINT_DISCONNECTED:
        WiFiPlazaConnect_PrintMessage(&work->msgBox, msg_0800_00027);
        work->timer = 90;
        *state = WIFI_PLAZA_DISCONNECT_WAIT;
        break;
    case WIFI_PLAZA_DISCONNECT_WAIT:
        if (--work->timer == 0) {
            *state = WIFI_PLAZA_DISCONNECT_FADE_OUT;
        }
        break;
    case WIFI_PLAZA_DISCONNECT_FADE_OUT:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_119);
        (*state)++;
        break;
    case WIFI_PLAZA_DISCONNECT_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            WiFiPlazaConnect_StopWaitingIcon(&work->msgBox);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL WiFiPlazaConnect_DisconnectExit(OverlayManager *man, int *state) {
    WiFiPlazaConnectWork *work = OverlayManager_GetData(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    if (work->paletteCycle.task != NULL) {
        SysTask_Destroy(work->paletteCycle.task);
        work->paletteCycle.task = NULL;
        work->paletteCycle.active = FALSE;
    }
    WiFiPlazaConnect_FreeMessageBox(&work->msgBox);
    WiFiPlazaConnect_FreeMessageBox(&work->errorBox);
    WiFiPlazaConnect_FreeMessageBox(&work->titleBox);
    WiFiPlazaConnect_FreeBgs(work);
    work->paletteCycle.active = FALSE;
    Heap_Free(work);
    Heap_Destroy(HEAP_ID_119);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    return TRUE;
}

static void WiFiPlazaConnect_VBlankCB(void *data) {
    WiFiPlazaConnect_DoBgUpdates(data);
}

static void WiFiPlazaConnect_InitGraphics(WiFiPlazaConnectWork *work, enum HeapID heapID) {
    int i;
    int j;
    const BgTemplate *template;
    NARC *narc;
    int target;
    int count;
    int amount;
    BOOL final;
    u16 *dst;
    u16 *src;
    u8 blend;
    NNSG2dPaletteData *plttData;
    void *plttFile;
    u8 frame;

    G2_BlendNone();
    G2S_BlendNone();
    GfGfx_SetBanks(&sWiFiPlazaConnectGraphicsBanks);
    BG_SetMaskColor(GF_BG_LYR_MAIN_0, RGB_BLACK);
    SetBothScreensModesAndDisable(&sWiFiPlazaConnectGraphicsModes);
    work->bgConfig = BgConfig_Alloc(heapID);
    for (i = 0; i < WIFI_PLAZA_CONNECT_NUM_BG_LAYERS; i++) {
        template = &sWiFiPlazaConnectBgTemplates[i];
        InitBgFromTemplate(work->bgConfig, sWiFiPlazaConnectBgLayers[i], template, GF_BG_TYPE_TEXT);
        BG_ClearCharDataRange(sWiFiPlazaConnectBgLayers[i], 32, 0, heapID);
        BgClearTilemapBufferAndCommit(work->bgConfig, sWiFiPlazaConnectBgLayers[i]);
    }
    frame = Options_GetFrame(Save_PlayerData_GetOptionsAddr(work->saveData));
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_10_OFFSET, heapID);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_9_OFFSET, heapID);
    LoadUserFrameGfx1(work->bgConfig, GF_BG_LYR_MAIN_1, 31, 12, 0, heapID);
    LoadUserFrameGfx2(work->bgConfig, GF_BG_LYR_MAIN_1, 1, 11, frame, heapID);
    GfGfxLoader_GXLoadPal(NARC_a_0_8_8, 3, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x120, heapID);
    GfGfxLoader_GXLoadPal(NARC_a_0_8_8, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x120, heapID);
    GfGfxLoader_LoadCharData(NARC_a_0_8_8, 2, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapID);
    GfGfxLoader_LoadCharData(NARC_a_0_8_8, 11, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
    GfGfxLoader_LoadScrnData(NARC_a_0_8_8, 6, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapID);
    GfGfxLoader_LoadScrnData(NARC_a_0_8_8, 12, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, heapID);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    narc = NARC_New(NARC_a_0_8_8, heapID);
    MI_CpuFill8(&work->paletteCycle, 0, sizeof(WiFiPlazaConnectPaletteCycle));
    plttFile = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, &plttData, heapID);
    MIi_CpuCopy16(plttData->pRawData, work->paletteCycle.baseColors[0], sizeof(work->paletteCycle.baseColors));
    MIi_CpuCopy16(plttData->pRawData, work->paletteCycle.blendedPalettes[0], sizeof(work->paletteCycle.baseColors));
    Heap_Free(plttFile);

    // Blend each of the first three base palettes toward the next one in 6 steps (21 palettes).
    count = 0;
    target = 0;
    dst = work->paletteCycle.blendedPalettes[0];
    src = work->paletteCycle.baseColors[0];
    do {
        WiFiPlazaConnectWork *next;
        amount = 0;
        final = FALSE;
        next = (WiFiPlazaConnectWork *)((u8 *)work + (target + 1) * 32);
        while (TRUE) {
            GF_ASSERT(count < WIFI_PLAZA_CONNECT_NUM_PALETTES);
            for (j = 1; j < 16; j++) {
                u16 *srcColor = src + j;
                u16 *dstColor = dst + j;
                blend = amount >> 8;
                BlendPalette(srcColor, dstColor, 1, blend, next->paletteCycle.baseColors[0][j]);
            }
            dst += 16;
            count++;
            if (final == TRUE) {
                break;
            }
            amount += 0x300;
            if (amount >= 0x1000) {
                amount = 0x1000;
                final = TRUE;
            }
        }
        src += 16;
        target++;
    } while (target < 3);
    DC_FlushRange(work->paletteCycle.blendedPalettes, sizeof(work->paletteCycle.blendedPalettes));
    work->paletteCycle.active = TRUE;
    work->paletteCycle.mode = 0;
    work->paletteCycle.task = SysTask_CreateOnVBlankQueue(WiFiPlazaConnect_PaletteCycleTask, &work->paletteCycle, 20);
    NARC_Delete(narc);
}

static void WiFiPlazaConnect_PaletteCycleTask(SysTask *task, void *data) {
    WiFiPlazaConnectPaletteCycle *cycle = data;
    if (!cycle->active) {
        return;
    }
    cycle->frameParity ^= 1;
    if (cycle->frameParity & 1) {
        return;
    }
    if (cycle->mode <= 1) {
        GX_LoadBGPltt(cycle->blendedPalettes[cycle->index], 0, sizeof(cycle->blendedPalettes[0]));
    }
    if (cycle->mode == 0 || cycle->mode == 2) {
        GXS_LoadBGPltt(cycle->blendedPalettes[cycle->index], 0, sizeof(cycle->blendedPalettes[0]));
    }
    if (cycle->direction == 0) {
        cycle->index++;
        if (cycle->index >= WIFI_PLAZA_CONNECT_NUM_PALETTES) {
            cycle->index = WIFI_PLAZA_CONNECT_NUM_PALETTES - 2;
            cycle->direction ^= 1;
        }
    } else {
        cycle->index--;
        if (cycle->index < 0) {
            cycle->index = 1;
            cycle->direction ^= 1;
        }
    }
}

static void WiFiPlazaConnect_FreeBgs(WiFiPlazaConnectWork *work) {
    int i;
    for (i = 0; i < WIFI_PLAZA_CONNECT_NUM_BG_LAYERS; i++) {
        FreeBgTilemapBuffer(work->bgConfig, sWiFiPlazaConnectBgLayers[i]);
    }
    Heap_Free(work->bgConfig);
}

static void WiFiPlazaConnect_DoBgUpdates(WiFiPlazaConnectWork *work) {
    DoScheduledBgGpuUpdates(work->bgConfig);
}

static void WiFiPlazaConnect_InitMessageBox(WiFiPlazaConnectMessageBox *box, BgConfig *bgConfig, int frameType, int msgBank, int x, int y, int width, int height, int baseTile, SaveData *saveData, enum HeapID heapID) {
    box->format = MessageFormat_New(heapID);
    box->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, msgBank, heapID);
    box->expanded = String_New(WIFI_PLAZA_CONNECT_MSG_STRING_LENGTH, heapID);
    box->raw = String_New(WIFI_PLAZA_CONNECT_MSG_STRING_LENGTH, heapID);
    box->frameType = frameType;
    box->textSpeed = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(saveData));
    box->printerId = 0;
    AddWindowParameterized(bgConfig, &box->window, GF_BG_LYR_MAIN_1, x, y, width, height, 9, baseTile);
}

static void WiFiPlazaConnect_PrintMessage(WiFiPlazaConnectMessageBox *box, int msgId) {
    if (TextPrinterCheckActive(box->printerId)) {
        RemoveTextPrinter(box->printerId);
    }
    FillWindowPixelBuffer(&box->window, 15);
    ReadMsgDataIntoString(box->msgData, msgId, box->raw);
    StringExpandPlaceholders(box->format, box->expanded, box->raw);
    AddTextPrinterParameterized(&box->window, 1, box->expanded, 0, 0, TEXT_SPEED_NOTRANSFER, NULL);
    if (box->frameType == 0) {
        DrawFrameAndWindow1(&box->window, TRUE, 31, 12);
    } else {
        DrawFrameAndWindow2(&box->window, TRUE, 1, 11);
    }
    ScheduleWindowCopyToVram(&box->window);
}

static void WiFiPlazaConnect_ClearMessageBox(WiFiPlazaConnectMessageBox *box) {
    if (TextPrinterCheckActive(box->printerId)) {
        RemoveTextPrinter(box->printerId);
    }
    if (box->frameType == 0) {
        EraseFrameAndWindow1(&box->window, TRUE);
        ClearWindowTilemapAndScheduleTransfer(&box->window);
        return;
    }
    if (box->waitingIcon != NULL) {
        WiFiPlazaConnect_StopWaitingIcon(box);
    }
    ClearFrameAndWindow2(&box->window, TRUE);
    ClearWindowTilemapAndScheduleTransfer(&box->window);
}

static void WiFiPlazaConnect_StartWaitingIcon(WiFiPlazaConnectMessageBox *box) {
    if (box->frameType == 1) {
        GF_ASSERT(box->waitingIcon == NULL);
        box->waitingIcon = WaitingIcon_New(&box->window, 1);
    }
}

static void WiFiPlazaConnect_StopWaitingIcon(WiFiPlazaConnectMessageBox *box) {
    if (box->frameType == 1) {
        GF_ASSERT(box->waitingIcon != NULL);
        WaitingIcon_Delete(box->waitingIcon);
        box->waitingIcon = NULL;
    }
}

static void WiFiPlazaConnect_FreeMessageBox(WiFiPlazaConnectMessageBox *box) {
    if (TextPrinterCheckActive(box->printerId)) {
        RemoveTextPrinter(box->printerId);
    }
    if (box->waitingIcon != NULL) {
        WiFiPlazaConnect_StopWaitingIcon(box);
    }
    RemoveWindow(&box->window);
    String_Delete(box->raw);
    String_Delete(box->expanded);
    DestroyMsgData(box->msgData);
    MessageFormat_Delete(box->format);
}

static void WiFiPlazaConnect_PrintCenteredTitle(WiFiPlazaConnectMessageBox *box, int msgId) {
    u32 x;
    FillWindowPixelBuffer(&box->window, 0);
    ReadMsgDataIntoString(box->msgData, msgId, box->raw);
    StringExpandPlaceholders(box->format, box->expanded, box->raw);
    x = FontID_String_GetCenterAlignmentX(0, box->expanded, 0, 0xB0);
    AddTextPrinterParameterizedWithColor(&box->window, 1, box->expanded, x, 0, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(15, 14, 0), NULL);
}

static void WiFiPlazaConnect_BufferErrorCode(WiFiPlazaConnectMessageBox *box, int errorCode) {
    BufferIntegerAsString(box->format, 0, errorCode, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
}

static YesNoPrompt *WiFiPlazaConnect_CreateYesNoPrompt(BgConfig *bgConfig, int tileStart) {
    YesNoPromptTemplate template;
    YesNoPrompt *prompt = YesNoPrompt_Create(HEAP_ID_119);
    template.bgConfig = bgConfig;
    template.bgId = GF_BG_LYR_MAIN_1;
    template.tileStart = tileStart;
    template.plttSlot = 13;
    template.x = 25;
    template.y = 10;
    template.ignoreTouchFlag = FALSE;
    template.initialCursorPos = 0;
    template.shapeParam = 0;
    YesNoPrompt_InitFromTemplate(prompt, &template);
    return prompt;
}
