#ifndef OV96_R40_RESIDUAL54_3_PRIVATE_H
#define OV96_R40_RESIDUAL54_3_PRIVATE_H

#include "global.h"

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct Ov96R54TaskWork {
    u8 state0;
    u8 state1;
    u8 state2;
    u8 pad03;
    void *task4;
    void *task8;
    void *taskC;
    void *task10;
    u8 pad14[4];
    u16 timer18;
    u16 timer1A;
    u16 value1C;
    u16 value1E;
    void *data20;
    u8 pad24[0xc];
    void *course30;
} Ov96R54TaskWork;

u8 *ov96_021E60D8(void *, u32, u32);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, u32);
void SysTask_Destroy(void *);
void *PokeathlonCourse_GetDataCopyArea(void *);
u8 *ov96_021E8A20(void *);
void ov96_021F31F0(void *, u32);
void ov96_021F3298(void *, u32);
void PlaySE(u32);
void G2x_SetBlendAlpha_(u32, int, int, int, int);
void ov96_021F2D68(void *, void *);

void ov96_021F2B24(void *, u32 *, u32, u32, void *);
void ov96_021F2B68(Ov96R54TaskWork *, u16, u16, void *);
void ov96_021F2BB4(void *, Ov96R54TaskWork *);
void ov96_021F2C04(void *, Ov96R54TaskWork *);
void ov96_021F2CD0(void *, Ov96R54TaskWork *);

#endif
