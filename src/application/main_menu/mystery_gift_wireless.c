#include "application/main_menu/mystery_gift_wireless.h"

#include "global.h"

#include "application/main_menu/mystery_gift_app.h"
#include "application/main_menu/mystery_gift_app_internal.h"

#include "comm_state_internal.h"
#include "comm_wireless.h"
#include "communication_command.h"
#include "communication_player_state.h"
#include "heap.h"
#include "link_synchronization.h"
#include "main.h"
#include "mystery_gift.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "sys_task_api.h"

// DS-wireless link used by Mystery Gift to receive a Wonder Card from a distribution system. The link
// is driven by a small state callback run from a task every frame.

typedef struct MysteryGiftCommWork {
    void *owner;
    u8 random[0x18]; // initialised by CommRandom_Init
    SysTask *task;
    MysteryGiftCommStateFunc stateFunc;
    u16 stateArg;
    u8 paused;
    u8 channel;
    PlayerProfile *profiles[16];
    u8 recvBuffer[sizeof(WonderCard)];
    u8 received;
    u8 unk_3C1[16];
} MysteryGiftCommWork;

static MysteryGiftCommWork *sMysteryGiftCommWork;

extern u16 Comm_GetLocalNetId(void);
extern int Comm_IsNetIdConnected(u16 slot);
extern BOOL Comm_IsActive(void);
extern void CommRandom_Init(void *seed);
extern int Comm_SendParentCommandNoCopy(int command, void *data, int size);

static const CommCommand sMysteryGiftCommCommands[2] = {
    {
        .recv = MysteryGiftComm_HandleReceived,
        .getSize = MysteryGiftComm_GetRecvBufferSize,
        .getBuffer = MysteryGiftComm_GetRecvBuffer,
    },
    {
        .recv = MysteryGiftComm_RecvSetFlag3C1,
        .getSize = CommCmd_GetSize0,
        .getBuffer = NULL,
    },
};

void MysteryGiftComm_Start(void *owner) {
    if (sMysteryGiftCommWork == NULL) {
        MysteryGiftComm_RegisterCommands(owner);
        sMysteryGiftCommWork = Heap_Alloc(HEAP_ID_15, sizeof(MysteryGiftCommWork));
        MI_CpuFill8(sMysteryGiftCommWork, 0, sizeof(MysteryGiftCommWork));
        sMysteryGiftCommWork->stateArg = 50;
        sMysteryGiftCommWork->task = SysTask_CreateOnMainQueue(MysteryGiftComm_Task, NULL, 10);
        sMysteryGiftCommWork->owner = owner;
        CommRandom_Init(sMysteryGiftCommWork->random);
    }
}

void MysteryGiftComm_SetState(MysteryGiftCommStateFunc func, u16 arg) {
    sMysteryGiftCommWork->stateFunc = func;
    sMysteryGiftCommWork->stateArg = arg;
}

void MysteryGiftComm_ParentWaitStartup(void) {
    int i;
    if (Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        for (i = 0; i < 16; i++) {
            sMysteryGiftCommWork->unk_3C1[i] = 0;
        }
        CommPlayerInfo_SendLocal();
        MysteryGiftComm_SetState(MysteryGiftComm_ParentCollectProfiles, 0);
    }
}

void MysteryGiftComm_ParentCollectProfiles(void) {
    int i;
    for (i = 0; i < 16; i++) {
        if (sMysteryGiftCommWork->profiles[i] == NULL && Comm_IsNetIdConnected((u16)i) == 1) {
            sMysteryGiftCommWork->profiles[i] = CommPlayerInfo_GetProfile(i);
        }
    }
}

void MysteryGiftComm_ChildWaitStartup(void) {
    if (CommWireless_IsStartedUp()) {
        MysteryGiftComm_SetState(MysteryGiftComm_ChildStateIdle, 0);
    }
}

void MysteryGiftComm_ChildStateIdle(void) {
}

void MysteryGiftComm_ChildConnect(void) {
    CommState_ConnectToSlot(sMysteryGiftCommWork->channel);
    MysteryGiftComm_SetState(MysteryGiftComm_ChildWaitLinked, 0);
}

void MysteryGiftComm_ChildWaitLinked(void) {
    if (CommState_IsLinked()) {
        sMysteryGiftCommWork->received = FALSE;
        CommPlayerInfo_SendLocal();
        LinkSync_StartSync(0xAB);
        MysteryGiftComm_SetState(MysteryGiftComm_ChildStateLinked, 0);
    }
}

void MysteryGiftComm_ChildStateLinked(void) {
}

void MysteryGiftComm_Task(SysTask *task, void *data) {
    MysteryGiftCommStateFunc func;
    if (sMysteryGiftCommWork == NULL) {
        SysTask_Destroy(task);
        return;
    }
    func = sMysteryGiftCommWork->stateFunc;
    if (func != NULL && !sMysteryGiftCommWork->paused) {
        func();
    }
}

void MysteryGiftComm_StartParent(void *owner, SaveData *saveData, s8 linkMode) {
    if (!Comm_IsActive()) {
        CommState_StartMysteryGiftParent(saveData, linkMode);
        MysteryGiftComm_Start(owner);
        MysteryGiftComm_SetState(MysteryGiftComm_ParentWaitStartup, 0);
    }
}

int MysteryGiftWireless_SendCard(void *data, int size) {
    return Comm_SendParentCommandNoCopy(0x16, data, size);
}

void MysteryGiftComm_StartChild(void *owner, s8 linkMode) {
    if (!Comm_IsActive()) {
        MainOverlayArgs *args = OverlayManager_GetArgs(MysteryGiftApp_GetOverlayManager());
        CommState_StartMysteryGiftChild(args->saveData, linkMode);
        MysteryGiftComm_Start(owner);
        MysteryGiftComm_SetState(MysteryGiftComm_ChildWaitStartup, 0);
    }
}

void MysteryGiftComm_ConnectToChannel(int channel) {
    sMysteryGiftCommWork->channel = channel;
    MysteryGiftComm_SetState(MysteryGiftComm_ChildConnect, 0);
}

// Copies the gift header of the first partner that sends one; returns its index.
int MysteryGiftComm_GetFirstParentInfo(MysteryGiftAppData *data) {
    int i;
    for (i = 0; i < 16; i++) {
        WonderCardInfo *info = CommWireless_GetParentMail(i);
        if (info != NULL && info->id != 0) {
            memcpy(&data->receivedHeader, info, sizeof(WonderCardInfo));
            return i;
        }
    }
    return -1;
}

void MysteryGiftComm_HandleReceived(int netId, int size, void *data, void *context) {
    if (sMysteryGiftCommWork->channel == netId) {
        sMysteryGiftCommWork->received = TRUE;
    }
}

u8 MysteryGiftComm_IsReceived(void) {
    return sMysteryGiftCommWork->received;
}

u32 MysteryGiftComm_GetRecvBufferSize(void) {
    return sizeof(WonderCard);
}

void *MysteryGiftComm_GetRecvBuffer(int netId, void *arg, int size) {
    return sMysteryGiftCommWork->recvBuffer;
}

void MysteryGiftComm_RecvSetFlag3C1(int netId, int size, void *data, void *context) {
    sMysteryGiftCommWork->unk_3C1[netId] = TRUE;
}

void MysteryGiftComm_Free(void) {
    Heap_FreeExplicit(HEAP_ID_15, sMysteryGiftCommWork);
    sMysteryGiftCommWork = NULL;
    CommState_RequestShutdown();
}

void MysteryGiftComm_RegisterCommands(void *owner) {
    Comm_RegisterCommandTable(sMysteryGiftCommCommands, 2, owner);
}
