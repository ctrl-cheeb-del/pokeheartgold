#ifndef POKEHEARTGOLD_FRONTIER_APPLICATION_INTERNAL_H
#define POKEHEARTGOLD_FRONTIER_APPLICATION_INTERNAL_H

#include "global.h"

#include "heap.h"

typedef struct Input97024 {
    u8 sendData[4];
    u32 frame;
    void *saveData;
    void *communication;
    void *options;
    void *gameStats;
    void *fieldSystem;
} Input97024;

typedef struct Work97024 {
    u32 unk0[4];
    u32 result;
    Input97024 input;
    void *menu;
    void *field34;
    void *field38;
} Work97024;

void *sub_02096C88(Work97024 *work, enum HeapID heapID);
void sub_02096CF4(void *ptr);
void sub_02096CC8(void *ptr);

#endif
