#include "wireless_manager.h"

#include <nitro/wm/wm_internal.h>
#include <stddef.h>
#include <string.h>

#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_command.h"
#include "global.h"

// Local wireless manager: drives the WM library for the communication layer. Every request is asynchronous: the
// state is WIRELESS_STATE_BUSY until its callback arrives.

#define WM_CopyBssid16(src, dst)                     \
    {                                                \
        ((u16 *)(dst))[2] = ((const u16 *)(src))[2]; \
        ((u16 *)(dst))[1] = ((const u16 *)(src))[1]; \
        ((u16 *)(dst))[0] = ((const u16 *)(src))[0]; \
    }

typedef void (*WirelessReceiveFunc)(u16 aid, void *data, u16 length);

// Common head of the WM callback arguments.
typedef struct WirelessEvent {
    u16 apiid;
    u16 errcode;
    u16 state;
} WirelessEvent;

// WM_StartParent callback argument.
typedef struct WirelessParentEvent {
    u16 apiid;
    u16 errcode;
    u8 unk_04[4];
    u16 state; // 0 parent started, 2 beacon sent, 7 child connected, 9 child disconnected
    u8 unk_0A[6];
    u16 aid;
    u8 unk_12[2];
    u8 connectData[4]; // the child's WM_StartConnectEx data
} WirelessParentEvent;

// WM_StartConnectEx callback argument.
typedef struct WirelessConnectEvent {
    u16 apiid;
    u16 errcode;
    u8 unk_04[4];
    u16 state; // 7 connected, 9 disconnected
    u16 aid;
} WirelessConnectEvent;

// WM_SetMPDataToPortEx callback argument.
typedef struct WirelessSendEvent {
    u16 apiid;
    u16 errcode;
    u8 unk_04[0x1C];
    WirelessSentFunc callback; // the request's argument
} WirelessSendEvent;

// The work buffer (Wireless_Init aligns it to 32 bytes; Wireless_GetWorkSize).
typedef struct WirelessWork {
    WmParentParam parentParam;
    u8 systemBuffer[0xF00];  // WM_Initialize
    u8 sendBuffer[0xE0];     // MP send buffer
    u8 receiveBuffer[0x200]; // MP receive buffer
    union {
        WMBssDesc bssDesc;
        u16 data[0x60];
    } parentInfo; // the parent found by the scan / connected to
    WmScanParam scanParam;
    u8 unk_12F0[0x10];
    void (*parentFoundCallback)(void *parentInfo);
    u32 sendBufferSize;
    u32 receiveBufferSize;
    u16 scanChannel; // 0: every allowed channel in turn
    u16 connectAfterScan;
    u32 state; // WIRELESS_STATE_*
    u32 mode;  // 0, 2, 4 parent; 1, 3, 5 child
    WirelessReceiveFunc receiveCallback;
    u32 unk_131C;
    void (*beaconCallback)(u32 ggid, u8 info); // every beacon seen while scanning
    void (*childLeftCallback)(u16 aid);
    void (*childJoinedCallback)(u16 aid);
    u16 aid;             // own AID (0: parent)
    u16 connectedBitmap; // bit per connected AID, the parent included
    u32 error;
    u8 maxEntries;
    u8 connectBlocked;
    u8 unk_1336[2];
    u32 random;
    u16 channel;
    u16 minBusyRatio;
    u16 quietChannels; // channels with minBusyRatio
    u8 entryLocked;
    u8 entryClosed;
    u8 entrySet;
    u8 beaconCount;
    u8 unk_1346[0x3A];
} WirelessWork;

typedef char WirelessWorkSizeCheck[sizeof(WirelessWork) == 0x1380 ? 1 : -1];
typedef char WirelessWorkStateCheck[offsetof(WirelessWork, state) == 0x1310 ? 1 : -1];
typedef char WirelessWorkBeaconCheck[offsetof(WirelessWork, beaconCount) == 0x1345 ? 1 : -1];

typedef struct WirelessManager {
    u32 unk_0;
    WirelessWork *work;
} WirelessManager;

static void Wireless_SetState(int state);
static void Wireless_SetError(int error);
static BOOL Wireless_SendParentParameter(void);
static void Wireless_OnParentParameterSet(void *arg);
static BOOL Wireless_StartParentRun(void);
static void Wireless_OnParentEvent(void *arg);
static BOOL Wireless_StartParentMP(void);
static void Wireless_OnParentMPEvent(void *arg);
static BOOL Wireless_EndParent(void);
static void Wireless_OnParentMPEnded(void *arg);
static BOOL Wireless_EndParentRun(void);
static void Wireless_OnParentEnded(void *arg);
static BOOL Wireless_ScanNextChannel(void);
static void Wireless_OnScanEvent(void *input);
static BOOL Wireless_EndScan(void);
static void Wireless_OnScanEnded(void *arg);
static BOOL Wireless_StartConnect(void);
static void Wireless_OnConnectEvent(void *arg);
static BOOL Wireless_StartChildMP(void);
static void Wireless_OnChildMPEvent(void *arg);
static BOOL Wireless_EndChild(void);
static void Wireless_OnChildMPEnded(void *arg);
static BOOL Wireless_Disconnect(void);
static void Wireless_OnDisconnected(void *arg);
static BOOL Wireless_Reset(void);
static void Wireless_OnReset(void *arg);
static BOOL Wireless_SetSendData(const void *data, u16 length, int port, WirelessSentFunc callback);
static void Wireless_OnDataSent(void *arg);
static void Wireless_OnPortEvent(void *arg);
static void Wireless_OnEnded(void *arg);
static u16 Wireless_CountConnected(void);
static u16 Wireless_MeasureFromChannel(u16 channel);
static void Wireless_OnChannelMeasured(void *arg);
static int Wireless_MeasureChannel(WmCallback callback, u16 channel);
static s16 Wireless_PickChannel(u16 channels);
static void Wireless_OnIndication(void *arg);
static BOOL Wireless_Initialize(int mode);
static void Wireless_OnInitialized(void *arg);
static void Wireless_OnLifeTimeSet(void *arg);
static void Wireless_ForceReset(void);
static void Wireless_OnEntrySet(void *arg);

static WirelessManager sWirelessManager;

static u8 sWirelessConnectTag[3] = "DP";

static void Wireless_SetState(int state) {
    sWirelessManager.work->state = state;
}

static void Wireless_SetError(int error) {
    int state = sWirelessManager.work->state;
    if ((u32)(state - WIRELESS_STATE_ERROR) > 1) {
        sWirelessManager.work->error = error;
    }
}

static BOOL Wireless_SendParentParameter(void) {
    int result;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    result = WM_SetParentParameter(Wireless_OnParentParameterSet, &sWirelessManager.work->parentParam);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnParentParameterSet(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
        Wireless_SetState(WIRELESS_STATE_ERROR);
    } else if (!Wireless_StartParentRun()) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
    }
}

static BOOL Wireless_StartParentRun(void) {
    u8 *status;
    int result;
    if ((u32)(sWirelessManager.work->state - WIRELESS_STATE_MP) <= 2) {
        return TRUE;
    }
    status = (u8 *)WMi_GetStatusAddress();
    DC_InvalidateRange(status + 0x198, 4);
    *(u32 *)(status + 0x198) = 0;
    DC_FlushRange(status + 0x198, 4);
    result = WM_StartParent(Wireless_OnParentEvent);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    sWirelessManager.work->aid = 0;
    sWirelessManager.work->connectedBitmap = 1;
    return TRUE;
}

// A child connecting is refused when entry is locked or closed, the parent is full, or its connect data
// (CommState_GetLinkMode(), sWirelessConnectTag) differ from ours.
static void Wireless_OnParentEvent(void *arg) {
    WirelessParentEvent *event = arg;
    u16 mask = 1 << event->aid;
    if (event->errcode) {
        Wireless_SetError(event->errcode);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return;
    }
    switch (event->state) {
    case 2:
        sWirelessManager.work->beaconCount++;
        break;
    case 7:
        if (sWirelessManager.work->entryClosed == 1 || sWirelessManager.work->entryLocked == 1 || Wireless_CountConnected() >= sWirelessManager.work->maxEntries || event->connectData[0] != CommState_GetLinkMode() || memcmp(sWirelessConnectTag, &event->connectData[1], 3) != 0) {
            int result = WM_Disconnect(NULL, event->aid);
            if (result != WM_ERRCODE_OPERATING) {
                Wireless_SetError(result);
                Wireless_SetState(WIRELESS_STATE_ERROR);
            }
        } else {
            sWirelessManager.work->connectedBitmap |= mask;
            if (sWirelessManager.work->childJoinedCallback) {
                sWirelessManager.work->childJoinedCallback(event->aid);
            }
        }
        break;
    case 9:
        sWirelessManager.work->connectedBitmap &= ~mask;
        if (sWirelessManager.work->childLeftCallback) {
            sWirelessManager.work->childLeftCallback(event->aid);
        }
        break;
    case 0:
        if (!Wireless_StartParentMP()) {
            Wireless_SetState(WIRELESS_STATE_ERROR);
        }
        break;
    case 26:
        break;
    }
}

static BOOL Wireless_StartParentMP(void) {
    WirelessWork *work;
    int result;

    if ((u32)(sWirelessManager.work->state - WIRELESS_STATE_MP) <= 2) {
        return TRUE;
    }
    Wireless_SetState(WIRELESS_STATE_MP);
    work = sWirelessManager.work;
    result = WM_StartMP(Wireless_OnParentMPEvent,
        work->receiveBuffer,
        (u16)work->receiveBufferSize,
        work->sendBuffer,
        (u16)work->sendBufferSize,
        1);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnParentMPEvent(void *arg) {
    WirelessEvent *event = arg;
    u16 error = event->errcode;
    u16 state;

    if (error != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(error);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return;
    }
    state = event->state;
    switch (state) {
    case 10:
        if (sWirelessManager.work->mode == 2) {
            if (sWirelessManager.work->state != WIRELESS_STATE_MP) {
                if (sWirelessManager.work->state == WIRELESS_STATE_CHILD) {
                    break;
                }
            }
        }
        Wireless_SetState(WIRELESS_STATE_MP);
        break;
    case 11:
    case 12:
    case 13:
    default:
        break;
    }
}

static BOOL Wireless_EndParent(void) {
    int result;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    result = WM_EndMP(Wireless_OnParentMPEnded);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnParentMPEnded(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
        Wireless_ForceReset();
    } else if (!Wireless_EndParentRun()) {
        Wireless_ForceReset();
    }
}

static BOOL Wireless_EndParentRun(void) {
    int result = WM_EndParent(Wireless_OnParentEnded);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnParentEnded(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
    } else {
        Wireless_SetState(WIRELESS_STATE_IDLE);
    }
}

// Scans for the parent with address bssid (on channel, or every allowed channel when 0), then connects to it.
BOOL Wireless_ScanAndConnect(int mode, const u16 *bssid, u16 channel) {
    sWirelessManager.work->receiveBufferSize = 0x200;
    sWirelessManager.work->sendBufferSize = 0x40;
    Wireless_SetState(WIRELESS_STATE_SCANNING);
    sWirelessManager.work->parentInfo.bssDesc.channel = 1;
    WM_CopyBssid16(bssid, sWirelessManager.work->scanParam.address);
    sWirelessManager.work->mode = mode;
    sWirelessManager.work->parentFoundCallback = NULL;
    sWirelessManager.work->scanChannel = channel;
    sWirelessManager.work->scanParam.channel = 0;
    sWirelessManager.work->connectAfterScan = 1;
    if (!Wireless_ScanNextChannel()) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

// Scans for parents; callback gets each one found.
BOOL Wireless_StartScan(void *callback, const u16 *bssid, u16 channel) {
    Wireless_SetState(WIRELESS_STATE_SCANNING);
    sWirelessManager.work->parentFoundCallback = callback;
    sWirelessManager.work->scanChannel = channel;
    sWirelessManager.work->scanParam.channel = 0;
    sWirelessManager.work->connectAfterScan = 0;
    WM_CopyBssid16(bssid, sWirelessManager.work->scanParam.address);
    if (!Wireless_ScanNextChannel()) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

#pragma optimization_level 2
#pragma opt_common_subs off

static BOOL Wireless_ScanNextChannel(void) {
    int error;
    u16 channels = WM_GetAllowedChannel();
    if (channels == 0x8000) {
        Wireless_SetError(3);
        CommState_SetError(1);
        return FALSE;
    }
    if (channels == 0) {
        Wireless_SetError(22);
        CommState_SetError(1);
        return FALSE;
    }
    if (sWirelessManager.work->scanChannel == 0) {
        for (;;) {
            sWirelessManager.work->scanParam.channel++;
            if (sWirelessManager.work->scanParam.channel > 16) {
                sWirelessManager.work->scanParam.channel = 1;
            }
            if (channels & (1u << (sWirelessManager.work->scanParam.channel - 1))) {
                break;
            }
        }
    } else {
        sWirelessManager.work->scanParam.channel = sWirelessManager.work->scanChannel;
    }
    sWirelessManager.work->scanParam.time = WM_GetDispersionScanPeriod() / 3;
    sWirelessManager.work->scanParam.buffer = &sWirelessManager.work->parentInfo;
    error = WM_StartScan(Wireless_OnScanEvent, &sWirelessManager.work->scanParam);
    if (error != WM_ERRCODE_OPERATING) {
        Wireless_SetError(error);
        return FALSE;
    }
    return TRUE;
}

#pragma opt_common_subs reset
#pragma optimization_level reset

// WM_StartScan callback argument.
typedef struct WirelessScanEvent {
    u16 apiid;
    u16 errcode;
    u8 unk_04[4];
    u16 state; // 3 nothing found, 4 channel done, 5 parent found
    u8 unk_0A[0x2C];
    u16 gameInfoLength;
    u8 unk_38[4];
    u32 ggid;
    u8 unk_40[3];
    u8 attribute;
    u8 unk_44[4];
    u8 gameInfo[5];
} WirelessScanEvent;

#pragma opt_propagation off

static void Wireless_OnScanEvent(void *input) {
    WirelessScanEvent *event = input;
    WirelessWork *work;
    u16 errcode = event->errcode;

    if (errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(errcode);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return;
    }
    work = sWirelessManager.work;
    if (work->state != WIRELESS_STATE_SCANNING) {
        work->connectAfterScan = 0;
        if (!Wireless_EndScan()) {
            Wireless_SetState(WIRELESS_STATE_ERROR);
        }
        return;
    }
    switch (event->state) {
    case 3:
        return;
    case 5:
        DC_InvalidateRange(&work->parentInfo, sizeof(work->parentInfo));
        work = sWirelessManager.work;
        if (work->beaconCallback != NULL && event->gameInfoLength >= 8) {
            u8 *gameInfo = event->gameInfo;
            work->beaconCallback(event->ggid, gameInfo[4]);
        }
        if (event->gameInfoLength >= 8) {
            work = sWirelessManager.work;
            if (event->ggid == work->parentParam.ggid && (event->attribute & 3) == 1) {
                if (work->parentFoundCallback != NULL) {
                    work->parentFoundCallback(&work->parentInfo);
                }
                work = sWirelessManager.work;
                if (work->connectAfterScan != 0) {
                    if (!Wireless_EndScan()) {
                        Wireless_SetState(WIRELESS_STATE_ERROR);
                    }
                    return;
                }
            }
        }
        break;
    case 4:
    default:
        break;
    }
    if (!Wireless_ScanNextChannel()) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
    }
}

#pragma opt_propagation reset

// The scan callback ends the scan once the state left WIRELESS_STATE_SCANNING.
BOOL Wireless_StopScan(void) {
    if (sWirelessManager.work->state != WIRELESS_STATE_SCANNING) {
        return FALSE;
    }
    Wireless_SetState(WIRELESS_STATE_BUSY);
    return TRUE;
}

static BOOL Wireless_EndScan(void) {
    int result = WM_EndScan(Wireless_OnScanEnded);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnScanEnded(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
        return;
    }
    Wireless_SetState(WIRELESS_STATE_IDLE);
    if (sWirelessManager.work->connectAfterScan != 0 && !Wireless_StartConnect()) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
    }
}

// Connects to the parent in parentInfo; the connect data are CommState_GetLinkMode() and sWirelessConnectTag.
static BOOL Wireless_StartConnect(void) {
    u8 data[0x20];
    int result;
    if ((u32)(sWirelessManager.work->state - WIRELESS_STATE_MP) <= 2) {
        return TRUE;
    }
    Wireless_SetState(WIRELESS_STATE_BUSY);
    MI_CpuCopy8(sWirelessConnectTag, data + 1, 3);
    data[0] = CommState_GetLinkMode();
    result = WM_StartConnectEx(Wireless_OnConnectEvent, sWirelessManager.work->parentInfo.data, data, 1, 0);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnConnectEvent(void *arg) {
    WirelessConnectEvent *event = arg;
    u16 code;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
        if (event->errcode == WM_ERRCODE_OVER_MAX_ENTRY) {
            Wireless_SetState(WIRELESS_STATE_ERROR);
            return;
        }
        if (event->errcode == WM_ERRCODE_NO_ENTRY) {
            Wireless_SetState(WIRELESS_STATE_ERROR);
            return;
        }
        if (event->errcode == WM_ERRCODE_FAILED) {
            if (CommState_ReportsErrors()) {
                Wireless_SetState(WIRELESS_STATE_ERROR);
                return;
            }
            Wireless_SetState(WIRELESS_STATE_8);
            return;
        }
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return;
    }
    code = event->state;
    if (code == 8) {
        return;
    }
    if (code == 7) {
        WirelessWork *work = sWirelessManager.work;
        if (work->connectBlocked) {
            Wireless_SetError(20);
            Wireless_SetState(WIRELESS_STATE_ERROR);
            return;
        }
        Wireless_SetState(WIRELESS_STATE_MP);
        if (!Wireless_StartChildMP()) {
            Wireless_SetState(WIRELESS_STATE_BUSY);
            return;
        }
        sWirelessManager.work->aid = event->aid;
        return;
    }
    if (code == 6) {
        return;
    }
    if (code == 9) {
        Wireless_SetError(20);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return;
    }
    if (code == 26) {
        return;
    }
    Wireless_SetState(WIRELESS_STATE_ERROR);
}

static BOOL Wireless_StartChildMP(void) {
    WirelessWork *work = sWirelessManager.work;
    int result = WM_StartMP(Wireless_OnChildMPEvent, work->receiveBuffer, (u16)work->receiveBufferSize, work->sendBuffer, (u16)work->sendBufferSize, 1);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnChildMPEvent(void *arg) {
    WirelessEvent *event = arg;
    u16 error = event->errcode;
    u16 state;
    if (error != WM_ERRCODE_SUCCESS) {
        if (error == WM_ERRCODE_SEND_FAILED || error == WM_ERRCODE_TIMEOUT || error == WM_ERRCODE_INVALID_POLLBITMAP) {
            return;
        }
        Wireless_SetError(error);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return;
    }
    state = event->state;
    switch (state) {
    case 10:
        if (sWirelessManager.work->mode != 3 || sWirelessManager.work->state != WIRELESS_STATE_CHILD) {
            Wireless_SetState(WIRELESS_STATE_MP);
        }
        break;
    case 11:
    case 12:
    case 13:
    default:
        break;
    }
}

static BOOL Wireless_EndChild(void) {
    int result;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    result = WM_EndMP(Wireless_OnChildMPEnded);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnChildMPEnded(void *arg) {
    WirelessEvent *event = arg;
    u16 error = event->errcode;
    if (error != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(error);
        Wireless_Stop();
    } else if (!Wireless_Disconnect()) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
    }
}

static BOOL Wireless_Disconnect(void) {
    int result;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    result = WM_Disconnect(Wireless_OnDisconnected, 0);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        Wireless_ForceReset();
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnDisconnected(void *arg) {
    WirelessEvent *event = arg;
    u16 error = event->errcode;
    if (error != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(error);
    } else {
        Wireless_SetState(WIRELESS_STATE_IDLE);
    }
}

static BOOL Wireless_Reset(void) {
    int result;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    result = WM_Reset(Wireless_OnReset);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnReset(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
        Wireless_SetError(event->errcode);
    } else {
        Wireless_SetState(WIRELESS_STATE_IDLE);
    }
}

// Sends data to every AID on port; callback (the request's argument) learns whether it was sent.
static BOOL Wireless_SetSendData(const void *data, u16 length, int port, WirelessSentFunc callback) {
    WMErrCode result;
    DC_FlushRange(sWirelessManager.work->sendBuffer, sWirelessManager.work->sendBufferSize);
    result = WM_SetMPDataToPortEx(Wireless_OnDataSent, (void *)callback, data, length, 0xFFFF, port, 2);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    return FALSE;
}

static void Wireless_OnDataSent(void *arg) {
    WirelessSendEvent *event = arg;
    u16 error = event->errcode;
    if (error != WM_ERRCODE_SUCCESS && error != WM_ERRCODE_SEND_FAILED) {
        Wireless_SetError(error);
        return;
    }
    if (event->callback != NULL) {
        (event->callback)(error == WM_ERRCODE_SUCCESS);
    }
}

static void Wireless_OnPortEvent(void *arg) {
    WmPortEvent *event = arg;
    u16 error = event->errcode;
    WirelessReceiveFunc callback;
    if (error != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(error);
        return;
    }
    callback = sWirelessManager.work->receiveCallback;
    if (callback == NULL) {
        return;
    }
    if (event->state == WM_EVENT_PORT_INIT) {
        return;
    }
    if (event->state == WM_EVENT_PORT_RECEIVE) {
        callback(event->aid, event->data, event->length);
    } else if (event->state == WM_EVENT_DISCONNECTED) {
        callback(event->aid, NULL, 0);
    }
}

void WVR_TerminateAsync(void (*callback)(void *), void *arg);

static void Wireless_OnEnded(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetState(WIRELESS_STATE_FATAL);
    } else {
        WVR_TerminateAsync(NULL, NULL);
        Wireless_SetState(WIRELESS_STATE_STOPPED);
    }
}

void Wireless_SetGgid(u32 ggid) {
    sWirelessManager.work->parentParam.ggid = ggid;
}

void Wireless_SetParentGameInfo(void *gameInfo, u16 length) {
    sWirelessManager.work->parentParam.gameInfo = gameInfo;
    sWirelessManager.work->parentParam.gameInfoLength = length;
}

u16 Wireless_GetConnectedBitmap(void) {
    return sWirelessManager.work->connectedBitmap;
}

static u16 Wireless_CountConnected(void) {
    int count = 0;
    int i = count;
    u16 bits = sWirelessManager.work->connectedBitmap;
    for (; i < 16; i++) {
        if (bits & 1) {
            count++;
        }
        bits >>= 1;
    }
    return count;
}

u32 Wireless_GetState(void) {
    return sWirelessManager.work->state;
}

u32 Wireless_GetError(void) {
    return sWirelessManager.work->error;
}

// WM_MeasureChannel callback argument.
typedef struct WirelessMeasureEvent {
    u16 apiid;
    u16 errcode;
    u16 unk_04;
    u16 unk_06;
    u16 channel;
    u16 busyRatio;
} WirelessMeasureEvent;

// Measures how busy every allowed channel is (WIRELESS_STATE_MEASURED when done).
BOOL Wireless_StartMeasureChannels(void) {
    u8 macAddress[6];
    u32 seed;
    u16 ret;

    OS_GetMacAddress(macAddress);
    seed = *(u32 *)0x027FFC3C;
    seed = ((u16 *)macAddress)[2] + (((u16 *)macAddress)[1] + (((u16 *)macAddress)[0] + seed));
    sWirelessManager.work->random = seed;
    sWirelessManager.work->random = sWirelessManager.work->random * 0x10DCD + 0x3039;
    sWirelessManager.work->channel = 0;
    sWirelessManager.work->minBusyRatio = 101;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    ret = Wireless_MeasureFromChannel(1);
    if (ret == 0x18) {
        Wireless_SetError(0x18);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        CommState_SetError(1);
        return FALSE;
    }
    if (ret != WM_ERRCODE_OPERATING) {
        Wireless_SetError(ret);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

// Measures the first allowed channel from channel on; 0x18 when there is none.
static u16 Wireless_MeasureFromChannel(u16 channel) {
    int allowed;

    allowed = WM_GetAllowedChannel();
    if (allowed == 0x8000) {
        Wireless_SetError(3);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        CommState_SetError(1);
        return 3;
    }
    if (allowed == 0) {
        Wireless_SetError(0x16);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        CommState_SetError(1);
        return 0x18;
    }
    while (!((1 << (channel - 1)) & allowed)) {
        channel++;
        if (channel > 16) {
            return 0x18;
        }
    }
    return (u16)Wireless_MeasureChannel(Wireless_OnChannelMeasured, channel);
}

static void Wireless_OnChannelMeasured(void *arg) {
    WirelessMeasureEvent *event = arg;
    u16 channel;
    u16 ratio;
    u16 ret;

    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
        Wireless_SetState(WIRELESS_STATE_ERROR);
        CommState_SetError(1);
        return;
    }
    channel = event->channel;
    ratio = event->busyRatio;
    if (sWirelessManager.work->minBusyRatio > ratio) {
        sWirelessManager.work->minBusyRatio = ratio;
        sWirelessManager.work->quietChannels = 1 << (channel - 1);
    } else if (sWirelessManager.work->minBusyRatio == ratio) {
        sWirelessManager.work->quietChannels |= 1 << (channel - 1);
    }
    ret = Wireless_MeasureFromChannel((u16)(channel + 1));
    if (ret == 0x18) {
        Wireless_SetState(WIRELESS_STATE_MEASURED);
        return;
    }
    if (ret != WM_ERRCODE_OPERATING) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
    }
}

static int Wireless_MeasureChannel(WmCallback callback, u16 channel) {
    return WM_MeasureChannel(callback, 3, 0x11, channel, 30);
}

// Picks one of the least busy channels.
u16 Wireless_SelectChannel(void) {
    Wireless_SetState(WIRELESS_STATE_IDLE);
    sWirelessManager.work->channel = Wireless_PickChannel(sWirelessManager.work->quietChannels);
    return sWirelessManager.work->channel;
}

// A random channel of the bitmap channels (1-16).
static s16 Wireless_PickChannel(u16 channels) {
    s16 result = 0, i;
    u16 count = 0;
    for (i = 0; i < 16; i++) {
        if (channels & (1 << i)) {
            result = i + 1;
            count++;
        }
    }
    if (count > 1) {
        u16 selected;
        sWirelessManager.work->random = sWirelessManager.work->random * 0x10dcd + 0x3039;
        selected = (count * ((u8)sWirelessManager.work->random)) >> 8;
        for (i = 0; i < 16; i++) {
            if (channels & 1) {
                if (selected == 0) {
                    return i + 1;
                }
                selected--;
            }
            channels >>= 1;
        }
        return 0;
    }
    return result;
}

// buffer: Wireless_GetWorkSize() bytes + 32 for the alignment. mode 1: WM_Initialize, else for listening only.
BOOL Wireless_Init(void *buffer, int mode) {
    u32 p = (u32)buffer;
    u32 mod;

    mod = p << 27;
    mod = mod >> 27;
    if (mod != 0) {
        p += 32 - mod;
    }
    sWirelessManager.work = (WirelessWork *)p;
    sWirelessManager.work->receiveBufferSize = 0;
    sWirelessManager.work->sendBufferSize = 0;
    sWirelessManager.work->receiveCallback = NULL;
    sWirelessManager.work->aid = 0;
    sWirelessManager.work->connectedBitmap = 1;
    sWirelessManager.work->error = 0;
    sWirelessManager.work->state = WIRELESS_STATE_STOPPED;
    sWirelessManager.work->parentParam.gameInfo = NULL;
    sWirelessManager.work->parentParam.gameInfoLength = 0;
    sWirelessManager.work->unk_131C = 0;
    sWirelessManager.work->maxEntries = 8;
    sWirelessManager.work->connectBlocked = 0;
    sWirelessManager.work->entryLocked = 0;
    if (!Wireless_Initialize(mode)) {
        return FALSE;
    }
    return TRUE;
}

u32 Wireless_GetWorkSize(void) {
    return sizeof(WirelessWork);
}

static void Wireless_OnIndication(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode == WM_ERRCODE_FIFO_ERROR) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
        Wireless_SetError(25);
    }
}

static BOOL Wireless_Initialize(int mode) {
    int result;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    if (mode == 1) {
        result = WM_Initialize(sWirelessManager.work->systemBuffer, Wireless_OnInitialized, 2);
    } else {
        result = WM_InitializeForListening(sWirelessManager.work->systemBuffer, Wireless_OnInitialized, 2, FALSE);
    }
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_SetError(result);
        Wireless_SetState(WIRELESS_STATE_FATAL);
        return FALSE;
    }
    return TRUE;
}

static void Wireless_OnInitialized(void *arg) {
    WirelessEvent *event = arg;
    int result;
    if (event->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(event->errcode);
        Wireless_SetState(WIRELESS_STATE_FATAL);
        CommState_SetError(5);
        return;
    }
    result = WM_SetIndCallback(Wireless_OnIndication);
    if (result != WM_ERRCODE_SUCCESS) {
        Wireless_SetError(result);
        Wireless_SetState(WIRELESS_STATE_FATAL);
        CommState_SetError(5);
        return;
    }
    Wireless_SetState(WIRELESS_STATE_IDLE);
}

static void Wireless_OnLifeTimeSet(void *arg) {
}

// Starts a parent (mode 0, 2 or 4).
BOOL Wireless_StartParent(int mode, u16 tgid, u16 channel, u16 maxEntry, u16 beaconPeriod, u32 entryFlag) {
    u16 value;
    if (Comm_IsCommClubLinkMode(CommState_GetLinkMode())) {
        WM_SetLifeTime(Wireless_OnLifeTimeSet, 0xFFFF, 100, 5, 100);
    }
    sWirelessManager.work->receiveBufferSize = 0x1C0;
    sWirelessManager.work->sendBufferSize = 0xE0;
    sWirelessManager.work->mode = mode;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    sWirelessManager.work->parentParam.tgid = tgid;
    sWirelessManager.work->parentParam.channel = channel;
    sWirelessManager.work->parentParam.beaconPeriod = beaconPeriod;
    switch (mode) {
    case 0:
        sWirelessManager.work->parentParam.parentMaxSize = 0xC0;
        if (maxEntry >= 5) {
            sWirelessManager.work->parentParam.childMaxSize = 0xC;
        } else {
            sWirelessManager.work->parentParam.childMaxSize = 0x26;
        }
        break;
    case 4:
        sWirelessManager.work->parentParam.parentMaxSize = 0x64;
        sWirelessManager.work->parentParam.childMaxSize = 0xC;
        break;
    }
    sWirelessManager.work->parentParam.maxEntry = maxEntry;
    value = 0;
    sWirelessManager.work->parentParam.CS_Flag = value;
    sWirelessManager.work->parentParam.multiBootFlag = value;
    sWirelessManager.work->parentParam.entryFlag = entryFlag;
    if (mode == 2) {
        value = 1;
    }
    sWirelessManager.work->parentParam.KS_Flag = value;
    if (mode == 0 || mode == 2 || mode == 4) {
        return Wireless_SendParentParameter();
    }
    return FALSE;
}

// Connects as a child (mode 1, 3 or 5) to the parent described by parentInfo.
BOOL Wireless_StartChild(int mode, const void *parentInfo) {
    if (Comm_IsCommClubLinkMode(CommState_GetLinkMode())) {
        WM_SetLifeTime(Wireless_OnLifeTimeSet, 0xFFFF, 100, 5, 100);
    }
    sWirelessManager.work->receiveBufferSize = 0x200;
    sWirelessManager.work->sendBufferSize = 0x40;
    sWirelessManager.work->mode = mode;
    Wireless_SetState(WIRELESS_STATE_BUSY);
    if (mode == 1 || mode == 3 || mode == 5) {
        MI_CpuCopy8(parentInfo, &sWirelessManager.work->parentInfo, sizeof(sWirelessManager.work->parentInfo));
        DC_FlushRange(&sWirelessManager.work->parentInfo, sizeof(sWirelessManager.work->parentInfo));
        DC_WaitWriteBufferEmpty();
        return Wireless_StartConnect();
    }
    return FALSE;
}

void Wireless_SetReceiveCallback(void *callback, int port) {
    WMErrCode result;
    sWirelessManager.work->receiveCallback = callback;
    result = WM_SetPortCallback((u16)port, Wireless_OnPortEvent, NULL);
    if (result != WM_ERRCODE_SUCCESS) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
        for (;;) {}
    }
}

// A parent sends only while a child is connected.
BOOL Wireless_SendData(const void *data, u16 length, int port, WirelessSentFunc callback) {
    if (Wireless_GetAid() == 0) {
        if ((Wireless_GetConnectedBitmap() & 0xFE) == 0) {
            return FALSE;
        }
    }
    return Wireless_SetSendData(data, length, port, callback);
}

static void Wireless_ForceReset(void) {
    if (sWirelessManager.work->state == WIRELESS_STATE_SCANNING) {
        for (;;) {}
    }
    if (!Wireless_Reset()) {
        Wireless_SetState(WIRELESS_STATE_FATAL);
    }
}

// Ends MP communication and the parent / the connection.
void Wireless_Stop(void) {
    u32 state = sWirelessManager.work->state;
    if (state == WIRELESS_STATE_IDLE) {
        return;
    }
    if (state != WIRELESS_STATE_CHILD && state != WIRELESS_STATE_5 && state != WIRELESS_STATE_MP) {
        Wireless_SetState(WIRELESS_STATE_BUSY);
        Wireless_ForceReset();
        return;
    }
    Wireless_SetState(WIRELESS_STATE_BUSY);
    switch (sWirelessManager.work->mode) {
    case 1:
    case 5:
        if (!Wireless_EndChild()) {
            Wireless_ForceReset();
        }
        break;
    case 0:
    case 4:
        if (!Wireless_EndParent()) {
            Wireless_ForceReset();
        }
        break;
    case 2:
    case 3:
        break;
    }
}

BOOL Wireless_End(void) {
    Wireless_SetState(WIRELESS_STATE_BUSY);
    if (WM_End(Wireless_OnEnded) != WM_ERRCODE_OPERATING) {
        Wireless_SetState(WIRELESS_STATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

u16 Wireless_GetAid(void) {
    return sWirelessManager.work->aid;
}

void Wireless_SetMaxEntries(int maxEntries) {
    if (sWirelessManager.work != NULL) {
        sWirelessManager.work->maxEntries = maxEntries;
    }
}

BOOL Wireless_IsIdle(void) {
    return sWirelessManager.work->state == WIRELESS_STATE_IDLE;
}

BOOL Wireless_IsBusy(void) {
    return sWirelessManager.work->state == WIRELESS_STATE_BUSY;
}

BOOL Wireless_HasError(void) {
    return sWirelessManager.work->state == WIRELESS_STATE_ERROR;
}

BOOL Wireless_HasFatalError(void) {
    return sWirelessManager.work->state == WIRELESS_STATE_FATAL;
}

BOOL Wireless_IsScanning(void) {
    WirelessWork *work = sWirelessManager.work;
    if (work != NULL) {
        if (work->state == WIRELESS_STATE_SCANNING) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

void Wireless_UpdateGameInfo(const void *gameInfo, int length, u32 ggid, int tgid) {
    if (sWirelessManager.work->state == WIRELESS_STATE_MP) {
        WM_SetGameInfo(NULL, gameInfo, (u16)length, ggid, (u16)tgid, 1);
    }
}

static void Wireless_OnEntrySet(void *arg) {
    WirelessEvent *event = arg;
    if (event->errcode == WM_ERRCODE_SUCCESS) {
        sWirelessManager.work->entrySet = 1;
    }
}

BOOL Wireless_SetEntry(BOOL enabled) {
    sWirelessManager.work->entrySet = 0;
    if (sWirelessManager.work->state == WIRELESS_STATE_MP && WM_SetEntry(Wireless_OnEntrySet, enabled) == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    return FALSE;
}

BOOL Wireless_HasSentBeacons(void) {
    WirelessWork *work = sWirelessManager.work;
    if (work != NULL) {
        if (work->beaconCount >= 6) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

void Wireless_ClearBeaconCount(void) {
    sWirelessManager.work->beaconCount = 0;
}

void Wireless_SetBeaconCallback(void *callback) {
    sWirelessManager.work->beaconCallback = callback;
}

void Wireless_SetChildJoinedCallback(void *callback) {
    sWirelessManager.work->childJoinedCallback = callback;
}

void Wireless_SetEntryLocked(int locked) {
    sWirelessManager.work->entryLocked = locked;
}

u8 Wireless_IsEntryLocked(void) {
    return sWirelessManager.work->entryLocked;
}

void Wireless_SetEntryClosed(int closed) {
    sWirelessManager.work->entryClosed = closed;
}
