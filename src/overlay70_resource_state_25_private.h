#ifndef OV70_RESIDUAL25_PRIVATE_H
#define OV70_RESIDUAL25_PRIVATE_H
#include "global.h"

#include "heap.h"
#include "pm_string.h"
#include "screen_fade.h"
#include "system.h"

typedef struct Ov70Alloc25 {
    u8 pad00[0x14];
    void *secondary;
    void *primary;
    u32 count;
    u8 pad20[0x30 - 0x20];
} Ov70Alloc25;

typedef struct Ov70Work25 {
    u8 pad00[0x2c];
    u32 state;
    u8 pad30[0xbbc - 0x30];
    String *string;
    u8 padbc0[0x11a8 - 0xbc0];
    void *manager;
    u8 pad11ac[0x11c4 - 0x11ac];
    Ov70Alloc25 *allocation;
    u8 pad11c8[0x1234 - 0x11c8];
    u8 pairs[1];
} Ov70Work25;

void ov70_0223ECCC(Ov70Work25 *);
void ov70_0223ED24(Ov70Work25 *);
int ov70_0223ED58(Ov70Work25 *);
int ov70_0223ED8C(Ov70Work25 *);
int ov70_0223EDB0(Ov70Work25 *);

void *ov70_0223F634(enum HeapID heapId, int member, u32 *sizeOut);
void *ov70_0223F684(enum HeapID heapId);
void ov70_0223F948(void *pairs);
int ov70_0223E8E8(Ov70Work25 *, int, int, int, int);
void ov70_02238D84(Ov70Work25 *, int, int);
void ov70_02238E50(Ov70Work25 *, int, int);
void ov70_022420C4(void *, int);
#endif
