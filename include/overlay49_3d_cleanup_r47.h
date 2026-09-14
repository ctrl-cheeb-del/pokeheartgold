#ifndef POKEHEARTGOLD_OVERLAY49_3D_CLEANUP_R47_H
#define POKEHEARTGOLD_OVERLAY49_3D_CLEANUP_R47_H
#include "global.h"
typedef struct Ov49State {
    u8 raw[0x300];
} Ov49State;
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
void sub_020180F8(void *, int);
void Heap_Free(void *);
void ov49_0225D57C(void *, void *, int);
int ov49_0225D5A0(void *, void *, int);
void GF_AssertFail(void);
int ov49_022588A0(void *, void *);
void sub_020181D4(void *, void *);
void sub_02018198(void *, void *);
void sub_020181EC(void *);
void sub_020181E0(void *, void *);
void NNS_G3dReleaseMdlSet(NNSG3dResMdlSet *);
void ov49_0225D9D0(Ov49State *, int);
void ov49_0225DA70(Ov49State *, void *);
void ov49_0225DAFC(Ov49State *, void *);
#endif
