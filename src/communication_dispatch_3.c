#include "communication_dispatch_internal.h"

void sub_02033F44(PacketPool *pool, int count, void *ring) {
    int size;
    MI_CpuFill8(pool, 0, sizeof(PacketPool));
    size = count * sizeof(PoolNode);
    pool->nodes = Heap_Alloc(HEAP_ID_15, size);
    MI_CpuFill8(pool->nodes, 0, size);
    pool->count = count;
    pool->ring = ring;
}

void sub_02033F70(PacketPool *pool) {
    MI_CpuFill8(pool->nodes, 0, pool->count * sizeof(PoolNode));
    pool->head = NULL;
    pool->tail = NULL;
    pool->unk08 = NULL;
    pool->unk0C = NULL;
    pool->current = NULL;
}

void sub_02033F90(PacketPool *pool) {
    Heap_Free(pool->nodes);
}

BOOL sub_02033F9C(PacketPool *pool, u8 type) {
    int i;
    PoolNode *node = pool->nodes;
    for (i = 0; i < pool->count; i++, node++) {
        if (node->type == type) {
            return TRUE;
        }
    }
    return FALSE;
}
