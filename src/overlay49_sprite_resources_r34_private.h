#ifndef OVERLAY49_SPRITE_RESOURCES_R34_PRIVATE_H
#define OVERLAY49_SPRITE_RESOURCES_R34_PRIVATE_H

#include "global.h"
#include "assert.h"
#include "sprite.h"
#include "sprite_transfer.h"
#include "unk_02009D48.h"
#include "unk_0200A090.h"

#pragma require_prototypes off

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov49Tbl {
    u16 key;
    u16 a;
    u16 b;
    u16 c;
} Ov49Tbl;

typedef struct Ov49Files {
    u32 narcId;
    u32 charFile;
    u32 plttFile;
    u32 cellFile;
    u32 animFile;
    u32 unk14;
} Ov49Files;

extern const Ov49Tbl ov49_0226988C[];

void sub_02070D84(u32 id, int kind, Ov49Files *dst);
void ov49_0225C368(void *pltt);

void ov49_0225BFF0(void *p, void *mgr, NARC *narc, enum HeapID heapId, u32 idx, BOOL draw);
void ov49_0225C148(void *p, void *mgr);
void ov49_0225C180(void *p, void *mgr, NARC *narc, enum HeapID heapId, u32 key);
void ov49_0225C328(void *p, void *mgr);

#endif
