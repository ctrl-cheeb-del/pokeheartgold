#include "global.h"

#include "constants/sndseq.h"

#include "application/wii_message/wii_message_settings_internal.h"
#include "application/wii_message/wii_number.h"
#include "dwc/dwc_account_internal.h"
#include "dwc/dwc_main_internal.h"
#include "dwc/net_common_internal.h"
#include "dwc/stats_upload_internal.h"
#include "gts/gts_server.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0188.h"
#include "msgdata/msg/msg_0775.h"
#include "msgdata/msg/msg_0778.h"
#include "msgdata/msg/msg_0800.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "oam_manager.h"
#include "render_text.h"
#include "sav_system_info.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "touchpad.h"
#include "vram_transfer_manager.h"
#include "wifi_connection.h"
#include "wireless_status_icon.h"

// States of WiiMessageSettingsScreen_Main, indexes into sWiiMessageSettingsScreenStates.
enum WiiMessageSettingsScreenState {
    WMS_STATE_MAIN_MENU,
    WMS_STATE_CHECK_WII_NUMBER,
    WMS_STATE_SET_MESSAGE_RECEPTION,
    WMS_STATE_DELETE_SETTINGS,
    WMS_STATE_REGISTER_WII_NUMBER,
    WMS_STATE_START_WII_NUMBER_ENTRY,
    WMS_STATE_CHECK_WII_NUMBER_ENTRY,
    WMS_STATE_CONFIRM_CONNECT,
    WMS_STATE_HANDLE_CONNECT_YES_NO,
    WMS_STATE_PRINT_DISCONNECTING,
    WMS_STATE_DISCONNECT,
    WMS_STATE_PRINT_DISCONNECTED,
    WMS_STATE_START_CONNECT,
    WMS_STATE_WAIT_CONNECT,
    WMS_STATE_START_AUTH,
    WMS_STATE_WAIT_AUTH,
    WMS_STATE_START_SERVER_SESSION,
    WMS_STATE_SEND_REGISTRATION_REQUEST,
    WMS_STATE_WAIT_REGISTRATION_RESPONSE,
    WMS_STATE_REGISTRATION_CODE_SENT,
    WMS_STATE_START_REGISTRATION_CODE_ENTRY,
    WMS_STATE_CONFIRM_CANCEL_REGISTRATION,
    WMS_STATE_CONFIRM_REGISTRATION_CODE,
    WMS_STATE_START_PASSWORD_ENTRY,
    WMS_STATE_SAVE_SETTINGS,
    WMS_STATE_SAVE_GAME,
    WMS_STATE_DISCONNECT_AND_WAIT,
    WMS_STATE_SHOW_CONNECTION_ERROR,
    WMS_STATE_WAIT_CLOSE_ERROR,
    WMS_STATE_FADE_OUT,
    WMS_STATE_FADE_OUT_ONLINE, // like WMS_STATE_FADE_OUT, but stays connected
    WMS_STATE_SHOW_YES_NO,
    WMS_STATE_SHOW_REGISTRATION_ERROR,
    WMS_STATE_DISCONNECT_AND_QUIT,
    WMS_STATE_WAIT_MESSAGE,
    WMS_STATE_WAIT_MESSAGE_AND_DELAY,
    WMS_STATE_WAIT_MESSAGE_AND_SHOW_YES_NO,
    WMS_STATE_PRINT_WII_NUMBER_REENTRY,
    WMS_STATE_CHECK_PASSWORD,
};

#define WII_MESSAGE_SETTINGS_TEXT_PRINTER_NONE 0xFF

// Palette cycle of the background, run as a VBlank task.
typedef struct WiiMessageSettingsPaletteAnim {
    SysTask *task;
    BOOL active;
    u16 basePltt[4 * 16];
    u16 fadePltt[21 * 16]; // 21 blend steps of palette 0
    s16 frame;
    s8 reverse;
    u8 skipFrame;
    u32 screens; // 0: both, 1: main, 2: sub
} WiiMessageSettingsPaletteAnim;

// The main screen of the app (OverlayManager data, HEAP_ID_116).
typedef struct WiiMessageSettingsScreen {
    WiiMessageSettings *app;
    BgConfig *bgConfig;
    int state;
    int nextState;
    int registrationError;
    int connectionResult;
    int connectionErrorCode;
    int connectionErrorType;
    MessageFormat *msgFormat;
    MsgData *gtsMsgData;
    MsgData *speciesNamesMsgData;
    MsgData *wfcMsgData;
    MsgData *wfcErrorMsgData;
    MsgData *msgData;
    String *messageBuffer;
    String *title;
    String *errorBuffer;
    u32 textPrinterId;
    Window messageWindow;
    Window titleWindow;
    Window errorWindow;
    Window menuWindow;
    YesNoPrompt *yesNoPrompt;
    WaitingIcon *waitingIcon;
    int timer;
    int subState;
    int waitTimer;
    int menuSelection;
    ListMenuItem *menuItems;
    ListMenu *listMenu;
    int explanationState;
    int explanationScroll;
    int registerChoice; // 0: register, 1: don't register
    int explanationNumLines;
    int explanationResult;
    int arrowTimer;
    int arrowFrame;
    Window explanationWindow;
    Window choiceWindow;
    struct ListMenuCursor *cursor;
    int timeoutTimer;
    WiiMessageSettingsPaletteAnim paletteAnim;
} WiiMessageSettingsScreen;

typedef struct WiiMessageSettingsMenuEntry {
    u32 msgId;
    u32 nextState;
} WiiMessageSettingsMenuEntry;

typedef struct WiiMessageSettingsWindowRect {
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} WiiMessageSettingsWindowRect;

typedef struct WiiMessageSettingsChoicePosition {
    u32 x;
    u32 y;
} WiiMessageSettingsChoicePosition;

typedef struct WiiMessageSettingsMainBgTemplates {
    BgTemplate bg0;
    BgTemplate bg1;
    BgTemplate bg2;
    BgTemplate bg3;
} WiiMessageSettingsMainBgTemplates;

typedef struct WiiMessageSettingsSubBgTemplates {
    BgTemplate bg0;
    BgTemplate bg1;
} WiiMessageSettingsSubBgTemplates;

enum WiiMessageSettingsScreenMainState {
    WII_MESSAGE_SETTINGS_SCREEN_MAIN_WAIT_FADE_IN,
    WII_MESSAGE_SETTINGS_SCREEN_MAIN_RUN,
    WII_MESSAGE_SETTINGS_SCREEN_MAIN_WAIT_FADE_OUT,
};

// WiiMessageSettingsScreen_RunExplanation
enum WiiMessageExplanationResult {
    WMS_EXPLANATION_RUNNING,
    WMS_EXPLANATION_REGISTER,
    WMS_EXPLANATION_DONT_REGISTER,
};

static void WiiMessageSettingsScreen_VBlankCB(void *data);
static void WiiMessageSettingsScreen_InitBgs(BgConfig *bgConfig);
static void WiiMessageSettingsScreen_FreeBgs(BgConfig *bgConfig);
static void WiiMessageSettingsScreen_LoadGraphics(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_AnimatePaletteTask(SysTask *task, void *data);
static void WiiMessageSettingsScreen_AddWindows(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_RemoveWindows(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_SetState(WiiMessageSettingsScreen *screen, enum WiiMessageSettingsScreenState state, enum WiiMessageSettingsScreenState nextState);
static void WiiMessageSettingsScreen_ShowWaitingIcon(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_HideWaitingIcon(WiiMessageSettingsScreen *screen);
static YesNoPrompt *WiiMessageSettingsScreen_CreateYesNoPrompt(BgConfig *bgConfig, int tileStart, int initialCursorPos);
static void WiiMessageSettingsScreen_PrintRegisterChoice(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_ClearRegisterChoice(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_AnimateScrollArrows(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_PrintExplanation(WiiMessageSettingsScreen *screen);
static int WiiMessageSettingsScreen_RunExplanation(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_PrintMessage(WiiMessageSettingsScreen *screen, MsgData *msgData, int msgId, u32 textSpeed, u32 unused);
static BOOL WiiMessageSettingsScreen_IsPrinterActive(u32 printerId);
static int WiiMessageSettingsScreen_GetAlignedX(Window *window, String *string, int x, int alignment, u32 unused, u32 fontId);
static int WiiMessageSettingsScreen_PrintAligned(Window *window, String *string, int x, int y, int alignment, u32 color);
static void WiiMessageSettingsScreen_PrintError(WiiMessageSettingsScreen *screen, int msgId);
static void WiiMessageSettingsScreen_PrintErrorCode(WiiMessageSettingsScreen *screen, int msgId, int errorCode);
static BOOL WiiMessageSettingsScreen_MainMenu(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartCheckWiiNumber(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_SetMessageReception(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_DeleteSettings(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_RegisterWiiNumber(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartWiiNumberEntry(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_CheckWiiNumberEntry(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_ConfirmConnect(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_HandleConnectYesNo(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_PrintDisconnecting(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_Disconnect(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_PrintDisconnected(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartConnect(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitConnect(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartAuth(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitAuth(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartServerSession(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_SendRegistrationRequest(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitRegistrationResponse(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_RegistrationCodeSent(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartRegistrationCodeEntry(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_ConfirmCancelRegistration(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_ConfirmRegistrationCode(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_StartPasswordEntry(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_SaveSettings(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_SaveGame(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_DisconnectAndWait(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_ShowConnectionError(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitCloseError(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_FadeOut(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_ShowYesNoPrompt(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_ShowRegistrationError(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_DisconnectAndQuit(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitMessage(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitMessageAndDelay(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_WaitMessageAndShowYesNo(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_PrintWiiNumberReentry(WiiMessageSettingsScreen *screen);
static BOOL WiiMessageSettingsScreen_CheckPassword(WiiMessageSettingsScreen *screen);
static void WiiMessageSettingsScreen_RegisteredMenuMoveCursor(ListMenu *menu, s32 index, BOOL onInit);
static void WiiMessageSettingsScreen_UnregisteredMenuMoveCursor(ListMenu *menu, s32 index, BOOL onInit);

static const WiiMessageSettingsWindowRect sWiiMessageSettingsRegisteredMenuWindow = {
    .x = 0xB,
    .y = 7,
    .width = 20,
    .height = 8,
};

static const WiiMessageSettingsWindowRect sWiiMessageSettingsUnregisteredMenuWindow = {
    .x = 0xB,
    .y = 0xD,
    .width = 20,
    .height = 4,
};

static const GraphicsModes sWiiMessageSettingsGraphicsModes = {
    .dispMode = GX_DISPMODE_GRAPHICS,
    .bgMode = GX_BGMODE_0,
    .subMode = GX_BGMODE_0,
    ._2d3dMode = GX_BG0_AS_2D,
};

static const WiiMessageSettingsMenuEntry sWiiMessageSettingsUnregisteredMenuItems[2] = {
    { 1, 4  },
    { 4, 29 },
};

static const ListMenuTemplate sWiiMessageSettingsRegisteredMenuTemplate = {
    .items = NULL,
    .moveCursorFunc = (LM_MoveCursorFunc_t)WiiMessageSettingsScreen_RegisteredMenuMoveCursor,
    .itemPrintFunc = NULL,
    .window = NULL,
    .totalItems = 4,
    .maxShowed = 4,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 0,
    .cursorPal = 1,
    .fillValue = 15,
    .cursorShadowPal = 2,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 0,
    .cursorKind = 0,
    .data = NULL,
};

static const ListMenuTemplate sWiiMessageSettingsUnregisteredMenuTemplate = {
    .items = NULL,
    .moveCursorFunc = (LM_MoveCursorFunc_t)WiiMessageSettingsScreen_UnregisteredMenuMoveCursor,
    .itemPrintFunc = NULL,
    .window = NULL,
    .totalItems = 2,
    .maxShowed = 2,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 0,
    .cursorPal = 1,
    .fillValue = 15,
    .cursorShadowPal = 2,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 0,
    .cursorKind = 0,
    .data = NULL,
};

static const WiiMessageSettingsMenuEntry sWiiMessageSettingsRegisteredMenuItems[4] = {
    { 0, 1  },
    { 2, 2  },
    { 3, 3  },
    { 4, 29 },
};

static const GraphicsBanks sWiiMessageSettingsGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_64_E,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_0_B,
    .texpltt = GX_VRAM_TEXPLTT_01_FG,
};

static const WiiMessageSettingsSubBgTemplates sWiiMessageSettingsSubBgTemplates = {
    .bg0 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
            },
    .bg1 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xd800,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
            },
};

static const WiiMessageSettingsMainBgTemplates sWiiMessageSettingsMainBgTemplates = {
    .bg0 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf800,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
            },
    .bg1 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x08000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
            },
    .bg2 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe800,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
            },
    .bg3 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe000,
            .charBase = GX_BG_CHARBASE_0x18000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .mosaic = FALSE,
            },
};

static BOOL (*sWiiMessageSettingsScreenStates[39])(WiiMessageSettingsScreen *) = {
    WiiMessageSettingsScreen_MainMenu,
    WiiMessageSettingsScreen_StartCheckWiiNumber,
    WiiMessageSettingsScreen_SetMessageReception,
    WiiMessageSettingsScreen_DeleteSettings,
    WiiMessageSettingsScreen_RegisterWiiNumber,
    WiiMessageSettingsScreen_StartWiiNumberEntry,
    WiiMessageSettingsScreen_CheckWiiNumberEntry,
    WiiMessageSettingsScreen_ConfirmConnect,
    WiiMessageSettingsScreen_HandleConnectYesNo,
    WiiMessageSettingsScreen_PrintDisconnecting,
    WiiMessageSettingsScreen_Disconnect,
    WiiMessageSettingsScreen_PrintDisconnected,
    WiiMessageSettingsScreen_StartConnect,
    WiiMessageSettingsScreen_WaitConnect,
    WiiMessageSettingsScreen_StartAuth,
    WiiMessageSettingsScreen_WaitAuth,
    WiiMessageSettingsScreen_StartServerSession,
    WiiMessageSettingsScreen_SendRegistrationRequest,
    WiiMessageSettingsScreen_WaitRegistrationResponse,
    WiiMessageSettingsScreen_RegistrationCodeSent,
    WiiMessageSettingsScreen_StartRegistrationCodeEntry,
    WiiMessageSettingsScreen_ConfirmCancelRegistration,
    WiiMessageSettingsScreen_ConfirmRegistrationCode,
    WiiMessageSettingsScreen_StartPasswordEntry,
    WiiMessageSettingsScreen_SaveSettings,
    WiiMessageSettingsScreen_SaveGame,
    WiiMessageSettingsScreen_DisconnectAndWait,
    WiiMessageSettingsScreen_ShowConnectionError,
    WiiMessageSettingsScreen_WaitCloseError,
    WiiMessageSettingsScreen_FadeOut,
    WiiMessageSettingsScreen_FadeOut,
    WiiMessageSettingsScreen_ShowYesNoPrompt,
    WiiMessageSettingsScreen_ShowRegistrationError,
    WiiMessageSettingsScreen_DisconnectAndQuit,
    WiiMessageSettingsScreen_WaitMessage,
    WiiMessageSettingsScreen_WaitMessageAndDelay,
    WiiMessageSettingsScreen_WaitMessageAndShowYesNo,
    WiiMessageSettingsScreen_PrintWiiNumberReentry,
    WiiMessageSettingsScreen_CheckPassword,
};

BOOL WiiMessageSettingsScreen_Init(OverlayManager *man, int *state) {
    WiiMessageSettingsScreen *screen;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_BlendNone();
    G2S_BlendNone();
    Heap_Create(HEAP_ID_3, HEAP_ID_116, 0x70000);
    screen = OverlayManager_CreateAndGetData(man, sizeof(WiiMessageSettingsScreen), HEAP_ID_116);
    MI_CpuFill8(screen, 0, sizeof(WiiMessageSettingsScreen));
    screen->app = OverlayManager_GetArgs(man);
    screen->bgConfig = BgConfig_Alloc(HEAP_ID_116);
    GF_CreateVramTransferManager(64, HEAP_ID_116);
    SetKeyRepeatTimers(4, 8);
    WiiMessageSettingsScreen_InitBgs(screen->bgConfig);
    GF_TouchpadResetSampling();
    GF_TouchpadStartSampling(4);
    screen->msgFormat = MessageFormat_New_Custom(11, 64, HEAP_ID_116);
    screen->gtsMsgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0775_bin, HEAP_ID_116);
    screen->wfcMsgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0778_bin, HEAP_ID_116);
    screen->wfcErrorMsgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0800_bin, HEAP_ID_116);
    screen->speciesNamesMsgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0237_bin, HEAP_ID_116);
    screen->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0188_bin, HEAP_ID_116);
    screen->messageBuffer = String_New(270, HEAP_ID_116);
    screen->errorBuffer = String_New(256, HEAP_ID_116);
    screen->title = NewString_ReadMsgData(screen->gtsMsgData, msg_0775_00031); // "Nintendo Wi-Fi Connection"
    WiiMessageSettingsScreen_LoadGraphics(screen);
    WiiMessageSettingsScreen_AddWindows(screen);

    switch (WiiMessageSettings_GetScreenStartState(screen->app)) {
    case WMS_STATE_START_CONNECT:
        if (DWC_CheckInet() == 0 && Comm_HasWifiProfile(screen->app->saveData) == TRUE) {
            screen->state = WMS_STATE_START_CONNECT;
            CommState_InitWiiMessageWfcSession(screen->app->saveData);
            WirelessStatusIcon_Create();
        } else {
            screen->state = WMS_STATE_MAIN_MENU;
        }
        break;
    case WMS_STATE_CONFIRM_REGISTRATION_CODE: {
        int *timeoutTimer = &screen->timeoutTimer;
        *timeoutTimer = 0;
        WirelessStatusIcon_Create();
    }
        screen->state = WiiMessageSettings_GetScreenStartState(screen->app);
        break;
    default:
        screen->state = WiiMessageSettings_GetScreenStartState(screen->app);
        break;
    }
    WiiMessageSettings_SetScreenStartState(screen->app, WMS_STATE_MAIN_MENU);

    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_116);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    gSystem.screensFlipped = TRUE;
    GfGfx_SwapDisplay();
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    Main_SetVBlankIntrCB(WiiMessageSettingsScreen_VBlankCB, screen);
    return TRUE;
}

BOOL WiiMessageSettingsScreen_Main(OverlayManager *man, int *state) {
    WiiMessageSettingsScreen *screen = OverlayManager_GetData(man);
    int prevState;
    BOOL done;

    switch (*state) {
    case WII_MESSAGE_SETTINGS_SCREEN_MAIN_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            *state = WII_MESSAGE_SETTINGS_SCREEN_MAIN_RUN;
        }
        break;
    case WII_MESSAGE_SETTINGS_SCREEN_MAIN_RUN:
        prevState = screen->state;
        done = sWiiMessageSettingsScreenStates[prevState](screen);
        if (prevState != screen->state) {
            screen->subState = 0;
            screen->menuSelection = 0;
            screen->waitTimer = 0;
        }
        if (done == TRUE) {
            *state = WII_MESSAGE_SETTINGS_SCREEN_MAIN_WAIT_FADE_OUT;
        }
        break;
    case WII_MESSAGE_SETTINGS_SCREEN_MAIN_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL WiiMessageSettingsScreen_Exit(OverlayManager *man, int *state) {
    WiiMessageSettingsScreen *screen = OverlayManager_GetData(man);

    if (screen->paletteAnim.task != NULL) {
        SysTask_Destroy(screen->paletteAnim.task);
        screen->paletteAnim.task = NULL;
        screen->paletteAnim.active = FALSE;
    }
    DestroyMsgData(screen->msgData);
    DestroyMsgData(screen->speciesNamesMsgData);
    DestroyMsgData(screen->wfcErrorMsgData);
    DestroyMsgData(screen->wfcMsgData);
    DestroyMsgData(screen->gtsMsgData);
    MessageFormat_Delete(screen->msgFormat);
    String_Delete(screen->title);
    String_Delete(screen->errorBuffer);
    String_Delete(screen->messageBuffer);
    WiiMessageSettingsScreen_RemoveWindows(screen);
    Heap_Free(screen->bgConfig);
    WiiMessageSettingsScreen_FreeBgs(screen->bgConfig);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GF_DestroyVramTransferManager();
    GF_TouchpadStopSampling();
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    TextFlags_SetAutoScrollParam(0);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    WirelessStatusIcon_Destroy();
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_116);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    return TRUE;
}

static void WiiMessageSettingsScreen_VBlankCB(void *data) {
    WiiMessageSettingsScreen *screen = data;

    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(screen->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void WiiMessageSettingsScreen_InitBgs(BgConfig *bgConfig) {
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    {
        GraphicsBanks banks = sWiiMessageSettingsGraphicsBanks;
        GfGfx_SetBanks(&banks);
    }
    MIi_CpuClear32(0, (void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MIi_CpuClear32(0, (void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MIi_CpuClear32(0, (void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MIi_CpuClear32(0, (void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);
    {
        GraphicsModes modes = sWiiMessageSettingsGraphicsModes;
        SetBothScreensModesAndDisable(&modes);
    }
    {
        WiiMessageSettingsMainBgTemplates templates = sWiiMessageSettingsMainBgTemplates;

        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &templates.bg0, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &templates.bg1, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &templates.bg2, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &templates.bg3, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    }
    {
        WiiMessageSettingsSubBgTemplates templates = sWiiMessageSettingsSubBgTemplates;

        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &templates.bg0, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_0, BG_POS_OP_SET_Y, 0);
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &templates.bg1, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 0);
    }
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 32, 0, HEAP_ID_116);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 32, 0, HEAP_ID_116);
}

static void WiiMessageSettingsScreen_FreeBgs(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
}

static void WiiMessageSettingsScreen_LoadGraphics(WiiMessageSettingsScreen *screen) {
    BgConfig *bgConfig = screen->bgConfig;
    NARC *narc = NARC_New(NARC_a_0_8_8, HEAP_ID_116);
    void *plttFile;
    NNSG2dPaletteData *pltt;
    int group;
    int step;
    int fraction;
    int last;
    u16 *dest;
    u16 *src;

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0, 0, HEAP_ID_116);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)0, 0, HEAP_ID_116);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0x1A0, HEAP_ID_116);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)0x1A0, HEAP_ID_116);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 10, Options_GetFrame(screen->app->options), HEAP_ID_116);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 31, 11, 0, HEAP_ID_116);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_2, 31, 11, 0, HEAP_ID_116);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, HEAP_ID_116);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x600, FALSE, HEAP_ID_116);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 11, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_116);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 12, bgConfig, GF_BG_LYR_SUB_1, 0, 0x600, FALSE, HEAP_ID_116);
    BG_SetMaskColor(GF_BG_LYR_MAIN_0, RGB_BLACK);
    BG_SetMaskColor(GF_BG_LYR_SUB_0, RGB_BLACK);

    MI_CpuFill8(&screen->paletteAnim, 0, sizeof(WiiMessageSettingsPaletteAnim));
    plttFile = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, &pltt, HEAP_ID_116);
    MIi_CpuCopy16(pltt->pRawData, screen->paletteAnim.basePltt, sizeof(screen->paletteAnim.basePltt));
    MIi_CpuCopy16(pltt->pRawData, screen->paletteAnim.fadePltt, sizeof(screen->paletteAnim.basePltt));
    Heap_Free(plttFile);

    // fadePltt: palette 0 blended in 7 steps towards each of palettes 1, 2 and 3
    step = 0;
    group = 0;
    dest = screen->paletteAnim.fadePltt;
    src = screen->paletteAnim.basePltt;
    for (; group < 3; group++) {
        fraction = 0;
        last = 0;
        for (;;) {
            int color;
            GF_ASSERT(step < 21);
            for (color = 1; color < 16; color++) {
                BlendPalette(src + color, dest + color, 1, fraction >> 8, screen->paletteAnim.basePltt[(group + 1) * 16 + color]);
            }
            dest += 16;
            step++;
            if (last == 1) {
                break;
            }
            fraction += 0x300;
            if (fraction >= 0x1000) {
                fraction = 0x1000;
                last = 1;
            }
        }
        src += 16;
    }
    DC_FlushRange(screen->paletteAnim.fadePltt, 21 * 32);
    screen->paletteAnim.active = TRUE;
    screen->paletteAnim.screens = 0;
    screen->paletteAnim.task = SysTask_CreateOnVBlankQueue(WiiMessageSettingsScreen_AnimatePaletteTask, &screen->paletteAnim, 20);
    NARC_Delete(narc);

    narc = NARC_New(NARC_a_1_9_7, HEAP_ID_116);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 11, bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, HEAP_ID_116);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, HEAP_ID_116);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 12, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_9_OFFSET, 0x20, HEAP_ID_116);
    NARC_Delete(narc);
}

static void WiiMessageSettingsScreen_AnimatePaletteTask(SysTask *task, void *data) {
    WiiMessageSettingsPaletteAnim *anim = data;
    if (anim->active) {
        anim->skipFrame ^= 1;
        if ((anim->skipFrame & 1) == 0) {
            if (anim->screens <= 1) {
                GX_LoadBGPltt(&anim->fadePltt[anim->frame * 16], 0, 32);
            }
            if (anim->screens == 0 || anim->screens == 2) {
                GXS_LoadBGPltt(&anim->fadePltt[anim->frame * 16], 0, 32);
            }
            if (anim->reverse == 0) {
                anim->frame++;
                if (anim->frame >= 21) {
                    anim->frame = 19;
                    anim->reverse ^= 1;
                }
            } else {
                anim->frame--;
                if (anim->frame < 0) {
                    anim->frame = 1;
                    anim->reverse ^= 1;
                }
            }
        }
    }
}

static void WiiMessageSettingsScreen_AddWindows(WiiMessageSettingsScreen *screen) {
    AddWindowParameterized(screen->bgConfig, &screen->errorWindow, GF_BG_LYR_MAIN_0, 4, 4, 23, 16, 13, 148);
    FillWindowPixelBuffer(&screen->errorWindow, 0);
    AddWindowParameterized(screen->bgConfig, &screen->titleWindow, GF_BG_LYR_MAIN_0, 4, 1, 24, 2, 13, 516);
    FillWindowPixelBuffer(&screen->titleWindow, 0);
    WiiMessageSettingsScreen_PrintAligned(&screen->titleWindow, screen->title, 0, 1, 1, MAKE_TEXT_COLOR(15, 14, 0));
    AddWindowParameterized(screen->bgConfig, &screen->messageWindow, GF_BG_LYR_MAIN_0, 2, 19, 27, 4, 13, 40);
    FillWindowPixelBuffer(&screen->messageWindow, 0);
}

static void WiiMessageSettingsScreen_RemoveWindows(WiiMessageSettingsScreen *screen) {
    RemoveWindow(&screen->messageWindow);
    RemoveWindow(&screen->titleWindow);
    RemoveWindow(&screen->errorWindow);
}

static void WiiMessageSettingsScreen_SetState(WiiMessageSettingsScreen *screen, enum WiiMessageSettingsScreenState state, enum WiiMessageSettingsScreenState nextState) {
    screen->state = state;
    screen->nextState = nextState;
}

static void WiiMessageSettingsScreen_ShowWaitingIcon(WiiMessageSettingsScreen *screen) {
    if (!screen->waitingIcon) {
        screen->waitingIcon = WaitingIcon_New(&screen->messageWindow, 1);
    }
}

static void WiiMessageSettingsScreen_HideWaitingIcon(WiiMessageSettingsScreen *screen) {
    if (screen->waitingIcon) {
        WaitingIcon_Delete(screen->waitingIcon);
        screen->waitingIcon = NULL;
    }
}

static YesNoPrompt *WiiMessageSettingsScreen_CreateYesNoPrompt(BgConfig *bgConfig, int tileStart, int initialCursorPos) {
    YesNoPrompt *prompt = YesNoPrompt_Create(HEAP_ID_116);
    YesNoPromptTemplate template;

    template.bgConfig = bgConfig;
    template.bgId = GF_BG_LYR_MAIN_0;
    template.tileStart = tileStart;
    template.plttSlot = 14;
    template.x = 25;
    template.y = 10;
    template.ignoreTouchFlag = FALSE;
    template.initialCursorPos = initialCursorPos;
    template.shapeParam = 0;
    YesNoPrompt_InitFromTemplate(prompt, &template);
    return prompt;
}

static BOOL WiiMessageSettingsScreen_MainMenu(WiiMessageSettingsScreen *screen) {
    ListMenuTemplate template;
    const WiiMessageSettingsWindowRect *rect;
    const WiiMessageSettingsMenuEntry *entries;
    const ListMenuTemplate *srcTemplate;
    int count;
    int i;
    int input;

    switch (screen->subState) {
    case 0:
        if (Save_WiiMessage_IsRegistered(screen->app->saveData) == TRUE) {
            rect = &sWiiMessageSettingsRegisteredMenuWindow;
            entries = sWiiMessageSettingsRegisteredMenuItems;
            count = 4;
            srcTemplate = &sWiiMessageSettingsRegisteredMenuTemplate;
        } else {
            rect = &sWiiMessageSettingsUnregisteredMenuWindow;
            entries = sWiiMessageSettingsUnregisteredMenuItems;
            srcTemplate = &sWiiMessageSettingsUnregisteredMenuTemplate;
            count = 2;
        }
        template = *srcTemplate;
        AddWindowParameterized(screen->bgConfig, &screen->menuWindow, GF_BG_LYR_MAIN_0, rect->x, rect->y, rect->width, rect->height, 13, 148);
        screen->menuItems = ListMenuItems_New(count, HEAP_ID_116);
        i = 0;
        if (count > 0) {
            do {
                ListMenuItems_AppendFromMsgData(screen->menuItems, screen->msgData, entries->msgId, entries->nextState);
                i++;
                entries++;
            } while (i < count);
        }
        template.window = &screen->menuWindow;
        template.items = screen->menuItems;
        screen->listMenu = ListMenuInit(&template, 0, 0, HEAP_ID_116);
        DrawFrameAndWindow1(&screen->menuWindow, TRUE, 31, 11);
        ClearFrameAndWindow2(&screen->messageWindow, TRUE);
        CopyWindowToVram(&screen->menuWindow);
        screen->subState++;
        break;
    case 1:
        input = ListMenu_ProcessInput(screen->listMenu);
        switch (input) {
        case LIST_CANCEL:
            PlaySE(SEQ_SE_DP_SELECT);
            WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_QUIT, 0);
            screen->menuSelection = WMS_STATE_FADE_OUT;
            screen->subState++;
            break;
        case LIST_NOTHING_CHOSEN:
            break;
        default:
            PlaySE(SEQ_SE_DP_SELECT);
            screen->menuSelection = input;
            screen->subState++;
            break;
        }
        break;
    default:
        ListMenuItems_Delete(screen->menuItems);
        DestroyListMenu(screen->listMenu, NULL, NULL);
        EraseFrameAndWindow1(&screen->menuWindow, TRUE);
        ClearWindowTilemapAndCopyToVram(&screen->menuWindow);
        RemoveWindow(&screen->menuWindow);
        screen->state = screen->menuSelection;
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartCheckWiiNumber(WiiMessageSettingsScreen *screen) {
    WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_CHECK_PASSWORD, WII_MESSAGE_SETTINGS_APP_SET_PASSWORD);
    WiiMessageSettings_SetScreenStartState(screen->app, WMS_STATE_CHECK_PASSWORD);
    screen->state = WMS_STATE_FADE_OUT;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_SetMessageReception(WiiMessageSettingsScreen *screen) {
    int input;

    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00025, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
        screen->subState++;
        break;
    case 2:
        input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00026, 1, 0xF0F);
            Save_WiiMessage_SetParam(screen->app->saveData, 0, TRUE);
            screen->subState++;
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00027, 1, 0xF0F);
            Save_WiiMessage_SetParam(screen->app->saveData, 0, FALSE);
            screen->subState++;
        }
        break;
    case 3:
        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_SAVE_GAME, WMS_STATE_MAIN_MENU);
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_DeleteSettings(WiiMessageSettingsScreen *screen) {
    int input;

    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00028, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 1);
        screen->subState++;
        break;
    case 2:
        input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00029, 1, 0xF0F);
            Save_WiiMessage_Reset(screen->app->saveData);
            screen->subState++;
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->state = WMS_STATE_MAIN_MENU;
        }
        break;
    case 3:
        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_SAVE_GAME, WMS_STATE_MAIN_MENU);
        break;
    }
    return FALSE;
}

static WiiMessageSettingsChoicePosition sWiiMessageSettingsRegisterChoicePositions[2] = {
    { 4,   8 },
    { 128, 8 },
};

static void WiiMessageSettingsScreen_PrintRegisterChoice(WiiMessageSettingsScreen *screen) {
    String *string;

    FillWindowPixelBuffer(&screen->choiceWindow, 15);
    string = NewString_ReadMsgData(screen->msgData, msg_0188_00042);
    AddTextPrinterParameterized(&screen->choiceWindow, 0, string, sWiiMessageSettingsRegisterChoicePositions[0].x + 12, sWiiMessageSettingsRegisterChoicePositions[0].y, TEXT_SPEED_NOTRANSFER, NULL);
    String_Delete(string);
    string = NewString_ReadMsgData(screen->msgData, msg_0188_00043);
    AddTextPrinterParameterized(&screen->choiceWindow, 0, string, sWiiMessageSettingsRegisterChoicePositions[1].x + 12, sWiiMessageSettingsRegisterChoicePositions[1].y, TEXT_SPEED_NOTRANSFER, NULL);
    String_Delete(string);
    ((void (*)(struct ListMenuCursor *, Window *, u32, u32))ListMenuUpdateCursorObj)(screen->cursor, &screen->choiceWindow, sWiiMessageSettingsRegisterChoicePositions[screen->registerChoice].x, sWiiMessageSettingsRegisterChoicePositions[screen->registerChoice].y);
    CopyWindowToVram(&screen->choiceWindow);
}

static void WiiMessageSettingsScreen_ClearRegisterChoice(WiiMessageSettingsScreen *screen) {
    FillWindowPixelBuffer(&screen->choiceWindow, 15);
    CopyWindowToVram(&screen->choiceWindow);
}

// Blinks the scroll arrows of the explanation text on bg main 3.
static void WiiMessageSettingsScreen_AnimateScrollArrows(WiiMessageSettingsScreen *screen) {
    screen->arrowTimer++;
    if (screen->arrowTimer != 8) {
        return;
    }
    screen->arrowFrame ^= 1;
    screen->arrowTimer = 0;
    if (screen->explanationScroll + 6 != screen->explanationNumLines) {
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 1, 14, 17, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 2, 15, 17, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 3, 16, 17, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 4, 17, 17, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 11, 14, 18, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 12, 15, 18, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 13, 16, 18, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 14, 17, 18, 1, 1, 9);
    } else {
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, 0, 14, 17, 4, 2, 9);
    }
    if (screen->explanationScroll != 0) {
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 5, 14, 3, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 6, 15, 3, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 7, 16, 3, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 8, 17, 3, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 15, 14, 4, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 16, 15, 4, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 17, 16, 4, 1, 1, 9);
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, screen->arrowFrame * 20 + 18, 17, 4, 1, 1, 9);
    } else {
        FillBgTilemapRect(screen->bgConfig, GF_BG_LYR_MAIN_3, 0, 14, 3, 4, 2, 9);
    }
    ScheduleBgTilemapBufferTransfer(screen->bgConfig, GF_BG_LYR_MAIN_3);
}

// Prints the 6 lines of the "Registering a Wii Number" text from the scroll position on.
static void WiiMessageSettingsScreen_PrintExplanation(WiiMessageSettingsScreen *screen) {
    String *text[1];
    String *line;
    int i;
    int y;
    Window *window;

    FillWindowPixelBuffer(&screen->explanationWindow, 15);
    text[0] = NewString_ReadMsgData(screen->msgData, msg_0188_00044);
    line = String_New(String_GetLength(text[0]), HEAP_ID_116);
    i = screen->explanationScroll;
    if (i < screen->explanationScroll + 6) {
        window = (y = 0, &screen->explanationWindow);
        do {
            String_GetLineN(line, text[0], i);
            AddTextPrinterParameterized(window, 0, line, 4, y, TEXT_SPEED_NOTRANSFER, NULL);
            i++;
            y += 16;
        } while (i < screen->explanationScroll + 6);
    }
    String_Delete(text[0]);
    String_Delete(line);
    CopyWindowToVram(&screen->explanationWindow);
}

// The scrollable explanation with "Don't register" / "Register" (enum WiiMessageExplanationResult).
static int WiiMessageSettingsScreen_RunExplanation(WiiMessageSettingsScreen *screen) {
    switch (screen->explanationState) {
    case 0: {
        String *text = NewString_ReadMsgData(screen->msgData, msg_0188_00044);
        int numLines = String_CountLines(text);
        String *line;
        int i;

        screen->explanationScroll = 0;
        screen->registerChoice = 0;
        screen->explanationResult = WMS_EXPLANATION_RUNNING;
        screen->explanationNumLines = numLines;
        AddWindowParameterized(screen->bgConfig, &screen->explanationWindow, GF_BG_LYR_MAIN_2, 1, 5, 30, 12, 13, 148);
        AddWindowParameterized(screen->bgConfig, &screen->choiceWindow, GF_BG_LYR_MAIN_2, 1, 19, 30, 4, 13, 508);
        FillWindowPixelBuffer(&screen->explanationWindow, 15);
        line = String_New(String_GetLength(text), HEAP_ID_116);
        for (i = 0; i < 6; i++) {
            String_GetLineN(line, text, i);
            AddTextPrinterParameterized(&screen->explanationWindow, 0, line, 4, i * 16, TEXT_SPEED_NOTRANSFER, NULL);
        }
        String_Delete(text);
        String_Delete(line);
        DrawFrameAndWindow1(&screen->explanationWindow, TRUE, 31, 11);
        CopyWindowToVram(&screen->explanationWindow);
        FillWindowPixelBuffer(&screen->choiceWindow, 15);
        DrawFrameAndWindow1(&screen->choiceWindow, TRUE, 31, 11);
        CopyWindowToVram(&screen->choiceWindow);
        screen->cursor = ListMenuCursorNew(HEAP_ID_116);
        FillWindowPixelBuffer(&screen->messageWindow, 15);
        ClearFrameAndWindow2(&screen->messageWindow, TRUE);
        ClearWindowTilemapAndCopyToVram(&screen->messageWindow);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_ON);
        screen->arrowTimer = 0;
        screen->arrowFrame = 0;
        screen->explanationState++;
        break;
    }
    case 1: {
        int prevScroll = screen->explanationScroll;
        if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
            if (prevScroll != 0) {
                screen->explanationScroll--;
                PlaySE(SEQ_SE_DP_SELECT);
            }
        } else if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
            if (prevScroll + 6 < screen->explanationNumLines) {
                screen->explanationScroll++;
                PlaySE(SEQ_SE_DP_SELECT);
            }
            if (screen->explanationScroll + 6 == screen->explanationNumLines) {
                WiiMessageSettingsScreen_PrintRegisterChoice(screen);
                screen->explanationState++;
                PlaySE(SEQ_SE_DP_SELECT);
            }
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            PlaySE(SEQ_SE_DP_SELECT);
            screen->explanationResult = WMS_EXPLANATION_DONT_REGISTER;
            screen->explanationState = 255;
        }
        if (prevScroll != screen->explanationScroll) {
            WiiMessageSettingsScreen_PrintExplanation(screen);
        }
        break;
    }
    case 2:
        if ((gSystem.newKeys & PAD_KEY_RIGHT) || (gSystem.newKeys & PAD_KEY_LEFT)) {
            screen->registerChoice ^= 1;
            PlaySE(SEQ_SE_DP_SELECT);
            WiiMessageSettingsScreen_PrintRegisterChoice(screen);
        } else if (gSystem.newKeys & PAD_BUTTON_A) {
            screen->explanationResult = WMS_EXPLANATION_DONT_REGISTER - screen->registerChoice;
            PlaySE(SEQ_SE_DP_SELECT);
            screen->explanationState++;
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            screen->explanationResult = WMS_EXPLANATION_DONT_REGISTER;
            PlaySE(SEQ_SE_DP_SELECT);
            screen->explanationState++;
        } else if (gSystem.newKeys & PAD_KEY_UP) {
            WiiMessageSettingsScreen_ClearRegisterChoice(screen);
            PlaySE(SEQ_SE_DP_SELECT);
            screen->explanationState--;
            screen->explanationScroll--;
            WiiMessageSettingsScreen_PrintExplanation(screen);
        }
        break;
    default:
        EraseFrameAndWindow1(&screen->explanationWindow, FALSE);
        ClearWindowTilemapAndCopyToVram(&screen->explanationWindow);
        RemoveWindow(&screen->explanationWindow);
        EraseFrameAndWindow1(&screen->choiceWindow, FALSE);
        ClearWindowTilemapAndCopyToVram(&screen->choiceWindow);
        RemoveWindow(&screen->choiceWindow);
        DestroyListMenuCursorObj(screen->cursor);
        BgClearTilemapBufferAndCommit(screen->bgConfig, GF_BG_LYR_MAIN_3);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
        screen->explanationState = 0;
        return screen->explanationResult;
    }
    WiiMessageSettingsScreen_AnimateScrollArrows(screen);
    return WMS_EXPLANATION_RUNNING;
}

static BOOL WiiMessageSettingsScreen_RegisterWiiNumber(WiiMessageSettingsScreen *screen) {
    int input;

    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }
    switch (screen->subState) {
    case 0:
        screen->subState = 3;
        break;
    case 1:
        screen->subState++;
        break;
    case 2:
        input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00009, 1, 0xF0F);
            screen->subState = 4;
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->subState++;
        }
        break;
    case 3:
        input = WiiMessageSettingsScreen_RunExplanation(screen);
        if (input == WMS_EXPLANATION_REGISTER) {
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00009, 1, 0xF0F);
            screen->subState++;
        } else if (input == WMS_EXPLANATION_DONT_REGISTER) {
            WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_MAIN_MENU);
        }
        break;
    case 4:
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
        screen->subState++;
        break;
    default:
        input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->state = WMS_STATE_START_WII_NUMBER_ENTRY;
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00010, 1, 0xF0F);
            WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_MAIN_MENU);
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartWiiNumberEntry(WiiMessageSettingsScreen *screen) {
    WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_WII_NUMBER_ENTRY, 0);
    WiiMessageSettings_SetScreenStartState(screen->app, WMS_STATE_CHECK_WII_NUMBER_ENTRY);
    screen->state = WMS_STATE_FADE_OUT;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_CheckWiiNumberEntry(WiiMessageSettingsScreen *screen) {
    switch (WiiMessageSettings_GetWiiNumberEntryState(screen->app)) {
    case WII_NUMBER_ENTRY_CANCELLED:
        screen->state = WMS_STATE_MAIN_MENU;
        return FALSE;
    case WII_NUMBER_ENTRY_ENTERED_ONCE:
    case WII_NUMBER_ENTRY_MISMATCH:
        screen->state = WMS_STATE_PRINT_WII_NUMBER_REENTRY;
        return FALSE;
    default:
        if (!screen->subState) {
            screen->state = WMS_STATE_CONFIRM_CONNECT;
        }
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_ConfirmConnect(WiiMessageSettingsScreen *screen) {
    int input;

    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }

    switch (screen->subState) {
    case 0:
        screen->subState++;
        break;
    case 1:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00011, 1, 0xF0F);
        screen->subState++;
        break;
    case 2:
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
        screen->subState++;
        break;
    case 3:
        input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->subState++;
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_MAIN_MENU);
        }
        break;
    case 4:
        if (!Comm_HasWifiProfile(screen->app->saveData)) {
            WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_OV44, 0);
            WiiMessageSettings_SetScreenStartState(screen->app, WMS_STATE_START_CONNECT);
            screen->state = WMS_STATE_FADE_OUT;
            return FALSE;
        }
        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_START_CONNECT);
        break;
    }

    return FALSE;
}

static BOOL WiiMessageSettingsScreen_HandleConnectYesNo(WiiMessageSettingsScreen *screen) {
    int input = YesNoPrompt_HandleInput(screen->yesNoPrompt);

    if (input == YESNORESPONSE_YES) {
        YesNoPrompt_Destroy(screen->yesNoPrompt);
        WiiMessageSettingsScreen_PrintMessage(screen, screen->wfcMsgData, msg_0778_00001, 1, 0xF0F);
        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_START_CONNECT);
        WiiMessageSettingsScreen_ShowWaitingIcon(screen);
    } else if (input == YESNORESPONSE_NO) {
        YesNoPrompt_Destroy(screen->yesNoPrompt);
        CommState_FreeWiiMessageWfcSession();
        WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_QUIT, 0);
        screen->state = WMS_STATE_FADE_OUT;
    }

    return FALSE;
}

static BOOL WiiMessageSettingsScreen_PrintDisconnecting(WiiMessageSettingsScreen *screen) {
    WiiMessageSettingsScreen_PrintMessage(screen, screen->wfcErrorMsgData, msg_0800_00026, 1, 0xF0F);
    WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_DISCONNECT);
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_Disconnect(WiiMessageSettingsScreen *screen) {
    CommState_FreeWiiMessageWfcSession();
    DWC_CleanupInet();
    WirelessStatusIcon_Destroy();
    Sys_ClearSleepDisableFlag(4);
    if (screen->app->serverSessionStarted == TRUE) {
        GtsServer_Exit();
        screen->app->serverSessionStarted = FALSE;
    }
    screen->state = WMS_STATE_PRINT_DISCONNECTED;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_PrintDisconnected(WiiMessageSettingsScreen *screen) {
    WiiMessageSettingsScreen_PrintMessage(screen, screen->wfcErrorMsgData, msg_0800_00027, 1, 0xF0F);
    WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE_AND_DELAY, WMS_STATE_FADE_OUT);
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartConnect(WiiMessageSettingsScreen *screen) {
    switch (screen->subState) {
    case 0:
        CommState_InitWiiMessageWfcSession(screen->app->saveData);
        WirelessStatusIcon_Create();
        WiiMessageSettingsScreen_PrintMessage(screen, screen->wfcMsgData, msg_0778_00001, 1, 0xF0F);
        WiiMessageSettingsScreen_ShowWaitingIcon(screen);
        screen->subState++;
        break;
    case 1:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            screen->subState++;
        }
        break;
    case 2:
        Sys_SetSleepDisableFlag(4);
        DWC_InitInetEx(&screen->app->netConnection, 2, 1, 20);
        DWC_SetAuthServer(2);
        DWC_ConnectInetAsync();
        screen->state = WMS_STATE_WAIT_CONNECT;
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitConnect(WiiMessageSettingsScreen *screen) {
    struct {
        int error;
        int errorType;
        int errorCode;
        NetApInfo info;
    } locals;

    DWC_ProcessInet();
    if (DWC_CheckInet()) {
        switch (DWC_GetInetStatus()) {
        case 7:
            screen->connectionResult = DWC_GetLastErrorEx(&locals.errorCode, &locals.errorType);
            screen->connectionErrorCode = locals.errorCode;
            screen->connectionErrorType = locals.errorType;
            DWC_ClearError();
            DWC_CleanupInet();
            WirelessStatusIcon_Destroy();
            CommState_FreeWiiMessageWfcSession();
            Sys_ClearSleepDisableFlag(4);
            if (screen->app->serverSessionStarted == TRUE) {
                GtsServer_Exit();
                screen->app->serverSessionStarted = FALSE;
            }
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 8:
        default:
            DWC_GetLastError(&locals.error);
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
            screen->registrationError = -2;
            break;
        case 4:
            DWC_GetApInfo(&locals.info);
            screen->state = WMS_STATE_START_AUTH;
            break;
        }
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartAuth(WiiMessageSettingsScreen *screen) {
    DWC_NASLoginAsync();
    screen->state = WMS_STATE_WAIT_AUTH;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitAuth(WiiMessageSettingsScreen *screen) {
    int errorCode;
    int errorType;

    switch (DWC_NASLoginProcess()) {
    case 3:
        screen->state = WMS_STATE_START_SERVER_SESSION;
        break;
    case 0:
    case 4:
    case 5:
        WiiMessageSettingsScreen_HideWaitingIcon(screen);
        screen->connectionResult = DWC_GetLastErrorEx(&errorCode, &errorType);
        screen->connectionErrorCode = errorCode;
        DWC_ClearError();
        DWC_CleanupInet();
        WirelessStatusIcon_Destroy();
        CommState_FreeWiiMessageWfcSession();
        Sys_ClearSleepDisableFlag(4);
        if (screen->app->serverSessionStarted == TRUE) {
            GtsServer_Exit();
            screen->app->serverSessionStarted = FALSE;
        }
        screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
        switch (errorType) {
        case 1:
        case 2:
            screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
            break;
        case 4:
            DWC_ShutdownGHTTP();
            screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
            break;
        case 6:
            screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
            break;
        case 3:
            DWC_ShutdownFriendsMatch();
            screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
            break;
        case 5:
        case 7:
            CommState_ShowRestartErrorAndHalt();
            break;
        }
        if (errorCode < -20000 && errorCode >= -29999) {
            screen->state = WMS_STATE_SHOW_CONNECTION_ERROR;
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartServerSession(WiiMessageSettingsScreen *screen) {
    void *wifiList = Save_FriendRoster_Get(screen->app->saveData);
    SysInfo *sysInfo = Save_SysInfo_Get(screen->app->saveData);
    void *userData = FriendRoster_GetUserData(wifiList);
    u32 profileId;
    u64 friendKey;

    if (Save_SysInfo_GetDwcProfileId(sysInfo) == 0) {
        Save_SysInfo_SetDwcProfileId(sysInfo, (s32)Comm_GetOwnGsProfileId(wifiList));
    }
    profileId = Save_SysInfo_GetDwcProfileId(sysInfo);
    friendKey = DWC_CreateFriendKey(userData);
    GtsServer_Init(profileId, friendKey, (u32)(friendKey >> 32));
    screen->app->serverSessionStarted = TRUE;
    screen->state = WMS_STATE_SEND_REGISTRATION_REQUEST;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_SendRegistrationRequest(WiiMessageSettingsScreen *screen) {
    WiiMessageSettings_InitRequest(screen->app);
    WiiMessageSettings_SetRequestWiiAddress(screen->app);
    GtsServer_RequestSetProfile(&screen->app->request, &screen->app->responseStatus);
    screen->state = WMS_STATE_WAIT_REGISTRATION_RESPONSE;
    screen->timeoutTimer = 0;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitRegistrationResponse(WiiMessageSettingsScreen *screen) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        screen->timeoutTimer = 0;
        switch (result) {
        case 0:
            switch (screen->app->responseStatus) {
            case 0:
                switch (screen->app->responseResult) {
                case 1:
                    screen->state = WMS_STATE_REGISTRATION_CODE_SENT;
                    break;
                case 2:
                    WiiMessageSettingsScreen_HideWaitingIcon(screen);
                    screen->registrationError = -5001;
                    screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                    break;
                case 0:
                    WiiMessageSettingsScreen_HideWaitingIcon(screen);
                    screen->registrationError = -5002;
                    screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                    break;
                case 3:
                    WiiMessageSettingsScreen_HideWaitingIcon(screen);
                    screen->registrationError = -5003;
                    screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                    break;
                default:
                    CommState_ShowRestartErrorAndHalt();
                    break;
                }
                break;
            case 1:
                WiiMessageSettingsScreen_HideWaitingIcon(screen);
                screen->registrationError = -5004;
                screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                break;
            case 2:
                WiiMessageSettingsScreen_HideWaitingIcon(screen);
                screen->registrationError = -5005;
                screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                break;
            default:
                WiiMessageSettingsScreen_HideWaitingIcon(screen);
                CommState_ShowRestartErrorAndHalt();
                break;
            }
            break;
        case 1:
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            screen->registrationError = result;
            screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
            break;
        case -1:
        case 2:
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            screen->registrationError = result;
            screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
            break;
        case -15:
        case -12:
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            screen->registrationError = result;
            screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
            break;
        case -14:
        case -2:
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            screen->registrationError = result;
            screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
            break;
        default:
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        screen->timeoutTimer++;
        if (screen->timeoutTimer == 3600) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_RegistrationCodeSent(WiiMessageSettingsScreen *screen) {
    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_HideWaitingIcon(screen);
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00013, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
        screen->subState++;
        break;
    case 2: {
        int input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->subState++;
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->state = WMS_STATE_CONFIRM_CANCEL_REGISTRATION;
        }
        break;
    }
    case 3:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00017, 1, 0xF0F);
        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_START_REGISTRATION_CODE_ENTRY);
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartRegistrationCodeEntry(WiiMessageSettingsScreen *screen) {
    WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_REGISTRATION_CODE_ENTRY, WII_MESSAGE_SETTINGS_APP_WII_NUMBER_ENTRY);
    WiiMessageSettings_SetScreenStartState(screen->app, WMS_STATE_CONFIRM_REGISTRATION_CODE);
    screen->state = WMS_STATE_FADE_OUT_ONLINE;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_ConfirmCancelRegistration(WiiMessageSettingsScreen *screen) {
    int input;

    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }

    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00014, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
        screen->subState++;
        break;
    case 2:
        input = YesNoPrompt_HandleInput(screen->yesNoPrompt);
        if (input == YESNORESPONSE_YES) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            WiiMessageSettingsScreen_SetState(screen, WMS_STATE_DISCONNECT_AND_WAIT, WMS_STATE_MAIN_MENU);
        } else if (input == YESNORESPONSE_NO) {
            YesNoPrompt_Destroy(screen->yesNoPrompt);
            screen->state = WMS_STATE_REGISTRATION_CODE_SENT;
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_ConfirmRegistrationCode(WiiMessageSettingsScreen *screen) {
    int result;

    if (WiiMessageSettings_GetRegistrationCode(screen->app) == -1) {
        screen->state = WMS_STATE_CONFIRM_CANCEL_REGISTRATION;
        return FALSE;
    }
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00018, 0, 0xF0F);
        WiiMessageSettingsScreen_ShowWaitingIcon(screen);
        WiiMessageSettings_SetRequestRegistrationCode(screen->app);
        GtsServer_RequestSetProfile(&screen->app->request, &screen->app->responseStatus);
        screen->subState++;
        break;
    case 1:
        if (GtsServer_IsRequestDone()) {
            result = GtsServer_GetResult();
            screen->timeoutTimer = 0;
            WiiMessageSettingsScreen_HideWaitingIcon(screen);
            switch (result) {
            case 0:
                switch (screen->app->responseStatus) {
                case 0:
                    switch (screen->app->responseResult) {
                    case 0:
                        screen->subState++;
                        break;
                    case 3:
                        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00019, 1, 0xF0F);
                        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_CONFIRM_CANCEL_REGISTRATION);
                        break;
                    case 1:
                        screen->registrationError = -5006;
                        screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                        break;
                    case 2:
                        screen->registrationError = -5007;
                        screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                        break;
                    default:
                        CommState_ShowRestartErrorAndHalt();
                        break;
                    }
                    break;
                case 1:
                    screen->registrationError = -5010;
                    screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                    break;
                case 2:
                    screen->registrationError = -5011;
                    screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                    break;
                default:
                    GF_ASSERT(0);
                    CommState_ShowRestartErrorAndHalt();
                    break;
                }
                break;
            case 1:
                screen->registrationError = result;
                screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                break;
            case -1:
            case 2:
                screen->registrationError = result;
                screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                break;
            case -15:
            case -12:
                screen->registrationError = result;
                screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                break;
            case -14:
            case -2:
                screen->registrationError = result;
                screen->state = WMS_STATE_SHOW_REGISTRATION_ERROR;
                break;
            default:
                CommState_ShowRestartErrorAndHalt();
                break;
            }
        } else {
            screen->timeoutTimer++;
            if (screen->timeoutTimer == 3600) {
                CommState_ShowRestartErrorAndHalt();
            }
        }
        break;
    case 2:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00020, 1, 0xF0F);
        screen->subState++;
        break;
    case 3:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            WiiMessageSettingsScreen_SetState(screen, WMS_STATE_DISCONNECT_AND_WAIT, WMS_STATE_START_PASSWORD_ENTRY);
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_StartPasswordEntry(WiiMessageSettingsScreen *screen) {
    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }

    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00021, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        WiiMessageSettings_SetNextApp(screen->app, WII_MESSAGE_SETTINGS_APP_SET_PASSWORD, WII_MESSAGE_SETTINGS_APP_REGISTRATION_CODE_ENTRY);
        WiiMessageSettings_SetScreenStartState(screen->app, WMS_STATE_SAVE_SETTINGS);
        screen->state = WMS_STATE_FADE_OUT_ONLINE;
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_SaveSettings(WiiMessageSettingsScreen *screen) {
    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }

    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00024, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        WiiMessageSettings_SaveWiiAddress(screen->app);
        WiiMessageSettings_SaveRegistrationCode(screen->app);
        WiiMessageSettings_SavePassword(screen->app);
        WiiMessageSettingsScreen_SetState(screen, WMS_STATE_SAVE_GAME, WMS_STATE_MAIN_MENU);
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_SaveGame(WiiMessageSettingsScreen *screen) {
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00032, 0, 0xF0F);
        WiiMessageSettingsScreen_ShowWaitingIcon(screen);
        screen->subState++;
        break;
    case 1:
        if (SaveGameNormal(screen->app->saveData) == WRITE_STATUS_SUCCESS) {
            PlayerProfile *profile = Save_PlayerData_GetProfile(screen->app->saveData);
            BufferPlayersName(screen->msgFormat, 0, profile);
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00033, 0, 0xF0F);
            PlaySE(SEQ_SE_DP_SAVE);
            Save_ClearStatusFlags(screen->app->saveData);
        } else {
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00034, 0, 0xF0F);
        }
        WiiMessageSettingsScreen_HideWaitingIcon(screen);
        screen->subState++;
        break;
    case 2:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            screen->subState++;
        }
        break;
    case 3:
        screen->waitTimer++;
        if (screen->waitTimer > 60) {
            screen->waitTimer = 0;
            screen->state = screen->nextState;
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_DisconnectAndWait(WiiMessageSettingsScreen *screen) {
    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }

    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00015, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        DWC_CleanupInet();
        WirelessStatusIcon_Destroy();
        CommState_FreeWiiMessageWfcSession();
        Sys_ClearSleepDisableFlag(4);
        if (screen->app->serverSessionStarted == TRUE) {
            GtsServer_Exit();
            screen->app->serverSessionStarted = FALSE;
        }
        screen->subState++;
        break;
    case 2:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00016, 1, 0xF0F);
            screen->subState++;
        }
        break;
    case 3:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            screen->subState++;
        }
        break;
    case 4:
        screen->timer++;
        if (screen->timer > 30) {
            screen->state = screen->nextState;
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_ShowConnectionError(WiiMessageSettingsScreen *screen) {
    s32 msgId = WifiConnection_ClassifyErrorCode(-screen->connectionErrorCode, screen->connectionErrorType);
    WiiMessageSettingsScreen_PrintErrorCode(screen, msgId, -screen->connectionErrorCode);
    screen->state = WMS_STATE_WAIT_CLOSE_ERROR;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitCloseError(WiiMessageSettingsScreen *screen) {
    u32 keys = gSystem.newKeys;

    if ((keys & PAD_BUTTON_A) || (keys & PAD_BUTTON_B)) {
        EraseFrameAndWindow1(&screen->errorWindow, FALSE);
        screen->state = WMS_STATE_MAIN_MENU;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_FadeOut(WiiMessageSettingsScreen *screen) {
    if (screen->state != WMS_STATE_FADE_OUT_ONLINE) {
        CommState_FreeWiiMessageWfcSession();
    }
    WirelessStatusIcon_Destroy();
    WiiMessageSettingsScreen_HideWaitingIcon(screen);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_116);
    screen->state = WMS_STATE_MAIN_MENU;
    return TRUE;
}

static BOOL WiiMessageSettingsScreen_ShowYesNoPrompt(WiiMessageSettingsScreen *screen) {
    screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
    screen->state = screen->nextState;
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_ShowRegistrationError(WiiMessageSettingsScreen *screen) {
    int fromGtsMsgs = 0;
    int msgId;

    switch (screen->registrationError) {
    case 1:
        msgId = msg_0188_00054;
        break;
    case -1:
    case 2:
        msgId = msg_0188_00055;
        break;
    case -14:
    case -2:
        msgId = msg_0188_00057;
        break;
    case -15:
    case -12:
    case -5:
    case -3:
    default:
        msgId = msg_0188_00056;
        break;
    case -5001:
        msgId = msg_0775_00181;
        fromGtsMsgs++;
        break;
    case -5002:
        msgId = msg_0775_00182;
        fromGtsMsgs++;
        break;
    case -5003:
        msgId = msg_0775_00182;
        fromGtsMsgs++;
        break;
    case -5004:
        msgId = msg_0775_00183;
        fromGtsMsgs++;
        break;
    case -5005:
        msgId = msg_0775_00184;
        fromGtsMsgs++;
        break;
    case -5006:
        msgId = msg_0775_00182;
        fromGtsMsgs++;
        break;
    case -5007:
        msgId = msg_0775_00182;
        fromGtsMsgs++;
        break;
    case -5010:
        msgId = msg_0775_00183;
        fromGtsMsgs++;
        break;
    case -5011:
        msgId = msg_0775_00184;
        fromGtsMsgs++;
        break;
    }
    if (!fromGtsMsgs) {
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msgId, 1, 0xF0F);
    } else {
        WiiMessageSettingsScreen_PrintMessage(screen, screen->gtsMsgData, msgId, 1, 0xF0F);
    }
    WiiMessageSettingsScreen_SetState(screen, WMS_STATE_WAIT_MESSAGE, WMS_STATE_DISCONNECT_AND_QUIT);
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_DisconnectAndQuit(WiiMessageSettingsScreen *screen) {
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00015, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            CommState_FreeWiiMessageWfcSession();
            DWC_CleanupInet();
            WirelessStatusIcon_Destroy();
            Sys_ClearSleepDisableFlag(4);
            if (screen->app->serverSessionStarted == TRUE) {
                GtsServer_Exit();
                screen->app->serverSessionStarted = FALSE;
            }
            screen->subState++;
        }
        break;
    case 2:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msg_0188_00016, 1, 0xF0F);
        screen->subState++;
        break;
    case 3:
        if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
            screen->subState++;
        }
        break;
    default:
        screen->timer++;
        if (screen->timer > 30) {
            WiiMessageSettings_Quit(screen->app);
            screen->state = WMS_STATE_FADE_OUT;
        }
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitMessage(WiiMessageSettingsScreen *screen) {
    if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
        screen->state = screen->nextState;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitMessageAndDelay(WiiMessageSettingsScreen *screen) {
    if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
        if (screen->timer > 30) {
            screen->state = screen->nextState;
        }
        screen->timer++;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_WaitMessageAndShowYesNo(WiiMessageSettingsScreen *screen) {
    if (!WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId)) {
        screen->yesNoPrompt = WiiMessageSettingsScreen_CreateYesNoPrompt(screen->bgConfig, 0x234, 0);
        screen->state = screen->nextState;
    }
    return FALSE;
}

static void WiiMessageSettingsScreen_PrintMessage(WiiMessageSettingsScreen *screen, MsgData *msgData, int msgId, u32 textSpeed, u32 unused) {
    String *string = NewString_ReadMsgData(msgData, msgId);
    StringExpandPlaceholders(screen->msgFormat, screen->messageBuffer, string);
    String_Delete(string);
    FillWindowPixelBuffer(&screen->messageWindow, 15);
    DrawFrameAndWindow2(&screen->messageWindow, FALSE, 1, 10);
    screen->textPrinterId = AddTextPrinterParameterized(&screen->messageWindow, 1, screen->messageBuffer, 0, 0, textSpeed, NULL);
    screen->timer = 0;
    if (textSpeed == TEXT_SPEED_NOTRANSFER || textSpeed == TEXT_SPEED_INSTANT) {
        screen->textPrinterId = WII_MESSAGE_SETTINGS_TEXT_PRINTER_NONE;
    }
}

static BOOL WiiMessageSettingsScreen_IsPrinterActive(u32 printerId) {
    if (printerId == WII_MESSAGE_SETTINGS_TEXT_PRINTER_NONE || !TextPrinterCheckActive(printerId)) {
        return FALSE;
    }
    return TRUE;
}

static BOOL WiiMessageSettingsScreen_PrintWiiNumberReentry(WiiMessageSettingsScreen *screen) {
    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }
    switch (screen->subState) {
    case 0:
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, WiiMessageSettings_GetWiiNumberEntryState(screen->app) == WII_NUMBER_ENTRY_ENTERED_ONCE ? msg_0188_00038 : msg_0188_00039, 1, 0xF0F);
        screen->subState++;
        break;
    case 1:
        screen->state = WMS_STATE_START_WII_NUMBER_ENTRY;
        break;
    }
    return FALSE;
}

static BOOL WiiMessageSettingsScreen_CheckPassword(WiiMessageSettingsScreen *screen) {
    WiiMessageSettings *app = screen->app;

    if (WiiMessageSettingsScreen_IsPrinterActive(screen->textPrinterId) == TRUE) {
        return FALSE;
    }
    switch (screen->subState) {
    case 0: {
        int msgId;
        int password = WiiMessageSettings_GetPassword(app);
        if (password == Save_WiiMessage_GetParam(app->saveData, 3)) {
            u32 groups[4];
            u32 i;
            WiiNumber_ParseDigitGroups(Save_WiiMessage_Get(app->saveData)->wiiAddress, groups, HEAP_ID_115);
            for (i = 0; i < 4; i++) {
                BufferIntegerAsString(screen->msgFormat, i, groups[i], 4, PRINTING_MODE_LEADING_ZEROS, TRUE);
            }
            msgId = msg_0188_00041;
        } else {
            msgId = msg_0188_00040;
        }
        WiiMessageSettingsScreen_PrintMessage(screen, screen->msgData, msgId, 1, 0xF0F);
        screen->subState++;
        break;
    }
    case 1:
        screen->state = WMS_STATE_MAIN_MENU;
        break;
    }
    return FALSE;
}

// alignment 0: left at x, 1: centered, 2: right aligned
static int WiiMessageSettingsScreen_GetAlignedX(Window *window, String *string, int x, int alignment, u32 unused, u32 fontId) {
    switch (alignment) {
    case 1: {
        int width = FontID_String_GetWidth(fontId, string, 0);
        x = (window->width * 8 - width) / 2;
        break;
    }
    case 2: {
        int width = FontID_String_GetWidth(fontId, string, 0);
        x = window->width * 8 - width;
        break;
    }
    }
    return x;
}

static int WiiMessageSettingsScreen_PrintAligned(Window *window, String *string, int x, int y, int alignment, u32 color) {
    int alignedX = WiiMessageSettingsScreen_GetAlignedX(window, string, x, alignment, color, 1);
    return AddTextPrinterParameterizedWithColor(window, 1, string, alignedX, y, TEXT_SPEED_INSTANT, color, NULL);
}

static void WiiMessageSettingsScreen_PrintError(WiiMessageSettingsScreen *screen, int msgId) {
    String *string = String_New(256, HEAP_ID_116);
    ReadMsgDataIntoString(screen->wfcErrorMsgData, msgId, string);
    StringExpandPlaceholders(screen->msgFormat, screen->errorBuffer, string);
    FillWindowPixelBuffer(&screen->errorWindow, 15);
    DrawFrameAndWindow1(&screen->errorWindow, TRUE, 31, 11);
    AddTextPrinterParameterized(&screen->errorWindow, 1, screen->errorBuffer, 0, 0, TEXT_SPEED_INSTANT, NULL);
    screen->textPrinterId = WII_MESSAGE_SETTINGS_TEXT_PRINTER_NONE;
    String_Delete(string);
}

static void WiiMessageSettingsScreen_PrintErrorCode(WiiMessageSettingsScreen *screen, int msgId, int errorCode) {
    if (msgId == -1) {
        msgId = msg_0800_00011;
    }
    BufferIntegerAsString(screen->msgFormat, 0, errorCode, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
    ClearFrameAndWindow2(&screen->messageWindow, TRUE);
    WiiMessageSettingsScreen_PrintError(screen, msgId);
}

static void WiiMessageSettingsScreen_RegisteredMenuMoveCursor(ListMenu *menu, s32 index, BOOL onInit) {
    if (!onInit) {
        PlaySE(SEQ_SE_DP_SELECT);
    }
}

static void WiiMessageSettingsScreen_UnregisteredMenuMoveCursor(ListMenu *menu, s32 index, BOOL onInit) {
    if (!onInit) {
        PlaySE(SEQ_SE_DP_SELECT);
    }
}
