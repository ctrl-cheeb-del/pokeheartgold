#include "comm_wireless.h"

#include <nitro/wm/wm_internal.h>
#include <stddef.h>

#include "global.h"

#include "constants/comm_type.h"

#include "comm_state_internal.h"
#include "communication_command.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "heap.h"
#include "mail_message.h"
#include "player_data.h"
#include "save_link_ruleset.h"
#include "system.h"

// Wireless link layer of the communication code, above the local wireless manager: the beacon, the parents found
// while scanning (kept 300 frames after their last beacon), connecting, and the start and shutdown sequences.

// The game info sent in the beacons, also read from a scanned parent's description.
typedef struct CommBeacon {
    u32 trainerId;
    u8 kind;        // link kind (CommState_GetLinkMode)
    u8 id;          // CommState_GetBeaconId
    u8 memberCount; // connected players
    u8 unk_07;
    MailMessage mail;
    PlayerProfile profile;
    u8 ruleset[0x20]; // LinkBattleRuleset
    u8 unk_50[4];
    u8 entryLocked; // Wireless_IsEntryLocked
    u8 unk_55[7];
} CommBeacon;

// A parent found while scanning: its description, as Wireless_StartChild takes it.
typedef struct CommParentInfo {
    u8 unk_00[4];
    u8 macAddress[6];
    u8 unk_0A[0x2C];
    u16 channel;
    u8 unk_38[0x18];
    CommBeacon beacon;
    u8 unk_AC[0x14];
} CommParentInfo;

typedef struct CommWirelessWork {
    u8 customBeacon[0x54];   // sent instead of the beacon in link kind 15
    CommParentInfo received; // last parent reported by the scan
    CommParentInfo parents[16];
    u8 macAddresses[8][6];
    u16 parentTimers[16]; // frames left until a parent is dropped (0: free slot)
    void *managerBuffer;  // Wireless_Init buffer
    MailMessage mail;
    u32 unk_D70;
    u8 parentListChanged;
    u8 unk_D75[3];
    PlayerProfile *profile;
    LinkBattleRuleset *ruleset;
    u32 ggid;
    void *beaconBuffer;
    CommBeacon *beacon; // beaconBuffer aligned to 32 bytes
    u16 channel;
    u16 firstCount; // 0xFFFF until the first CommWireless_Update
    u8 currentChannel;
    u8 channelTimer;
    u8 shutdown; // 0 none, 1 stop and free, 2 end the manager, 3 ended
    u8 portCallbackSet;
    u8 stopState;
    u8 linkLost : 1;
    u8 detectDrops : 1;
    u8 lostWhenAlone : 1;
    u8 renewTgid : 1;
    u8 shutdownRequested : 1;
    u8 entryFlag : 1;
    u8 parentPending : 1; // received holds a parent not stored yet
    u8 unk_D96[2];
} CommWirelessWork;

typedef char CommWirelessWorkSizeCheck[sizeof(CommWirelessWork) == 0xD98 ? 1 : -1];
typedef char CommWirelessTimerCheck[offsetof(CommWirelessWork, parentTimers) == 0xD44 ? 1 : -1];
typedef char CommBeaconSizeCheck[sizeof(CommBeacon) == 0x5C ? 1 : -1];

enum CommWirelessPowerState {
    COMM_WIRELESS_OFF,
    COMM_WIRELESS_STARTING_UP,
    COMM_WIRELESS_STARTED,
};

enum CommWirelessShutdown {
    COMM_WIRELESS_SHUTDOWN_NONE,
    COMM_WIRELESS_SHUTDOWN_STOP_AND_FREE,
    COMM_WIRELESS_SHUTDOWN_END_MANAGER,
    COMM_WIRELESS_SHUTDOWN_ENDED,
};

enum CommWirelessStopState {
    COMM_WIRELESS_STOP_START,
    COMM_WIRELESS_STOP_WAIT_SCAN,
    COMM_WIRELESS_STOP_WAIT_IDLE,
};

typedef struct CommWireless {
    u16 tgid;
    u16 unk_02;
    enum CommWirelessPowerState state; // started through WVR
    CommWirelessWork *work;
} CommWireless;

typedef struct CommBssid {
    u8 data[6];
} CommBssid;

int WVR_StartUpAsync(int mode, void (*callback)(void *, int), void *arg);
int WVR_TerminateAsync(void (*callback)(void *), void *arg);

int CommState_GetLinkMode(void);
u8 CommState_GetBeaconId(void);
void Comm_RecvChildFrameCallback(int netId, const u8 *data, int size);
void Comm_RecvParentFrameCallback(int netId, const u8 *data, int size);

u32 Wireless_GetWorkSize(void);
BOOL Wireless_Init(void *buffer, int mode);
void Wireless_SetGgid(u32 ggid);
void Wireless_SetParentGameInfo(void *gameInfo, u16 length);
void Wireless_ClearBeaconCount(void);
void Wireless_SetReceiveCallback(void *callback, int port);
BOOL Wireless_StartMeasureChannels(void);
BOOL Wireless_StartScan(void (*callback)(void *), const void *bssid, u16 channel);
BOOL Wireless_IsScanning(void);
BOOL Wireless_StopScan(void);
BOOL Wireless_IsBusy(void);
BOOL Wireless_HasError(void);
BOOL Wireless_IsIdle();
u16 Wireless_GetConnectedBitmap();
u32 Wireless_GetState();
void Wireless_Stop(void);
BOOL Wireless_ScanAndConnect(int mode, void *bssid, u16 channel);
BOOL Wireless_StartChild(int mode, const void *parentInfo);
u8 Wireless_IsEntryLocked(void);
void Wireless_UpdateGameInfo(const void *gameInfo, int length, u32 ggid, int tgid);
u16 Wireless_GetAid(void);
u32 Wireless_GetError(void);
BOOL Wireless_End(void);
u16 Wireless_SelectChannel(void);
BOOL Wireless_StartParent(int, u16, u16, int, u32, u32);
BOOL Wireless_HasSentBeacons(void);

static BOOL CommWireless_BytesEqual(const u8 *a, const u8 *b, int size);
static void CommWireless_OnParentFound(void *parentInfo);
static void CommWireless_StoreFoundParent(void);
static void CommWireless_OnStartedUp(void *unused, int failed);
static void CommWireless_OnTerminated(void *unused);
static void CommWireless_InitManager(int mode);
static void CommWireless_SetRenewTgid(BOOL renew);
static void CommWireless_ResetFlags(void);
static void CommWireless_Free(void);
static void CommWireless_BuildBeacon(void);
static void CommWireless_UpdateBeaconMemberCount(void);
static void CommWireless_Update(int count, CommWirelessWork *work);
static BOOL CommWireless_IsAidConnected(u16 aid);
static int CommWireless_CountConnected(void);
static u32 CommWireless_GetBeaconPeriod(u32 kind);

static const CommBssid sCommWirelessAnyBssid = {
    .data = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};

static CommWireless sCommWireless;

void CommWireless_Init(PlayerProfile *profile, int mode) {
    if (sCommWireless.work == NULL) {
        void *allocation;
        CommWirelessWork *work;
        u8 *raw;
        u32 remainder;
        u32 adjustment;

        allocation = Heap_Alloc(HEAP_ID_15, sizeof(CommWirelessWork));
        sCommWireless.work = allocation;
        MI_CpuFill8(allocation, 0, sizeof(CommWirelessWork));

        allocation = Heap_Alloc(HEAP_ID_15, Wireless_GetWorkSize());
        sCommWireless.work->managerBuffer = allocation;
        MI_CpuFill8(sCommWireless.work->managerBuffer, 0, Wireless_GetWorkSize());

        allocation = Heap_Alloc(HEAP_ID_15, LinkBattleRuleset_sizeof());
        sCommWireless.work->ruleset = allocation;
        MI_CpuFill8(sCommWireless.work->ruleset, 0, LinkBattleRuleset_sizeof());

        allocation = Heap_Alloc(HEAP_ID_15, 0x90);
        sCommWireless.work->beaconBuffer = allocation;
        work = sCommWireless.work;
        raw = work->beaconBuffer;
        remainder = (u32)raw & 0x1F;
        adjustment = 0x20 - remainder;
        work->beacon = (CommBeacon *)(adjustment + (u32)raw);
        sCommWireless.work->ggid = 0x333;
        sCommWireless.work->profile = profile;
        MailMsg_Init(&sCommWireless.work->mail);
        CommWireless_InitManager(mode);
        sCommWireless.tgid = WM_GetNextTgid();
    }
}

BOOL CommWireless_IsInitialized(void) {
    return sCommWireless.work != NULL;
}

static BOOL CommWireless_BytesEqual(const u8 *a, const u8 *b, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (*a != *b) {
            return FALSE;
        }
        a++;
        b++;
    }
    return TRUE;
}

// Scan callback: keeps a parent of our link kind (and id), stored by CommWireless_StoreFoundParent.
static void CommWireless_OnParentFound(void *parentInfo) {
    CommParentInfo *info = parentInfo;
    CommBeacon *beacon;
    int kind;
    int id;

    kind = CommState_GetLinkMode();
    id = CommState_GetBeaconId();
    beacon = &info->beacon;

    if (kind != COMM_TYPE_14) {
        if (!Comm_IsUnionRoomLinkMode(beacon->kind) || !Comm_IsUnionRoomLinkMode(kind)) {
            if (beacon->entryLocked != 0 && beacon->kind == COMM_TYPE_10) {
                return;
            }
            if (beacon->kind != kind) {
                return;
            }
        }
    }
    if (kind != COMM_TYPE_14 && beacon->id != id) {
        return;
    }
    MI_CpuCopy8(info, &sCommWireless.work->received, sizeof(CommParentInfo));
    sCommWireless.work->parentPending = 1;
}

static void CommWireless_StoreFoundParent(void) {
    CommWirelessWork *work;
    CommParentInfo *received;
    int i;

    work = sCommWireless.work;
    received = &work->received;
    if (work->parentPending == 0) {
        return;
    }
    work->parentPending = 0;
    for (i = 0; i < 16; i++) {
        if (sCommWireless.work->parentTimers[i] != 0) {
            if (CommWireless_BytesEqual(sCommWireless.work->parents[i].macAddress, received->macAddress, 6)) {
                sCommWireless.work->parentTimers[i] = 300;
                MI_CpuCopy8(received, &sCommWireless.work->parents[i], sizeof(CommParentInfo));
                return;
            }
        }
    }
    for (i = 0; i < 16; i++) {
        if (sCommWireless.work->parentTimers[i] == 0) {
            break;
        }
    }
    if (i < 16) {
        sCommWireless.work->parentTimers[i] = 300;
        MI_CpuCopy8(received, &sCommWireless.work->parents[i], sizeof(CommParentInfo));
        sCommWireless.work->parentListChanged = 1;
    }
}

static void CommWireless_OnStartedUp(void *unused, int failed) {
    if (failed != 0) {
        OS_Terminate();
    }
    sCommWireless.state = COMM_WIRELESS_STARTED;
}

static void CommWireless_OnTerminated(void *unused) {
    sCommWireless.state = COMM_WIRELESS_OFF;
    Sys_ClearSleepDisableFlag(4);
}

void CommWireless_StartUp(void) {
    Sys_SetSleepDisableFlag(4);
    sCommWireless.state = COMM_WIRELESS_STARTING_UP;
    if (WVR_StartUpAsync(8, CommWireless_OnStartedUp, NULL) != 1) {
        OS_Terminate();
    }
}

BOOL CommWireless_IsStartedUp(void) {
    return sCommWireless.state == COMM_WIRELESS_STARTED;
}

BOOL CommWireless_IsOn(void) {
    return sCommWireless.state != COMM_WIRELESS_OFF;
}

void CommWireless_Terminate(void) {
    WVR_TerminateAsync(CommWireless_OnTerminated, NULL);
}

static void CommWireless_InitManager(int mode) {
    u8 *buffer;
    u32 misalignment;

    sCommWireless.work->unk_D70 = 0;
    buffer = sCommWireless.work->managerBuffer;
    misalignment = (u32)buffer & 0x1F;
    Wireless_Init(buffer + (0x20 - misalignment), mode);
    Wireless_SetGgid(sCommWireless.work->ggid);
}

void CommWireless_ClearParents(void) {
    int i;
    for (i = 0; i < 16; i++) {
        sCommWireless.work->parentTimers[i] = 0;
    }
    MI_CpuFill8(sCommWireless.work->parents, 0, sizeof(sCommWireless.work->parents));
}

static void CommWireless_SetRenewTgid(BOOL renew) {
    sCommWireless.work->renewTgid = renew;
}

static void CommWireless_ResetFlags(void) {
    sCommWireless.work->parentListChanged = 0;
    sCommWireless.work->linkLost = 0;
    sCommWireless.work->lostWhenAlone = 0;
    sCommWireless.work->shutdown = COMM_WIRELESS_SHUTDOWN_NONE;
    sCommWireless.work->shutdownRequested = 0;
    sCommWireless.work->stopState = COMM_WIRELESS_STOP_START;
    sCommWireless.work->portCallbackSet = 0;
}

// Measures the channels; CommWireless_Update starts the parent on the quietest one.
BOOL CommWireless_StartParent(int unused, BOOL renewTgid, BOOL entryFlag) {
    (void)unused;
    CommWireless_ResetFlags();
    CommWireless_SetRenewTgid(renewTgid);
    Wireless_ClearBeaconCount();
    if (sCommWireless.work->portCallbackSet == 0) {
        Wireless_SetReceiveCallback(Comm_RecvChildFrameCallback, 14);
        sCommWireless.work->portCallbackSet = 1;
    }
    sCommWireless.work->entryFlag = entryFlag;
    if (Wireless_GetState() == 1 && Wireless_StartMeasureChannels() != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL CommWireless_StartScan(int unused, BOOL clearParents) {
    CommBssid bssid;
    (void)unused;
    CommWireless_ResetFlags();
    if (clearParents) {
        CommWireless_ClearParents();
    }
    if (sCommWireless.work->portCallbackSet == 0) {
        Wireless_SetReceiveCallback(Comm_RecvParentFrameCallback, 14);
        sCommWireless.work->portCallbackSet = 1;
    }
    if (Wireless_GetState() == 1) {
        bssid = sCommWirelessAnyBssid;
        if (Wireless_StartScan(CommWireless_OnParentFound, &bssid, 0)) {
            return TRUE;
        }
    }
    return FALSE;
}

// Ends the scan / the link; TRUE once the manager is idle.
BOOL CommWireless_Stop(void) {
    if (sCommWireless.work == NULL) {
        return TRUE;
    }
    switch (sCommWireless.work->stopState) {
    case COMM_WIRELESS_STOP_START:
        if (Wireless_IsScanning()) {
            Wireless_StopScan();
            sCommWireless.work->stopState = COMM_WIRELESS_STOP_WAIT_SCAN;
        } else if (!Wireless_IsBusy()) {
            Wireless_Stop();
            sCommWireless.work->stopState = COMM_WIRELESS_STOP_WAIT_IDLE;
        }
        break;
    case COMM_WIRELESS_STOP_WAIT_SCAN:
        if (!Wireless_IsBusy()) {
            Wireless_Stop();
            sCommWireless.work->stopState = COMM_WIRELESS_STOP_WAIT_IDLE;
        }
        break;
    case COMM_WIRELESS_STOP_WAIT_IDLE:
        if (Wireless_IsIdle()) {
            return TRUE;
        }
        if (Wireless_HasError()) {
            sCommWireless.work->stopState = COMM_WIRELESS_STOP_WAIT_SCAN;
        }
        break;
    }
    return FALSE;
}

BOOL CommWireless_RequestStopAndFree(void) {
    if (sCommWireless.work != NULL && sCommWireless.work->shutdown == COMM_WIRELESS_SHUTDOWN_NONE) {
        sCommWireless.work->shutdown = COMM_WIRELESS_SHUTDOWN_STOP_AND_FREE;
        Wireless_Stop();
        return TRUE;
    }
    return FALSE;
}

void CommWireless_SetManagerEnded(BOOL end) {
    if (sCommWireless.work != NULL) {
        if (end) {
            sCommWireless.work->shutdown = COMM_WIRELESS_SHUTDOWN_END_MANAGER;
        } else {
            sCommWireless.work->shutdown = COMM_WIRELESS_SHUTDOWN_NONE;
            CommWireless_InitManager(1);
        }
    }
}

static void CommWireless_Free(void) {
    Heap_Free(sCommWireless.work->ruleset);
    Heap_Free(sCommWireless.work->managerBuffer);
    Heap_Free(sCommWireless.work->beaconBuffer);
    Heap_Free(sCommWireless.work);
    sCommWireless.work = NULL;
}

int CommWireless_CountParents(void) {
    int i;
    int count;

    if (!Comm_IsActive()) {
        return 0;
    }
    count = 0;
    for (i = 0; i < 16; i++) {
        if (sCommWireless.work->parentTimers[i] != 0) {
            count++;
        }
    }
    return count;
}

int CommWireless_GetParentSlot(int ordinal) {
    int i;
    int count = 0;

    for (i = 0; i < 16; i++) {
        if (sCommWireless.work->parentTimers[i] != 0) {
            if (count == ordinal) {
                return i;
            }
            count++;
        }
    }
    GF_ASSERT(FALSE);
    return 0;
}

u8 CommWireless_IsParentListChanged(void) {
    return sCommWireless.work->parentListChanged;
}

void CommWireless_ClearParentListChanged(void) {
    sCommWireless.work->parentListChanged = 0;
}

// The players connected to the parent in slot (at least 1), FALSE for a free slot.
BOOL CommWireless_GetParentMemberCount(int slot) {
    CommWirelessWork *work;
    u16 value;

    work = sCommWireless.work;
    value = work->parentTimers[slot];
    if (value != 0) {
        u8 count = work->parents[slot].beacon.memberCount;
        if (count == 0) {
            return TRUE;
        }
        return count;
    }
    return FALSE;
}

void CommWireless_CopyParentProfile(int ordinal, PlayerProfile *profile) {
    int i;
    int current = 0;

    for (i = 0; i < 16; i++) {
        if (sCommWireless.work->parentTimers[i] != 0) {
            if (ordinal == current) {
                PlayerProfile_Copy(CommWireless_GetParentProfile(i), profile);
                return;
            }
            current++;
        }
    }
}

BOOL CommWireless_ConnectToParent(int slot) {
    int state = Wireless_GetState();

    if (state == 2) {
        Wireless_StopScan();
        return FALSE;
    }
    if (Wireless_GetState() == 1) {
        int kind = CommState_GetLinkMode();
        sCommWireless.work->currentChannel = sCommWireless.work->parents[slot].channel;
        if (Comm_IsUnionRoomLinkMode(kind)) {
            Wireless_ScanAndConnect(1, sCommWireless.work->parents[slot].macAddress, 0);
        } else {
            Wireless_StartChild(1, &sCommWireless.work->parents[slot]);
        }
        return TRUE;
    }
    return FALSE;
}

// Stores a parent the scan reported and counts down the others' timers.
void CommWireless_UpdateParents(void) {
    int i;

    CommWireless_StoreFoundParent();
    for (i = 0; i < 16; i++) {
        if (sCommWireless.work->parentTimers[i] != 0) {
            if (sCommWireless.work->parentTimers[i] != 0) {
                sCommWireless.work->parentTimers[i]--;
                if (sCommWireless.work->parentTimers[i] == 0) {
                    sCommWireless.work->parentListChanged = 1;
                }
            }
        }
    }
}

static void CommWireless_BuildBeacon(void) {
    int kind = CommState_GetLinkMode();
    PlayerProfile *profile = CommWireless_GetProfile();

    if (kind != 15) {
        CommBeacon *beacon = sCommWireless.work->beacon;
        GF_ASSERT((int)LinkBattleRuleset_sizeof() <= 0x20);
        GF_ASSERT(PlayerProfile_sizeof() == 0x20);
        MI_CpuCopy8(profile, &beacon->profile, PlayerProfile_sizeof());
        MI_CpuCopy8(sCommWireless.work->ruleset, beacon->ruleset, LinkBattleRuleset_sizeof());
        beacon->trainerId = PlayerProfile_GetTrainerID(profile);
        beacon->kind = CommState_GetLinkMode();
        beacon->id = CommState_GetBeaconId();
        MI_CpuCopy8(&sCommWireless.work->mail, &beacon->mail, sizeof(MailMessage));
        beacon->entryLocked = Wireless_IsEntryLocked();
    } else {
        CommBeacon *beacon = sCommWireless.work->beacon;
        beacon->trainerId = PlayerProfile_GetTrainerID(profile);
        beacon->kind = CommState_GetLinkMode();
        beacon->id = CommState_GetBeaconId();
        MI_CpuCopy8(sCommWireless.work->customBeacon, &beacon->mail, sizeof(sCommWireless.work->customBeacon));
    }
    DC_FlushRange(sCommWireless.work->beacon, sizeof(CommBeacon));
    Wireless_SetParentGameInfo(sCommWireless.work->beacon, sizeof(CommBeacon));
}

static void CommWireless_UpdateBeaconMemberCount(void) {
    CommBeacon *beacon = sCommWireless.work->beacon;

    if (beacon->memberCount != CommWireless_CountConnected()) {
        beacon->memberCount = CommWireless_CountConnected();
        DC_FlushRange(sCommWireless.work->beacon, sizeof(CommBeacon));
        Wireless_SetParentGameInfo(sCommWireless.work->beacon, sizeof(CommBeacon));
        Wireless_UpdateGameInfo(sCommWireless.work->beacon, sizeof(CommBeacon), sCommWireless.work->ggid, sCommWireless.tgid);
    }
}

// Per frame: notices a lost link (alone as parent, fewer players than at the start, players dropped, errors),
// follows the shutdown request, and starts the parent once the channels are measured.
static void CommWireless_Update(int count, CommWirelessWork *unused) {
    int state = Wireless_GetState(count);
    BOOL dropped = CommPlayerInfo_DropDisconnected();
    CommWireless_UpdateBeaconMemberCount();
    if (Wireless_GetAid() == 0 && CommWireless_GetConnectedChildren() == 0 && sCommWireless.work->lostWhenAlone) {
        sCommWireless.work->linkLost = 1;
    }
    if (sCommWireless.work->firstCount == 0xFFFF) {
        sCommWireless.work->firstCount = count;
    }
    if (sCommWireless.work->detectDrops) {
        if (sCommWireless.work->firstCount > (u32)count) {
            sCommWireless.work->linkLost = 1;
        }
        if (dropped != 0) {
            sCommWireless.work->linkLost = 1;
        }
    }
    if (Wireless_GetError() == 0x19) {
        CommState_ShowErrorAndHalt(0);
    }
    switch (state) {
    case 0:
        if (sCommWireless.work->shutdown == COMM_WIRELESS_SHUTDOWN_STOP_AND_FREE) {
            CommWireless_Free();
            return;
        }
        if (sCommWireless.work->shutdown == COMM_WIRELESS_SHUTDOWN_END_MANAGER) {
            sCommWireless.work->shutdown = COMM_WIRELESS_SHUTDOWN_ENDED;
            return;
        }
        break;
    case 1:
        if (sCommWireless.work->shutdown == COMM_WIRELESS_SHUTDOWN_STOP_AND_FREE) {
            if (Wireless_End() != 0) {
                break;
            }
        }
        if (sCommWireless.work->shutdown == COMM_WIRELESS_SHUTDOWN_END_MANAGER) {
            if (Wireless_End() == 0) {
                return;
            }
            return;
        }
        break;
    case 8:
    case 9:
        if (sCommWireless.work != NULL) {
            sCommWireless.work->linkLost = 1;
            return;
        }
        break;
    case 7: {
        u16 channel = Wireless_SelectChannel();
        u16 saved;
        int maxEntry;
        u32 beaconPeriod;
        if (sCommWireless.work->channelTimer == 0) {
            sCommWireless.work->channel = channel;
            sCommWireless.work->channelTimer = 5;
        } else {
            sCommWireless.work->channelTimer--;
        }
        saved = sCommWireless.work->channel;
        if (sCommWireless.work->renewTgid) {
            sCommWireless.tgid = WM_GetNextTgid();
        }
        CommWireless_BuildBeacon();
        maxEntry = Comm_GetMaxChildren(CommState_GetLinkMode());
        beaconPeriod = CommWireless_GetBeaconPeriod((u16)CommState_GetLinkMode());
        Wireless_StartParent(0, sCommWireless.tgid, saved, maxEntry, beaconPeriod, sCommWireless.work->entryFlag);
        sCommWireless.work->currentChannel = saved;
        break;
    }
    }
    return;
}

BOOL CommWireless_Main(int count) {
    if (sCommWireless.work != NULL) {
        CommWireless_Update(count, sCommWireless.work);
    }
}

static BOOL CommWireless_IsAidConnected(u16 aid) {
    if (sCommWireless.work == NULL) {
        return FALSE;
    }
    if (Wireless_GetState() != 4) {
        return FALSE;
    }
    if (Wireless_GetConnectedBitmap() & (1 << aid)) {
        return TRUE;
    }
    return FALSE;
}

static int CommWireless_CountConnected(void) {
    int count = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (CommWireless_IsAidConnected(i)) {
            count++;
        }
    }
    return count;
}

int CommWireless_IsManagerEnded(void) {
    if (sCommWireless.work != NULL && sCommWireless.work->shutdown == COMM_WIRELESS_SHUTDOWN_ENDED) {
        return 1;
    }
    return 0;
}

BOOL CommWireless_Exists(void) {
    return sCommWireless.work != NULL;
}

int CommWireless_IsIdle(void) {
    if (sCommWireless.work != NULL) {
        return Wireless_IsIdle(sCommWireless.work);
    }
    return 1;
}

int CommWireless_GetConnectedChildren(void) {
    if (sCommWireless.work != NULL) {
        return Wireless_GetConnectedBitmap(sCommWireless.work) & 0xFFFE;
    }
    return 0;
}

BOOL CommWireless_IsLinkLost(void) {
    if (sCommWireless.work != NULL) {
        if (sCommWireless.work->linkLost != 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void CommWireless_SetLostWhenAlone(BOOL value) {
    if (sCommWireless.work != NULL) {
        sCommWireless.work->lostWhenAlone = value;
    }
}

void CommWireless_SetDetectDrops(BOOL value) {
    if (sCommWireless.work != NULL) {
        sCommWireless.work->detectDrops = value;
        sCommWireless.work->firstCount = 0xFFFF;
    }
}

// A quarter of the beacon period for link kinds 9, 10 and 13.
static u32 CommWireless_GetBeaconPeriod(u32 kind) {
    u16 period = WM_GetDispersionBeaconPeriod();

    GF_ASSERT(kind < 41);
    if (kind == 10) {
        return ((u32)period << 14) >> 16;
    }
    if (kind == 9 || kind == 13) {
        return ((u32)period << 14) >> 16;
    }
    return period;
}

void *CommWireless_GetParentInfo(int slot) {
    if (sCommWireless.work != NULL) {
        if (sCommWireless.work->parentTimers[slot] != 0) {
            return &sCommWireless.work->parents[slot];
        }
    }
    return NULL;
}

PlayerProfile *CommWireless_GetProfile(void) {
    return sCommWireless.work->profile;
}

PlayerProfile *CommWireless_GetParentProfile(int slot) {
    CommBeacon *beacon;
    if (sCommWireless.work->parentTimers[slot] == 0) {
        return NULL;
    }
    beacon = &sCommWireless.work->parents[slot].beacon;
    return &beacon->profile;
}

void CommWireless_SetMacAddress(const u8 *macAddress, int index) {
    if (sCommWireless.work != NULL) {
        GF_ASSERT(index < 8);
        MI_CpuCopy8(macAddress, sCommWireless.work->macAddresses[index], 6);
    }
}

BOOL CommWireless_IsShutdownRequested(void) {
    if (sCommWireless.work != NULL) {
        return sCommWireless.work->shutdownRequested;
    }
    return FALSE;
}

void CommWireless_RequestShutdown(void) {
    if (sCommWireless.work != NULL) {
        sCommWireless.work->shutdownRequested = 1;
    }
}

void CommWireless_SetMail(const MailMessage *mail) {
    MI_CpuCopy8(mail, &sCommWireless.work->mail, 8);
}

void CommWireless_SetRuleset(const void *ruleset) {
    MI_CpuCopy8(ruleset, sCommWireless.work->ruleset, LinkBattleRuleset_sizeof());
}

void *CommWireless_GetRuleset(void) {
    return sCommWireless.work->ruleset;
}

void CommWireless_RefreshBeacon(void) {
    CommWireless_BuildBeacon();
    Wireless_UpdateGameInfo(sCommWireless.work->beacon, sizeof(CommBeacon), sCommWireless.work->ggid, sCommWireless.tgid);
}

BOOL CommWireless_HasSentBeacons(void) {
    return Wireless_HasSentBeacons();
}

void CommWireless_SetCustomBeacon(const void *src) {
    MI_CpuCopy8(src, sCommWireless.work->customBeacon, sizeof(sCommWireless.work->customBeacon));
    CommWireless_RefreshBeacon();
}

void *CommWireless_GetParentMail(int slot) {
    if (sCommWireless.work != NULL) {
        if (sCommWireless.work->parentTimers[slot] != 0) {
            CommBeacon *beacon = &sCommWireless.work->parents[slot].beacon;
            return &beacon->mail;
        }
    }
    return NULL;
}
