#include "application/main_menu/mystery_gift_wfc.h"

#include "global.h"

#include "application/main_menu/mystery_gift_app.h"
#include "application/main_menu/mystery_gift_app_internal.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "comm_wireless.h"
#include "heap.h"
#include "network_overlay_loader.h"
#include "overlay_manager.h"
#include "system.h"
#include "wifi_connection.h"
#include "wireless_status_icon.h"

// Mystery Gift > Get via Nintendo Wi-Fi Connection: connects, downloads the gift file of the game (into
// MysteryGiftAppData.wfcRecvBuffer) and disconnects. MysteryGiftApp_RunWfcDownload runs MysteryGiftWfc_Run every frame.

// The state of the download library callbacks (gMysteryGiftWfcStatus)
typedef struct MysteryGiftWfcStatus {
    BOOL requestDone; // MysteryGiftWfc_OnRequestDone
    BOOL cleanupDone; // MysteryGiftWfc_OnCleanupDone
    int result;       // MYSTERY_GIFT_WFC_RESULT_*
    int requestError;
    BOOL errorShown;
} MysteryGiftWfcStatus;

int DWC_GetLastErrorEx(s32 *errorCode, s32 *errorType);
int DWC_GetInetStatus(void);
void DWC_GetApInfo(void *data);
int DWC_NdCleanupAsync(void (*callback)(void));
void DWC_ClearError(void);
void DWC_SetMemFunc(void *(*alloc)(void *, u32), void (*free)(void *, void *));
void DWC_InitInetEx(void *config, int priority, int unused, int sslPriority);
void DWC_SetAuthServer(int server);
void DWC_ConnectInetAsync(void);
int DWC_CheckInet(void);
void DWC_ProcessInet(void);
void DWC_CleanupInet(void);
int DWC_CleanupInetAsync(void);
int DWC_UpdateConnection(void);
int DWC_NASLoginAsync(void);
int DWC_NASLoginProcess(void);
void DWC_NASLoginAbort(void);
int DWC_NdInitAsync(void (*callback)(int, int), const char *gameCode, const char *secretKey);
int DWC_NdSetAttr(const char *attribute1, const char *attribute2, const char *attribute3);
int DWC_NdGetFileListNumAsync(int *count);
int DWC_NdGetFileListAsync(void *fileList, int start, int count);
int DWC_NdGetFileAsync(void *fileInfo, void *buffer, int size);
int DWC_NdCancelAsync(void);
int DWC_NdGetProgress(u32 *received, u32 *total);

extern MysteryGiftWfcStatus gMysteryGiftWfcStatus;
extern const char gStr_IPGE[];
extern const char gStr_K5WfPEw9T3cvqzHa[];
extern const char gMysteryGiftWfcEmptyString[];
extern u8 gMysteryGiftWfcFileList[];

// Allocator of the Wi-Fi library: 32-byte aligned blocks, the raw block is stored in the word before
static void MysteryGiftWfc_OnCleanupDone(void);
static void MysteryGiftWfc_OnRequestDone(int unused, int error);

static void *MysteryGiftWfc_Alloc(void *unused, u32 size) {
    void *raw;
    u32 result;
    size = ((size + 36) & ~31u) + 32;
    raw = Heap_Alloc(HEAP_ID_84, size);
    result = ((u32)raw + 32) & ~31u;
    *(void **)(result - 4) = raw;
    return (void *)result;
}

static void MysteryGiftWfc_Free(void *unused, void *ptr) {
    if (ptr != NULL) {
        Heap_Free(((void **)ptr)[-1]);
    }
}

// Shows the error of the Wi-Fi library (MysteryGiftApp_ShowWfcError)
static int MysteryGiftWfc_HandleError(MysteryGiftAppData *data) {
    s32 error[2];
    DWC_GetLastErrorEx(&error[0], &error[1]);
    data->wfcErrorMsgId = WifiConnection_ClassifyErrorCode(-error[0], error[1]);
    data->wfcErrorCode = -error[0];
    data->wfcErrorType = error[1];
    data->wfcErrorReady = TRUE;
    gMysteryGiftWfcStatus.errorShown = TRUE;
    data->wfcCallback = NULL;
    thunk_MysteryGiftApp_SetWaitingIconVisible(data, FALSE);
    return WFC_STATE_ERROR;
}

static BOOL MysteryGiftWfc_CheckInetStatus4(MysteryGiftAppData *data) {
    u8 buffer[60];
    switch (DWC_GetInetStatus()) {
    case 4:
        DWC_GetApInfo(buffer);
        return TRUE;
    case 7:
        break;
    case 8:
        break;
    }
    return FALSE;
}

// Waits for the request just started, then continues with nextState
static void MysteryGiftWfc_WaitForRequest(MysteryGiftAppData *data, int *state, int nextState) {
    gMysteryGiftWfcStatus.requestDone = FALSE;
    gMysteryGiftWfcStatus.requestError = 0;
    data->wfcNextState = nextState;
    *state = WFC_STATE_WAIT_REQUEST;
}

// Ends the download library with the given result, then continues with nextState (or failState at once)
static void MysteryGiftWfc_StartCleanup(MysteryGiftAppData *data, int result, int *state, int nextState, int failState) {
    gMysteryGiftWfcStatus.cleanupDone = FALSE;
    gMysteryGiftWfcStatus.result = result;
    data->wfcNextState = nextState;
    *state = WFC_STATE_WAIT_CLEANUP;
    if (!DWC_NdCleanupAsync(MysteryGiftWfc_OnCleanupDone)) {
        *state = failState;
    }
}

static void MysteryGiftWfc_OnRequestDone(int unused, int error) {
    gMysteryGiftWfcStatus.requestDone = TRUE;
    gMysteryGiftWfcStatus.requestError = error;
}

static void MysteryGiftWfc_OnCleanupDone(void) {
    gMysteryGiftWfcStatus.cleanupDone = TRUE;
}

static void MysteryGiftWfc_Shutdown(void) {
    WirelessStatusIcon_Destroy();
    CommState_FreeMysteryGiftWfcSession();
    UnloadOVY38();
    UnloadDwcOverlay();
    CommWireless_Terminate();
}

// One frame of the download; returns MYSTERY_GIFT_WFC_RESULT_* (0 while running)
int MysteryGiftWfc_Run(OverlayManager *manager, int *state) {
    MysteryGiftAppData *data = OverlayManager_GetData(manager);
    if (data->wfcCallback) {
        if (data->wfcCallback() == 1) {
            *state = MysteryGiftWfc_HandleError(data);
        }
    }
    switch (*state) {
    case WFC_STATE_LOAD_OVERLAYS:
        CommWireless_StartUp();
        LoadDwcOverlay();
        LoadOVY38();
        Comm_InitDwc(HEAP_ID_3);
        *state = WFC_STATE_WAIT_OVERLAYS;
        break;
    case WFC_STATE_WAIT_OVERLAYS:
        if (CommWireless_IsStartedUp()) {
            DWC_SetMemFunc(MysteryGiftWfc_Alloc, MysteryGiftWfc_Free);
            CommState_InitMysteryGiftWfcSession(data->saveData);
            *state = WFC_STATE_INIT;
        }
        break;
    case WFC_STATE_INIT:
        DWC_InitInetEx(data->wfcConfig, 2, 1, 20);
        DWC_SetAuthServer(2);
        DWC_ConnectInetAsync();
        WirelessStatusIcon_Create();
        *state = WFC_STATE_CONNECT;
        data->wfcCancel = FALSE;
        break;
    case WFC_STATE_CONNECT:
        DWC_ProcessInet();
        if (DWC_CheckInet()) {
            if (MysteryGiftWfc_CheckInetStatus4(data) == TRUE) {
                if (data->wfcCancel == TRUE) {
                    gMysteryGiftWfcStatus.result = MYSTERY_GIFT_WFC_RESULT_CANCELLED;
                    *state = WFC_STATE_DISCONNECT;
                } else {
                    *state = WFC_STATE_LOGIN;
                }
            } else {
                *state = MysteryGiftWfc_HandleError(data);
            }
        }
        if (gSystem.newKeys & PAD_BUTTON_B) {
            data->wfcCancel = TRUE;
        }
        break;
    case WFC_STATE_LOGIN:
        if (!DWC_NASLoginAsync()) {
            *state = MysteryGiftWfc_HandleError(data);
        } else {
            *state = WFC_STATE_WAIT_LOGIN;
        }
        break;
    case WFC_STATE_WAIT_LOGIN: {
        int result = DWC_NASLoginProcess();
        if (result == 3) {
            *state = WFC_STATE_INIT_DOWNLOAD;
            data->wfcCallback = DWC_UpdateConnection;
        } else if (result == 4) {
            *state = MysteryGiftWfc_HandleError(data);
            DWC_CleanupInet();
        } else if (result == 5) {
            gMysteryGiftWfcStatus.result = MYSTERY_GIFT_WFC_RESULT_CANCELLED;
            *state = WFC_STATE_DISCONNECT;
        }
        if (gSystem.newKeys & PAD_BUTTON_B) {
            DWC_NASLoginAbort();
        }
        break;
    }
    case WFC_STATE_INIT_DOWNLOAD:
        if (!DWC_NdInitAsync(MysteryGiftWfc_OnRequestDone, gStr_IPGE, gStr_K5WfPEw9T3cvqzHa)) { // "IPGE", the secret key
            *state = MysteryGiftWfc_HandleError(data);
        } else {
            MysteryGiftWfc_WaitForRequest(data, state, WFC_STATE_SET_ATTRIBUTES);
        }
        break;
    case WFC_STATE_SET_ATTRIBUTES:
        if (data->wfcCancel == TRUE) {
            MysteryGiftWfc_StartCleanup(data, MYSTERY_GIFT_WFC_RESULT_CANCELLED, state, WFC_STATE_CLEANUP, WFC_STATE_CLEANUP);
        } else {
            if (!DWC_NdSetAttr(gMysteryGiftWfcEmptyString, gMysteryGiftWfcEmptyString, gMysteryGiftWfcEmptyString)) { // ""
                *state = MysteryGiftWfc_HandleError(data);
            } else {
                *state = WFC_STATE_GET_FILE_COUNT;
            }
        }
        break;
    case WFC_STATE_GET_FILE_COUNT:
        if (!DWC_NdGetFileListNumAsync(&data->wfcFileCount)) {
            *state = MysteryGiftWfc_HandleError(data);
        } else {
            MysteryGiftWfc_WaitForRequest(data, state, WFC_STATE_GET_FILE_LIST);
        }
        break;
    case WFC_STATE_GET_FILE_LIST:
        if (data->wfcFileCount != 1) {
            MysteryGiftWfc_StartCleanup(data, MYSTERY_GIFT_WFC_RESULT_NO_GIFT, state, WFC_STATE_DISCONNECT, WFC_STATE_DISCONNECT);
        } else {
            if (!DWC_NdGetFileListAsync(gMysteryGiftWfcFileList, 0, 10)) {
                *state = MysteryGiftWfc_HandleError(data);
            } else {
                MysteryGiftWfc_WaitForRequest(data, state, WFC_STATE_GET_FILE);
            }
        }
        break;
    case WFC_STATE_GET_FILE:
        if (!DWC_NdGetFileAsync(gMysteryGiftWfcFileList, data->wfcRecvBuffer, sizeof(data->wfcRecvBuffer))) {
            *state = MysteryGiftWfc_HandleError(data);
        } else {
            *state = WFC_STATE_DOWNLOADING;
            data->wfcProgress = 0;
        }
        break;
    case WFC_STATE_DOWNLOADING:
        if (!gMysteryGiftWfcStatus.requestDone) {
            if (gSystem.newKeys & PAD_BUTTON_B) {
                MysteryGiftWfc_StartCleanup(data, MYSTERY_GIFT_WFC_RESULT_CANCELLED, state, WFC_STATE_CLEANUP, WFC_STATE_CLEANUP);
            } else if (DWC_NdGetProgress(&data->wfcBytesReceived, &data->wfcBytesTotal) == 1) {
                u32 progress = 100 * data->wfcBytesReceived / data->wfcBytesTotal;
                if (data->wfcProgress != progress) {
                    data->wfcProgress = progress;
                }
            }
        } else {
            if (gMysteryGiftWfcStatus.requestError) {
                *state = MysteryGiftWfc_HandleError(data);
            } else if (!data->wfcCancel) {
                MysteryGiftWfc_StartCleanup(data, MYSTERY_GIFT_WFC_RESULT_RECEIVED, state, WFC_STATE_DISCONNECT, WFC_STATE_DISCONNECT);
            } else {
                MysteryGiftWfc_StartCleanup(data, MYSTERY_GIFT_WFC_RESULT_CANCELLED, state, WFC_STATE_DISCONNECT, WFC_STATE_DISCONNECT);
            }
        }
        break;
    case WFC_STATE_CLEANUP:
        if (!DWC_NdCancelAsync()) {
            *state = WFC_STATE_DISCONNECT;
        } else {
            data->wfcCallback = NULL;
            MysteryGiftWfc_Shutdown();
            return gMysteryGiftWfcStatus.result;
        }
        break;
    case WFC_STATE_DISCONNECT:
        if (DWC_CleanupInetAsync() == 1) {
            data->wfcCallback = NULL;
            MysteryGiftWfc_Shutdown();
            return gMysteryGiftWfcStatus.result;
        }
        break;
    case WFC_STATE_ERROR:
        if (gMysteryGiftWfcStatus.errorShown == TRUE) {
            MysteryGiftApp_ShowWfcError(data);
            if (data->wfcErrorType == 5 || data->wfcErrorType == 6) {
                MysteryGiftWfc_StartCleanup(data, MYSTERY_GIFT_WFC_RESULT_CANCELLED, state, WFC_STATE_ERROR_SHOWN, WFC_STATE_WAIT_BUTTON);
            } else {
                *state = WFC_STATE_ERROR_SHOWN;
            }
        }
        break;
    case WFC_STATE_ERROR_SHOWN:
        DWC_CleanupInet();
        *state = WFC_STATE_WAIT_BUTTON;
        break;
    case WFC_STATE_WAIT_BUTTON:
        if (gSystem.newKeys & PAD_BUTTON_A) {
            data->wfcCallback = NULL;
            DWC_ClearError();
            MysteryGiftWfc_Shutdown();
            return MYSTERY_GIFT_WFC_RESULT_ERROR;
        }
        break;
    case WFC_STATE_WAIT_REQUEST:
        if (gMysteryGiftWfcStatus.requestDone == TRUE) {
            gMysteryGiftWfcStatus.requestDone = FALSE;
            if (gMysteryGiftWfcStatus.requestError) {
                *state = MysteryGiftWfc_HandleError(data);
            } else {
                *state = data->wfcNextState;
            }
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            data->wfcCancel = TRUE;
        }
        break;
    case WFC_STATE_WAIT_CLEANUP:
        if (gMysteryGiftWfcStatus.cleanupDone == TRUE) {
            gMysteryGiftWfcStatus.cleanupDone = FALSE;
            *state = data->wfcNextState;
        } else if (gSystem.newKeys & PAD_BUTTON_B) {
            data->wfcCancel = TRUE;
        }
        break;
    }
    return 0;
}
