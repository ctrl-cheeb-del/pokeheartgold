#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"

void Sprite_SetDrawFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);

typedef struct SummaryWork {
    u8 pad000[0x280];
    u32 value : 28;
    u32 upper : 4;
    u8 pad284[0x1D0];
    void *sprite454;
    u8 pad458[0xCC];
    void *sprite524;
} SummaryWork;

void sub_0208B4EC(SummaryWork *);

#endif
