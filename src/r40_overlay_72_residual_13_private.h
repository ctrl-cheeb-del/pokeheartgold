#ifndef SOL40_R40_OV72_13_PRIVATE_H
#define SOL40_R40_OV72_13_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void BufferIntegerAsString(void *, int, int, int, int, int);
void ov72_0223A280(void *, void *, int, int, int);
void ov72_02238680(void *, int, int);
void ov72_0223A520(void *, int, int);
void ov72_0223A41C(void *, int, int);
int ov72_0223A588(void *);
void ov00_021ECB94(void *, void *);
int sub_0202D720(void *, u8, u8, void *);
int ov72_02237B54(void *);
int ov72_02237B74(void);
void ov72_0223A444(void *);
void sub_020399EC(void);
#endif
