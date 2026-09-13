#ifndef CAND_H
#define CAND_H
#include "global.h"
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
extern u32 _021D41CC;
int sub_02037FCC(void);
void sub_0205A034(void *, void (*)(void *), int);
void sub_02059F78(void *);
void sub_0205A0B4(void *);
void sub_0203894C(void *);
void sub_0203898C(void *);
void sub_02037F64(void *);
void sub_0208F814(int);
void sub_02038918(void *);
void sub_02059EBC(void *);
#endif
