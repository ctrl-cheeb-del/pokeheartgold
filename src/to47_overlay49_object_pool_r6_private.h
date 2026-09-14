#ifndef POKEHEARTGOLD_TO47_OVERLAY49_OBJECT_POOL_R6_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY49_OBJECT_POOL_R6_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct SolCfg6 {
    s16 x, y;
    u16 id, a, b, c;
} SolCfg6;

int ov49_022589D8(void *, int, u16 *, u16 *, int);
void GF_AssertFail(void);
void *ov49_02258C5C(void *, int, int, int);
void *ov49_022593C0(void *);
void *ov42_022280B8(void *, void *);
void *ov45_0223070C(void *, void *);
void ov49_02258EEC(void *, void *, int);
void *ov49_02258DAC(void *);
int ov49_02258FDC(void *, int, int);
void ov45_02230884(void *);
void ov42_02228100(void *);
void *memset(void *, int, u32);
int ov42_02228188(void *, int);

#endif // POKEHEARTGOLD_TO47_OVERLAY49_OBJECT_POOL_R6_PRIVATE_H
