#ifndef OV96_R39_PRIVATE_H
#define OV96_R39_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

typedef union Ov96R39Flags {
    u32 raw;
    struct {
        u32 angle : 16;
        u32 speed : 4;
        u32 active : 1;
        u32 destroy : 1;
        u32 unused : 10;
    };
} Ov96R39Flags;

typedef struct Ov96R39Particle {
    ManagedSprite *sprite;
    fx32 xVelocity;
    fx32 yVelocity;
    fx32 x;
    fx32 y;
    Ov96R39Flags state;
} Ov96R39Particle;

typedef struct Ov96R39Manager {
    u32 heapId;
    Ov96R39Particle particles[15];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    u32 timer;
    u32 delay;
    u32 threshold;
} Ov96R39Manager;

extern const ManagedSpriteTemplate ov96_0221B0BC;
extern const ManagedSpriteTemplate ov96_0221B0F0;

extern void GF_AssertFail(void);
extern u32 MTRandom(void);
extern s32 GF_SinDeg(u16);
extern u32 ov96_021ED6E8(void);
extern void GfGfxLoader_GXLoadPal(u32, s32, u32, u32, u32, u32);

void ov96_021ECDEC(Ov96R39Particle *particle, SpriteSystem *spriteSystem, SpriteManager *spriteManager);
BOOL ov96_021ECF48(Ov96R39Particle *particle);
void ov96_021ECFF8(Ov96R39Particle *particle, SpriteSystem *spriteSystem, SpriteManager *spriteManager);
Ov96R39Manager *ov96_021ED054(u32 heapId, SpriteSystem *spriteSystem, SpriteManager *spriteManager);
void ov96_021ED09C(Ov96R39Manager *manager);
void ov96_021ED0C8(Ov96R39Manager *manager);
void ov96_021ED158(Ov96R39Manager *manager, u32 threshold);
void ov96_021ED17C(Ov96R39Manager *manager, u8 count);

#endif
