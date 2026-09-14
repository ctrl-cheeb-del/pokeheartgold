#ifndef OVERLAY49_OBJECT_COMMANDS_R49_PRIVATE_H
#define OVERLAY49_OBJECT_COMMANDS_R49_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov49Slot12 {
    u8 raw[12];
} Ov49Slot12;

typedef struct Ov49Vec2s {
    s16 x;
    s16 y;
} Ov49Vec2s;

extern void ov49_0225EB54(void *p, void *q, u32 a);
extern void ov49_0225EB84(void *p);
extern void ov49_0225ECD4(void *p, u32 v);
extern u32 ov49_0225D450(void *p, u32 a);
extern void ov49_0225D214(void *p, void *q, u32 a, u32 b);
extern void ov49_0225D3F8(void *p, void *q, u32 a, fx32 b);
extern void ov49_0225D394(void *p, void *q);
extern void ov49_0225D4A0(void *p, void *q, u32 a);
extern void ov49_0225D328(void *p, void *q, u32 a);
extern Ov49Vec2s ov49_0225D1EC(void *p);

u32 ov49_0225E85C(void *p, u32 i, u32 flag, u32 arg);
void ov49_0225E894(void *p, u32 v);
void ov49_0225E8C4(void *p, u32 idx, u32 a, u32 b, u32 c, u32 d);
BOOL ov49_0225E9D0(void *p, s32 x, s32 y);

#endif
