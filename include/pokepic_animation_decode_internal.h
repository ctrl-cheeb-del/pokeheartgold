#ifndef PRIVATE_UNK_020172C8_H
#define PRIVATE_UNK_020172C8_H
#include "global.h"

typedef struct {
    void *pic;
    u8 pad04[0x14];
    u32 complete;
    u32 stopped;
    u8 pad20[4];
    s32 variables[13];
    s32 baseX;
    s32 baseY;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 scaleX;
    s32 scaleY;
} AnimState;

void sub_02017294(AnimState *, u8 *);
void sub_02017280(AnimState *, u8 *);
void sub_020172B4(AnimState *, u8 *, u8 *);
void sub_0201726C(AnimState *, s32 *);
void GF_AssertFail(void);
void Pokepic_SetAttr(void *, u32, s32);
void Pokepic_AddAttr(void *, u32, s32);

void sub_020172C8(AnimState *, u8 *, s32 *, s32 *);
void sub_0201733C(AnimState *, u8 *, s32 *, s32 *);
void sub_020173C8(AnimState *, u8 *, s32 *, s32 *);
u32 sub_02017470(const s32 *, const s32 *);
void sub_02017488(AnimState *);
void sub_020174A4(AnimState *);
void sub_020174B4(AnimState *);
void sub_020174BC(AnimState *);
#endif
