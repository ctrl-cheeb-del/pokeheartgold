#ifndef POKEHEARTGOLD_OVERLAY43_PLAZA_MENU_R26_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY43_PLAZA_MENU_R26_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))

extern u8 gSystem[];

void ClearWindowTilemapAndScheduleTransfer(void *);
void ov43_0222AA70(void *);
void ov43_0222AD20(void *, int);
void ov43_0222AD74(void *, int, int);
int ov43_0222D2FC(void *, void *, void *);
int ov43_0222D3B8(void *, void *, void *, int *);
void ov43_0222DAE8(void *, void *, void *, int, int, void *);
void ov43_0222DB94(void *, void *, int);
void ov43_0222DDD0(void *, void *);
void ov43_0222DD88(void *);
void ov43_0222DE10(void *);
void ov43_0222DED0(void *, int);
void ov43_0222DF90(void *, void *);
void PlaySE(int);
void Sprite_SetPositionXY(void *, s16, s16);

int ov43_0222D47C(void *, void *, void *);
void ov43_0222D4C4(void *, void *, void *, int);
void ov43_0222D610(void *, void *, void *);
void ov43_0222D87C(void *, void *);
void ov43_0222DACC(void *);
void ov43_0222DB28(void *, void *, int);

#endif
