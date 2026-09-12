#ifndef POKEHEARTGOLD_OVERLAY40_TRAINER_CARD_RESOURCES_R19_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_TRAINER_CARD_RESOURCES_R19_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

int sub_0202FC48(void);
void sub_0202FC24(void);
void sub_0202FC90(void *saveData, int heapId, int *result, void *setup, int value);
void *sub_0203077C(int heapId);
void *sub_020307AC(int heapId);
void *sub_020314A4(int heapId);
void sub_020314C4(void *a, void *b);
u32 sub_02074490(void);
u32 sub_0207449C(void);
u32 sub_020744A8(void);

void ov40_0222FCCC(void *p);
void ov40_0222FDC4(void *p);
void ov40_0222FE00(void *p);
void ov40_0222FE68(void *p);

#endif
