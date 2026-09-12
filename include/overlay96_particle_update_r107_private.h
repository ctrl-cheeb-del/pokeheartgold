#ifndef POKEHEARTGOLD_OVERLAY96_PARTICLE_UPDATE_R107_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_PARTICLE_UPDATE_R107_PRIVATE_H

#include "global.h"

typedef struct Ov96ParticleUpdateR107 {
    void *owner;
    s16 unk04;
    s16 x;
    s16 y;
    u16 padding_0A;
    u32 flags;
    u8 timer;
    u8 padding_11[3];
} Ov96ParticleUpdateR107;

void ov96_02210AE0(Ov96ParticleUpdateR107 *particle, u16 average, u16 value);
void ov96_02210980(Ov96ParticleUpdateR107 *particle, void *owner, u8 index);
void ov96_022108BC(Ov96ParticleUpdateR107 *particle, int index, void *owner);
void ov96_022108EC(Ov96ParticleUpdateR107 *particle, u16 average, u16 value);

#endif
