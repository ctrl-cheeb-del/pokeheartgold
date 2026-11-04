#include "global.h"

#include "constants/game_stats.h"
#include "constants/map_sections.h"
#include "constants/pokemon.h"
#include "constants/pokewalker_courses.h"

#include "dwc/net_common_internal.h"
#include "gts/gts_internal.h"
#include "gts/gts_server.h"
#include "msgdata/msg/msg_0775.h"

#include "bg_window.h"
#include "comm_state.h"
#include "communication_error.h"
#include "font.h"
#include "game_stats.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "options.h"
#include "party.h"
#include "pm_string.h"
#include "pm_version.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokewalker.h"
#include "render_window.h"
#include "sav_chatot.h"
#include "save.h"
#include "save_gts.h"
#include "save_vars_flags.h"
#include "screen_fade.h"
#include "sys_vars.h"
#include "text.h"
#include "wireless_status_icon.h"

// Talking to the GTS server (screen 7): deposit, take back, trade, receive, status check. The game is saved in two
// parts with the request that completes the transaction in between.

typedef enum GtsTransactionState {
    GTS_TRANSACTION_STATE_START,
    GTS_TRANSACTION_STATE_IDLE,
    GTS_TRANSACTION_STATE_SEND_POST,
    GTS_TRANSACTION_STATE_WAIT_POST,
    GTS_TRANSACTION_STATE_SEND_POST_FINISH,
    GTS_TRANSACTION_STATE_WAIT_POST_FINISH,
    GTS_TRANSACTION_STATE_DEPOSIT_DONE,
    GTS_TRANSACTION_STATE_SEND_GET,
    GTS_TRANSACTION_STATE_WAIT_GET,
    GTS_TRANSACTION_STATE_SEND_RETURN,
    GTS_TRANSACTION_STATE_WAIT_RETURN,
    GTS_TRANSACTION_STATE_RECEIVE_DONE,
    GTS_TRANSACTION_STATE_SEND_EXCHANGE,
    GTS_TRANSACTION_STATE_WAIT_EXCHANGE,
    GTS_TRANSACTION_STATE_SEND_EXCHANGE_FINISH,
    GTS_TRANSACTION_STATE_WAIT_EXCHANGE_FINISH,
    GTS_TRANSACTION_STATE_EXCHANGE_DONE,
    GTS_TRANSACTION_STATE_ALREADY_TRADED,
    GTS_TRANSACTION_STATE_RECEIVE_TRADED_MON,
    GTS_TRANSACTION_STATE_SEND_DELETE,
    GTS_TRANSACTION_STATE_WAIT_DELETE,
    GTS_TRANSACTION_STATE_TRADED_DONE,
    GTS_TRANSACTION_STATE_SEND_UNSAVED_RETURN,
    GTS_TRANSACTION_STATE_WAIT_UNSAVED_RETURN,
    GTS_TRANSACTION_STATE_SEND_RESULT,
    GTS_TRANSACTION_STATE_WAIT_RESULT,
    GTS_TRANSACTION_STATE_SEND_STATUS_GET,
    GTS_TRANSACTION_STATE_WAIT_STATUS_GET,
    GTS_TRANSACTION_STATE_EXIT_TO_MAIN_MENU,
    GTS_TRANSACTION_STATE_SAVE_AND_EXIT,
    GTS_TRANSACTION_STATE_START_SAVE,
    GTS_TRANSACTION_STATE_WAIT_SAVE_DELAY,
    GTS_TRANSACTION_STATE_SAVE_FIRST_PART,
    GTS_TRANSACTION_STATE_SAVE_REST,
    GTS_TRANSACTION_STATE_START_SAVE_WITH_MESSAGE,
    GTS_TRANSACTION_STATE_SAVE_WITH_MESSAGE,
    GTS_TRANSACTION_STATE_FADE_OUT,
    GTS_TRANSACTION_STATE_WAIT_TEXT,
    GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT,
    GTS_TRANSACTION_STATE_SERVER_ERROR,
} GtsTransactionState;

static void GtsTransaction_InitBgs(BgConfig *bgConfig);
static void GtsTransaction_FreeBgs(BgConfig *bgConfig);
static void GtsTransaction_LoadGraphics(GtsApp *app);
static void GtsTransaction_CreateWindows(GtsApp *app);
static void GtsTransaction_RemoveWindows(GtsApp *app);
static void GtsTransaction_CreateStrings(GtsApp *app);
static void GtsTransaction_DeleteStrings(GtsApp *app);
static void GtsTransaction_ReturnToCaller(GtsApp *app);
static void GtsTransaction_RecordTradeStats(GtsApp *app, Pokemon *mon);
static void GtsTransaction_PrintServerError(GtsApp *app);
static void GtsTransaction_StoreSelectedMon(GtsApp *app, BOOL setDeposited);
static void GtsTransaction_ReceiveMon(GtsApp *app, Pokemon *mon, int box, int traded);
static void GtsTransaction_ReceiveExchangedMon(GtsApp *app, Pokemon *mon, int box);
static void GtsTransaction_SaveTradeDate(GtsSave *gtsSave, BOOL exchange);
static void GtsTransaction_AddPartnerToWifiHistory(SaveWiFiHistory *wifiHistory, GtsRecord *record);
static int GtsTransaction_CheckCanReceive(GtsApp *app, Pokemon *mon);
static void GtsTransaction_SetSaveStates(GtsApp *app, u16 midState, u16 doneState);
static BOOL GtsTransaction_IsDepositMissingFromSave(GtsApp *app);

void CommState_ShowRestartErrorAndHalt(void);

enum GtsAppState GtsTransaction_Start(GtsApp *app);
enum GtsAppState GtsTransaction_SendPost(GtsApp *app);
enum GtsAppState GtsTransaction_WaitPost(GtsApp *app);
enum GtsAppState GtsTransaction_SendPostFinish(GtsApp *app);
enum GtsAppState GtsTransaction_WaitPostFinish(GtsApp *app);
enum GtsAppState GtsTransaction_SendGet(GtsApp *app);
enum GtsAppState GtsTransaction_WaitGet(GtsApp *app);
enum GtsAppState GtsTransaction_SendReturn(GtsApp *app);
enum GtsAppState GtsTransaction_WaitReturn(GtsApp *app);
enum GtsAppState GtsTransaction_SendExchange(GtsApp *app);
enum GtsAppState GtsTransaction_WaitExchange(GtsApp *app);
enum GtsAppState GtsTransaction_SendExchangeFinish(GtsApp *app);
enum GtsAppState GtsTransaction_WaitExchangeFinish(GtsApp *app);
enum GtsAppState GtsTransaction_SendResult(GtsApp *app);
enum GtsAppState GtsTransaction_WaitResult(GtsApp *app);
enum GtsAppState GtsTransaction_ExitToMainMenu(GtsApp *app);
enum GtsAppState GtsTransaction_SendStatusGet(GtsApp *app);
enum GtsAppState GtsTransaction_WaitStatusGet(GtsApp *app);
enum GtsAppState GtsTransaction_ReceiveTradedMon(GtsApp *app);
enum GtsAppState GtsTransaction_SendDelete(GtsApp *app);
enum GtsAppState GtsTransaction_WaitDelete(GtsApp *app);
enum GtsAppState GtsTransaction_Idle(GtsApp *app);
enum GtsAppState GtsTransaction_DepositDone(GtsApp *app);
enum GtsAppState GtsTransaction_ReceiveDone(GtsApp *app);
enum GtsAppState GtsTransaction_ExchangeDone(GtsApp *app);
enum GtsAppState GtsTransaction_TradedDone(GtsApp *app);
enum GtsAppState GtsTransaction_SendUnsavedReturn(GtsApp *app);
enum GtsAppState GtsTransaction_WaitUnsavedReturn(GtsApp *app);
enum GtsAppState GtsTransaction_AlreadyTraded(GtsApp *app);
enum GtsAppState GtsTransaction_ServerErrorExit(GtsApp *app);
enum GtsAppState GtsTransaction_ServerError(GtsApp *app);
enum GtsAppState GtsTransaction_SaveAndExit(GtsApp *app);
enum GtsAppState GtsTransaction_StartSave(GtsApp *app);
enum GtsAppState GtsTransaction_WaitSaveDelay(GtsApp *app);
enum GtsAppState GtsTransaction_SaveFirstPart(GtsApp *app);
enum GtsAppState GtsTransaction_SaveRest(GtsApp *app);
enum GtsAppState GtsTransaction_StartSaveWithMessage(GtsApp *app);
enum GtsAppState GtsTransaction_SaveWithMessage(GtsApp *app);
enum GtsAppState GtsTransaction_FadeOut(GtsApp *app);
enum GtsAppState GtsTransaction_WaitText(GtsApp *app);

enum GtsAppState GtsTransaction_Init(GtsApp *app, int state) {
    GtsTransaction_CreateStrings(app);
    GtsTransaction_InitBgs(app->bgConfig);
    GtsTransaction_LoadGraphics(app);
    GtsTransaction_CreateWindows(app);
    Gts_ResetAvatarPositions(app);
    BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, HEAP_ID_61);
    Gts_CreateWirelessStatusIcon(app);
    app->state = GTS_TRANSACTION_STATE_START;
    return GTS_APP_STATE_WAIT_FADE_IN;
}

enum GtsAppState GtsTransaction_Main(GtsApp *app, int state) {
    WirelessStatusIcon_SetLevel(Gts_GetWifiIconLevel());
    return gGtsTransactionStates[app->state](app);
}

enum GtsAppState GtsTransaction_Exit(GtsApp *app, int state) {
    if (GXS_GetMasterBrightness()) {
        Gts_LowerAvatars(app);
    }
    GtsTransaction_DeleteStrings(app);
    GtsTransaction_RemoveWindows(app);
    GtsTransaction_FreeBgs(app->bgConfig);
    Gts_SwitchScreen(app);
    return GTS_APP_STATE_INIT_SCREEN;
}

static void GtsTransaction_InitBgs(BgConfig *bgConfig) {
    GraphicsModes graphicsModes;
    BgTemplate bg0;
    BgTemplate bg1;
    BgTemplate bg2;
    BgTemplate subBg0;
    BgTemplate subBg1;

    graphicsModes = gGtsTransactionGraphicsModes;
    SetBothScreensModesAndDisable(&graphicsModes);
    bg0 = gGtsTransactionBg0Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &bg0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    bg1 = gGtsTransactionBg1Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    bg2 = gGtsTransactionBg2Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &bg2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    subBg0 = gGtsTransactionSubBg0Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &subBg0, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    subBg1 = gGtsTransactionSubBg1Template;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &subBg1, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_61);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 0x20, 0, HEAP_ID_61);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_61);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

static void GtsTransaction_FreeBgs(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
}

// The sub screen stays dark until the player has walked in; after the trade sequence it is drawn again.
static void GtsTransaction_LoadGraphics(GtsApp *app) {
    BgConfig *bgConfig = app->bgConfig;

    GfGfxLoader_GXLoadPal(NARC_a_1_0_0, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x60, HEAP_ID_61);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_61);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 14, Options_GetFrame(app->args->options), HEAP_ID_61);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 0x1F, 11, 0, HEAP_ID_61);
    if (!app->playerAnimDone) {
        ToggleBgLayer(GF_BG_LYR_SUB_0, GF_PLANE_TOGGLE_OFF);
        ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_OFF);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_OFF);
    }
    if (app->prevScreen == GTS_SCREEN_TRADE) {
        Gts_LoadSubScreenBg(app);
        Gts_ShowSubScreenPanel(app);
    }
}

static void GtsTransaction_CreateWindows(GtsApp *app) {
    AddWindowParameterized(app->bgConfig, &app->waitingIconWindow, GF_BG_LYR_MAIN_0, 2, 19, 27, 4, 13, 0x28);
    FillWindowPixelBuffer(&app->waitingIconWindow, 0);
}

static void GtsTransaction_RemoveWindows(GtsApp *app) {
    RemoveWindow(&app->waitingIconWindow);
}

static void GtsTransaction_CreateStrings(GtsApp *app) {
    app->msgBuffer = String_New(180, HEAP_ID_61);
}

static void GtsTransaction_DeleteStrings(GtsApp *app) {
    String_Delete(app->msgBuffer);
}

enum GtsAppState GtsTransaction_Start(GtsApp *app) {
    switch (app->nextScreenArg) {
    case 7:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00024, 1, 0xF0F); // Checking GTS's status...
        Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_SEND_POST);
        break;
    case 8:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00024, 1, 0xF0F);
        Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_SEND_GET);
        break;
    case 9:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00024, 1, 0xF0F);
        Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_SEND_EXCHANGE);
        break;
    case 10:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00024, 1, 0xF0F);
        Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_RECEIVE_TRADED_MON);
        app->fadedBothScreens = 1;
        break;
    case 11:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00024, TEXT_SPEED_INSTANT, 0xF0F);
        app->state = GTS_TRANSACTION_STATE_SEND_RESULT;
        break;
    case 12:
        Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00148, 1, 0xF0F); // Saving... Do not turn off the power.
        app->nextScreen = GTS_SCREEN_MAIN_MENU;
        app->state = GTS_TRANSACTION_STATE_SAVE_AND_EXIT;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    Gts_CreateWaitingIcon(app);
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SendPost(GtsApp *app) {
    Pokemon_RemoveCapsule(&app->record.mon);
    GtsServer_RequestPost(&app->record);
    app->state = GTS_TRANSACTION_STATE_WAIT_POST;
    app->requestFrames = 0;
    GtsTransaction_SetSaveStates(app, GTS_TRANSACTION_STATE_SEND_POST_FINISH, GTS_TRANSACTION_STATE_DEPOSIT_DONE);
    return GTS_APP_STATE_RUN_SCREEN;
}

// Each request is given a minute; then the connection is dropped (CommState_ShowRestartErrorAndHalt).
enum GtsAppState GtsTransaction_WaitPost(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            GtsTransaction_StoreSelectedMon(app, TRUE);
            GameStats_Inc(app->args->gameStats, GAME_STAT_UNK45);
            app->state = GTS_TRANSACTION_STATE_START_SAVE;
            break;
        case -1:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -11:
        case -10:
        case -9:
        case -8:
        case -7:
        case -6:
        case -5:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR;
            break;
        case -12:
        case -4:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR;
            break;
        case -15:
        case -14:
        case -2:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -13:
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

enum GtsAppState GtsTransaction_SendPostFinish(GtsApp *app) {
    GtsServer_RequestPostFinish();
    app->state = GTS_TRANSACTION_STATE_WAIT_POST_FINISH;
    app->requestFrames = 0;
    app->hasDepositedMon = TRUE;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitPostFinish(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_TRANSACTION_STATE_SAVE_REST;
            break;
        case -12:
        case -4:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR;
            break;
        case -15:
        case -14:
        case -5:
        case -3:
        case -2:
        case -1:
            CommState_SetError(4);
            break;
        case -13:
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

enum GtsAppState GtsTransaction_SendGet(GtsApp *app) {
    GtsServer_RequestGet(&app->record);
    app->state = GTS_TRANSACTION_STATE_WAIT_GET;
    app->requestFrames = 0;
    GtsTransaction_SetSaveStates(app, GTS_TRANSACTION_STATE_SEND_RETURN, GTS_TRANSACTION_STATE_RECEIVE_DONE);
    return GTS_APP_STATE_RUN_SCREEN;
}

// The deposited Pokemon comes back unless it was traded in the meantime (then the status check takes over).
enum GtsAppState GtsTransaction_WaitGet(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0: {
            s8 traded = app->record.isTraded;
            if (traded != 0) {
                app->state = GTS_TRANSACTION_STATE_SEND_RESULT;
            } else {
                GtsTransaction_ReceiveMon(app, &app->record.mon, GtsSave_GetStoredMonBox(app->args->gtsSave), traded);
                app->state = GTS_TRANSACTION_STATE_START_SAVE;
            }
            break;
        }
        case -3:
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -4:
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -12:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR;
            break;
        case -15:
        case -14:
        case -2:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -13:
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

enum GtsAppState GtsTransaction_SendReturn(GtsApp *app) {
    GtsServer_RequestReturn();
    app->state = GTS_TRANSACTION_STATE_WAIT_RETURN;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitReturn(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_TRANSACTION_STATE_SAVE_REST;
            break;
        case -5:
        case -4:
        case -3:
            CommState_SetError(3);
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            CommState_SetError(4);
            break;
        case -13:
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

enum GtsAppState GtsTransaction_SendExchange(GtsApp *app) {
    Pokemon_RemoveCapsule(&app->record.mon);
    GtsServer_RequestExchange(app->searchResults[app->selectedResult].exchangeId, &app->record, &app->searchResults[7]);
    GtsTransaction_SetSaveStates(app, GTS_TRANSACTION_STATE_SEND_EXCHANGE_FINISH, GTS_TRANSACTION_STATE_EXCHANGE_DONE);
    app->state = GTS_TRANSACTION_STATE_WAIT_EXCHANGE;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitExchange(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_TRANSACTION_STATE_START_SAVE;
            GtsTransaction_StoreSelectedMon(app, FALSE);
            GtsTransaction_ReceiveExchangedMon(app, &app->searchResults[7].mon, app->selectedBox);
            GtsTransaction_AddPartnerToWifiHistory(app->args->wifiHistory, &app->searchResults[7]);
            GtsTransaction_RecordTradeStats(app, &app->searchResults[7].mon);
            break;
        case -5:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_ALREADY_TRADED;
            break;
        case -11:
        case -10:
        case -9:
        case -8:
        case -7:
        case -6:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR;
            break;
        case -12:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR;
            break;
        case -15:
        case -14:
        case -2:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -13:
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

enum GtsAppState GtsTransaction_SendExchangeFinish(GtsApp *app) {
    GtsServer_RequestExchangeFinish();
    app->state = GTS_TRANSACTION_STATE_WAIT_EXCHANGE_FINISH;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitExchangeFinish(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_TRANSACTION_STATE_SAVE_REST;
            break;
        case -5:
            CommState_SetError(3);
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            CommState_SetError(4);
            break;
        case -13:
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

enum GtsAppState GtsTransaction_SendResult(GtsApp *app) {
    GtsServer_RequestResult(&app->record);
    app->state = GTS_TRANSACTION_STATE_WAIT_RESULT;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

// 0: the deposited Pokemon is still offered, 1: it was traded, -3: the server has no deposit (the Pokemon in the
// save comes back), -4: neither has one ("appears to have fled").
enum GtsAppState GtsTransaction_WaitResult(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_TRANSACTION_STATE_SEND_STATUS_GET;
            break;
        case 1: {
            int canReceive;
            app->hasDepositedMon = TRUE;
            canReceive = GtsTransaction_CheckCanReceive(app, &app->record.mon);
            switch (canReceive) {
            case 1:
                Gts_DeleteWaitingIcon(app);
                Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00029, 1, 0xF0F); // Your Storage Boxes are full.
                Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_EXIT_TO_MAIN_MENU);
                break;
            case 2:
                Gts_DeleteWaitingIcon(app);
                Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00035, 1, 0xF0F); // Your party is full (the Pokemon holds Mail).
                Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_EXIT_TO_MAIN_MENU);
                break;
            case 0:
                app->state = GTS_TRANSACTION_STATE_RECEIVE_TRADED_MON;
                app->fadedBothScreens = 1;
                break;
            }
            break;
        }
        case -3: {
            Pokemon *mon;
            app->hasDepositedMon = FALSE;
            if (GtsSave_HasStoredMon(app->args->gtsSave)) {
                mon = AllocMonZeroed(HEAP_ID_61);
                GtsSave_GetStoredMon(app->args->gtsSave, mon);
                BufferBoxMonNickname(app->msgFormat, 0, Mon_GetBoxMon(mon));
                app->afterSaveMsgId = 2; // {nickname} was not traded.
                app->state = GTS_TRANSACTION_STATE_START_SAVE_WITH_MESSAGE;
                GtsTransaction_ReceiveMon(app, mon, GtsSave_GetStoredMonBox(app->args->gtsSave), 0);
                GtsSave_SetHasStoredMon(app->args->gtsSave, 0);
                Heap_Free(mon);
            } else {
                GtsTransaction_ReturnToCaller(app);
            }
            break;
        }
        case -4: {
            Pokemon *mon;
            app->hasDepositedMon = FALSE;
            if (GtsSave_HasStoredMon(app->args->gtsSave)) {
                mon = AllocMonZeroed(HEAP_ID_61);
                GtsSave_GetStoredMon(app->args->gtsSave, mon);
                BufferBoxMonNickname(app->msgFormat, 0, Mon_GetBoxMon(mon));
                app->afterSaveMsgId = 3; // {nickname} appears to have fled...
                app->state = GTS_TRANSACTION_STATE_START_SAVE_WITH_MESSAGE;
                GtsSave_SetHasStoredMon(app->args->gtsSave, 0);
                Heap_Free(mon);
            }
            break;
        }
        case -15:
        case -14:
        case -12:
        case -2:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            break;
        case -13:
            ShowCommunicationError(HEAP_ID_3, 1, 0);
            for (;;) {}
        }
    } else {
        app->requestFrames++;
        if (app->requestFrames == 60 * 60) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_ExitToMainMenu(GtsApp *app) {
    Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
    app->state = GTS_TRANSACTION_STATE_FADE_OUT;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SendStatusGet(GtsApp *app) {
    GtsServer_RequestGet(&app->record);
    app->state = GTS_TRANSACTION_STATE_WAIT_STATUS_GET;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitStatusGet(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            if (GtsTransaction_IsDepositMissingFromSave(app)) {
                app->state = GTS_TRANSACTION_STATE_SEND_UNSAVED_RETURN;
                app->hasDepositedMon = FALSE;
                return GTS_APP_STATE_RUN_SCREEN;
            }
            app->hasDepositedMon = TRUE;
            break;
        case -3:
            app->hasDepositedMon = FALSE;
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            app->serverResult = result;
            app->state = GTS_TRANSACTION_STATE_SERVER_ERROR_EXIT;
            return GTS_APP_STATE_RUN_SCREEN;
        case -13:
            CommState_ShowRestartErrorAndHalt();
            return GTS_APP_STATE_RUN_SCREEN;
        case -11:
        case -10:
        case -9:
        case -8:
        case -7:
        case -6:
        case -5:
        case -4:
        case -1:
            break;
        }
        GtsTransaction_ReturnToCaller(app);
    } else {
        app->requestFrames++;
        if (app->requestFrames == 60 * 60) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

// Back to the screen that asked for the status check: the main menu (statusCheckCaller 1) or the summary (2).
static void GtsTransaction_ReturnToCaller(GtsApp *app) {
    switch (app->statusCheckCaller) {
    case 1:
        Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
        app->state = GTS_TRANSACTION_STATE_FADE_OUT;
        break;
    case 2:
        Gts_SetNextScreen(app, GTS_SCREEN_SUMMARY, 3);
        app->state = GTS_TRANSACTION_STATE_FADE_OUT;
        break;
    }
}

// A Pokemon from another language opens the Pokewalker's Beyond the Sea course.
static void GtsTransaction_RecordTradeStats(GtsApp *app, Pokemon *mon) {
    GameStats_AddScore(app->args->gameStats, SCORE_EVENT_GTS_TRADE);
    GameStats_Inc(app->args->gameStats, GAME_STAT_WIFI_TRADES);
    if (gGameLanguage != GetMonData(mon, MON_DATA_LANGUAGE, NULL)) {
        Pokewalker_UnlockCourse(Save_Pokewalker_Get(app->args->saveData), WALKER_COURSE_BEYOND_THE_SEA);
    }
}

enum GtsAppState GtsTransaction_ReceiveTradedMon(GtsApp *app) {
    GtsTransaction_ReceiveMon(app, &app->record.mon, GtsSave_GetStoredMonBox(app->args->gtsSave), app->record.isTraded);
    GtsTransaction_AddPartnerToWifiHistory(app->args->wifiHistory, &app->record);
    GtsTransaction_RecordTradeStats(app, &app->record.mon);
    GtsSave_SetHasStoredMon(app->args->gtsSave, 0);
    app->state = GTS_TRANSACTION_STATE_START_SAVE;
    GtsTransaction_SetSaveStates(app, GTS_TRANSACTION_STATE_SEND_DELETE, GTS_TRANSACTION_STATE_RECEIVE_DONE);
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SendDelete(GtsApp *app) {
    GtsServer_RequestDelete();
    app->state = GTS_TRANSACTION_STATE_WAIT_DELETE;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitDelete(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            app->state = GTS_TRANSACTION_STATE_SAVE_REST;
            break;
        case -3:
            CommState_SetError(3);
            break;
        case -12:
        case -4:
            app->serverResult = result;
            // fallthrough
        case -15:
        case -14:
        case -2:
            CommState_SetError(4);
            break;
        case -13:
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

enum GtsAppState GtsTransaction_Idle(GtsApp *app) {
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_DepositDone(GtsApp *app) {
    app->hasDepositedMon = TRUE;
    Gts_SetNextScreen(app, GTS_SCREEN_TRADE, 7);
    app->state = GTS_TRANSACTION_STATE_FADE_OUT;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_ReceiveDone(GtsApp *app) {
    app->hasDepositedMon = FALSE;
    Gts_SetNextScreen(app, GTS_SCREEN_TRADE, 8);
    app->state = GTS_TRANSACTION_STATE_FADE_OUT;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_ExchangeDone(GtsApp *app) {
    Gts_SetNextScreen(app, GTS_SCREEN_TRADE, 9);
    app->state = GTS_TRANSACTION_STATE_FADE_OUT;
    return GTS_APP_STATE_RUN_SCREEN;
}

// No state leads here.
enum GtsAppState GtsTransaction_TradedDone(GtsApp *app) {
    app->hasDepositedMon = FALSE;
    Gts_SetNextScreen(app, GTS_SCREEN_TRADE, 10);
    app->state = GTS_TRANSACTION_STATE_START_SAVE;
    return GTS_APP_STATE_RUN_SCREEN;
}

// The server holds a Pokemon the save does not know about: it is taken off the GTS.
enum GtsAppState GtsTransaction_SendUnsavedReturn(GtsApp *app) {
    GtsServer_RequestReturn();
    app->state = GTS_TRANSACTION_STATE_WAIT_UNSAVED_RETURN;
    app->requestFrames = 0;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitUnsavedReturn(GtsApp *app) {
    if (GtsServer_IsRequestDone()) {
        int result = GtsServer_GetResult();
        app->requestFrames = 0;
        switch (result) {
        case 0:
            GtsTransaction_ReturnToCaller(app);
            break;
        case -3:
            GtsTransaction_ReturnToCaller(app);
            // fallthrough
        case -4:
            GtsTransaction_ReturnToCaller(app);
            // fallthrough
        case -5:
            CommState_SetError(3);
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            CommState_SetError(4);
            break;
        case -13:
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

enum GtsAppState GtsTransaction_AlreadyTraded(GtsApp *app) {
    Gts_PrintMessage(app, app->gtsMsgData, msg_0775_00147, 1, 0xF0F); // Unfortunately, it was traded to another Trainer.
    Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_FADE_OUT);
    Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
    Gts_DeleteWaitingIcon(app);
    Gts_StopAvatarAnims(app);
    return GTS_APP_STATE_RUN_SCREEN;
}

static void GtsTransaction_PrintServerError(GtsApp *app) {
    int msgId = msg_0775_00154; // Communication error...
    // Switched over serverResult + 15: -11..-6, -1, -14, -2.
    switch (app->serverResult + 15) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        msgId = msg_0775_00026; // That Pokemon may not be offered for trade!
        break;
    case 14:
        msgId = msg_0775_00151; // The GTS is very crowded now.
        break;
    case 1:
    case 13:
        msgId = msg_0775_00156; // You were disconnected from the GTS.
        break;
    }
    Gts_PrintMessage(app, app->gtsMsgData, msgId, 1, 0xF0F);
}

enum GtsAppState GtsTransaction_ServerErrorExit(GtsApp *app) {
    GtsTransaction_PrintServerError(app);
    Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_FADE_OUT);
    Gts_SetNextScreen(app, GTS_SCREEN_CONNECTION, 0);
    Gts_DeleteWaitingIcon(app);
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_ServerError(GtsApp *app) {
    GtsTransaction_PrintServerError(app);
    Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_FADE_OUT);
    Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
    Gts_DeleteWaitingIcon(app);
    Gts_StopAvatarAnims(app);
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SaveAndExit(GtsApp *app) {
    Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_START_SAVE);
    GtsTransaction_SetSaveStates(app, GTS_TRANSACTION_STATE_SAVE_REST, GTS_TRANSACTION_STATE_FADE_OUT);
    return GTS_APP_STATE_RUN_SCREEN;
}

// The save starts after 2..61 frames.
enum GtsAppState GtsTransaction_StartSave(GtsApp *app) {
    SetAllPCBoxesModified();
    Save_PrepareForAsyncWrite(app->args->saveData, 2);
    app->state = GTS_TRANSACTION_STATE_WAIT_SAVE_DELAY;
    app->waitFrames = (u16)(LCRandom() % 60) + 2;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_WaitSaveDelay(GtsApp *app) {
    app->waitFrames--;
    if (app->waitFrames == 0) {
        app->state = GTS_TRANSACTION_STATE_SAVE_FIRST_PART;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SaveFirstPart(GtsApp *app) {
    if (Save_WriteFileAsync(app->args->saveData) == WRITE_STATUS_NEXT) {
        app->state = app->saveMidState;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SaveRest(GtsApp *app) {
    if (Save_WriteFileAsync(app->args->saveData) == WRITE_STATUS_SUCCESS) {
        app->state = app->saveDoneState;
        Gts_DeleteWaitingIcon(app);
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_StartSaveWithMessage(GtsApp *app) {
    SetAllPCBoxesModified();
    Save_PrepareForAsyncWrite(app->args->saveData, 2);
    app->state = GTS_TRANSACTION_STATE_SAVE_WITH_MESSAGE;
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_SaveWithMessage(GtsApp *app) {
    if (Save_WriteFileAsync(app->args->saveData) == WRITE_STATUS_SUCCESS) {
        Gts_SetNextScreen(app, GTS_SCREEN_MAIN_MENU, 0);
        Gts_DeleteWaitingIcon(app);
        Gts_PrintMessage(app, app->gtsMsgData, app->afterSaveMsgId, 1, 0xF0F);
        Gts_SetState(app, GTS_TRANSACTION_STATE_WAIT_TEXT, GTS_TRANSACTION_STATE_EXIT_TO_MAIN_MENU);
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

enum GtsAppState GtsTransaction_FadeOut(GtsApp *app) {
    Gts_DeleteWaitingIcon(app);
    WirelessStatusIcon_Destroy();
    if (app->fadedBothScreens == 1) {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_61);
    } else {
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, HEAP_ID_61);
    }
    app->state = GTS_TRANSACTION_STATE_START;
    return GTS_APP_STATE_EXIT_SCREEN;
}

enum GtsAppState GtsTransaction_WaitText(GtsApp *app) {
    if (!TextPrinterCheckActive(app->textPrinterId)) {
        app->state = app->nextState;
    }
    return GTS_APP_STATE_RUN_SCREEN;
}

// Moves the selected Pokemon out of the box or the party into the GTS save data.
static void GtsTransaction_StoreSelectedMon(GtsApp *app, BOOL setDeposited) {
    Pokemon *mon;

    if (app->selectedBox != GTS_BOX_PARTY) {
        mon = AllocMonZeroed(HEAP_ID_61);
        CopyBoxPokemonToPokemon(PCStorage_GetMonByIndexPair(app->args->pcStorage, app->selectedBox, app->selectedSlot), mon);
        GtsSave_SetStoredMon(app->args->gtsSave, mon, app->selectedBox);
        PCStorage_DeleteBoxMonByIndexPair(app->args->pcStorage, app->selectedBox, app->selectedSlot);
        Heap_Free(mon);
    } else {
        mon = Party_GetMonByIndex(app->args->party, app->selectedSlot);
        Pokemon_RemoveCapsule(mon);
        GtsSave_SetStoredMon(app->args->gtsSave, mon, app->selectedBox);
        Party_RemoveMon(app->args->party, app->selectedSlot);
        if (!Party_HasMon(app->args->party, SPECIES_CHATOT)) {
            Chatot_Invalidate(Save_Chatot_Get(app->args->saveData));
        }
    }
    if (setDeposited) {
        GtsSave_SetHasStoredMon(app->args->gtsSave, 1);
    }
}

// Into the party, or the first free box slot when it is full (offeredBox/offeredSlot say where); the box argument
// is not used. A traded Pokemon gets the friendship of a traded Pokemon and the date of the trade is saved.
static void GtsTransaction_ReceiveMon(GtsApp *app, Pokemon *mon, int box, int traded) {
    int slot;
    int count;
    u8 friendship;
    SaveVarsFlags *varsFlags;

    GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    UpdatePokedexWithReceivedSpecies(app->args->saveData, mon);
    box = GTS_BOX_PARTY;
    if (Party_GetCount(app->args->party) == PARTY_SIZE) {
        box = 0;
    }
    if (traded) {
        friendship = 70;
        if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_ARCEUS) {
            if (GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) != 0 || (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == MAPSEC_HALL_OF_ORIGIN && GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) == 0)) {
                varsFlags = Save_VarsFlags_Get(app->args->saveData);
                if (Save_VarsFlags_GetVar404C(varsFlags) == 0) {
                    Save_VarsFlags_SetVar404C(varsFlags, 1);
                }
            }
        }
        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(mon, MON_DATA_GENDER, NULL);
        GtsTransaction_SaveTradeDate(app->args->gtsSave, FALSE);
    }
    if (box == GTS_BOX_PARTY) {
        Party_AddMon(app->args->party, mon);
        count = Party_GetCount(app->args->party);
        app->offeredBox = GTS_BOX_PARTY;
        app->offeredSlot = count - 1;
    } else {
        slot = 0;
        PCStorage_FindFirstEmptySlot(app->args->pcStorage, &box, &slot);
        PCStorage_PlaceMonInBoxFirstEmptySlot(app->args->pcStorage, box, Mon_GetBoxMon(mon));
        app->offeredBox = box;
        app->offeredSlot = slot;
    }
    GtsSave_SetHasStoredMon(app->args->gtsSave, 0);
}

// The Pokemon got by an exchange; the box argument is not used.
static void GtsTransaction_ReceiveExchangedMon(GtsApp *app, Pokemon *mon, int box) {
    int slot;
    int count;
    u8 friendship;
    SaveVarsFlags *varsFlags;

    UpdatePokedexWithReceivedSpecies(app->args->saveData, mon);
    box = GTS_BOX_PARTY;
    if (Party_GetCount(app->args->party) == PARTY_SIZE) {
        box = 0;
    }
    if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_ARCEUS) {
        if (GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) != 0 || (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == MAPSEC_HALL_OF_ORIGIN && GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) == 0)) {
            varsFlags = Save_VarsFlags_Get(app->args->saveData);
            if (Save_VarsFlags_GetVar404C(varsFlags) == 0) {
                Save_VarsFlags_SetVar404C(varsFlags, 1);
            }
        }
    }
    friendship = 70;
    SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(mon, MON_DATA_GENDER, NULL);
    if (box == GTS_BOX_PARTY) {
        Party_AddMon(app->args->party, mon);
        count = Party_GetCount(app->args->party);
        app->offeredBox = GTS_BOX_PARTY;
        app->offeredSlot = count - 1;
    } else {
        slot = 0;
        PCStorage_FindFirstEmptySlot(app->args->pcStorage, &box, &slot);
        PCStorage_PlaceMonInBoxFirstEmptySlot(app->args->pcStorage, box, Mon_GetBoxMon(mon));
        app->offeredBox = box;
        app->offeredSlot = slot;
    }
    GtsTransaction_SaveTradeDate(app->args->gtsSave, TRUE);
}

// Today's date packed as year, month, day, weekday bytes (SEEK POKEMON reads them back): the date the deposited
// Pokemon was traded, or (exchange) the date of the last exchange.
static void GtsTransaction_SaveTradeDate(GtsSave *gtsSave, BOOL exchange) {
    RTCDate date;
    RTCTime time;
    u32 packed;

    DWC_GetDateTime(&date, &time);
    packed = (date.year << 24) | ((date.month << 24) >> 8) | ((date.day << 24) >> 16) | date.week;
    if (exchange == TRUE) {
        GtsSave_SetTradeDate(gtsSave, packed);
    } else {
        GtsSave_SetDepositDate(gtsSave, packed);
    }
}

static void GtsTransaction_AddPartnerToWifiHistory(SaveWiFiHistory *wifiHistory, GtsRecord *record) {
    Comm_MarkLocationSeen(wifiHistory, record->country, record->city, record->language);
}

// 0: the Pokemon can be received, 1: the party and all boxes are full, 2: it holds Mail and the party is full.
static int GtsTransaction_CheckCanReceive(GtsApp *app, Pokemon *mon) {
    if (Gts_MonHoldsMail(mon) && Party_GetCount(app->args->party) == PARTY_SIZE) {
        return 2;
    }
    if (app->boxMonCount == NUM_BOXES * MONS_PER_BOX && Party_GetCount(app->args->party) == PARTY_SIZE) {
        return 1;
    }
    return 0;
}

static void GtsTransaction_SetSaveStates(GtsApp *app, u16 midState, u16 doneState) {
    app->saveMidState = midState;
    app->saveDoneState = doneState;
}

// The save holds no deposited Pokemon although hasDepositedMon is set.
static BOOL GtsTransaction_IsDepositMissingFromSave(GtsApp *app) {
    if (!GtsSave_HasStoredMon(app->args->gtsSave) && app->hasDepositedMon) {
        return TRUE;
    }
    return FALSE;
}
