#ifndef POKEHEARTGOLD_OVERLAY96_PARTICLE_PACKED_UPDATE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_PARTICLE_PACKED_UPDATE_PRIVATE_H

#include "global.h"

typedef struct Ov96R102Particle {
    s16 value;
    s16 counter;
    u32 low : 2;
    u32 state : 3;
    u32 enabled : 1;
    u32 timer : 8;
    u32 rest : 18;
    u8 unk8;
    u8 type;
    u8 speed;
} Ov96R102Particle;

typedef struct Ov96R102Packed {
    u16 counter : 7;
    u16 type : 4;
    u16 state : 3;
    u16 low : 2;
} Ov96R102Packed;

BOOL ov96_0220FBEC(Ov96R102Particle *particle, void *context, s16 *point);
void ov96_0220FD28(Ov96R102Particle *particle, void *context, const s16 *point);
s16 ov96_0220E6DC(s16 value, u8 type);
void ov96_0220FBDC(Ov96R102Particle *particle);
void ov96_0220FE38(Ov96R102Particle *particle, Ov96R102Packed *packed, void *context);

#endif
