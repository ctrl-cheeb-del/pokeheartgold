#ifndef POKEHEARTGOLD_NINTENDO_WFC_CONNECT_UNUSED_H
#define POKEHEARTGOLD_NINTENDO_WFC_CONNECT_UNUSED_H

#include <nitro.h>

#include <dwc/net_common_internal.h>

#include "global.h"

#include "frontier_data_access.h"
#include "frontier_wifi_upload_record.h"
#include "msgdata.h"
#include "nintendo_wfc_connect.h"
#include "nintendo_wfc_connect_internal.h"
#include "render_window.h"
#include "save_wii_message.h"
#include "sprite.h"
#include "yes_no_prompt.h"

enum NintendoWfcUnusedState {
    NINTENDO_WFC_UNUSED_STATE_ASK_CONNECT,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_CONNECT_CHOICE,
    NINTENDO_WFC_UNUSED_STATE_START_CONNECT,
    NINTENDO_WFC_UNUSED_STATE_WAIT_CONNECT,
    NINTENDO_WFC_UNUSED_STATE_START_AUTH,
    NINTENDO_WFC_UNUSED_STATE_WAIT_AUTH,
    NINTENDO_WFC_UNUSED_STATE_INIT_HTTP,
    NINTENDO_WFC_UNUSED_STATE_REQUEST_INFO,
    NINTENDO_WFC_UNUSED_STATE_WAIT_INFO,
    NINTENDO_WFC_UNUSED_STATE_REQUEST_SET_PROFILE,
    NINTENDO_WFC_UNUSED_STATE_WAIT_SET_PROFILE,
    NINTENDO_WFC_UNUSED_STATE_REQUEST_ROOM_COUNT,
    NINTENDO_WFC_UNUSED_STATE_WAIT_ROOM_COUNT,
    NINTENDO_WFC_UNUSED_STATE_ASK_CHALLENGE_ROOM,
    NINTENDO_WFC_UNUSED_STATE_START_CHALLENGE_ROOM_INPUT,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_CHALLENGE_ROOM_INPUT,
    NINTENDO_WFC_UNUSED_STATE_PRINT_RECEIVING_TRAINERS,
    NINTENDO_WFC_UNUSED_STATE_REQUEST_TRAINERS_DOWNLOAD,
    NINTENDO_WFC_UNUSED_STATE_WAIT_TRAINERS_DOWNLOAD,
    NINTENDO_WFC_UNUSED_STATE_PRINT_TRAINERS_RECEIVED,
    NINTENDO_WFC_UNUSED_STATE_PRINT_ROOM_UNAVAILABLE,
    NINTENDO_WFC_UNUSED_STATE_ASK_CANCEL_CHALLENGE,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_CANCEL_CHALLENGE_CHOICE,
    NINTENDO_WFC_UNUSED_STATE_ASK_CANCEL_DOWNLOAD,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_CANCEL_DOWNLOAD_CHOICE,
    NINTENDO_WFC_UNUSED_STATE_PRINT_SENDING_RECORD,
    NINTENDO_WFC_UNUSED_STATE_REQUEST_UPLOAD,
    NINTENDO_WFC_UNUSED_STATE_WAIT_UPLOAD,
    NINTENDO_WFC_UNUSED_STATE_PRINT_RECORD_SENT,
    NINTENDO_WFC_UNUSED_STATE_ASK_LEADERS_RANK,
    NINTENDO_WFC_UNUSED_STATE_START_LEADERS_RANK_INPUT,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_LEADERS_RANK_INPUT,
    NINTENDO_WFC_UNUSED_STATE_ASK_LEADERS_ROOM,
    NINTENDO_WFC_UNUSED_STATE_START_LEADERS_ROOM_INPUT,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_LEADERS_ROOM_INPUT,
    NINTENDO_WFC_UNUSED_STATE_PRINT_RECEIVING_LEADERS,
    NINTENDO_WFC_UNUSED_STATE_REQUEST_LEADERS_DOWNLOAD,
    NINTENDO_WFC_UNUSED_STATE_WAIT_LEADERS_DOWNLOAD,
    NINTENDO_WFC_UNUSED_STATE_PRINT_LEADERS_RECEIVED,
    NINTENDO_WFC_UNUSED_STATE_START_SAVE,
    NINTENDO_WFC_UNUSED_STATE_SAVE,
    NINTENDO_WFC_UNUSED_STATE_PRINT_DISCONNECTING,
    NINTENDO_WFC_UNUSED_STATE_CLOSE_CONNECTION,
    NINTENDO_WFC_UNUSED_STATE_PRINT_DISCONNECTED,
    NINTENDO_WFC_UNUSED_STATE_UNUSED_IDLE,
    NINTENDO_WFC_UNUSED_STATE_START_DISCONNECT,
    NINTENDO_WFC_UNUSED_STATE_START_EXIT,
    NINTENDO_WFC_UNUSED_STATE_WAIT_MESSAGE,
    NINTENDO_WFC_UNUSED_STATE_OPEN_YES_NO_PROMPT,
    NINTENDO_WFC_UNUSED_STATE_WAIT_MESSAGE_AND_DELAY,
    NINTENDO_WFC_UNUSED_STATE_UNUSED_HANDLE_YES_NO,
    NINTENDO_WFC_UNUSED_STATE_ASK_LOG_OUT,
    NINTENDO_WFC_UNUSED_STATE_HANDLE_LOG_OUT_CHOICE,
    NINTENDO_WFC_UNUSED_STATE_SHOW_HTTP_ERROR,
    NINTENDO_WFC_UNUSED_STATE_DISCONNECT,
    NINTENDO_WFC_UNUSED_STATE_SHOW_DWC_ERROR,
    NINTENDO_WFC_UNUSED_STATE_WAIT_ERROR_DISMISS,
};

typedef struct NintendoWfcUnused {
    NintendoWifiConnectArgs *args;
    BgConfig *bgConfig;
    u8 padding_0008[8];
    int mode; // index into sNintendoWfcUnusedModes
    int nextMode;
    int unk_0018;
    enum NintendoWfcUnusedState state; // index into sNintendoWfcUnusedStates
    enum NintendoWfcUnusedState nextState;
    void *heapMem;
    NNSFndHeapHandle expHeap;
    NetConnection connection;
    u32 ownRank;
    int rank;
    int roomCount;
    int room;
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
    SpriteResource *resObjs[4];
    u8 padding_0D44[0x20];
    SpriteResourcesHeader spriteHeader;
    u8 padding_0D88[0x48];
    Sprite *arrows[2]; // up/down arrows next to the number windows
    Window msgWindow;
    Window rankWindow;
    Window roomWindow;
    Window titleWindow;
    Window errorWindow;
    u8 padding_0E28[0xE4];
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
} NintendoWfcUnused;

typedef struct NintendoWfcUnusedGlobal {
    NintendoWfcUnused *wfc;
    NNSFndHeapHandle heap; // heap of the DWC allocator callbacks
} NintendoWfcUnusedGlobal;

typedef enum NintendoWfcMainState (*NintendoWfcUnusedModeFunc)(NintendoWfcUnused *wfc, int state);

// The session functions of each mode.
typedef struct NintendoWfcUnusedModeRow {
    NintendoWfcUnusedModeFunc init;
    NintendoWfcUnusedModeFunc main;
    NintendoWfcUnusedModeFunc exit;
} NintendoWfcUnusedModeRow;

extern const u16 gNintendoWfcUnusedArrowPositions[2][2];

void CommState_InitWfcSession(SaveData *saveData);
void CommState_FreeWfcSession(void);
void CommState_ShowRestartErrorAndHalt(void);
int RecordMixing_State_AbortLeave(int errorCode, int errorType);

enum NintendoWfcMainState NintendoWfcUnused_SessionInit(NintendoWfcUnused *wfc, int state);
enum NintendoWfcMainState NintendoWfcUnused_SessionMain(NintendoWfcUnused *wfc, int state);
enum NintendoWfcMainState NintendoWfcUnused_SessionExit(NintendoWfcUnused *wfc, int state);
enum NintendoWfcMainState NintendoWfcUnused_AskConnect(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleConnectChoice(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_AskLogOut(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleLogOutChoice(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartConnect(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitConnect(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartAuth(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitAuth(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_InitHttp(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_RequestInfo(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitInfo(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_RequestSetProfile(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitSetProfile(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_RequestRoomCount(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitRoomCount(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_AskChallengeRoom(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartChallengeRoomInput(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleChallengeRoomInput(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintReceivingTrainers(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintRoomUnavailable(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_RequestTrainersDownload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitTrainersDownload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintTrainersReceived(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintSendingRecord(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_RequestUpload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitUpload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintRecordSent(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_AskLeadersRank(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartLeadersRankInput(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleLeadersRankInput(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_AskLeadersRoom(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartLeadersRoomInput(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleLeadersRoomInput(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintReceivingLeaders(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_RequestLeadersDownload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitLeadersDownload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintLeadersReceived(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartDisconnect(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_AskCancelChallenge(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleCancelChallengeChoice(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_AskCancelDownload(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_HandleCancelDownloadChoice(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintDisconnecting(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_CloseConnection(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_PrintDisconnected(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_UnusedState_Idle(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_UnusedState_HandleYesNo(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartSave(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_Save(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_StartExit(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_ShowHttpError(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_Disconnect(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitMessage(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitMessageAndDelay(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_OpenYesNoPrompt(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_ShowDwcError(NintendoWfcUnused *wfc);
enum NintendoWfcMainState NintendoWfcUnused_WaitErrorDismiss(NintendoWfcUnused *wfc);

YesNoPrompt *NintendoWfcUnused_CreateYesNoPrompt(BgConfig *bgConfig, u8 y, int tileStart);
int NintendoWfcUnused_HandleYesNoPrompt(YesNoPrompt *prompt);
void NintendoWfcUnused_SetState(NintendoWfcUnused *wfc, enum NintendoWfcUnusedState state, enum NintendoWfcUnusedState nextState);
int NintendoWfcUnused_GetWifiIconLevel(NintendoWfcUnused *wfc);
void NintendoWfcUnused_SetNextMode(NintendoWfcUnused *wfc, int mode, int a2);

#endif // POKEHEARTGOLD_NINTENDO_WFC_CONNECT_UNUSED_H
