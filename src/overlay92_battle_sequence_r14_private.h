#ifndef OVERLAY92_BATTLE_SEQUENCE_R14_PRIVATE_H
#define OVERLAY92_BATTLE_SEQUENCE_R14_PRIVATE_H

#include "global.h"

#define U32_AT(p, o)        (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o)        (*(void **)((u8 *)(p) + (o)))
#define PTR_AT_OFFSET(p, o) ((void *)((u8 *)(p) + (o)))

typedef struct Ov92BattleSequenceR14 {
    u8 pad0000[0x2ae4];
    s32 progress;
    u32 mode;
    u32 index;
    u32 accumulator;
    u8 pad2af4[0x2afe - 0x2af4];
    s16 count;
    u8 pad2b00[0x2b18 - 0x2b00];
    s32 value;
} Ov92BattleSequenceR14;

void ov92_0225EE60(void *, int);
int ov92_0225F8EC(Ov92BattleSequenceR14 *);
int ov92_0225F968(Ov92BattleSequenceR14 *, int, u32 *);
void ov92_0225FC2C(Ov92BattleSequenceR14 *);

void ov92_0225F530(void *, void *);
void ov92_0225FAB8(void *);
void ov92_0225F9C4(void *);
void ov92_0225F8B0(Ov92BattleSequenceR14 *);
void ov92_0225FEE4(void *);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, u32);
BOOL PlaySE(u16);

#endif
