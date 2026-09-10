#ifndef POKEHEARTGOLD_SUMMARY_UI_STATS_INTERNAL_H
#define POKEHEARTGOLD_SUMMARY_UI_STATS_INTERNAL_H
#include "global.h"

typedef struct SummaryWork {
    void *bgConfig;
    u8 pad_004[0x228];
    void *monData; /* 0x22c */
    u8 pad_230[0x58c];
    s8 selection; /* 0x7bc */
} SummaryWork;

void *AllocAndReadWholeNarcMemberByIdPair(int, int, int);
void LoadRectToBgTilemapRect(void *, u8, void *, u8, u8, u8, u8);
void ScheduleBgTilemapBufferTransfer(void *, u8);
void Heap_Free(void *);
int CalculateHpBarColor(u16, u16, int);
u32 CalculateHpBarPixelsLength(u32, u32, int);
void FillBgTilemapRect(void *, int, u32, u8, u8, u8, u8, u8);
u8 sub_0208E544(SummaryWork *);
BOOL sub_02089E80(SummaryWork *, int);
void sub_02089E14(SummaryWork *, s8);
void sub_0208ADB8(SummaryWork *, int);
void PlaySE(int);
int sub_0208B044(SummaryWork *, int);
BOOL sub_0208A310(SummaryWork *, int);
void ScheduleSetBgPosText(void *, int, int, int);
void sub_0208AF70(SummaryWork *);
void sub_020196E8(void *, int, int, int);
void sub_0208B118(SummaryWork *);
extern const u32 _021039B8[][3];

void sub_020897C0(SummaryWork *);
void sub_02089C50(SummaryWork *);
void sub_0208C57C(SummaryWork *);
void sub_0208C614(SummaryWork *);
void sub_0208C6B4(SummaryWork *);
void sub_02089F98(SummaryWork *);
void sub_0208E4B4(SummaryWork *);
void sub_0208B448(SummaryWork *);
void sub_0208BA60(SummaryWork *);
void sub_0208B5A8(SummaryWork *);
void sub_0208B89C(SummaryWork *);
void sub_0208B9C8(SummaryWork *);
void sub_0208C2A0(SummaryWork *);
void sub_0208BE70(SummaryWork *);
void sub_0208B48C(SummaryWork *);
void sub_0208B4EC(SummaryWork *);
void sub_0208BCD4(SummaryWork *);
void sub_0208BD38(SummaryWork *);
void sub_0208CBD4(SummaryWork *);
void sub_0208B400(SummaryWork *);
void sub_0208BFD0(SummaryWork *);

void sub_02089F50(SummaryWork *, void *, int, int);
void sub_0208A234(SummaryWork *, u8);
void sub_0208A0EC(SummaryWork *);
void sub_0208A1A0(SummaryWork *);
int sub_02089E98(SummaryWork *);
#endif
