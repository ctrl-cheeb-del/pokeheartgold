#ifndef OV49_R79_PRIVATE_H
#define OV49_R79_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

typedef struct Ov49ChoiceSet {
    const void *entries;
    u32 count;
} Ov49ChoiceSet;

extern BOOL PlaySE(u16 seq);
extern void StopSE(u16 seq, int fadeFrames);
extern void *Heap_Alloc(u32 heapId, u32 size);

extern void ov49_0225E82C();
extern void ov49_0225E624();
extern u32 *ov49_0225EF84();
extern void *ov49_02259FE8();
extern void *ov49_02259FF0();
extern void *ov49_02258DB0();
extern void *ov49_02258DAC();
extern u32 ov49_0225EF88();
extern u32 *ov49_0225EF40();
extern void ov49_02258E60();
extern u32 ov42_022282A4();
extern void ov49_02258EEC();
extern void ov49_02259130();
extern void ov49_02259160();
extern u32 ov45_0222A330();
extern u32 ov45_0222A3A0();
extern u32 ov45_0222A2E0();
extern void *ov49_0225A30C();
extern void ov49_0225A08C();
extern void ov49_0225EF8C();
extern void ov49_0225A264();
extern u32 ov49_0225A2C4();
extern void ov49_0225A2F8();
extern void ov49_0225A0EC();
extern void ov49_0225EF68();
extern void ov49_02258EAC();
extern u32 ov49_0225A0AC();
extern void *ov49_02259FF8();
extern void *ov49_0225A000();
extern u32 ov49_022589A8();
extern void ov49_022589D8();
extern void ov49_0225E3B8();
extern u32 ov45_0222AD80();
extern void ov49_02269178();
extern void ov49_022695C4();

extern const u8 ov49_0226A834[];
extern const u8 ov49_0226A82C[];
extern const u8 ov49_0226A824[];
extern const u8 ov49_0226A81C[];
extern const u8 ov49_0226A820[];
extern const u8 ov49_0226A828[];
extern const u8 ov49_0226A830[];
extern const u8 ov49_0226A8C8[];

void ov49_02268CEC(void *work);
void ov49_02268D0C(u32 kind, Ov49ChoiceSet *set);
void ov49_02268D94(void *work);
void ov49_02268DB0(void *work);
BOOL ov49_02268DCC(void *task, void *ctx);
void *ov49_02268FAC(void *ctx, u32 heapId);

#endif
