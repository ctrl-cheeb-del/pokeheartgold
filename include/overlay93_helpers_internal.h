#ifndef OV93_THUMB2_PRIVATE_H
#define OV93_THUMB2_PRIVATE_H

#include "global.h"

/* Raw byte-offset accessors: no invented struct sizes. */
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

#endif
