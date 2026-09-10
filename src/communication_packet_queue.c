#include "communication_packet_queue_internal.h"

BOOL sub_02033CB0(W2Node *node, W2ByteWriter *writer) {
    u32 value = sub_020341DC(node->type);
    if (value == 0xFFFF) {
        if (writer->remaining < 3) {
            node->flags.b.b0 = 0;
            return TRUE;
        }
    } else {
        if (writer->remaining < 1) {
            node->flags.b.b0 = 0;
            return TRUE;
        }
    }
    sub_02033C94(writer, node->type);
    if (value == 0xFFFF) {
        sub_02033C94(writer, (u8)(node->value >> 8));
        sub_02033C94(writer, (u8)node->value);
    } else {
        node->value = (u16)value;
    }
    node->flags.b.b0 = 1;
    return FALSE;
}

BOOL sub_02033D28(W2Node *node, W2ByteWriter *writer, W2ByteRing *ring, int force) {
    int extra;
    int i;
    if (sub_020341DC(node->type) == 0xFFFF) {
        extra = 3;
    } else {
        extra = 1;
    }
    if (writer->remaining < node->value + extra && force == 0) {
        return FALSE;
    }
    if (node->flags.b.b0 != 1) {
        if (sub_02033CB0(node, writer) != 0) {
            return FALSE;
        }
    }
    if (writer->remaining < node->value) {
        if (node->flags.b.b1) {
            sub_02033B4C(ring, writer->dest, writer->remaining);
        } else {
            for (i = 0; i < writer->remaining; i++) {
                writer->dest[i] = node->data[i];
            }
        }
        node->data += writer->remaining;
        node->value -= writer->remaining;
        writer->remaining = -1;
        return TRUE;
    } else {
        if (node->flags.b.b1) {
            sub_02033B4C(ring, writer->dest, node->value);
        } else {
            MI_CpuCopy8(node->data, writer->dest, node->value);
        }
        writer->dest += node->value;
        writer->remaining -= node->value;
        return TRUE;
    }
}

BOOL sub_02033DF0(W2Pool *pool, int index, u8 *data, int size, int a4, int a5) {
    W2Node *node;
    int value;
    node = sub_02033C30(pool);
    if (node == NULL) {
        return FALSE;
    }
    if (size >= 0xFFFE) {
        GF_AssertFail();
    }
    value = sub_020341DC(index);
    if (value == 0xFFFF) {
        value = size;
    }
    if (a5 != 0) {
        if (value + 3 >= sub_02033BE4(pool->ring)) {
            return FALSE;
        }
        sub_02033AF0(pool->ring, data, value, 0x109);
        sub_02033C28(pool->ring);
        node->flags.raw |= 2;
    }
    node->value = (u16)value;
    node->type = (u8)index;
    node->data = data;
    if (pool->tail == NULL) {
        pool->tail = node;
        pool->head = node;
    } else {
        pool->tail->next = node;
        node->prev = pool->tail;
        pool->tail = node;
    }
    return TRUE;
}

W2Node *sub_02033E88(W2Pool *pool) {
    if (pool->current != NULL) {
        return pool->current;
    }
    if (pool->head != NULL) {
        return pool->head;
    }
    if (pool->head2 != NULL) {
        return pool->head2;
    }
    return NULL;
}

void sub_02033EA8(W2Pool *pool) {
    if (pool->current != NULL) {
        pool->current = NULL;
        return;
    }
    if (!sub_02033C70((W2Queue *)pool)) {
        sub_02033C70((W2Queue *)&pool->head2);
    }
}

BOOL sub_02033ECC(W2Pool *pool, W2ByteWriter *writer, int next) {
    W2Node *node;
    int flag = 1;
    int i;
    while (writer->remaining > 0) {
        node = sub_02033E88(pool);
        if (node == NULL) {
            break;
        }
        sub_02033EA8(pool);
        if (!sub_02033D28(node, writer, pool->ring, flag)) {
            pool->current = node;
            break;
        }
        if (writer->remaining == -1) {
            pool->current = node;
            return FALSE;
        }
        MI_CpuFill8(node, 0, 16);
        flag = next;
    }
    for (i = 0; i < writer->remaining; i++) {
        *writer->dest = 0xEE;
        writer->dest++;
    }
    return TRUE;
}
