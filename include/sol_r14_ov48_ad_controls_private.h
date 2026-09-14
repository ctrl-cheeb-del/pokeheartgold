#ifndef TO45_R14_OV48_R26_PRIVATE_H
#define TO45_R14_OV48_R26_PRIVATE_H
#include "global.h"

#include "sprite.h"
#define U8AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define S16AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))
void PlaySE(u16);
void StopSE(u16, int);
void ov48_0225AEA8(void *, void *);
u32 ov48_0225AE60(void *, void *);
void ov48_0225B010(void *, u32);
void ov48_0225AD54(void *, void *);
u32 ov48_0225ADBC(void *, u32, void *);
u32 ov48_0225ADF8(void *, u32, void *);
#endif
