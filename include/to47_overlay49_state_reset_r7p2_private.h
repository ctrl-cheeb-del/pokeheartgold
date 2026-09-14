#ifndef POKEHEARTGOLD_TO47_OVERLAY49_STATE_RESET_R7P2_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY49_STATE_RESET_R7P2_PRIVATE_H

#include "global.h"

typedef struct Ov49Res7P2State {
    u8 pad00[8];
    u16 unk08;
    u8 unk0A;
    u8 unk0B;
    u8 unk0C[24];
    u32 unk24;
} Ov49Res7P2State;

typedef void (*Ov49Res7P2Callback)(Ov49Res7P2State *, void *);

extern Ov49Res7P2Callback ov49_02269698[];
extern u32 ov49_022696C0[];

void ov49_02258EEC(void *, Ov49Res7P2State *, int);

#endif
