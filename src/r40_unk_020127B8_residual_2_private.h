#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"

typedef struct FadeParam8 {
    const void *unk0;
    u16 unk4;
    u16 unk6;
} FadeParam8;

void sub_02011080(void *, u32, u32, u32, u32);
void sub_020110DC(void *, u8 *, u32);
void sub_02011068(void *, int, u32, u32);
void sub_02010F84(void *, int, int, int, u32, int, int, int, int, int);
void sub_02012940(u8 *, const FadeParam8 *, int, int, u32, void *, u32, u32);

#endif
