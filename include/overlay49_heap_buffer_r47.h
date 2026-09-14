#ifndef POKEHEARTGOLD_OVERLAY49_HEAP_BUFFER_R47_H
#define POKEHEARTGOLD_OVERLAY49_HEAP_BUFFER_R47_H
#include "global.h"
typedef struct Ov49Buffer {
    u16 heapId;
    u8 pad_002[6];
    void *data;
} Ov49Buffer;
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
#endif
