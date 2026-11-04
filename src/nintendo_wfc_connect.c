#include "nintendo_wfc_connect.h"

#include <dwc/dwc_account_internal.h>
#include <dwc/dwc_main_internal.h>
#include <dwc/net_common_internal.h>
#include <dwc/stats_upload_internal.h>
#include <nitrowifi/wcm_internal.h>

#include "global.h"

#include "constants/dwc_status.h"
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0191.h"
#include "msgdata/msg/msg_0774.h"
#include "msgdata/msg/msg_0778.h"
#include "msgdata/msg/msg_0800.h"
#include "nnsys/fnd/expheap.h"

#include "bg_window.h"
#include "comm_state.h"
#include "comm_wireless.h"
#include "filesystem.h"
#include "font.h"
#include "frontier_data_access.h"
#include "frontier_wifi_upload_record.h"
#include "game_stats_request.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "network_overlay_loader.h"
#include "nintendo_wfc_connect_internal.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "overlay_00_thumb.h"
#include "palette.h"
#include "pm_string.h"
#include "render_text.h"
#include "render_window.h"
#include "save_wii_message.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_resource_header.h"
#include "sprite_transfer.h"
#include "sys_task_api.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"
#include "yes_no_prompt.h"

// Number pad cursor positions: the digit keys 0..9, then the buttons below them. gNintendoWfcPadNeighbors also
// holds markers for moving up or down from a button, resolved by the column the cursor came from.
enum NintendoWfcPadKey {
    NINTENDO_WFC_PAD_KEY_BACK = 10,
    NINTENDO_WFC_PAD_KEY_OK,
    NINTENDO_WFC_PAD_KEY_CANCEL,
    NINTENDO_WFC_PAD_UP_FROM_LEFT_BUTTON,
    NINTENDO_WFC_PAD_DOWN_FROM_LEFT_BUTTON,
    NINTENDO_WFC_PAD_UP_FROM_RIGHT_BUTTON,
    NINTENDO_WFC_PAD_DOWN_FROM_RIGHT_BUTTON,
};

enum NintendoWfcState {
    NINTENDO_WFC_STATE_ASK_CONNECT,
    NINTENDO_WFC_STATE_HANDLE_CONNECT_CHOICE,
    NINTENDO_WFC_STATE_START_CONNECT,
    NINTENDO_WFC_STATE_WAIT_CONNECT,
    NINTENDO_WFC_STATE_START_AUTH,
    NINTENDO_WFC_STATE_WAIT_AUTH,
    NINTENDO_WFC_STATE_INIT_HTTP,
    NINTENDO_WFC_STATE_REQUEST_INFO,
    NINTENDO_WFC_STATE_WAIT_INFO,
    NINTENDO_WFC_STATE_REQUEST_SET_PROFILE,
    NINTENDO_WFC_STATE_WAIT_SET_PROFILE,
    NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT,
    NINTENDO_WFC_STATE_WAIT_ROOM_COUNT,
    NINTENDO_WFC_STATE_ASK_CHALLENGE_ROOM,
    NINTENDO_WFC_STATE_START_CHALLENGE_ROOM_INPUT,
    NINTENDO_WFC_STATE_HANDLE_CHALLENGE_ROOM_INPUT,
    NINTENDO_WFC_STATE_PRINT_RECEIVING_TRAINERS,
    NINTENDO_WFC_STATE_REQUEST_TRAINERS_DOWNLOAD,
    NINTENDO_WFC_STATE_WAIT_TRAINERS_DOWNLOAD,
    NINTENDO_WFC_STATE_PRINT_TRAINERS_RECEIVED,
    NINTENDO_WFC_STATE_PRINT_ROOM_UNAVAILABLE,
    NINTENDO_WFC_STATE_ASK_CANCEL_CHALLENGE,
    NINTENDO_WFC_STATE_HANDLE_CANCEL_CHALLENGE_CHOICE,
    NINTENDO_WFC_STATE_ASK_CANCEL_DOWNLOAD,
    NINTENDO_WFC_STATE_HANDLE_CANCEL_DOWNLOAD_CHOICE,
    NINTENDO_WFC_STATE_PRINT_SENDING_RECORD,
    NINTENDO_WFC_STATE_REQUEST_UPLOAD,
    NINTENDO_WFC_STATE_WAIT_UPLOAD,
    NINTENDO_WFC_STATE_PRINT_RECORD_SENT,
    NINTENDO_WFC_STATE_ASK_LEADERS_RANK,
    NINTENDO_WFC_STATE_START_LEADERS_RANK_INPUT,
    NINTENDO_WFC_STATE_HANDLE_LEADERS_RANK_INPUT,
    NINTENDO_WFC_STATE_ASK_LEADERS_ROOM,
    NINTENDO_WFC_STATE_START_LEADERS_ROOM_INPUT,
    NINTENDO_WFC_STATE_HANDLE_LEADERS_ROOM_INPUT,
    NINTENDO_WFC_STATE_PRINT_RECEIVING_LEADERS,
    NINTENDO_WFC_STATE_REQUEST_LEADERS_DOWNLOAD,
    NINTENDO_WFC_STATE_WAIT_LEADERS_DOWNLOAD,
    NINTENDO_WFC_STATE_PRINT_LEADERS_RECEIVED,
    NINTENDO_WFC_STATE_START_SAVE,
    NINTENDO_WFC_STATE_SAVE,
    NINTENDO_WFC_STATE_PRINT_DISCONNECTING,
    NINTENDO_WFC_STATE_CLOSE_CONNECTION,
    NINTENDO_WFC_STATE_PRINT_DISCONNECTED,
    NINTENDO_WFC_STATE_UNUSED_IDLE,
    NINTENDO_WFC_STATE_START_DISCONNECT,
    NINTENDO_WFC_STATE_START_EXIT,
    NINTENDO_WFC_STATE_WAIT_MESSAGE,
    NINTENDO_WFC_STATE_OPEN_YES_NO_MENU,
    NINTENDO_WFC_STATE_WAIT_MESSAGE_AND_DELAY,
    NINTENDO_WFC_STATE_UNUSED_HANDLE_YES_NO,
    NINTENDO_WFC_STATE_ASK_LOG_OUT,
    NINTENDO_WFC_STATE_HANDLE_LOG_OUT_CHOICE,
    NINTENDO_WFC_STATE_SHOW_HTTP_ERROR,
    NINTENDO_WFC_STATE_DISCONNECT,
    NINTENDO_WFC_STATE_SHOW_DWC_ERROR,
    NINTENDO_WFC_STATE_WAIT_ERROR_DISMISS,
};

enum NintendoWfcNumberInputState {
    NINTENDO_WFC_NUMBER_INPUT_FADE_OUT,
    NINTENDO_WFC_NUMBER_INPUT_SETUP,
    NINTENDO_WFC_NUMBER_INPUT_WAIT_FADE_IN,
    NINTENDO_WFC_NUMBER_INPUT_MAIN,
    NINTENDO_WFC_NUMBER_INPUT_UNUSED4,
    NINTENDO_WFC_NUMBER_INPUT_UNUSED5,
    NINTENDO_WFC_NUMBER_INPUT_UNUSED6,
    NINTENDO_WFC_NUMBER_INPUT_START_FADE_OUT,
    NINTENDO_WFC_NUMBER_INPUT_TEARDOWN,
    NINTENDO_WFC_NUMBER_INPUT_WAIT_FADE_OUT,
    NINTENDO_WFC_NUMBER_INPUT_WAIT_BUTTON_FLASH,
    NINTENDO_WFC_NUMBER_INPUT_FINISH,
};

enum NintendoWfcYesNoState {
    NINTENDO_WFC_YES_NO_START,
    NINTENDO_WFC_YES_NO_HANDLE_INPUT,
    NINTENDO_WFC_YES_NO_UNUSED2,
    NINTENDO_WFC_YES_NO_WAIT_CLOSE,
};

// Number pad on the sub screen (rank / Battle Room number entry).
typedef struct NintendoWfcNumberInput {
    u8 unk_0;
    u8 maxValue; // 100: three digits
    s8 value;    // entered value, -1: quit
    u8 cursor;   // pad key under the cursor
    s16 digitPos;
    u8 state; // index into gNintendoWfcNumberInputStates
    u8 nextState;
    s8 digits[3]; // -1: empty
    u8 unk_B;
} NintendoWfcNumberInput;

// Brief palette flash of a pressed button: a sprite, or a rectangle of a bg layer.
typedef struct NintendoWfcButtonFlash {
    u8 isBgRect;
    u8 state;
    u8 target; // sprite index or bg layer
    u8 timer;
    u8 width;
    u8 height;
    u8 x;
    u8 y;
    u16 pressedPltt;
    u16 normalPltt;
} NintendoWfcButtonFlash;

#define NINTENDO_WFC_SPRITE_DIGIT_0       0
#define NINTENDO_WFC_SPRITE_PAD_CURSOR    3
#define NINTENDO_WFC_SPRITE_DIGIT_CURSOR  4
#define NINTENDO_WFC_SPRITE_BUTTON_0      5
#define NINTENDO_WFC_SPRITE_YES_NO_CURSOR 8
#define NINTENDO_WFC_SPRITE_COUNT         9

struct NintendoWfcConnect {
    NintendoWifiConnectArgs *args;
    BgConfig *bgConfig;
    u8 padding_0008[8];
    int screen; // index into gNintendoWfcScreens (there is only screen 0)
    int nextScreen;
    int unk_0018;
    enum NintendoWfcState state; // index into gNintendoWfcStates
    enum NintendoWfcState nextState;
    void *heapMem;
    NNSFndHeapHandle expHeap;
    NetConnection connection;
    u32 ownRank;
    u32 rank;
    int roomCount;
    u32 room;
    BattleRoomDownloadData downloadBuffer;
    FrontierWifiUploadRecord uploadRecord;
    u8 padding_0BBC[0x14];
    MessageFormat *msgFormat;
    MsgData *msgDataTower; // Wi-Fi Battle Tower
    MsgData *msgDataWfc;   // Nintendo WFC
    MsgData *msgDataError; // Nintendo WFC errors
    String *msgString;
    String *titleString;
    String *roomString;
    String *rankString;
    String *errorString;
    u32 textPrinterId;
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resMan[4];
    SpriteResource *resObjs[12];
    SpriteResourcesHeader spriteHeaders[3];
    u8 padding_0DD0[0x24];
    Sprite *sprites[NINTENDO_WFC_SPRITE_COUNT];
    Window msgWindow;
    Window rankWindow;
    Window roomWindow;
    Window titleWindow;
    Window errorWindow;
    u8 padding_0E68[0xE4];
    WaitingIcon *waitingIcon;
    int dwcError;
    int dwcErrorCode;
    int dwcErrorType;
    int httpResult; // enum NintendoWfcHttpResult
    int messageTimer;
    WifiServerProfile profile;
    u32 profileResponse[2];
    s16 subState;
    s16 subTimer;
    int timeoutCounter;
    NintendoWfcPaletteCycle paletteCycle;
    YesNoPrompt *yesNoPrompt;
    NintendoWfcNumberInput numberInput;
    Window numberInputWindow;
    Window buttonWindows[3];
    NintendoWfcButtonFlash buttonFlash;
    u16 padColumn[2]; // pad column to return to from the bottom rows
    u32 twoDigits;
    NintendoWfcYesNoMenu yesNoMenu;
};

void CommState_InitWfcSession(SaveData *saveData);
void CommState_FreeWfcSession(void);
void CommState_ShowRestartErrorAndHalt(void);

static BOOL NintendoWfcHttp_StartRequest(const char *url, void *request, int requestSize, void *response, int responseSize);
static enum NintendoWfcHttpResult NintendoWfcHttp_ConvertError(int error);
static void NintendoWfc_VBlankCB(void *arg);
static void NintendoWfc_SetGfxBanks(void);
static void NintendoWfc_InitArgs(NintendoWfcConnect *wfc, OverlayManager *man);
static void NintendoWfc_ExitDummy(NintendoWfcConnect *wfc);
static void NintendoWfc_InitObjTransfer(void);
static void NintendoWfc_InitSpriteResources(NintendoWfcConnect *wfc);
static void NintendoWfc_InitSpriteTemplate(SpriteTemplate *template, NintendoWfcConnect *wfc, SpriteResourcesHeader *header, u32 whichScreen);
static void NintendoWfc_CreateSprites(NintendoWfcConnect *wfc);
static int NintendoWfc_HandleYesNoPrompt(YesNoPrompt *prompt);
static void NintendoWfc_SetState(NintendoWfcConnect *wfc, enum NintendoWfcState state, enum NintendoWfcState nextState);
static void NintendoWfc_SetSpritePosition(Sprite *sprite, int x, int y);
static void NintendoWfc_MovePadCursor(Sprite *sprite, int key);
static void NintendoWfc_MoveDigitCursor(Sprite *sprite, int index, int twoDigits);
static void NintendoWfc_SetDigitSpritePosition(Sprite *sprite, int index, int twoDigits);
static void *NintendoWfc_Alloc(int heap, u32 size, int alignment);
static void NintendoWfc_Free(int heap, void *ptr, u32 size);
static int NintendoWfc_GetWifiIconLevel(void);
static void NintendoWfc_SetNextScreen(NintendoWfcConnect *wfc, int screen, int a2);
static void NintendoWfc_InitGraphics(NintendoWfcConnect *wfc);
static void NintendoWfc_FreeGraphics(NintendoWfcConnect *wfc);
static void NintendoWfc_InitBgs(BgConfig *bgConfig);
static void NintendoWfc_FreeBgs(BgConfig *bgConfig);
static void NintendoWfc_LoadSubScreenBg(NintendoWfcConnect *wfc, int numberPad);
static void NintendoWfc_LoadBgGraphics(NintendoWfcConnect *wfc);
static void NintendoWfc_PaletteCycleTask(SysTask *task, void *data);
static void NintendoWfc_AddWindows(NintendoWfcConnect *wfc);
static void NintendoWfc_RemoveWindows(NintendoWfcConnect *wfc);
static void NintendoWfc_InitStrings(NintendoWfcConnect *wfc);
static void NintendoWfc_FreeStrings(NintendoWfcConnect *wfc);
static void NintendoWfc_PrintFormattedMessage(NintendoWfcConnect *wfc, MsgData *msgData, int msgNo, int textSpeed, int unused);
static void NintendoWfc_PrintMessage(NintendoWfcConnect *wfc, MsgData *msgData, int msgNo, int textSpeed, int unused);
static int NintendoWfc_GetAlignedTextX(const Window *window, String *string, int x, int alignment, int unused, int fontId);
static void NintendoWfc_PrintAlignedText(Window *window, String *string, int x, int y, int alignment, u32 color);
static void NintendoWfc_CreateWirelessIcon(NintendoWfcConnect *wfc);
static void NintendoWfc_NumberInputDummy(NintendoWfcConnect *wfc, int unused1, int unused2);
static void NintendoWfc_ShowWaitingIcon(NintendoWfcConnect *wfc);
static void NintendoWfc_HideWaitingIcon(NintendoWfcConnect *wfc);
static void NintendoWfc_PrintErrorMessage(NintendoWfcConnect *wfc, int msgNo);
static void NintendoWfc_ShowErrorMessage(NintendoWfcConnect *wfc, int msgNo, int errorCode);
static int NintendoWfc_StartNumberInput(NintendoWfcConnect *wfc, int a1, int maxValue);
static int NintendoWfc_RunNumberInput(NintendoWfcConnect *wfc);
static void NintendoWfc_ShowNumberInputSprites(NintendoWfcConnect *wfc);
static int NintendoWfc_GetTouchedPadKey(NintendoWfcConnect *wfc);
static u8 NintendoWfc_GetPadNeighbor(u32 key, u32 direction, u16 *padColumn);
static int NintendoWfc_GetEnteredNumber(NintendoWfcNumberInput *input, int newDigit);
static BOOL NintendoWfc_AreDigitsComplete(NintendoWfcNumberInput *input);
static u8 NintendoWfc_GetCursorAfterDigit(NintendoWfcNumberInput *input);
static void NintendoWfc_PressPadKey(NintendoWfcConnect *wfc, int key);
static BOOL NintendoWfc_HandlePadButtons(NintendoWfcConnect *wfc);
static void NintendoWfc_UpdateDigitSprites(NintendoWfcConnect *wfc);
static void NintendoWfc_AddNumberInputWindows(NintendoWfcConnect *wfc);
static void NintendoWfc_PrintButtonLabel(Window *window, MsgData *msgData, int msgNo);
static void NintendoWfc_RemoveNumberInputWindows(NintendoWfcConnect *wfc);
static void NintendoWfc_HideNumberInput(NintendoWfcConnect *wfc);
static void NintendoWfc_SetButtonFlashPltt(NintendoWfcConnect *wfc, u8 pltt);
static BOOL NintendoWfc_UpdateButtonFlash(NintendoWfcConnect *wfc);
static void NintendoWfc_StartButtonFlash(NintendoWfcConnect *wfc, int x, int y, int nextState);
static void NintendoWfcYesNo_Init(NintendoWfcYesNoMenu *menu);
static int NintendoWfcYesNo_Run(NintendoWfcYesNoMenu *menu);
static void NintendoWfcYesNo_LoadGraphics(NintendoWfcYesNoMenu *menu);
static void NintendoWfcYesNo_AddWindows(NintendoWfcYesNoMenu *menu);
static void NintendoWfcYesNo_RemoveWindows(NintendoWfcYesNoMenu *menu);
static void NintendoWfcYesNo_ShowCursor(NintendoWfcYesNoMenu *menu);
static void NintendoWfcYesNo_MoveCursor(NintendoWfcYesNoMenu *menu, int choice);

void NintendoWfcHttp_Init(u32 profileId, u64 friendKey) {
    gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_IDLE;
    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_OK;
    gNintendoWfcHttp.profileId = profileId;
    gNintendoWfcHttp.friendKey = friendKey;
}

void NintendoWfcHttp_Update(void) {
    switch (gNintendoWfcHttp.state) {
    case NINTENDO_WFC_HTTP_NONE:
    case NINTENDO_WFC_HTTP_IDLE:
    case NINTENDO_WFC_HTTP_DONE:
        break;
    case NINTENDO_WFC_HTTP_ROOM_COUNT:
        switch (GameStats_Update()) {
        case GAME_STATS_STATE_IDLE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            gNintendoWfcHttp.result = NintendoWfcHttp_ConvertError(GameStats_GetError());
            GameStats_Shutdown();
            break;
        case GAME_STATS_STATE_DONE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            if (GameStats_GetResponseLength() > 0) {
                gNintendoWfcHttp.result = gNintendoWfcHttpResponse.status;
            } else {
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
            }
            GameStats_Shutdown();
            break;
        }
        break;
    case NINTENDO_WFC_HTTP_DOWNLOAD:
        switch (GameStats_Update()) {
        case GAME_STATS_STATE_IDLE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            gNintendoWfcHttp.result = NintendoWfcHttp_ConvertError(GameStats_GetError());
            GameStats_Shutdown();
            break;
        case GAME_STATS_STATE_DONE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            if (GameStats_GetResponseLength() == NINTENDO_WFC_DOWNLOAD_SIZE) {
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_OK;
            } else {
                switch (*gNintendoWfcHttpResponse.buffer) {
                case NINTENDO_WFC_SERVER_BAD_ROOM:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_BAD_ROOM;
                    break;
                case NINTENDO_WFC_SERVER_ERROR:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
                    break;
                default:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
                    break;
                }
            }
            GameStats_Shutdown();
            break;
        }
        break;
    case NINTENDO_WFC_HTTP_UPLOAD:
        switch (GameStats_Update()) {
        case GAME_STATS_STATE_IDLE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            gNintendoWfcHttp.result = NintendoWfcHttp_ConvertError(GameStats_GetError());
            GameStats_Shutdown();
            break;
        case GAME_STATS_STATE_DONE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            switch (gNintendoWfcHttpResponse.status) {
            case NINTENDO_WFC_SERVER_OK:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_OK;
                break;
            case NINTENDO_WFC_SERVER_BAD_ROOM:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_BAD_ROOM;
                break;
            case NINTENDO_WFC_SERVER_CROWDED:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED;
                break;
            case NINTENDO_WFC_SERVER_ERROR:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
                break;
            default:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
                break;
            }
            GameStats_Shutdown();
            break;
        }
        break;
    case NINTENDO_WFC_HTTP_INFO:
        switch (GameStats_Update()) {
        case GAME_STATS_STATE_IDLE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            gNintendoWfcHttp.result = NintendoWfcHttp_ConvertError(GameStats_GetError());
            GameStats_Shutdown();
            break;
        case GAME_STATS_STATE_DONE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            switch (gNintendoWfcHttpResponse.status) {
            case NINTENDO_WFC_SERVER_OK:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_OK;
                break;
            case NINTENDO_WFC_SERVER_MAINTENANCE:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_MAINTENANCE;
                break;
            case NINTENDO_WFC_SERVER_CROWDED:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_CROWDED;
                break;
            case NINTENDO_WFC_SERVER_ERROR:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
                break;
            default:
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
                break;
            }
            GameStats_Shutdown();
            break;
        }
        break;
    case NINTENDO_WFC_HTTP_SET_PROFILE:
        switch (GameStats_Update()) {
        case GAME_STATS_STATE_IDLE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            gNintendoWfcHttp.result = NintendoWfcHttp_ConvertError(GameStats_GetError());
            GameStats_Shutdown();
            break;
        case GAME_STATS_STATE_DONE:
            gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
            if (GameStats_GetResponseLength() == 8) {
                gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_OK;
            } else {
                switch (gNintendoWfcHttpResponse.status) {
                case NINTENDO_WFC_SERVER_OK:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_OK;
                    break;
                case NINTENDO_WFC_SERVER_MAINTENANCE:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_MAINTENANCE;
                    break;
                case NINTENDO_WFC_SERVER_CROWDED:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_CROWDED;
                    break;
                case NINTENDO_WFC_SERVER_ERROR:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
                    break;
                default:
                    gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
                    break;
                }
            }
            GameStats_Shutdown();
            break;
        }
        break;
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
        gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_CANCELED;
        GameStats_Shutdown();
        break;
    }
}

BOOL NintendoWfcHttp_IsDone(void) {
    switch (gNintendoWfcHttp.state) {
    case NINTENDO_WFC_HTTP_IDLE:
        return TRUE;
    case NINTENDO_WFC_HTTP_DONE:
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_IDLE;
        return TRUE;
    default:
        return FALSE;
    }
}

s32 NintendoWfcHttp_GetResult(void) {
    return gNintendoWfcHttp.result;
}

void NintendoWfcHttp_RequestRoomCount(int rank) {
    GameStats_Start();
    gNintendoWfcHttp.rank = rank - 1;
    if (NintendoWfcHttp_StartRequest(gNintendoWfcRoomNumUrl, gNintendoWfcHttpRequestBuffer, 1, gNintendoWfcHttpShortResponse, 2)) {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_ROOM_COUNT;
    } else {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
        gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
        GameStats_Shutdown();
    }
}

void NintendoWfcHttp_RequestDownload(int rank, int room, BattleRoomDownloadData *download) {
    gNintendoWfcHttpResponse.buffer = (u8 *)download;
    GameStats_Start();
    gNintendoWfcHttp.rank = rank - 1;
    gNintendoWfcHttp.room = room - 1;
    if (NintendoWfcHttp_StartRequest(gNintendoWfcDownloadUrl, gNintendoWfcHttpRequestBuffer, 2, download, NINTENDO_WFC_DOWNLOAD_SIZE)) {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DOWNLOAD;
    } else {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
        gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
        GameStats_Shutdown();
    }
}

void NintendoWfcHttp_RequestUpload(int rank, int room, int winCount, FrontierWifiUploadRecord *record) {
    u8 *dst;
    u8 *src;
    u32 count;
    GameStats_Start();
    memcpy(gNintendoWfcHttpRequestBuffer, record, sizeof(FrontierWifiUploadRecord));
    // the request continues after the record: rank, room, winCount and the friend key
    ov72_0223B900[0x18] = rank - 1;
    ov72_0223B900[0x19] = room - 1;
    ov72_0223B900[0x1A] = winCount;
    dst = gNintendoWfcHttpUploadFriendKey;
    src = gNintendoWfcHttpFriendKey;
    count = 8;
    do {
        *dst++ = *src++;
    } while (--count);
    if (NintendoWfcHttp_StartRequest(gNintendoWfcUploadUrl, gNintendoWfcHttpRequestBuffer, 239, gNintendoWfcHttpShortResponse, 2)) {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_UPLOAD;
    } else {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
        gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
        GameStats_Shutdown();
    }
}

void NintendoWfcHttp_RequestInfo(void) {
    GameStats_Start();
    if (NintendoWfcHttp_StartRequest(gNintendoWfcInfoUrl, gNintendoWfcHttpRequestBuffer, 0, gNintendoWfcHttpShortResponse, 2)) {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_INFO;
    } else {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
        gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
        GameStats_Shutdown();
    }
}

void NintendoWfcHttp_RequestSetProfile(WifiServerProfile *profile, u32 *response) {
    OS_GetMacAddress(profile->macAddress);
    memcpy(gNintendoWfcHttpRequestBuffer, profile, sizeof(WifiServerProfile));
    gNintendoWfcHttpResponse.buffer = (u8 *)response;
    GameStats_Start();
    if (NintendoWfcHttp_StartRequest(gNintendoWfcSetProfileUrl, gNintendoWfcHttpRequestBuffer, sizeof(WifiServerProfile), gNintendoWfcHttpResponse.buffer, 8)) {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_SET_PROFILE;
    } else {
        gNintendoWfcHttp.state = NINTENDO_WFC_HTTP_DONE;
        gNintendoWfcHttp.result = NINTENDO_WFC_HTTP_RESULT_FATAL;
        GameStats_Shutdown();
    }
}

static BOOL NintendoWfcHttp_StartRequest(const char *url, void *request, int requestSize, void *response, int responseSize) {
    enum GameStatsPrepareResult result = GameStats_PrepareRequest(url, gNintendoWfcHttp.profileId, request, requestSize, response, responseSize);
    switch (result) {
    case GAME_STATS_PREPARE_OK:
        return TRUE;
    case GAME_STATS_PREPARE_NOT_STARTED:
        break;
    case GAME_STATS_PREPARE_NO_MEMORY:
        break;
    }
    return FALSE;
}

static enum NintendoWfcHttpResult NintendoWfcHttp_ConvertError(int error) {
    enum NintendoWfcHttpResult ret;
    switch (error) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
    case 14:
    case 20:
    case 21:
    case 22:
    case 23:
    case GAME_STATS_ERROR_RESPONSE_TOO_LONG:
        ret = NINTENDO_WFC_HTTP_RESULT_FATAL;
        break;
    case 2:
    case 8:
    case 25:
        ret = NINTENDO_WFC_HTTP_RESULT_FATAL;
        break;
    case 11:
        ret = NINTENDO_WFC_HTTP_RESULT_DISCONNECTED;
        break;
    case 12:
    case 13:
        ret = NINTENDO_WFC_HTTP_RESULT_DISCONNECTED;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case GAME_STATS_ERROR_CHECK_SUM:
    case GAME_STATS_ERROR_PID:
    case GAME_STATS_ERROR_DATA_LENGTH:
    case GAME_STATS_ERROR_TOKEN_NOT_FOUND:
    case GAME_STATS_ERROR_INCORRECT_HASH:
        ret = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
        break;
    case 15:
    case GAME_STATS_ERROR_TOKEN_EXPIRED:
        ret = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
        break;
    default:
        ret = NINTENDO_WFC_HTTP_RESULT_FATAL;
        break;
    }
    if (ret != NINTENDO_WFC_HTTP_RESULT_FATAL) {
        if (WCM_GetPhase() != WCM_PHASE_DCF) {
            ret = NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED;
        }
        DWC_ClearError();
    }
    return ret;
}

BOOL NintendoWfc_Init(OverlayManager *man, int *state) {
    NintendoWfcConnect *wfc;
    switch (*state) {
    case NINTENDO_WFC_INIT_SETUP: {
        GraphicsModes modes;
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        Heap_Create(HEAP_ID_3, HEAP_ID_67, 0x50000);
        LoadDwcOverlay();
        LoadOVY38();
        Comm_InitDwc(HEAP_ID_67);
        wfc = OverlayManager_CreateAndGetData(man, sizeof(NintendoWfcConnect), HEAP_ID_67);
        memset(wfc, 0, sizeof(NintendoWfcConnect));
        wfc->bgConfig = BgConfig_Alloc(HEAP_ID_67);
        gNintendoWfcGlobal.wfc = wfc;
        modes = gNintendoWfcGraphicsModes;
        SetBothScreensModesAndDisable(&modes);
        wfc->msgFormat = MessageFormat_New_Custom(11, 32, HEAP_ID_67);
        wfc->msgDataTower = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0774_bin, HEAP_ID_67);
        wfc->msgDataWfc = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0778_bin, HEAP_ID_67);
        wfc->msgDataError = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0800_bin, HEAP_ID_67);
        SetKeyRepeatTimers(4, 8);
        NintendoWfc_InitArgs(wfc, man);
        NintendoWfc_InitGraphics(wfc);
        Sound_SetSceneAndPlayBGM(52, SEQ_NONE, 0);
        wfc->heapMem = Heap_Alloc(HEAP_ID_67, 0x20020);
        wfc->expHeap = NNS_FndCreateExpHeapEx((void *)(((u32)wfc->heapMem + 31) & ~31), 0x20000, 0);
        Sound_SetSceneAndPlayBGM(11, SEQ_GS_WIFI_ACCESS, 1);
        TextFlags_SetCanTouchSpeedUpPrint(TRUE);
        reg_GX_POWCNT |= REG_GX_POWCNT_DSEL_MASK;
        *state = NINTENDO_WFC_INIT_START_WIRELESS;
        break;
    }
    case NINTENDO_WFC_INIT_START_WIRELESS:
        CommWireless_StartUp();
        FontID_Alloc(4, HEAP_ID_67);
        *state = NINTENDO_WFC_INIT_SETUP;
        return TRUE;
    }
    return FALSE;
}

BOOL NintendoWfc_Main(OverlayManager *man, int *state) {
    NintendoWfcConnect *wfc = OverlayManager_GetData(man);
    DWC_UpdateConnection();
    NintendoWfcHttp_Update();
    DWC_UpdateConnection();
    switch (*state) {
    case NINTENDO_WFC_MAIN_WAIT_STARTUP:
        if (CommWireless_IsStartedUp()) {
            gNintendoWfcGlobal.heap = wfc->expHeap;
            DWC_SetMemFunc(NintendoWfc_Alloc, NintendoWfc_Free);
            *state = NINTENDO_WFC_MAIN_SESSION_INIT;
        }
        break;
    case NINTENDO_WFC_MAIN_SESSION_INIT:
        *state = gNintendoWfcScreens[wfc->screen].init(wfc, *state);
        break;
    case NINTENDO_WFC_MAIN_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            *state = NINTENDO_WFC_MAIN_SESSION_MAIN;
        }
        break;
    case NINTENDO_WFC_MAIN_SESSION_MAIN:
        *state = gNintendoWfcScreens[wfc->screen].main(wfc, *state);
        break;
    case NINTENDO_WFC_MAIN_SESSION_EXIT:
        if (IsPaletteFadeFinished()) {
            *state = gNintendoWfcScreens[wfc->screen].exit(wfc, *state);
        }
        break;
    case NINTENDO_WFC_MAIN_DONE:
        return TRUE;
    }
    if (wfc->spriteList != NULL) {
        SpriteList_RenderAndAnimateSprites(wfc->spriteList);
    }
    return FALSE;
}

BOOL NintendoWfc_Exit(OverlayManager *man, int *state) {
    NintendoWfcConnect *wfc = OverlayManager_GetData(man);
    if (!IsPaletteFadeFinished()) {
        return FALSE;
    }
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    FontID_Release(4);
    Heap_Free(wfc->heapMem);
    UnloadOVY38();
    UnloadDwcOverlay();
    NintendoWfc_FreeGraphics(wfc);
    DestroyMsgData(wfc->msgDataError);
    DestroyMsgData(wfc->msgDataWfc);
    DestroyMsgData(wfc->msgDataTower);
    MessageFormat_Delete(wfc->msgFormat);
    NintendoWfc_ExitDummy(wfc);
    CommWireless_Terminate();
    Heap_Free(wfc->bgConfig);
    OverlayManager_FreeData(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(HEAP_ID_67);
    return TRUE;
}

static void NintendoWfc_VBlankCB(void *arg) {
    NintendoWfcConnect *wfc = arg;
    GF_RunVramTransferTasks();
    DoScheduledBgGpuUpdates(wfc->bgConfig);
    OamManager_ApplyAndResetBuffers();
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void NintendoWfc_SetGfxBanks(void) {
    GraphicsBanks banks = gNintendoWfcGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void NintendoWfc_InitArgs(NintendoWfcConnect *wfc, OverlayManager *man) {
    wfc->args = OverlayManager_GetArgs(man);
    wfc->screen = 0;
    NintendoWfc_SetNextScreen(wfc, 0, 0);
}

static void NintendoWfc_ExitDummy(NintendoWfcConnect *wfc) {
}

static void NintendoWfc_InitObjTransfer(void) {
    ObjCharTransferTemplate template = gNintendoWfcObjCharTransferTemplate;
    ObjCharTransfer_Init(&template);
    ObjPlttTransfer_Init(20, HEAP_ID_67);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

static void NintendoWfc_InitSpriteResources(NintendoWfcConnect *wfc) {
    NARC *narcA237 = NARC_New(NARC_a_2_3_7, HEAP_ID_67);
    NARC *narcA236 = NARC_New(NARC_a_2_3_6, HEAP_ID_67);
    int i;
    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 126, 0, 32, 0, 126, 0, 32, HEAP_ID_67);
    wfc->spriteList = G2dRenderer_Init(20, &wfc->renderer, HEAP_ID_67);
    G2dRenderer_SetSubSurfaceCoords(&wfc->renderer, 0, 256 << FX32_SHIFT);
    for (i = 0; i < 4; i++) {
        wfc->resMan[i] = Create2DGfxResObjMan(3, (GfGfxResType)i, HEAP_ID_67);
    }
    wfc->resObjs[0] = AddCharResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_CHAR], narcA236, 1, FALSE, 0, NNS_G2D_VRAM_TYPE_2DSUB, HEAP_ID_67);
    wfc->resObjs[1] = AddPlttResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_PLTT], narcA236, 0, FALSE, 0, NNS_G2D_VRAM_TYPE_2DSUB, 3, HEAP_ID_67);
    wfc->resObjs[2] = AddCellOrAnimResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_CELL], narcA236, 2, FALSE, 0, GF_GFX_RES_TYPE_CELL, HEAP_ID_67);
    wfc->resObjs[3] = AddCellOrAnimResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_ANIM], narcA236, 3, FALSE, 0, GF_GFX_RES_TYPE_ANIM, HEAP_ID_67);
    wfc->resObjs[4] = AddCharResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_CHAR], narcA236, 5, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, HEAP_ID_67);
    wfc->resObjs[5] = AddPlttResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_PLTT], narcA236, 4, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, 3, HEAP_ID_67);
    wfc->resObjs[6] = AddCellOrAnimResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_CELL], narcA236, 6, FALSE, 1, GF_GFX_RES_TYPE_CELL, HEAP_ID_67);
    wfc->resObjs[7] = AddCellOrAnimResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_ANIM], narcA236, 7, FALSE, 1, GF_GFX_RES_TYPE_ANIM, HEAP_ID_67);
    wfc->resObjs[8] = AddCharResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_CHAR], narcA237, 12, FALSE, 2, NNS_G2D_VRAM_TYPE_2DSUB, HEAP_ID_67);
    wfc->resObjs[9] = AddPlttResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_PLTT], narcA237, 11, FALSE, 2, NNS_G2D_VRAM_TYPE_2DSUB, 1, HEAP_ID_67);
    wfc->resObjs[10] = AddCellOrAnimResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_CELL], narcA237, 13, FALSE, 2, GF_GFX_RES_TYPE_CELL, HEAP_ID_67);
    wfc->resObjs[11] = AddCellOrAnimResObjFromOpenNarc(wfc->resMan[GF_GFX_RES_TYPE_ANIM], narcA237, 14, FALSE, 2, GF_GFX_RES_TYPE_ANIM, HEAP_ID_67);
    SpriteTransfer_CreateCharTransferTask(wfc->resObjs[0]);
    SpriteTransfer_CreateCharTransferTask(wfc->resObjs[4]);
    SpriteTransfer_CreateCharTransferTask(wfc->resObjs[8]);
    SpriteTransfer_CreateExtPlttTransferTask(wfc->resObjs[1]);
    SpriteTransfer_CreateExtPlttTransferTask(wfc->resObjs[5]);
    SpriteTransfer_CreateExtPlttTransferTask(wfc->resObjs[9]);
    NARC_Delete(narcA236);
    NARC_Delete(narcA237);
}

static void NintendoWfc_InitSpriteTemplate(SpriteTemplate *template, NintendoWfcConnect *wfc, SpriteResourcesHeader *header, u32 whichScreen) {
    template->spriteList = wfc->spriteList;
    template->header = header;
    template->position.z = 0;
    template->scale.x = FX32_ONE;
    template->scale.y = FX32_ONE;
    template->scale.z = FX32_ONE;
    template->rotation = 0;
    template->drawPriority = 1;
    template->whichScreen = (NNS_G2D_VRAM_TYPE)whichScreen;
    template->heapID = HEAP_ID_67;
}

static void NintendoWfc_CreateSprites(NintendoWfcConnect *wfc) {
    SpriteTemplate template;
    int i;
    CreateSpriteResourcesHeader(&wfc->spriteHeaders[0], 0, 0, 0, 0, -1, -1, 0, 0, wfc->resMan[GF_GFX_RES_TYPE_CHAR], wfc->resMan[GF_GFX_RES_TYPE_PLTT], wfc->resMan[GF_GFX_RES_TYPE_CELL], wfc->resMan[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    CreateSpriteResourcesHeader(&wfc->spriteHeaders[1], 1, 1, 1, 1, -1, -1, 0, 0, wfc->resMan[GF_GFX_RES_TYPE_CHAR], wfc->resMan[GF_GFX_RES_TYPE_PLTT], wfc->resMan[GF_GFX_RES_TYPE_CELL], wfc->resMan[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    CreateSpriteResourcesHeader(&wfc->spriteHeaders[2], 2, 2, 2, 2, -1, -1, 0, 0, wfc->resMan[GF_GFX_RES_TYPE_CHAR], wfc->resMan[GF_GFX_RES_TYPE_PLTT], wfc->resMan[GF_GFX_RES_TYPE_CELL], wfc->resMan[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
    NintendoWfc_InitSpriteTemplate(&template, wfc, &wfc->spriteHeaders[0], NNS_G2D_VRAM_TYPE_2DSUB);
    for (i = 0; i < 3; i++) {
        template.position.x = gNintendoWfcDigitSpritePositions[0][i][0] << FX32_SHIFT;
        template.position.y = (gNintendoWfcDigitSpritePositions[0][i][1] << FX32_SHIFT) + (256 << FX32_SHIFT);
        wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i] = Sprite_CreateAffine(&template);
        Sprite_SetAnimActiveFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], TRUE);
        Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], 0);
        Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], FALSE);
    }
    NintendoWfc_InitSpriteTemplate(&template, wfc, &wfc->spriteHeaders[1], NNS_G2D_VRAM_TYPE_2DSUB);
    template.position.x = 32 << FX32_SHIFT;
    template.position.y = 0x151000;
    wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR] = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], TRUE);
    Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], 1);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], FALSE);
    template.position.x = 96 << FX32_SHIFT;
    template.position.y = 0x129000;
    wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR] = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], TRUE);
    Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], 0);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], FALSE);
    for (i = 0; i < 3; i++) {
        template.position.x = gNintendoWfcButtonSpritePositions[i][0] << FX32_SHIFT;
        template.position.y = (gNintendoWfcButtonSpritePositions[i][1] << FX32_SHIFT) + (256 << FX32_SHIFT);
        wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + i] = Sprite_CreateAffine(&template);
        Sprite_SetAnimActiveFlag(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + i], TRUE);
        Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + i], 3);
        Sprite_SetPriority(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + i], 1);
        Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + i], FALSE);
    }
    NintendoWfc_InitSpriteTemplate(&template, wfc, &wfc->spriteHeaders[2], NNS_G2D_VRAM_TYPE_2DSUB);
    template.position.x = 128 << FX32_SHIFT;
    template.position.y = 0x151000;
    wfc->sprites[NINTENDO_WFC_SPRITE_YES_NO_CURSOR] = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(wfc->sprites[NINTENDO_WFC_SPRITE_YES_NO_CURSOR], TRUE);
    Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_YES_NO_CURSOR], 1);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_YES_NO_CURSOR], FALSE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, TRUE);
    WirelessStatusIcon_Create();
}

static int NintendoWfc_HandleYesNoPrompt(YesNoPrompt *prompt) {
    int response = YesNoPrompt_HandleInput(prompt);
    if (response) {
        YesNoPrompt_Destroy(prompt);
    }
    return response;
}

static void NintendoWfc_SetState(NintendoWfcConnect *wfc, enum NintendoWfcState state, enum NintendoWfcState nextState) {
    wfc->state = state;
    wfc->nextState = nextState;
}

static void NintendoWfc_SetSpritePosition(Sprite *sprite, int x, int y) {
    VecFx32 pos;
    float rounded;
    if (x > 0) {
        rounded = (float)(x << FX32_SHIFT) + 0.5f;
    } else {
        rounded = (float)(x << FX32_SHIFT) - 0.5f;
    }
    pos.x = (fx32)rounded;
    if (y > 0) {
        rounded = (float)(y << FX32_SHIFT) + 0.5f;
    } else {
        rounded = (float)(y << FX32_SHIFT) - 0.5f;
    }
    pos.y = (fx32)rounded;
    pos.z = 0;
    Sprite_SetMatrix(sprite, &pos);
}

static void NintendoWfc_MovePadCursor(Sprite *sprite, int key) {
    NintendoWfc_SetSpritePosition(sprite, gNintendoWfcPadCursorPositions[key][0], gNintendoWfcPadCursorPositions[key][1] + 256);
    if (key < NINTENDO_WFC_PAD_KEY_BACK) {
        Sprite_SetAnimCtrlSeq(sprite, 1);
    } else {
        Sprite_SetAnimCtrlSeq(sprite, 2);
    }
}

static void NintendoWfc_MoveDigitCursor(Sprite *sprite, int index, int twoDigits) {
    NintendoWfc_SetSpritePosition(sprite, gNintendoWfcDigitSpritePositions[twoDigits][index][0], 0x129);
}

static void NintendoWfc_SetDigitSpritePosition(Sprite *sprite, int index, int twoDigits) {
    NintendoWfc_SetSpritePosition(sprite, gNintendoWfcDigitSpritePositions[twoDigits][index][0], gNintendoWfcDigitSpritePositions[twoDigits][index][1] + 256);
}

static void *NintendoWfc_Alloc(int heap, u32 size, int alignment) {
    OSIntrMode enabled = OS_DisableInterrupts();
    void *result = NNS_FndAllocFromExpHeapEx(gNintendoWfcGlobal.heap, size, alignment);
    OS_RestoreInterrupts(enabled);
    return result;
}

static void NintendoWfc_Free(int heap, void *ptr, u32 size) {
    OSIntrMode enabled;
    if (!ptr) {
        return;
    }
    enabled = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(gNintendoWfcGlobal.heap, ptr);
    OS_RestoreInterrupts(enabled);
}

static int NintendoWfc_GetWifiIconLevel(void) {
    return 3 - DWC_GetLinkLevel();
}

static void NintendoWfc_SetNextScreen(NintendoWfcConnect *wfc, int screen, int a2) {
    wfc->nextScreen = screen;
    wfc->unk_0018 = a2;
}

static void NintendoWfc_InitGraphics(NintendoWfcConnect *wfc) {
    NintendoWfc_SetGfxBanks();
    NintendoWfc_InitObjTransfer();
    NintendoWfc_InitSpriteResources(wfc);
    NintendoWfc_CreateSprites(wfc);
    Main_SetVBlankIntrCB(NintendoWfc_VBlankCB, wfc);
}

static void NintendoWfc_FreeGraphics(NintendoWfcConnect *wfc) {
    int i;
    SpriteTransfer_DeleteCharTransferTask(wfc->resObjs[0]);
    SpriteTransfer_DeleteCharTransferTask(wfc->resObjs[4]);
    SpriteTransfer_DeletePlttTransferTask(wfc->resObjs[1]);
    SpriteTransfer_DeletePlttTransferTask(wfc->resObjs[5]);
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(wfc->resMan[i]);
    }
    SpriteList_Delete(wfc->spriteList);
    wfc->spriteList = NULL;
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}

enum NintendoWfcMainState NintendoWfc_SessionInit(NintendoWfcConnect *wfc, int state) {
    NintendoWfc_InitStrings(wfc);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 8, 1, HEAP_ID_67);
    NintendoWfc_InitBgs(wfc->bgConfig);
    NintendoWfc_LoadBgGraphics(wfc);
    NintendoWfc_AddWindows(wfc);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, TRUE);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, TRUE);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, TRUE);
    wfc->ownRank = FrontierData_WifiRankAction(wfc->args->frontierData, FRONTIER_DATA_GET);
    wfc->rank = wfc->ownRank;
    wfc->room = 1;
    wfc->waitingIcon = NULL;
    if (!DWC_CheckInet()) {
        NintendoWifiConnectArgs *args = wfc->args;
        if (args->connectNow != 0) {
            CommState_InitWfcSession(args->saveData);
            NintendoWfc_PrintMessage(wfc, wfc->msgDataWfc, msg_0778_00001, 1, 0xF0F);
            NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_CONNECT);
            NintendoWfc_ShowWaitingIcon(wfc);
        } else {
            Sys_ClearSleepDisableFlag(4);
            wfc->state = NINTENDO_WFC_STATE_ASK_CONNECT;
        }
    } else {
        CommState_InitWfcSession(wfc->args->saveData);
        wfc->state = NINTENDO_WFC_STATE_ASK_LOG_OUT;
    }
    return NINTENDO_WFC_MAIN_WAIT_FADE_IN;
}

enum NintendoWfcMainState NintendoWfc_SessionMain(NintendoWfcConnect *wfc, int state) {
    u32 prevState;
    enum NintendoWfcMainState result;
    WirelessStatusIcon_SetLevel(NintendoWfc_GetWifiIconLevel());
    prevState = wfc->state;
    result = gNintendoWfcStates[prevState](wfc);
    if (prevState != wfc->state) {
        wfc->subState = 0;
        wfc->subTimer = 0;
    }
    return result;
}

enum NintendoWfcMainState NintendoWfc_SessionExit(NintendoWfcConnect *wfc, int state) {
    if (wfc->paletteCycle.task != NULL) {
        SysTask_Destroy(wfc->paletteCycle.task);
        wfc->paletteCycle.task = NULL;
        wfc->paletteCycle.active = FALSE;
    }
    NintendoWfc_FreeStrings(wfc);
    NintendoWfc_RemoveWindows(wfc);
    NintendoWfc_FreeBgs(wfc->bgConfig);
    wfc->paletteCycle.active = FALSE;
    wfc->screen = wfc->nextScreen;
    if (wfc->screen == 0) {
        return NINTENDO_WFC_MAIN_DONE;
    }
    return NINTENDO_WFC_MAIN_SESSION_INIT;
}

static void NintendoWfc_InitBgs(BgConfig *bgConfig) {
    BgTemplate main0 = gNintendoWfcBgTemplate_Main0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &main0, GF_BG_TYPE_TEXT);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, FALSE);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    BgTemplate main1 = gNintendoWfcBgTemplate_Main1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &main1, GF_BG_TYPE_TEXT);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, FALSE);
    BgTemplate sub0 = gNintendoWfcBgTemplate_Sub0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &sub0, GF_BG_TYPE_TEXT);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, FALSE);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    BgTemplate sub1 = gNintendoWfcBgTemplate_Sub1;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &sub1, GF_BG_TYPE_TEXT);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG1, FALSE);
    BgTemplate sub2 = gNintendoWfcBgTemplate_Sub2;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &sub2, GF_BG_TYPE_TEXT);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, TRUE);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_67);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_67);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_2, 0x20, 0, HEAP_ID_67);
}

static void NintendoWfc_FreeBgs(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_0);
}

static void NintendoWfc_LoadSubScreenBg(NintendoWfcConnect *wfc, int numberPad) {
    NARC *narc;
    BgConfig *bgConfig = wfc->bgConfig;

    if (numberPad == 0) {
        narc = NARC_New(NARC_a_0_8_8, HEAP_ID_67);
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x100, HEAP_ID_67);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 11, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_67);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 12, bgConfig, GF_BG_LYR_SUB_1, 0, 0x600, FALSE, HEAP_ID_67);
        wfc->paletteCycle.screens = NINTENDO_WFC_PALETTE_BOTH_SCREENS;
        NARC_Delete(narc);
        return;
    } else {
        narc = NARC_New(NARC_a_2_3_6, HEAP_ID_67);
        wfc->paletteCycle.screens = NINTENDO_WFC_PALETTE_MAIN_SCREEN;
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 8, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x40, HEAP_ID_67);
        GfGfxLoader_LoadCharDataFromOpenNarc(narc, 9, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_67);
        GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, bgConfig, GF_BG_LYR_SUB_1, 0, 0x600, FALSE, HEAP_ID_67);
        NARC_Delete(narc);
        return;
    }
}

static void NintendoWfc_LoadBgGraphics(NintendoWfcConnect *wfc) {
    NNSG2dPaletteData *plttData;
    NARC *narc;
    int outer;
    int count;
    int blend;
    int last;
    u16 *dest;
    u16 *src;
    BgConfig *bgConfig = wfc->bgConfig;
    void *raw;
    int i;
    narc = NARC_New(NARC_a_0_8_8, HEAP_ID_67);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_67);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_67);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_67);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_13_OFFSET, HEAP_ID_67);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_MAIN_0, 1, 14, Options_GetFrame(wfc->args->options), HEAP_ID_67);
    LoadUserFrameGfx2(bgConfig, GF_BG_LYR_SUB_0, 1, 14, Options_GetFrame(wfc->args->options), HEAP_ID_67);
    LoadUserFrameGfx1(bgConfig, GF_BG_LYR_MAIN_0, 31, 11, 0, HEAP_ID_67);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, HEAP_ID_67);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, bgConfig, GF_BG_LYR_MAIN_1, 0, 0x600, FALSE, HEAP_ID_67);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 11, bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_67);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 12, bgConfig, GF_BG_LYR_SUB_1, 0, 0x600, FALSE, HEAP_ID_67);
    BG_SetMaskColor(GF_BG_LYR_MAIN_0, 0);
    BG_SetMaskColor(GF_BG_LYR_SUB_0, 0);
    MI_CpuFill8(&wfc->paletteCycle, 0, sizeof(NintendoWfcPaletteCycle));
    raw = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, &plttData, HEAP_ID_67);
    MIi_CpuCopy16(plttData->pRawData, wfc->paletteCycle.basePltt, 0x80);
    MIi_CpuCopy16(plttData->pRawData, wfc->paletteCycle.cyclePltt, 0x80);
    Heap_Free(raw);
    count = 0;
    outer = 0;
    dest = wfc->paletteCycle.cyclePltt;
    src = wfc->paletteCycle.basePltt;
    while (outer < 3) {
        blend = 0;
        last = 0;
        while (TRUE) {
            GF_ASSERT(count < NINTENDO_WFC_PALETTE_CYCLE_STEPS);
            for (i = 1; i < 16; i++) {
                BlendPalette(&src[i], &dest[i], 1, blend >> 8, wfc->paletteCycle.basePltt[(outer + 1) * 16 + i]);
            }
            dest += 16;
            count++;
            if (last == 1) {
                break;
            }
            blend += 0x300;
            if (blend >= 0x1000) {
                blend = 0x1000;
                last = 1;
            }
        }
        src += 16;
        outer++;
    }
    DC_FlushRange(wfc->paletteCycle.cyclePltt, sizeof(wfc->paletteCycle.cyclePltt));
    wfc->paletteCycle.active = TRUE;
    wfc->paletteCycle.screens = NINTENDO_WFC_PALETTE_BOTH_SCREENS;
    wfc->paletteCycle.task = SysTask_CreateOnVBlankQueue(NintendoWfc_PaletteCycleTask, &wfc->paletteCycle, 20);
    NARC_Delete(narc);
}

static void NintendoWfc_PaletteCycleTask(SysTask *task, void *data) {
    NintendoWfcPaletteCycle *cycle = data;
    if (cycle->active) {
        cycle->tick ^= 1;
        if (cycle->tick & 1) {
            return;
        }
        if (cycle->screens <= NINTENDO_WFC_PALETTE_MAIN_SCREEN) {
            GX_LoadBGPltt(cycle->cyclePltt + cycle->index * 16, 0, 0x20);
        }
        if (cycle->screens == NINTENDO_WFC_PALETTE_BOTH_SCREENS || cycle->screens == NINTENDO_WFC_PALETTE_SUB_SCREEN) {
            GXS_LoadBGPltt(cycle->cyclePltt + cycle->index * 16, 0, 0x20);
        }
        if (cycle->direction == 0) {
            cycle->index++;
            if (cycle->index >= NINTENDO_WFC_PALETTE_CYCLE_STEPS) {
                cycle->index = NINTENDO_WFC_PALETTE_CYCLE_STEPS - 2;
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
}

static void NintendoWfc_AddWindows(NintendoWfcConnect *wfc) {
    AddWindowParameterized(wfc->bgConfig, &wfc->errorWindow, GF_BG_LYR_MAIN_0, 4, 4, 23, 16, 13, 0xA4);
    FillWindowPixelBuffer(&wfc->errorWindow, 0);
    AddWindowParameterized(wfc->bgConfig, &wfc->roomWindow, GF_BG_LYR_MAIN_0, 26, 14, 4, 2, 13, 0x94);
    FillWindowPixelBuffer(&wfc->roomWindow, 15);
    AddWindowParameterized(wfc->bgConfig, &wfc->rankWindow, GF_BG_LYR_MAIN_0, 26, 14, 4, 2, 13, 0x9C);
    FillWindowPixelBuffer(&wfc->rankWindow, 15);
    AddWindowParameterized(wfc->bgConfig, &wfc->titleWindow, GF_BG_LYR_MAIN_0, 4, 1, 24, 2, 13, 0x214);
    FillWindowPixelBuffer(&wfc->titleWindow, 0);
    NintendoWfc_PrintAlignedText(&wfc->titleWindow, wfc->titleString, 0, 1, NINTENDO_WFC_ALIGN_CENTER, MAKE_TEXT_COLOR(15, 14, 0));
    AddWindowParameterized(wfc->bgConfig, &wfc->msgWindow, GF_BG_LYR_MAIN_0, 2, 19, 27, 4, 13, 0x28);
    FillWindowPixelBuffer(&wfc->msgWindow, 15);
}

static void NintendoWfc_RemoveWindows(NintendoWfcConnect *wfc) {
    RemoveWindow(&wfc->msgWindow);
    RemoveWindow(&wfc->titleWindow);
    RemoveWindow(&wfc->rankWindow);
    RemoveWindow(&wfc->roomWindow);
    RemoveWindow(&wfc->errorWindow);
}

static void NintendoWfc_InitStrings(NintendoWfcConnect *wfc) {
    wfc->msgString = String_New(180, HEAP_ID_67);
    wfc->roomString = String_New(4, HEAP_ID_67);
    wfc->rankString = String_New(3, HEAP_ID_67);
    wfc->titleString = NewString_ReadMsgData(wfc->msgDataTower, msg_0774_00012);
    wfc->errorString = String_New(256, HEAP_ID_67);
}

static void NintendoWfc_FreeStrings(NintendoWfcConnect *wfc) {
    String_Delete(wfc->errorString);
    String_Delete(wfc->titleString);
    String_Delete(wfc->rankString);
    String_Delete(wfc->roomString);
    String_Delete(wfc->msgString);
}

enum NintendoWfcMainState NintendoWfc_AskConnect(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataError, msg_0800_00017, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_OPEN_YES_NO_MENU, NINTENDO_WFC_STATE_HANDLE_CONNECT_CHOICE);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleConnectChoice(NintendoWfcConnect *wfc) {
    int choice = NintendoWfcYesNo_Run(&wfc->yesNoMenu);
    if (choice) {
        if (choice == YESNORESPONSE_NO) {
            CommState_FreeWfcSession();
            NintendoWfc_SetNextScreen(wfc, 0, 0);
            wfc->state = NINTENDO_WFC_STATE_START_EXIT;
        } else {
            NintendoWfc_PrintMessage(wfc, wfc->msgDataWfc, msg_0778_00001, 1, 0xF0F);
            NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_CONNECT);
            NintendoWfc_ShowWaitingIcon(wfc);
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_AskLogOut(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataWfc, msg_0778_00012, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_OPEN_YES_NO_MENU, NINTENDO_WFC_STATE_HANDLE_LOG_OUT_CHOICE);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleLogOutChoice(NintendoWfcConnect *wfc) {
    int result = NintendoWfcYesNo_Run(&wfc->yesNoMenu);
    if (result) {
        if (result == YESNORESPONSE_NO) {
            if (!DWC_CheckInet()) {
                wfc->state = NINTENDO_WFC_STATE_ASK_CONNECT;
            } else {
                wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTING;
            }
        } else {
            if (!DWC_CheckInet()) {
                NintendoWfc_SetNextScreen(wfc, 0, 0);
                wfc->state = NINTENDO_WFC_STATE_START_EXIT;
            } else {
                wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTING;
            }
            wfc->args->incomplete = 1;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartConnect(NintendoWfcConnect *wfc) {
    CommState_InitWfcSession(wfc->args->saveData);
    Sys_SetSleepDisableFlag(4);
    NintendoWfc_CreateWirelessIcon(wfc);
    DWC_InitInetEx(&wfc->connection, 2, 1, 20);
    DWC_SetAuthServer(2);
    DWC_ConnectInetAsync();
    wfc->state = NINTENDO_WFC_STATE_WAIT_CONNECT;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitConnect(NintendoWfcConnect *wfc) {
    int errorCode;
    int lastError;
    NetApInfo apInfo;
    DWC_ProcessInet();
    if (DWC_CheckInet()) {
        switch (DWC_GetInetStatus()) {
        case DWC_CONNECTINET_STATE_ERROR:
            wfc->dwcError = DWC_GetLastError(&errorCode);
            wfc->dwcErrorCode = errorCode;
            DWC_ClearError();
            DWC_CleanupInet();
            NintendoWfc_HideWaitingIcon(wfc);
            wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
            break;
        case DWC_CONNECTINET_STATE_NOT_INITIALIZED:
        case DWC_CONNECTINET_STATE_IDLE:
        case DWC_CONNECTINET_STATE_OPERATING:
        case DWC_CONNECTINET_STATE_OPERATED:
        case DWC_CONNECTINET_STATE_DISCONNECTING:
        case DWC_CONNECTINET_STATE_DISCONNECTED:
        case DWC_CONNECTINET_STATE_FATAL_ERROR:
        default:
            DWC_GetLastError(&lastError);
            NintendoWfc_HideWaitingIcon(wfc);
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            wfc->httpResult = NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR;
            break;
        case DWC_CONNECTINET_STATE_CONNECTED:
            DWC_GetApInfo(&apInfo);
            wfc->state = NINTENDO_WFC_STATE_START_AUTH;
            break;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartAuth(NintendoWfcConnect *wfc) {
    DWC_NASLoginAsync();
    wfc->state = NINTENDO_WFC_STATE_WAIT_AUTH;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitAuth(NintendoWfcConnect *wfc) {
    int errorCode;
    u32 errorType;
    switch (DWC_NASLoginProcess()) {
    case DWC_NASLOGIN_STATE_SUCCESS:
        wfc->state = NINTENDO_WFC_STATE_INIT_HTTP;
        break;
    case DWC_NASLOGIN_STATE_DIRTY:
    case DWC_NASLOGIN_STATE_ERROR:
    case DWC_NASLOGIN_STATE_CANCELED:
        NintendoWfc_HideWaitingIcon(wfc);
        wfc->dwcError = DWC_GetLastErrorEx(&errorCode, &errorType);
        wfc->dwcErrorCode = errorCode;
        DWC_ClearError();
        DWC_CleanupInet();
        wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
        switch (errorType) {
        case DWC_ETYPE_LIGHT:
        case DWC_ETYPE_SHOW_ERROR:
            wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_GHTTP:
            DWC_ShutdownGHTTP();
            wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
            break;
        case DWC_ETYPE_DISCONNECT:
            wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_FM:
            DWC_ShutdownFriendsMatch();
            wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
            break;
        case DWC_ETYPE_SHUTDOWN_ND:
        case DWC_ETYPE_FATAL:
            CommState_ShowRestartErrorAndHalt();
            break;
        }
        if (errorCode < -20000 && errorCode >= -29999) {
            wfc->state = NINTENDO_WFC_STATE_SHOW_DWC_ERROR;
        }
        break;
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_InitHttp(NintendoWfcConnect *wfc) {
    u32 profileId;
    u64 friendKey;
    if (Save_SysInfo_GetDwcProfileId(wfc->args->sysInfo) == 0) {
        Save_SysInfo_SetDwcProfileId(wfc->args->sysInfo, wfc->args->dwcProfileId);
    }
    profileId = Save_SysInfo_GetDwcProfileId(wfc->args->sysInfo);
    friendKey = DWC_CreateFriendKey(wfc->args->dwcUserData);
    NintendoWfcHttp_Init(profileId, friendKey);
    wfc->state = NINTENDO_WFC_STATE_REQUEST_INFO;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_RequestInfo(NintendoWfcConnect *wfc) {
    NintendoWfcHttp_RequestInfo();
    wfc->state = NINTENDO_WFC_STATE_WAIT_INFO;
    wfc->timeoutCounter = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitInfo(NintendoWfcConnect *wfc) {
    int result;
    if (NintendoWfcHttp_IsDone()) {
        result = NintendoWfcHttp_GetResult();
        wfc->timeoutCounter = 0;
        switch (result) {
        case NINTENDO_WFC_HTTP_RESULT_OK:
            NintendoWfc_HideWaitingIcon(wfc);
            switch (wfc->args->mode) {
            case NINTENDO_WFC_MODE_DOWNLOAD_ROOM:
                NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT, NINTENDO_WFC_STATE_ASK_CHALLENGE_ROOM);
                break;
            case NINTENDO_WFC_MODE_UPLOAD_RECORD:
                wfc->state = NINTENDO_WFC_STATE_PRINT_SENDING_RECORD;
                break;
            case NINTENDO_WFC_MODE_CHECK_LEADERS:
                wfc->state = NINTENDO_WFC_STATE_ASK_LEADERS_RANK;
                break;
            }
            break;
        case NINTENDO_WFC_HTTP_RESULT_MAINTENANCE:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
        case NINTENDO_WFC_HTTP_RESULT_CROWDED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_CANCELED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        default:
            NintendoWfc_HideWaitingIcon(wfc);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        wfc->timeoutCounter++;
        if (wfc->timeoutCounter == NINTENDO_WFC_HTTP_TIMEOUT_FRAMES) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_RequestSetProfile(NintendoWfcConnect *wfc) {
    Save_WiiMessage_GetServerProfile(wfc->args->saveData, &wfc->profile);
    NintendoWfcHttp_RequestSetProfile(&wfc->profile, wfc->profileResponse);
    wfc->state = NINTENDO_WFC_STATE_WAIT_SET_PROFILE;
    wfc->timeoutCounter = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitSetProfile(NintendoWfcConnect *wfc) {
    int result;
    if (NintendoWfcHttp_IsDone()) {
        result = NintendoWfcHttp_GetResult();
        wfc->timeoutCounter = 0;
        switch (result) {
        case NINTENDO_WFC_HTTP_RESULT_OK:
            NintendoWfc_HideWaitingIcon(wfc);
            switch (wfc->profileResponse[0]) {
            case 0:
                switch (wfc->profileResponse[1]) {
                case 0:
                    switch (wfc->args->mode) {
                    case NINTENDO_WFC_MODE_DOWNLOAD_ROOM:
                        NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT, NINTENDO_WFC_STATE_ASK_CHALLENGE_ROOM);
                        break;
                    case NINTENDO_WFC_MODE_UPLOAD_RECORD:
                        wfc->state = NINTENDO_WFC_STATE_PRINT_SENDING_RECORD;
                        break;
                    case NINTENDO_WFC_MODE_CHECK_LEADERS:
                        wfc->state = NINTENDO_WFC_STATE_ASK_LEADERS_RANK;
                        break;
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    wfc->httpResult = result;
                    wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
                    NintendoWfc_HideWaitingIcon(wfc);
                    break;
                }
                break;
            case 1:
            case 2:
                wfc->httpResult = result;
                wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
                NintendoWfc_HideWaitingIcon(wfc);
                break;
            default:
                NintendoWfc_HideWaitingIcon(wfc);
                CommState_ShowRestartErrorAndHalt();
                break;
            }
            break;
        case NINTENDO_WFC_HTTP_RESULT_MAINTENANCE:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
        case NINTENDO_WFC_HTTP_RESULT_CROWDED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_CANCELED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        default:
            NintendoWfc_HideWaitingIcon(wfc);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        wfc->timeoutCounter++;
        if (wfc->timeoutCounter == NINTENDO_WFC_HTTP_TIMEOUT_FRAMES) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_RequestRoomCount(NintendoWfcConnect *wfc) {
    NintendoWfcHttp_RequestRoomCount(wfc->rank);
    wfc->state = NINTENDO_WFC_STATE_WAIT_ROOM_COUNT;
    wfc->timeoutCounter = 0;
    NintendoWfc_ShowWaitingIcon(wfc);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitRoomCount(NintendoWfcConnect *wfc) {
    int value;

    if (NintendoWfcHttp_IsDone()) {
        value = NintendoWfcHttp_GetResult();
        wfc->timeoutCounter = 0;
        switch (value) {
        case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
            wfc->httpResult = value;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            break;
        case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
            wfc->httpResult = value;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            break;
        case NINTENDO_WFC_HTTP_RESULT_BAD_ROOM:
            wfc->httpResult = value;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            break;
        case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
            wfc->httpResult = value;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            break;
        case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_CANCELED:
            wfc->httpResult = value;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            break;
        case NINTENDO_WFC_HTTP_RESULT_FATAL:
            wfc->httpResult = value;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            CommState_ShowRestartErrorAndHalt();
            break;
        default:
            if (value > 0) {
                wfc->roomCount = value;
                wfc->state = wfc->nextState;
            }
            break;
        }
        NintendoWfc_HideWaitingIcon(wfc);
    } else {
        wfc->timeoutCounter++;
        if (wfc->timeoutCounter == NINTENDO_WFC_HTTP_TIMEOUT_FRAMES) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_AskChallengeRoom(NintendoWfcConnect *wfc) {
    int roomCount = wfc->roomCount;

    if (roomCount >= 100) {
        BufferIntegerAsString(wfc->msgFormat, 0, roomCount, 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
        NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00011, 1, 0xF0F);
    } else {
        BufferIntegerAsString(wfc->msgFormat, 0, roomCount, 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
        NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00000, 1, 0xF0F);
    }
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_CHALLENGE_ROOM_INPUT);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartChallengeRoomInput(NintendoWfcConnect *wfc) {
    NintendoWfc_StartNumberInput(wfc, 1, wfc->roomCount);
    wfc->state = NINTENDO_WFC_STATE_HANDLE_CHALLENGE_ROOM_INPUT;
    NintendoWfc_NumberInputDummy(wfc, 0, 1);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleChallengeRoomInput(NintendoWfcConnect *wfc) {
    RTCTime time;
    RTCDate date;
    int value = NintendoWfc_RunNumberInput(wfc);

    if (value != 0) {
        if (value > 0) {
            DWC_GetDateTime(&date, &time);
            wfc->room = value;
            if (BattleRoomDownload_IsRoomMarked(wfc->args->battleRoomDownload, (u8)wfc->rank, (u8)wfc->room, &date)) {
                wfc->state = NINTENDO_WFC_STATE_PRINT_ROOM_UNAVAILABLE;
            } else {
                wfc->state = NINTENDO_WFC_STATE_PRINT_RECEIVING_TRAINERS;
            }
        } else {
            NintendoWfc_NumberInputDummy(wfc, 0, 0);
            wfc->state = NINTENDO_WFC_STATE_ASK_CANCEL_CHALLENGE;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintReceivingTrainers(NintendoWfcConnect *wfc) {
    BufferIntegerAsString(wfc->msgFormat, 0, wfc->room, 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BufferIntegerAsString(wfc->msgFormat, 1, wfc->rank, 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00001, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_REQUEST_TRAINERS_DOWNLOAD);
    MIi_CpuClearFast(0, (u32 *)&wfc->downloadBuffer, sizeof(wfc->downloadBuffer));
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintRoomUnavailable(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00002, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_ASK_CHALLENGE_ROOM);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_RequestTrainersDownload(NintendoWfcConnect *wfc) {
    NintendoWfcHttp_RequestDownload(wfc->ownRank, wfc->room, &wfc->downloadBuffer);
    NintendoWfc_ShowWaitingIcon(wfc);
    wfc->state = NINTENDO_WFC_STATE_WAIT_TRAINERS_DOWNLOAD;
    wfc->timeoutCounter = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitTrainersDownload(NintendoWfcConnect *wfc) {
    if (NintendoWfcHttp_IsDone()) {
        int result = NintendoWfcHttp_GetResult();
        wfc->timeoutCounter = 0;
        switch (result) {
        case NINTENDO_WFC_HTTP_RESULT_OK: {
            RTCTime time;
            RTCDate date;
            BattleRoomDownload_SetTrainers(wfc->args->battleRoomDownload, wfc->downloadBuffer.trainers, (u8)wfc->ownRank, (u8)wfc->room);
            NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_START_SAVE, NINTENDO_WFC_STATE_PRINT_TRAINERS_RECEIVED);
            DWC_GetDateTime(&date, &time);
            BattleRoomDownload_MarkRoom(wfc->args->battleRoomDownload, (u8)wfc->rank, (u8)wfc->room, &date);
        } break;
        case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_BAD_ROOM:
        case NINTENDO_WFC_HTTP_RESULT_CANCELED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_FATAL:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        wfc->timeoutCounter++;
        if (wfc->timeoutCounter == NINTENDO_WFC_HTTP_TIMEOUT_FRAMES) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintTrainersReceived(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00003, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_DISCONNECT);
    NintendoWfc_HideWaitingIcon(wfc);
    wfc->args->incomplete = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintSendingRecord(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00007, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_REQUEST_UPLOAD);
    NintendoWfc_ShowWaitingIcon(wfc);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_RequestUpload(NintendoWfcConnect *wfc) {
    u8 buf[4];
    int winCount = FrontierData_GetWifiWinCount(wfc->args->frontierData);
    BattleRoomDownload_GetTrainersRoom(wfc->args->battleRoomDownload, buf);
    Frontier_FillWifiUploadRecord(wfc->args->saveData, 1, &wfc->uploadRecord);
    NintendoWfcHttp_RequestUpload(buf[0], buf[1], winCount, &wfc->uploadRecord);
    wfc->state = NINTENDO_WFC_STATE_WAIT_UPLOAD;
    wfc->timeoutCounter = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitUpload(NintendoWfcConnect *wfc) {
    int result;
    if (NintendoWfcHttp_IsDone()) {
        result = NintendoWfcHttp_GetResult();
        wfc->timeoutCounter = 0;
        switch (result) {
        case NINTENDO_WFC_HTTP_RESULT_OK:
            FrontierData_FlagAction(wfc->args->frontierData, 5, FRONTIER_DATA_RESET);
            NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_START_SAVE, NINTENDO_WFC_STATE_PRINT_RECORD_SENT);
            break;
        case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_BAD_ROOM:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_CANCELED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_FATAL:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        wfc->timeoutCounter++;
        if (wfc->timeoutCounter == NINTENDO_WFC_HTTP_TIMEOUT_FRAMES) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintRecordSent(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00008, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_DISCONNECT);
    NintendoWfc_HideWaitingIcon(wfc);
    wfc->args->incomplete = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_AskLeadersRank(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00005, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_LEADERS_RANK_INPUT);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartLeadersRankInput(NintendoWfcConnect *wfc) {
    wfc->rank = 1;
    NintendoWfc_NumberInputDummy(wfc, 1, 1);
    NintendoWfc_StartNumberInput(wfc, 1, 10);
    wfc->state = NINTENDO_WFC_STATE_HANDLE_LEADERS_RANK_INPUT;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleLeadersRankInput(NintendoWfcConnect *wfc) {
    int value = NintendoWfc_RunNumberInput(wfc);
    if (value != 0) {
        if (value > 0) {
            wfc->rank = value;
            NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT, NINTENDO_WFC_STATE_ASK_LEADERS_ROOM);
        } else {
            wfc->state = NINTENDO_WFC_STATE_ASK_CANCEL_DOWNLOAD;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_AskLeadersRoom(NintendoWfcConnect *wfc) {
    if (wfc->roomCount >= 100) {
        BufferIntegerAsString(wfc->msgFormat, 0, wfc->roomCount, 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
        NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00010, 1, 0xF0F);
    } else {
        BufferIntegerAsString(wfc->msgFormat, 0, wfc->roomCount, 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
        NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00006, 1, 0xF0F);
    }
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_LEADERS_ROOM_INPUT);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartLeadersRoomInput(NintendoWfcConnect *wfc) {
    wfc->room = 1;
    NintendoWfc_StartNumberInput(wfc, 1, wfc->roomCount);
    NintendoWfc_NumberInputDummy(wfc, 0, 1);
    wfc->state = NINTENDO_WFC_STATE_HANDLE_LEADERS_ROOM_INPUT;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleLeadersRoomInput(NintendoWfcConnect *wfc) {
    int value = NintendoWfc_RunNumberInput(wfc);
    if (value != 0) {
        if (value > 0) {
            wfc->room = value;
            wfc->state = NINTENDO_WFC_STATE_PRINT_RECEIVING_LEADERS;
        } else {
            wfc->state = NINTENDO_WFC_STATE_ASK_LEADERS_RANK;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintReceivingLeaders(NintendoWfcConnect *wfc) {
    BufferIntegerAsString(wfc->msgFormat, 0, wfc->room, 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BufferIntegerAsString(wfc->msgFormat, 1, wfc->rank, 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    NintendoWfc_PrintFormattedMessage(wfc, wfc->msgDataTower, msg_0774_00001, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_REQUEST_LEADERS_DOWNLOAD);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_RequestLeadersDownload(NintendoWfcConnect *wfc) {
    NintendoWfcHttp_RequestDownload(wfc->rank, wfc->room, &wfc->downloadBuffer);
    wfc->state = NINTENDO_WFC_STATE_WAIT_LEADERS_DOWNLOAD;
    wfc->timeoutCounter = 0;
    NintendoWfc_ShowWaitingIcon(wfc);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitLeadersDownload(NintendoWfcConnect *wfc) {
    if (NintendoWfcHttp_IsDone()) {
        int result = NintendoWfcHttp_GetResult();
        wfc->timeoutCounter = 0;
        switch (result) {
        case NINTENDO_WFC_HTTP_RESULT_OK:
            BattleRoomDownload_SetLeaders(wfc->args->battleRoomDownload, wfc->downloadBuffer.leaders, (u8)wfc->rank, (u8)wfc->room);
            NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_START_SAVE, NINTENDO_WFC_STATE_PRINT_LEADERS_RECEIVED);
            break;
        case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_BAD_ROOM:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
        case NINTENDO_WFC_HTTP_RESULT_CANCELED:
            wfc->state = NINTENDO_WFC_STATE_REQUEST_ROOM_COUNT;
            wfc->httpResult = result;
            NintendoWfc_HideWaitingIcon(wfc);
            break;
        case NINTENDO_WFC_HTTP_RESULT_FATAL:
            wfc->httpResult = result;
            wfc->state = NINTENDO_WFC_STATE_SHOW_HTTP_ERROR;
            NintendoWfc_HideWaitingIcon(wfc);
            CommState_ShowRestartErrorAndHalt();
            break;
        }
    } else {
        ++wfc->timeoutCounter;
        if (wfc->timeoutCounter == NINTENDO_WFC_HTTP_TIMEOUT_FRAMES) {
            CommState_ShowRestartErrorAndHalt();
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintLeadersReceived(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00003, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_START_DISCONNECT);
    NintendoWfc_HideWaitingIcon(wfc);
    wfc->args->incomplete = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartDisconnect(NintendoWfcConnect *wfc) {
    wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTING;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartSave(NintendoWfcConnect *wfc) {
    Save_PrepareForAsyncWrite(wfc->args->saveData, 2);
    wfc->state = NINTENDO_WFC_STATE_SAVE;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_Save(NintendoWfcConnect *wfc) {
    if (Save_WriteFileAsync(wfc->args->saveData) == WRITE_STATUS_SUCCESS) {
        wfc->state = wfc->nextState;
        NintendoWfc_HideWaitingIcon(wfc);
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_AskCancelChallenge(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00004, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_OPEN_YES_NO_MENU, NINTENDO_WFC_STATE_HANDLE_CANCEL_CHALLENGE_CHOICE);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleCancelChallengeChoice(NintendoWfcConnect *wfc) {
    int result = NintendoWfcYesNo_Run(&wfc->yesNoMenu);
    if (result) {
        if (result == YESNORESPONSE_NO) {
            wfc->state = NINTENDO_WFC_STATE_ASK_CHALLENGE_ROOM;
        } else {
            wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTING;
            wfc->args->incomplete = 1;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_AskCancelDownload(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00009, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_OPEN_YES_NO_MENU, NINTENDO_WFC_STATE_HANDLE_CANCEL_DOWNLOAD_CHOICE);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_HandleCancelDownloadChoice(NintendoWfcConnect *wfc) {
    int result = NintendoWfcYesNo_Run(&wfc->yesNoMenu);
    if (result) {
        if (result == YESNORESPONSE_NO) {
            wfc->state = NINTENDO_WFC_STATE_ASK_LEADERS_RANK;
        } else {
            wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTING;
            wfc->args->incomplete = 1;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintDisconnecting(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataError, msg_0800_00026, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_CLOSE_CONNECTION);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_CloseConnection(NintendoWfcConnect *wfc) {
    DWC_CleanupInet();
    NintendoWfc_SetNextScreen(wfc, 0, 0);
    wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTED;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_PrintDisconnected(NintendoWfcConnect *wfc) {
    NintendoWfc_PrintMessage(wfc, wfc->msgDataError, msg_0800_00027, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE_AND_DELAY, NINTENDO_WFC_STATE_START_EXIT);
    wfc->messageTimer = 0;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_UnusedState_Idle(void) {
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_StartExit(NintendoWfcConnect *wfc) {
    WirelessStatusIcon_Destroy();
    CommState_FreeWfcSession();
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 8, 1, HEAP_ID_67);
    wfc->state = NINTENDO_WFC_STATE_ASK_CONNECT;
    return NINTENDO_WFC_MAIN_SESSION_EXIT;
}

enum NintendoWfcMainState NintendoWfc_UnusedState_HandleYesNo(NintendoWfcConnect *wfc) {
    int response = NintendoWfc_HandleYesNoPrompt(wfc->yesNoPrompt);
    if (response) {
        if (response == YESNORESPONSE_NO) {
            wfc->state = NINTENDO_WFC_STATE_ASK_CONNECT;
        } else {
            wfc->state = NINTENDO_WFC_STATE_PRINT_DISCONNECTING;
        }
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_ShowHttpError(NintendoWfcConnect *wfc) {
    int msgNo = msg_0774_00000;
    switch (wfc->httpResult) {
    case NINTENDO_WFC_HTTP_RESULT_NOT_CONNECTED:
    case NINTENDO_WFC_HTTP_RESULT_SERVER_ERROR:
        msgNo = msg_0774_00015;
        break;
    case NINTENDO_WFC_HTTP_RESULT_MAINTENANCE:
        msgNo = msg_0774_00013;
        break;
    case NINTENDO_WFC_HTTP_RESULT_UPLOAD_CROWDED:
    case NINTENDO_WFC_HTTP_RESULT_CROWDED:
        msgNo = msg_0774_00014;
        break;
    case NINTENDO_WFC_HTTP_RESULT_DISCONNECTED:
    case NINTENDO_WFC_HTTP_RESULT_CANCELED:
        msgNo = msg_0774_00016;
        break;
    case NINTENDO_WFC_HTTP_RESULT_BAD_ROOM:
        msgNo = msg_0774_00017;
        break;
    }
    NintendoWfc_HideWaitingIcon(wfc);
    NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msgNo, 1, 0xF0F);
    NintendoWfc_SetState(wfc, NINTENDO_WFC_STATE_WAIT_MESSAGE, NINTENDO_WFC_STATE_DISCONNECT);
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_Disconnect(NintendoWfcConnect *wfc) {
    switch (wfc->subState) {
    case NINTENDO_WFC_DISCONNECT_PRINT:
        NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00018, 1, 0xF0F);
        wfc->subState++;
        break;
    case NINTENDO_WFC_DISCONNECT_CLEANUP:
        if (TextPrinterCheckActive(wfc->textPrinterId) == 0) {
            CommState_FreeWfcSession();
            DWC_CleanupInet();
            wfc->subState++;
        }
        break;
    case NINTENDO_WFC_DISCONNECT_PRINT_DONE:
        NintendoWfc_PrintMessage(wfc, wfc->msgDataTower, msg_0774_00019, 1, 0xF0F);
        wfc->subState++;
        break;
    case NINTENDO_WFC_DISCONNECT_WAIT_PRINT:
        if (TextPrinterCheckActive(wfc->textPrinterId) == 0) {
            wfc->subState++;
        }
        break;
    default:
        wfc->subTimer++;
        if (wfc->subTimer > 30) {
            NintendoWfc_SetNextScreen(wfc, 0, 0);
            wfc->state = NINTENDO_WFC_STATE_START_EXIT;
        }
        break;
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitMessage(NintendoWfcConnect *wfc) {
    if (!TextPrinterCheckActive(wfc->textPrinterId)) {
        wfc->state = wfc->nextState;
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitMessageAndDelay(NintendoWfcConnect *wfc) {
    if (!TextPrinterCheckActive(wfc->textPrinterId)) {
        if (wfc->messageTimer > 30) {
            wfc->state = wfc->nextState;
        }
        wfc->messageTimer++;
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_OpenYesNoMenu(NintendoWfcConnect *wfc) {
    if (!TextPrinterCheckActive(wfc->textPrinterId)) {
        wfc->yesNoMenu.cursorSprite = wfc->sprites[NINTENDO_WFC_SPRITE_YES_NO_CURSOR];
        wfc->yesNoMenu.bgConfig = wfc->bgConfig;
        wfc->yesNoMenu.heapID = HEAP_ID_67;
        wfc->yesNoMenu.initialChoice = 0;
        wfc->yesNoMenu.bgPltt = 10;
        wfc->yesNoMenu.bgLayer = GF_BG_LYR_SUB_2;
        wfc->yesNoMenu.textBgLayer = GF_BG_LYR_SUB_0;
        wfc->yesNoMenu.fontPltt = 11;
        wfc->yesNoMenu.baseTile = 1;
        wfc->yesNoMenu.cursorOffsetY = 256;
        NintendoWfcYesNo_Init(&wfc->yesNoMenu);
        wfc->state = wfc->nextState;
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

static void NintendoWfc_PrintFormattedMessage(NintendoWfcConnect *wfc, MsgData *msgData, int msgNo, int textSpeed, int unused) {
    String *string = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(wfc->msgFormat, wfc->msgString, string);
    FillWindowPixelBuffer(&wfc->msgWindow, 15);
    DrawFrameAndWindow2(&wfc->msgWindow, FALSE, 1, 14);
    wfc->textPrinterId = AddTextPrinterParameterized(&wfc->msgWindow, 1, wfc->msgString, 0, 0, textSpeed, NULL);
    String_Delete(string);
}

enum NintendoWfcMainState NintendoWfc_ShowDwcError(NintendoWfcConnect *wfc) {
    int msgNo = WifiConnection_ClassifyErrorCode(-wfc->dwcErrorCode, wfc->dwcErrorType);
    NintendoWfc_ShowErrorMessage(wfc, msgNo, -wfc->dwcErrorCode);
    wfc->state = NINTENDO_WFC_STATE_WAIT_ERROR_DISMISS;
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

enum NintendoWfcMainState NintendoWfc_WaitErrorDismiss(NintendoWfcConnect *wfc) {
    if ((gSystem.newKeys & PAD_BUTTON_A) || (gSystem.newKeys & PAD_BUTTON_B) || gSystem.touchNew) {
        EraseFrameAndWindow1(&wfc->errorWindow, FALSE);
        wfc->state = NINTENDO_WFC_STATE_ASK_CONNECT;
    }
    return NINTENDO_WFC_MAIN_SESSION_MAIN;
}

static void NintendoWfc_PrintMessage(NintendoWfcConnect *wfc, MsgData *msgData, int msgNo, int textSpeed, int unused) {
    ReadMsgDataIntoString(msgData, msgNo, wfc->msgString);
    FillWindowPixelBuffer(&wfc->msgWindow, 15);
    DrawFrameAndWindow2(&wfc->msgWindow, FALSE, 1, 14);
    wfc->textPrinterId = AddTextPrinterParameterized(&wfc->msgWindow, 1, wfc->msgString, 0, 0, textSpeed, NULL);
}

static int NintendoWfc_GetAlignedTextX(const Window *window, String *string, int x, int alignment, int unused, int fontId) {
    int width;
    switch (alignment) {
    case NINTENDO_WFC_ALIGN_CENTER:
        width = FontID_String_GetWidth(fontId, string, 0);
        x = ((window->width << 3) - width) / 2;
        break;
    case NINTENDO_WFC_ALIGN_RIGHT:
        width = FontID_String_GetWidth(fontId, string, 0);
        x = (window->width << 3) - width;
        break;
    }
    return x;
}

static void NintendoWfc_PrintAlignedText(Window *window, String *string, int x, int y, int alignment, u32 color) {
    x = NintendoWfc_GetAlignedTextX(window, string, x, alignment, color, 1);
    AddTextPrinterParameterizedWithColor(window, 1, string, x, y, TEXT_SPEED_INSTANT, color, NULL);
}

static void NintendoWfc_CreateWirelessIcon(NintendoWfcConnect *wfc) {
    WirelessStatusIcon_Create();
}

static void NintendoWfc_NumberInputDummy(NintendoWfcConnect *wfc, int unused1, int unused2) {
}

static void NintendoWfc_ShowWaitingIcon(NintendoWfcConnect *wfc) {
    if (!wfc->waitingIcon) {
        wfc->waitingIcon = WaitingIcon_New(&wfc->msgWindow, 1);
    }
}

static void NintendoWfc_HideWaitingIcon(NintendoWfcConnect *wfc) {
    WaitingIcon *waitingIcon = wfc->waitingIcon;
    if (waitingIcon) {
        WaitingIcon_Delete(waitingIcon);
        wfc->waitingIcon = NULL;
    }
}

static void NintendoWfc_PrintErrorMessage(NintendoWfcConnect *wfc, int msgNo) {
    String *string = String_New(256, HEAP_ID_67);

    ReadMsgDataIntoString(wfc->msgDataError, msgNo, string);
    StringExpandPlaceholders(wfc->msgFormat, wfc->errorString, string);
    FillWindowPixelBuffer(&wfc->errorWindow, 15);
    DrawFrameAndWindow1(&wfc->errorWindow, TRUE, 31, 11);
    wfc->textPrinterId = AddTextPrinterParameterized(&wfc->errorWindow, 1, wfc->errorString, 0, 0, TEXT_SPEED_INSTANT, NULL);
    String_Delete(string);
}

static void NintendoWfc_ShowErrorMessage(NintendoWfcConnect *wfc, int msgNo, int errorCode) {
    if (msgNo == -1) {
        msgNo = 11;
    }
    BufferIntegerAsString(wfc->msgFormat, 0, errorCode, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
    ClearFrameAndWindow2(&wfc->msgWindow, TRUE);
    NintendoWfc_PrintErrorMessage(wfc, msgNo);
}

static int NintendoWfc_StartNumberInput(NintendoWfcConnect *wfc, int a1, int maxValue) {
    wfc->numberInput.unk_0 = a1;
    wfc->numberInput.maxValue = maxValue;
    wfc->numberInput.value = 0;
    wfc->numberInput.cursor = 0;
    if (maxValue != 100) {
        wfc->numberInput.digitPos = 1;
        wfc->twoDigits = 1;
    } else {
        wfc->numberInput.digitPos = 0;
        wfc->twoDigits = 0;
    }
    wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_FADE_OUT;
    wfc->numberInput.digits[0] = -1;
    wfc->numberInput.digits[1] = -1;
    wfc->numberInput.digits[2] = -1;
    wfc->padColumn[0] = 0;
    wfc->padColumn[1] = 1;
    if (wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR]) {
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], 0);
    }
    return 1;
}

static int NintendoWfc_RunNumberInput(NintendoWfcConnect *wfc) {
    if (gNintendoWfcNumberInputStates[wfc->numberInput.state](wfc) == TRUE) {
        return wfc->numberInput.value;
    }
    return 0;
}

BOOL NintendoWfc_NumberInput_FadeOut(NintendoWfcConnect *wfc) {
    BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 4, 1, HEAP_ID_67);
    wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_SETUP;
    return FALSE;
}

BOOL NintendoWfc_NumberInput_Setup(NintendoWfcConnect *wfc) {
    if (IsPaletteFadeFinished() == TRUE) {
        NintendoWfc_ShowNumberInputSprites(wfc);
        NintendoWfc_MoveDigitCursor(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], wfc->numberInput.digitPos, wfc->twoDigits);
        NintendoWfc_LoadSubScreenBg(wfc, 1);
        NintendoWfc_AddNumberInputWindows(wfc);
        NintendoWfc_PrintButtonLabel(&wfc->buttonWindows[0], wfc->msgDataTower, msg_0774_00020);
        NintendoWfc_PrintButtonLabel(&wfc->buttonWindows[1], wfc->msgDataTower, msg_0774_00021);
        NintendoWfc_PrintButtonLabel(&wfc->buttonWindows[2], wfc->msgDataTower, msg_0774_00022);
        ToggleBgLayer(GF_BG_LYR_SUB_0, TRUE);
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 4, 1, HEAP_ID_67);
        wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_WAIT_FADE_IN;
    }
    return FALSE;
}

static void NintendoWfc_ShowNumberInputSprites(NintendoWfcConnect *wfc) {
    int i;

    if (wfc->numberInput.maxValue == 100) {
        Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0], TRUE);
    }
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + 1], TRUE);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + 2], TRUE);
    for (i = 0; i < 3; i++) {
        NintendoWfc_SetDigitSpritePosition(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], i, wfc->twoDigits);
    }
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], TRUE);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], TRUE);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0], TRUE);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + 1], TRUE);
    Sprite_SetDrawFlag(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + 2], TRUE);
}

BOOL NintendoWfc_NumberInput_WaitFadeIn(NintendoWfcConnect *wfc) {
    if (IsPaletteFadeFinished() == TRUE) {
        wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_MAIN;
    }
    return FALSE;
}

static int NintendoWfc_GetTouchedPadKey(NintendoWfcConnect *wfc) {
    if (wfc->numberInput.maxValue == 100) {
        return TouchscreenHitbox_FindRectAtTouchNew(gNintendoWfcPadHitboxes_Max100);
    }
    return TouchscreenHitbox_FindRectAtTouchNew(gNintendoWfcPadHitboxes);
}

static u8 NintendoWfc_GetPadNeighbor(u32 key, u32 direction, u16 *padColumn) {
    u8 next = gNintendoWfcPadNeighbors[key][direction];

    if (next == NINTENDO_WFC_PAD_UP_FROM_LEFT_BUTTON) {
        next = gNintendoWfcPadKeysUpFromLeftButton[padColumn[0]];
    } else if (next == NINTENDO_WFC_PAD_DOWN_FROM_LEFT_BUTTON) {
        next = gNintendoWfcPadKeysDownFromLeftButton[padColumn[0]];
    } else if (next == NINTENDO_WFC_PAD_UP_FROM_RIGHT_BUTTON) {
        next = gNintendoWfcPadKeysUpFromRightButton[padColumn[1]];
    } else if (next == NINTENDO_WFC_PAD_DOWN_FROM_RIGHT_BUTTON) {
        next = gNintendoWfcPadKeysDownFromRightButton[padColumn[1]];
    } else if (next == NINTENDO_WFC_PAD_KEY_BACK) {
        if (key == 5 || key == 0) {
            padColumn[0] = 0;
        } else if (key == 1 || key == 6) {
            padColumn[0] = 1;
        }
    } else if (next == NINTENDO_WFC_PAD_KEY_CANCEL) {
        if (key == 3 || key == 8) {
            padColumn[1] = 0;
        } else if (key == 4 || key == 9) {
            padColumn[1] = 1;
        }
    }
    return next;
}

static int NintendoWfc_GetEnteredNumber(NintendoWfcNumberInput *input, int newDigit) {
    int digits[3];
    int selected[3];
    int placeValue = 100;
    int digitCount = 3;
    int outputCount;
    BOOL started;
    int i;
    int sum;

    for (i = 0; i < 3; i++) {
        digits[i] = input->digits[i];
    }
    if (newDigit != -1) {
        digits[input->digitPos] = newDigit;
    }
    outputCount = 0;
    started = FALSE;
    for (i = 0; i < 3; i++) {
        if ((input->digits[i] == 0 && !started) || digits[i] < 0) {
            placeValue /= 10;
            digitCount--;
        } else {
            started = TRUE;
            selected[outputCount++] = digits[i];
        }
    }
    sum = 0;
    for (i = 0; i < digitCount; i++) {
        sum += selected[i] * placeValue;
        placeValue /= 10;
    }
    if (sum > input->maxValue) {
        return -1;
    }
    return sum;
}

static BOOL NintendoWfc_AreDigitsComplete(NintendoWfcNumberInput *input) {
    if (input->maxValue != 100) {
        if (input->digits[1] >= 0 && input->digits[2] >= 0) {
            return TRUE;
        }
    } else {
        if (input->digits[0] >= 0 && input->digits[1] >= 0 && input->digits[2] >= 0) {
            return TRUE;
        }
    }
    return FALSE;
}

static u8 NintendoWfc_GetCursorAfterDigit(NintendoWfcNumberInput *input) {
    if (NintendoWfc_AreDigitsComplete(input)) {
        return NINTENDO_WFC_PAD_KEY_OK;
    }
    return input->cursor;
}

static void NintendoWfc_PressPadKey(NintendoWfcConnect *wfc, int key) {
    switch (key) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        if (NintendoWfc_GetEnteredNumber(&wfc->numberInput, key - 3) != -1) {
            wfc->numberInput.digits[wfc->numberInput.digitPos] = key - 3;
            if (wfc->numberInput.digitPos < 2) {
                wfc->numberInput.digitPos++;
            }
            NintendoWfc_MoveDigitCursor(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], wfc->numberInput.digitPos, wfc->twoDigits);
            wfc->numberInput.cursor = key - 3;
            wfc->numberInput.cursor = NintendoWfc_GetCursorAfterDigit(&wfc->numberInput);
            NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
            PlaySE(SEQ_SE_DP_SELECT);
            NintendoWfc_StartButtonFlash(wfc, gNintendoWfcPadKeyFlashes[key - 3].x, gNintendoWfcPadKeyFlashes[key - 3].y, NINTENDO_WFC_NUMBER_INPUT_MAIN);
        } else {
            PlaySE(SEQ_SE_DP_CUSTOM06);
        }
        break;
    case 13:
        wfc->numberInput.digits[wfc->numberInput.digitPos] = -1;
        wfc->numberInput.digitPos--;
        if (wfc->numberInput.maxValue == 100) {
            if (wfc->numberInput.digitPos < 0) {
                wfc->numberInput.digitPos = 0;
            }
        } else if (wfc->numberInput.digitPos < 1) {
            wfc->numberInput.digitPos = 1;
        }
        PlaySE(SEQ_SE_DP_SELECT);
        NintendoWfc_MoveDigitCursor(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_CURSOR], wfc->numberInput.digitPos, wfc->twoDigits);
        Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0], 5);
        break;
    case 14:
        wfc->numberInput.cursor = key - 3;
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
        wfc->numberInput.value = NintendoWfc_GetEnteredNumber(&wfc->numberInput, -1);
        if (wfc->numberInput.value <= 0) {
            wfc->numberInput.value = 1;
        }
        wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_START_FADE_OUT;
        PlaySE(SEQ_SE_DP_SELECT);
        Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + 1], 5);
        break;
    case 15:
        wfc->numberInput.cursor = key - 3;
        wfc->numberInput.value = -1;
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
        wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_START_FADE_OUT;
        PlaySE(SEQ_SE_DP_SELECT);
        Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_BUTTON_0 + 2], 5);
        break;
    }
}

static BOOL NintendoWfc_HandlePadButtons(NintendoWfcConnect *wfc) {
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        wfc->numberInput.cursor = NintendoWfc_GetPadNeighbor(wfc->numberInput.cursor, 0, wfc->padColumn);
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
        PlaySE(SEQ_SE_DP_SELECT);
    } else if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        wfc->numberInput.cursor = NintendoWfc_GetPadNeighbor(wfc->numberInput.cursor, 1, wfc->padColumn);
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
        PlaySE(SEQ_SE_DP_SELECT);
    } else if (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) {
        wfc->numberInput.cursor = NintendoWfc_GetPadNeighbor(wfc->numberInput.cursor, 2, wfc->padColumn);
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
        PlaySE(SEQ_SE_DP_SELECT);
    } else if (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) {
        wfc->numberInput.cursor = NintendoWfc_GetPadNeighbor(wfc->numberInput.cursor, 3, wfc->padColumn);
        NintendoWfc_MovePadCursor(wfc->sprites[NINTENDO_WFC_SPRITE_PAD_CURSOR], wfc->numberInput.cursor);
        PlaySE(SEQ_SE_DP_SELECT);
    } else if (gSystem.newKeys & PAD_BUTTON_A) {
        NintendoWfc_PressPadKey(wfc, wfc->numberInput.cursor + 3);
    } else if (gSystem.newKeys & PAD_BUTTON_B) {
        NintendoWfc_PressPadKey(wfc, 13);
    }
    return FALSE;
}

BOOL NintendoWfc_NumberInput_Main(NintendoWfcConnect *wfc) {
    int key = NintendoWfc_GetTouchedPadKey(wfc);

    if (key == -1) {
        NintendoWfc_HandlePadButtons(wfc);
    } else {
        NintendoWfc_PressPadKey(wfc, key);
    }
    NintendoWfc_UpdateDigitSprites(wfc);
    return FALSE;
}

static void NintendoWfc_UpdateDigitSprites(NintendoWfcConnect *wfc) {
    int i;

    for (i = 0; i < 3; i++) {
        s8 digit = wfc->numberInput.digits[i];
        if (digit == -1) {
            Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], 0);
        } else if (digit >= 0 && digit <= 9) {
            Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], digit + 1);
        }
    }
}

BOOL NintendoWfc_NumberInput_UnusedState4(void) {
    return FALSE;
}

BOOL NintendoWfc_NumberInput_UnusedState5(void) {
    return FALSE;
}

BOOL NintendoWfc_NumberInput_UnusedState6(void) {
    return FALSE;
}

BOOL NintendoWfc_NumberInput_StartFadeOut(NintendoWfcConnect *wfc) {
    BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 4, 1, HEAP_ID_67);
    wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_TEARDOWN;
    return FALSE;
}

BOOL NintendoWfc_NumberInput_Teardown(NintendoWfcConnect *wfc) {
    if (IsPaletteFadeFinished() == TRUE) {
        NintendoWfc_HideNumberInput(wfc);
        NintendoWfc_LoadSubScreenBg(wfc, 0);
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 4, 1, HEAP_ID_67);
        wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_WAIT_FADE_OUT;
    }
    return FALSE;
}

BOOL NintendoWfc_NumberInput_WaitButtonFlash(NintendoWfcConnect *wfc) {
    if (!NintendoWfc_UpdateButtonFlash(wfc)) {
        wfc->numberInput.state = wfc->numberInput.nextState;
    }
    return FALSE;
}

BOOL NintendoWfc_NumberInput_WaitFadeOut(NintendoWfcConnect *wfc) {
    if (IsPaletteFadeFinished() == TRUE) {
        wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_FINISH;
    }
    return FALSE;
}

BOOL NintendoWfc_NumberInput_Finish(void) {
    return TRUE;
}

static void NintendoWfc_AddNumberInputWindows(NintendoWfcConnect *wfc) {
    int i;
    int baseTile;
    const int *x = gNintendoWfcNumberInputWindowX;
    Window *window;
    i = 0;
    baseTile = 31;
    window = wfc->buttonWindows;
    for (; i < 3; baseTile += 64, x++, window++, i++) {
        AddWindowParameterized(wfc->bgConfig, window, GF_BG_LYR_SUB_0, *x, 21, 8, 2, 13, baseTile);
    }
    AddWindowParameterized(wfc->bgConfig, &wfc->numberInputWindow, GF_BG_LYR_SUB_0, 2, 19, 27, 4, 13, 79);
}

static void NintendoWfc_PrintButtonLabel(Window *window, MsgData *msgData, int msgNo) {
    String *string = NewString_ReadMsgData(msgData, msgNo);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 4, string, 0, 0, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(15, 2, 0), NULL);
    CopyWindowToVram(window);
    String_Delete(string);
}

static void NintendoWfc_RemoveNumberInputWindows(NintendoWfcConnect *wfc) {
    int i;
    Window *window = wfc->buttonWindows;
    for (i = 0; i < 3; i++) {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        window++;
    }
    RemoveWindow(&wfc->numberInputWindow);
}

static void NintendoWfc_HideNumberInput(NintendoWfcConnect *wfc) {
    int i;
    NintendoWfc_RemoveNumberInputWindows(wfc);
    Sprite_SetDrawFlag(wfc->sprites[0], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[1], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[2], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[3], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[4], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[5], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[6], FALSE);
    Sprite_SetDrawFlag(wfc->sprites[7], FALSE);
    for (i = 0; i < 3; i++) {
        Sprite_SetAnimCtrlSeq(wfc->sprites[NINTENDO_WFC_SPRITE_DIGIT_0 + i], 0);
    }
}

static void NintendoWfc_SetButtonFlashPltt(NintendoWfcConnect *wfc, u8 pltt) {
    NintendoWfcButtonFlash *flash = &wfc->buttonFlash;
    if (flash->isBgRect == 0) {
        Sprite_SetAnimCtrlSeq(wfc->sprites[flash->target], pltt);
    } else {
        BgTilemapRectChangePalette(wfc->bgConfig, flash->target, flash->x, flash->y, flash->width, flash->height, pltt);
        ScheduleBgTilemapBufferTransfer(wfc->bgConfig, flash->target);
    }
}

static BOOL NintendoWfc_UpdateButtonFlash(NintendoWfcConnect *wfc) {
    NintendoWfcButtonFlash *flash = &wfc->buttonFlash;
    switch (flash->state) {
    case 0:
        NintendoWfc_SetButtonFlashPltt(wfc, flash->pressedPltt);
        flash->state++;
        break;
    case 1:
        flash->timer++;
        if (flash->timer == 4) {
            NintendoWfc_SetButtonFlashPltt(wfc, flash->normalPltt);
            flash->timer = 0;
            flash->state++;
        }
        break;
    case 2:
        flash->timer++;
        if (flash->timer == 2) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

static void NintendoWfc_StartButtonFlash(NintendoWfcConnect *wfc, int x, int y, int nextState) {
    wfc->buttonFlash.isBgRect = TRUE;
    wfc->buttonFlash.timer = 0;
    wfc->buttonFlash.state = 0;
    wfc->buttonFlash.target = GF_BG_LYR_SUB_1;
    wfc->buttonFlash.pressedPltt = 1;
    wfc->buttonFlash.normalPltt = 0;
    wfc->buttonFlash.x = x;
    wfc->buttonFlash.y = y;
    wfc->buttonFlash.width = 6;
    wfc->buttonFlash.height = 6;
    wfc->numberInput.nextState = nextState;
    wfc->numberInput.state = NINTENDO_WFC_NUMBER_INPUT_WAIT_BUTTON_FLASH;
}

static void NintendoWfcYesNo_Init(NintendoWfcYesNoMenu *menu) {
    menu->state = NINTENDO_WFC_YES_NO_START;
    menu->choice = menu->initialChoice;
    NintendoWfcYesNo_LoadGraphics(menu);
    NintendoWfcYesNo_AddWindows(menu);
    NintendoWfcYesNo_ShowCursor(menu);
}

static int NintendoWfcYesNo_Run(NintendoWfcYesNoMenu *menu) {
    BOOL result = gNintendoWfcYesNoStates[menu->state](menu);
    if (result == TRUE) {
        return menu->choice + YESNORESPONSE_YES;
    }
    return YESNORESPONSE_WAIT;
}

BOOL NintendoWfcYesNo_Start(NintendoWfcYesNoMenu *menu) {
    menu->state = NINTENDO_WFC_YES_NO_HANDLE_INPUT;
    return FALSE;
}

BOOL NintendoWfcYesNo_HandleInput(NintendoWfcYesNoMenu *menu) {
    int hit = TouchscreenHitbox_FindRectAtTouchNew(gNintendoWfcYesNoHitboxes);
    if (hit != -1) {
        PlaySE(SEQ_SE_DP_SELECT);
        if (hit == 0) {
            menu->choice = 0;
            NintendoWfcYesNo_MoveCursor(menu, menu->choice);
            Sprite_SetAnimCtrlSeq(menu->cursorSprite, 3);
            menu->state = NINTENDO_WFC_YES_NO_WAIT_CLOSE;
        } else if (hit == 1) {
            menu->choice = 1;
            NintendoWfcYesNo_MoveCursor(menu, menu->choice);
            Sprite_SetAnimCtrlSeq(menu->cursorSprite, 3);
            menu->state = NINTENDO_WFC_YES_NO_WAIT_CLOSE;
        }
    } else {
        if (gSystem.newKeys & PAD_KEY_UP) {
            menu->choice = 0;
            NintendoWfcYesNo_MoveCursor(menu, menu->choice);
            PlaySE(SEQ_SE_DP_SELECT);
        } else if (gSystem.newKeys & PAD_KEY_DOWN) {
            menu->choice = 1;
            NintendoWfcYesNo_MoveCursor(menu, menu->choice);
            PlaySE(SEQ_SE_DP_SELECT);
        } else if (gSystem.newKeys & PAD_BUTTON_A) {
            Sprite_SetAnimCtrlSeq(menu->cursorSprite, 3);
            menu->state = NINTENDO_WFC_YES_NO_WAIT_CLOSE;
            PlaySE(SEQ_SE_DP_SELECT);
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            menu->choice = 1;
            NintendoWfcYesNo_MoveCursor(menu, menu->choice);
            menu->state = NINTENDO_WFC_YES_NO_WAIT_CLOSE;
            Sprite_SetAnimCtrlSeq(menu->cursorSprite, 3);
            PlaySE(SEQ_SE_DP_SELECT);
        }
    }
    return FALSE;
}

BOOL NintendoWfcYesNo_UnusedState2(void) {
    return FALSE;
}

BOOL NintendoWfcYesNo_WaitClose(NintendoWfcYesNoMenu *menu) {
    if (Sprite_IsAnimated(menu->cursorSprite)) {
        return FALSE;
    }
    ToggleBgLayer(menu->bgLayer, FALSE);
    ToggleBgLayer(menu->textBgLayer, FALSE);
    NintendoWfcYesNo_RemoveWindows(menu);
    Sprite_SetDrawFlag(menu->cursorSprite, FALSE);
    return TRUE;
}

static void NintendoWfcYesNo_LoadGraphics(NintendoWfcYesNoMenu *menu) {
    NARC *narc = NARC_New(NARC_a_2_3_7, menu->heapID);
    void *buffer;
    NNSG2dScreenData *screen;
    int i;
    u16 *src;
    u16 *dst;
    if (menu->bgLayer <= GF_BG_LYR_MAIN_3) {
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)(menu->bgPltt * 32), 32, menu->heapID);
        LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)(menu->fontPltt * 32), menu->heapID);
    } else {
        GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)(menu->bgPltt * 32), 32, menu->heapID);
        LoadFontPal0(GF_PAL_LOCATION_SUB_BG, (enum GFPalSlotOffset)(menu->fontPltt * 32), menu->heapID);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, menu->bgConfig, (GFBgLayer)menu->bgLayer, 0, 0, FALSE, menu->heapID);
    buffer = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 10, FALSE, &screen, menu->heapID);
    dst = GetBgTilemapBuffer(menu->bgConfig, menu->bgLayer);
    i = 0;
    src = (u16 *)screen->rawData;
    do {
        int tile = *src;
        int pltt = menu->bgPltt;
        i++;
        tile &= 0xFFF;
        *dst = (pltt << 12) | tile;
        src++;
        dst++;
    } while (i < 32 * 24);
    BgCommitTilemapBufferToVram(menu->bgConfig, menu->bgLayer);
    Heap_Free(buffer);
    NARC_Delete(narc);
    ToggleBgLayer(menu->bgLayer, TRUE);
    ToggleBgLayer(menu->textBgLayer, TRUE);
}

static void NintendoWfcYesNo_AddWindows(NintendoWfcYesNoMenu *menu) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0191_bin, menu->heapID);
    String *yes;
    String *no;

    AddWindowParameterized(menu->bgConfig, &menu->yesWindow, menu->textBgLayer, 12, 8, 8, 2, menu->fontPltt, menu->baseTile);
    FillWindowPixelBuffer(&menu->yesWindow, 0);
    AddWindowParameterized(menu->bgConfig, &menu->noWindow, menu->textBgLayer, 12, 14, 8, 2, menu->fontPltt, menu->baseTile + 16);
    FillWindowPixelBuffer(&menu->noWindow, 0);
    yes = NewString_ReadMsgData(msgData, msg_0191_00046);
    no = NewString_ReadMsgData(msgData, msg_0191_00047);
    AddTextPrinterParameterizedWithColor(&menu->yesWindow, 4, yes, 0, 0, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(15, 1, 0), NULL);
    AddTextPrinterParameterizedWithColor(&menu->noWindow, 4, no, 0, 0, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(15, 1, 0), NULL);
    CopyWindowToVram(&menu->yesWindow);
    CopyWindowToVram(&menu->noWindow);
    String_Delete(no);
    String_Delete(yes);
    DestroyMsgData(msgData);
}

static void NintendoWfcYesNo_RemoveWindows(NintendoWfcYesNoMenu *menu) {
    ClearWindowTilemapAndCopyToVram(&menu->noWindow);
    ClearWindowTilemapAndCopyToVram(&menu->yesWindow);
    RemoveWindow(&menu->noWindow);
    RemoveWindow(&menu->yesWindow);
}

static void NintendoWfcYesNo_ShowCursor(NintendoWfcYesNoMenu *menu) {
    Sprite_SetDrawFlag(menu->cursorSprite, TRUE);
    NintendoWfcYesNo_MoveCursor(menu, menu->initialChoice);
}

static void NintendoWfcYesNo_MoveCursor(NintendoWfcYesNoMenu *menu, int choice) {
    VecFx32 pos;
    pos.x = gNintendoWfcYesNoCursorPositions[choice].x << FX32_SHIFT;
    pos.y = (menu->cursorOffsetY + gNintendoWfcYesNoCursorPositions[choice].y) << FX32_SHIFT;
    pos.z = 0;
    Sprite_SetMatrix(menu->cursorSprite, &pos);
}
