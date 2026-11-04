#include "global.h"

#include "constants/comm_type.h"

#include "dwc/dwc_main_internal.h"

#include "comm_state_internal.h"
#include "comm_wireless.h"
#include "communication_command.h"
#include "communication_core_internal.h"
#include "communication_packet_pool.h"
#include "communication_player_state.h"
#include "error_handling.h"
#include "gf_rtc.h"
#include "heap.h"
#include "link_synchronization.h"
#include "sys_task_api.h"
#include "system.h"
#include "wifi_connection.h"
#include "wireless_manager.h"

int CommState_GetLinkMode(void);
void CommState_SetErrorWatch(BOOL watchMembers, BOOL reportErrors);
void LinkSync_Free(void);
void LinkSync_Update(void);

static int Comm_InitWork(int create, int packetSize);
static void Comm_ResetBuffers(void);
static void Comm_Reset(void);
static void Comm_OnTransferModeChanged(void);
static void Comm_ResetNetIdBuffers(int slot);
static void Comm_ResetDisconnectedNetIds(void);
static void Comm_OnChildJoined(int slot);
static void Comm_UpdateTransferMode(void);
static void Comm_RequestTransferMode(int connected);
static int Comm_GetTransferMode(void);
static void Comm_VBlankSendTask(SysTask *task, void *data);
static void Comm_ShutdownWhenRequested(void);
static void Comm_UpdateChildSend(void);
static BOOL Comm_FillParentFrameFromChildren(int slot);
static void Comm_SendParentFrame(void);
static BOOL Comm_HasNoChildBacklog(void);
static void Comm_UpdateParentSend(void);
static void Comm_OnParentFrameReceived(int netId, const u8 *data, int size);
static void Comm_OnChildFrameReceived(int slot, const u8 *data, int size);
static void Comm_OnChildFrameSent(BOOL success);
static void Comm_OnParentFrameSent(BOOL success);
static void Comm_SendChildFrame(void);
static inline u32 CommWork_Random(CommWork *w, u32 max);
static void Comm_ScrambleDirectionKeys(void);
static int Comm_ReadFrameKeys(const u8 *data, int slot);
static int Comm_WriteFrameKeys(u8 *data);
static int Comm_BuildChildFrame(u8 *data);
static void Comm_BuildParentFrame(u8 *data);
static BOOL Comm_IsSendSkippedThisFrame(void);
static void Comm_FinishCommand(int netId, int command, int size, void *data, PacketCursor *cursor);
static void Comm_ReceiveCommands(ByteRing *ring, int netId, u8 *buffer, PacketCursor *cursor);
static void Comm_ReceiveFromParent(void);
static void Comm_ReceiveFromChildren(void);
static BOOL Comm_IsKeySyncEnabled(void);
static void Comm_UpdateTransferModeHandshake(void);
static int Comm_GetChildFrameSize(u16 linkMode);

static CommCore sCommCore;
static CommSendStages sCommSendStages = {
    { 4, 4 }
};

static int Comm_InitWork(int create, int packetSize) {
    int existing = 0;
    int count;
    int i;

    sCommCore.updateLock = 0;
    if (create != 0) {
        count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
        if (sCommCore.work != NULL) {
            return 1;
        }

        LinkSync_Init(HEAP_ID_15);
        sCommCore.allocation = Heap_Alloc(HEAP_ID_15, sizeof(CommWork) + 32);
        sCommCore.work = (CommWork *)(32 - ((u32)sCommCore.allocation & 31) + (u32)sCommCore.allocation);
        MI_CpuFill8(sCommCore.work, 0, sizeof(CommWork));

        if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
            sCommCore.work->frameDataSize = packetSize * 2 + 0x40;
        } else {
            sCommCore.work->frameDataSize = packetSize + 0x40;
        }
        sCommCore.work->recvDataSize = sCommCore.work->frameDataSize * count;
        sCommCore.work->transferMode = 0;
        packetSize = 42;
        sCommCore.work->packetSize = packetSize;
        sCommCore.work->parentRecvData = Heap_Alloc(HEAP_ID_15, sCommCore.work->frameDataSize * 2);
        sCommCore.work->commandBuffer = Heap_Alloc(HEAP_ID_15, sCommCore.work->frameDataSize);
        sCommCore.work->recvData = Heap_Alloc(HEAP_ID_15, sCommCore.work->recvDataSize);
        sCommCore.work->childFrameData = Heap_Alloc(HEAP_ID_15, sCommCore.work->recvDataSize);

        if (CommState_GetLinkMode() == COMM_TYPE_10) {
            PacketPool_Init(&sCommCore.work->childQueue, 100, &sCommCore.work->childSendRing);
            PacketPool_Init(&sCommCore.work->parentQueue, 800, &sCommCore.work->parentSendRing);
        } else {
            PacketPool_Init(&sCommCore.work->childQueue, 20, &sCommCore.work->childSendRing);
            PacketPool_Init(&sCommCore.work->parentQueue, packetSize + 238, &sCommCore.work->parentSendRing);
        }
    } else {
        existing = 1;
        GF_ASSERT(sCommCore.work != NULL);
    }

    sCommCore.work->connectedNetIds = 0;
    for (i = 0; i < 4; i++) {
        sCommCore.work->battleSlots[i] = 0xFF;
    }
    if (existing == 0) {
        Comm_Reset();
    }
    CommRandom_Init(&sCommCore.work->random);
    if (existing == 0) {
        sCommCore.work->sendTask = SysTask_CreateOnVBlankQueue(Comm_VBlankSendTask, NULL, 0);
    }
    sCommCore.work->wifiConnected = 0;
    return 1;
}

static void Comm_ResetBuffers(void) {
    int count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
    int length;
    int i;

    sCommCore.work->keyScrambleMode = 0;
    sCommCore.work->scrambleTimer = 0;
    MI_CpuFill8(sCommCore.work->recvData, 0, sCommCore.work->recvDataSize);
    MI_CpuFill8(sCommCore.work->recvRings, 0, sizeof(sCommCore.work->recvRings));
    length = sCommCore.work->recvDataSize / count;
    for (i = 0; i < count; i++) {
        ByteRing_Init(&sCommCore.work->recvRings[i], sCommCore.work->recvData + i * length, length);
    }
    MI_CpuFill8(sCommCore.work->childFrameData, 0, sCommCore.work->recvDataSize);
    MI_CpuFill8(sCommCore.work->childFrameRings, 0, sizeof(sCommCore.work->childFrameRings));
    for (i = 0; i < count; i++) {
        ByteRing_Init(&sCommCore.work->childFrameRings[i], sCommCore.work->childFrameData + i * length, length);
    }
    MI_CpuFill8(sCommCore.work->parentSendData, 0, sizeof(sCommCore.work->parentSendData));
    ByteRing_Init(&sCommCore.work->parentSendRing, sCommCore.work->parentSendData, sizeof(sCommCore.work->parentSendData));
    MI_CpuFill8(sCommCore.work->parentFrames[0], 0xEE, sizeof(sCommCore.work->parentFrames));
    MI_CpuFill8(sCommCore.work->parentFrames[1], 0xEE, sizeof(sCommCore.work->parentFrames));
    MI_CpuFill8(sCommCore.work->childSendData, 0, sizeof(sCommCore.work->childSendData));
    ByteRing_Init(&sCommCore.work->childSendRing, sCommCore.work->childSendData, sizeof(sCommCore.work->childSendData));
    MI_CpuFill8(sCommCore.work->childFrames[0], 0xEE, 38);
    MI_CpuFill8(sCommCore.work->childFrames[1], 0xEE, 38);
    sCommCore.work->childFrames[0][0] = 0xFF;
    sCommCore.work->childFrames[1][0] = 0xFF;
    MI_CpuFill8(sCommCore.work->parentRecvData, 0, sCommCore.work->frameDataSize * 2);
    ByteRing_Init(&sCommCore.work->parentRecvRing, sCommCore.work->parentRecvData, sCommCore.work->frameDataSize * 2);
    sCommCore.work->childQueuePending = 0;
    sCommCore.work->parentQueuePending = 0;
    for (i = 0; i < 8; i++) {
        sCommCore.work->childFrameCounts[i] = 0;
        sCommCore.work->waitingFirstFrame[i] = 1;
        sCommCore.work->directionKeys[i] = 0;
        sCommCore.work->recvCursors[i].command = 0xEE;
        sCommCore.work->recvCursors[i].size = 0xFFFF;
        sCommCore.work->recvCursors[i].data = NULL;
        sCommCore.work->recvCursors[i].received = 0;
        sCommCore.work->childSentFrames[i] = 0;
    }
    sCommCore.work->sentFrames = 0;
    sCommCore.work->parentCursor.command = 0xEE;
    sCommCore.work->parentCursor.size = 0xFFFF;
    sCommCore.work->parentCursor.data = NULL;
    sCommCore.work->parentCursor.received = 0;
    sCommCore.work->waitingParentFrame = 1;
    sCommCore.work->unk_6B3 = 1;
    sCommCore.initialized = 0;
    PacketPool_Reset(&sCommCore.work->childQueue);
    PacketPool_Reset(&sCommCore.work->parentQueue);
    sCommCore.work->unk_6B7 = 0;
}

static void Comm_Reset(void) {
    sCommCore.work->childFrameIndex = 0;
    sCommCore.work->parentFrameIndex = 0;
    sCommCore.work->continuousSend = TRUE;
    Comm_ResetBuffers();
    sCommSendStages.stage[0] = 4;
    sCommSendStages.stage[1] = 4;
}

static void Comm_OnTransferModeChanged(void) {
    Comm_ResetBuffers();
}

static void Comm_ResetNetIdBuffers(int slot) {
    int count;
    CommWork *work;
    int length;

    sCommCore.work->childFrameCounts[slot] = 0;
    sCommCore.work->waitingFirstFrame[slot] = 1;
    sCommCore.work->childSentFrames[slot] = 0;
    count = Comm_GetMaxChildren((u16)CommState_GetLinkMode());
    work = sCommCore.work;
    work = (CommWork *)work;
    length = work->recvDataSize / (count + 1);
    ByteRing_Init(&work->childFrameRings[slot], work->childFrameData + slot * length, length);
    work = sCommCore.work;
    ByteRing_Init(&work->recvRings[slot], work->recvData + slot * length, length);
    sCommCore.work->recvCursors[slot].command = 0xEE;
    sCommCore.work->recvCursors[slot].size = 0xFFFF;
    sCommCore.work->recvCursors[slot].data = NULL;
    sCommCore.work->recvCursors[slot].received = 0;
}

static void Comm_ResetDisconnectedNetIds(void) {
    int i;
    for (i = 1; i < 8; i++) {
        if (!Comm_IsNetIdConnected((u16)i) && sCommCore.work->waitingFirstFrame[i] == 0) {
            Comm_ResetNetIdBuffers(i);
        }
    }
}

static void Comm_OnChildJoined(int slot) {
    Comm_ResetNetIdBuffers(slot);
}

int Comm_StartParent(int a, int b, int c, int d) {
    int result = 1;
    if (!Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        result = CommWireless_StartParent(a, b, d);
        Wireless_SetChildJoinedCallback(Comm_OnChildJoined);
    }
    Comm_InitWork(a, c);
    return result;
}

int Comm_StartScan(int a, int b, int c) {
    int result = 1;
    if (!Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        result = CommWireless_StartScan(a, b);
    }
    Comm_InitWork(a, c);
    sCommSendStages.stage[1] = 4;
    return result;
}

static void Comm_UpdateTransferMode(void) {
    int changed = 0;
    if (Comm_GetLocalNetId() == 0) {
        if (sCommSendStages.stage[0] != 4) {
            return;
        }
    } else if (sCommSendStages.stage[1] != 4) {
        return;
    }
    if (sCommCore.work->transferMode == 2) {
        sCommCore.work->transferMode = 0;
        changed = 1;
    }
    if (sCommCore.work->transferMode == 3) {
        changed = 1;
        sCommCore.work->transferMode = 1;
    }
    if (changed) {
        Comm_OnTransferModeChanged();
    }
    Comm_UpdateTransferModeHandshake();
}

static void Comm_RequestTransferMode(int connected) {
    u8 state = sCommCore.work->transferMode;
    if (state == 0 && connected == 1) {
        sCommCore.work->transferMode = 3;
        return;
    }
    if (state == 1 && connected == 0) {
        sCommCore.work->transferMode = 2;
    }
}

void Comm_RequestTransferMode1(void) {
    Comm_RequestTransferMode(1);
}

void Comm_RequestTransferMode0(void) {
    Comm_RequestTransferMode(0);
}

static int Comm_GetTransferMode(void) {
    int state = sCommCore.work->transferMode;
    if (state == 2) {
        return 1;
    }
    if (state == 3) {
        return 0;
    }
    return state;
}

BOOL Comm_IsTransferMode1(void) {
    if (Comm_GetTransferMode() == 1) {
        return TRUE;
    }
    return FALSE;
}

void Comm_Shutdown(void) {
    int destroy = 0;
    if (sCommCore.work != NULL) {
        if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
            WifiConnection_Shutdown();
            destroy = 1;
        } else if (CommWireless_RequestStopAndFree()) {
            destroy = 1;
        }
    }
    if (destroy) {
        LinkSync_Free();
        CommPlayerInfo_Free();
        sCommCore.updateLock = 0;
        SysTask_Destroy(sCommCore.work->sendTask);
        sCommCore.work->sendTask = NULL;
        Heap_Free(sCommCore.work->parentRecvData);
        Heap_Free(sCommCore.work->commandBuffer);
        Heap_Free(sCommCore.work->recvData);
        Heap_Free(sCommCore.work->childFrameData);
        PacketPool_Free(&sCommCore.work->parentQueue);
        PacketPool_Free(&sCommCore.work->childQueue);
        Heap_Free(sCommCore.allocation);
        sCommCore.work = NULL;
        sCommCore.allocation = NULL;
    }
}

int Comm_ConnectToParent(int value) {
    return CommWireless_ConnectToParent(value);
}

static void Comm_VBlankSendTask(SysTask *task, void *data) {
    if (sCommCore.updateLock != 0) {
        Comm_SendChildFrame();
        if (Comm_GetLocalNetId() == 0 && Comm_IsNetIdConnected(0)) {
            Comm_SendParentFrame();
        }
        sCommCore.updateLock = 0;
    }
}

static void Comm_ShutdownWhenRequested(void) {
    if (CommWireless_IsShutdownRequested()) {
        if (Comm_GetLocalNetId() == 0) {
            if (CommWireless_GetConnectedChildren() == 0) {
                Comm_Shutdown();
            }
        } else {
            Comm_Shutdown();
        }
    }
}

BOOL Comm_Update(void) {
    CommWork *work;

    CommState_Main();
    work = sCommCore.work;
    if (work != NULL) {
        if (work->updateStopped == 0) {
            work->frameCount++;
            sCommCore.updateLock = 0;
            Comm_UpdateTransferMode();
            work = sCommCore.work;
            work->heldKeys |= gSystem.heldKeys & 0x7FFF;
            Comm_ScrambleDirectionKeys();
            Comm_UpdateChildSend();
            work = sCommCore.work;
            work->heldKeys &= 0x8000;
            if (Comm_GetTransferMode() == 0) {
                Comm_ReceiveFromParent();
            }
            if (Comm_GetLocalNetId() == 0 && Comm_IsNetIdConnected(0)) {
                if (!Comm_IsWifiPeerLinkMode(CommState_GetLinkMode())) {
                    Comm_UpdateParentSend();
                }
            }
            if (Comm_GetLocalNetId() == 0 || Comm_GetTransferMode() == 1) {
                Comm_ReceiveFromChildren();
            }
            sCommCore.updateLock = 1;
        }
        CommWireless_Main(sCommCore.work->connectedNetIds);
        if (Comm_GetLocalNetId() == 0) {
            Comm_ResetDisconnectedNetIds();
        }
        Comm_ShutdownWhenRequested();
    } else {
        CommWireless_Main(0);
    }
    CommState_CheckLinkError(0);
    LinkSync_Update();
    return TRUE;
}

void Comm_ResetWork(void) {
    u8 lock = sCommCore.updateLock;
    sCommCore.updateLock = 0;
    if (sCommCore.work != NULL) {
        Comm_Reset();
    }
    sCommCore.updateLock = lock;
}

void Comm_ResetInTransferMode1(void) {
    u8 lock = sCommCore.updateLock;
    sCommCore.updateLock = 0;
    if (sCommCore.work != NULL) {
        sCommCore.work->transferMode = 1;
        Comm_Reset();
    }
    sCommCore.updateLock = lock;
}

void Comm_ResetWorkAndParents(void) {
    u8 lock = sCommCore.updateLock;
    sCommCore.updateLock = 0;
    if (sCommCore.work != NULL) {
        Comm_Reset();
        CommWireless_ClearParents();
    }
    sCommCore.updateLock = lock;
}

static void Comm_UpdateChildSend(void) {
    int i;
    int count;

    if (Comm_IsWifiPeerLinkMode(CommState_GetLinkMode())) {
        if (sCommCore.work->wifiConnected) {
            if (sCommCore.work->continuousSend) {
                if (!Comm_HasNoChildBacklog()) {
                    return;
                }
                if (sCommSendStages.stage[1] == 4) {
                    Comm_BuildChildFrame(sCommCore.work->childFrames[0]);
                    sCommSendStages.stage[1] = 2;
                }
            } else if (sCommSendStages.stage[1] == 4) {
                if (!Comm_BuildChildFrame(sCommCore.work->childFrames[0])) {
                    return;
                }
                sCommSendStages.stage[1] = 2;
            }
            if (Comm_IsSendSkippedThisFrame()) {
                return;
            }
            if (WifiConnection_SendToAll(sCommCore.work->childFrames[0], 38)) {
                count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
                for (i = 0; i < count; i++) {
                    if (Comm_IsNetIdConnected((u16)i)) {
                        sCommCore.work->childSentFrames[i]++;
                    }
                }
                sCommSendStages.stage[1] = 4;
            }
        }
    } else if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        if (!sCommCore.work->wifiConnected) {
            return;
        }
        if (sCommCore.work->continuousSend) {
            if (sCommCore.work->sentFrames > 3) {
                return;
            }
            if (sCommSendStages.stage[1] == 4) {
                Comm_BuildChildFrame(sCommCore.work->childFrames[0]);
                sCommSendStages.stage[1] = 2;
            }
        } else if (sCommSendStages.stage[1] == 4) {
            if (!Comm_BuildChildFrame(sCommCore.work->childFrames[0])) {
                return;
            }
            sCommSendStages.stage[1] = 2;
        }
        if (Comm_IsSendSkippedThisFrame()) {
            return;
        }
        if (!WifiConnection_SendToHost(sCommCore.work->childFrames[0], 38)) {
            return;
        }
        sCommSendStages.stage[1] = 4;
        sCommCore.work->sentFrames++;
    } else if (Wireless_GetState() == WIRELESS_STATE_MP) {
        if (!Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
            return;
        }
        if (sCommSendStages.stage[1] == 4 && sCommCore.work->sentFrames <= 3) {
            Comm_BuildChildFrame(sCommCore.work->childFrames[sCommCore.work->childFrameIndex]);
            Comm_BuildChildFrame(sCommCore.work->childFrames[1 - sCommCore.work->childFrameIndex]);
            sCommSendStages.stage[1] = 0;
        }
        Comm_SendChildFrame();
    }
}

static BOOL Comm_FillParentFrameFromChildren(int slot) {
    int bad = 0;
    int stride = Comm_GetChildFrameSize((u16)CommState_GetLinkMode());
    int count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
    int i;

    for (i = 0; i < count; i++) {
        ByteRing_Commit(&sCommCore.work->childFrameRings[i]);
        if (Comm_IsNetIdConnected((u16)i)) {
            sCommCore.work->parentFrames[slot][i * stride] = 14;
        } else {
            bad++;
            sCommCore.work->parentFrames[slot][i * stride] = 0xFF;
            continue;
        }
        ByteRing_Read(&sCommCore.work->childFrameRings[i], &sCommCore.work->parentFrames[slot][i * stride], stride);
        if (sCommCore.work->parentFrames[slot][i * stride] == 14) {
            bad++;
        }
    }
    if (bad == count) {
        return FALSE;
    }
    return TRUE;
}

static void Comm_SendParentFrame(void) {
    int count;
    int i;

    if (sCommCore.work == NULL) {
        return;
    }
    if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        return;
    }
    Comm_GetChildFrameSize(CommState_GetLinkMode());
    count = Comm_GetMaxChildren(CommState_GetLinkMode()) + 1;
    if (sCommSendStages.stage[0] != 2 && sCommSendStages.stage[0] != 0) {
        return;
    }
    sCommSendStages.stage[0]++;
    if (Comm_GetTransferMode() == 1) {
        if (!sCommCore.initialized) {
            Comm_FillParentFrameFromChildren(sCommCore.work->parentFrameIndex);
            sCommCore.initialized = 1;
        }
    }
    if (Wireless_GetState() == WIRELESS_STATE_MP) {
        if (!Wireless_SendData(sCommCore.work->parentFrames[sCommCore.work->parentFrameIndex], 0xC0, 14, Comm_OnParentFrameSent)) {
            sCommSendStages.stage[0]--;
        }
    }
    if (sCommSendStages.stage[0] == 1 || sCommSendStages.stage[0] == 3) {
        sCommCore.initialized = 0;
        for (i = 0; i < count; i++) {
            if (Comm_IsNetIdConnected((u16)i)) {
                sCommCore.work->childSentFrames[i]++;
            }
        }
        Comm_OnParentFrameReceived(0, sCommCore.work->parentFrames[sCommCore.work->parentFrameIndex], 0xC0);
        sCommCore.work->parentFrameIndex = 1 - sCommCore.work->parentFrameIndex;
    }
    if (Wireless_GetState() != WIRELESS_STATE_MP) {
        sCommSendStages.stage[0]++;
    }
}

static BOOL Comm_HasNoChildBacklog(void) {
    int count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
    int i;
    for (i = 1; i < count; i++) {
        if (Comm_IsNetIdConnected((u16)i) && sCommCore.work->childSentFrames[i] > 3) {
            return FALSE;
        }
    }
    return TRUE;
}

static void Comm_UpdateParentSend(void) {
    int count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
    int i;

    if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        if (!Comm_IsNetIdConnected(0)) {
            return;
        }
        if (sCommCore.work->continuousSend) {
            if (!Comm_HasNoChildBacklog()) {
                return;
            }
            if (sCommSendStages.stage[0] == 4) {
                if (Comm_GetTransferMode() == 1) {
                    Comm_FillParentFrameFromChildren(0);
                }
                sCommSendStages.stage[0] = 2;
            }
        } else {
            if (sCommSendStages.stage[0] == 4) {
                if (Comm_GetTransferMode() == 1) {
                    if (!Comm_FillParentFrameFromChildren(0)) {
                        return;
                    }
                }
            }
            sCommSendStages.stage[0] = 2;
        }
        if (!WifiConnection_SendFromHost(sCommCore.work->parentFrames[0], sizeof(sCommCore.work->parentFrames[0]))) {
            return;
        }
        sCommSendStages.stage[0] = 4;
        for (i = 0; i < count; i++) {
            if (Comm_IsNetIdConnected((u16)i)) {
                sCommCore.work->childSentFrames[i]++;
            }
        }
    } else {
        if (Wireless_GetState() != WIRELESS_STATE_MP || sCommSendStages.stage[0] != 4 || !Comm_HasNoChildBacklog()) {
            return;
        }
        if (Comm_GetTransferMode() == 0) {
            Comm_BuildParentFrame(sCommCore.work->parentFrames[sCommCore.work->parentFrameIndex]);
            Comm_BuildParentFrame(sCommCore.work->parentFrames[1 - sCommCore.work->parentFrameIndex]);
        }
        sCommSendStages.stage[0] = 0;
        Comm_SendParentFrame();
    }
}

void Comm_RecvParentFrameCallback(int netId, const u8 *data, int size) {
    Comm_OnParentFrameReceived(netId, data, size);
}

static void Comm_OnParentFrameReceived(int netId, const u8 *data, int size) {
    int stride;
    int count;
    int i;

    sCommCore.work->sentFrames--;
    if (data == NULL) {
        return;
    }
    if (data[0] == 0xB) {
        if (Comm_GetTransferMode() == 1) {
            return;
        }
        data++;
    } else if (Comm_GetTransferMode() == 0) {
        return;
    }
    if (sCommCore.work->waitingParentFrame != 0 && (data[0] & 1)) {
        return;
    }
    sCommCore.work->waitingParentFrame = 0;
    if (Comm_GetTransferMode() == 1) {
        stride = Comm_GetChildFrameSize((u16)CommState_GetLinkMode());
        count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
        for (i = 0; i < count; i++) {
            if (data[0] == 0xFF) {
                sCommCore.work->connectedNetIds &= ~(1 << i);
            } else {
                sCommCore.work->connectedNetIds |= 1 << i;
            }
            if (data[0] == 0xFF) {
                data += stride;
                continue;
            }
            if (data[0] == 0xE) {
                data += stride;
                continue;
            }
            if (sCommCore.work->waitingFirstFrame[i] != 0 && (data[0] & 1)) {
                data += stride;
                continue;
            }
            data++;
            ByteRing_Write(&sCommCore.work->recvRings[i], data, stride - 1, i + 0x54C);
            data += stride - 1;
            sCommCore.work->waitingFirstFrame[i] = 0;
        }
    } else {
        sCommCore.work->connectedNetIds = data[1];
        sCommCore.work->connectedNetIds <<= 8;
        sCommCore.work->connectedNetIds += data[2];
        ByteRing_Write(&sCommCore.work->parentRecvRing, data + 4, data[3], 0x560);
    }
}

void Comm_RecvChildFrameCallback(int netId, const u8 *data, int size) {
    Comm_OnChildFrameReceived(netId, data, size);
}

static void Comm_OnChildFrameReceived(int slot, const u8 *data, int size) {
    int frameSize;

    sCommCore.work->childSentFrames[slot]--;
    if (data == NULL) {
        return;
    }
    if (sCommCore.work->waitingFirstFrame[slot] != 0 && (data[0] & 1) != 0) {
        return;
    }
    sCommCore.work->waitingFirstFrame[slot] = 0;
    if (Comm_GetTransferMode() == 1) {
        frameSize = Comm_GetChildFrameSize((u16)CommState_GetLinkMode());
        Comm_GetMaxChildren((u16)CommState_GetLinkMode());
        if ((data[0] & 2) == 0) {
            ByteRing_Write(&sCommCore.work->childFrameRings[slot], data, frameSize, 0x5A5);
        }
        sCommCore.work->childFrameCounts[slot]++;
    } else {
        Comm_ReadFrameKeys(data, slot);
        if ((data[0] & 2) == 0) {
            ByteRing_Write(&sCommCore.work->recvRings[slot], data + 1, 11, 0x5AE);
        }
    }
}

void Comm_RecvPeerFrameCallback(int slot, const u8 *data) {
    int frameSize;

    sCommCore.work->childSentFrames[slot]--;
    if (data == NULL) {
        return;
    }
    if (sCommCore.work->waitingFirstFrame[slot] != 0 && (data[0] & 1) != 0) {
        return;
    }
    sCommCore.work->waitingFirstFrame[slot] = 0;
    if (Comm_GetTransferMode() != 1) {
        return;
    }
    frameSize = Comm_GetChildFrameSize((u16)CommState_GetLinkMode());
    Comm_GetMaxChildren((u16)CommState_GetLinkMode());
    if (data[0] == 0xFF) {
        sCommCore.work->connectedNetIds &= ~(1 << slot);
    } else {
        sCommCore.work->connectedNetIds |= 1 << slot;
    }
    if (data[0] == 0xFF || data[0] == 2 || data[0] == 0xE) {
        return;
    }
    if (sCommCore.work->waitingFirstFrame[slot] != 0 && (data[0] & 1) != 0) {
        return;
    }
    ByteRing_Write(&sCommCore.work->recvRings[slot], data + 1, frameSize - 1, 0x5E7);
    sCommCore.work->waitingFirstFrame[slot] = 0;
}

static void Comm_OnChildFrameSent(BOOL success) {
    if (success) {
        sCommSendStages.stage[1]++;
    } else {
        GF_ASSERT(FALSE);
    }
}

static void Comm_OnParentFrameSent(BOOL success) {
    if (success) {
        sCommSendStages.stage[0]++;
    } else {
        GF_ASSERT(FALSE);
    }
}

static void Comm_SendChildFrame(void) {
    int frameSize;

    if (sCommCore.work == NULL) {
        return;
    }
    if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        return;
    }
    frameSize = Comm_GetChildFrameSize((u16)CommState_GetLinkMode());
    Comm_GetMaxChildren((u16)CommState_GetLinkMode());
    if (Wireless_GetState() != WIRELESS_STATE_MP) {
        return;
    }
    if (!Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        Comm_GetLocalNetId();
        return;
    }
    if (sCommSendStages.stage[1] == 2 || sCommSendStages.stage[1] == 0) {
        if (Comm_GetLocalNetId()) {
            sCommSendStages.stage[1]++;
            if (!Wireless_SendData(sCommCore.work->childFrames[sCommCore.work->childFrameIndex], frameSize, 14, Comm_OnChildFrameSent)) {
                sCommSendStages.stage[1]--;
                return;
            }
            sCommCore.work->childFrameIndex = 1 - sCommCore.work->childFrameIndex;
            sCommCore.work->sentFrames++;
        } else {
            if ((Wireless_GetConnectedBitmap() & 0xFFFE) == 0) {
                return;
            }
            sCommSendStages.stage[1]++;
            Comm_OnChildFrameSent(TRUE);
            Comm_OnChildFrameReceived(0, sCommCore.work->childFrames[sCommCore.work->childFrameIndex], (u16)frameSize);
            sCommCore.work->childFrameIndex = 1 - sCommCore.work->childFrameIndex;
            sCommCore.work->sentFrames++;
        }
    }
}

static inline u32 CommWork_Random(CommWork *w, u32 max) {
    CommRandom *rng = &w->random;
    rng->state = rng->multiplier * rng->state + rng->increment;
    return (u32)((((u64)rng->state >> 32) * max) >> 32);
}

static void Comm_ScrambleDirectionKeys(void) {
    CommWork *w = sCommCore.work;
    u16 result = 0;
    if (w->keyScrambleMode == 0 || !(w->heldKeys & PAD_PLUS_KEY_MASK)) {
        return;
    }
    if (w->keyScrambleMode == 2) {
        if (w->heldKeys & PAD_KEY_LEFT) {
            result |= PAD_KEY_RIGHT;
        }
        if (w->heldKeys & PAD_KEY_RIGHT) {
            result |= PAD_KEY_LEFT;
        }
        if (w->heldKeys & PAD_KEY_UP) {
            result |= PAD_KEY_DOWN;
        }
        if (w->heldKeys & PAD_KEY_DOWN) {
            result |= PAD_KEY_UP;
        }
    } else if (w->scrambleDirection != 0) {
        result = w->scrambleDirection;
        w->scrambleTimer--;
        if (sCommCore.work->scrambleTimer < 0) {
            sCommCore.work->scrambleDirection = 0;
        }
    } else {
        switch (CommWork_Random(w, 4)) {
        case 0:
            result = PAD_KEY_LEFT;
            break;
        case 1:
            result = PAD_KEY_RIGHT;
            break;
        case 2:
            result = PAD_KEY_UP;
            break;
        case 3:
            result = PAD_KEY_DOWN;
            break;
        }
        w = sCommCore.work;
        w->scrambleTimer = CommWork_Random(w, 16);
        sCommCore.work->scrambleDirection = result;
    }
    sCommCore.work->heldKeys &= ~PAD_PLUS_KEY_MASK;
    sCommCore.work->heldKeys += result;
}

static int Comm_ReadFrameKeys(const u8 *data, int slot) {
    u8 value;
    u8 direction;
    int decoded;

    sCommCore.work->directionKeys[slot] = 0;
    value = *data;
    if ((value & 0x10) == 0x10) {
        direction = value & 0x0c;
        if (direction == 0) {
            sCommCore.work->directionKeys[slot] |= 0x40;
        } else if (direction == 4) {
            sCommCore.work->directionKeys[slot] |= 0x80;
        } else if (direction == 8) {
            sCommCore.work->directionKeys[slot] |= 0x20;
        } else if (direction == 0x0c) {
            sCommCore.work->directionKeys[slot] |= 0x10;
        }
        decoded = *data >> 5;
        decoded &= 7;
        sCommCore.work->moveSpeeds[slot] = decoded;
    }
    return 1;
}

static int Comm_WriteFrameKeys(u8 *data) {
    u16 flags;
    if (sCommCore.work->keysLocked != 0) {
        return 0;
    }
    if (!Comm_IsKeySyncEnabled()) {
        return 0;
    }
    if (sCommCore.work->keySendTimer != 0) {
        sCommCore.work->keySendTimer--;
    }
    flags = sCommCore.work->heldKeys;
    if (flags & 0x40) {
        *data |= 0x10;
        sCommCore.work->keySendTimer = 8;
    } else if (flags & 0x80) {
        *data |= 0x14;
        sCommCore.work->keySendTimer = 8;
    } else if (flags & 0x20) {
        *data |= 0x18;
        sCommCore.work->keySendTimer = 8;
    } else if (flags & 0x10) {
        *data |= 0x1C;
        sCommCore.work->keySendTimer = 8;
    }
    *data |= sCommCore.work->localMoveSpeed << 5;
    return 0;
}

static int Comm_BuildChildFrame(u8 *data) {
    ByteWriter receive;
    int count = Comm_GetChildFrameSize((u16)CommState_GetLinkMode());

    Comm_GetMaxChildren((u16)CommState_GetLinkMode());
    if (sCommCore.work->childQueuePending == 0) {
        *data = 0;
    } else {
        *data = 1;
    }
    if (Comm_GetTransferMode() == 0) {
        Comm_WriteFrameKeys(data);
    }
    sCommCore.work->childQueuePending = 0;
    if (PacketPool_AllNodesFree(&sCommCore.work->childQueue)) {
        *data |= 2;
        if (*data == 2) {
            return 0;
        }
    } else {
        receive.remaining = count - 1;
        receive.dest = data + 1;
        if (!PacketPool_WriteFrame(&sCommCore.work->childQueue, &receive, 1)) {
            sCommCore.work->childQueuePending = 1;
        }
        if (Comm_GetTransferMode() == 1) {
            sCommCore.work->frameSequence++;
            *data |= (sCommCore.work->frameSequence << 4) & 0xF0;
        }
    }
    return 1;
}

static void Comm_BuildParentFrame(u8 *data) {
    ByteWriter receive;
    u16 value;

    data[0] = 0xB;
    if (sCommCore.work->parentQueuePending == 0) {
        data[1] = 0;
    } else {
        data[1] = 1;
    }
    value = Wireless_GetConnectedBitmap();
    data[2] = value >> 8;
    data[3] = value;
    receive.remaining = 0xBB;
    receive.dest = data + 5;
    if (PacketPool_WriteFrame(&sCommCore.work->parentQueue, &receive, 0)) {
        sCommCore.work->parentQueuePending = 0;
        data[4] = 0xBB - receive.remaining;
    } else {
        sCommCore.work->parentQueuePending = 1;
        data[4] = 0xBB;
    }
}

static BOOL Comm_IsSendSkippedThisFrame(void) {
    int divisor = sCommCore.work->sendSkipInterval;
    if (divisor == 0) {
        return FALSE;
    }
    if (sCommCore.work->frameCount % divisor == 0) {
        return TRUE;
    }
    return FALSE;
}

int Comm_SendCommandNoCopy(int command, void *data, int size) {
    if (!Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        return 0;
    }
    if (PacketPool_Enqueue(&sCommCore.work->childQueue, command, data, size, 1, 0)) {
        return 1;
    }
    if (CommState_GetLinkMode() == COMM_TYPE_10) {
        Comm_SetLinkError();
    }
    return 0;
}

int Comm_SendCommand(int command, void *data, int size) {
    if (!Comm_IsNetIdConnected(Comm_GetLocalNetId())) {
        return 0;
    }
    if (PacketPool_Enqueue(&sCommCore.work->childQueue, command, data, size, 1, 1)) {
        return 1;
    }
    if (CommState_GetLinkMode() == COMM_TYPE_10) {
        Comm_SetLinkError();
    }
    return 0;
}

int Comm_SendParentCommandNoCopy(int command, void *data, int size) {
    if (Comm_GetLocalNetId() != 0) {
        GF_ASSERT(FALSE);
        return 0;
    }
    if (!Comm_IsNetIdConnected(0)) {
        return 0;
    }
    if (Comm_GetTransferMode() == 1) {
        return Comm_SendCommandNoCopy(command, data, size);
    }
    if (PacketPool_Enqueue(&sCommCore.work->parentQueue, command, data, size, 1, 0)) {
        return 1;
    }
    if (CommState_GetLinkMode() == COMM_TYPE_10) {
        Comm_SetLinkError();
    }
    return 0;
}

int Comm_SendParentCommand(int command, void *data, int size) {
    if (Comm_GetLocalNetId() != 0) {
        Comm_SetLinkError();
        return 0;
    }
    if (!Comm_IsNetIdConnected(0)) {
        return 0;
    }
    if (Comm_GetTransferMode() == 1) {
        return Comm_SendCommand(command, data, size);
    }
    if (PacketPool_Enqueue(&sCommCore.work->parentQueue, command, data, size, 1, 1)) {
        return 1;
    }
    if (CommState_GetLinkMode() == COMM_TYPE_10) {
        Comm_SetLinkError();
    }
    return 0;
}

int Comm_SendFixedParentCommand(int command, void *data) {
    return Comm_SendParentCommand(command, data, 0);
}

int Comm_GetSendBufferFreeSpace(void) {
    return ByteRing_GetFreeSize(&sCommCore.work->childSendRing);
}

static void Comm_FinishCommand(int netId, int command, int size, void *data, PacketCursor *cursor) {
    Comm_CallCommandRecv(netId, command, size, data);
    cursor->command = 0xEE;
    cursor->size = 0xFFFF;
    cursor->data = NULL;
    cursor->received = 0;
}

static void Comm_ReceiveCommands(ByteRing *ring, int netId, u8 *buffer, PacketCursor *cursor) {
    while (ByteRing_GetReadableSize(ring)) {
        int command = cursor->command;
        if (command == 0xEE) {
            command = ByteRing_ReadByte(ring);
            if (command == 0xEE) {
                continue;
            }
        }
        int start = ring->read;
        cursor->command = command;
        int size = cursor->size;
        if (size == 0xFFFF) {
            size = Comm_GetCommandSize(command);
            if (sCommCore.work->linkError) {
                return;
            }
            if (size == 0xFFFF) {
                if (ByteRing_GetReadableSize(ring) < 1) {
                    ring->read = start;
                    return;
                }
                size = ByteRing_ReadByte(ring) << 8;
                size += ByteRing_ReadByte(ring);
                start = ring->read;
            }
            cursor->size = size;
        }
        if (Comm_CommandHasBuffer(command)) {
            if (!cursor->data) {
                cursor->data = Comm_GetCommandBuffer(command, netId, cursor->size);
            }
            int copied = ByteRing_Read(ring, buffer, size - cursor->received);
            if (cursor->data) {
                MI_CpuCopy8(buffer, cursor->data + cursor->received, copied);
            }
            cursor->received = (s32)((u32)cursor->received + (u32)copied);
            if (cursor->received >= size) {
                Comm_FinishCommand(netId, command, size, cursor->data, cursor);
                if (command == 17) {
                    break;
                }
            }
        } else {
            if (ByteRing_GetReadableSize(ring) >= size) {
                ByteRing_Read(ring, buffer, size);
                Comm_FinishCommand(netId, command, size, buffer, cursor);
                if (command == 17) {
                    break;
                }
            } else {
                ring->read = start;
                return;
            }
        }
    }
}

static void Comm_ReceiveFromParent(void) {
    if (sCommCore.work != NULL && sCommCore.work->receiveStopped == 0) {
        ByteRing_Commit(&sCommCore.work->parentRecvRing);
        if (ByteRing_GetReadableSize(&sCommCore.work->parentRecvRing) > 0) {
            Comm_ReceiveCommands(&sCommCore.work->parentRecvRing, 0, sCommCore.work->commandBuffer, &sCommCore.work->parentCursor);
        }
    }
}

static void Comm_ReceiveFromChildren(void) {
    int count;
    int i;

    if (sCommCore.work == NULL || sCommCore.work->receiveStopped != 0) {
        return;
    }
    count = Comm_GetMaxChildren((u16)CommState_GetLinkMode()) + 1;
    for (i = 0; i < count; i++) {
        ByteRing_Commit(&sCommCore.work->recvRings[i]);
        if (ByteRing_GetReadableSize(&sCommCore.work->recvRings[i]) > 0) {
            Comm_ReceiveCommands(&sCommCore.work->recvRings[i], i, sCommCore.work->commandBuffer, &sCommCore.work->recvCursors[i]);
        }
    }
}

int Comm_IsNetIdConnected(int slot) {
    if (sCommCore.work == NULL) {
        return 0;
    }
    if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        if (sCommCore.work->wifiConnected != 0) {
            u16 mask = DWC_GetAIDBitmap();
            if ((mask & (1 << slot)) != 0) {
                return 1;
            }
        }
        return 0;
    }
    if (!Comm_IsActive()) {
        return 0;
    }
    if (Wireless_GetState() != WIRELESS_STATE_MP) {
        return 0;
    }
    if (slot == Comm_GetLocalNetId()) {
        return 1;
    }
    if (Comm_GetLocalNetId() == 0) {
        if ((Wireless_GetConnectedBitmap() & (1 << slot)) != 0) {
            return 1;
        }
    } else if ((sCommCore.work->connectedNetIds & (1 << slot)) != 0) {
        return 1;
    }
    return 0;
}

int Comm_CountConnected(void) {
    int count = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (Comm_IsNetIdConnected((u16)i)) {
            count++;
        }
    }
    return count;
}

BOOL Comm_IsActive(void) {
    if (sCommCore.work != NULL && Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        return TRUE;
    }
    return CommWireless_Exists();
}

void Comm_SetLocalMoveSpeed(int value) {
    sCommCore.work->localMoveSpeed = value;
}

int Comm_GetMoveSpeed(int slot) {
    return sCommCore.work->moveSpeeds[slot];
}

u16 Comm_TakeDirectionKeys(int slot) {
    u16 value;
    if (sCommCore.work == NULL) {
        return 0;
    }
    value = sCommCore.work->directionKeys[slot];
    sCommCore.work->directionKeys[slot] = 0;
    return value;
}

void Comm_EnableKeySync(void) {
    if (sCommCore.work != NULL) {
        sCommCore.work->heldKeys |= 0x8000;
    }
}

void Comm_DisableKeySync(void) {
    if (sCommCore.work != NULL) {
        sCommCore.work->heldKeys = 0;
    }
}

static BOOL Comm_IsKeySyncEnabled(void) {
    if (sCommCore.work != NULL) {
        return sCommCore.work->heldKeys & 0x8000;
    }
    return TRUE;
}

int Comm_SendParentCommandNoCopyUnchecked(int command, void *data, int size) {
    if (Comm_GetTransferMode() == 1) {
        return PacketPool_Enqueue(&sCommCore.work->childQueue, command, data, size, 1, 0);
    }
    return PacketPool_Enqueue(&sCommCore.work->parentQueue, command, data, size, 1, 0);
}

static void Comm_UpdateTransferModeHandshake(void) {
    s32 result;

    if (sCommCore.work == NULL) {
        return;
    }
    switch (sCommCore.work->transferModeHandshake) {
    case 1:
        if (Comm_GetTransferMode() == 1) {
            result = Comm_SendFixedCommand(11, &sCommCore.work->requestedTransferMode);
        } else {
            result = Comm_SendParentCommand(11, &sCommCore.work->requestedTransferMode, 1);
        }
        if (result != 0) {
            sCommCore.work->transferModeHandshake = 2;
        }
        break;
    case 3:
        if (Comm_SendFixedCommand(12, &sCommCore.work->requestedTransferMode) != 0) {
            Comm_RequestTransferMode(sCommCore.work->requestedTransferMode);
            sCommCore.work->transferModeHandshake = 0;
        }
        break;
    }
}

void Comm_RecvTransferModeRequest(int netId, int size, void *data, void *context) {
    const u8 *mode = data;
    if (Comm_GetLocalNetId() == 0) {
        sCommCore.work->transferModeHandshake = 1;
        sCommCore.work->requestedTransferMode = *mode;
    }
}

void Comm_RecvTransferModeChange(int netId, int size, void *data, void *context) {
    const u8 *mode = data;
    if (Comm_GetLocalNetId() != 0) {
        sCommCore.work->requestedTransferMode = *mode;
        sCommCore.work->transferModeHandshake = 3;
    }
}

void Comm_RecvTransferModeAck(int netId, int size, void *data, void *context) {
    const u8 *mode = data;
    if (Comm_GetLocalNetId() == 0 && sCommCore.work->transferModeHandshake == 2) {
        Comm_RequestTransferMode(*mode);
        sCommCore.work->transferModeHandshake = 0;
    }
}

int Comm_GetLocalNetId(void) {
    if (sCommCore.work != NULL) {
        if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
            int id = WifiConnection_GetAid();
            if (id != -1) {
                return (u16)id;
            }
        } else {
            return Wireless_GetAid();
        }
    }
    return 0;
}

int Comm_SendFixedCommandNoCopy(int command, void *data) {
    return Comm_SendCommandNoCopy(command, data, 0);
}

int Comm_SendFixedCommand(int command, void *data) {
    return Comm_SendCommand(command, data, 0);
}

int Comm_SendEmptyCommand(int command) {
    return Comm_SendCommand(command, NULL, 0);
}

int Comm_GetConnectedChildren(void) {
    return CommWireless_GetConnectedChildren();
}

BOOL Comm_HasLinkError(void) {
    if (sCommCore.work != NULL && sCommCore.work->linkError != 0) {
        CommState_SetErrorWatch(TRUE, TRUE);
        return TRUE;
    }
    return CommWireless_IsLinkLost();
}

static int Comm_GetChildFrameSize(u16 linkMode) {
    if ((u32)Comm_GetMaxChildren(linkMode) >= 5) {
        return 12;
    }
    if (Comm_GetTransferMode() == 0) {
        return 12;
    }
    return 0x26;
}

int Comm_GetMaxPlayers(int value) {
    return Comm_GetMaxChildren((u16)value) + 1;
}

int Comm_GetMinPlayers(int value) {
    return Comm_GetMinChildren((u16)value) + 1;
}

void Comm_RecvShutdown(int netId, int size, void *data, void *context) {
    u8 value;
    if (!CommWireless_IsShutdownRequested() && !Comm_GetLocalNetId()) {
        Comm_SendFixedParentCommand(2, &value);
    }
    CommWireless_RequestShutdown();
}

void CommRandom_Init(CommRandom *seed) {
    RTCDate date;
    RTCTime time;

    GF_RTC_CopyDateTime(&date, &time);
    seed->state = (time.second + gSystem.vblankCounter) + ((time.minute + ((time.hour + ((date.day + ((date.month + ((u64)date.year << 4)) << 5)) << 5)) << 6)) << 6);
    seed->multiplier = 0x5D588B656C078965ULL;
    seed->increment = 0x269EC3;
}

BOOL Comm_ParentQueueHasCommand(int value) {
    return PacketPool_HasCommand(&sCommCore.work->parentQueue, value);
}

BOOL Comm_IsParentQueueEmpty(void) {
    return PacketPool_AllNodesFree(&sCommCore.work->parentQueue);
}

BOOL Comm_IsChildQueueEmpty(void) {
    return PacketPool_AllNodesFree(&sCommCore.work->childQueue);
}

void Comm_SetWifiConnected(int value) {
    sCommCore.work->wifiConnected = value;
}

BOOL Comm_IsWifiConnected(void) {
    return sCommCore.work->wifiConnected;
}

void Comm_SetBattleSlot(int value, int slot) {
    if (sCommCore.work != NULL) {
        sCommCore.work->battleSlots[slot] = value;
    }
}

int Comm_GetBattleSlot(int slot) {
    if (sCommCore.work != NULL) {
        if (sCommCore.work->battleSlots[slot] != 0xFF) {
            return sCommCore.work->battleSlots[slot];
        }
    }
    return slot;
}

int Comm_IsWifiVoiceChatEnabled(void) {
    if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        return WifiConnection_IsVoiceChatEnabled();
    }
    return 0;
}

void Comm_SetWifiContinuousSend(int value) {
    int i;
    if (Comm_IsWifiLinkMode(CommState_GetLinkMode()) && sCommCore.work->continuousSend != value) {
        sCommCore.work->continuousSend = value;
        if (value != 0) {
            sCommCore.work->sentFrames = 0;
            for (i = 0; i < 8; i++) {
                sCommCore.work->childSentFrames[i] = 0;
            }
        }
    }
}

void Comm_SetWifiContinuousSendAndMuteVoice(BOOL enabled) {
    Comm_SetWifiContinuousSend(enabled);
    if (Comm_IsWifiLinkMode(CommState_GetLinkMode())) {
        if (enabled) {
            WifiConnection_SetVoiceUnmuted(0);
        } else {
            WifiConnection_SetVoiceUnmuted(1);
        }
    }
}

BOOL Comm_IsSendingMoveKeys(void) {
    return sCommCore.work->keySendTimer != 0;
}

void Comm_SetLinkError(void) {
    sCommCore.work->linkError = 1;
}

void Comm_StopFrameUpdate(void) {
    if (sCommCore.work != NULL) {
        sCommCore.work->updateStopped = 1;
    }
}
