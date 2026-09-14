#ifndef POKEHEARTGOLD_TO45_OVERLAY45_R19_PRIVATE_H
#define POKEHEARTGOLD_TO45_OVERLAY45_R19_PRIVATE_H

#include "global.h"

typedef struct Ov45R19State {
    u32 flags;
    u16 value;
    u8 mode;
    u8 padding_07[3];
    u8 byte_0A;
    u8 padding_0B;
    u8 counters[20];
} Ov45R19State;

void ov45_0222BE54(Ov45R19State *state);
void ov45_0222BD4C(Ov45R19State *state);
void ov45_0222BD5C(Ov45R19State *state);
BOOL ov45_0222BD74(Ov45R19State *state, u32 index);
void ov45_0222BD94(Ov45R19State *state, u32 index);
void ov45_0222BDB0(Ov45R19State *state, u32 index);
void ov45_0222BDCC(Ov45R19State *state, u32 index);
void ov45_0222BDE8(Ov45R19State *state, u32 index);

#endif
