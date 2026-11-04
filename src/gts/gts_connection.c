#include "global.h"

#include "constants/dwc_status.h"

#include "dwc/dwc_account_internal.h"
#include "dwc/dwc_main_internal.h"
#include "dwc/net_common_internal.h"
#include "dwc/stats_upload_internal.h"
#include "gts/gts_internal.h"
#include "gts/gts_server.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0775.h"
#include "msgdata/msg/msg_0778.h"
#include "msgdata/msg/msg_0800.h"

#include "bg_window.h"
#include "comm_state_internal.h"
#include "font.h"
#include "friend_roster.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "list_menu_2d.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "palette.h"
#include "render_window.h"
#include "sav_system_info.h"
#include "save_wii_message.h"
#include "screen_fade.h"
#include "string_util.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "wifi_connection.h"
#include "wireless_status_icon.h"
#include "yes_no_prompt.h"

// Connecting to Nintendo Wi-Fi Connection (screen 0): the first screen of the GTS, and the last one, which
// disconnects.

enum GtsConnectionDisconnectStep {
    GTS_DISCONNECT_PRINT_DISCONNECTING,
    GTS_DISCONNECT_DISCONNECT,
    GTS_DISCONNECT_PRINT_DISCONNECTED,
    GTS_DISCONNECT_WAIT_MESSAGE,
};

typedef enum GtsConnectionState {
    GTS_CONNECTION_STATE_ASK_CONNECT,
    GTS_CONNECTION_STATE_HANDLE_CONNECT_PROMPT,
    GTS_CONNECTION_STATE_START_CONNECT,
    GTS_CONNECTION_STATE_WAIT_CONNECT,
    GTS_CONNECTION_STATE_START_AUTH,
    GTS_CONNECTION_STATE_WAIT_AUTH,
    GTS_CONNECTION_STATE_INIT_SERVER,
    GTS_CONNECTION_STATE_SEND_INFO,
    GTS_CONNECTION_STATE_WAIT_INFO,
    GTS_CONNECTION_STATE_SEND_SET_PROFILE,
    GTS_CONNECTION_STATE_WAIT_SET_PROFILE,
    GTS_CONNECTION_STATE_FADE_OUT,
    GTS_CONNECTION_STATE_WAIT_TEXT,
    GTS_CONNECTION_STATE_WAIT_TEXT_AND_SHOW_YES_NO,
    GTS_CONNECTION_STATE_HANDLE_EXIT_PROMPT,
    GTS_CONNECTION_STATE_ASK_DISCONNECT,
    GTS_CONNECTION_STATE_HANDLE_DISCONNECT_MENU,
    GTS_CONNECTION_STATE_PRINT_DISCONNECTING,
    GTS_CONNECTION_STATE_DISCONNECT,
    GTS_CONNECTION_STATE_PRINT_DISCONNECTED,
    GTS_CONNECTION_STATE_WAIT_TEXT_AND_DELAY,
    GTS_CONNECTION_STATE_PRINT_SERVER_ERROR,
    GTS_CONNECTION_STATE_DISCONNECT_AFTER_ERROR,
    GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR,
    GTS_CONNECTION_STATE_WAIT_CLOSE_ERROR,
} GtsConnectionState;

static void GtsConnection_InitBgs(BgConfig *bgConfig);
static void GtsConnection_FreeBgs(BgConfig *bgConfig);
static void GtsConnection_LoadGraphics(GtsApp *app);
static void GtsConnection_AnimatePaletteTask(SysTask *task, GtsPaletteAnim *anim);
static void GtsConnection_CreateWindows(GtsApp *app);
static void GtsConnection_RemoveWindows(GtsApp *app);
static void GtsConnection_CreateStrings(GtsApp *app);
static void GtsConnection_DeleteStrings(GtsApp *app);
static int Gts_GetAlignedX(Window *window, String *string, int x, int align, u32 unused, u32 fontId);
static void Gts_PrintAlignedFont1(Window *window, String *string, int x, int y, int align, u32 color);
static void GtsConnection_PrintError(GtsApp *app, int msgId);
static void GtsConnection_PrintErrorCode(GtsApp *app, int msgId, int errorCode);

enum GtsAppState GtsConnection_AskConnect(GtsApp *app);
enum GtsAppState GtsConnection_HandleConnectPrompt(GtsApp *app);
enum GtsAppState GtsConnection_AskDisconnect(GtsApp *app);
enum GtsAppState GtsConnection_HandleDisconnectMenu(GtsApp *app);
enum GtsAppState GtsConnection_PrintDisconnecting(GtsApp *app);
enum GtsAppState GtsConnection_Disconnect(GtsApp *app);
enum GtsAppState GtsConnection_PrintDisconnected(GtsApp *app);
void GtsConnection_StartConnect(GtsApp *app);
enum GtsAppState GtsConnection_WaitConnect(GtsApp *app);
enum GtsAppState GtsConnection_StartAuth(GtsApp *app);
enum GtsAppState GtsConnection_WaitAuth(GtsApp *app);
enum GtsAppState GtsConnection_InitServer(GtsApp *app);
enum GtsAppState GtsConnection_SendInfo(GtsApp *app);
enum GtsAppState GtsConnection_WaitInfo(GtsApp *app);
enum GtsAppState GtsConnection_SendSetProfile(GtsApp *app);
enum GtsAppState GtsConnection_WaitSetProfile(GtsApp *app);
enum GtsAppState GtsConnection_ShowConnectionError(GtsApp *app);
enum GtsAppState GtsConnection_WaitCloseError(GtsApp *app);
enum GtsAppState GtsConnection_FadeOut(GtsApp *app);
enum GtsAppState GtsConnection_HandleExitPrompt(GtsApp *app);
enum GtsAppState GtsConnection_PrintServerError(GtsApp *app);
enum GtsAppState GtsConnection_DisconnectAfterError(GtsApp *app);
enum GtsAppState GtsConnection_WaitText(GtsApp *app);
enum GtsAppState GtsConnection_WaitTextAndDelay(GtsApp *app);
enum GtsAppState GtsConnection_WaitTextAndShowYesNo(GtsApp *app);

BOOL GtsSelector_HasCountriesInGroup(GtsSelector *selector, int group) {
    int first = gGtsSelectorGroupStarts[group];
    int count = gGtsSelectorLetterGroups[group].count;
    if (count > 0) {
        int i = 0;
        if (i < count) {
            do {
                if (GtsSelector_CountCountriesOfLetter(selector, first + i) > 0) {
                    return TRUE;
                }
                i++;
            } while (i < gGtsSelectorLetterGroups[group].count);
        }
    } else if (GtsSelector_CountCountriesOfLetter(selector, first) > 0) {
        return TRUE;
    }
    return FALSE;
}

enum GtsAppState GtsConnection_Init(GtsApp *app, int state) {
    GtsArgs *args;

    GtsConnection_CreateStrings(app);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_61);
    GtsConnection_InitBgs(app->bgConfig);
    GtsConnection_LoadGraphics(app);
    GtsConnection_CreateWindows(app);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG3, GF_PLANE_TOGGLE_OFF);
    if (!DWC_CheckInet()) {
        args = app->args;
        if (args->connectDirectly != 0) {
            // Connect without asking.
            CommState_InitWfcSession(args->saveData);
            Gts_PrintMessage(app, app->wifiMsgData, msg_0778_00001, 1, 0xF0F); // Connecting to Nintendo Wi-Fi Connection...
            Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT, GTS_CONNECTION_STATE_START_CONNECT);
            Gts_CreateWaitingIcon(app);
        } else {
            Sys_ClearSleepDisableFlag(4);
            app->state = GTS_CONNECTION_STATE_ASK_CONNECT;
        }
    } else {
        // Back from the GTS: disconnect.
        args = app->args;
        CommState_InitWfcSession(args->saveData);
        Gts_CreateWirelessStatusIcon(app);
        app->state = GTS_CONNECTION_STATE_PRINT_DISCONNECTING;
    }
    return GTS_APP_STATE_WAIT_FADE_IN;
}

enum GtsAppState GtsConnection_Main(GtsApp *app, int state) {
    int prevState;
    enum GtsAppState result;

    WirelessStatusIcon_SetLevel(Gts_GetWifiIconLevel());
    prevState = app->state;
    result = gGtsConnectionStates[prevState](app);
    if (prevState != app->state) {
        app->subState = 0;
        app->subTimer = 0;
    }
    return result;
}

enum GtsAppState GtsConnection_Exit(GtsApp *app, int state) {
    if (app->paletteAnim.task != NULL) {
        SysTask_Destroy(app->paletteAnim.task);
        app->paletteAnim.task = NULL;
        app->paletteAnim.active = FALSE;
    }
    GtsConnection_DeleteStrings(app);
    GtsConnection_RemoveWindows(app);
    GtsConnection_FreeBgs(app->bgConfig);
    app->paletteAnim.active = FALSE;
    Gts_SwitchScreen(app);
    if (app->screen == GTS_SCREEN_CONNECTION) {
        return GTS_APP_STATE_END;
    }
    return GTS_APP_STATE_INIT_SCREEN;
}

static void GtsConnection_InitBgs(BgConfig *bgConfig) {
    BgTemplate bg0 = gGtsConnectionBg0Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &bg0, GF_BG_TYPE_TEXT);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    {
        BgTemplate bg1 = gGtsConnectionBg1Template;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg1, GF_BG_TYPE_TEXT);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    }
    {
        BgTemplate subBg0 = gGtsConnectionSubBg0Template;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &subBg0, GF_BG_TYPE_TEXT);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    }
    {
        BgTemplate subBg1 = gGtsConnectionSubBg1Template;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &subBg1, GF_BG_TYPE_TEXT);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    }
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_61);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_61);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_OFF);
}

static void GtsConnection_FreeBgs(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
}

static void GtsConnection_LoadGraphics(GtsApp *app) {
    NNSG2dPaletteData *pltt;
    NARC *narc;
    int group;
    int step;
    int fraction;
    int last;
    u16 *dest;
    u16 *src;
    BgConfig *bgConfig = app->bgConfig;
    void *plttFile;
    int color;

    narc = NARC_New(NARC_a_0_8_8, HEAP_ID_61);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_61);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_61);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_61);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_61);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 14, Options_GetFrame(app->args->options), HEAP_ID_61);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 31, 11, 0, HEAP_ID_61);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, HEAP_ID_61);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x600, FALSE, HEAP_ID_61);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 11, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_61);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 12, bgConfig, GF_BG_LYR_SUB_1, 0, 0x600, FALSE, HEAP_ID_61);
    BG_SetMaskColor(GF_BG_LYR_MAIN_0, RGB_BLACK);
    BG_SetMaskColor(GF_BG_LYR_SUB_0, RGB_BLACK);

    MI_CpuFill8(&app->paletteAnim, 0, sizeof(GtsPaletteAnim));
    plttFile = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, &pltt, HEAP_ID_61);
    MIi_CpuCopy16(pltt->pRawData, app->paletteAnim.basePltt, sizeof(app->paletteAnim.basePltt));
    MIi_CpuCopy16(pltt->pRawData, app->paletteAnim.fadePltt, sizeof(app->paletteAnim.basePltt));
    Heap_Free(plttFile);

    step = 0;
    group = 0;
    dest = app->paletteAnim.fadePltt;
    src = app->paletteAnim.basePltt;
    while (group < 3) {
        fraction = 0;
        last = 0;
        while (TRUE) {
            GF_ASSERT(step < 21);
            for (color = 1; color < 16; color++) {
                BlendPalette(&src[color], &dest[color], 1, fraction >> 8, app->paletteAnim.basePltt[(group + 1) * 16 + color]);
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
        group++;
    }
    DC_FlushRange(app->paletteAnim.fadePltt, sizeof(app->paletteAnim.fadePltt));
    app->paletteAnim.active = TRUE;
    app->paletteAnim.screens = 0;
    app->paletteAnim.task = SysTask_CreateOnVBlankQueue((SysTaskFunc)GtsConnection_AnimatePaletteTask, &app->paletteAnim, 20);
    NARC_Delete(narc);
}

static void GtsConnection_AnimatePaletteTask(SysTask *task, GtsPaletteAnim *anim) {
    if (!anim->active) {
        return;
    }
    anim->skipFrame ^= 1;
    if (anim->skipFrame & 1) {
        return;
    }
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

static void GtsConnection_CreateWindows(GtsApp *app) {
    AddWindowParameterized(app->bgConfig, &app->boxNameWindow, GF_BG_LYR_MAIN_0, 4, 4, 23, 16, 13, 0x94);
    FillWindowPixelBuffer(&app->boxNameWindow, 0);
    AddWindowParameterized(app->bgConfig, &app->titleWindow, GF_BG_LYR_MAIN_0, 4, 1, 24, 2, 13, 0x204);
    FillWindowPixelBuffer(&app->titleWindow, 0);
    Gts_PrintAlignedFont1(&app->titleWindow, app->titleString, 0, 1, 1, MAKE_TEXT_COLOR(15, 14, 0));
    AddWindowParameterized(app->bgConfig, &app->waitingIconWindow, GF_BG_LYR_MAIN_0, 2, 19, 27, 4, 13, 0x28);
    FillWindowPixelBuffer(&app->waitingIconWindow, 0);
}

static void GtsConnection_RemoveWindows(GtsApp *app) {
    RemoveWindow(&app->waitingIconWindow);
    RemoveWindow(&app->titleWindow);
    RemoveWindow(&app->boxNameWindow);
}

static void GtsConnection_CreateStrings(GtsApp *app) {
    app->msgBuffer = String_New(180, HEAP_ID_61);
    app->errorBuffer = String_New(256, HEAP_ID_61);
    app->titleString = NewString_ReadMsgData(app->gtsMsgData, msg_0775_00031); // Nintendo Wi-Fi Connection
}

static void GtsConnection_DeleteStrings(GtsApp *app) {
    String_Delete(app->titleString);
    String_Delete(app->errorBuffer);
    String_Delete(app->msgBuffer);
}

// Also starts counting the Pokemon in the PC while the player answers (without resetting the count).
enum GtsAppState GtsConnection_AskConnect(GtsApp *app) {
    Gts_PrintMessage(app, app->wifiErrorMsgData, msg_0800_00017, 1, 0xF0F); // Connect to Nintendo Wi-Fi Connection?
    Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT_AND_SHOW_YES_NO, GTS_CONNECTION_STATE_HANDLE_CONNECT_PROMPT);
    app->countingBox = 1;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_HandleConnectPrompt(GtsApp *app) {
    YesNoResponse response = Gts_HandleYesNoPrompt(app);
    if (response == YESNORESPONSE_YES) {
        YesNoPrompt_Destroy(app->yesNoPrompt);
        Gts_PrintMessage(app, app->wifiMsgData, msg_0778_00001, 1, 0xF0F); // Connecting to Nintendo Wi-Fi Connection...
        Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT, GTS_CONNECTION_STATE_START_CONNECT);
        Gts_CreateWaitingIcon(app);
    } else if (response == YESNORESPONSE_NO) {
        YesNoPrompt_Destroy(app->yesNoPrompt);
        CommState_FreeWfcSession();
        Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
        app->state = GTS_CONNECTION_STATE_FADE_OUT;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_AskDisconnect(GtsApp *app) {
    Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00007, 1, 0xF0F); // Is it OK to disconnect from Nintendo Wi-Fi Connection?
    Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT_AND_SHOW_YES_NO, GTS_CONNECTION_STATE_HANDLE_DISCONNECT_MENU);
    return GTS_APP_STATE_RUN_SCREEN;
}

// Reads a 2D menu that nothing in the GTS creates (the state before shows a Yes/No prompt instead). Cancel goes
// back to the GTS (screen 7 checks its status) when connected, anything else disconnects and leaves the app.
enum GtsAppState GtsConnection_HandleDisconnectMenu(GtsApp *app) {
    int result = Handle2dMenuInput_DeleteOnFinish(app->disconnectMenu, HEAP_ID_61);
    if (result != -1) {
        if (result == -2) {
            if (!DWC_CheckInet()) {
                app->state = GTS_CONNECTION_STATE_ASK_CONNECT;
            } else {
                Gts_SetNextScreen(app, GTS_SCREEN_TRANSACTION, 11);
                app->statusCheckCaller = 1;
                app->state = GTS_CONNECTION_STATE_FADE_OUT;
            }
        } else {
            if (DWC_CheckInet()) {
                DWC_CleanupInet();
            }
            CommState_FreeWfcSession();
            Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
            app->state = GTS_CONNECTION_STATE_FADE_OUT;
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_PrintDisconnecting(GtsApp *app) {
    Gts_PrintMessage(app, app->wifiErrorMsgData, msg_0800_00026, 1, 0xF0F); // Disconnecting from Nintendo Wi-Fi Connection.
    Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT, GTS_CONNECTION_STATE_DISCONNECT);
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_Disconnect(GtsApp *app) {
    CommState_FreeWfcSession();
    DWC_CleanupInet();
    Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
    app->state = GTS_CONNECTION_STATE_PRINT_DISCONNECTED;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_PrintDisconnected(GtsApp *app) {
    WirelessStatusIcon_Destroy();
    Gts_PrintMessage(app, app->wifiErrorMsgData, msg_0800_00027, 1, 0xF0F); // You have been disconnected from Nintendo Wi-Fi Connection.
    Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT_AND_DELAY, GTS_CONNECTION_STATE_FADE_OUT);
    return GTS_APP_STATE_RUN_SCREEN;
}

// BUG: returns no value, although it is a state function: what Gts_Main gets back is undefined.
void GtsConnection_StartConnect(GtsApp *app) {
    CommState_InitWfcSession(app->args->saveData);
    Sys_SetSleepDisableFlag(4);
    Gts_CreateWirelessStatusIcon(app);
    DWC_InitInetEx(&app->wifiConnection, 2, 1, 20);
    DWC_SetAuthServer(2);
    DWC_ConnectInetAsync();
    app->state = GTS_CONNECTION_STATE_WAIT_CONNECT;
}

enum GtsAppState GtsConnection_WaitConnect(GtsApp *app) {
    struct {
        int error;
        int errorType;
        int errorCode;
        NetApInfo apInfo;
    } locals;

    DWC_ProcessInet();
    if (DWC_CheckInet()) {
        switch (DWC_GetInetStatus()) {
        case DWC_CONNECTINET_STATE_ERROR:
            app->connectionResult = DWC_GetLastErrorEx(&locals.errorCode, &locals.errorType);
            app->connectionErrorCode = locals.errorCode;
            app->connectionErrorType = locals.errorType;
            DWC_ClearError();
            DWC_CleanupInet();
            Gts_DeleteWaitingIcon(app);
            app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
            break;
        case DWC_CONNECTINET_STATE_NOT_INITIALIZED:
        case DWC_CONNECTINET_STATE_IDLE:
        case DWC_CONNECTINET_STATE_OPERATING:
        case DWC_CONNECTINET_STATE_OPERATED:
        case DWC_CONNECTINET_STATE_DISCONNECTING:
        case DWC_CONNECTINET_STATE_DISCONNECTED:
        case DWC_CONNECTINET_STATE_FATAL_ERROR:
        default:
            DWC_GetLastError(&locals.error);
            Gts_DeleteWaitingIcon(app);
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            app->serverResult = -2;
            break;
        case DWC_CONNECTINET_STATE_CONNECTED:
            DWC_GetApInfo(&locals.apInfo);
            app->state = GTS_CONNECTION_STATE_START_AUTH;
            break;
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_StartAuth(GtsApp *app) {
    DWC_NASLoginAsync();
    app->state = GTS_CONNECTION_STATE_WAIT_AUTH;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_WaitAuth(GtsApp *app) {
    int errorCode;
    int errorType;
    int result;

    switch (DWC_NASLoginProcess()) {
    case DWC_NASLOGIN_STATE_SUCCESS:
        app->state = GTS_CONNECTION_STATE_INIT_SERVER;
        break;
    case DWC_NASLOGIN_STATE_DIRTY:
    case DWC_NASLOGIN_STATE_ERROR:
    case DWC_NASLOGIN_STATE_CANCELED:
        Gts_DeleteWaitingIcon(app);
        result = DWC_GetLastErrorEx(&errorCode, &errorType);
        app->connectionResult = result;
        app->connectionErrorCode = errorCode;
        DWC_ClearError();
        DWC_CleanupInet();
        app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
        switch (errorType) {
        case DWC_ETYPE_LIGHT:
        case DWC_ETYPE_SHOW_ERROR:
            app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_GHTTP:
            DWC_ShutdownGHTTP();
            app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
            break;
        case DWC_ETYPE_DISCONNECT:
            app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_FM:
            DWC_ShutdownFriendsMatch();
            app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_ND:
        case DWC_ETYPE_FATAL:
            CommState_ShowRestartErrorAndHalt();
            break;
        }
        if (errorCode < -20000 && errorCode >= -29999) {
            app->state = GTS_CONNECTION_STATE_SHOW_CONNECTION_ERROR;
        }
        break;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_InitServer(GtsApp *app) {
    void *userData;
    u32 profileId;

    userData = FriendRoster_GetUserData(app->args->friendRoster);
    if (Save_SysInfo_GetDwcProfileId(app->args->sysInfo) == 0) {
        Save_SysInfo_SetDwcProfileId(app->args->sysInfo, app->args->gsProfileId);
    }
    profileId = Save_SysInfo_GetDwcProfileId(app->args->sysInfo);
    {
        u64 friendKey = DWC_CreateFriendKey(userData);
        GtsServer_Init(profileId, (u32)friendKey, (u32)(friendKey >> 32));
    }
    app->state = GTS_CONNECTION_STATE_SEND_INFO;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_SendInfo(GtsApp *app) {
    GtsServer_RequestInfo();
    app->state = GTS_CONNECTION_STATE_WAIT_INFO;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

// Each request is given a minute; then the connection is dropped (CommState_ShowRestartErrorAndHalt).
enum GtsAppState GtsConnection_WaitInfo(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_CONNECTION_STATE_SEND_SET_PROFILE;
            break;
        case 1:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        case -1:
        case 2:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        case -15:
        case -12:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        case -14:
        case -2:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        default:
            Gts_DeleteWaitingIcon(app);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        app->requestFrames++;
        if (app->requestFrames == 60 * 60) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_SendSetProfile(GtsApp *app) {
    Save_WiiMessage_GetServerProfile(app->args->saveData, &app->profile);
    GtsServer_RequestSetProfile(&app->profile, app->profileResponse);
    app->state = GTS_CONNECTION_STATE_WAIT_SET_PROFILE;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

// The answer of setProfile.asp: [0] 0 accepted, 1 and 2 errors; [1] when accepted: 0 fine, 1..3 errors. The errors
// become the server results -5000 .. -5005 that GtsConnection_PrintServerError has messages for.
enum GtsAppState GtsConnection_WaitSetProfile(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            Gts_DeleteWaitingIcon(app);
            switch (app->profileResponse[0]) {
            case 0:
                switch (app->profileResponse[1]) {
                case 0:
                    Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
                    app->state = GTS_CONNECTION_STATE_FADE_OUT;
                    break;
                case 3:
                    app->serverResult = -5003;
                    app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
                    break;
                case 1:
                    app->serverResult = -5000;
                    app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
                    break;
                case 2:
                    app->serverResult = -5001;
                    app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
                    break;
                default:
                    CommState_ShowRestartErrorAndHalt();
                    break;
                }
                break;
            case 1:
                app->serverResult = -5004;
                app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
                break;
            case 2:
                app->serverResult = -5005;
                app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
                break;
            default:
                Gts_DeleteWaitingIcon(app);
                CommState_ShowRestartErrorAndHalt();
                break;
            }
            break;
        case 1:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        case -1:
        case 2:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        case -15:
        case -12:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        case -14:
        case -2:
            Gts_DeleteWaitingIcon(app);
            app->serverResult = result;
            app->state = GTS_CONNECTION_STATE_PRINT_SERVER_ERROR;
            break;
        default:
            Gts_DeleteWaitingIcon(app);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        app->requestFrames++;
        if (app->requestFrames == 60 * 60) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_ShowConnectionError(GtsApp *app) {
    int msgId = WifiConnection_ClassifyErrorCode(-app->connectionErrorCode, app->connectionErrorType);
    GtsConnection_PrintErrorCode(app, msgId, -app->connectionErrorCode);
    app->state = GTS_CONNECTION_STATE_WAIT_CLOSE_ERROR;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_WaitCloseError(GtsApp *app) {
    if ((gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B) || gSystem.touchNew != 0) {
        EraseFrameAndWindow1(&app->boxNameWindow, FALSE);
        app->state = GTS_CONNECTION_STATE_ASK_CONNECT;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_FadeOut(GtsApp *app) {
    WirelessStatusIcon_Destroy();
    Gts_DeleteWaitingIcon(app);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_61);
    app->state = GTS_CONNECTION_STATE_ASK_CONNECT;
    app->fadedBothScreens = 1;
    return GTS_APP_STATE_EXIT_SCREEN;
}

// Nothing sets this state: Yes leaves the app, No asks to connect again.
enum GtsAppState GtsConnection_HandleExitPrompt(GtsApp *app) {
    YesNoResponse response = Gts_HandleYesNoPrompt(app);
    if (response == YESNORESPONSE_YES) {
        YesNoPrompt_Destroy(app->yesNoPrompt);
        Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
        app->state = GTS_CONNECTION_STATE_FADE_OUT;
    } else if (response == YESNORESPONSE_NO) {
        YesNoPrompt_Destroy(app->yesNoPrompt);
        app->state = GTS_CONNECTION_STATE_ASK_CONNECT;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_PrintServerError(GtsApp *app) {
    int msgId;

    switch (app->serverResult) {
    case 1:
        msgId = msg_0775_00150; // The GTS is currently undergoing maintenance.
        break;
    case -1:
    case 2:
        msgId = msg_0775_00151; // The GTS is very crowded now.
        break;
    case -14:
    case -2:
        msgId = msg_0775_00156; // You were disconnected from the GTS.
        break;
    case -15:
    case -12:
    case -5:
    case -3:
    default:
        msgId = msg_0775_00155; // Unable to connect to the GTS.
        break;
    case -5003:
        msgId = msg_0775_00185; // There was a Wii message authentication error.
        break;
    case -5000:
        msgId = msg_0775_00182; // There was a communication error.
        break;
    case -5001:
        msgId = msg_0775_00182;
        break;
    case -5004:
        msgId = msg_0775_00183; // The data was corrupted. It could not be sent.
        break;
    case -5005:
        msgId = msg_0775_00184; // The server is undergoing maintenance.
        break;
    }
    Gts_PrintMessage(app, app->gtsMsgData, msgId, 1, 0xF0F);
    Gts_SetState(app, GTS_CONNECTION_STATE_WAIT_TEXT, GTS_CONNECTION_STATE_DISCONNECT_AFTER_ERROR);
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_DisconnectAfterError(GtsApp *app) {
    switch (app->subState) {
    case GTS_DISCONNECT_PRINT_DISCONNECTING:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00186, 1, 0xF0F); // Disconnecting from Nintendo Wi-Fi Connection...
        app->subState++;
        break;
    case GTS_DISCONNECT_DISCONNECT:
        if (!TextPrinterCheckActive(app->textPrinterId)) {
            CommState_FreeWfcSession();
            DWC_CleanupInet();
            app->subState++;
        }
        break;
    case GTS_DISCONNECT_PRINT_DISCONNECTED:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00187, 1, 0xF0F); // You have disconnected from Nintendo Wi-Fi Connection.
        app->subState++;
        break;
    case GTS_DISCONNECT_WAIT_MESSAGE:
        if (!TextPrinterCheckActive(app->textPrinterId)) {
            app->subState++;
        }
        break;
    default:
        app->subTimer++;
        if (app->subTimer > 30) {
            Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
            app->state = GTS_CONNECTION_STATE_FADE_OUT;
        }
        break;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_WaitText(GtsApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->state = app->nextState;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_WaitTextAndDelay(GtsApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        if (app->waitFrames > 30) {
            app->state = app->nextState;
        }
        app->waitFrames++;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsConnection_WaitTextAndShowYesNo(GtsApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->yesNoPrompt = Gts_CreateYesNoPrompt(app->bgConfig, 10, 0x234, 8, 0);
        app->state = app->nextState;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

void Gts_PrintMessage(GtsApp *app, MsgData *msgData, int msgId, int textSpeed, u32 unused4) {
    String *string = NewString_ReadMsgData(msgData, msgId);
    StringExpandPlaceholders(app->msgFormat, app->msgBuffer, string);
    String_Delete(string);
    FillWindowPixelBuffer(&app->waitingIconWindow, 15);
    DrawFrameAndWindow2(&app->waitingIconWindow, FALSE, 1, 14);
    app->textPrinterId = AddTextPrinterParameterized(&app->waitingIconWindow, 1, app->msgBuffer, 0, 0, textSpeed, NULL);
    app->waitFrames = 0;
}

static int Gts_GetAlignedX(Window *window, String *string, int x, int align, u32 unused, u32 fontId) {
    switch (align) {
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

static void Gts_PrintAlignedFont1(Window *window, String *string, int x, int y, int align, u32 color) {
    x = Gts_GetAlignedX(window, string, x, align, color, 1);
    AddTextPrinterParameterizedWithColor(window, 1, string, x, y, TEXT_SPEED_INSTANT, color, NULL);
}

void Gts_PrintAlignedFont0(Window *window, String *string, int x, int y, int align, u32 color) {
    x = Gts_GetAlignedX(window, string, x, align, color, 0);
    AddTextPrinterParameterizedWithColor(window, 0, string, x, y, TEXT_SPEED_INSTANT, color, NULL);
}

void Gts_PrintAlignedFont4(Window *window, String *string, int x, int y, int align, u32 color) {
    x = Gts_GetAlignedX(window, string, x, align, color, 0);
    AddTextPrinterParameterizedWithColor(window, 4, string, x, y, TEXT_SPEED_INSTANT, color, NULL);
}

void Gts_PrintPanelCaption(Window *window, MsgData *msgData, int caption) {
    String *string = NewString_ReadMsgData(msgData, gGtsPanelCaptionMsgIds[caption]);
    Gts_PrintAlignedFont0(window, string, 0, 0, 0, MAKE_TEXT_COLOR(1, 2, 0));
    String_Delete(string);
}

void Gts_CreateWirelessStatusIcon(GtsApp *app) {
    WirelessStatusIcon_Create();
}

static void GtsConnection_PrintError(GtsApp *app, int msgId) {
    String *string = String_New(256, HEAP_ID_61);
    ReadMsgDataIntoString(app->wifiErrorMsgData, msgId, string);
    StringExpandPlaceholders(app->msgFormat, app->errorBuffer, string);
    FillWindowPixelBuffer(&app->boxNameWindow, 15);
    DrawFrameAndWindow1(&app->boxNameWindow, TRUE, 31, 11);
    app->textPrinterId = AddTextPrinterParameterized(&app->boxNameWindow, 1, app->errorBuffer, 0, 0, TEXT_SPEED_INSTANT, NULL);
    String_Delete(string);
}

static void GtsConnection_PrintErrorCode(GtsApp *app, int msgId, int errorCode) {
    if (msgId == -1) {
        msgId = 11; // Communication error. Error code: ...
    }
    BufferIntegerAsString(app->msgFormat, 0, errorCode, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
    ClearFrameAndWindow2(&app->waitingIconWindow, TRUE);
    GtsConnection_PrintError(app, msgId);
}
