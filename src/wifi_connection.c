#include "wifi_connection.h"

#include "global.h"

#include "constants/comm_type.h"
#include "constants/dwc_status.h"

#include "dwc/dwc_account_internal.h"
#include "dwc/dwc_main_internal.h"
#include "dwc/net_common_internal.h"
#include "nnsys/fnd_internal.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_command.h"
#include "communication_core_internal.h"
#include "friend_roster.h"
#include "frontier_save_access.h"
#include "heap.h"
#include "voice_chat.h"
#include "wifi_connection_result.h"

enum WifiMatchType {
    WIFI_MATCH_TYPE_ANYBODY,
    WIFI_MATCH_TYPE_HOST,
    WIFI_MATCH_TYPE_CLIENT,
};

// 32-byte aligned inside a Heap_Alloc'd block (rawAlloc).
struct WifiConnection {
    u8 sendBuffer[0x100];   // 4-byte header + payload
    DwcAccData *friendList; // 32 entries
    DwcControl loginControl;
    DwcUserData *userData;
    NetConnection libConfig;
    SaveData *saveData;
    void *rawAlloc;
    void *recvBuffers[4];
    void *heapMemory;
    NNSFndHeapHandle heap;
    void *extraHeapMemory;
    NNSFndHeapHandle extraHeap;
    u32 extraHeapFreeSize;
    WifiReceiveCallback recvLocalCallback;
    WifiReceiveCallback recvCallback;
    void (*disconnectCallback)(int, void *);
    void *disconnectCallbackArg;
    void (*clientCallback)(int, void *);
    void *clientCallbackArg;
    BOOL (*connectFilterCallback)(int);
    void (*errorCallback)(int);
    char matchFilter[0x80];
    u8 friendStatus[32];
    u8 *friendStatusData;
    int friendStatusStride;
    int friendStatusIndex;
    int state;
    enum WifiMatchType matchType;
    int sendBusy;
    int maxPlayers;
    int conferenceAidMask;
    int heapId;
    int heapId2;
    u32 heapSize;
    int voiceChatActive;
    int targetFriendIndex;
    int newClientIndex;
    int voiceChatEnabled;
    int matchInProgress;
    int voiceChatMode;
    int recvTimeoutArmed;
    int keepAliveTimers[8];
    int retryCount;
    int peerVoiceFlag;
    u16 ownVoiceFlag;
    u16 voiceUnmuted;
    int matchedAidBitmap;
    u8 sendSequence;
    u8 recvSequence;
    u8 forceError;
    u8 unk_10DF;
    u8 stopMatchingState;
    u8 recvBufferFromGameHeap[4];
    u8 disconnectWhenAlone;
    u8 friendDataChanged;
    u8 padding_10E7[0x1108 - 0x10E7];
};

static WifiConnection *sWifiConnection;

extern int sprintf(char *dest, const char *format, ...);

extern int DWC_IsSendableReliable(u8);
extern u32 DWC_SendReliableBitmap(u32, void *, u32);
extern void DWC_SetRecvBuffer(u8, void *, int);
extern int DWC_SetRecvTimeoutTime(u8, int);
extern void DWC_SetUserSendCallback(void (*)(u32, s32));
extern void DWC_SetUserRecvCallback(void (*)(u16, const u8 *, int));
extern void DWC_SetUserRecvTimeoutCallback(void (*)(void));

static void WifiConnection_Destroy(void);
static void WifiConnection_FinishCancel(void);
static void WifiConnection_LoginCallback(int result, int unused, void *param);
static void WifiConnection_TimeoutCallback(void);
static void WifiConnection_UpdateServersCallback(int result, int unused, void *param);
static void WifiConnection_FriendStatusCallback(void);
static void WifiConnection_DeleteFriendCallback(int index, int srcIndex);
static void WifiConnection_BuddyFriendCallback(void);
static void WifiConnection_ResetKeepAliveTimers(void);
static void WifiConnection_SetRecvTimeouts(void);
static void WifiConnection_OnConnected(int aid);
static void WifiConnection_AnybodyMatchedCallback(int result, int cancelled, void *param);
static BOOL WifiConnection_EvalPlayerCallback(void);
static void WifiConnection_SendDoneCallback(u32 result, s32 aid);
static void WifiConnection_ReadPeerVoiceFlag(u32 header);
static void WifiConnection_ReceiveCallback(u16 aid, const u8 *data, int size);
static void WifiConnection_ConnectionClosedCallback(int result, BOOL isLocal, BOOL isServer, u32 aid, int index, void *param);
static void *WifiConnection_Alloc(int unused, u32 size, int alignment);
static void WifiConnection_Free(int unused, void *ptr, u32 size);
static int WifiConnection_CanSendToAll(void);
static int WifiConnection_SendKeepAlive(int aid);
static int WifiConnection_UpdateConnected(void);
static void WifiConnection_ClearVoiceChatActive(void);
static void WifiConnection_UpdateFriendStatus(void);
static void WifiConnection_GameServerMatchedCallback(int result, BOOL cancelled, BOOL self, BOOL isServer, int aid, void *param);
static void WifiConnection_ConnectedToServerCallback(int result, BOOL cancelled, BOOL self, BOOL isServer, int aid, void *param);
static void WifiConnection_NewClientCallback(int index);
static void WifiConnection_CreateTokenAndScanFriends(void);
static void WifiConnection_StopServerMatchingCallback(void *param);
static void WifiConnection_FreeRecvBuffer(int aid);
static void WifiConnection_AllocRecvBuffer(int aid);
static void WifiConnection_FreeRecvBuffers(void);

static const DwcMatchOptMinComplete sWifiConnectionAnybodyMatchParams = {
    .valid = 1,
    .minEntry = 2,
    .retry = 0,
    .pad = 0,
    .timeout = 0,
};

static const char sWifiConnectionMatchFilterFormat[] = "%s = '%s'";

int WifiConnection_Init(SaveData *saveData, int heapId, u32 heapSize, int maxPlayers) {
    u8 *raw;
    int i;

    GF_ASSERT(sWifiConnection == NULL);
    raw = Heap_Alloc((enum HeapID)heapId, sizeof(WifiConnection));
    MI_CpuFill8(raw, 0, sizeof(WifiConnection));
    sWifiConnection = (WifiConnection *)(((u32)raw + 31) & ~31);
    sWifiConnection->rawAlloc = raw;
    sWifiConnection->saveData = saveData;
    sWifiConnection->recvLocalCallback = NULL;
    sWifiConnection->recvCallback = NULL;
    sWifiConnection->errorCallback = NULL;
    sWifiConnection->state = WIFI_CONNECTION_STATE_INIT;
    sWifiConnection->heapId = heapId;
    sWifiConnection->heapId2 = heapId;
    sWifiConnection->heapSize = heapSize;
    sWifiConnection->heapMemory = Heap_Alloc((enum HeapID)heapId, heapSize + 0x3020);
    sWifiConnection->extraHeapMemory = NULL;
    sWifiConnection->heap = NNS_FndCreateExpHeapEx((void *)(((u32)sWifiConnection->heapMemory + 31) & ~31), heapSize, 0);
    sWifiConnection->extraHeap = NULL;
    sWifiConnection->voiceChatMode = 0;
    sWifiConnection->targetFriendIndex = -1;
    sWifiConnection->friendStatusIndex = 0;
    sWifiConnection->maxPlayers = maxPlayers;
    sWifiConnection->conferenceAidMask = 0;
    sWifiConnection->matchedAidBitmap = 0;
    sWifiConnection->newClientIndex = -1;
    sWifiConnection->voiceChatEnabled = 1;
    sWifiConnection->forceError = 0;
    sWifiConnection->retryCount = 0;
    sWifiConnection->sendSequence = 0;
    sWifiConnection->recvSequence = 0;
    sWifiConnection->ownVoiceFlag = 1;
    sWifiConnection->peerVoiceFlag = 1;
    sWifiConnection->voiceUnmuted = 1;
    if (saveData != NULL) {
        sWifiConnection->userData = FriendRoster_GetUserData(Save_FriendRoster_Get(sWifiConnection->saveData));
        sWifiConnection->friendList = FriendRoster_GetDwcFriendData(Save_FriendRoster_Get(sWifiConnection->saveData), 0);
    }
    sWifiConnection->disconnectWhenAlone = 1;
    sWifiConnection->friendStatusData = NULL;
    for (i = 0; i < 32; i++) {
        sWifiConnection->friendStatus[i] = DWC_STATUS_OFFLINE;
    }
    WifiConnection_CreateTokenAndScanFriends();
    if (!DWC_CheckHasProfile(sWifiConnection->userData)) {
        return 1;
    }
    if (DWC_CheckValidConsole(sWifiConnection->userData)) {
        return 0;
    }
    return 2;
}

static void WifiConnection_Destroy(void) {
    if (sWifiConnection != NULL) {
        WifiConnection_FreeRecvBuffers();
        if (sWifiConnection->extraHeapMemory != NULL) {
            NNS_FndDestroyExpHeap(sWifiConnection->extraHeap);
            Heap_Free(sWifiConnection->extraHeapMemory);
            sWifiConnection->extraHeapMemory = NULL;
        }
        NNS_FndDestroyExpHeap(sWifiConnection->heap);
        Heap_FreeExplicit((enum HeapID)sWifiConnection->heapId, sWifiConnection->heapMemory);
        Heap_FreeExplicit((enum HeapID)sWifiConnection->heapId, sWifiConnection->rawAlloc);
        sWifiConnection = NULL;
    }
    DWC_ClearError();
}

int WifiConnection_UpdateLogin(void) {
    OSOwnerInfo owner;
    int err;

    switch ((u32)sWifiConnection->state) {
    case WIFI_CONNECTION_STATE_INIT:
        DWC_SetMemFunc(WifiConnection_Alloc, WifiConnection_Free);
        DWC_InitInetEx(&sWifiConnection->libConfig, 2, 1, 20);
        DWC_SetAuthServer(2);
        DWC_ConnectInetAsync();
        sWifiConnection->state = WIFI_CONNECTION_STATE_WAIT_LINK;
        sWifiConnection->voiceChatActive = 0;
    case WIFI_CONNECTION_STATE_WAIT_LINK:
        if (DWC_CheckInet()) {
            if (DWC_GetInetStatus() == DWC_CONNECTINET_STATE_CONNECTED) {
                sWifiConnection->state = WIFI_CONNECTION_STATE_LOGIN;
            } else {
                sWifiConnection->state = WIFI_CONNECTION_STATE_ERROR;
            }
        } else {
            DWC_ProcessInet();
            break;
        }
    case WIFI_CONNECTION_STATE_LOGIN:
        err = WifiConnection_CheckError();
        if (err) {
            return err;
        }
        DWC_InitFriendsMatch(&sWifiConnection->loginControl, sWifiConnection->userData, 0x29E7, "pokemondpds", "1vTlwb", 0, 0, sWifiConnection->friendList, 32);
        OS_GetOwnerInfo(&owner);
        DWC_LoginAsync(owner.nickName, 0, WifiConnection_LoginCallback, NULL);
        sWifiConnection->state = WIFI_CONNECTION_STATE_LOGGING_IN;
    case WIFI_CONNECTION_STATE_LOGGING_IN:
        DWC_ProcessFriendsMatch();
        break;
    case WIFI_CONNECTION_STATE_LOGGED_IN:
        DWC_ProcessFriendsMatch();
        return WIFI_CONNECTION_RESULT_LOGGED_IN;
    }
    return WifiConnection_CheckError();
}

void WifiConnection_SetReceiveCallbacks(WifiReceiveCallback recvLocal, WifiReceiveCallback recv) {
    sWifiConnection->recvLocalCallback = recvLocal;
    sWifiConnection->recvCallback = recv;
}

void WifiConnection_SetDisconnectCallback(void (*callback)(int, void *), void *arg) {
    sWifiConnection->disconnectCallback = callback;
    sWifiConnection->disconnectCallbackArg = arg;
}

void WifiConnection_SetConnectFilterCallback(BOOL (*callback)(int)) {
    sWifiConnection->connectFilterCallback = callback;
}

void WifiConnection_SetClientCallback(void (*callback)(int, void *), void *arg) {
    sWifiConnection->clientCallback = callback;
    sWifiConnection->clientCallbackArg = arg;
}

int WifiConnection_StartAnybodyMatchmaking(const char *name, int maxPlayers, int filterLocal, int timeoutSeconds) {
    DwcMatchOptMinComplete params;

    GF_ASSERT(sWifiConnection);
    if (sWifiConnection->state != WIFI_CONNECTION_STATE_LOGGED_IN) {
        return 0;
    }
    WifiConnection_FreeRecvBuffers();
    params = sWifiConnectionAnybodyMatchParams;
    params.timeout = 1000 * timeoutSeconds;
    GF_ASSERT(DWC_SetMatchingOption(0, &params, sizeof(params)) == 0);
    GF_ASSERT(DWC_AddMatchKeyString(0, "ppw_lobby", name) != 0);
    MI_CpuFill8(sWifiConnection->matchFilter, 0, 128);
    sprintf(sWifiConnection->matchFilter, sWifiConnectionMatchFilterFormat, "ppw_lobby", name);
    GF_ASSERT(strlen(sWifiConnection->matchFilter) < 128);
    if (filterLocal) {
        DWC_AddMatchKeyString(1, sWifiConnection->matchFilter, sWifiConnection->matchFilter);
    }
    sWifiConnection->state = WIFI_CONNECTION_STATE_MATCHING;
    sWifiConnection->maxPlayers = maxPlayers;
    DWC_ConnectToAnybodyAsync((u8)maxPlayers, sWifiConnection->matchFilter, WifiConnection_AnybodyMatchedCallback, 0, WifiConnection_EvalPlayerCallback, 0);
    sWifiConnection->matchType = WIFI_MATCH_TYPE_ANYBODY;
    DWC_SetUserSendCallback(WifiConnection_SendDoneCallback);
    DWC_SetUserRecvCallback(WifiConnection_ReceiveCallback);
    DWC_SetConnectionClosedCallback(WifiConnection_ConnectionClosedCallback, NULL);
    DWC_SetUserRecvTimeoutCallback(WifiConnection_TimeoutCallback);
    sWifiConnection->sendBusy = 0;
    sWifiConnection->disconnectWhenAlone = 1;
    return 1;
}

static void WifiConnection_FinishCancel(void) {
    if (sWifiConnection->state == WIFI_CONNECTION_STATE_CANCEL_REQUESTED) {
        sWifiConnection->state = WIFI_CONNECTION_STATE_CANCELLED_BY_PEER;
    } else {
        sWifiConnection->state = WIFI_CONNECTION_STATE_CANCELLED;
    }
}

int WifiConnection_Update(int success) {
    switch (sWifiConnection->state) {
    case WIFI_CONNECTION_STATE_MATCHING:
        if (success) {
            sWifiConnection->state = WIFI_CONNECTION_STATE_MATCHED;
        }
        if (sWifiConnection->matchType == WIFI_MATCH_TYPE_CLIENT && sWifiConnection->targetFriendIndex >= 0 && sWifiConnection->friendStatus[sWifiConnection->targetFriendIndex] != DWC_STATUS_MATCH_SC_SV) {
            sWifiConnection->state = WIFI_CONNECTION_STATE_CANCEL_REQUESTED;
        }
        break;
    case WIFI_CONNECTION_STATE_MATCHED:
    case WIFI_CONNECTION_STATE_CANCEL_REQUESTED:
        if (!sWifiConnection->matchType) {
            DWC_CancelMatching();
        } else {
            DWC_CloseAllConnectionsHard();
            WifiConnection_FinishCancel();
        }
        break;
    case WIFI_CONNECTION_STATE_CONNECTED:
        if (!Comm_IsWifiPeerLinkMode(CommState_GetLinkMode())) {
            WifiConnection_StartVoiceChat(sWifiConnection->heapId);
        }
        {
            WifiConnection *connection = sWifiConnection;
            if (connection->voiceChatEnabled) {
                connection->ownVoiceFlag = 1;
            } else {
                connection->ownVoiceFlag = 0;
            }
        }
        sWifiConnection->state = WIFI_CONNECTION_STATE_CONNECTED_VOICE;
        return WIFI_CONNECTION_RESULT_CONNECTED;
    case WIFI_CONNECTION_STATE_CANCELLED:
        sWifiConnection->state = WIFI_CONNECTION_STATE_LOGGED_IN;
        sWifiConnection->sendBusy = 0;
        sWifiConnection->newClientIndex = -1;
        return WIFI_CONNECTION_RESULT_CANCELLED;
    case WIFI_CONNECTION_STATE_CANCELLED_BY_PEER:
        sWifiConnection->state = WIFI_CONNECTION_STATE_LOGGED_IN;
        sWifiConnection->sendBusy = 0;
        sWifiConnection->newClientIndex = -1;
        return WIFI_CONNECTION_RESULT_CANCELLED_BY_PEER;
    case WIFI_CONNECTION_STATE_ERROR:
        return WifiConnection_CheckError();
    case WIFI_CONNECTION_STATE_DISCONNECTING:
        if (!sWifiConnection->voiceChatActive) {
            DWC_CloseAllConnectionsHard();
            sWifiConnection->state = WIFI_CONNECTION_STATE_DISCONNECTED;
        }
        break;
    }
    return WifiConnection_UpdateConnected();
}

int WifiConnection_SendToHost(void *data, int size) {
    if (size >= 0x100) {
        return 0;
    }
    if (DWC_GetMyAID() == 0) {
        if (sWifiConnection->recvLocalCallback != NULL) {
            sWifiConnection->recvLocalCallback(0, data, size);
        }
        return 1;
    }
    if (sWifiConnection->sendBusy != 0 || !WifiConnection_CanSendToAll()) {
        return 0;
    }
    *(u32 *)sWifiConnection->sendBuffer = 1 | ((u32)sWifiConnection->ownVoiceFlag << 8);
    sWifiConnection->sendSequence++;
    sWifiConnection->sendBuffer[2] = sWifiConnection->sendSequence;
    MI_CpuCopy8(data, sWifiConnection->sendBuffer + 4, size);
    sWifiConnection->sendBusy = 1;
    DWC_SendReliableBitmap(1, sWifiConnection, size + 4);
    return 1;
}

int WifiConnection_SendFromHost(void *data, int size) {
    if (size >= 0x100) {
        return 0;
    }
    if (DWC_GetMyAID() != 0) {
        return 0;
    }
    if (sWifiConnection->sendBusy != 0 || !WifiConnection_CanSendToAll()) {
        return 0;
    }
    *(u32 *)sWifiConnection->sendBuffer = 1 | ((u32)sWifiConnection->ownVoiceFlag << 8);
    sWifiConnection->sendSequence++;
    sWifiConnection->sendBuffer[2] = sWifiConnection->sendSequence;
    MI_CpuCopy8(data, sWifiConnection->sendBuffer + 4, size);
    sWifiConnection->sendBusy = 1;
    if (DWC_SendReliableBitmap(DWC_GetAIDBitmap(), sWifiConnection, size + 4) == 0) {
        sWifiConnection->sendBusy = 0;
        return 0;
    }
    if (sWifiConnection->recvCallback != NULL) {
        sWifiConnection->recvCallback(0, data, size);
    }
    return 1;
}

int WifiConnection_SendToAll(void *data, int size) {
    u16 aidMask;
    if (size >= 0x100) {
        return 0;
    }
    if (sWifiConnection->sendBusy != 0 || !WifiConnection_CanSendToAll()) {
        return 0;
    }
    *(u32 *)sWifiConnection->sendBuffer = 1 | ((u32)sWifiConnection->ownVoiceFlag << 8);
    sWifiConnection->sendSequence++;
    sWifiConnection->sendBuffer[2] = sWifiConnection->sendSequence;
    MI_CpuCopy8(data, sWifiConnection->sendBuffer + 4, size);
    sWifiConnection->sendBusy = 1;
    aidMask = DWC_GetAIDBitmap();
    if (DWC_SendReliableBitmap(aidMask, sWifiConnection, size + 4) != aidMask) {
        sWifiConnection->sendBusy = 0;
        return 0;
    }
    if (sWifiConnection->recvCallback != NULL) {
        sWifiConnection->recvCallback(DWC_GetMyAID(), data, size);
    }
    return 1;
}

static void WifiConnection_LoginCallback(int result, int unused, void *param) {
    if (DWC_CheckDirtyFlag(sWifiConnection->userData)) {
        DWC_ClearDirtyFlag(sWifiConnection->userData);
        sWifiConnection->friendDataChanged = 1;
    }
    if (result == 0) {
        if (DWC_UpdateServersAsync(0, WifiConnection_UpdateServersCallback, sWifiConnection->userData, WifiConnection_FriendStatusCallback, param, WifiConnection_DeleteFriendCallback, param) == 0) {
            CommState_SetError(1);
            return;
        }
        DWC_SetBuddyFriendCallback(WifiConnection_BuddyFriendCallback, 0);
        return;
    }
    sWifiConnection->state = WIFI_CONNECTION_STATE_ERROR;
}

static void WifiConnection_TimeoutCallback(void) {
    if (sWifiConnection->recvTimeoutArmed != 0) {
        DWC_CloseAllConnectionsHard();
        sWifiConnection->newClientIndex = -1;
        sWifiConnection->state = WIFI_CONNECTION_STATE_TIMED_OUT;
    }
}

static void WifiConnection_UpdateServersCallback(int result, int unused, void *param) {
    if (result == 0) {
        sWifiConnection->state = WIFI_CONNECTION_STATE_LOGGED_IN;
    } else {
        sWifiConnection->state = WIFI_CONNECTION_STATE_ERROR;
    }
}

static void WifiConnection_FriendStatusCallback(void) {
}

static void WifiConnection_DeleteFriendCallback(int index, int srcIndex) {
    FriendRoster_MergeFriend(Save_FriendRoster_Get(sWifiConnection->saveData), index, srcIndex);
    FrontierSave_ClearRow(Save_Frontier_GetStatic(sWifiConnection->saveData), index, srcIndex);
}

static void WifiConnection_BuddyFriendCallback(void) {
}

static void WifiConnection_ResetKeepAliveTimers(void) {
    MI_CpuFill8(sWifiConnection->keepAliveTimers, 0, sizeof(sWifiConnection->keepAliveTimers));
}

static void WifiConnection_SetRecvTimeouts(void) {
    int i;
    for (i = 0; i < 4; i++) {
        DWC_SetRecvTimeoutTime(i, 0);
    }
    if (DWC_GetMyAID() == 0) {
        for (i = 0; i < sWifiConnection->maxPlayers; i++) {
            if (i != DWC_GetMyAID() && (DWC_GetAIDBitmap() & (1 << i))) {
                if (!DWC_SetRecvTimeoutTime(i, 10000)) {
                    GF_ASSERT(FALSE);
                }
            }
        }
    } else {
        if (!DWC_SetRecvTimeoutTime(0, 10000)) {
            GF_ASSERT(FALSE);
        }
    }
    sWifiConnection->recvTimeoutArmed = 1;
    WifiConnection_ResetKeepAliveTimers();
}

static void WifiConnection_OnConnected(int aid) {
    int i;
    sWifiConnection->state = WIFI_CONNECTION_STATE_CONNECTED;
    for (i = 0; i < sWifiConnection->maxPlayers; i++) {
        if (i != DWC_GetMyAID()) {
            WifiConnection_AllocRecvBuffer(i);
        }
    }
    WifiConnection_SetRecvTimeouts();
}

static void WifiConnection_AnybodyMatchedCallback(int result, int cancelled, void *param) {
    WifiConnection *connection;
    if (result == 0) {
        if (cancelled == 0) {
            WifiConnection_OnConnected(1 - DWC_GetMyAID());
        } else {
            WifiConnection_FinishCancel();
        }
    } else {
        sWifiConnection->state = WIFI_CONNECTION_STATE_ERROR;
    }
    connection = sWifiConnection;
    if (connection->clientCallback) {
        int aid = DWC_GetMyAID();
        sWifiConnection->clientCallback(aid, connection->clientCallbackArg);
    }
}

static BOOL WifiConnection_EvalPlayerCallback(void) {
    return TRUE;
}

static void WifiConnection_SendDoneCallback(u32 result, s32 aid) {
    sWifiConnection->sendBusy = 0;
    sWifiConnection->keepAliveTimers[aid] = 0;
}

static void WifiConnection_ReadPeerVoiceFlag(u32 header) {
    if (!Comm_IsWifiPeerLinkMode(CommState_GetLinkMode())) {
        if (header & 0x100) {
            sWifiConnection->peerVoiceFlag = 1;
        } else {
            sWifiConnection->peerVoiceFlag = 0;
        }
    }
}

static void WifiConnection_ReceiveCallback(u16 aid, const u8 *data, int size) {
    void *buf;
    u32 header;

    header = data[0] | ((data[1] << 8) | ((data[3] << 24) | (data[2] << 16)));
    sWifiConnection->recvTimeoutArmed = 1;
    if ((u8)header == 1) {
        WifiConnection_ReadPeerVoiceFlag(header);
        sWifiConnection->recvSequence = data[2];
    } else {
        if (!VoiceChat_ReceiveData(aid, (void *)data, size)) {
            WifiConnection_ReadPeerVoiceFlag(header);
        }
        return;
    }
    size -= 4;
    buf = WifiConnection_Alloc(0, size, 4);
    if (buf != NULL) {
        MI_CpuCopy8(data + 4, buf, size);
        if (DWC_GetMyAID() == 0) {
            if (sWifiConnection->recvLocalCallback != NULL) {
                sWifiConnection->recvLocalCallback(aid, buf, size);
            }
        } else {
            if (sWifiConnection->recvCallback != NULL) {
                sWifiConnection->recvCallback(aid, buf, size);
            }
        }
        WifiConnection_Free(0, buf, size);
    }
}

static void WifiConnection_ConnectionClosedCallback(int result, BOOL isLocal, BOOL isServer, u32 aid, int index, void *param) {
    sWifiConnection->sendBusy = 0;
    sWifiConnection->retryCount = 0;
    sWifiConnection->matchInProgress = 0;
    if (result == 0 && sWifiConnection->disconnectWhenAlone == 1 && DWC_GetNumConnectionHost() == 1) {
        if (sWifiConnection->state != WIFI_CONNECTION_STATE_MATCHED) {
            sWifiConnection->state = WIFI_CONNECTION_STATE_DISCONNECTING;
        }
        if (sWifiConnection->voiceChatActive != 0) {
            WifiConnection_StopVoiceChat();
        }
    }
    if (sWifiConnection->disconnectCallback != NULL) {
        sWifiConnection->disconnectCallback(aid, sWifiConnection->disconnectCallbackArg);
    }
}

static void *WifiConnection_Alloc(int unused, u32 size, int alignment) {
    OSIntrMode intr = OS_DisableInterrupts();
    void *result = NNS_FndAllocFromExpHeapEx(sWifiConnection->heap, size, alignment);
    if (result == NULL && sWifiConnection->extraHeapMemory != NULL) {
        result = NNS_FndAllocFromExpHeapEx(sWifiConnection->extraHeap, size, alignment);
    }
    if (result == NULL) {
        CommState_SetError(1);
        OS_RestoreInterrupts(intr);
        return NULL;
    }
    OS_RestoreInterrupts(intr);
    return result;
}

static void WifiConnection_Free(int unused, void *ptr, u32 size) {
    if (ptr != NULL) {
        OSIntrMode intr = OS_DisableInterrupts();
        if (NNS_FndGetGroupIDForMBlockExpHeap(ptr) == 0x10) {
            if (sWifiConnection->extraHeapMemory == NULL) {
                CommState_SetError(1);
                return;
            }
            NNS_FndFreeToExpHeap(sWifiConnection->extraHeap, ptr);
        } else {
            NNS_FndFreeToExpHeap(sWifiConnection->heap, ptr);
        }
        OS_RestoreInterrupts(intr);
    }
}

int WifiConnection_CheckError(void) {
    int error;
    u32 type;
    int status;
    int result = 0;

    status = DWC_GetLastErrorEx(&error, &type);
    if (status) {
        result = error;
        if (error == 0 || type == 1) {
            result = status;
        }
        switch (type) {
        case 1:
            DWC_ClearError();
            break;
        case 2:
            DWC_ClearError();
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            if (sWifiConnection) {
                switch ((u32)sWifiConnection->state) {
                case WIFI_CONNECTION_STATE_LOGGING_IN:
                case WIFI_CONNECTION_STATE_LOGGED_IN:
                case WIFI_CONNECTION_STATE_MATCHING:
                case WIFI_CONNECTION_STATE_MATCHED:
                case WIFI_CONNECTION_STATE_CONNECTED:
                case WIFI_CONNECTION_STATE_CONNECTED_VOICE:
                case WIFI_CONNECTION_STATE_CANCELLED:
                case WIFI_CONNECTION_STATE_ERROR:
                case WIFI_CONNECTION_STATE_DISCONNECTING:
                case WIFI_CONNECTION_STATE_DISCONNECTED:
                case WIFI_CONNECTION_STATE_TIMED_OUT:
                    DWC_ShutdownFriendsMatch();
                case WIFI_CONNECTION_STATE_INIT:
                case WIFI_CONNECTION_STATE_WAIT_LINK:
                case WIFI_CONNECTION_STATE_LOGIN:
                    if (CommState_GetLinkMode() != COMM_TYPE_WIFI_PLAZA) {
                        DWC_CleanupInet();
                    }
                    break;
                }
                DWC_ClearError();
            }
            if (sWifiConnection) {
                sWifiConnection->state = WIFI_CONNECTION_STATE_FATAL_ERROR;
            }
            break;
        case 7:
            if (sWifiConnection) {
                sWifiConnection->state = WIFI_CONNECTION_STATE_ERROR_CALLBACK;
                if (sWifiConnection->errorCallback) {
                    sWifiConnection->errorCallback(-error);
                }
            }
            break;
        }
    }
    if (sWifiConnection->forceError) {
        result = WIFI_CONNECTION_RESULT_FORCED_ERROR;
    }
    if (status) {
        CommState_SetWifiError(error, type, status);
    }
    return result;
}

static int WifiConnection_CanSendToAll(void) {
    int i;
    int found = 0;
    i = found;
    if (sWifiConnection->maxPlayers > 0) {
        do {
            if (i != DWC_GetMyAID() && DWC_IsValidAID((u8)i)) {
                found = 1;
                if (!DWC_IsSendableReliable(i)) {
                    return 0;
                }
            }
            i++;
        } while (i < sWifiConnection->maxPlayers);
    }
    return found;
}

static int WifiConnection_SendKeepAlive(int aid) {
    if (sWifiConnection->sendBusy == 0 && WifiConnection_CanSendToAll()) {
        u32 mask = DWC_GetAIDBitmap();
        if ((mask & 0xFFFE) != 0) {
            sWifiConnection->sendBusy = 1;
            *(u32 *)sWifiConnection->sendBuffer = 2 | ((u32)sWifiConnection->ownVoiceFlag << 8);
            DWC_SendReliableBitmap(DWC_GetAIDBitmap(), sWifiConnection, 4);
            sWifiConnection->keepAliveTimers[aid] = 0;
            return 1;
        }
    }
    return 0;
}

static int WifiConnection_UpdateConnected(void) {
    s32 state;

    DWC_ProcessFriendsMatch();
    WifiConnection_UpdateFriendStatus();
    if (sWifiConnection->voiceChatActive) {
        if (sWifiConnection->ownVoiceFlag == 1 && sWifiConnection->peerVoiceFlag == 1 && sWifiConnection->voiceUnmuted == 1) {
            VoiceChat_Unmute();
        } else {
            VoiceChat_Mute();
        }
        VoiceChat_Update();
        {
            WifiConnection *connection = sWifiConnection;
            if (connection->conferenceAidMask != DWC_GetAIDBitmap() && !connection->unk_10DF && connection->voiceChatEnabled) {
                s32 aidMask = DWC_GetAIDBitmap();
                s32 ownAid = DWC_GetMyAID();
                if (VoiceChat_AddConferenceClients(aidMask, ownAid)) {
                    sWifiConnection->conferenceAidMask = DWC_GetAIDBitmap();
                }
            }
        }
    }
    state = sWifiConnection->state;
    if (state == WIFI_CONNECTION_STATE_TIMED_OUT) {
        s32 result = WifiConnection_CheckError();
        if (!result) {
            return WIFI_CONNECTION_RESULT_TIMED_OUT;
        }
        return result;
    }
    if (state == WIFI_CONNECTION_STATE_DISCONNECTED) {
        return WIFI_CONNECTION_RESULT_DISCONNECTED;
    }
    if ((u32)state - WIFI_CONNECTION_STATE_CONNECTED <= 1) {
        s32 i;
        for (i = 0; i < sWifiConnection->maxPlayers; i++) {
            if (sWifiConnection->keepAliveTimers[i]++ >= 120 && !sWifiConnection->sendBusy && WifiConnection_SendKeepAlive(i)) {
                WifiConnection_ResetKeepAliveTimers();
                break;
            }
        }
    }
    return WifiConnection_CheckError();
}

int WifiConnection_GetAid(void) {
    if (sWifiConnection != NULL && (sWifiConnection->state == WIFI_CONNECTION_STATE_CONNECTED || sWifiConnection->state == WIFI_CONNECTION_STATE_CONNECTED_VOICE || sWifiConnection->state == WIFI_CONNECTION_STATE_DISCONNECTING)) {
        return DWC_GetMyAID();
    }
    return -1;
}

static void WifiConnection_ClearVoiceChatActive(void) {
    sWifiConnection->voiceChatActive = 0;
}

void WifiConnection_StartVoiceChat(int heapId) {
    int count = 1;
    BOOL online;
    int codec;

    online = Comm_IsWifiPeerLinkMode(CommState_GetLinkMode());
    if (online) {
        count = Comm_CountConnected() - 1;
        if (count < 1) {
            count = 1;
        }
        sWifiConnection->ownVoiceFlag = 1;
        sWifiConnection->peerVoiceFlag = 1;
        sWifiConnection->voiceUnmuted = 1;
    }
    if (sWifiConnection->voiceChatActive == 0) {
        switch (sWifiConnection->voiceChatMode) {
        case 2:
            codec = 1;
            break;
        case 3:
            codec = 2;
            break;
        case 4:
            codec = 3;
            break;
        case 5:
            codec = 4;
            break;
        case 0:
        case 1:
        default:
            if (online == 0) {
                codec = 4;
            } else {
                codec = 3;
            }
            break;
        }
        VoiceChat_Init(heapId, codec, count);
        VoiceChat_SetEndCallback(WifiConnection_ClearVoiceChatActive);
        sWifiConnection->voiceChatActive = 1;
    }
}

void WifiConnection_StopVoiceChat(void) {
    VoiceChat_Shutdown();
    if (sWifiConnection != NULL) {
        sWifiConnection->voiceChatActive = 0;
        sWifiConnection->conferenceAidMask = 0;
    }
}

int WifiConnection_ClassifyErrorCode(int errorCode, u32 context) {
    s32 hundreds = errorCode / 100;
    s32 thousands = errorCode / 1000;

    if (errorCode == 20101) {
        return 1;
    }
    if (thousands == 23) {
        return 1;
    }
    if (errorCode == 20108) {
        return 2;
    }
    if (errorCode == 20110) {
        return 3;
    }
    if (hundreds == 512) {
        return 4;
    }
    if (hundreds == 500) {
        return 5;
    }
    if (errorCode == 51103) {
        return 7;
    }
    if (hundreds == 510) {
        return 6;
    }
    if (hundreds == 511) {
        return 6;
    }
    if (hundreds == 513) {
        return 6;
    }
    if (errorCode >= 52000 && errorCode <= 52003) {
        return 8;
    }
    if (errorCode >= 52100 && errorCode <= 52103) {
        return 8;
    }
    if (errorCode >= 52200 && errorCode <= 52203) {
        return 8;
    }
    if (errorCode == 80430) {
        return 9;
    }
    if (thousands == 20) {
        return 0;
    }
    if (hundreds == 520) {
        return 0;
    }
    if (hundreds == 521) {
        return 0;
    }
    if (hundreds == 522) {
        return 0;
    }
    if (hundreds == 523) {
        return 0;
    }
    if (hundreds == 530) {
        return 0;
    }
    if (hundreds == 531) {
        return 0;
    }
    if (hundreds == 532) {
        return 0;
    }
    if (errorCode < 10000) {
        return 14;
    }
    if (thousands == 31) {
        return 12;
    }
    switch (context) {
    case 0:
    case 1:
    case 2:
        return 11;
    case 3:
    case 4:
    case 5:
    case 6:
        return 10;
    default:
        GF_ASSERT(FALSE);
        break;
    case 7:
        return 15;
    }
    return -1;
}

int WifiConnection_Disconnect(int checkOnly) {
    if (checkOnly == 0) {
        switch (sWifiConnection->state) {
        case WIFI_CONNECTION_STATE_MATCHING:
        case WIFI_CONNECTION_STATE_CONNECTED:
        case WIFI_CONNECTION_STATE_CONNECTED_VOICE:
            if (sWifiConnection->voiceChatActive != 0) {
                VoiceChat_HangUp(sWifiConnection->voiceChatActive);
            }
            sWifiConnection->state = WIFI_CONNECTION_STATE_DISCONNECTING;
            break;
        case WIFI_CONNECTION_STATE_LOGGED_IN:
        case WIFI_CONNECTION_STATE_FATAL_ERROR:
        case WIFI_CONNECTION_STATE_DISCONNECTED:
        case WIFI_CONNECTION_STATE_TIMED_OUT:
            return 1;
        }
    } else {
        switch (sWifiConnection->state) {
        case WIFI_CONNECTION_STATE_LOGGED_IN:
        case WIFI_CONNECTION_STATE_DISCONNECTED:
        case WIFI_CONNECTION_STATE_TIMED_OUT:
            return 1;
        }
    }
    return 0;
}

int WifiConnection_FinishDisconnect(void) {
    if (sWifiConnection->state == WIFI_CONNECTION_STATE_DISCONNECTED || sWifiConnection->state == WIFI_CONNECTION_STATE_TIMED_OUT || sWifiConnection->state == WIFI_CONNECTION_STATE_LOGGED_IN) {
        sWifiConnection->state = WIFI_CONNECTION_STATE_LOGGED_IN;
        sWifiConnection->newClientIndex = -1;
        WifiConnection_ResetStopServerMatching();
        return 1;
    }
    return 0;
}

void WifiConnection_SetErrorCallback(void (*callback)(int)) {
    if (sWifiConnection != NULL) {
        sWifiConnection->errorCallback = callback;
    }
}

void WifiConnection_Shutdown(void) {
    DWC_ShutdownFriendsMatch();
    DWC_CleanupInet();
    WifiConnection_StopVoiceChat();
    WifiConnection_Destroy();
}

void WifiConnection_SetFriendStatusBuffer(u8 *data, int stride) {
    sWifiConnection->friendStatusData = data;
    sWifiConnection->friendStatusStride = stride;
}

static void WifiConnection_UpdateFriendStatus(void) {
    int result;
    if (sWifiConnection->friendStatusData) {
        int friendIndex = sWifiConnection->friendStatusIndex & 31;
        if (DWC_IsBuddyFriendData(&sWifiConnection->friendList[friendIndex])) {
            sWifiConnection->friendStatus[friendIndex] = DWC_GetFriendStatusData(&sWifiConnection->friendList[friendIndex], sWifiConnection->friendStatusData + sWifiConnection->friendStatusStride * friendIndex, &result);
        }
        sWifiConnection->friendStatusIndex = (sWifiConnection->friendStatusIndex + 1) & 31;
    }
}

void WifiConnection_SetOwnStatusData(void *data, int size) {
    DWC_SetOwnStatusData(data, size);
}

u8 WifiConnection_GetFriendStatus(int index) {
    return sWifiConnection->friendStatus[index];
}

int WifiConnection_StartMatchmaking(int friendIndex, int maxPlayers, BOOL alternate) {
    int result;

    if (WifiConnection_IsFriendDataChanged()) {
        return WIFI_MATCHMAKING_FRIENDS_CHANGED;
    }
    if (sWifiConnection->state != WIFI_CONNECTION_STATE_LOGGED_IN) {
        sWifiConnection->retryCount++;
        if (sWifiConnection->retryCount > 120) {
            return WIFI_MATCHMAKING_TOO_MANY_TRIES;
        }
        return WIFI_MATCHMAKING_NOT_LOGGED_IN;
    }
    WifiConnection_FreeRecvBuffers();
    sWifiConnection->matchedAidBitmap = 0;
    sWifiConnection->disconnectWhenAlone = 1;
    sWifiConnection->targetFriendIndex = friendIndex;
    sWifiConnection->maxPlayers = maxPlayers;
    if (alternate) {
        maxPlayers = 2;
    }
    sWifiConnection->matchInProgress = 1;
    if (friendIndex < 0) {
        result = DWC_SetupGameServer(maxPlayers, WifiConnection_GameServerMatchedCallback, NULL, WifiConnection_NewClientCallback, NULL);
        sWifiConnection->matchType = WIFI_MATCH_TYPE_HOST;
    } else {
        result = DWC_ConnectToGameServerAsync(friendIndex, WifiConnection_ConnectedToServerCallback, NULL, WifiConnection_NewClientCallback, NULL);
        sWifiConnection->matchType = WIFI_MATCH_TYPE_CLIENT;
    }
    if (!result) {
        sWifiConnection->retryCount++;
        if (sWifiConnection->retryCount > 120) {
            return WIFI_MATCHMAKING_TOO_MANY_TRIES;
        }
        return WIFI_MATCHMAKING_START_FAILED;
    }
    sWifiConnection->retryCount = 0;
    sWifiConnection->state = WIFI_CONNECTION_STATE_MATCHING;
    DWC_SetUserSendCallback(WifiConnection_SendDoneCallback);
    DWC_SetUserRecvCallback(WifiConnection_ReceiveCallback);
    DWC_SetConnectionClosedCallback(WifiConnection_ConnectionClosedCallback, NULL);
    DWC_SetUserRecvTimeoutCallback(WifiConnection_TimeoutCallback);
    sWifiConnection->sendBusy = 0;
    return WIFI_MATCHMAKING_STARTED;
}

int WifiConnection_GetTargetFriendIndex(void) {
    if (sWifiConnection != NULL) {
        return sWifiConnection->targetFriendIndex;
    }
    return -1;
}

static void WifiConnection_GameServerMatchedCallback(int result, BOOL cancelled, BOOL self, BOOL isServer, int aid, void *param) {
    int reject = 0;
    sWifiConnection->matchInProgress = 0;
    if (result == 0) {
        if (!cancelled) {
            u32 mask;
            u32 current;
            if (Comm_IsLinkMode19To23Or34(CommState_GetLinkMode()) && aid == -1) {
                reject = 1;
            }
            if (sWifiConnection->connectFilterCallback && !sWifiConnection->connectFilterCallback(aid)) {
                reject = 1;
            }
            if (sWifiConnection->stopMatchingState || reject) {
                mask = DWC_GetAIDBitmap() & ~sWifiConnection->matchedAidBitmap;
                current = DWC_GetAIDBitmap();
                if (mask) {
                    DWC_CloseConnectionHardBitmap(&mask);
                    if ((mask ^ current) == 1) {
                        sWifiConnection->state = WIFI_CONNECTION_STATE_MATCHED;
                    }
                    return;
                }
            }
            sWifiConnection->targetFriendIndex = aid;
            sWifiConnection->matchedAidBitmap = DWC_GetAIDBitmap();
            if (sWifiConnection->matchedAidBitmap == 1) {
                sWifiConnection->state = WIFI_CONNECTION_STATE_MATCHED;
                return;
            }
            WifiConnection_OnConnected(aid);
        } else if (!self) {
            sWifiConnection->newClientIndex = -1;
        }
    }
}

static void WifiConnection_ConnectedToServerCallback(int result, BOOL cancelled, BOOL self, BOOL isServer, int aid, void *param) {
    sWifiConnection->matchInProgress = 0;
    if (result == 0 && !cancelled) {
        WifiConnection_OnConnected(aid);
    }
}

static void WifiConnection_NewClientCallback(int index) {
    void (*callback)(int, void *);
    sWifiConnection->newClientIndex = index;
    callback = sWifiConnection->clientCallback;
    if (callback) {
        callback((u16)index, sWifiConnection->clientCallbackArg);
    }
}

static void WifiConnection_CreateTokenAndScanFriends(void) {
    DwcAccData profileToken;
    DwcAccData newToken;
    int i;
    int offset;

    if (!DWC_CheckHasProfile(sWifiConnection->userData)) {
        DWC_CreateExchangeToken(sWifiConnection->userData, &profileToken);
    } else {
        DWC_CreateExchangeToken(sWifiConnection->userData, &newToken);
    }
    for (i = 0, offset = 0; i < 32; i++, offset += 12) {
        DWC_GetFriendDataType(&sWifiConnection->friendList[i]);
        DWC_IsBuddyFriendData(&sWifiConnection->friendList[i]);
    }
}

BOOL WifiConnection_GetVoiceActivity(void) {
    return VoiceChat_GetVoiceActivity();
}

int WifiConnection_IsVoiceChatEnabled(void) {
    if (sWifiConnection != NULL) {
        return sWifiConnection->voiceChatEnabled;
    }
    return 0;
}

int WifiConnection_GetNewClientIndex(void) {
    if (sWifiConnection != NULL) {
        return sWifiConnection->newClientIndex;
    }
    return 0;
}

void WifiConnection_SetVoiceChatEnabled(int value) {
    sWifiConnection->voiceChatEnabled = value;
}

void WifiConnection_SetVoiceUnmuted(u16 value) {
    sWifiConnection->voiceUnmuted = value;
}

static void WifiConnection_StopServerMatchingCallback(void *param) {
    sWifiConnection->stopMatchingState = 2;
}

BOOL WifiConnection_StopServerMatching(void) {
    if (sWifiConnection->stopMatchingState == 0) {
        sWifiConnection->stopMatchingState = 1;
        DWC_StopSCMatchingAsync(WifiConnection_StopServerMatchingCallback, 0);
    }
    if (sWifiConnection->stopMatchingState == 2) {
        return TRUE;
    }
    return FALSE;
}

void WifiConnection_ResetStopServerMatching(void) {
    sWifiConnection->stopMatchingState = 0;
}

int WifiConnection_GetNumConnectionHost(void) {
    return DWC_GetNumConnectionHost();
}

void WifiConnection_SetExtraHeapEnabled(BOOL enable, int heapId) {
    WifiConnection *connection;
    if (enable) {
        sWifiConnection->heapId2 = 11;
        if (sWifiConnection->extraHeapMemory == NULL) {
            sWifiConnection->extraHeapMemory = Heap_Alloc((enum HeapID)heapId, 0xF020);
            sWifiConnection->extraHeap = NNS_FndCreateExpHeapEx((void *)(((u32)sWifiConnection->extraHeapMemory + 31) & ~31), 0xF000, 0);
            NNS_FndSetGroupIDForExpHeap(sWifiConnection->extraHeap, 16);
            sWifiConnection->extraHeapFreeSize = NNS_FndGetTotalFreeSizeForExpHeap(sWifiConnection->extraHeap);
        }
    } else {
        sWifiConnection->heapId2 = sWifiConnection->heapId;
        connection = sWifiConnection;
        if (connection->extraHeapMemory) {
            if (connection->extraHeapFreeSize != NNS_FndGetTotalFreeSizeForExpHeap(connection->extraHeap)) {
                CommState_SetError(1);
                return;
            }
            NNS_FndDestroyExpHeap(connection->extraHeap);
            Heap_Free(sWifiConnection->extraHeapMemory);
            sWifiConnection->extraHeapMemory = NULL;
        }
    }
}

void WifiConnection_SetDisconnectWhenAlone(u8 value) {
    sWifiConnection->disconnectWhenAlone = value;
}

static void WifiConnection_FreeRecvBuffer(int aid) {
    void *buffer = sWifiConnection->recvBuffers[aid];
    if (buffer) {
        if (sWifiConnection->recvBufferFromGameHeap[aid] == 1) {
            Heap_Free(buffer);
        } else {
            WifiConnection_Free(0, buffer, 0);
        }
        sWifiConnection->recvBuffers[aid] = NULL;
    }
}

static void WifiConnection_AllocRecvBuffer(int aid) {
    WifiConnection_FreeRecvBuffer(aid);
    if (sWifiConnection->recvBuffers[aid] == NULL) {
        if (sWifiConnection->heapId2 == 11) {
            sWifiConnection->recvBuffers[aid] = Heap_Alloc((enum HeapID)sWifiConnection->heapId2, 0x1020);
            sWifiConnection->recvBufferFromGameHeap[aid] = 1;
        } else {
            sWifiConnection->recvBuffers[aid] = WifiConnection_Alloc(0, 0x1000, 32);
            sWifiConnection->recvBufferFromGameHeap[aid] = 0;
        }
        DWC_SetRecvBuffer(aid, (void *)(((u32)sWifiConnection->recvBuffers[aid] + 31) & ~31), 0x1000);
    }
}

static void WifiConnection_FreeRecvBuffers(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        WifiConnection_FreeRecvBuffer(i);
    }
}

u8 WifiConnection_IsFriendDataChanged(void) {
    return sWifiConnection->friendDataChanged;
}

void WifiConnection_ClearFriendDataChanged(void) {
    sWifiConnection->friendDataChanged = 0;
}
