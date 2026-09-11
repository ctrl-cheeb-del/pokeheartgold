#ifndef SOL40_OV49_R52_PRIVATE_H
#define SOL40_OV49_R52_PRIVATE_H
#include "global.h"
typedef struct { void *unk0; u16 state; u16 pad6; void *unk8; } Ov49Small;
typedef struct { u8 raw[0x24]; } Ov49Entry;
typedef struct { int heap; void *ctx; Ov49Entry entries[20]; Ov49Entry extra; } Ov49Work;
void ov49_0225D4C8(void *, void *);
void ov49_0225D214(void *, void *, int, int);
void ov49_0225D494(void *, int);
int ov49_0225D3BC(void *, void *, int);
void ov49_0225D4E8(void *);
void ov49_0225D4F0(void *, int, int, int);
void ov49_0225EC28(Ov49Small *);
int ov49_0225EC30(Ov49Small *);
u32 ov49_0225D1EC(void *);
typedef struct { s16 x, y; } Ov49Pair;
void ov49_0225D1C4(void *, Ov49Pair);
extern const s32 ov49_02269A74[];
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void *memset(void *, int, u32);
void ov49_0225F068(void *, int, int);
void ov49_0225F074(void *);
void ov49_0225ED68(Ov49Small *, void *);
void ov49_0225ECF0(Ov49Small *, void *);
void ov49_0225ED98(Ov49Small *, void *);
void ov49_0225EE10(Ov49Small *, void *);
void ov49_0225EE4C(void *, int);
Ov49Work *ov49_0225EEAC(void *, int);
void ov49_0225EEF8(Ov49Work *);
#endif
