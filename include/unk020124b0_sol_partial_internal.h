#ifndef TO30_UNK_020124B0_PRIVATE_H
#define TO30_UNK_020124B0_PRIVATE_H

#include "global.h"

#include "heap.h"
#include "sys_task_api.h"

typedef struct FadeContainer {
    void *allocation;
    int count;
} FadeContainer;

typedef struct FadeOwner {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    int state;
    u32 unk10;
    void *effect;
    u32 unk18;
    u32 unk1C;
    u32 heapId;
} FadeOwner;

typedef struct FadeParam {
    u16 start;
    u16 end;
    u8 unk04;
    u8 unk05;
    u16 color;
} FadeParam;

typedef struct FadeEffect {
    FadeContainer resources;
    u32 unk08;
    int start;
    int current;
    int delta;
    int duration;
    int frame;
    int delay;
    int counter;
    u32 color;
    u32 heapId;
    u32 callbackArg;
    u32 unk34;
} FadeEffect;

typedef struct FadePalette {
    u8 padding00[0xC];
    int amount;
} FadePalette;

typedef struct Interpolation {
    int value;
    int start;
    int delta;
} Interpolation;

extern int _s32_div_f(int, int);
extern void *sub_02010EE0(void *, int);
extern int sub_020109D8(int, int);
extern void sub_02010E64(void *, int, u32, u32);
extern void sub_020127B8(void *);
extern void sub_02010F00(SysTask *, void *);
extern void sub_02010C38(void);
extern void sub_02010F84(u32, u8, u8, int, u32, int, int, int, int, u32);
extern void sub_02011068(u32, int, u32, u32);
extern void sub_0200FF88(u32, void *, void (*)(void), u32, u32);
extern void sub_0200FFB4(u32, u32, u32);
extern void sub_02010F34(u32, u32, u32);
extern void sub_020127B4(void *);
extern void sub_02010EC8(void *);
extern void sub_02012884(void *, int, int);

void sub_020124B0(FadePalette *work);
void sub_020125D4(Interpolation *interp, int numerator, int denominator);
void sub_020125EC(FadeOwner *work, const FadeParam *param);
BOOL sub_0201262C(FadeOwner *work);
void sub_0201268C(FadeEffect *effect, const FadeParam *param, u32 unk2, u32 unk3, u32 unk4, u32 unk5, u32 unk6, u32 heapId);
BOOL sub_0201275C(FadeEffect *effect);

#endif
