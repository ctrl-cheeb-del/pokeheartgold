#ifndef POKEHEARTGOLD_TO47_OVERLAY83_HP_ACTION_R4_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY83_HP_ACTION_R4_PRIVATE_H

#include "global.h"

#define O83_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define O83_S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define O83_PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov83Flags {
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 bit2 : 1;
    u8 rest : 5;
} Ov83Flags;
#define O83_FLAGS(p) ((Ov83Flags *)((u8 *)(p) + 0xE))

int ov83_02240FAC(u8 *work, u32 selected, u32 action);
int ov83_022411B0(void *value, u32 choice);
int ov83_022411DC(void *value, u32 choice);
void ov83_02241208(u8 *work, int delta);
void ov83_02241254(u8 *work, int delta);

void ov83_02240DB0(void *work);
u32 ov83_02247768(u32 count, u32 selected);
void *Party_GetMonByIndex(void *party, int index);
void ov83_0223FD4C(void *work, void *window, void *mon);
void ov83_0223FF44(void *work, void *window, void *mon);
u32 GetMonData(void *mon, int field, void *dest);
int CalculateHpBarColor(u16 hp, u16 maxHp, int width);
int ov80_02237D8C(u32 value);
void *ov83_02247454(void *, u32, u32, u32, u32, s16, u32, u32, u32);
int ov83_02247624(void *);
void ov83_0224753C(void *);
void ov83_02240238(void *, void *, u32, u32);
void ov83_02241E18(void *);
void ov83_022421E0(void *, u32);
void ov83_022475D4(void *, u32);
void ov83_02247600(void *, u32);

#endif
