#ifndef TO45_OV49_R73_PRIVATE_H
#define TO45_OV49_R73_PRIVATE_H

#include "global.h"

#include "overlay_42.h"
#include "system.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define S8_AT(p, n)  (*(s8 *)((u8 *)(p) + (n)))
#define S16_AT(p, n) (*(s16 *)((u8 *)(p) + (n)))

extern u32 ov49_02258F70(void *);
extern u32 ov49_02265968(void *, int);
extern void ov49_022659D0(void *, void *, int);
extern BOOL sub_020182A4(void *);
extern void sub_020182A0(void *, int);
extern u32 ov49_02265B28(void *, void *, int, int);
extern void ov49_02265B14(void *, void *, int, int);
extern u32 ov49_02266D60(void *, void *);
extern u32 ov49_02266D7C(void *, void *);
extern u32 ov49_02266E78(void *, void *);
extern void ov49_02266EF8(void *, void *);
extern u32 ov49_022670B8(void *, void *);
extern u32 ov49_02267E18(void *, int);
extern void ov49_02267D00(void *, void *);
extern void ov49_02267D34(void *, void *);
extern void ov49_02259154(void *, VecFx32 *);
extern void ov49_0226540C(void *, fx32, fx32, fx32, fx32, fx32, fx32, u32);
extern void ov49_022655F4(void *, u32, u32, u32);
extern u32 ov49_02267674(void *);
extern void ov49_0226747C(void *);
extern const u8 ov49_0226A450[];
extern u32 ov49_02265434(void *, s32);
extern void ov49_02265628(void *);
extern void ov49_022655E0(void *, fx32 *, fx32 *, fx32 *);
extern void ov49_02265660(void *, fx32 *);
extern void ov49_02259148(void *, VecFx32 *);
extern void ov49_0226789C(void *, void *, u32);
extern void *ov49_02258DAC(void *);
extern void ov49_02259160(void *, u32);
extern u32 ov49_02258E34(void *);
extern void ov49_02258E04(void *, UnkStruct_ov44_02232914, s32);

typedef struct Ov49R73Entry {
    u8 raw[0x78];
} Ov49R73Entry;

#define OV49_R73_ENTRIES(p) ((Ov49R73Entry *)((u8 *)(p) + 0xC))

#endif
