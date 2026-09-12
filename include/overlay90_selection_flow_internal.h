#ifndef POKEHEARTGOLD_OVERLAY90_SELECTION_FLOW_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY90_SELECTION_FLOW_INTERNAL_H

#include "global.h"

#include "sprite.h"

typedef struct Ov90SelectionEntry {
    u8 pad00[0x14];
    Sprite *sprite14;
    u8 pad18[0x1C];
    void *resource34;
} Ov90SelectionEntry;

typedef struct Ov90SelectionWork {
    u8 pad00[0x10];
    volatile u8 count;
    u8 pad11[0x1F3];
    Ov90SelectionEntry entries[1];
} Ov90SelectionWork;

void GF_AssertFail(void);
void ov90_022590C0(void *);
void ov90_0225917C(void *);
void ov90_0225A198(void *);
void ov90_02259200(void *, int);
void ov90_02259350(void *, int, void *, u8, u8, int);
void ov90_022592A8(void *, int, void *, u8, u8);
void ov90_022591F4(void *);
void ov90_02259210(void *, void *);
void ov90_02259220(void *, void *, int);
void ov90_02259234(void *, int, int);
void ov90_022592C4(void *, int, void *, u8, u8);

void ov90_02259B18(void *, Ov90SelectionWork *);
u32 ov90_02259B38(const u8 *, u32);
void ov90_02259D50(void *, void *, int, int, s16, int);
void ov90_02259DAC(void *, void *, int, void *, int, s16);
void ov90_02259E18(Ov90SelectionEntry *, int);
void ov90_02259E38(void *, void *, int, int, s16, int);

#endif
