#ifndef OVERLAY96_EVENT_BEHAVIOR_R14_PRIVATE_H
#define OVERLAY96_EVENT_BEHAVIOR_R14_PRIVATE_H
#include <nitro/fx/fx_vec.h>

#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef struct R123Flags {
    u32 index : 2;
    u32 bit2 : 1;
    u32 bit3 : 1;
    u32 rest : 28;
} R123Flags;
typedef struct R123Rec {
    void *ctx;
    s8 state;
    s8 timer;
    s8 timer2;
    s8 target;
    union {
        u32 flags;
        R123Flags bits;
    };
} R123Rec;
typedef u32 (*R123Unary)(u32);
extern void ov96_0221A400(R123Rec *);
extern int ov96_02215FA0(const VecFx32 *);
extern void (*ov96_0221D9A0[])(void *);
extern R123Unary ov96_0221D9C8[];
extern void *ov96_021E94EC(void *, u8);
extern void ov96_0221A730(void *);
extern u32 MTRandom(void);
extern u32 ov96_02215E68(void *, u8);
void ov96_02219FE4(void *);
void ov96_0221A00C(R123Rec *, u8, void *);
BOOL ov96_0221A034(const VecFx32 *, const VecFx32 *, fx32);
BOOL ov96_0221A05C(const VecFx32 *, const VecFx32 *, int);
BOOL ov96_0221A3AC(R123Rec *);
void ov96_0221A56C(void *, int);
void ov96_0221A57C(void *, int);
void ov96_0221A5B8(void *, int);
float ov96_0221A5D4(u32, float);
u8 ov96_0221A61C(float);
u8 ov96_0221A640(u32);
#endif
