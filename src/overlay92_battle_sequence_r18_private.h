#ifndef OVERLAY92_BATTLE_SEQUENCE_R18_PRIVATE_H
#define OVERLAY92_BATTLE_SEQUENCE_R18_PRIVATE_H

#include "global.h"

typedef struct ManagedSprite ManagedSprite;
typedef struct PaletteData PaletteData;
typedef struct SysTask SysTask;

typedef struct Ov92AnimState {
    s32 state;
    s32 active;
    ManagedSprite *sprites[8];
    s32 unk28;
    u8 pad2C[0x20];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
} Ov92AnimState;

typedef struct Ov92Context18 {
    u8 pad00[0x10];
    void *bgConfig;
    PaletteData *paletteData;
    u8 pad18[0x34 - 0x18];
    u8 blocked;
} Ov92Context18;

typedef struct Ov92Work18 {
    u8 pad000[0x15c];
    s32 *paletteBase;
    s32 *blend;
    u32 timer;
    u32 unk168;
    u8 pad16c[0x170 - 0x16c];
    u32 animState;
    u32 enabled;
    u32 direction;
    Ov92Context18 *context;
    u8 tweens[3][0x18];
    u8 pad1c8[0x200 - 0x1c8];
    u32 unk200;
} Ov92Work18;

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define ADDR(p, o)   ((void *)((u8 *)(p) + (o)))
#define WORD(p, o)   (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))

void ov92_02261118(Ov92AnimState *);
void ov92_02261208(Ov92AnimState *);
void ov92_0226135C(Ov92AnimState *);
void ov92_022613F0(Ov92AnimState *);
void ov92_02261448(SysTask *, void *);
void ov92_022616D8(void *);
void ov92_02261850(void *);
int ov92_022619C4(int);
void ov92_02261A18(SysTask *, void *);
void ov92_02261B18(void *);

void PaletteData_BlendPalettes(PaletteData *, int, u16, u8, u16);
void sub_020182A0(ManagedSprite *, int);
void SysTask_Destroy(SysTask *);
SysTask *SysTask_CreateOnMainQueue(void (*)(SysTask *, void *), void *, u32);
BOOL IsPaletteFadeFinished(void);
BOOL PlaySE(u16);
void StopSE(u16, int);
void ov92_022610E8(ManagedSprite *, s32 *);
void ov92_02260860(void *, s32, s32, s32);
BOOL ov92_02260870(void *);
void ScheduleSetBgPosText(void *, int, int, int);
void ManagedSprite_SetPaletteOverrideOffset(ManagedSprite *, int);

#endif
