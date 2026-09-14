#ifndef POKEHEARTGOLD_OVERLAY49_OBJECT_STATE_UPDATES_R48_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_OBJECT_STATE_UPDATES_R48_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

void ov49_0225E58C(void *p, u8 a, u8 b);
void ov49_0225E624(void *p, int a);

#endif
