#ifndef POKEHEARTGOLD_TO47_OVERLAY49_PERIODIC_EFFECTS_R78_INTERNAL_H
#define POKEHEARTGOLD_TO47_OVERLAY49_PERIODIC_EFFECTS_R78_INTERNAL_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

typedef struct Ov49List {
    u8 *items;
    u32 count;
} Ov49List;

extern const u8 ov49_0226A8B4[];
extern const u32 ov49_0226A894[][2];
extern const u8 ov49_0226A83C[];
extern const u8 ov49_0226A83D[];
extern const u32 ov49_0226A864[];
extern const u32 ov49_0226A868[];
extern void (*const ov49_0226A87C[])(void *, void *);

int ov49_0225E85C(void *p, u8 value, int flag, int scale);
void GF_AssertFail(void);
void ov49_02268D0C(u32 id, Ov49List *list);
void ov49_0225E894(void *p, u32 value);
void ov49_0225E6E0(void *p, u32 value);
BOOL PlaySE(u16 seq);

void ov49_02268B0C(void *p, u32 tick);
void ov49_02268B90(void *p, u32 tick);
void ov49_02268C2C(void *p, u32 value);
void ov49_02268C74(void *p, u32 index, void *arg);

#endif // POKEHEARTGOLD_TO47_OVERLAY49_PERIODIC_EFFECTS_R78_INTERNAL_H
