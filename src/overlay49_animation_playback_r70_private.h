#ifndef TO37_OV49_R70_PRIVATE_H
#define TO37_OV49_R70_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

#pragma require_prototypes off

typedef struct Ov49AnimationState {
    u8 pad_000[0x87C];
    const u8 *descs[18];
    s32 frames[18][2];
} Ov49AnimationState;

void GF_AssertFail(void);
void sub_02018198(void *, s32);
s32 sub_020181A0(void *);
s32 sub_020181A4(void *);
void sub_020181B0(void *, void *);
void sub_020181D4(void *, void *);
void sub_020181E0(void *, void *);
void sub_020181EC(void *);
BOOL sub_020182A4(void *);

void ov49_02265B3C(void *, Ov49AnimationState *, u32, u32, s32);
BOOL ov49_02265B94(void *, Ov49AnimationState *, u32, u32, s32);

#endif
