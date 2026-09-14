#ifndef OV75_R3_H
#define OV75_R3_H
#include "global.h"
typedef struct {
    u8 raw[0x400];
} State;
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#endif
