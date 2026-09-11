#ifndef SOL40_OV49_R13_PRIVATE_H
#define SOL40_OV49_R13_PRIVATE_H
#include "global.h"
typedef struct { void *field; } Ov49R13Work;
typedef struct { u8 pad[0x44]; u32 input; } Ov49System;
extern Ov49System gSystem;
int ov42_02228188(void *, int);
void ov49_0225927C(void *, int, int, int);
void ov49_02259410(Ov49R13Work *, void *);
#endif
