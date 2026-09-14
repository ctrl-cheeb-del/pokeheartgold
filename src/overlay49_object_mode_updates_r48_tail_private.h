#ifndef POKEHEARTGOLD_OVERLAY49_OBJECT_MODE_UPDATES_R48_TAIL_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_OBJECT_MODE_UPDATES_R48_TAIL_PRIVATE_H

#include "global.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct {
    u8 p0[4];
    void *owner;
    void *objects[312];
    u8 p4e8[0x123];
    u8 countA;
    u8 p60c[6];
    u8 countB;
} Ov49R48;

u16 ov49_0225D1C0(void *p);
void ov49_0225D4A0(void *, void *, u32);
void ov49_0225D214(void *, void *, u32, u32);
void ov49_0225D224(void *, void *, u32, u32, void *);
void ov49_0225D328(void *, void *, u32);
void ov49_0225EA10(void *, void *);
void ov49_0225EA40(void *, void *);

void ov49_0225E714(Ov49R48 *);
void ov49_0225E760(Ov49R48 *, u32);

#endif
