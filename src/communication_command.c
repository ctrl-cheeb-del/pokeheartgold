#include "communication_command.h"

#include "global.h"

#include "constants/comm_type.h"
#include "comm_state_internal.h"
#include "link_synchronization_internal.h"

#include "assert.h"
#include "communication_core.h"
#include "communication_packet_pool.h"
#include "communication_player_state.h"
#include "heap.h"

// Link command layer: byte rings and packet queues that cut the outgoing commands into frames, and the command
// table: the communication layer's own commands, followed by the table an application registers.

typedef struct CommCommandTable {
    const CommCommand *commands;
    int count;
    void *context;
    u8 ready[8]; // per net id, kept by the parent
    u8 shutdown;
} CommCommandTable;

static CommCommandTable *sCommCommandTable;

static int ByteRing_Peek(ByteRing *ring, u8 *dst, int count);
static s32 ByteRing_GetWritableSize(const ByteRing *ring);
static s32 ByteRing_Wrap(const ByteRing *ring, s32 pos);
static PacketNode *PacketPool_GetFreeNode(const PacketPool *pool);
static BOOL PacketQueue_PopFront(PacketQueue *queue);
static BOOL ByteWriter_PutByte(ByteWriter *writer, u8 value);
static BOOL Packet_WriteHeader(PacketNode *node, ByteWriter *writer);
static BOOL Packet_Write(PacketNode *node, ByteWriter *writer, ByteRing *ring, int force);
static PacketNode *PacketPool_PeekNext(PacketPool *pool);
static void PacketPool_PopNext(PacketPool *pool);
static u32 CommCmd_GetSize2(void);
static void CommCmd_RecvReady(int netId, int size, void *data, void *context);
static void CommCmd_RecvShutdown(int netId, int size, void *data, void *context);
static void CommCmd_RecvNotReady(int netId, int size, void *data, void *context);

void Comm_RecvShutdown(int netId, int size, void *data, void *context);
void Comm_RecvTransferModeRequest(int netId, int size, void *data, void *context);
void Comm_RecvTransferModeChange(int netId, int size, void *data, void *context);
void Comm_RecvTransferModeAck(int netId, int size, void *data, void *context);

static const CommCommand sCommBaseCommands[COMM_BASE_COMMAND_COUNT] = {
    { NULL,                           CommCmd_GetSize0,             NULL },
    { NULL,                           CommCmd_GetSize0,             NULL },
    { Comm_RecvShutdown,              CommCmd_GetSize0,             NULL },
    { CommPlayerInfo_RecvPlayerEntry, CommPlayerInfo_GetEntrySize,  NULL },
    { CommPlayerInfo_RecvEntry,       CommPlayerInfo_GetEntrySize,  NULL },
    { CommPlayerInfo_RecvSetUnk3A4,   CommCmd_GetSize0,             NULL },
    { CommState_RecvJoinRequest,      CommState_GetJoinMessageSize, NULL },
    { CommState_RecvJoinReply,        CommState_GetJoinMessageSize, NULL },
    { NULL,                           NULL,                         NULL },
    { NULL,                           NULL,                         NULL },
    { Comm_RecvTransferModeRequest,   CommCmd_GetSize1,             NULL },
    { Comm_RecvTransferModeChange,    CommCmd_GetSize1,             NULL },
    { Comm_RecvTransferModeAck,       CommCmd_GetSize1,             NULL },
    { CommCmd_RecvReady,              CommCmd_GetSize0,             NULL },
    { CommCmd_RecvShutdown,           CommCmd_GetSize0,             NULL },
    { CommCmd_RecvNotReady,           CommCmd_GetSize0,             NULL },
    { LinkSync_RecvRequest,           CommCmd_GetSize1,             NULL },
    { LinkSync_RecvDone,              CommCmd_GetSize1,             NULL },
    { LinkSync_RecvState,             CommCmd_GetSize2,             NULL },
    { LinkSync_RecvValue,             LinkSync_GetValueSize,        NULL },
    { LinkSync_RecvPacket,            CommState_GetSyncPacketSize,  NULL },
    { CommState_RecvWifiDisconnect,   CommCmd_GetSize0,             NULL },
};

void ByteRing_Init(ByteRing *ring, u8 *data, int capacity) {
    ring->data = data;
    ring->capacity = capacity;
    ring->read = 0;
    ring->limit = 0;
    ring->write = 0;
}

void ByteRing_Write(ByteRing *ring, const u8 *src, int count, int unused) {
    int pos;
    int i;
    if (ByteRing_GetWritableSize(ring) <= count) {
        Comm_SetLinkError();
        return;
    }
    pos = ring->write;
    i = 0;
    while (pos < ring->write + count) {
        GF_ASSERT(src != NULL);
        ring->data[ByteRing_Wrap(ring, pos)] = src[i];
        pos++;
        i++;
    }
    ring->write = ByteRing_Wrap(ring, pos);
}

int ByteRing_Read(ByteRing *ring, u8 *dst, int count) {
    int n = ByteRing_Peek(ring, dst, count);
    ring->read = ByteRing_Wrap(ring, ring->read + n);
    return n;
}

u8 ByteRing_ReadByte(ByteRing *ring) {
    u8 value;
    ByteRing_Read(ring, &value, 1);
    return value;
}

static int ByteRing_Peek(ByteRing *ring, u8 *dst, int count) {
    int pos = ring->read;
    int i = 0;
    for (; pos < ring->read + count; pos++) {
        int index = ByteRing_Wrap(ring, pos);
        if (ring->limit == index) {
            return i;
        }
        dst[i++] = ring->data[ByteRing_Wrap(ring, pos)];
    }
    return i;
}

s32 ByteRing_GetReadableSize(const ByteRing *ring) {
    s16 read = ring->read;
    if (read > ring->limit) {
        return ring->capacity + ring->limit - read;
    }
    return ring->limit - read;
}

s32 ByteRing_GetFreeSize(const ByteRing *ring) {
    return ring->capacity - ByteRing_GetReadableSize(ring);
}

static s32 ByteRing_GetWritableSize(const ByteRing *ring) {
    s16 read = ring->read;
    if (read > ring->write) {
        return read - ring->write;
    }
    return ring->capacity - (ring->write - read);
}

static s32 ByteRing_Wrap(const ByteRing *ring, s32 pos) {
    return pos % ring->capacity;
}

void ByteRing_Commit(ByteRing *ring) {
    ring->limit = ring->write;
}

static PacketNode *PacketPool_GetFreeNode(const PacketPool *pool) {
    PacketNode *node = pool->nodes;
    s32 i;
    s32 count = pool->count;
    for (i = 0; i < count; i++, node++) {
        if (node->command == 0) {
            return node;
        }
    }
    return NULL;
}

BOOL PacketPool_AllNodesFree(const PacketPool *pool) {
    PacketNode *node = pool->nodes;
    s32 i;
    s32 count = pool->count;
    for (i = 0; i < count; i++, node++) {
        if (node->command != 0) {
            return FALSE;
        }
    }
    return TRUE;
}

static BOOL PacketQueue_PopFront(PacketQueue *queue) {
    if (queue->head != NULL) {
        if (queue->head->next != NULL) {
            queue->head = queue->head->next;
            queue->head->prev = NULL;
        } else {
            queue->head = NULL;
            queue->tail = NULL;
        }
        return TRUE;
    }
    return FALSE;
}

static BOOL ByteWriter_PutByte(ByteWriter *writer, u8 value) {
    *writer->dest = value;
    writer->dest++;
    writer->remaining--;
    if (writer->remaining == 0) {
        return TRUE;
    }
    return FALSE;
}

// The command byte, followed by the size for variable-size commands; TRUE when it does not fit.
static BOOL Packet_WriteHeader(PacketNode *node, ByteWriter *writer) {
    u32 size = Comm_GetCommandSize(node->command);
    if (size == 0xFFFF) {
        if (writer->remaining < 3) {
            node->flags.b.headerWritten = 0;
            return TRUE;
        }
    } else {
        if (writer->remaining < 1) {
            node->flags.b.headerWritten = 0;
            return TRUE;
        }
    }
    ByteWriter_PutByte(writer, node->command);
    if (size == 0xFFFF) {
        ByteWriter_PutByte(writer, node->size >> 8);
        ByteWriter_PutByte(writer, node->size);
    } else {
        node->size = size;
    }
    node->flags.b.headerWritten = 1;
    return FALSE;
}

static BOOL Packet_Write(PacketNode *node, ByteWriter *writer, ByteRing *ring, int force) {
    int headerSize;
    int i;
    if (Comm_GetCommandSize(node->command) == 0xFFFF) {
        headerSize = 3;
    } else {
        headerSize = 1;
    }
    if (writer->remaining < node->size + headerSize && force == 0) {
        return FALSE;
    }
    if (node->flags.b.headerWritten != 1) {
        if (Packet_WriteHeader(node, writer)) {
            return FALSE;
        }
    }
    if (writer->remaining < node->size) {
        if (node->flags.b.inRing) {
            ByteRing_Read(ring, writer->dest, writer->remaining);
        } else {
            for (i = 0; i < writer->remaining; i++) {
                writer->dest[i] = node->data[i];
            }
        }
        node->data += writer->remaining;
        node->size -= writer->remaining;
        writer->remaining = -1;
        return TRUE;
    } else {
        if (node->flags.b.inRing) {
            ByteRing_Read(ring, writer->dest, node->size);
        } else {
            MI_CpuCopy8(node->data, writer->dest, node->size);
        }
        writer->dest += node->size;
        writer->remaining -= node->size;
        return TRUE;
    }
}

BOOL PacketPool_Enqueue(PacketPool *pool, int command, u8 *data, int size, int a4, int copyToRing) {
    PacketNode *node;
    int packetSize;
    node = PacketPool_GetFreeNode(pool);
    if (node == NULL) {
        return FALSE;
    }
    GF_ASSERT(size < 0xFFFE);
    packetSize = Comm_GetCommandSize(command);
    if (packetSize == 0xFFFF) {
        packetSize = size;
    }
    if (copyToRing != 0) {
        if (packetSize + 3 >= ByteRing_GetFreeSize(pool->ring)) {
            return FALSE;
        }
        ByteRing_Write(pool->ring, data, packetSize, 0x109);
        ByteRing_Commit(pool->ring);
        node->flags.raw |= 2;
    }
    node->size = packetSize;
    node->command = command;
    node->data = data;
    if (pool->queue.tail == NULL) {
        pool->queue.tail = node;
        pool->queue.head = node;
    } else {
        pool->queue.tail->next = node;
        node->prev = pool->queue.tail;
        pool->queue.tail = node;
    }
    return TRUE;
}

static PacketNode *PacketPool_PeekNext(PacketPool *pool) {
    if (pool->current != NULL) {
        return pool->current;
    }
    if (pool->queue.head != NULL) {
        return pool->queue.head;
    }
    if (pool->queue2.head != NULL) {
        return pool->queue2.head;
    }
    return NULL;
}

static void PacketPool_PopNext(PacketPool *pool) {
    if (pool->current != NULL) {
        pool->current = NULL;
        return;
    }
    if (!PacketQueue_PopFront(&pool->queue)) {
        PacketQueue_PopFront(&pool->queue2);
    }
}

// Fills the writer with queued packets; the rest of the frame is padded with 0xEE.
BOOL PacketPool_WriteFrame(PacketPool *pool, ByteWriter *writer, int next) {
    PacketNode *node;
    int force = 1;
    int i;
    while (writer->remaining > 0) {
        node = PacketPool_PeekNext(pool);
        if (node == NULL) {
            break;
        }
        PacketPool_PopNext(pool);
        if (!Packet_Write(node, writer, pool->ring, force)) {
            pool->current = node;
            break;
        }
        if (writer->remaining == -1) {
            pool->current = node;
            return FALSE;
        }
        MI_CpuFill8(node, 0, 16);
        force = next;
    }
    for (i = 0; i < writer->remaining; i++) {
        *writer->dest = 0xEE;
        writer->dest++;
    }
    return TRUE;
}

void PacketPool_Init(PacketPool *pool, int count, ByteRing *ring) {
    int size;
    MI_CpuFill8(pool, 0, sizeof(PacketPool));
    size = count * sizeof(PacketNode);
    pool->nodes = Heap_Alloc(HEAP_ID_15, size);
    MI_CpuFill8(pool->nodes, 0, size);
    pool->count = count;
    pool->ring = ring;
}

void PacketPool_Reset(PacketPool *pool) {
    MI_CpuFill8(pool->nodes, 0, pool->count * sizeof(PacketNode));
    pool->queue.head = NULL;
    pool->queue.tail = NULL;
    pool->queue2.head = NULL;
    pool->queue2.tail = NULL;
    pool->current = NULL;
}

void PacketPool_Free(PacketPool *pool) {
    Heap_Free(pool->nodes);
}

BOOL PacketPool_HasCommand(PacketPool *pool, int command) {
    int i;
    PacketNode *node = pool->nodes;
    for (i = 0; i < pool->count; i++, node++) {
        if (node->command == command) {
            return TRUE;
        }
    }
    return FALSE;
}

int Comm_GetMaxChildren(u16 linkMode) {
    u8 maxChildren[] = { 1, 1, 1, 1, 3, 3, 3, 4, 3, 4, 7, 3, 7, 4, 1, 4, 1, 1, 4, 1, 1, 1, 1, 3, 0, 0, 4, 1, 1, 2, 1, 1, 1, 3, 1, 3, 0, 1, 1, 1, 3 };
    GF_ASSERT(linkMode < NELEMS(maxChildren));
    return maxChildren[linkMode];
}

int Comm_GetMinChildren(u16 linkMode) {
    u8 minChildren[] = { 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 };
    GF_ASSERT(linkMode < NELEMS(minChildren));
    return minChildren[linkMode];
}

BOOL Comm_IsUnionRoomLinkMode(int v) {
    switch (v) {
    case COMM_TYPE_MIX_RECORDS:
    case COMM_TYPE_UNION:
    case COMM_TYPE_13:
    case COMM_TYPE_UNION_APP:
    case COMM_TYPE_SPIN_TRADE:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL Comm_IsWifiLinkMode(int v) {
    switch (v) {
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 29:
    case 33:
    case 34:
    case 35:
    case 36:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL Comm_IsWifiPeerLinkMode(int v) {
    if (v == COMM_TYPE_29 || v == COMM_TYPE_WIFI_PLAZA || v == COMM_TYPE_CLUB_WIFI) {
        return TRUE;
    }
    return FALSE;
}

BOOL Comm_IsLinkMode19To23Or34(int v) {
    switch (v) {
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 34:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL Comm_IsCommClubLinkMode(int v) {
    switch (v) {
    case COMM_TYPE_SINGLE_BATTLE:
    case COMM_TYPE_DOUBLE_BATTLE:
    case COMM_TYPE_MIX_BATTLE:
    case COMM_TYPE_MULTI_BATTLE_1:
    case COMM_TYPE_MULTI_BATTLE_2:
    case COMM_TYPE_8:
    case COMM_TYPE_FLAT_BATTLE_1:
    case COMM_TYPE_FLAT_BATTLE_2:
    case COMM_TYPE_SAFARI_ZONE:
    case COMM_TYPE_POKEATHLON:
        return TRUE;
    default:
        return FALSE;
    }
}

void Comm_RegisterCommandTable(const void *commands, int count, void *context) {
    int i;
    if (sCommCommandTable == NULL) {
        sCommCommandTable = Heap_Alloc(HEAP_ID_15, sizeof(CommCommandTable));
    }
    sCommCommandTable->commands = commands;
    sCommCommandTable->count = count;
    sCommCommandTable->context = context;
    for (i = 0; i < 8; i++) {
        sCommCommandTable->ready[i] = 0;
    }
    sCommCommandTable->shutdown = 0;
}

void Comm_FreeCommandTable(void) {
    if (sCommCommandTable != NULL) {
        Heap_Free(sCommCommandTable);
        sCommCommandTable = NULL;
    }
}

void Comm_CallCommandRecv(int netId, int command, int size, void *data) {
    CommCmdRecvFunc func;
    if (command < COMM_BASE_COMMAND_COUNT) {
        func = sCommBaseCommands[command].recv;
    } else {
        GF_ASSERT(sCommCommandTable != NULL);
        if (command > sCommCommandTable->count + COMM_BASE_COMMAND_COUNT) {
            Comm_SetLinkError();
            return;
        }
        func = sCommCommandTable->commands[command - COMM_BASE_COMMAND_COUNT].recv;
    }
    if (func != NULL) {
        if (sCommCommandTable != NULL) {
            func(netId, size, data, sCommCommandTable->context);
        } else {
            func(netId, size, data, NULL);
        }
    }
}

u32 Comm_GetCommandSize(int command) {
    CommCmdSizeFunc func;
    u32 result = 0;
    if (command < COMM_BASE_COMMAND_COUNT) {
        func = sCommBaseCommands[command].getSize;
    } else {
        GF_ASSERT(sCommCommandTable != NULL);
        if (sCommCommandTable == NULL) {
            Comm_SetLinkError();
            return 0;
        }
        if (command > sCommCommandTable->count + COMM_BASE_COMMAND_COUNT) {
            GF_ASSERT(FALSE);
            Comm_SetLinkError();
            return 0;
        }
        func = sCommCommandTable->commands[command - COMM_BASE_COMMAND_COUNT].getSize;
    }
    if (func != NULL) {
        result = func();
    }
    return result;
}

BOOL Comm_CommandHasBuffer(int command) {
    if (command < COMM_BASE_COMMAND_COUNT) {
        if (sCommBaseCommands[command].getBuffer != NULL) {
            return TRUE;
        }
        return FALSE;
    } else {
        if (sCommCommandTable->commands[command - COMM_BASE_COMMAND_COUNT].getBuffer != NULL) {
            return TRUE;
        }
        return FALSE;
    }
}

void *Comm_GetCommandBuffer(int command, int netId, int size) {
    if (command < COMM_BASE_COMMAND_COUNT) {
        return sCommBaseCommands[command].getBuffer(netId, NULL, size);
    }
    return sCommCommandTable->commands[command - COMM_BASE_COMMAND_COUNT].getBuffer(netId, sCommCommandTable->context, size);
}

u32 CommCmd_GetSizeVariable(void) {
    return 0xFFFF;
}

u32 CommCmd_GetSize0(void) {
    return 0;
}

u32 CommCmd_GetSize1(void) {
    return 1;
}

static u32 CommCmd_GetSize2(void) {
    return 2;
}

// The parent counts the players ready to switch command tables; once all are, it sends command 14.
static void CommCmd_RecvReady(int netId, int size, void *data, void *context) {
    int i;
    if (Comm_GetLocalNetId() == 0) {
        sCommCommandTable->ready[netId] = 1;
        for (i = 0; i < 8; i++) {
            if (Comm_IsNetIdConnected(i) && sCommCommandTable->ready[i] == 0) {
                return;
            }
        }
        Comm_SendParentCommand(14, NULL, 0);
    }
}

static void CommCmd_RecvShutdown(int netId, int size, void *data, void *context) {
    sCommCommandTable->commands = NULL;
    sCommCommandTable->count = 0;
    sCommCommandTable->context = NULL;
    sCommCommandTable->shutdown = 1;
    Comm_SendFixedCommand(15, data);
}

static void CommCmd_RecvNotReady(int netId, int size, void *data, void *context) {
    if (Comm_GetLocalNetId() == 0) {
        sCommCommandTable->ready[netId] = 0;
    }
}
