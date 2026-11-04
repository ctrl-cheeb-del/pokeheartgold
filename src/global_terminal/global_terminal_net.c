#include "global_terminal/global_terminal_net.h"

#include <nitro/os/alloc.h>
#include <nitro/os/arena.h>

#include "global.h"

#include "constants/pokemon.h"
#include "constants/species.h"

#include "msgdata/msg.naix"

#include "application/vs_recorder/vs_recorder_screens.h"
#include "assert.h"
#include "battle_record.h"
#include "dwc/net_common_internal.h"
#include "global_terminal/global_terminal_server.h"
#include "comm_state_internal.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "overlay_00_thumb.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokemon_storage_system.h"
#include "save.h"
#include "string_util.h"
#include "system.h"

// 20001 response: list of dress-up photos
typedef struct GlobalTerminalNetDressUpEntry {
    u8 unk_00[12];
    GlobalTerminalNetDressUpUpload photo;
} GlobalTerminalNetDressUpEntry;

typedef struct GlobalTerminalNetDressUpList {
    int count;
    GlobalTerminalNetDressUpEntry entries[1];
} GlobalTerminalNetDressUpList;

typedef struct GlobalTerminalNetDressUpListResponse {
    int unk_00;
    GlobalTerminalNetDressUpList list;
} GlobalTerminalNetDressUpListResponse;

// 21001 response: list of boxes
typedef struct GlobalTerminalNetBoxEntry {
    u8 unk_00[16];
    GlobalTerminalNetBoxUpload box;
} GlobalTerminalNetBoxEntry;

typedef struct GlobalTerminalNetBoxListResponse {
    int unk_00;
    int count;
    GlobalTerminalNetBoxEntry entries[1];
} GlobalTerminalNetBoxListResponse;

// 22000 response: the records of this week's rankings
typedef struct GlobalTerminalNetRankingsHeaderResponse {
    u32 unk_00;
    u8 recordIds[4];
} GlobalTerminalNetRankingsHeaderResponse;

// 22001 response: last week's results, then this week's standings
typedef struct GlobalTerminalNetRankings {
    GlobalTerminalNetRankingResults results[3];
    GlobalTerminalNetRankingStandings standings[3];
} GlobalTerminalNetRankings;

typedef struct GlobalTerminalNetRankingsResponse {
    u32 unk_00;
    GlobalTerminalNetRankings rankings;
} GlobalTerminalNetRankingsResponse;

// 23000 response
typedef struct GlobalTerminalNetVideoNumberResponse {
    u32 unk_00;
    u32 numberLow;
    u32 numberHigh;
} GlobalTerminalNetVideoNumberResponse;

// 23001 response: list of battle video headers
typedef struct GlobalTerminalNetVideoEntry {
    u32 unk_00;
    u64 number;
    GlobalTerminalNetVideoHeader header;
} GlobalTerminalNetVideoEntry;

typedef struct GlobalTerminalNetVideoList {
    int count;
    GlobalTerminalNetVideoEntry entries[1];
} GlobalTerminalNetVideoList;

typedef struct GlobalTerminalNetVideoListResponse {
    u8 unk_00[4];
    GlobalTerminalNetVideoList list;
} GlobalTerminalNetVideoListResponse;

// 23002 response: one battle video
typedef struct GlobalTerminalNetVideoResponse {
    u64 unk_00;
    u64 number;
    u8 unk_10[0xD8];
    u64 savedNumber;
} GlobalTerminalNetVideoResponse;

typedef struct GlobalTerminalNetVideoView {
    u8 unk_00[0xE4];
    u8 savedNumber[8];
} GlobalTerminalNetVideoView;

enum GlobalTerminalNetStepResult {
    GLOBAL_TERMINAL_NET_STEP_WAIT,
    GLOBAL_TERMINAL_NET_STEP_NEXT,
    GLOBAL_TERMINAL_NET_STEP_RESTART,
};

static void GlobalTerminalNet_PackDressUpPhoto(SaveData *saveData, const SaveFashionDataSub *record, GlobalTerminalNetDressUpForm *form);
static void GlobalTerminalNet_SealBoxData(SaveData *saveData, GlobalTerminalNetBoxForm *form, int value);
static void GlobalTerminalNet_SetRequestHeader(SaveData *saveData, const FrontierCard *src, void *dst);
static int GlobalTerminalNet_SeqStopClient(GlobalTerminalNet *net, void *stepWork);
static int GlobalTerminalNet_SeqDisconnect(GlobalTerminalNet *net, void *stepWork);
static int GlobalTerminalNet_SeqShowError(GlobalTerminalNet *net, void *stepWork);
static int GlobalTerminalNet_SeqWaitButton(GlobalTerminalNet *net, void *stepWork);
static BOOL GlobalTerminalNet_SendPendingRequest(GlobalTerminalNet *net);
static BOOL GlobalTerminalNet_PollStatus(GlobalTerminalNet *net);
static BOOL GlobalTerminalNet_CompleteResponse(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending);
static BOOL GlobalTerminalNet_CompleteVideoUploadFailed(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending);
static BOOL GlobalTerminalNet_SaveUploadedVideoNumber(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending);
static BOOL GlobalTerminalNet_CompleteDressUpUploadFailed(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending);
static BOOL GlobalTerminalNet_CompleteBoxUploadFailed(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending);
static BOOL GlobalTerminalNet_CompleteError(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending);
static BOOL GlobalTerminalNet_HandleResponse(GlobalTerminalNet *net);
static void GlobalTerminalNet_PrintMessage(GlobalTerminalNet *net, String *message);
static void GlobalTerminalNet_ShowErrorMessage(GlobalTerminalNet *net, int msgId, int errorNumber);
static u32 GlobalTerminalNet_GetSequence(GlobalTerminalNet *net);
static void *GlobalTerminalNet_CreateOsHeap(enum HeapID heapID);
static void GlobalTerminalNet_ClearOsHeap(void);
static BOOL GlobalTerminalNet_CheckDressUpUploadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckDressUpDownloadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckBoxUploadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckBoxDownloadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_Check22000Result(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckRankingsResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckVideoUploadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckVideoSearchResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_CheckVideoDownloadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);
static BOOL GlobalTerminalNet_Check23003Result(GlobalTerminalNet *net, GlobalTerminalNetResponse *response);

static const GlobalTerminalNetStepFunc sGlobalTerminalNetNoSequence[1] = {
    NULL,
};

static const GlobalTerminalNetStepFunc sGlobalTerminalNetErrorSequence[5] = {
    GlobalTerminalNet_SeqDisconnect,
    GlobalTerminalNet_SeqStopClient,
    GlobalTerminalNet_SeqShowError,
    GlobalTerminalNet_SeqWaitButton,
    NULL,
};

// Nothing sets net->sequence, so the error sequence never runs.
static const GlobalTerminalNetStepFunc *const sGlobalTerminalNetSequences[3] = {
    NULL,
    sGlobalTerminalNetErrorSequence,
    sGlobalTerminalNetNoSequence,
};

static OSHeapHandle sGlobalTerminalNetOsHeap;

static void GlobalTerminalNet_PackDressUpPhoto(SaveData *saveData, const SaveFashionDataSub *record, GlobalTerminalNetDressUpForm *form) {
    GlobalTerminalNet_DressUpToUploadForm(record, form);
    form->crc = SaveArray_CalcCRC16(saveData, form, offsetof(GlobalTerminalNetDressUpForm, crc));
}

void GlobalTerminalNet_UnpackDressUpPhoto(const GlobalTerminalNetDressUpForm *form, SaveFashionDataSub *record) {
    GlobalTerminalNet_UploadFormToDressUp(form, record);
}

void GlobalTerminalNet_PackBoxData(SaveData *saveData, PCStorage *storage, int box, GlobalTerminalNetBoxForm *form, enum HeapID heapID) {
    String *name;
    int i;

    MI_CpuFill8(form, 0, sizeof(GlobalTerminalNetBoxForm));
    name = String_New(60, heapID);
    PCStorage_GetBoxName(storage, box, name);
    CopyStringToU16Array(name, form->name, 20);
    String_Delete(name);
    for (i = 0; i < 30; i++) {
        form->species[i] = PCStorage_GetMonDataByIndexPair(storage, box, i, MON_DATA_SPECIES, NULL);
        form->personality[i] = PCStorage_GetMonDataByIndexPair(storage, box, i, MON_DATA_PERSONALITY, NULL);
        form->otIds[i] = PCStorage_GetMonDataByIndexPair(storage, box, i, MON_DATA_OT_ID, NULL);
        if (PCStorage_GetMonDataByIndexPair(storage, box, i, MON_DATA_SPECIES_OR_EGG, NULL) == SPECIES_EGG) {
            form->eggFlags |= 1 << i;
        }
        form->forms[i] = PCStorage_GetMonDataByIndexPair(storage, box, i, MON_DATA_FORM, NULL);
    }
    form->wallpaper = PCStorage_GetBoxWallpaper(storage, box);
    form->category = 0;
    form->crc = SaveArray_CalcCRC16(saveData, form, offsetof(GlobalTerminalNetBoxForm, crc));
}

static void GlobalTerminalNet_SealBoxData(SaveData *saveData, GlobalTerminalNetBoxForm *form, int value) {
    form->category = value;
    form->crc = SaveArray_CalcCRC16(saveData, form, offsetof(GlobalTerminalNetBoxForm, crc));
}

static void GlobalTerminalNet_SetRequestHeader(SaveData *saveData, const FrontierCard *src, void *dst) {
    MI_CpuFill8(dst, 0, 0x80);
    MI_CpuCopy8(src, dst, 0x80);
}

void GlobalTerminalNet_CopyRequestHeader(const void *src, FrontierCard *dst) {
    MI_CpuCopy8(src, dst, 0x80);
}

void GlobalTerminalNet_SetRankingsHeader(SaveData *saveData, const GlobalTerminalNetRankingsSource *src, GlobalTerminalNetRankingsHeader *dst) {
    MI_CpuFill8(dst, 0, sizeof(GlobalTerminalNetRankingsHeader));
    dst->version = src->version;
    dst->unk_01 = src->unk_1A;
    dst->birthdayMonth = src->birthdayMonth;
    dst->avatar = src->avatar;
    dst->species = src->species;
    dst->isEgg = src->isEgg;
}

BOOL GlobalTerminalNet_Init(GlobalTerminalNet *net, GlobalTerminalNetArgs *args) {
    MI_CpuFill8(net, 0, sizeof(GlobalTerminalNet));
    net->heapID = args->heapID;
    net->saveData = args->saveData;
    net->callbacks = args->callbacks;
    net->messageArg = args->messageArg;
    net->messageFunc = args->messageFunc;
    net->prevStatus = -1;
    net->pendingCommand = GTS_REQUEST_NONE;
    net->activeCommand = GTS_REQUEST_NONE;
    net->responseBuffer = Heap_Alloc(args->heapID, GlobalTerminalServer_GetResponseBufferSize(-1));
    MI_CpuFill8(net->responseBuffer, 0, GlobalTerminalServer_GetResponseBufferSize(-1));
    net->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0800_bin, args->heapID);
    net->msgFormat = MessageFormat_New(args->heapID);
    net->string = String_New(256, args->heapID);
    net->osHeapMemory = GlobalTerminalNet_CreateOsHeap(args->heapID);
    net->login.dwcProfileId = args->dwcProfileId;
    net->login.gameVersion = GAME_VERSION;
    net->login.unk_05 = 2;
    GF_ASSERT(GlobalTerminalServer_Init(&net->login) == TRUE);
    net->isRunning = TRUE;
    net->initialized = 1;
    return TRUE;
}

void GlobalTerminalNet_Free(GlobalTerminalNet *net) {
    GlobalTerminalServer_Stop();
    net->isRunning = FALSE;
    String_Delete(net->string);
    MessageFormat_Delete(net->msgFormat);
    DestroyMsgData(net->msgData);
    Heap_Free(net->responseBuffer);
    GlobalTerminalNet_ClearOsHeap();
    Heap_Free(net->osHeapMemory);
}

static int GlobalTerminalNet_SeqStopClient(GlobalTerminalNet *net, void *stepWork) {
    GlobalTerminalServer_Stop();
    net->isRunning = FALSE;
    return GLOBAL_TERMINAL_NET_STEP_NEXT;
}

static int GlobalTerminalNet_SeqDisconnect(GlobalTerminalNet *net, void *stepWork) {
    DWC_ClearError();
    DWC_CleanupInet();
    CommState_FreeWfcSession();
    net->unk_3C8 = 0;
    return GLOBAL_TERMINAL_NET_STEP_NEXT;
}

static int GlobalTerminalNet_SeqShowError(GlobalTerminalNet *net, void *stepWork) {
    int msgId = WifiConnection_ClassifyErrorCode(-net->errorCode, net->errorType);
    GlobalTerminalNet_ShowErrorMessage(net, msgId, -net->errorCode);
    return GLOBAL_TERMINAL_NET_STEP_NEXT;
}

static int GlobalTerminalNet_SeqWaitButton(GlobalTerminalNet *net, void *stepWork) {
    u32 keys = gSystem.newKeys;
    if ((keys & PAD_BUTTON_A) || (keys & PAD_BUTTON_B)) {
        GlobalTerminalNet_PrintMessage(net, NULL);
        return GLOBAL_TERMINAL_NET_STEP_NEXT;
    }
    return GLOBAL_TERMINAL_NET_STEP_WAIT;
}

BOOL GlobalTerminalNet_RequestDressUpUpload(GlobalTerminalNet *net, const FrontierCard *header, const SaveFashionDataSub *record) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    GlobalTerminalNet_SetRequestHeader(net->saveData, header, net->request.dressUpUpload.header);
    GlobalTerminalNet_PackDressUpPhoto(net->saveData, record, &net->request.dressUpUpload.form);
    net->sendDelay = 60;
    net->pendingCommand = GTS_REQUEST_DRESS_UP_UPLOAD;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestDressUpDownload(GlobalTerminalNet *net, int arg) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    net->requestArg.half = arg;
    net->pendingCommand = GTS_REQUEST_DRESS_UP_DOWNLOAD;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestBoxUpload(GlobalTerminalNet *net, int value, const FrontierCard *header, PCStorage *storage, int box) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    net->requestArg.bytes[0] = value;
    net->requestArg.bytes[1] = box;
    GlobalTerminalNet_SetRequestHeader(net->saveData, header, net->request.boxUpload.header);
    GlobalTerminalNet_PackBoxData(net->saveData, storage, box, &net->request.boxUpload.form, net->heapID);
    GlobalTerminalNet_SealBoxData(net->saveData, &net->request.boxUpload.form, value);
    net->sendDelay = 60;
    net->pendingCommand = GTS_REQUEST_BOX_UPLOAD;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestBoxDownload(GlobalTerminalNet *net, int arg) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    net->requestArg.bytes[0] = arg;
    net->pendingCommand = GTS_REQUEST_BOX_DOWNLOAD;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestRankingsHeader(GlobalTerminalNet *net) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    net->pendingCommand = GTS_REQUEST_22000;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestRankings(GlobalTerminalNet *net, const GlobalTerminalNetRankingsSource *src, const GlobalTerminalNetPair *pairs) {
    s32 i;

    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    MI_CpuCopy8(Save_PlayerData_GetIGTAddr(net->saveData), &net->request.rankings.playTime, 4);
    GlobalTerminalNet_SetRankingsHeader(net->saveData, src, &net->request.rankings.header);
    for (i = 0; i < 3; i++) {
        net->request.rankings.pairs[i] = pairs[i];
    }
    net->pendingCommand = GTS_REQUEST_RANKINGS;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestVideoUpload(GlobalTerminalNet *net, const FrontierCard *header) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    GF_ASSERT(BattleRecord_sizeof() - 4 == 0x1D4C);
    net->request.video = BattleRecord_GetProfile2();
    VsRecorder_EncryptRecord(net->saveData);
    MI_CpuCopy8(header, BattleRecord_GetProfile(), 0x80);
    net->sendDelay = 60;
    net->pendingCommand = GTS_REQUEST_VIDEO_UPLOAD;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestVideoSearch(GlobalTerminalNet *net, u16 species, u8 facility, u8 country, u8 region) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    MI_CpuFill8(&net->request, 0, sizeof(GlobalTerminalNetVideoSearch));
    net->request.search.species = species;
    net->request.search.facility = facility;
    net->request.search.country = country;
    net->request.search.region = region;
    net->request.search.unk_08 = 0x140;
    net->searchKind = 0;
    net->pendingCommand = GTS_REQUEST_VIDEO_SEARCH;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestDefaultVideoSearchNoFrontier(GlobalTerminalNet *net) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    MI_CpuFill8(&net->request, 0, sizeof(GlobalTerminalNetVideoSearch));
    net->request.search.species = 0xFFFF;
    net->request.search.facility = 0xFE;
    net->request.search.country = 0xFF;
    net->request.search.region = 0xFF;
    net->request.search.unk_08 = 0x140;
    net->searchKind = 0;
    net->pendingCommand = GTS_REQUEST_VIDEO_SEARCH;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestDefaultVideoSearch(GlobalTerminalNet *net) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    MI_CpuFill8(&net->request, 0, sizeof(GlobalTerminalNetVideoSearch));
    net->request.search.species = 0xFFFF;
    net->request.search.facility = 0xFF;
    net->request.search.country = 0xFF;
    net->request.search.region = 0xFF;
    net->request.search.unk_08 = 0x140;
    net->searchKind = 0;
    net->pendingCommand = GTS_REQUEST_VIDEO_SEARCH;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestTopColosseumVideos(GlobalTerminalNet *net) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    MI_CpuFill8(&net->request.unk_00, 0, 4);
    net->request.unk_00 = 0x140;
    net->searchKind = 1;
    net->pendingCommand = GTS_REQUEST_VIDEO_SEARCH;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestTopFrontierVideos(GlobalTerminalNet *net) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    MI_CpuFill8(&net->request.unk_00, 0, 4);
    net->request.unk_00 = 0x140;
    net->searchKind = 2;
    net->pendingCommand = GTS_REQUEST_VIDEO_SEARCH;
    return TRUE;
}

BOOL GlobalTerminalNet_RequestVideoDownload(GlobalTerminalNet *net, u32 numberLow, u32 numberHigh) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    net->requestArg.word = numberLow;
    net->requestArgHigh = numberHigh;
    net->pendingCommand = GTS_REQUEST_VIDEO_DOWNLOAD;
    return TRUE;
}

BOOL GlobalTerminalNet_ReportVideoSaved(GlobalTerminalNet *net, u32 argLow, u32 argHigh) {
    if (!GlobalTerminalNet_IsIdle(net)) {
        return FALSE;
    }
    net->requestArg.word = argLow;
    net->requestArgHigh = argHigh;
    net->pendingCommand = GTS_REQUEST_23003;
    return TRUE;
}

BOOL GlobalTerminalNet_Update(GlobalTerminalNet *net) {
    const GlobalTerminalNetStepFunc *sequence;

    if (net->isRunning == 1) {
        if (net->pendingCommand != GTS_REQUEST_NONE) {
            if (net->sendDelay != 0) {
                net->sendDelay--;
            } else {
                switch (GlobalTerminalServer_GetState()) {
                case GTS_SOCKET_STATE_READY:
                case GTS_SOCKET_STATE_CANCELLED:
                case GTS_SOCKET_STATE_DONE:
                case GTS_SOCKET_STATE_ERROR:
                    if (GlobalTerminalNet_SendPendingRequest(net) == TRUE) {
                        net->pendingCommand = GTS_REQUEST_NONE;
                    }
                    break;
                }
            }
        }
        GlobalTerminalNet_PollStatus(net);
        if (net->pendingResponse.completeFunc != NULL) {
            if (net->pendingResponse.completeFunc(net, &net->pendingResponse) == TRUE) {
                net->pendingResponse.completeFunc = NULL;
                if (net->pendingResponse.func != NULL) {
                    net->pendingResponse.func(net->callbacks.arg, &net->error);
                    net->pendingResponse.func = NULL;
                }
                MI_CpuFill8(&net->pendingResponse, 0, sizeof(net->pendingResponse));
                net->activeCommand = GTS_REQUEST_NONE;
            }
        }
    }

    sequence = sGlobalTerminalNetSequences[net->sequence];
    if (sequence != NULL) {
        switch (sequence[net->sequenceStep](net, &net->stepWork)) {
        case GLOBAL_TERMINAL_NET_STEP_WAIT:
            break;
        case GLOBAL_TERMINAL_NET_STEP_NEXT:
            MI_CpuFill8(&net->stepWork, 0, sizeof(GlobalTerminalNetStepWork));
            net->sequenceStep++;
            MI_CpuFill8(&net->stepWork, 0, sizeof(GlobalTerminalNetStepWork));
            if (sGlobalTerminalNetSequences[net->sequence][net->sequenceStep] == NULL) {
                net->sequenceStep = 0;
                net->sequence = 0;
            }
            break;
        case GLOBAL_TERMINAL_NET_STEP_RESTART:
            MI_CpuFill8(&net->stepWork, 0, sizeof(GlobalTerminalNetStepWork));
            net->sequenceStep = 0;
            break;
        }
    }
    return TRUE;
}

static BOOL GlobalTerminalNet_SendPendingRequest(GlobalTerminalNet *net) {
    BOOL result = FALSE;

    switch (net->pendingCommand) {
    case GTS_REQUEST_DRESS_UP_UPLOAD:
        result = GlobalTerminalServer_UploadDressUp(&net->request.dressUpUpload, net->responseBuffer);
        break;
    case GTS_REQUEST_DRESS_UP_DOWNLOAD:
        result = GlobalTerminalServer_DownloadDressUp(net->requestArg.half, net->responseBuffer);
        break;
    case GTS_REQUEST_BOX_UPLOAD:
        result = GlobalTerminalServer_UploadBox(net->requestArg.bytes[0], &net->request.boxUpload, net->responseBuffer);
        break;
    case GTS_REQUEST_BOX_DOWNLOAD:
        result = GlobalTerminalServer_DownloadBox(net->requestArg.bytes[0], net->responseBuffer);
        break;
    case GTS_REQUEST_22000:
        result = GlobalTerminalServer_SendRequest22000(net->responseBuffer);
        break;
    case GTS_REQUEST_RANKINGS:
        result = GlobalTerminalServer_GetRankings(&net->request.rankings, net->responseBuffer);
        break;
    case GTS_REQUEST_VIDEO_UPLOAD:
        result = GlobalTerminalServer_UploadVideo(net->request.video, net->responseBuffer);
        break;
    case GTS_REQUEST_VIDEO_SEARCH:
        switch (net->searchKind) {
        case 0:
            result = GlobalTerminalServer_SearchVideos(&net->request.search, net->responseBuffer);
            break;
        case 1:
            result = GlobalTerminalServer_SearchVideosKind1(&net->request.unk_00, net->responseBuffer);
            break;
        case 2:
            result = GlobalTerminalServer_SearchVideosKind2(&net->request.unk_00, net->responseBuffer);
            break;
        }
        break;
    case GTS_REQUEST_VIDEO_DOWNLOAD:
        result = GlobalTerminalServer_DownloadVideo(net->requestArg.word, net->requestArgHigh, 0x140, net->responseBuffer);
        break;
    case GTS_REQUEST_23003:
        result = GlobalTerminalServer_SendRequest23003(net->requestArg.word, net->requestArgHigh, net->responseBuffer);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }

    if (result == TRUE) {
        net->activeCommand = net->pendingCommand;
    }
    return result;
}

static BOOL GlobalTerminalNet_PollStatus(GlobalTerminalNet *net) {
    if (net->activeCommand == GTS_REQUEST_NONE) {
        return TRUE;
    }
    net->status = GlobalTerminalServer_GetState();
    if (net->status != net->prevStatus) {
        switch (net->status) {
        case GTS_SOCKET_STATE_NONE:
        case GTS_SOCKET_STATE_READY:
        case GTS_SOCKET_STATE_FETCH_TOKEN:
        case GTS_SOCKET_STATE_OPEN:
        case GTS_SOCKET_STATE_CONNECT:
        case GTS_SOCKET_STATE_SEND:
        case GTS_SOCKET_STATE_RECEIVE:
            break;
        case GTS_SOCKET_STATE_CANCELLED:
            net->error.type = 1;
            net->error.command = 0;
            net->error.code = 7;
            net->error.isError = TRUE;
            net->pendingResponse.completeFunc = GlobalTerminalNet_CompleteError;
            break;
        case GTS_SOCKET_STATE_DONE:
            net->pendingResponse.completeFunc = GlobalTerminalNet_CompleteResponse;
            GlobalTerminalNet_HandleResponse(net);
            break;
        case GTS_SOCKET_STATE_ERROR:
            net->error.type = 0;
            net->error.command = 0;
            net->error.code = GlobalTerminalServer_GetError();
            net->error.isError = TRUE;
            net->pendingResponse.completeFunc = GlobalTerminalNet_CompleteError;
            break;
        }
        net->prevStatus = net->status;
    }
    return TRUE;
}

static BOOL GlobalTerminalNet_CompleteResponse(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending) {
    return TRUE;
}

static BOOL GlobalTerminalNet_CompleteVideoUploadFailed(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending) {
    return TRUE;
}

// stores the server's number for the uploaded video in the recording and saves it; done when the save finished
static BOOL GlobalTerminalNet_SaveUploadedVideoNumber(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending) {
    GlobalTerminalNetVideoNumberResponse *response = GlobalTerminalServer_GetResponse();
    int result = VsRecorder_SaveRecordNumber(net->saveData, response->numberLow, response->numberHigh, &pending->saveState, &pending->saveWriteState);
    return (u32)(result - 2) <= 1;
}

static BOOL GlobalTerminalNet_CompleteDressUpUploadFailed(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending) {
    return TRUE;
}

static BOOL GlobalTerminalNet_CompleteBoxUploadFailed(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending) {
    return TRUE;
}

static BOOL GlobalTerminalNet_CompleteError(GlobalTerminalNet *net, GlobalTerminalNetPendingResponse *pending) {
    return TRUE;
}

static BOOL GlobalTerminalNet_HandleResponse(GlobalTerminalNet *net) {
    BOOL result = TRUE;
    GlobalTerminalNetResponse *response = GlobalTerminalServer_GetResponse();

    GlobalTerminalServer_GetResponseSize();
    GF_ASSERT(net->activeCommand == response->command);
    net->pendingResponse.func = NULL;
    switch (response->command) {
    case 0:
        break;
    case GTS_REQUEST_DRESS_UP_UPLOAD:
        result = GlobalTerminalNet_CheckDressUpUploadResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[0];
        if (!result) {
            net->pendingResponse.completeFunc = GlobalTerminalNet_CompleteDressUpUploadFailed;
        }
        break;
    case GTS_REQUEST_DRESS_UP_DOWNLOAD:
        result = GlobalTerminalNet_CheckDressUpDownloadResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[1];
        break;
    case GTS_REQUEST_BOX_UPLOAD:
        result = GlobalTerminalNet_CheckBoxUploadResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[2];
        if (!result) {
            net->pendingResponse.completeFunc = GlobalTerminalNet_CompleteBoxUploadFailed;
        }
        break;
    case GTS_REQUEST_BOX_DOWNLOAD:
        result = GlobalTerminalNet_CheckBoxDownloadResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[3];
        break;
    case GTS_REQUEST_22000:
        result = GlobalTerminalNet_Check22000Result(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[4];
        break;
    case GTS_REQUEST_RANKINGS:
        result = GlobalTerminalNet_CheckRankingsResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[5];
        break;
    case GTS_REQUEST_VIDEO_UPLOAD:
        result = GlobalTerminalNet_CheckVideoUploadResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[6];
        if (!result) {
            net->pendingResponse.completeFunc = GlobalTerminalNet_CompleteVideoUploadFailed;
        } else {
            net->pendingResponse.completeFunc = GlobalTerminalNet_SaveUploadedVideoNumber;
        }
        break;
    case GTS_REQUEST_VIDEO_SEARCH:
        result = GlobalTerminalNet_CheckVideoSearchResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[7];
        break;
    case GTS_REQUEST_VIDEO_DOWNLOAD:
        result = GlobalTerminalNet_CheckVideoDownloadResult(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[8];
        break;
    case GTS_REQUEST_23003:
        result = GlobalTerminalNet_Check23003Result(net, response);
        net->pendingResponse.func = net->callbacks.onResponse[9];
        break;
    }
    if (!result) {
        net->error.type = 2;
        net->error.command = response->command;
        net->error.code = response->result;
        net->error.isError = TRUE;
    } else {
        net->error.isError = FALSE;
    }
    return result;
}

u32 GlobalTerminalNet_GetError(GlobalTerminalNet *net, GlobalTerminalNetError **error) {
    *error = &net->error;
    return net->error.isError;
}

static void GlobalTerminalNet_PrintMessage(GlobalTerminalNet *net, String *message) {
    net->messageFunc(net->messageArg, message);
}

static void GlobalTerminalNet_ShowErrorMessage(GlobalTerminalNet *net, int msgId, int errorNumber) {
    String *string;

    if (msgId == -1) {
        msgId = 11;
    }
    BufferIntegerAsString(net->msgFormat, 0, errorNumber, 5, PRINTING_MODE_LEADING_ZEROS, TRUE);
    string = NewString_ReadMsgData(net->msgData, msgId);
    StringExpandPlaceholders(net->msgFormat, net->string, string);
    String_Delete(string);
    GlobalTerminalNet_PrintMessage(net, net->string);
}

BOOL GlobalTerminalNet_IsIdle(GlobalTerminalNet *net) {
    if (GlobalTerminalNet_GetSequence(net) == 0 && net->pendingCommand == GTS_REQUEST_NONE && net->activeCommand == GTS_REQUEST_NONE) {
        return TRUE;
    }
    return FALSE;
}

static u32 GlobalTerminalNet_GetSequence(GlobalTerminalNet *net) {
    return net->sequence;
}

static void *GlobalTerminalNet_CreateOsHeap(enum HeapID heapID) {
    void *memory = Heap_Alloc(heapID, 0x2000);
    void *end = (u8 *)memory + 0x2000;
    void *arenaLo = OS_InitAlloc(OS_ARENA_MAIN, memory, end, 1);

    OS_SetArenaLo(OS_ARENA_MAIN, arenaLo);
    arenaLo = (void *)(((u32)arenaLo + 31) & ~31);
    end = (void *)(((u32)end + 31) & ~31);
    sGlobalTerminalNetOsHeap = OS_CreateHeap(OS_ARENA_MAIN, arenaLo, end);
    OS_SetCurrentHeap(OS_ARENA_MAIN, sGlobalTerminalNetOsHeap);
    return memory;
}

static void GlobalTerminalNet_ClearOsHeap(void) {
    OS_ClearAlloc(OS_ARENA_MAIN);
}

// every result check has a case list with the server's error results, all of which fall through to FALSE
static BOOL GlobalTerminalNet_CheckDressUpUploadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
    return ret;
}

static BOOL GlobalTerminalNet_CheckDressUpDownloadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    return ret;
}

int GlobalTerminalNet_GetDressUpList(GlobalTerminalNet *net, GlobalTerminalNetDressUpUpload **out, int max) {
    GlobalTerminalNetDressUpList *list = &((GlobalTerminalNetDressUpListResponse *)GlobalTerminalServer_GetResponse())->list;
    int count = list->count;
    int i;
    GlobalTerminalNetDressUpEntry *entry;

    if (count > max) {
        count = max;
    }
    entry = list->entries;
    i = 0;
    if (count > 0) {
        do {
            out[i] = &entry->photo;
            i++;
            entry++;
        } while (i < count);
    }
    for (; i < max; i++) {
        out[i] = NULL;
    }
    return count;
}

static BOOL GlobalTerminalNet_CheckBoxUploadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    }
    return ret;
}

static BOOL GlobalTerminalNet_CheckBoxDownloadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    return ret;
}

int GlobalTerminalNet_GetBoxList(GlobalTerminalNet *net, GlobalTerminalNetBoxUpload **out, int max) {
    int count;
    int *base = &((GlobalTerminalNetBoxListResponse *)GlobalTerminalServer_GetResponse())->count;
    int i;
    GlobalTerminalNetBoxEntry *entry;

    count = *base;
    if (count > max) {
        count = max;
        GF_ASSERT(FALSE);
    }
    entry = (GlobalTerminalNetBoxEntry *)(base + 1);
    i = 0;
    if (i < count) {
        GlobalTerminalNetBoxUpload **dst = out;
        do {
            *dst++ = &entry->box;
            i++;
            entry++;
        } while (i < count);
    }
    if (i < max) {
        GlobalTerminalNetBoxUpload **dst = out + i;
        do {
            *dst++ = NULL;
            i++;
        } while (i < max);
    }
    return count;
}

static BOOL GlobalTerminalNet_Check22000Result(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
        break;
    }
    return ret;
}

void GlobalTerminalNet_GetRankingsHeader(GlobalTerminalNet *net, u8 **recordIds) {
    GlobalTerminalNetRankingsHeaderResponse *response = GlobalTerminalServer_GetResponse();
    *recordIds = response->recordIds;
}

static BOOL GlobalTerminalNet_CheckRankingsResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
    return ret;
}

void GlobalTerminalNet_GetRankings(GlobalTerminalNet *net, GlobalTerminalNetRankingResults **results, GlobalTerminalNetRankingStandings **standings) {
    GlobalTerminalNetRankings *rankings = &((GlobalTerminalNetRankingsResponse *)GlobalTerminalServer_GetResponse())->rankings;
    *results = rankings->results;
    *standings = rankings->standings;
}

static BOOL GlobalTerminalNet_CheckVideoUploadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
    return ret;
}

u64 GlobalTerminalNet_GetUploadedVideoNumber(GlobalTerminalNet *net) {
    GlobalTerminalNetVideoNumberResponse *response = GlobalTerminalServer_GetResponse();
    return *(u64 *)&response->numberLow;
}

static BOOL GlobalTerminalNet_CheckVideoSearchResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    return ret;
}

int GlobalTerminalNet_GetVideoList(GlobalTerminalNet *net, GlobalTerminalNetVideoHeader **out, int max) {
    GlobalTerminalNetVideoList *list = &((GlobalTerminalNetVideoListResponse *)GlobalTerminalServer_GetResponse())->list;
    int count = list->count;
    GlobalTerminalNetVideoEntry *entry;
    int i;

    if (count > max) {
        count = max;
        GF_ASSERT(FALSE);
    }
    entry = list->entries;
    for (i = 0; i < count; i++) {
        out[i] = &entry->header;
        if (out[i]->number != entry->number) {
            out[i]->number = entry->number;
            out[i]->crc = SaveArray_CalcCRC16(net->saveData, out[i]->data, sizeof(out[i]->data));
        }
        entry++;
    }
    for (; i < max; i++) {
        out[i] = NULL;
    }
    return count;
}

static BOOL GlobalTerminalNet_CheckVideoDownloadResult(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    return ret;
}

u32 GlobalTerminalNet_GetDownloadedVideo(GlobalTerminalNet *net, u8 **out) {
    GlobalTerminalNetVideoResponse *response = GlobalTerminalServer_GetResponse();
    GlobalTerminalNetVideoView *view = (GlobalTerminalNetVideoView *)((u8 *)response + 4);

    *out = (u8 *)((u32)view + 12);
    if (*(u64 *)view->savedNumber != response->number) {
        *(u64 *)view->savedNumber = response->number;
        *(u16 *)(*out + 0xE0) = SaveArray_CalcCRC16(net->saveData, *out + 0x80, 0x58);
    }
    return response->number; // low word only
}

static BOOL GlobalTerminalNet_Check23003Result(GlobalTerminalNet *net, GlobalTerminalNetResponse *response) {
    BOOL ret = FALSE;
    switch (response->result) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    return ret;
}
