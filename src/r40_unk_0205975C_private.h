#ifndef CAND_H
#define CAND_H
#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
BOOL sub_02037108(int, void *, int);
BOOL sub_02037030(int, void *, int);
BOOL sub_0205975C(void *);
#endif
