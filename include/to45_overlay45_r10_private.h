#ifndef TO45_OVERLAY45_R10_PRIVATE_H
#define TO45_OVERLAY45_R10_PRIVATE_H

#include "global.h"

typedef struct Overlay45Residual10State {
    u8 padding_000[0x38];
    u8 state_038;
    u8 mode_039;
    u16 value_03A;
} Overlay45Residual10State;

typedef struct Overlay45Residual10Entry {
    u16 value;
    u16 padding_02;
} Overlay45Residual10Entry;

extern const Overlay45Residual10Entry ov45_02254A84[16];
extern u16 ov45_0222CD04(u16 value);

u32 ov45_0222A9CC(Overlay45Residual10State *state);
u32 ov45_0222AA10(Overlay45Residual10State *state);
BOOL ov45_0222AA28(Overlay45Residual10State *state);

#endif
