#ifndef POKEHEARTGOLD_OVERLAY18_PROFILE_ANIMATION_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY18_PROFILE_ANIMATION_INTERNAL_H
#include "global.h"

#include "sprite_system.h"

#define PTR(p, off, T) (*(T **)((u8 *)(p) + (off)))
typedef struct R21State {
    void *root;
    u32 velocity;
    u16 state;
    u8 direction;
    u8 pad;
    s32 x;
    s32 y;
    s32 z;
} R21State;

void ov18_021F13DC(void *, u32);
void ov18_021F14FC(void *, u32, u32, int);
void ov18_021F1534(void *, u32, u32, int);
void ov18_021F1294(void *, int, s16, s16, int);
void ov18_021F12C8(void *, int, s16 *, s16 *, int);
void ov18_021F4EB0(u16, s16 *, s16 *);
void ov18_021F4F98(void *, int, u16, s16, s16);
void ov18_021F4FC8(void *, int, int);
void ov18_021F3CA8(void *, int, u8 *, u8 *);
void ov18_021F69E8(void *, u16, u8, u8, int);
void ov18_021F6AB0(void *, s16, s16);

void ov18_021F4CC4(void *);
void ov18_021F4D64(void *);
void ov18_021F4DDC(void *);
void ov18_021F4F98(void *, int, u16, s16, s16);
void ov18_021F4FC8(void *, int, int);
void ov18_021F5000(void *, u16);
void ov18_021F516C(R21State *);
void ov18_021F5180(R21State *, s32, s32);
void ov18_021F5198(R21State *, s32, s32, s32);
extern void (*const ov18_021FA588[])(R21State *);
#endif
