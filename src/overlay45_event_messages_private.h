#ifndef POKEHEARTGOLD_OVERLAY45_EVENT_MESSAGES_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY45_EVENT_MESSAGES_PRIVATE_H

#include "global.h"

typedef struct ENode {
    u8 type;
    u8 padding_01[3];
    u32 a;
    u32 b;
    u32 c;
    void *strings[4];
    u16 v20;
    u16 v22;
    u16 v24;
    u16 v26;
    u16 rank;
    s16 timer;
    struct ENode *next;
    struct ENode *prev;
} ENode;

typedef struct EList {
    ENode nodes[8];
    ENode sentinel;
} EList;

typedef struct EWork {
    u8 type;
    u8 padding_01[3];
    u32 count;
    u32 count2;
    u32 x;
    void *strings[4];
    u16 vals[4];
} EWork;

#endif
