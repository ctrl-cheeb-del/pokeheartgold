#ifndef TO47_OVERLAY70_SPRITE_SETUP_R32_PRIVATE_H
#define TO47_OVERLAY70_SPRITE_SETUP_R32_PRIVATE_H

#include "global.h"

typedef struct Sprite Sprite;

typedef struct Ov70R32Vec {
    s32 x;
    s32 y;
    s32 z;
} Ov70R32Vec;

typedef struct Ov70R32SpriteTemplate {
    void *spriteList;
    const void *header;
    Ov70R32Vec position;
    Ov70R32Vec scale;
    u16 rotation;
    u16 pad22;
    u32 drawPriority;
    u32 whichScreen;
    u32 heapID;
} Ov70R32SpriteTemplate;

Sprite *Sprite_CreateAffine(const Ov70R32SpriteTemplate *);
void Sprite_SetAnimActiveFlag(Sprite *, int);
void Sprite_SetAnimCtrlSeq(Sprite *, int);
void Sprite_SetDrawFlag(Sprite *, int);
void Sprite_SetPriority(Sprite *, int);
Ov70R32Vec *Sprite_GetMatrixPtr(Sprite *);
void ov70_02238B54(Ov70R32SpriteTemplate *, u8 *, void *, int);
void ov70_02238F9C(Sprite *, int, void *);
void ov70_022410F0(Sprite *, int, int);
void ov70_0224127C(u8 *);
extern const u16 ov70_02245D0A[];

void ov70_02240D74(u8 *, int);

#endif
