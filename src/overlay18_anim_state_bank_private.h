#ifndef POKEHEARTGOLD_OVERLAY18_RESIDUAL_22_H
#define POKEHEARTGOLD_OVERLAY18_RESIDUAL_22_H

#include "global.h"

#include "sprite_system.h"

#define R22_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define R22_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define R22_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define R22_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define R22_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

#define R22_ROOT(p)   (*(void **)(p))
#define R22_SPRITE(p) (*(ManagedSprite **)((u8 *)R22_ROOT(p) + 0x68C))

typedef struct Position18 {
    s16 y;
    s16 x;
} Position18;

void PlaySE(u16 seqNo);

void ov18_021F11C0(void *root, u32 idx, u32 draw);
void ov18_021F1294(void *root, u32 idx, s16 x, s16 y, u32 a4);
void ov18_021F12C8(void *root, u32 idx, s16 *x, s16 *y, u32 a4);
void ov18_021F5000(void *root, u32 rotation);
void ov18_021F5180(void *p, u32 a1, u32 a2);
void ov18_021F5198(void *p, u32 a1, int a2, int a3);

#endif
