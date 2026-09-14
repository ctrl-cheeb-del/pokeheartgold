#ifndef POKEHEARTGOLD_R47_OVERLAY49_RESIDUAL_5_PRIVATE_H
#define POKEHEARTGOLD_R47_OVERLAY49_RESIDUAL_5_PRIVATE_H

#include "global.h"

typedef struct Ov49Residual5Context {
    u8 unk_00[4];
    void *unk_04;
    u8 unk_08[0x10];
    u8 unk_18;
} Ov49Residual5Context;

extern const u32 ov49_02269660[];
void ov49_02259A20(void *, void *, u32);
void ov49_02259A3C(void *, u32);
void ov49_02258BEC(Ov49Residual5Context *, int);
void ov49_02258C08(Ov49Residual5Context *, int);

#endif // POKEHEARTGOLD_R47_OVERLAY49_RESIDUAL_5_PRIVATE_H
