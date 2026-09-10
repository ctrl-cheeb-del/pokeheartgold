#ifndef POKEHEARTGOLD_COMMUNICATION_PACKET_QUEUE_INTERNAL_H
#define POKEHEARTGOLD_COMMUNICATION_PACKET_QUEUE_INTERNAL_H
#include "global.h"
typedef struct W2ByteRing {
    u8 *data;
    s16 read;
    s16 limit;
    s16 write;
    s16 capacity;
} W2ByteRing;

typedef struct W2Node {
    u8 *data;
    struct W2Node *prev;
    struct W2Node *next;
    u16 value;
    u8 type;
    union {
        u8 raw;
        struct {
            u8 b0 : 1;
            u8 b1 : 1;
            u8 rest : 6;
        } b;
    } flags;
} W2Node;

typedef struct W2ByteWriter {
    u8 *dest;
    int remaining;
} W2ByteWriter;

typedef struct W2Queue {
    W2Node *head;
    W2Node *tail;
} W2Queue;

typedef struct W2Pool {
    W2Node *head;
    W2Node *tail;
    W2Node *head2;
    W2Node *tail2;
    W2Node *current;
    W2ByteRing *ring;
    W2Node *nodes;
    int count;
} W2Pool;

BOOL sub_02033C70(W2Queue *queue);
BOOL sub_02033C94(W2ByteWriter *writer, u8 value);
void sub_02033AF0(W2ByteRing *ring, const u8 *src, int count, int a3);
int sub_02033B4C(W2ByteRing *ring, u8 *dst, int count);
int sub_02033BE4(W2ByteRing *ring);
void sub_02033C28(W2ByteRing *ring);
W2Node *sub_02033C30(W2Pool *pool);
u32 sub_020341DC(int index);

BOOL sub_02033CB0(W2Node *node, W2ByteWriter *writer);
BOOL sub_02033D28(W2Node *node, W2ByteWriter *writer, W2ByteRing *ring, int force);
BOOL sub_02033DF0(W2Pool *pool, int index, u8 *data, int size, int a4, int a5);
W2Node *sub_02033E88(W2Pool *pool);
void sub_02033EA8(W2Pool *pool);
BOOL sub_02033ECC(W2Pool *pool, W2ByteWriter *writer, int next);

BOOL sub_02033CB0(W2Node *node, W2ByteWriter *writer);
BOOL sub_02033D28(W2Node *node, W2ByteWriter *writer, W2ByteRing *ring, int force);
BOOL sub_02033DF0(W2Pool *pool, int index, u8 *data, int size, int a4, int a5);
W2Node *sub_02033E88(W2Pool *pool);
void sub_02033EA8(W2Pool *pool);
BOOL sub_02033ECC(W2Pool *pool, W2ByteWriter *writer, int next);

#endif
