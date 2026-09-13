#ifndef OV49_R73_PRIVATE_H
#define OV49_R73_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define S8_AT(p, n)  (*(s8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S16_AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))

typedef struct Ov49Entry {
    u8 raw[0x78];
} Ov49Entry;
#define OV49_ENTRIES(s) ((Ov49Entry *)((u8 *)(s) + 0xC))

extern void GF_AssertFail(void);
extern void *Heap_Alloc(u32, u32);

extern const u8 ov49_0226A7E0[];
extern const u16 ov49_0226A7D8[];
extern const u32 ov49_0226A70C[];
extern void (*const ov49_0226A4CC[])(void *, u32);
extern u32 (*const ov49_0226A484[])(void *);

extern void sub_020182A0(void *, int);

extern u32 ov49_02258F70(void *);
extern void ov49_02259154(void *, VecFx32 *);
extern void ov49_0226540C(void *, fx32, fx32, fx32, fx32, fx32, fx32, u32);
extern void ov49_022655F4(void *, u32, u32, u32);
extern void ov49_02265628(void *);
extern void ov49_02265660(void *, fx32 *);
extern u32 ov49_02265968(void *, int);
extern void ov49_022659D0(void *, void *, int);
extern void ov49_02265B14(void *, void *, int, int);
extern void ov49_02265BE8(void *, void *, u32, int, u32);
extern u32 ov49_02265C40(void *, void *, u32, u32);
extern void ov49_02265980(void *, void *, u32, const void *);
extern void ov49_022686C0(void *, const u8 *);
extern void ov49_022686E4(void *, const u16 *);
extern void ov49_022686F0(void *);
extern void ov49_02259148(void *, VecFx32 *);

typedef struct Ov49Ctl {
    s16 state;
    u16 kind;
    u16 count;
    u8 active;
    u8 phase;
    struct {
        u8 raw[0x28];
    } emitters[4];
    struct {
        u8 raw[0xC];
    } motions[4];
    void *objects[4];
    void *callbackArg;
} Ov49Ctl;

typedef struct Ov49Allocated {
    u8 unk00[0x48];
    u32 values48[2];
    u32 values50[4];
} Ov49Allocated;

u32 ov49_02268230(Ov49Ctl *);
void ov49_022683FC(Ov49Ctl *, u32, VecFx32 *, fx32, fx32, fx32, u32, u32);

#endif
