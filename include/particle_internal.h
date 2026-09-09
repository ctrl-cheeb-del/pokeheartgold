#ifndef POKEHEARTGOLD_PARTICLE_INTERNAL_H
#define POKEHEARTGOLD_PARTICLE_INTERNAL_H

#include "unk_02014DA0.h"

typedef struct ParticleContext {
    SPLManager *manager;
    void *resource;
    void *emitter;
    void *heapStart;
    void *heapCurrent;
    void *heapEnd;
    texAllocFun texAlloc;
    plttAllocFun plttAlloc;
    Camera *camera;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u16 perspective;
    u8 pad_32[2];
    VecFx32 pos;
    VecFx32 up;
    VecFx32 target;
    u32 texKeys[16];
    u32 plttKeys[16];
    u8 flags;
    u8 unk_D9;
    u8 slot;
    u8 perspectiveType;
} ParticleContext;

#endif
