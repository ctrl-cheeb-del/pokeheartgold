#include "spin_trade_link.h"

#include "global.h"

#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_command.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "field_comm_cmds.h"
#include "heap.h"
#include "pokemon_types_def.h"
#include "union_room_objects.h"
#include "union_room_talk.h"
#include "wireless_manager.h"

typedef struct SpinTradeJoinRequest {
    u8 sender, count, command, accepted;
} SpinTradeJoinRequest;

u32 MATH_CountPopulation(u32 value);
typedef void (*SpinTradeLinkPacketHandler)(int, int, void *, SpinTradeLink *);
static BOOL SpinTradeLink_SendPacket(SpinTradeLink *link, u32 command, void *data, u32 size);
static void SpinTradeLink_ReceivePacket(int sender, int size, void *data, void *context);
static void SpinTradeLink_ReceiveParty(int sender, int size, void *data, void *context);
static void SpinTradeLink_HandleLeaderMenuState(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleSyncCount(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleStartSync(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleClearMessage(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleJoinRequest(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleMemberJoined(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleCloseYesNo(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleJoinNotice(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleStatus(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleJoin(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleSlot(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleCount(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleJump(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleSpin(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleTradeSlot(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleResult(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleCancel(int sender, int unused, void *data, SpinTradeLink *link);
static void SpinTradeLink_HandleConfirm(int sender, int unused, void *data, SpinTradeLink *link);
static u32 SpinTradeLink_GetPacketSize(void);
static u32 SpinTradeLink_GetPartySize(void);
static void *SpinTradeLink_GetPartyRecvBuffer(int sender, void *context, int size);
static int SpinTradeLink_CountMemberProfiles(void);

static const SpinTradeLinkPacketHandler sSpinTradeLinkPacketHandlers[] = {
    SpinTradeLink_HandleMemberJoined,
    SpinTradeLink_HandleClearMessage,
    SpinTradeLink_HandleJoinRequest,
    SpinTradeLink_HandleCloseYesNo,
    SpinTradeLink_HandleJoinNotice,
    SpinTradeLink_HandleStartSync,
    SpinTradeLink_HandleSyncCount,
    SpinTradeLink_HandleLeaderMenuState,
    SpinTradeLink_HandleStatus,
    SpinTradeLink_HandleJoin,
    SpinTradeLink_HandleJump,
    SpinTradeLink_HandleSpin,
    SpinTradeLink_HandleSlot,
    SpinTradeLink_HandleCount,
    SpinTradeLink_HandleTradeSlot,
    SpinTradeLink_HandleResult,
    SpinTradeLink_HandleCancel,
    SpinTradeLink_HandleConfirm,
};

static const CommCommand sSpinTradeLinkCommands[] = {
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { CommCmd_RecvIgnored,         CommCmd_GetSize0,            NULL                             },
    { SpinTradeLink_ReceivePacket, SpinTradeLink_GetPacketSize, NULL                             },
    { SpinTradeLink_ReceiveParty,  SpinTradeLink_GetPartySize,  SpinTradeLink_GetPartyRecvBuffer },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
    { NULL,                        NULL,                        NULL                             },
};

SpinTradeLink *SpinTradeLink_New(SpinTradeArgs *parent, enum HeapID heap) {
    SpinTradeLink *link = Heap_Alloc(heap, sizeof(SpinTradeLink));
    GF_ASSERT(link);
    memset(link, 0, sizeof(SpinTradeLink));
    link->parent = parent;
    link->partyRecvBuffer = Heap_Alloc(heap, sizeof(PartyCore) * 5);
    link->parties = Heap_Alloc(heap, sizeof(PartyCore) * 5);
    return link;
}

void SpinTradeLink_Free(SpinTradeLink *link) {
    Heap_Free(link->partyRecvBuffer);
    Heap_Free(link->parties);
    Heap_Free(link);
}

void SpinTradeLink_RegisterCommands(SpinTradeLink *link) {
    Comm_RegisterCommandTable(sSpinTradeLinkCommands, NELEMS(sSpinTradeLinkCommands), link);
}

void SpinTradeLink_Close(SpinTradeLink *link) {
    CommState_SetMaxEntries(2);
    CommState_ResumeAlternateSearch();
    UnionRoomObjects_ResetSlots(link->parent->input.communication);
    UnionRoom_SetBeaconActivity(UNION_ACTIVITY_NONE);
}

static BOOL SpinTradeLink_SendPacket(SpinTradeLink *link, u32 command, void *data, u32 size) {
    SpinTradeLinkPacket *packet;
    GF_ASSERT(command < NELEMS(sSpinTradeLinkPacketHandlers));
    GF_ASSERT(size + 4 <= sizeof(SpinTradeLinkPacket));
    packet = &link->packet;
    packet->command = command;
    memcpy(packet->data, data, size);
    return Comm_SendCommand(0x82, packet, sizeof(SpinTradeLinkPacket));
}

BOOL SpinTradeLink_SendCommand(SpinTradeLink *link, u32 command, void *data, u32 size) {
    if (link->blocked == 1) {
        return FALSE;
    }
    return SpinTradeLink_SendPacket(link, command, data, size);
}

static void SpinTradeLink_ReceivePacket(int sender, int size, void *data, void *context) {
    SpinTradeLinkPacket *packet = data;
    SpinTradeLink *link = context;

    if (packet->command >= NELEMS(sSpinTradeLinkPacketHandlers)) {
        GF_ASSERT(FALSE);
        return;
    }
    sSpinTradeLinkPacketHandlers[packet->command](sender, size, packet->data, link);
}

static void SpinTradeLink_ReceiveParty(int sender, int size, void *data, void *context) {
    SpinTradeLink *link = context;

    link->partyReceivedMask |= 1 << sender;
    memcpy(SpinTradeLink_GetReceivedParty(link, sender), data, sizeof(PartyCore));
}

static void SpinTradeLink_HandleLeaderMenuState(int sender, int unused, void *data, SpinTradeLink *link) {
    if (sender == 0) {
        link->leaderJoinPending = *(u8 *)data;
    }
}

static void SpinTradeLink_HandleSyncCount(int sender, int unused, void *data, SpinTradeLink *link) {
    link->count++;
}

static void SpinTradeLink_HandleStartSync(int sender, int unused, void *data, SpinTradeLink *link) {
    if (Comm_GetLocalNetId() != 0) {
        link->count = 0;
        link->state = 1;
        SpinTradeGroup_HandleLinkEvent(link->parent->groupApp, 31, (u8)sender);
    }
}

static void SpinTradeLink_HandleClearMessage(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTradeGroup_HandleLinkEvent(link->parent->groupApp, 2, 0);
}

static void SpinTradeLink_HandleJoinRequest(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTradeJoinRequest *src = data;
    if (sender != 0) {
        SpinTradeJoinRequest packet;
        if (Comm_GetLocalNetId() != 0) {
            return;
        }
        packet = *src;
        packet.sender = sender;
        packet.count = link->participantCount;
        switch (src->command) {
        case 0:
            if (link->participantCount != Comm_CountConnected() || link->participantCount != SpinTradeLink_CountMemberProfiles() || link->participantCount != MATH_CountPopulation(Wireless_GetConnectedBitmap())) {
                packet.accepted = 0;
            } else {
                link->leavingMask |= 1 << sender;
                packet.accepted = 1;
                CommState_SetMaxEntries(Comm_CountConnected());
            }
            break;
        case 1:
            break;
        }
        SpinTradeLink_SendCommand(link, SPIN_TRADE_CMD_JOIN_REQUEST, &packet, 4);
        return;
    }
    switch (src->command) {
    case 0: {
        int id = src->sender;
        if (id != Comm_GetLocalNetId()) {
            return;
        }
        if (src->accepted == 0) {
            SpinTradeGroup_HandleLinkEvent(link->parent->groupApp, 8, id);
            return;
        }
        link->assignedCount = src->count;
        SpinTradeGroup_HandleLinkEvent(link->parent->groupApp, 7, src->sender);
        return;
    }
    case 1:
        SpinTradeGroup_HandleLinkEvent(link->parent->groupApp, 19, src->sender);
        break;
    }
}

static void SpinTradeLink_HandleMemberJoined(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTradeGroup_HandleMemberEvent(link->parent->groupApp, 1, *(u8 *)data);
    if (Comm_GetLocalNetId() == 0) {
        link->unk34 = 0;
    }
}

static void SpinTradeLink_HandleCloseYesNo(int sender, int unused, void *data, SpinTradeLink *link) {
    if (Comm_GetLocalNetId() != 0) {
        SpinTradeGroup_HandleLinkEvent(link->parent->groupApp, 13, 0);
    }
}

static void SpinTradeLink_HandleJoinNotice(int sender, int unused, void *data, SpinTradeLink *link) {
    if (Comm_GetLocalNetId() == 0) {
        u8 id = sender;
        SpinTradeLink_SendCommand(link, SPIN_TRADE_CMD_MEMBER_JOINED, &id, 1);
    }
}

static void SpinTradeLink_HandleStatus(int sender, int unused, void *data, SpinTradeLink *link) {
    link->receivedStatus |= *(u16 *)data;
}

static void SpinTradeLink_HandleJoin(int sender, int unused, void *data, SpinTradeLink *link) {
    link->memberMask |= 1 << sender;
}

static void SpinTradeLink_HandleSlot(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTrade_ReceiveMemberSlot(link->parent->tradeApp, data);
}

static void SpinTradeLink_HandleCount(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTrade_ReceivePlayerCount(link->parent->tradeApp, *(u32 *)data);
}

static void SpinTradeLink_HandleJump(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTrade_ReceiveJump(link->parent->tradeApp, *(u8 *)data);
}

static void SpinTradeLink_HandleSpin(int sender, int unused, void *data, SpinTradeLink *link) {
    if (Comm_GetLocalNetId() != 0) {
        SpinTrade_ReceiveSpinData(link->parent->tradeApp, data);
    }
}

static void SpinTradeLink_HandleTradeSlot(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTrade_ReceiveTradeSlot(link->parent->tradeApp, sender, *(u32 *)data);
}

static void SpinTradeLink_HandleResult(int sender, int unused, void *data, SpinTradeLink *link) {
    SpinTrade_ReceiveResult(link->parent->tradeApp, data);
}

static void SpinTradeLink_HandleCancel(int sender, int unused, void *data, SpinTradeLink *link) {
    link->cancelMask |= 1 << sender;
}

static void SpinTradeLink_HandleConfirm(int sender, int unused, void *data, SpinTradeLink *link) {
    link->confirmMask |= 1 << sender;
}

static u32 SpinTradeLink_GetPacketSize(void) {
    return sizeof(SpinTradeLinkPacket);
}

static u32 SpinTradeLink_GetPartySize(void) {
    return sizeof(PartyCore);
}

static void *SpinTradeLink_GetPartyRecvBuffer(int sender, void *context, int size) {
    SpinTradeLink *link = context;

    return link->partyRecvBuffer + sender * sizeof(PartyCore);
}

static int SpinTradeLink_CountMemberProfiles(void) {
    int i, count = 0;
    for (i = 0; i < 5; i++) {
        if (CommPlayerInfo_GetProfile(i) != NULL) {
            count++;
        }
    }
    return count;
}

void *SpinTradeLink_GetReceivedParty(SpinTradeLink *link, int sender) {
    return link->parties + sender * sizeof(PartyCore);
}
