#ifndef OV49_R73_R2_PRIVATE_H
#define OV49_R73_R2_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define S8_AT(p, n)  (*(s8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S16_AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

typedef struct Ov49Entry {
    u8 raw[0x78];
} Ov49Entry;
typedef struct Ov49KindState {
    u8 raw[0x960];
    u8 kinds[1];
} Ov49KindState;
typedef struct Ov49Interp {
    u8 raw[0x28];
} Ov49Interp;
typedef struct Ov49CounterState {
    u8 raw[0x958];
    s8 counters[0x10];
    Ov49Interp interp[1];
} Ov49CounterState;
#define OV49_ENTRIES(s) ((Ov49Entry *)((u8 *)(s) + 0xC))

extern u32 ov49_02258F70(void *);
extern void *ov49_02258DAC(void *);
extern u32 ov49_02258E60(void *, int);
extern void ov49_02259130(void *, int);
extern void ov49_02259154(void *, VecFx32 *);
extern void ov49_02259148(void *, VecFx32 *);
extern void ov49_02259160(void *, u32);
extern void ov49_0225919C(void *, int);
extern void ov49_0226540C(void *, fx32, fx32, fx32, fx32, fx32, fx32, u32);
extern u32 ov49_02265434(void *, s32);
extern void ov49_022655E0(void *, fx32 *, fx32 *, fx32 *);
extern void ov49_022655F4(void *, u32, u32, u32);
extern void ov49_02265628(void *);
extern void ov49_02265668(void *, void *, u32);
extern u32 ov49_02265968(void *, int);
extern void ov49_022659D0(void *, void *, int);
extern void ov49_02265980(void *, void *, u32, const void *);
extern void ov49_02265B14(void *, void *, int, int);
extern void ov49_02265BE8(void *, void *, u32, int, u32);
extern u32 ov49_02265C40(void *, void *, u32, u32);
extern void sub_020182A0(void *, int);
extern void sub_020182A8(void *, fx32, fx32, fx32);
extern void sub_020182B0(void *, fx32 *, fx32 *, fx32 *);
extern void ov49_0225CC40(void *, void *);

extern const VecFx32 ov49_0226A4D8[];
extern const VecFx32 ov49_0226A508[];
extern const u8 ov49_0226A450[];
extern const u32 ov49_0226A70C[];

void ov49_02266F14(void *ctx, void *state);
void ov49_02267074(void *ctx, void *state);
u32 ov49_022670D4(void *ctx, void *state);
u32 ov49_02267328(void *ctx, void *state);
u32 ov49_0226786C(void *ctx, void *state, u32 idx, u8 value);
void ov49_0226789C(void *ctx, void *state, u32 idx);

#endif
