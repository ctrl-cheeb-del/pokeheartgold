#ifndef PRIVATE_UNK_02017808_H
#define PRIVATE_UNK_02017808_H
#include <nitro/fx/fx_trig.h>

#include "global.h"

typedef struct {
    void *pic;
    u8 pad04[8];
    u32 cursor;
    u8 pad10[8];
    u32 complete;
    u8 pad1c[8];
    s32 variables[13];
    s32 baseX;
    s32 baseY;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 scaleX;
    s32 scaleY;
    s32 rotation;
    u8 pad7c[0x150];
    u8 reverseX;
    u8 pad1cd;
    u8 opcode;
    u8 fadeDone;
} AnimState;

extern const s16 FX_SinCosTable_[];
void sub_020173C8(AnimState *, u8 *, s32 *, s32 *);
void sub_02017294(AnimState *, u8 *);
void sub_02017280(AnimState *, u8 *);
void sub_0201726C(AnimState *, s32 *);
u8 sub_02017214(u32);
void sub_02017488(AnimState *);
void GF_AssertFail(void);
void Pokepic_SetAttr(void *, u32, s32);
void Pokepic_StartPaletteFade(void *, u32, u32, u32, s32);
BOOL Pokepic_ResumePaletteFade(void *);

void sub_02017808(AnimState *);
void sub_0201783C(AnimState *);
void sub_02017874(AnimState *);
void sub_020178BC(AnimState *);
void sub_0201790C(AnimState *);
void sub_020179D4(AnimState *);
void sub_02017A1C(AnimState *);
void sub_02017A84(AnimState *);
void sub_02017AD8(AnimState *);
void sub_02017AEC(AnimState *);
void sub_02017B2C(AnimState *);
#endif
