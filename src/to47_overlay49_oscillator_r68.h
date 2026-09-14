#ifndef TO47_OV49_RESIDUAL_68_PRIVATE_H
#define TO47_OV49_RESIDUAL_68_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

extern const s16 FX_SinCosTable_[];

typedef struct SolOsc49 {
    u16 angle;
    u16 step;
    s32 amplitude;
    s32 value;
} SolOsc49;

void ov49_022655F4(SolOsc49 *p, int angle, int step, int amplitude);
void ov49_02265628(SolOsc49 *p);

#endif
