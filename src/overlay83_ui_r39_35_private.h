#ifndef TO40_SOL_R39_OVERLAY83_R35_PRIVATE_H
#define TO40_SOL_R39_OVERLAY83_R35_PRIVATE_H

#include "overlay83_sol_partial_internal.h"

#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

void ov83_02245554(u8 *p, u8 value);
void ov83_02245748(u8 *p, u32 value);

#endif
