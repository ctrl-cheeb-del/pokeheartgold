#ifndef SOL_R40_FOLLOWUP_OV72_10_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV72_10_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
int ov72_0223AF48(void *);
int ov00_021EC5B4(void);
void ov72_022387D0(void *, int, int);
void sub_02039418(void *);
void Sys_SetSleepDisableFlag(int);
void ov72_0223A414(void *);
void ov00_021EC3F0(void *, int, int, int);
void ov00_021EC454(int);
void ov00_021EC4A4(void);
void ov00_021EC60C(void);
int ov00_021EC724(void);
void *ov00_021EC0FC(void *);
void ov00_021EC210(void);
void ov00_021EC8D8(void);
void ov72_0223A444(void *);
void ov00_021EC9E0(void *);
#endif
